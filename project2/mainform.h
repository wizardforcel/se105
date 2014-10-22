#ifndef MAINFORM_H
#define MAINFORM_H

#include<FL\Fl.H>
#include<FL\Fl_Button.H>
#include<FL\Fl_Window.H>
#include<FL\Fl_OutPut.H>
#include<Fl\Fl_Box.H>
#include<FL\Fl_Radio_Round_Button.H>
#include<Windows.h>
#include"calculator.h"

#include<sstream>
#include<string>
using namespace std;

const unsigned int WIN_BACKGROUND = 53U;

class MainForm
{
public:
	static const int SPACE = 10;
	static const int BTN_LEN = 40;
	static const int BTN_WID = 30;

	Fl_Output *Output;
	Fl_Output *UpWnd;

	MainForm();
	~MainForm();

	void show();

private:

	int mode;//1:�������� 2:���м���

	Fl_Button *Button0;
	Fl_Button *Button1;
	Fl_Button *Button2;
	Fl_Button *Button3;
	Fl_Button *Button4;
	Fl_Button *Button5;
	Fl_Button *Button6;
	Fl_Button *Button7;
	Fl_Button *Button8;
	Fl_Button *Button9;
	Fl_Button *ButtonDot;//.
	Fl_Button *ButtonAdd;//+
	Fl_Button *ButtonSub;//-
	Fl_Button *ButtonMul;//*
	Fl_Button *ButtonDiv;///
	Fl_Button *ButtonEqe;//�Ⱥ�
	Fl_Button *ButtonSpr;//ȡ��
	Fl_Button *ButtonExc;//̾��
	Fl_Button *ButtonClr;//CE
	Fl_Button *ButtonBck;//�˸�
	Fl_Button *ButtonLeft;//(
	Fl_Button *ButtonRight;//)
	Fl_Button *ButtonAbs;//|

	Fl_Window *Form;
	
	Fl_Box *Box;
	Fl_Radio_Round_Button *SimRatio;
	Fl_Radio_Round_Button *LineRatio;

	MainForm& operator=(const MainForm&);
	MainForm(const MainForm&);

	//callbacks data���ڴ�thisָ��
	static void BtnNum_Click(Fl_Widget *w, void *data);//���� ����ȥĬ�ϵ�0��
	static void BtnDot_Click(Fl_Widget *w, void *data);//С���㣨����ȥĬ�ϵ�0��

	static void BtnSigDel0_Click(Fl_Widget *w, void *data);//���������ȥĬ�ϵ�0��
	static void BtnSigNDel0_Click(Fl_Widget *w, void *data);//�����������ȥĬ�ϵ�0�����ڵ�������ģʽֱ�ӵõ����

	static void BtnEqe_Click(Fl_Widget *w, void *data);//=
	static void BtnBck_Click(Fl_Widget *w, void *data);//<-
	static void BtnClr_Click(Fl_Widget *w, void *data);//CE

	static void RatioSim_Click(Fl_Widget *w, void *data);//step mode
	static void RatioLine_Click(Fl_Widget *w, void *data);//line mode

};
#endif