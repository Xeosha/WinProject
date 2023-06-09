#pragma once

#include <iostream>
#include "MyForm.h"
#include "MySqlCon.h"

namespace WinProject {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// ������ ��� Autorisation
	/// </summary>
	/// 


	public ref class Autorisation : public System::Windows::Forms::Form
	{
	private: 
		std::string String_to_string(System::String^ str)
		{
			System::IntPtr ptr = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str);
			std::string res_str = static_cast<char*>(ptr.ToPointer());
			System::Runtime::InteropServices::Marshal::FreeHGlobal(ptr);
			return res_str;
		}
	public:
		Autorisation(void)
		{
			
			InitializeComponent();
			this->TextLogin->Text = "������� �����";
			TextLogin->ForeColor = Color::WhiteSmoke;
			this->TextPassword->Text = "������� ������";
			TextPassword->ForeColor = Color::WhiteSmoke;
			// ��������� ���������� � ����������� �� ������
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			// ������ ��� ������
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			// ��������� ���������� ������
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;

			btnClose->FlatAppearance->BorderSize = 0;
			button2->FlatAppearance->BorderSize = 0;
			button3->FlatAppearance->BorderSize = 0;

		}


	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~Autorisation()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^ TextLogin;

	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnClose;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::TextBox^ TextPassword;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;


	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Autorisation::typeid));
			this->TextLogin = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->TextPassword = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// TextLogin
			// 
			this->TextLogin->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)));
			this->TextLogin->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(204), true));
			this->TextLogin->ForeColor = System::Drawing::Color::White;
			this->TextLogin->Location = System::Drawing::Point(837, 200);
			this->TextLogin->Multiline = true;
			this->TextLogin->Name = L"TextLogin";
			this->TextLogin->Size = System::Drawing::Size(243, 33);
			this->TextLogin->TabIndex = 1;
			this->TextLogin->Text = L"������� �����";
			this->TextLogin->Enter += gcnew System::EventHandler(this, &Autorisation::TextLogin_Enter);
			this->TextLogin->Leave += gcnew System::EventHandler(this, &Autorisation::TextLogin_Leave);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)));
			this->button1->Location = System::Drawing::Point(861, 305);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(195, 75);
			this->button1->TabIndex = 3;
			this->button1->Text = L"��������������";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Autorisation::btnNumberClick);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Transparent;
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->button2->Location = System::Drawing::Point(884, 386);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(156, 20);
			this->button2->TabIndex = 5;
			this->button2->Text = L"������ ������";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Autorisation::btnNumberClick);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Transparent;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->button3->Location = System::Drawing::Point(940, 277);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(151, 22);
			this->button3->TabIndex = 6;
			this->button3->Text = L"������� �������";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Autorisation::btnNumberClick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(910, 160);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(88, 26);
			this->label1->TabIndex = 7;
			this->label1->Text = L"�����";
			// 
			// btnClose
			// 
			this->btnClose->BackColor = System::Drawing::Color::Transparent;
			this->btnClose->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnClose.BackgroundImage")));
			this->btnClose->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClose->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(98)), static_cast<System::Int32>(static_cast<System::Byte>(163)),
				static_cast<System::Int32>(static_cast<System::Byte>(247)));
			this->btnClose->Location = System::Drawing::Point(1130, 12);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(49, 47);
			this->btnClose->TabIndex = 8;
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &Autorisation::BtnClose);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// TextPassword
			// 
			this->TextPassword->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)));
			this->TextPassword->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(204), true));
			this->TextPassword->ForeColor = System::Drawing::Color::White;
			this->TextPassword->Location = System::Drawing::Point(837, 238);
			this->TextPassword->Multiline = true;
			this->TextPassword->Name = L"TextPassword";
			this->TextPassword->Size = System::Drawing::Size(243, 33);
			this->TextPassword->TabIndex = 10;
			this->TextPassword->Text = L"������� ������";
			this->TextPassword->Enter += gcnew System::EventHandler(this, &Autorisation::TextPassword_Enter);
			this->TextPassword->Leave += gcnew System::EventHandler(this, &Autorisation::TextPassword_Leave);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(121, 213);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(222, 278);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 11;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(37, 21);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(394, 313);
			this->pictureBox2->TabIndex = 12;
			this->pictureBox2->TabStop = false;
			// 
			// Autorisation
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::SystemColors::ControlLight;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1191, 583);
			this->ControlBox = false;
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->TextPassword);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->TextLogin);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Autorisation";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Autorisation";
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Autorisation::Autorisation_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Autorisation::Autorisation_MouseMove);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
private: System::Void btnNumberClick(System::Object^ sender, System::EventArgs^ e) 
{
	Button^ button = safe_cast<Button^>(sender);
	
	if (button->Text == "��������������")
	{
		try {
			// �������������� � string �� String^
			std::string login = String_to_string(TextLogin->Text);
			std::string password = String_to_string(TextPassword->Text);
			
			// ����������� � ��
			MySqlCon DB;
			DB.connection_to_database();

			// �������� �� �����-������
			if (DB.check_user_data(login, password)) {
				std::cout << "Login successful!" << std::endl;
				MyForm^ main_form = gcnew MyForm();
				main_form->Show();
				this->Hide();
			}
			else {	
				std::cout << "Invalid username or password." << std::endl;
				MessageBox::Show("�������� ����� ��� ������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		catch (sql::SQLException& e) {
			std::cout << "SQL error: " << e.what() << std::endl;
			MessageBox::Show("���������� �� �����������. ��������� ��������� ���������.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
		} 
	}
	else if (button->Text == "������� �������" ||
			 button->Text == "������ ������")
	{
		std::cout << "������ ������, ������� �� ������������." << std::endl;
		MessageBox::Show("���������� �� �����: den.darknezz@gmail.com", "OK", MessageBoxButtons::OK, MessageBoxIcon::Information);
	} else MessageBox::Show("����������� ������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
}
private: System::Void BtnClose(System::Object^ sender, System::EventArgs^ e) 
{
	this->Close();
}
private: System::Void TextLogin_Enter(System::Object^ sender, System::EventArgs^ e) 
{
	if (TextLogin->Text == "������� �����")
	{
		this->TextLogin->Text = "";
		TextLogin->ForeColor = Color::Black;
	}
}
private: System::Void TextLogin_Leave(System::Object^ sender, System::EventArgs^ e) 
{
	if (TextLogin->Text == "")
	{
		this->TextLogin->Text = "������� �����";
		TextLogin->ForeColor = Color::WhiteSmoke;
	}
}
private: System::Void TextPassword_Enter(System::Object^ sender, System::EventArgs^ e)
{
	if (TextPassword->Text == "������� ������")
	{
		this->TextPassword->Text = "";
		TextPassword->ForeColor = Color::Black;
	}
}
private: System::Void TextPassword_Leave(System::Object^ sender, System::EventArgs^ e)
{
	if (TextPassword->Text == "")
	{
		this->TextPassword->Text = "������� ������";
		TextPassword->ForeColor = Color::WhiteSmoke;
	}
}
private: System::Drawing::Point lastPoint;
private: System::Void Autorisation_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	if (e->Button == System::Windows::Forms::MouseButtons::Left)
	{
		lastPoint = e->Location;
	}
}
private: System::Void Autorisation_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
{
	if (e->Button == System::Windows::Forms::MouseButtons::Left)
	{
		this->Left += e->X - lastPoint.X;
		this->Top += e->Y - lastPoint.Y;
	}
}
};
}
