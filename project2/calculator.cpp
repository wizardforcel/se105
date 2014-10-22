#include"calculator.h"

Calculator::Calculator(string text) :full(false), buffer(0), expr(text) {}

//exp = term + term + ... + term һ������
//term = sub_term * sub_term * ... * sub_term ��������
//sub_term = prim! or prim ����
//prim = num  or (exp) or |exp| ���ֻ�Խ������


void Calculator::put_back(Token t)
{
	if(full) throw exception("buffer������");
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

	switch(ch)//ÿ�ζ����µ�����Ҫ��������������
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
		throw exception("�Ƿ��ַ���");
	}



}


double Calculator::calculate()
{
	double val = expression();
	//ȡ����ʽ�ж��Ƿ���зֺ�
	Token t = this->get();
	if(t.kind != ';')
		throw exception("���ʽ��Ч��");
	return val;
}



int Calculator::factorial(int num)
{
	if (num < 0) throw exception("���׳���������㣡");
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
	//�������ж������� ��ȡ�����ж��ǲ���������
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


	double left = term();//��ȡ���һ��term������ֵ
	if(!is_posi) left = -left;
	t = get();//ȡ����

	while(true)
	{
		switch (t.kind)
		{
		case '+':
			left += term();//�ӷ�����ȡ��term��� ��ͬ
			t = get();//��ȡ����
			break;
		case '-':
			left -= term();
			t = get();
			break;
		default://���ȡ�����Ĳ��ǼӼ���
			put_back (t);
			return left;//˵��ȡ���� ���Է���left
		}
	}
}


double Calculator::term()
{
	//ԭ��ͬ expression()

	double left = sub_term();//��ȡ���һ��sub_term������ֵ
	Token t = get();//ȡ����
	double d;
	while(true)
	{
		switch (t.kind)
		{
		case '*':
			left *= sub_term();//�˷�����ȡ��primary��� ��ͬ
			t = get();//��ȡ����
			break;
		case '/':
			 d = sub_term();//������
			if(d == 0) throw exception("��������Ϊ�㣡");
			left /= d;
			t = get();
			break;
		//ȡ���ڴ˶��壺
		case '%':
			 d = sub_term();//�������
			 if((int)left != left || (int)d != d) throw exception("ȡ���������ʹ������������");
			 if((int)d == 0) throw exception("��������Ϊ�㣡");
			 left = (int)left % (int)d;
			 t = get();
			 break;
		default://���ȡ�������Ǳ��
			put_back (t);
			return left;//˵��ȡ���� ���Է���left
		}
	}


}

double Calculator::sub_term()
{
	double tmp = primary();//��ȡ���һ��primary������ֵ
	while(true)//ʵ�����׳�
	{
		Token t = get();//ȡ����
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
	//��ײ�ļ���

	Token t = get();
	
	double d;
	switch(t.kind)
	{
	case '('://
		d = expression();
		t = get();
		if(t.kind != ')') throw exception("��ʽ�����޺����ţ�");
		return d;
	case '8':
		return t.value;
	case '|'://ģ���� ���ȼ���������ͬ ֻ������ȡ����ֵ
		d = expression();
		t = get();
		if(t.kind != '|') throw exception("ģ�����ʽ����");
		return abs(d);
	default:
		throw exception("δ֪���ţ�");
	}
}