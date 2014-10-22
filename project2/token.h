#ifndef TOKEN_H
#define TOKEN_H

class Token
{
public:
	char kind;
	double value;

	Token(char ch)
		:kind(ch), value(0){};
	Token(char ch, double val)
		:kind(ch),value(val){};
};

#endif