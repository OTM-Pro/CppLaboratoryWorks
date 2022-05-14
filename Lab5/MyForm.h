#pragma once
#include <string.h>

namespace Lab5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	private:
		SqlConnection^ dataBaseCon;
		SqlDataAdapter^ dataAdapter;
		DataSet^ dataSet;
		bool tableIsOpened = false;


	private: System::Windows::Forms::Button^ button2;

	private: System::Windows::Forms::Button^ button3;


	private: System::Windows::Forms::Button^ button1;


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

	protected:
	private: System::Windows::Forms::DataGridView^ dataGridView1;




	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label1;

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
#pragma endregion
private: System::Void InitializeComponent() {
	this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
	this->label1 = (gcnew System::Windows::Forms::Label());
	this->button2 = (gcnew System::Windows::Forms::Button());
	this->button3 = (gcnew System::Windows::Forms::Button());
	this->button1 = (gcnew System::Windows::Forms::Button());
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
	this->SuspendLayout();
	// 
	// dataGridView1
	// 
	this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
	this->dataGridView1->Location = System::Drawing::Point(12, 12);
	this->dataGridView1->Name = L"dataGridView1";
	this->dataGridView1->Size = System::Drawing::Size(480, 537);
	this->dataGridView1->TabIndex = 0;
	// 
	// label1
	// 
	this->label1->Location = System::Drawing::Point(12, 566);
	this->label1->Name = L"label1";
	this->label1->Size = System::Drawing::Size(635, 22);
	this->label1->TabIndex = 3;
	this->label1->Text = L"label1";
	this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
	// 
	// button2
	// 
	this->button2->Location = System::Drawing::Point(498, 55);
	this->button2->Name = L"button2";
	this->button2->Size = System::Drawing::Size(148, 37);
	this->button2->TabIndex = 4;
	this->button2->Text = L"Save";
	this->button2->UseVisualStyleBackColor = true;
	this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
	// 
	// button3
	// 
	this->button3->Location = System::Drawing::Point(499, 98);
	this->button3->Name = L"button3";
	this->button3->Size = System::Drawing::Size(148, 37);
	this->button3->TabIndex = 4;
	this->button3->Text = L"Delete Row";
	this->button3->UseVisualStyleBackColor = true;
	this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
	// 
	// button1
	// 
	this->button1->Location = System::Drawing::Point(498, 12);
	this->button1->Name = L"button1";
	this->button1->Size = System::Drawing::Size(148, 37);
	this->button1->TabIndex = 4;
	this->button1->Text = L"Open";
	this->button1->UseVisualStyleBackColor = true;
	this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
	// 
	// MyForm
	// 
	this->ClientSize = System::Drawing::Size(659, 597);
	this->Controls->Add(this->button1);
	this->Controls->Add(this->button3);
	this->Controls->Add(this->button2);
	this->Controls->Add(this->label1);
	this->Controls->Add(this->dataGridView1);
	this->Name = L"MyForm";
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
	this->ResumeLayout(false);

}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		dataSet = gcnew DataSet();
		dataBaseCon = gcnew SqlConnection("Data Source=el-1-60-02;Initial Catalog=testDataBase;Integrated Security=True");
		String^ query = "select MainTable.id, MainTable.name, MainTable.age, Dic.Post from MainTable, Dic where Dic.id = MainTable.postId";
		dataAdapter = gcnew SqlDataAdapter(query, dataBaseCon);
		dataBaseCon->Open();
		dataAdapter->Fill(dataSet);
		dataBaseCon->Close();
		dataGridView1->DataSource = dataSet->Tables[0];
		tableIsOpened = true;
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (dataGridView1->SelectedRows->Count != 0)
		{
			dataGridView1->Rows->Remove(dataGridView1->SelectedRows[0]);
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		
	}
};
}
