#include"mainform.h"

MainForm::MainForm() : mode(2)
{
	//创建窗体

	this->Form = new Fl_Window(500, 200 ,6 * SPACE + 5 * BTN_LEN, 9 * SPACE + 8 * BTN_WID, "Simple Calc");
	this->Form->color(WIN_BACKGROUND);
	
	//自下至上依次添加控件
	this->Button0 = new Fl_Button(SPACE, 7 * BTN_WID + 8 * SPACE, BTN_LEN * 2 + SPACE, BTN_WID, "0");
	this->Button0->color(WIN_BACKGROUND);
	this->ButtonDot = new Fl_Button(SPACE * 3 + BTN_LEN * 2, 7 * BTN_WID + 8 * SPACE, BTN_LEN, BTN_WID, ".");
	this->ButtonDot->color(WIN_BACKGROUND);
	this->ButtonAdd = new Fl_Button(SPACE * 4 + BTN_LEN * 3, 7 * BTN_WID + 8 * SPACE, BTN_LEN, BTN_WID, "+");
	this->ButtonAdd->color(WIN_BACKGROUND);

	this->Button1 = new Fl_Button(SPACE, 6 * BTN_WID + 7 * SPACE, BTN_LEN, BTN_WID, "1");
	this->Button1->color(WIN_BACKGROUND);
	this->Button2 = new Fl_Button(SPACE * 2 + BTN_LEN, 6 * BTN_WID + 7 * SPACE, BTN_LEN, BTN_WID, "2");
	this->Button2->color(WIN_BACKGROUND);
	this->Button3 = new Fl_Button(SPACE * 3 + BTN_LEN * 2, 6 * BTN_WID + 7 * SPACE, BTN_LEN, BTN_WID, "3");
	this->Button3->color(WIN_BACKGROUND);
	this->ButtonSub = new Fl_Button(SPACE * 4 + BTN_LEN * 3, 6 * BTN_WID + 7 * SPACE, BTN_LEN, BTN_WID, "-");
	this->ButtonSub->color(WIN_BACKGROUND);
	this->ButtonEqe = new Fl_Button(SPACE * 5 + BTN_LEN * 4, 6 * BTN_WID + 7 * SPACE, BTN_LEN, BTN_WID * 2 + SPACE, "=");
	this->ButtonEqe->color(WIN_BACKGROUND);

	this->Button4 = new Fl_Button(SPACE, 5 * BTN_WID + 6 * SPACE, BTN_LEN, BTN_WID, "4");
	this->Button4->color(WIN_BACKGROUND);
	this->Button5 = new Fl_Button(SPACE * 2 + BTN_LEN, 5 * BTN_WID + 6 * SPACE, BTN_LEN, BTN_WID, "5");
	this->Button5->color(WIN_BACKGROUND);
	this->Button6 = new Fl_Button(SPACE * 3 + BTN_LEN * 2, 5 * BTN_WID + 6 * SPACE, BTN_LEN, BTN_WID, "6");
	this->Button6->color(WIN_BACKGROUND);
	this->ButtonMul = new Fl_Button(SPACE * 4 + BTN_LEN * 3, 5 * BTN_WID + 6 * SPACE, BTN_LEN, BTN_WID, "*");
	this->ButtonMul->color(WIN_BACKGROUND);
	this->ButtonExc = new Fl_Button(SPACE * 5 + BTN_LEN * 4, 5 * BTN_WID + 6 * SPACE, BTN_LEN, BTN_WID, "!");
	this->ButtonExc->color(WIN_BACKGROUND);

	this->Button7 = new Fl_Button(SPACE, 4 * BTN_WID + 5 * SPACE, BTN_LEN, BTN_WID, "7");
	this->Button7->color(WIN_BACKGROUND);
	this->Button8 = new Fl_Button(SPACE * 2 + BTN_LEN, 4 * BTN_WID + 5 * SPACE, BTN_LEN, BTN_WID, "8");
	this->Button8->color(WIN_BACKGROUND);
	this->Button9 = new Fl_Button(SPACE * 3 + BTN_LEN * 2, 4 * BTN_WID + 5 * SPACE, BTN_LEN, BTN_WID, "9");
	this->Button9->color(WIN_BACKGROUND);
	this->ButtonDiv = new Fl_Button(SPACE * 4 + BTN_LEN * 3, 4 * BTN_WID + 5 * SPACE, BTN_LEN, BTN_WID, "/");
	this->ButtonDiv->color(WIN_BACKGROUND);
	this->ButtonSpr = new Fl_Button(SPACE * 5 + BTN_LEN * 4, 4 * BTN_WID + 5 * SPACE, BTN_LEN, BTN_WID, "%");
	this->ButtonSpr->color(WIN_BACKGROUND);

	this->ButtonBck = new Fl_Button(SPACE, 3 * BTN_WID + 4 * SPACE, BTN_LEN, BTN_WID, "<-");
	this->ButtonBck->color(WIN_BACKGROUND);
	this->ButtonClr = new Fl_Button(SPACE * 2 + BTN_LEN, 3 * BTN_WID + 4 * SPACE, BTN_LEN, BTN_WID, "CE");
	this->ButtonClr->color(WIN_BACKGROUND);
	this->ButtonAbs = new Fl_Button(SPACE * 3 + BTN_LEN * 2, 3 * BTN_WID + 4 * SPACE, BTN_LEN, BTN_WID, "|");
	this->ButtonAbs->color(WIN_BACKGROUND);
	this->ButtonLeft = new Fl_Button(SPACE * 4 + BTN_LEN * 3, 3 * BTN_WID + 4 * SPACE, BTN_LEN, BTN_WID, "(");
	this->ButtonLeft->color(WIN_BACKGROUND);
	this->ButtonRight = new Fl_Button(SPACE * 5 + BTN_LEN * 4, 3 * BTN_WID + 4 * SPACE, BTN_LEN, BTN_WID, ")");
	this->ButtonRight->color(WIN_BACKGROUND);

	//label()返回按钮上面的东西

	this->Output = new Fl_Output(SPACE, SPACE * 2 + BTN_WID * 2, 5 * BTN_LEN + 4 * SPACE, BTN_WID + SPACE);
	this->Output->value("0");
	this->UpWnd = new Fl_Output(SPACE, SPACE * 2 + BTN_WID, 5 * BTN_LEN + 4 * SPACE, BTN_WID);
	
	this->Box = new Fl_Box(SPACE, SPACE, 5 * BTN_LEN + 4 * SPACE, BTN_WID);
	this->Box->box(FL_THIN_UP_BOX);
	this->Box->color(WIN_BACKGROUND);

	this->SimRatio = new Fl_Radio_Round_Button (SPACE + BTN_WID / 2, SPACE, BTN_LEN * 2 , BTN_WID,"step mode");
	this->LineRatio = new Fl_Radio_Round_Button (SPACE * 4 + BTN_WID * 7 / 2, SPACE, BTN_LEN * 2, BTN_WID,"line mode");
	this->LineRatio->value(1);//使它选中

	this->Form->end();

	//绑定回调
	Button0->callback((Fl_Callback *)BtnNum_Click, this);
	Button1->callback((Fl_Callback *)BtnNum_Click, this);
	Button2->callback((Fl_Callback *)BtnNum_Click, this);
	Button3->callback((Fl_Callback *)BtnNum_Click, this);
	Button4->callback((Fl_Callback *)BtnNum_Click, this);
	Button5->callback((Fl_Callback *)BtnNum_Click, this);
	Button6->callback((Fl_Callback *)BtnNum_Click, this);
	Button7->callback((Fl_Callback *)BtnNum_Click, this);
	Button8->callback((Fl_Callback *)BtnNum_Click, this);
	Button9->callback((Fl_Callback *)BtnNum_Click, this);
	ButtonDot->callback((Fl_Callback *)BtnDot_Click, this);
	ButtonAdd->callback((Fl_Callback *)BtnSigNDel0_Click, this);
	ButtonSub->callback((Fl_Callback *)BtnSigNDel0_Click, this);
	ButtonMul->callback((Fl_Callback *)BtnSigNDel0_Click, this);
	ButtonDiv->callback((Fl_Callback *)BtnSigNDel0_Click, this);
	ButtonLeft->callback((Fl_Callback *)BtnSigDel0_Click, this);
	ButtonRight->callback((Fl_Callback *)BtnSigDel0_Click, this);
	ButtonAbs->callback((Fl_Callback *)BtnSigDel0_Click, this);
	ButtonSpr->callback((Fl_Callback *)BtnSigNDel0_Click, this);
	ButtonExc->callback((Fl_Callback *)BtnSigNDel0_Click, this);

	ButtonClr->callback((Fl_Callback *)BtnClr_Click, this);
	ButtonBck->callback((Fl_Callback *)BtnBck_Click, this);
	ButtonEqe->callback((Fl_Callback *)BtnEqe_Click, this);

	SimRatio->callback((Fl_Callback *)RatioSim_Click, this);
	LineRatio->callback((Fl_Callback *)RatioLine_Click, this);

	Fl::scheme("gtk+");

}

