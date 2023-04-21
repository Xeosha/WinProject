#pragma once
#define CURL_STATICLIB
#include <iostream>
#include <string>
#include <curl/curl.h>

std::string TEMPERATURE_PARSER = "0";						// обновл€юща€с€ переменна€ темпы в ѕерми

//=========ѕарсер=======//
namespace Parser
{
	size_t write_data(void* ptr, size_t size, size_t nmemb, std::string* data) {
		data->append((char*)ptr, size * nmemb);
		return size * nmemb;
	}
	std::string get_data_from_site() {
		CURL* curl;
		std::string data;

		curl = curl_easy_init();
		curl_easy_setopt(curl, CURLOPT_URL, "https://www.gismeteo.ru/weather-perm-4476/now/");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
		curl_easy_perform(curl);
		curl_easy_cleanup(curl);

		return data;
	}
	std::string parse_temperature(std::string data) {
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
		std::string data = get_data_from_site();
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
	/// —водка дл€ MyForm
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
	private: System::Windows::Forms::TextBox^ TextYopta;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->TextYopta = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(100, 245);
			this->button1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(165, 92);
			this->button1->TabIndex = 0;
			this->button1->Text = L"btn";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::btn);
			// 
			// TextYopta
			// 
			this->TextYopta->Location = System::Drawing::Point(136, 175);
			this->TextYopta->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->TextYopta->Name = L"TextYopta";
			this->TextYopta->Size = System::Drawing::Size(100, 20);
			this->TextYopta->TabIndex = 1;
			this->TextYopta->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(7)),
				static_cast<System::Int32>(static_cast<System::Byte>(7)));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button2->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Marlett", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(12, 13);
			this->button2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(29, 28);
			this->button2->TabIndex = 2;
			this->button2->Text = L"x";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 10000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
				static_cast<System::Int32>(static_cast<System::Byte>(99)));
			this->ClientSize = System::Drawing::Size(371, 493);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->TextYopta);
			this->Controls->Add(this->button1);
			this->ForeColor = System::Drawing::Color::Black;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"WinProject";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	
	private: System::Void btn(System::Object^ sender, System::EventArgs^ e) 
	{
		this->TextYopta->Text = "“ут должна быть темпа";
	}
	private: System::Void textBox(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Close();
	}
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
{
	Parser::Parsing();
	this->TextYopta->Text = gcnew String(TEMPERATURE_PARSER.c_str());
}
};
}
