#ifndef CALC_H
#define CALC_H

#include<iostream>
#include<sstream>
#include<stdexcept>
#include<math.h>
#include"token.h"

using namespace std;

class Calculator
{
public:
	Calculator(string text);

	double calculate();

	Token get();//用读expr字符

private:
	bool full;
	Token buffer;

	stringstream expr;//要计算的表达式
	//Token_stream ts;
	int factorial(int);//阶乘

	void put_back(Token t);//将t插入最前面
	

	double expression();//处理+和-；调用↓和get_token
	double term();//处理* / 和%；调用↓和get_token
	double sub_term();//处理阶乘
	double primary();//处理数字和括号；调用get_token
};
#endif