void MainForm::show()
{
	this->Form->show();
	Fl::run();
}

MainForm::~MainForm()
{
	delete this->Button0;
	delete this->Button1;
	delete this->Button2;
	delete this->Button3;
	delete this->Button4;
	delete this->Button5;
	delete this->Button6;
	delete this->Button7;
	delete this->Button8;
	delete this->Button9;
	delete this->ButtonAdd;
	delete this->ButtonSub;
	delete this->ButtonMul;
	delete this->ButtonDiv;
	delete this->ButtonEqe;
	delete this->ButtonClr;
	delete this->ButtonBck;
	delete this->ButtonExc;
	delete this->ButtonSpr;
	delete this->ButtonAbs;
	delete this->ButtonLeft;
	delete this->ButtonRight;

	delete this->UpWnd;
	delete this->Output;
	
	delete this->Box;
	delete this->SimRatio;
	delete this->LineRatio;
	delete this->Form;
}

void MainForm::BtnNum_Click(Fl_Widget *w, void *data)//这个不变
{
	Fl_Button *lpbtn = (Fl_Button *)w;
	MainForm *lpwnd = (MainForm *)data;
	string tmp = lpwnd->Output->value();
	if(tmp == "0")
		tmp = "";
	tmp += lpbtn->label();
	lpwnd->Output->value(tmp.c_str());
}

