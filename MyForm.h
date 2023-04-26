#pragma once
#define CURL_STATICLIB

#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <windows.h> 

std::string TEMPERATURE_PARSER = "0";											// обновляющаяся переменная темпы в Перми
std::string tempGor			   = "0";											// температура холодной горячей воды
std::string tempXol			   = "0";											// температура холодной горячей воды
std::string tempKomn		   = "0";											// температура в комнате
std::string PNagr			   = "0";											// мощность нагрева
std::string pomp			   = "0";											// идет ли подача воды
std::string error			   = "0";											// ошибка в ардуинке

std::string WEATHER_URL = "https:\//www.gismeteo.ru/weather-perm-4476/now/";	// откуда парсить темпу погоды
std::string SERVER_URL  = "http:\//x958887o.beget.tech/";						// ссылка для работы с ардуинкой
std::string jsPostPC	= "getPC.php";											// post запрос
std::string jsGet		= "new.json";											// json, откуда берутся данные выше.
std::string jsGetPC		= "newPC.json";

using namespace nlohmann;	// для json

//=========Парсер=======//
namespace Parser
{
	size_t write_data(void* ptr, size_t size, size_t nmemb, std::string* data) {
		data->append((char*)ptr, size * nmemb);
		return size * nmemb;
	}
	std::string get_data_from_site(std::string url) {
		CURL* curl;
		CURLcode response;
		std::string data = "";

		curl = curl_easy_init();
		if (curl)
		{
			curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
			response = curl_easy_perform(curl);
			if (response != CURLE_OK) {
				std::cerr << "Error: " << curl_easy_strerror(response) << std::endl;
				return "";
			}
			curl_easy_cleanup(curl);
			if (url == WEATHER_URL)
			{
				std::cout << "GET: " << "Parsing temperature = " << TEMPERATURE_PARSER << std::endl;
			}
			else 	std::cout << "GET: " << data << std::endl;
		}
		return data;
	}

	int post_data_to_site(std::string url, json data)
	{
		CURLcode ret;
		CURL* hnd;
		struct curl_slist* slist1;
		std::string jsonstr = data.dump();

		slist1 = NULL;
		slist1 = curl_slist_append(slist1, "Content-Type: application/json");

		hnd = curl_easy_init();
		if (hnd)
		{
			curl_easy_setopt(hnd, CURLOPT_URL, url.c_str());
			curl_easy_setopt(hnd, CURLOPT_NOPROGRESS, 1L);
			curl_easy_setopt(hnd, CURLOPT_POSTFIELDS, jsonstr.c_str());
			curl_easy_setopt(hnd, CURLOPT_USERAGENT, "Mozilla/5.0");
			curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, slist1);
			curl_easy_setopt(hnd, CURLOPT_POSTFIELDSIZE, jsonstr.size());
			curl_easy_setopt(hnd, CURLOPT_MAXREDIRS, 50L);
			curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "POST");
			curl_easy_setopt(hnd, CURLOPT_TCP_KEEPALIVE, 1L);

			ret = curl_easy_perform(hnd);
			if (ret != CURLE_OK) {
				std::cerr << "Error: " << curl_easy_strerror(ret) << std::endl;
				return 0;
			}
			std::cout << "POST: " << jsonstr << std::endl;
			curl_easy_cleanup(hnd);
			curl_slist_free_all(slist1);
			return 1;
		} return 0;
	}


	std::string parse_temperature(std::string data) {
		if (data == "") return "0";
		int pos = data.find("<span class=\"sign\">"); 
		if ('-' == data[pos + 19])
		{
			int pos_end = data.find("</span>", pos + 27);
			return "-" + data.substr(pos + 27, pos_end - pos - 27);
		}
		else if ('+' == data[pos + 19])
		{
			int pos_end = data.find("</span>", pos + 27);
			return "+" + data.substr(pos + 27, pos_end - pos - 27);
		}
		else return "0";
	}
	void Parsing()
	{
		std::string data = get_data_from_site(WEATHER_URL);
		TEMPERATURE_PARSER = parse_temperature(data);
	}

}



namespace WinProject {

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

	public:
		MyForm(void)
		{
			InitializeComponent();
			Parser::Parsing();
			this->TextYopta->Text = gcnew String(TEMPERATURE_PARSER.c_str());
			timer1->Enabled = true;
			//
			//TODO: добавьте код конструктора
			//
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Settings))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(86, 163);
			this->button1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(165, 92);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Отправить json";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::btnNumber_Click);
			// 
			// TextYopta
			// 
			this->TextYopta->Location = System::Drawing::Point(115, 83);
			this->TextYopta->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->TextYopta->Name = L"TextYopta";
			this->TextYopta->Size = System::Drawing::Size(150, 20);
			this->TextYopta->TabIndex = 1;
			this->TextYopta->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox);
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
			this->button2->Location = System::Drawing::Point(86, 278);
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
			this->pictureBox1->Location = System::Drawing::Point(61, 61);
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
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(99)));
			this->ClientSize = System::Drawing::Size(380, 523);
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

			if (Parser::post_data_to_site(SERVER_URL + jsPostPC, data))
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
				data = Parser::get_data_from_site(SERVER_URL+jsGet);
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
	private: System::Void textBox(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btn_Close(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Close();
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		Parser::Parsing();
		this->TextYopta->Text = gcnew String(TEMPERATURE_PARSER.c_str());
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
};
}
