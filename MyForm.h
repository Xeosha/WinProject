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
	private: System::Windows::Forms::Label^ labelTextTemp1;
	private: System::Windows::Forms::PictureBox^ dom123;
	private: System::Windows::Forms::Button^ close;

	private: System::Windows::Forms::Label^ labelTextTemp2;
	private: System::Windows::Forms::Label^ labelTextTemp3;


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
			
			dom123->BackColor = Color::Transparent;

			
			
			
			
	

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

			}
		}





	private: System::Windows::Forms::Timer^ timer1;









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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->comboBoxUsers = (gcnew System::Windows::Forms::ComboBox());
			this->l1 = (gcnew System::Windows::Forms::Button());
			this->l2 = (gcnew System::Windows::Forms::Button());
			this->l3 = (gcnew System::Windows::Forms::Button());
			this->labelLamp1 = (gcnew System::Windows::Forms::Label());
			this->labelLamp2 = (gcnew System::Windows::Forms::Label());
			this->labelLamp3 = (gcnew System::Windows::Forms::Label());
			this->tempLabel1 = (gcnew System::Windows::Forms::Label());
			this->tempLabel2 = (gcnew System::Windows::Forms::Label());
			this->tempLabel3 = (gcnew System::Windows::Forms::Label());
			this->labelTextTemp1 = (gcnew System::Windows::Forms::Label());
			this->labelTextTemp2 = (gcnew System::Windows::Forms::Label());
			this->labelTextTemp3 = (gcnew System::Windows::Forms::Label());
			this->close = (gcnew System::Windows::Forms::Button());
			this->dom123 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dom123))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 10000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
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
			// l1
			// 
			this->l1->BackColor = System::Drawing::Color::Transparent;
			this->l1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"l1.BackgroundImage")));
			this->l1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->l1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->l1->Location = System::Drawing::Point(21, 30);
			this->l1->Name = L"l1";
			this->l1->Size = System::Drawing::Size(62, 48);
			this->l1->TabIndex = 10;
			this->l1->UseVisualStyleBackColor = false;
			this->l1->Click += gcnew System::EventHandler(this, &MyForm::l1_click);
			// 
			// l2
			// 
			this->l2->BackColor = System::Drawing::Color::Transparent;
			this->l2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"l2.BackgroundImage")));
			this->l2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->l2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->l2->Location = System::Drawing::Point(21, 84);
			this->l2->Name = L"l2";
			this->l2->Size = System::Drawing::Size(62, 48);
			this->l2->TabIndex = 11;
			this->l2->UseVisualStyleBackColor = false;
			this->l2->Click += gcnew System::EventHandler(this, &MyForm::l2_click);
			// 
			// l3
			// 
			this->l3->BackColor = System::Drawing::Color::Transparent;
			this->l3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"l3.BackgroundImage")));
			this->l3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->l3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->l3->Location = System::Drawing::Point(21, 138);
			this->l3->Name = L"l3";
			this->l3->Size = System::Drawing::Size(62, 48);
			this->l3->TabIndex = 12;
			this->l3->UseVisualStyleBackColor = false;
			this->l3->Click += gcnew System::EventHandler(this, &MyForm::l3_click);
			// 
			// labelLamp1
			// 
			this->labelLamp1->AutoSize = true;
			this->labelLamp1->BackColor = System::Drawing::Color::Transparent;
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
			this->labelLamp2->BackColor = System::Drawing::Color::Transparent;
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
			this->labelLamp3->BackColor = System::Drawing::Color::Transparent;
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
			this->tempLabel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->tempLabel1->AutoSize = true;
			this->tempLabel1->BackColor = System::Drawing::Color::Transparent;
			this->tempLabel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tempLabel1->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->tempLabel1->Location = System::Drawing::Point(1052, 9);
			this->tempLabel1->Name = L"tempLabel1";
			this->tempLabel1->Size = System::Drawing::Size(51, 25);
			this->tempLabel1->TabIndex = 16;
			this->tempLabel1->Text = L"+16";
			this->tempLabel1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tempLabel2
			// 
			this->tempLabel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->tempLabel2->AutoSize = true;
			this->tempLabel2->BackColor = System::Drawing::Color::Transparent;
			this->tempLabel2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tempLabel2->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->tempLabel2->Location = System::Drawing::Point(1052, 53);
			this->tempLabel2->Name = L"tempLabel2";
			this->tempLabel2->Size = System::Drawing::Size(51, 25);
			this->tempLabel2->TabIndex = 17;
			this->tempLabel2->Text = L"+20";
			this->tempLabel2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tempLabel3
			// 
			this->tempLabel3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->tempLabel3->AutoSize = true;
			this->tempLabel3->BackColor = System::Drawing::Color::Transparent;
			this->tempLabel3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tempLabel3->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->tempLabel3->Location = System::Drawing::Point(1054, 93);
			this->tempLabel3->Name = L"tempLabel3";
			this->tempLabel3->Size = System::Drawing::Size(46, 25);
			this->tempLabel3->TabIndex = 18;
			this->tempLabel3->Text = L"-10";
			this->tempLabel3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelTextTemp1
			// 
			this->labelTextTemp1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->labelTextTemp1->AutoSize = true;
			this->labelTextTemp1->BackColor = System::Drawing::Color::Transparent;
			this->labelTextTemp1->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->labelTextTemp1->Location = System::Drawing::Point(1054, 34);
			this->labelTextTemp1->Name = L"labelTextTemp1";
			this->labelTextTemp1->Size = System::Drawing::Size(52, 13);
			this->labelTextTemp1->TabIndex = 19;
			this->labelTextTemp1->Text = L"T в доме";
			// 
			// labelTextTemp2
			// 
			this->labelTextTemp2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->labelTextTemp2->AutoSize = true;
			this->labelTextTemp2->BackColor = System::Drawing::Color::Transparent;
			this->labelTextTemp2->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->labelTextTemp2->Location = System::Drawing::Point(1033, 119);
			this->labelTextTemp2->Name = L"labelTextTemp2";
			this->labelTextTemp2->Size = System::Drawing::Size(99, 13);
			this->labelTextTemp2->TabIndex = 20;
			this->labelTextTemp2->Text = L"T запрашиваемая";
			// 
			// labelTextTemp3
			// 
			this->labelTextTemp3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->labelTextTemp3->AutoSize = true;
			this->labelTextTemp3->BackColor = System::Drawing::Color::Transparent;
			this->labelTextTemp3->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->labelTextTemp3->Location = System::Drawing::Point(1054, 80);
			this->labelTextTemp3->Name = L"labelTextTemp3";
			this->labelTextTemp3->Size = System::Drawing::Size(61, 13);
			this->labelTextTemp3->TabIndex = 21;
			this->labelTextTemp3->Text = L"T на улице";
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
			// dom123
			// 
			this->dom123->BackColor = System::Drawing::Color::Transparent;
			this->dom123->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"dom123.BackgroundImage")));
			this->dom123->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->dom123->Location = System::Drawing::Point(485, 290);
			this->dom123->Name = L"dom123";
			this->dom123->Size = System::Drawing::Size(189, 112);
			this->dom123->TabIndex = 22;
			this->dom123->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(71)), static_cast<System::Int32>(static_cast<System::Byte>(129)),
				static_cast<System::Int32>(static_cast<System::Byte>(177)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1132, 637);
			this->Controls->Add(this->dom123);
			this->Controls->Add(this->labelTextTemp3);
			this->Controls->Add(this->labelTextTemp2);
			this->Controls->Add(this->labelTextTemp1);
			this->Controls->Add(this->tempLabel3);
			this->Controls->Add(this->tempLabel2);
			this->Controls->Add(this->tempLabel1);
			this->Controls->Add(this->labelLamp3);
			this->Controls->Add(this->labelLamp2);
			this->Controls->Add(this->labelLamp1);
			this->Controls->Add(this->l3);
			this->Controls->Add(this->l2);
			this->Controls->Add(this->l1);
			this->Controls->Add(this->comboBoxUsers);
			this->Controls->Add(this->close);
			this->DoubleBuffered = true;
			this->ForeColor = System::Drawing::Color::Black;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Location = System::Drawing::Point(777, 156);
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"WinProject";
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dom123))->EndInit();
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
				/*this->TextYopta->Text = gcnew String("Успешно отправилось");*/
			}
		}
		else if (button->Text == "Принять json")
		{
	/*		this->TextYopta->Text = gcnew String("Успешно считалось");*/
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