void MainForm::BtnSigNDel0_Click(Fl_Widget *w, void *data)
{
	
	try
	{
		Fl_Button *lpbtn = (Fl_Button *)w;
		MainForm *lpwnd = (MainForm *)data;
		string tmp = lpwnd->Output->value();
		if(tmp == "0" && lpbtn->label() == "-")//特殊情况
		{
			lpwnd->Output->value("-");
			return;
		}
		if(lpwnd->mode == 1)//单步模式
		{
			lpwnd->UpWnd->value((tmp + " =").c_str());
			Calculator *calc = new Calculator(tmp + ";");
			double val = calc->calculate();
			stringstream ss;
			ss.precision(10);
			ss<<val;
			ss>>tmp;
			delete calc;
		}
		tmp += lpbtn->label();
		lpwnd->Output->value(tmp.c_str());
	}
	catch(exception& ex)
	{
		MainForm *lpwnd = (MainForm *)data;
		lpwnd->Output->value("0");
		//fl_alert(ex.what());
		MessageBoxA(0, ex.what(), "错误！",0);
	}
}

void MainForm::BtnSigDel0_Click(Fl_Widget *w, void *data)
{
	Fl_Button *lpbtn = (Fl_Button *)w;
	MainForm *lpwnd = (MainForm *)data;
	string tmp = lpwnd->Output->value();
	if(tmp == "0")
		tmp = "";
	tmp += lpbtn->label();
	lpwnd->Output->value(tmp.c_str());

}

void MainForm::BtnClr_Click(Fl_Widget *w, void *data)//这个也不变
{
	MainForm *lpwnd = (MainForm *)data;
	lpwnd->Output->value("0");
}

void MainForm::BtnBck_Click(Fl_Widget *w, void *data)//这个也不变
{
	MainForm *lpwnd = (MainForm *)data;
	Fl_Button *lpbtn = (Fl_Button *)w;
	string tmp = lpwnd->Output->value();
	int len = tmp.length();
	if(len == 1)
	{
		lpwnd->Output->value("0");
	}
	else
	{
		tmp = tmp.substr(0, len - 1);
		lpwnd->Output->value(tmp.c_str());
	}
}

void MainForm::BtnEqe_Click(Fl_Widget *w, void *data)
{
	try
	{
		MainForm *lpwnd = (MainForm *)data;
		Fl_Button *lpbtn = (Fl_Button *)w;
		string tmp = lpwnd->Output->value();
		lpwnd->UpWnd->value((tmp + " =").c_str());
		Calculator *calc = new Calculator(tmp + ";");
		double val = calc->calculate();
		stringstream ss;
		ss.precision(10);
		ss<<val;
		ss>>tmp;
		lpwnd->Output->value(tmp.c_str());
		delete calc;
	}
	catch(exception& ex)
	{
		MainForm *lpwnd = (MainForm *)data;
		lpwnd->Output->value("0");
		//fl_alert(ex.what());
		MessageBoxA(0, ex.what(), "错误！",0);
	}
}

void MainForm::BtnDot_Click(Fl_Widget *w, void *data)//不消去前方的零
{
	Fl_Button *lpbtn = (Fl_Button *)w;
	MainForm *lpwnd = (MainForm *)data;
	string tmp = lpwnd->Output->value();
	tmp += lpbtn->label();
	lpwnd->Output->value(tmp.c_str());
}

void MainForm::RatioSim_Click(Fl_Widget *w, void *data)
{
	MainForm *lpwnd = (MainForm *)data;
	lpwnd->mode = 1;
}

void MainForm::RatioLine_Click(Fl_Widget *w, void *data)
{
	MainForm *lpwnd = (MainForm *)data;
	lpwnd->mode = 2;
}