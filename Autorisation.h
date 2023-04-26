#pragma once

#include <iostream>
#include "MyForm.h"
#include <msclr/marshal.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>



namespace WinProject {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Сводка для Autorisation
	/// </summary>
	public ref class Autorisation : public System::Windows::Forms::Form
	{
	public:
		Autorisation(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			this->TextLogin->Text = "ВВЕДИТЕ ЛОГИН";
			TextLogin->ForeColor = Color::WhiteSmoke;
			this->TextPassword->Text = "ВВЕДИТЕ ПАРОЛЬ";
			TextPassword->ForeColor = Color::WhiteSmoke;
			// запретить расширение в зависимости от экрана
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			// убрать все плашки
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			// запретить расширение кнопок
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;

			
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Autorisation()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^ TextLogin;
	private: System::Windows::Forms::TextBox^ TextPassword;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnClose;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Autorisation::typeid));
			this->TextLogin = (gcnew System::Windows::Forms::TextBox());
			this->TextPassword = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// TextLogin
			// 
			this->TextLogin->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(71)), static_cast<System::Int32>(static_cast<System::Byte>(129)),
				static_cast<System::Int32>(static_cast<System::Byte>(177)));
			this->TextLogin->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(204), true));
			this->TextLogin->ForeColor = System::Drawing::Color::White;
			this->TextLogin->Location = System::Drawing::Point(837, 200);
			this->TextLogin->Multiline = true;
			this->TextLogin->Name = L"TextLogin";
			this->TextLogin->Size = System::Drawing::Size(243, 33);
			this->TextLogin->TabIndex = 1;
			this->TextLogin->Text = L"ВВЕДИТЕ ЛОГИН";
			this->TextLogin->Enter += gcnew System::EventHandler(this, &Autorisation::TextLogin_Enter);
			this->TextLogin->Leave += gcnew System::EventHandler(this, &Autorisation::TextLogin_Leave);
			// 
			// TextPassword
			// 
			this->TextPassword->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(71)), static_cast<System::Int32>(static_cast<System::Byte>(129)),
				static_cast<System::Int32>(static_cast<System::Byte>(177)));
			this->TextPassword->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(204), true));
			this->TextPassword->ForeColor = System::Drawing::Color::White;
			this->TextPassword->Location = System::Drawing::Point(837, 239);
			this->TextPassword->Multiline = true;
			this->TextPassword->Name = L"TextPassword";
			this->TextPassword->Size = System::Drawing::Size(243, 32);
			this->TextPassword->TabIndex = 2;
			this->TextPassword->Text = L"ВВЕДИТЕ ПАРОЛЬ";
			this->TextPassword->Enter += gcnew System::EventHandler(this, &Autorisation::TextPassword_Enter);
			this->TextPassword->Leave += gcnew System::EventHandler(this, &Autorisation::TextPassword_Leave);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(71)), static_cast<System::Int32>(static_cast<System::Byte>(129)),
				static_cast<System::Int32>(static_cast<System::Byte>(177)));
			this->button1->Location = System::Drawing::Point(866, 317);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(195, 75);
			this->button1->TabIndex = 3;
			this->button1->Text = L"АВТОРИЗОВАТЬСЯ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Autorisation::btnNumberClick);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::WhiteSmoke;
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(71)), static_cast<System::Int32>(static_cast<System::Byte>(129)),
				static_cast<System::Int32>(static_cast<System::Byte>(177)));
			this->button2->Location = System::Drawing::Point(884, 398);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(156, 20);
			this->button2->TabIndex = 5;
			this->button2->Text = L"ЗАБЫЛИ ПАРОЛЬ";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Autorisation::btnNumberClick);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::WhiteSmoke;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(71)), static_cast<System::Int32>(static_cast<System::Byte>(129)),
				static_cast<System::Int32>(static_cast<System::Byte>(177)));
			this->button3->Location = System::Drawing::Point(929, 277);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(151, 22);
			this->button3->TabIndex = 6;
			this->button3->Text = L"СОЗДАТЬ АККАУНТ";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Autorisation::btnNumberClick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(71)), static_cast<System::Int32>(static_cast<System::Byte>(129)),
				static_cast<System::Int32>(static_cast<System::Byte>(177)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(910, 160);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(88, 26);
			this->label1->TabIndex = 7;
			this->label1->Text = L"ВОЙТИ";
			// 
			// btnClose
			// 
			this->btnClose->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(71)), static_cast<System::Int32>(static_cast<System::Byte>(129)),
				static_cast<System::Int32>(static_cast<System::Byte>(177)));
			this->btnClose->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnClose.BackgroundImage")));
			this->btnClose->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClose->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(98)), static_cast<System::Int32>(static_cast<System::Byte>(163)),
				static_cast<System::Int32>(static_cast<System::Byte>(247)));
			this->btnClose->Location = System::Drawing::Point(1135, 12);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(44, 43);
			this->btnClose->TabIndex = 8;
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &Autorisation::BtnClose);
			// 
			// Autorisation
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1191, 583);
			this->ControlBox = false;
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->TextPassword);
			this->Controls->Add(this->TextLogin);
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
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
private: System::Void btnNumberClick(System::Object^ sender, System::EventArgs^ e) 
{
	Button^ button = safe_cast<Button^>(sender);
	
	if (button->Text == "АВТОРИЗОВАТЬСЯ")
	{
		// Подключение к базе данных
		try {
			// Преобразование в string из String^
			IntPtr ptr = Marshal::StringToHGlobalAnsi(TextLogin->Text);
			std::string login = static_cast<char*>(ptr.ToPointer());
			Marshal::FreeHGlobal(ptr);
			IntPtr ptr2 = Marshal::StringToHGlobalAnsi(TextPassword->Text);
			std::string password = static_cast<char*>(ptr2.ToPointer());
			Marshal::FreeHGlobal(ptr2);

			sql::Driver* driver;
			sql::Connection* con;
			sql::PreparedStatement* stmt;
			sql::ResultSet* res;

			// Create a connection to the MySQL database
			driver = get_driver_instance();
			con = driver->connect("x958887o.beget.tech:3306", "x958887o_login", "bGYD7d2h");
			con->setSchema("x958887o_login");

			// Select the user with the given username and password
			stmt = con->prepareStatement("SELECT * FROM passwords WHERE login=? AND password=?");
			stmt->setString(1, login);
			stmt->setString(2, password);
			res = stmt->executeQuery();

			// Check if the user was found
			if (res->next()) {
				std::cout << "Login successful!" << std::endl;
				MyForm^ main_form = gcnew MyForm();
				main_form->Show();
				this->Hide();
			}
			else {	
				std::cout << "Invalid username or password." << std::endl;
				MessageBox::Show("Неверный логин или пароль", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}

			delete res;
			delete stmt;
			delete con;
		}
		catch (sql::SQLException& e) {
			std::cout << "SQL error: " << e.what() << std::endl;
		}
	}
}
private: System::Void BtnClose(System::Object^ sender, System::EventArgs^ e) 
{
	this->Close();
}
private: System::Void TextLogin_Enter(System::Object^ sender, System::EventArgs^ e) 
{
	if (TextLogin->Text == "ВВЕДИТЕ ЛОГИН")
	{
		this->TextLogin->Text = "";
		TextLogin->ForeColor = Color::Black;
	}
}
private: System::Void TextLogin_Leave(System::Object^ sender, System::EventArgs^ e) 
{
	if (TextLogin->Text == "")
	{
		this->TextLogin->Text = "ВВЕДИТЕ ЛОГИН";
		TextLogin->ForeColor = Color::WhiteSmoke;
	}
}
private: System::Void TextPassword_Enter(System::Object^ sender, System::EventArgs^ e)
{
	if (TextPassword->Text == "ВВЕДИТЕ ПАРОЛЬ")
	{
		this->TextPassword->Text = "";
		TextPassword->ForeColor = Color::Black;
	}
}
private: System::Void TextPassword_Leave(System::Object^ sender, System::EventArgs^ e)
{
	if (TextPassword->Text == "")
	{
		this->TextPassword->Text = "ВВЕДИТЕ ПАРОЛЬ";
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
