#include"mainform.h"

void main()
{
	MainForm *mainform = new MainForm();

	mainform->show();

	delete mainform;

	exit(0);
}


int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{

	MainForm *mainform = new MainForm();

	mainform->show();

	delete mainform;

	return 0;
}
