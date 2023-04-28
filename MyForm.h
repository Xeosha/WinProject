#pragma once
#include <string>
#include <vector>
#include "ParseSite.h"
#include "MySqlCon.h"
#include <msclr/marshal.h>


std::string String_to_string(System::String^ str)
{
	System::IntPtr ptr = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str);
	std::string res_str = static_cast<char*>(ptr.ToPointer());
	System::Runtime::InteropServices::Marshal::FreeHGlobal(ptr);
	return res_str;
}


namespace WinProject {
	using namespace nlohmann;	// для json
	using namespace System;	
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private: 
		String^ selectedHouse;
	
	public:
		MyForm(void)
		{
			InitializeComponent();

			MySqlCon DB;
			DB.connection_to_database();
			std::vector<std::string> arr = DB.ConnectComboBox();
			for (auto& house : arr)
			{
				comboBoxUsers->Items->Add(gcnew String(house.c_str()));
			}
			comboBoxUsers->SelectedItem = gcnew String(arr[0].c_str());

			timer1->Enabled = true;

		}


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ TextYopta;
	private: System::Windows::Forms::Button^ close;


	private: System::Windows::Forms::Timer^ timer1;



	private: System::Windows::Forms::Button^ button2;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ Settings;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ comboBoxUsers;


	private: System::ComponentModel::IContainer^ components;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->TextYopta = (gcnew System::Windows::Forms::TextBox());
			this->close = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->Settings = (gcnew System::Windows::Forms::PictureBox());
			this->comboBoxUsers = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Settings))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(495, 188);
			this->button1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(174, 92);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Отправить json";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::btnNumber_Click);
			// 
			// TextYopta
			// 
			this->TextYopta->Location = System::Drawing::Point(495, 144);
			this->TextYopta->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->TextYopta->Name = L"TextYopta";
			this->TextYopta->Size = System::Drawing::Size(174, 20);
			this->TextYopta->TabIndex = 1;
			// 
			// close
			// 
			this->close->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(7)),
				static_cast<System::Int32>(static_cast<System::Byte>(7)));
			this->close->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->close->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->close->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->close->Font = (gcnew System::Drawing::Font(L"Marlett", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->close->ForeColor = System::Drawing::Color::White;
			this->close->Location = System::Drawing::Point(12, 13);
			this->close->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->close->Name = L"close";
			this->close->Size = System::Drawing::Size(29, 28);
			this->close->TabIndex = 2;
			this->close->Text = L"x";
			this->close->UseVisualStyleBackColor = false;
			this->close->Click += gcnew System::EventHandler(this, &MyForm::btn_Close);
			// 
			// timer1
			// 
			this->timer1->Interval = 10000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(495, 299);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(174, 101);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Принять json";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::btnNumber_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(441, 122);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(48, 42);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// Settings
			// 
			this->Settings->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Settings.Image")));
			this->Settings->Location = System::Drawing::Point(47, 12);
			this->Settings->Name = L"Settings";
			this->Settings->Size = System::Drawing::Size(35, 29);
			this->Settings->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->Settings->TabIndex = 5;
			this->Settings->TabStop = false;
			// 
			// comboBoxUsers
			// 
			this->comboBoxUsers->FormattingEnabled = true;
			this->comboBoxUsers->Location = System::Drawing::Point(0, 0);
			this->comboBoxUsers->Name = L"comboBoxUsers";
			this->comboBoxUsers->Size = System::Drawing::Size(190, 21);
			this->comboBoxUsers->TabIndex = 6;
			this->comboBoxUsers->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBoxUsers_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(297, 102);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(561, 72);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(827, 102);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"label3";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(99)));
			this->ClientSize = System::Drawing::Size(1137, 637);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBoxUsers);
			this->Controls->Add(this->Settings);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->close);
			this->Controls->Add(this->TextYopta);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->ForeColor = System::Drawing::Color::Black;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"WinProject";
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Settings))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {}
	
	private: System::Void btnNumber_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		Button^ button = safe_cast<Button^>(sender);

		if (button->Text == "Отправить json")
		{
			json data = { {"led", ( rand() % 2 ) }};
			if (Parser::post_data_to_site(Parser::files::postPS, data))
			{
				this->TextYopta->Text = gcnew String("Успешно отправилось");
			}
		}
		else if (button->Text == "Принять json")
		{
			char result = 'n';
			json datajs;
			std::string data;
			int count = 0;
			while (true)
			{
				data = Parser::get_data_from_site(Parser::SERVER_URL + Parser::files::getPS);
				datajs = json::parse(data);
				result = data[11];
				if (result == 'n')
				{
					Sleep(500);
					count++;
					if (count == 10) { return; }
				}
				else break;
			}
			this->TextYopta->Text = gcnew String("Успешно считалось");
		}
	}

	private: System::Void btn_Close(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Close();
		Application::Exit();
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
	{
	
		Parser::Parsing();
		Parser::ParsingUserTemperature(Parser::Pochta);
		this->label2->Text = gcnew String(Parser::TEMPERATURE_USER.c_str());
		this->TextYopta->Text = gcnew String(Parser::TEMPERATURE_PARSER.c_str());

	}
	private: System::Drawing::Point lastPoint;	
	private: System::Void MyForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
	{
		if (e->Button == System::Windows::Forms::MouseButtons::Left)
		{
			lastPoint = e->Location;
		}
	}
	private: System::Void MyForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
	{
		if (e->Button == System::Windows::Forms::MouseButtons::Left)
		{
			this->Left += e->X - lastPoint.X;
			this->Top += e->Y - lastPoint.Y;
		}
	}
private: System::Void comboBoxUsers_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	selectedHouse = comboBoxUsers->SelectedItem->ToString();

	
	MySqlCon DB2;
	DB2.connection_to_database();
	Parser::Pochta = DB2.GetMailUser(String_to_string(selectedHouse));

	Parser::ParsingUserTemperature(Parser::Pochta);


	Parser::files::getPS = Parser::Pochta + ".json";

	this->label1->Text = gcnew String(Parser::Pochta.c_str());
	this->label2->Text = gcnew String(Parser::TEMPERATURE_USER.c_str());
	this->label3->Text = gcnew String(Parser::files::getPS.c_str());
	
	
}

};
}
