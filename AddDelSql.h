#pragma once
#include <msclr/marshal.h>
#include <string>
#include "MySqlCon.h"


namespace WinProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AddDelSql
	/// </summary>
	public ref class AddDelSql : public System::Windows::Forms::Form
	{
	public:
		AddDelSql(void)
		{
			InitializeComponent();
			this->btnAdd->FlatAppearance->BorderSize = 0;
			this->btnDel->FlatAppearance->BorderSize = 0;
			this->btnClose->FlatAppearance->BorderSize = 0;

			this->textBoxAdd->Text = gcnew String("ВВЕДИТЕ АДРЕС ДОМА");
			this->textBoxAdd->ForeColor = Color::Black;
			this->textBoxDel->Text = gcnew String("ВВЕДИТЕ АДРЕС ДОМА");
			this->textBoxDel->ForeColor = Color::Black;

			st_del = gcnew Stack();
			st_add = gcnew Stack();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AddDelSql()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labelAdd;
	protected:

	private: System::Windows::Forms::Button^ btnClose;
	private: System::Windows::Forms::TextBox^ textBoxAdd;

	private: System::Windows::Forms::Label^ labelDel;
	private: System::Windows::Forms::TextBox^ textBoxDel;
	private: System::Windows::Forms::Button^ btnAdd;
	private: System::Windows::Forms::Button^ btnDel;


	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddDelSql::typeid));
			this->labelAdd = (gcnew System::Windows::Forms::Label());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->textBoxAdd = (gcnew System::Windows::Forms::TextBox());
			this->labelDel = (gcnew System::Windows::Forms::Label());
			this->textBoxDel = (gcnew System::Windows::Forms::TextBox());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->btnDel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// labelAdd
			// 
			this->labelAdd->AutoSize = true;
			this->labelAdd->BackColor = System::Drawing::Color::Transparent;
			this->labelAdd->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->labelAdd->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelAdd->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->labelAdd->Location = System::Drawing::Point(28, 81);
			this->labelAdd->Name = L"labelAdd";
			this->labelAdd->Size = System::Drawing::Size(267, 32);
			this->labelAdd->TabIndex = 0;
			this->labelAdd->Text = L"Добавить новый дом";
			// 
			// btnClose
			// 
			this->btnClose->BackColor = System::Drawing::Color::Transparent;
			this->btnClose->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnClose.BackgroundImage")));
			this->btnClose->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClose->Location = System::Drawing::Point(443, 12);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(41, 40);
			this->btnClose->TabIndex = 1;
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &AddDelSql::btnClose_Click);
			// 
			// textBoxAdd
			// 
			this->textBoxAdd->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxAdd->Location = System::Drawing::Point(33, 113);
			this->textBoxAdd->Name = L"textBoxAdd";
			this->textBoxAdd->Size = System::Drawing::Size(273, 33);
			this->textBoxAdd->TabIndex = 2;
			this->textBoxAdd->Enter += gcnew System::EventHandler(this, &AddDelSql::textBoxAdd_Enter);
			this->textBoxAdd->Leave += gcnew System::EventHandler(this, &AddDelSql::textBoxAdd_Leave);
			// 
			// labelDel
			// 
			this->labelDel->AutoSize = true;
			this->labelDel->BackColor = System::Drawing::Color::Transparent;
			this->labelDel->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelDel->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->labelDel->Location = System::Drawing::Point(27, 152);
			this->labelDel->Name = L"labelDel";
			this->labelDel->Size = System::Drawing::Size(166, 32);
			this->labelDel->TabIndex = 3;
			this->labelDel->Text = L"Удалить дом";
			// 
			// textBoxDel
			// 
			this->textBoxDel->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxDel->Location = System::Drawing::Point(33, 187);
			this->textBoxDel->Name = L"textBoxDel";
			this->textBoxDel->Size = System::Drawing::Size(273, 33);
			this->textBoxDel->TabIndex = 4;
			this->textBoxDel->Enter += gcnew System::EventHandler(this, &AddDelSql::textBoxDel_Enter);
			this->textBoxDel->Leave += gcnew System::EventHandler(this, &AddDelSql::textBoxDel_Leave);
			// 
			// btnAdd
			// 
			this->btnAdd->BackColor = System::Drawing::Color::Transparent;
			this->btnAdd->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAdd.BackgroundImage")));
			this->btnAdd->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnAdd->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAdd->Location = System::Drawing::Point(323, 115);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(41, 36);
			this->btnAdd->TabIndex = 5;
			this->btnAdd->UseVisualStyleBackColor = false;
			this->btnAdd->Click += gcnew System::EventHandler(this, &AddDelSql::btnAdd_Click);
			// 
			// btnDel
			// 
			this->btnDel->BackColor = System::Drawing::Color::Transparent;
			this->btnDel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnDel.BackgroundImage")));
			this->btnDel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnDel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDel->Location = System::Drawing::Point(323, 187);
			this->btnDel->Name = L"btnDel";
			this->btnDel->Size = System::Drawing::Size(41, 36);
			this->btnDel->TabIndex = 6;
			this->btnDel->UseVisualStyleBackColor = false;
			this->btnDel->Click += gcnew System::EventHandler(this, &AddDelSql::btnDel_Click);
			// 
			// AddDelSql
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(496, 298);
			this->Controls->Add(this->btnDel);
			this->Controls->Add(this->btnAdd);
			this->Controls->Add(this->textBoxDel);
			this->Controls->Add(this->labelDel);
			this->Controls->Add(this->textBoxAdd);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->labelAdd);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AddDelSql";
			this->Text = L"AddDelSql";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &AddDelSql::AddDelSql_FormClosed);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &AddDelSql::AddDelSql_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &AddDelSql::AddDelSql_MouseMove);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: std::string Str_to_str(String^ str)
	{
		System::IntPtr ptr = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str);
		std::string res_str = static_cast<char*>(ptr.ToPointer());
		System::Runtime::InteropServices::Marshal::FreeHGlobal(ptr);
		return res_str;
	}
	private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Drawing::Point lastPoint;
