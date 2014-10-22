#include"calculator.h"

Calculator::Calculator(string text) :full(false), buffer(0), expr(text) {}

//exp = term + term + ... + term 一级运算
//term = sub_term * sub_term * ... * sub_term 二级运算
//sub_term = prim! or prim 三级
//prim = num  or (exp) or |exp| 数字或越级运算


void Calculator::put_back(Token t)
{
	if(full) throw exception("buffer已满！");
	buffer = t;
	full = true;
}

Token Calculator::get()
{
		if(full)
	{
		full = false;
		return buffer;
	}
	char ch;
	if(this->expr.eof())
		ch = ';';
	else
	{
		expr>>ch;
	}

	switch(ch)//每次定义新的运算要在这里添加运算符
	{
	case ';': //for "print"
	case 'q': //for "quit"
	case '(': case ')': case '+': case '-': case '*': case '/': case '|': case '!': case '%':
		return Token(ch);
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
		expr.putback(ch);
		double val;
		expr>>val;
		return Token('8', val);
	default:
		throw exception("非法字符！");
	}



}


double Calculator::calculate()
{
	double val = expression();
	//取完表达式判断是否带有分号
	Token t = this->get();
	if(t.kind != ';')
		throw exception("表达式无效！");
	return val;
}



int Calculator::factorial(int num)
{
	if (num < 0) throw exception("被阶乘数须大于零！");
	if (num == 0) return 1;
	else
	{
		int retn = 1;
		for(int i = 2; i <= num; i++)
		{
			retn *= i;
		}
		return retn;
	}
}

double Calculator::expression()
{
	//新增：判断正负号 先取符号判断是不是正负号
	Token t = get();
	bool is_posi = true;
	switch(t.kind)
	{
	case '+':
		//do nothing
		break;
	case '-':
		is_posi = false;
		break;
	default:
		put_back(t);
	}


	double left = term();//先取左边一个term并计算值
	if(!is_posi) left = -left;
	t = get();//取符号

	while(true)
	{
		switch (t.kind)
		{
		case '+':
			left += term();//加法则再取个term相加 下同
			t = get();//再取符号
			break;
		case '-':
			left -= term();
			t = get();
			break;
		default://如果取出来的不是加减号
			put_back (t);
			return left;//说明取完了 可以返回left
		}
	}
}


double Calculator::term()
{
	//原理同 expression()

	double left = sub_term();//先取左边一个sub_term并计算值
	Token t = get();//取符号
	double d;
	while(true)
	{
		switch (t.kind)
		{
		case '*':
			left *= sub_term();//乘法则再取个primary相加 下同
			t = get();//再取符号
			break;
		case '/':
			 d = sub_term();//除零检查
			if(d == 0) throw exception("除数不能为零！");
			left /= d;
			t = get();
			break;
		//取余在此定义：
		case '%':
			 d = sub_term();//整数检查
			 if((int)left != left || (int)d != d) throw exception("取余操作必须使用两个整数！");
			 if((int)d == 0) throw exception("除数不能为零！");
			 left = (int)left % (int)d;
			 t = get();
			 break;
		default://如果取出来的是别的
			put_back (t);
			return left;//说明取完了 可以返回left
		}
	}


}

double Calculator::sub_term()
{
	double tmp = primary();//先取左边一个primary并计算值
	while(true)//实现连阶乘
	{
		Token t = get();//取符号
		if (t.kind == '!')
		{
			tmp = factorial(tmp);
		}
		else
		{
			put_back(t);
			return tmp;
		}
	}
	
}


double Calculator::primary()
{
	//最底层的计算

	Token t = get();
	
	double d;
	switch(t.kind)
	{
	case '('://
		d = expression();
		t = get();
		if(t.kind != ')') throw exception("格式错误，无后括号！");
		return d;
	case '8':
		return t.value;
	case '|'://模运算 优先级和括号相同 只不过是取绝对值
		d = expression();
		t = get();
		if(t.kind != '|') throw exception("模运算格式错误！");
		return abs(d);
	default:
		throw exception("未知符号！");
	}
}