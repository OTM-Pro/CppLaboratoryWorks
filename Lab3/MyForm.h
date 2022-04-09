#pragma once
#include "string"

namespace TestWinFormAppCpp {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:




	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::Button^ button2;



	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.25F));
			this->button1->Location = System::Drawing::Point(146, 123);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(136, 95);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Open file";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.25F));
			this->textBox3->Location = System::Drawing::Point(466, 190);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(323, 225);
			this->textBox3->TabIndex = 1;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(462, 167);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(69, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Output:";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.25F));
			this->textBox1->Location = System::Drawing::Point(466, 123);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(323, 26);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"0";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox1_KeyPress);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(462, 100);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(98, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Array size: ";
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->FileName = L"Output";
			this->saveFileDialog1->Filter = L"Text (*.txt)|*.txt|All files (*.*)|*.*";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.25F));
			this->button2->Location = System::Drawing::Point(146, 267);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(136, 95);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Save to file";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(940, 593);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		String^ fileName;
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) fileName = openFileDialog1->FileName;

		String^ str;
		StreamReader^ sr;
		int arraySize = System::Convert::ToInt32(textBox1->Text);
		if (arraySize == 0)
		{
			sr = File::OpenText(fileName);
			while ((str = sr->ReadLine()) != nullptr) arraySize++;
		}

		array< float >^ arr = gcnew array< float >(arraySize);
		sr = File::OpenText(fileName);
		textBox3->Text = "Array: ";
		for (int i = 0; i < arraySize; i++)
		{
			str = sr->ReadLine();
			arr[i] = System::Convert::ToDouble(str);
			textBox3->Text += str + " ";
		}

		float sum = 0, max = 0, min = 999999999, pro = 1;
		int maxIndex, minIndex;

		for (int i = 0; i < arraySize; i++)
		{
			if (arr[i] < 0) sum += arr[i];
			if (arr[i] > max)
			{
				max = arr[i];
				maxIndex = i;
			}
			if (arr[i] < min)
			{
				min = arr[i];
				minIndex = i;
			}
		}
		textBox3->Text += Environment::NewLine + "Sum: " + sum + Environment::NewLine;

		if (maxIndex > minIndex) for (int i = minIndex + 1; i < maxIndex; i++) pro *= arr[i];
		else for (int i = maxIndex + 1; i < minIndex; i++) pro *= arr[i];
		textBox3->Text += "Product: " + pro + Environment::NewLine;

		for (int i = 0; i < arraySize; i++)
		{
			for (int j = 0; j < arraySize - (i + 1); j++)
			{
				if (arr[j] > arr[j + 1])
				{
					float x = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = x;
				}
			}
		}
		textBox3->Text += "Sorted array: ";
		for (int i = 0; i < arraySize; i++) textBox3->Text += System::Convert::ToString(arr[i]) + " ";
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		String^ fileName;
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) fileName = saveFileDialog1->FileName;
		System::IO::File::WriteAllText(fileName, textBox3->Text);
		MessageBox::Show("‘айл успешно сохранен.\n", "—охранено", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	private: System::Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
	{
		if (((e->KeyChar >= '0') && (e->KeyChar <= '9')) || (e->KeyChar == (char)Keys::Back)) return;
		e->Handled = true;
	}
};
}
