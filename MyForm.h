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
		MySqlCon DB;
		String^ selectedHouse;
		Image^ greenlamp;
		Image^ freelamp;
		bool pusk, avto, ruch;
	private: System::Windows::Forms::Label^ tempLabel1;
	private: System::Windows::Forms::Label^ tempLabel2;
	private: System::Windows::Forms::Label^ tempLabel3;
	public:
		MyForm(void)
		{
			InitializeComponent();
			pusk = 0; avto = 1; ruch = 0;
			DB.connection_to_database();
			std::vector<std::string> arr = DB.ConnectComboBox();
			for (auto& house : arr)
			{
				comboBoxUsers->Items->Add(gcnew String(house.c_str()));
			}
			comboBoxUsers->SelectedItem = gcnew String(arr[0].c_str());


				
			l1->FlatAppearance->BorderSize = 0;
			l2->FlatAppearance->BorderSize = 0;
			l3->FlatAppearance->BorderSize = 0;

			this->freelamp = l1->BackgroundImage;
			this->greenlamp = l3->BackgroundImage;
		
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


	private: System::Windows::Forms::PictureBox^ Settings;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ labelLamp1;
	private: System::Windows::Forms::Label^ labelLamp2;
	private: System::Windows::Forms::Label^ labelLamp3;
	private: System::Windows::Forms::Button^ l1;
	private: System::Windows::Forms::Button^ l2;
	private: System::Windows::Forms::Button^ l3;

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
			this->comboBoxUsers = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->l1 = (gcnew System::Windows::Forms::Button());
			this->l2 = (gcnew System::Windows::Forms::Button());
			this->l3 = (gcnew System::Windows::Forms::Button());
			this->labelLamp1 = (gcnew System::Windows::Forms::Label());
			this->labelLamp2 = (gcnew System::Windows::Forms::Label());
			this->labelLamp3 = (gcnew System::Windows::Forms::Label());
			this->tempLabel1 = (gcnew System::Windows::Forms::Label());
			this->tempLabel2 = (gcnew System::Windows::Forms::Label());
			this->tempLabel3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button1->Location = System::Drawing::Point(495, 234);
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
			this->TextYopta->Anchor = System::Windows::Forms::AnchorStyles::Top;
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
			this->close->Location = System::Drawing::Point(1097, 584);
			this->close->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->close->Name = L"close";
			this->close->Size = System::Drawing::Size(28, 28);
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
			this->button2->Location = System::Drawing::Point(508, 367);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(174, 101);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Принять json";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::btnNumber_Click);
			// 
			// comboBoxUsers
			// 
			this->comboBoxUsers->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxUsers->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->comboBoxUsers->FormattingEnabled = true;
			this->comboBoxUsers->Location = System::Drawing::Point(-2, -2);
			this->comboBoxUsers->Name = L"comboBoxUsers";
			this->comboBoxUsers->Size = System::Drawing::Size(236, 21);
			this->comboBoxUsers->TabIndex = 6;
			this->comboBoxUsers->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBoxUsers_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(384, 203);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(562, 203);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(785, 203);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"label3";
			// 
			// l1
			// 
			this->l1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"l1.BackgroundImage")));
			this->l1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->l1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->l1->Location = System::Drawing::Point(21, 30);
			this->l1->Name = L"l1";
			this->l1->Size = System::Drawing::Size(62, 48);
			this->l1->TabIndex = 10;
			this->l1->UseVisualStyleBackColor = true;
			this->l1->Click += gcnew System::EventHandler(this, &MyForm::l1_click);
			// 
			// l2
			// 
			this->l2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"l2.BackgroundImage")));
			this->l2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->l2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->l2->Location = System::Drawing::Point(21, 84);
			this->l2->Name = L"l2";
			this->l2->Size = System::Drawing::Size(62, 48);
			this->l2->TabIndex = 11;
			this->l2->UseVisualStyleBackColor = true;
			this->l2->Click += gcnew System::EventHandler(this, &MyForm::l2_click);
			// 
			// l3
			// 
			this->l3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"l3.BackgroundImage")));
			this->l3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->l3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->l3->Location = System::Drawing::Point(21, 138);
			this->l3->Name = L"l3";
			this->l3->Size = System::Drawing::Size(62, 48);
			this->l3->TabIndex = 12;
			this->l3->UseVisualStyleBackColor = true;
			this->l3->Click += gcnew System::EventHandler(this, &MyForm::l3_click);
			// 
			// labelLamp1
			// 
			this->labelLamp1->AutoSize = true;
			this->labelLamp1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelLamp1->ForeColor = System::Drawing::Color::White;
			this->labelLamp1->Location = System::Drawing::Point(89, 39);
			this->labelLamp1->Name = L"labelLamp1";
			this->labelLamp1->Size = System::Drawing::Size(99, 25);
			this->labelLamp1->TabIndex = 13;
			this->labelLamp1->Text = L"РУЧНОЙ";
			// 
			// labelLamp2
			// 
			this->labelLamp2->AutoSize = true;
			this->labelLamp2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelLamp2->ForeColor = System::Drawing::Color::White;
			this->labelLamp2->Location = System::Drawing::Point(89, 93);
			this->labelLamp2->Name = L"labelLamp2";
			this->labelLamp2->Size = System::Drawing::Size(69, 25);
			this->labelLamp2->TabIndex = 14;
			this->labelLamp2->Text = L"АВТО";
			// 
			// labelLamp3
			// 
			this->labelLamp3->AutoSize = true;
			this->labelLamp3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelLamp3->ForeColor = System::Drawing::Color::White;
			this->labelLamp3->Location = System::Drawing::Point(89, 147);
			this->labelLamp3->Name = L"labelLamp3";
			this->labelLamp3->Size = System::Drawing::Size(71, 25);
			this->labelLamp3->TabIndex = 15;
			this->labelLamp3->Text = L"СТОП";
			// 
			// tempLabel1
			// 
			this->tempLabel1->AutoSize = true;
			this->tempLabel1->Location = System::Drawing::Point(1047, 18);
			this->tempLabel1->Name = L"tempLabel1";
			this->tempLabel1->Size = System::Drawing::Size(35, 13);
			this->tempLabel1->TabIndex = 16;
			this->tempLabel1->Text = L"label4";
			// 
			// tempLabel2
			// 
			this->tempLabel2->AutoSize = true;
			this->tempLabel2->Location = System::Drawing::Point(1047, 48);
			this->tempLabel2->Name = L"tempLabel2";
			this->tempLabel2->Size = System::Drawing::Size(35, 13);
			this->tempLabel2->TabIndex = 17;
			this->tempLabel2->Text = L"label4";
			// 
			// tempLabel3
			// 
			this->tempLabel3->AutoSize = true;
			this->tempLabel3->Location = System::Drawing::Point(1047, 74);
			this->tempLabel3->Name = L"tempLabel3";
			this->tempLabel3->Size = System::Drawing::Size(35, 13);
			this->tempLabel3->TabIndex = 18;
			this->tempLabel3->Text = L"label4";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(71)), static_cast<System::Int32>(static_cast<System::Byte>(129)),
				static_cast<System::Int32>(static_cast<System::Byte>(177)));
			this->ClientSize = System::Drawing::Size(1137, 637);
			this->Controls->Add(this->tempLabel3);
			this->Controls->Add(this->tempLabel2);
			this->Controls->Add(this->tempLabel1);
			this->Controls->Add(this->labelLamp3);
			this->Controls->Add(this->labelLamp2);
			this->Controls->Add(this->labelLamp1);
			this->Controls->Add(this->l3);
			this->Controls->Add(this->l2);
			this->Controls->Add(this->l1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBoxUsers);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->close);
			this->Controls->Add(this->TextYopta);
			this->Controls->Add(this->button1);
			this->ForeColor = System::Drawing::Color::Black;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"WinProject";
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
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
		Parser::ParsingUserTemperature();
		this->label2->Text = gcnew String(Parser::TEMPERATURE_USER.c_str());
		this->TextYopta->Text = gcnew String(Parser::TEMPERATURE_PARSER.c_str());

		Parser::ParsingRoomTemperature();

		this->tempLabel1->Text = gcnew String(Parser::TEMPERATURE_ROOM.c_str());
		this->tempLabel2->Text = gcnew String(Parser::TEMPERATURE_PARSER.c_str());
		this->tempLabel3->Text = gcnew String(Parser::TEMPERATURE_USER.c_str());

		json data = { {"tempStreet", Parser::TEMPERATURE_PARSER}, {"tempReq", Parser::TEMPERATURE_USER}, {"avto", int(avto)}, {"ruch", int(ruch)}, {"pusk", int(pusk)} };
		Parser::post_data_to_site(Parser::files::postPS, data);

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

	DB.connection_to_database();
	Parser::Pochta = DB.GetMailUser(String_to_string(selectedHouse));

	Parser::ParsingUserTemperature();

	Parser::files::getPS = Parser::Pochta + ".json";

	Parser::Parsing();
	Parser::ParsingRoomTemperature();

	this->tempLabel1->Text = gcnew String(Parser::TEMPERATURE_ROOM.c_str());
	this->tempLabel2->Text = gcnew String(Parser::TEMPERATURE_PARSER.c_str());
	this->tempLabel3->Text = gcnew String(Parser::TEMPERATURE_USER.c_str());

	this->label1->Text = gcnew String(Parser::Pochta.c_str());
	this->label2->Text = gcnew String(Parser::TEMPERATURE_USER.c_str());
	this->label3->Text = gcnew String(Parser::files::getPS.c_str());
}


private: System::Void l2_click(System::Object^ sender, System::EventArgs^ e)
{
	if (l2->BackgroundImage != greenlamp)
	{
		l2->BackgroundImage = greenlamp;
		l1->BackgroundImage = freelamp;
		l3->BackgroundImage = freelamp;
		pusk = 1; avto = 1; ruch = 0;
	}

}
private: System::Void l1_click(System::Object^ sender, System::EventArgs^ e) 
{
	if (l1->BackgroundImage != greenlamp)
	{
		l1->BackgroundImage = greenlamp;
		l2->BackgroundImage = freelamp;
		l3->BackgroundImage = freelamp;
		pusk = 1; avto = 0; ruch = 1;
	}
}
private: System::Void l3_click(System::Object^ sender, System::EventArgs^ e) 
{
	if (l3->BackgroundImage != greenlamp)
	{
		l3->BackgroundImage = greenlamp;
		l1->BackgroundImage = freelamp;
		l2->BackgroundImage = freelamp;
		pusk = 0; avto = 0; ruch = 0;
	}
}
};
}
