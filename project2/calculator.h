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

	Token get();//�ö�expr�ַ�

private:
	bool full;
	Token buffer;

	stringstream expr;//Ҫ����ı��ʽ
	//Token_stream ts;
	int factorial(int);//�׳�

	void put_back(Token t);//��t������ǰ��
	

	double expression();//����+��-�����á���get_token
	double term();//����* / ��%�����á���get_token
	double sub_term();//����׳�
	double primary();//�������ֺ����ţ�����get_token
};
#endif