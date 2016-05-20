#pragma once

namespace tic {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	int matrix[3][3] = { {}, {}, {} };
	static bool repeat = true;
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	
	protected:

	protected:
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button11;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->AccessibleDescription = L"";
			this->button1->AccessibleName = L"b1";
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 58);
			this->button1->TabIndex = 0;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click1);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(93, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 58);
			this->button2->TabIndex = 1;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(174, 12);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 58);
			this->button3->TabIndex = 2;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(12, 76);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 58);
			this->button4->TabIndex = 3;
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(93, 76);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 58);
			this->button5->TabIndex = 4;
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(174, 76);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 58);
			this->button6->TabIndex = 5;
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(12, 140);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(75, 58);
			this->button7->TabIndex = 6;
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(93, 140);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(75, 58);
			this->button8->TabIndex = 7;
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(174, 140);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(75, 58);
			this->button9->TabIndex = 8;
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(12, 204);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(156, 33);
			this->button10->TabIndex = 9;
			this->button10->Text = L"New Game";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(174, 204);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(75, 33);
			this->button11->TabIndex = 10;
			this->button11->Text = L"Exit";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
		static int counter = 0;

	private: System::Void button1_Click1(System::Object^  sender, System::EventArgs^  e) {
		if (button1->Text == "")
			if (counter % 2 == 0){
				matrix[0][0] = 1;
				button1->Text = "X";
				counter++;
				check();
			}
			else {
				matrix[0][0] = 2;
				button1->Text = "O";
				counter++;
				check();
			}
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		if (button2->Text == "")
		if (counter % 2 == 0){
			matrix[0][1] = 1;
			button2->Text = "X";
			counter++;
			check();
		}
		else {
			matrix[0][1] = 2; 
			button2->Text = "O";
			counter++;
			check();
		}
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		if (button3->Text == "")
		if (counter % 2 == 0){
			matrix[0][2] = 1;
			button3->Text = "X";
			counter++;
			check();
		}
		else {
			matrix[0][2] = 2;
			button3->Text = "O";
			counter++;
			check();
		}
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		if (button4->Text == "")
		if (counter % 2 == 0){
			matrix[1][0] = 1;
			button4->Text = "X";
			counter++;
			check();
		}
		else {
			matrix[1][0] = 2;
			button4->Text = "O";
			counter++;
			check();
		}
	}
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
		if (button5->Text == "")
			if (counter % 2 == 0){
			matrix[1][1] = 1;
			button5->Text = "X";
			counter++;
			check();
		}
		else {
			matrix[1][1] = 2;
			button5->Text = "O";
			counter++;
			check();
		}
	}
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
		if (button6->Text == "")
		if (counter % 2 == 0){
			matrix[1][2] = 1;
			button6->Text = "X";
			counter++;
			check();
		}
		else {
			matrix[1][2] = 2;
			button6->Text = "O";
			counter++;
			check();
		}
	}
	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
		if (button7->Text == "")
		if (counter % 2 == 0){
			matrix[2][0] = 1;
			button7->Text = "X";
			counter++;
			check();
		}
		else {
			matrix[2][0] = 2;
			button7->Text = "O";
			counter++;
			check();
		}
	}
	private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
		if (button8->Text == "")
		if (counter % 2 == 0){
			matrix[2][1] = 1;
			button8->Text = "X";
			counter++;
			check();
		}
		else {
			matrix[2][1] = 2;
			button8->Text = "O";
			counter++;
			check();
		}
	}
	private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
		if (button9->Text == "")
		if (counter % 2 == 0){
			matrix[2][2] = 1;
			button9->Text = "X";
			counter++;
			check();
		}
		else {
			matrix[2][2] = 2;
			button9->Text = "O";
			counter++;
			check();
		}
	}

	static void check(){
		if(
			(matrix[0][0] == matrix[1][0] && matrix[0][0] == matrix[2][0] && matrix[0][0] == 1) ||
			(matrix[0][1] == matrix[1][1] && matrix[0][1] == matrix[2][1] && matrix[0][1] == 1) ||
			(matrix[0][2] == matrix[1][2] && matrix[0][2] == matrix[2][2] && matrix[0][2] == 1) ||

			(matrix[0][0] == matrix[0][1] && matrix[0][0] == matrix[0][2] && matrix[0][0] == 1) ||
			(matrix[1][0] == matrix[1][1] && matrix[1][0] == matrix[1][2] && matrix[1][0] == 1) ||
			(matrix[2][0] == matrix[2][1] && matrix[2][0] == matrix[2][2] && matrix[2][0] == 1) ||

			(matrix[1][1] == matrix[0][0] && matrix[1][1] == matrix[2][2] && matrix[1][1] == 1) ||
			(matrix[1][1] == matrix[2][0] && matrix[1][1] == matrix[0][2] && matrix[1][1] == 1)
			){

				MessageBox::Show("X - winners");
				//Application::Exit();
		}
		else if(
			(matrix[0][0] == matrix[1][0] && matrix[0][0] == matrix[2][0] && matrix[0][0] == 2) ||
			(matrix[0][1] == matrix[1][1] && matrix[0][1] == matrix[2][1] && matrix[0][1] == 2) ||
			(matrix[0][2] == matrix[1][2] && matrix[0][2] == matrix[2][2] && matrix[0][2] == 2) ||

			(matrix[0][0] == matrix[0][1] && matrix[0][0] == matrix[0][2] && matrix[0][0] == 2) ||
			(matrix[1][0] == matrix[1][1] && matrix[1][0] == matrix[1][2] && matrix[1][0] == 2) ||
			(matrix[2][0] == matrix[2][1] && matrix[2][0] == matrix[2][2] && matrix[2][0] == 2) ||

			(matrix[1][1] == matrix[0][0] && matrix[1][1] == matrix[2][2] && matrix[1][1] == 2) ||
			(matrix[1][1] == matrix[2][0] && matrix[1][1] == matrix[0][2] && matrix[1][1] == 2)
			){

			MessageBox::Show("O - winners");

			//Application::Exit();
		}
			

		else{
			if (counter == 9)
			MessageBox::Show("\t\tDraw");
		}
			
	}
private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			matrix[i][j] = 0;
	counter = 0;
	button1->Text = "";
	button2->Text = "";
	button3->Text = "";
	button4->Text = "";
	button5->Text = "";
	button6->Text = "";
	button7->Text = "";
	button8->Text = "";
	button9->Text = "";
	}

private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
	repeat = false;
	Application::Exit();
}
};
}
