#include"token_stream.h"

using namespace std;

Token_stream::Token_stream()
	:full(false), buffer(0)
{

}


void Token_stream::put_back(Token t)
{
	if(full) throw exception("buffer已满！");
	buffer = t;
	full = true;
}

Token Token_stream::get(istream& is)
{
	if(full)
	{
		full = false;
		return buffer;
	}
	char ch;
	cin>>ch;

	switch(ch)//每次定义新的运算要在这里添加运算符
	{
	case ';': //for "print"
	case 'q': //for "quit"
	case '(': case ')': case '+': case '-': case '*': case '/': case '|': case '!':
		return Token(ch);
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
		cin.putback(ch);
		double val;
		cin>>val;
		return Token('8', val);
	default:
		throw exception("非法字符！");
	}
}