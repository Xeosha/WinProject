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
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::PictureBox^ pictureBox10;
	private: System::Windows::Forms::PictureBox^ pictureBox11;
	private: System::Windows::Forms::PictureBox^ pictureBox12;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::PictureBox^ pictureBox13;
	private: System::Windows::Forms::PictureBox^ pictureBox14;
	private: System::Windows::Forms::Label^ label6;

	private: System::Windows::Forms::Button^ btnErrors;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::Button^ btnSettings;
	private: System::Windows::Forms::PictureBox^ pictureBox6;
	private: System::Windows::Forms::PictureBox^ pictureBox7;
	private: System::Windows::Forms::PictureBox^ pictureBox8;
	private: System::Windows::Forms::PictureBox^ pictureBox9;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::Button^ btnTrands;


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
			pusk = 0; avto = 1; ruch = 0;
			InitializeComponent();
			DB.connection_to_database();
			std::vector<std::string> arr = DB.ConnectComboBox();
			for (auto& house : arr)
			{
				comboBoxUsers->Items->Add(gcnew String(house.c_str()));
			}
			comboBoxUsers->SelectedItem = gcnew String(arr[0].c_str());



			l1->FlatAppearance->BorderSize = 0; btnTrands->FlatAppearance->BorderSize = 0;
			l2->FlatAppearance->BorderSize = 0; btnSettings->FlatAppearance->BorderSize = 0;
			l3->FlatAppearance->BorderSize = 0; btnErrors->FlatAppearance->BorderSize = 0;

			this->freelamp = l1->BackgroundImage;
			this->greenlamp = l2->BackgroundImage;
			button1->Visible = false;
			timer1->Enabled = true;
		}


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->btnTrands = (gcnew System::Windows::Forms::Button());
			this->btnErrors = (gcnew System::Windows::Forms::Button());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->btnSettings = (gcnew System::Windows::Forms::Button());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox11 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox12 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->pictureBox13 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox14 = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dom123))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox14))->BeginInit();
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
			this->close->BackColor = System::Drawing::Color::Transparent;
			this->close->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"close.BackgroundImage")));
			this->close->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->close->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->close->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->close->Font = (gcnew System::Drawing::Font(L"Marlett", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->close->ForeColor = System::Drawing::Color::Black;
			this->close->Location = System::Drawing::Point(1085, 571);
			this->close->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->close->Name = L"close";
			this->close->Size = System::Drawing::Size(35, 41);
			this->close->TabIndex = 2;
			this->close->UseVisualStyleBackColor = false;
			this->close->Visible = false;
			this->close->Click += gcnew System::EventHandler(this, &MyForm::btn_Close);
			// 
			// dom123
			// 
			this->dom123->BackColor = System::Drawing::Color::Transparent;
			this->dom123->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"dom123.BackgroundImage")));
			this->dom123->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->dom123->Location = System::Drawing::Point(764, 180);
			this->dom123->Name = L"dom123";
			this->dom123->Size = System::Drawing::Size(189, 112);
			this->dom123->TabIndex = 22;
			this->dom123->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox1->Location = System::Drawing::Point(494, 375);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(162, 137);
			this->pictureBox1->TabIndex = 23;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(846, 278);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(14, 150);
			this->pictureBox2->TabIndex = 24;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.BackgroundImage")));
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox3->Location = System::Drawing::Point(792, 424);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(68, 33);
			this->pictureBox3->TabIndex = 25;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.BackgroundImage")));
			this->pictureBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox4->Location = System::Drawing::Point(617, 441);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(179, 16);
			this->pictureBox4->TabIndex = 26;
			this->pictureBox4->TabStop = false;
			// 
			// btnTrands
			// 
			this->btnTrands->BackColor = System::Drawing::Color::Transparent;
			this->btnTrands->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnTrands.BackgroundImage")));
			this->btnTrands->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnTrands->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnTrands->Location = System::Drawing::Point(653, 1);
			this->btnTrands->Name = L"btnTrands";
			this->btnTrands->Size = System::Drawing::Size(133, 69);
			this->btnTrands->TabIndex = 27;
			this->btnTrands->UseVisualStyleBackColor = false;
			// 
			// btnErrors
			// 
			this->btnErrors->BackColor = System::Drawing::Color::Transparent;
			this->btnErrors->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnErrors.BackgroundImage")));
			this->btnErrors->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnErrors->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnErrors->Location = System::Drawing::Point(889, -1);
			this->btnErrors->Name = L"btnErrors";
			this->btnErrors->Size = System::Drawing::Size(133, 71);
			this->btnErrors->TabIndex = 28;
			this->btnErrors->UseVisualStyleBackColor = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.BackgroundImage")));
			this->pictureBox5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox5->Location = System::Drawing::Point(138, 190);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(186, 138);
			this->pictureBox5->TabIndex = 29;
			this->pictureBox5->TabStop = false;
			// 
			// btnSettings
			// 
			this->btnSettings->BackColor = System::Drawing::Color::Transparent;
			this->btnSettings->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSettings.BackgroundImage")));
			this->btnSettings->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnSettings->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSettings->Location = System::Drawing::Point(782, 0);
			this->btnSettings->Name = L"btnSettings";
			this->btnSettings->Size = System::Drawing::Size(110, 70);
			this->btnSettings->TabIndex = 30;
			this->btnSettings->UseVisualStyleBackColor = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.BackgroundImage")));
			this->pictureBox6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox6->Location = System::Drawing::Point(295, 411);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(91, 48);
			this->pictureBox6->TabIndex = 31;
			this->pictureBox6->TabStop = false;
			// 
			// pictureBox7
			// 
			this->pictureBox7->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.BackgroundImage")));
			this->pictureBox7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox7->Location = System::Drawing::Point(218, 414);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(83, 45);
			this->pictureBox7->TabIndex = 32;
			this->pictureBox7->TabStop = false;
			// 
			// pictureBox8
			// 
			this->pictureBox8->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox8.BackgroundImage")));
			this->pictureBox8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox8->Location = System::Drawing::Point(380, 441);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(151, 18);
			this->pictureBox8->TabIndex = 33;
			this->pictureBox8->TabStop = false;
			// 
			// pictureBox9
			// 
			this->pictureBox9->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox9->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox9.BackgroundImage")));
			this->pictureBox9->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox9->Location = System::Drawing::Point(218, 313);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(16, 104);
			this->pictureBox9->TabIndex = 34;
			this->pictureBox9->TabStop = false;
			// 
			// pictureBox10
			// 
			this->pictureBox10->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox10->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox10.BackgroundImage")));
			this->pictureBox10->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox10->Location = System::Drawing::Point(569, 247);
			this->pictureBox10->Name = L"pictureBox10";
			this->pictureBox10->Size = System::Drawing::Size(74, 35);
			this->pictureBox10->TabIndex = 35;
			this->pictureBox10->TabStop = false;
			// 
			// pictureBox11
			// 
			this->pictureBox11->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox11->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox11.BackgroundImage")));
			this->pictureBox11->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox11->Location = System::Drawing::Point(569, 278);
			this->pictureBox11->Name = L"pictureBox11";
			this->pictureBox11->Size = System::Drawing::Size(17, 101);
			this->pictureBox11->TabIndex = 36;
			this->pictureBox11->TabStop = false;
			// 
			// pictureBox12
			// 
			this->pictureBox12->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox12->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox12.BackgroundImage")));
			this->pictureBox12->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox12->Location = System::Drawing::Point(642, 247);
			this->pictureBox12->Name = L"pictureBox12";
			this->pictureBox12->Size = System::Drawing::Size(168, 16);
			this->pictureBox12->TabIndex = 37;
			this->pictureBox12->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Location = System::Drawing::Point(639, 469);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(80, 13);
			this->label1->TabIndex = 38;
			this->label1->Text = L"Темпаратура: ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Location = System::Drawing::Point(639, 415);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 13);
			this->label2->TabIndex = 39;
			this->label2->Text = L"Давление";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Location = System::Drawing::Point(614, 221);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(80, 13);
			this->label3->TabIndex = 40;
			this->label3->Text = L"Температура: ";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Location = System::Drawing::Point(240, 331);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(60, 13);
			this->label4->TabIndex = 41;
			this->label4->Text = L"Мощность";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Location = System::Drawing::Point(240, 354);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(75, 13);
			this->label5->TabIndex = 42;
			this->label5->Text = L"Расход газа: ";
			// 
			// pictureBox13
			// 
			this->pictureBox13->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox13->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox13.BackgroundImage")));
			this->pictureBox13->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox13->Location = System::Drawing::Point(494, 509);
			this->pictureBox13->Name = L"pictureBox13";
			this->pictureBox13->Size = System::Drawing::Size(92, 36);
			this->pictureBox13->TabIndex = 43;
			this->pictureBox13->TabStop = false;
			// 
			// pictureBox14
			// 
			this->pictureBox14->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox14->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox14.BackgroundImage")));
			this->pictureBox14->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox14->Location = System::Drawing::Point(369, 527);
			this->pictureBox14->Name = L"pictureBox14";
			this->pictureBox14->Size = System::Drawing::Size(131, 18);
			this->pictureBox14->TabIndex = 44;
			this->pictureBox14->TabStop = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Location = System::Drawing::Point(366, 509);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(92, 13);
			this->label6->TabIndex = 45;
			this->label6->Text = L"Расход воздуха: ";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(925, 570);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(154, 42);
			this->button1->TabIndex = 46;
			this->button1->Text = L"ОТПРАВИТЬ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::btnNumber_Click);
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
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->pictureBox14);
			this->Controls->Add(this->pictureBox13);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox12);
			this->Controls->Add(this->pictureBox11);
			this->Controls->Add(this->pictureBox10);
			this->Controls->Add(this->pictureBox9);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->pictureBox7);
			this->Controls->Add(this->pictureBox8);
			this->Controls->Add(this->pictureBox6);
			this->Controls->Add(this->btnSettings);
			this->Controls->Add(this->btnErrors);
			this->Controls->Add(this->btnTrands);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox14))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {}
	
	private: System::Void btnNumber_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		Button^ button = safe_cast<Button^>(sender);

		if (button->Text == "ОТПРАВИТЬ")
		{
			json data = { {"tempStreet", Parser::TEMPERATURE_PARSER}, {"tempReq", Parser::TEMPERATURE_USER}, {"avto", int(avto)}, {"Pruch", Parser::PNagr}, {"pusk", int(pusk)} };
			Parser::post_data_to_site(Parser::files::postPS, data);
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
		if (avto || !pusk)
		{
			json data = { {"tempStreet", Parser::TEMPERATURE_PARSER}, {"tempReq", Parser::TEMPERATURE_USER}, {"avto", int(avto)}, {"Pruch", Parser::PNagr}, {"pusk", int(pusk)} };
			Parser::post_data_to_site(Parser::files::postPS, data);
		}
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
		close->Visible = false; 
		button1->Visible = false;
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
		close->Visible = true; 
		button1->Visible = true;
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
		close->Visible = false; 
		button1->Visible = false;
	}
}
};
}
