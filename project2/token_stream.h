#include"token.h"

#ifndef TOKEN_STREAM_H
#define TOKEN_STREAM_H

#include<stdexcept>
#include<iostream>

class Token_stream
{
public:
	Token_stream();//ʵ����

	void put_back(Token t);//��t������ǰ��

	Token get(istream& is);//��is�����

private:
	bool full;
	Token buffer;
};

#endif