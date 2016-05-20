#include "MyForm.h"

using namespace System::Windows::Forms;

int main(){
	
	do{
		Application::Run(gcnew tic::MyForm);
	} while (tic::repeat);
	return 0;
}