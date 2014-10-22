#include"token.h"

#ifndef TOKEN_STREAM_H
#define TOKEN_STREAM_H

#include<stdexcept>
#include<iostream>

class Token_stream
{
public:
	Token_stream();//实例化

	void put_back(Token t);//将t插入最前面

	Token get(istream& is);//用is读语句

private:
	bool full;
	Token buffer;
};

#endif