private: System::Void AddDelSql_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (e->Button == System::Windows::Forms::MouseButtons::Left)
	{
		this->Left += e->X - lastPoint.X;
		this->Top += e->Y - lastPoint.Y;
	}
}
private: System::Void AddDelSql_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (e->Button == System::Windows::Forms::MouseButtons::Left)
	{
		lastPoint = e->Location;
	}
}
private: System::Void textBoxAdd_Enter(System::Object^ sender, System::EventArgs^ e)
{
	if (this->textBoxAdd->Text == "ВВЕДИТЕ АДРЕС ДОМА")
	{
		this->textBoxAdd->Text = "";
		this->textBoxAdd->ForeColor = Color::Green;
	}
}
private: System::Void textBoxAdd_Leave(System::Object^ sender, System::EventArgs^ e)
{
	if (this->textBoxAdd->Text == "")
	{
		this->textBoxAdd->Text = "ВВЕДИТЕ АДРЕС ДОМА";
		this->textBoxAdd->ForeColor = Color::Black;
	}
}
private: System::Void textBoxDel_Enter(System::Object^ sender, System::EventArgs^ e) 
{
	if (this->textBoxDel->Text == "ВВЕДИТЕ АДРЕС ДОМА")
	{
		this->textBoxDel->Text = "";
		this->textBoxDel->ForeColor = Color::Red;
	}
}
private: System::Void textBoxDel_Leave(System::Object^ sender, System::EventArgs^ e) 
{
	if (this->textBoxDel->Text == "")
	{
		this->textBoxDel->Text = "ВВЕДИТЕ АДРЕС ДОМА";
		this->textBoxDel->ForeColor = Color::Black;
	}
}
public: System::Collections::Stack^ st_add;
private: System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e) 
{
	std::string house = Str_to_str(this->textBoxAdd->Text);
	MySqlCon Db;
	Db.connection_to_database();
	Db.add_house_user(house);
	st_add->Push(this->textBoxAdd->Text);

}
public: System::Collections::Stack^ st_del;
private: System::Void btnDel_Click(System::Object^ sender, System::EventArgs^ e) 
{
	std::string house = Str_to_str(this->textBoxDel->Text);
	MySqlCon Db;
	Db.connection_to_database();
	Db.del_house_user(house);
	st_del->Push(this->textBoxDel->Text);
}
private: System::Void AddDelSql_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) 
{
	MessageBox::Show("Дождитесь удаление/добавление пользователя, после можете закрыть окно", "OK", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
}
};
}

