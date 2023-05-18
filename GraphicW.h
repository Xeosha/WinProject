#pragma once
#include <string>

namespace WinProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms::DataVisualization::Charting;
	/// <summary>
	/// —водка дл€ GraphicW
	/// </summary>
	public ref class GraphicW : public System::Windows::Forms::Form
	{
	public:
		GraphicW(void)
		{
			InitializeComponent();
			timer1->Enabled = true;
			chart->ChartAreas[0]->AxisY->Maximum = 100;
			chart->ChartAreas[0]->AxisY->Minimum = -40;

			chart->ChartAreas[0]->AxisX->LabelStyle->Format = "H:mm:ss";
			chart->Series[0]->XValueType = ChartValueType::DateTime;

			chart->ChartAreas[0]->AxisX->Minimum = DateTime::Now.ToOADate();
			chart->ChartAreas[0]->AxisX->Maximum = DateTime::Now.AddMinutes(1).ToOADate();

			chart->ChartAreas[0]->AxisX->IntervalType = DateTimeIntervalType::Seconds;
			chart->ChartAreas[0]->AxisX->Interval = 5;

			
		}
	private: String^ temp1;
		   String^ temp2;
		   String^ temp3;
		   String^ pnagr;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart;
	public:
		void setAttr(std::string temp1, std::string temp2, std::string temp3, std::string pnagr)
		{
				this->temp1 = gcnew String(temp1.c_str());
				this->temp2 = gcnew String(temp2.c_str());
				this->temp3 = gcnew String(temp3.c_str());
				this->pnagr = gcnew String(pnagr.c_str());
		}
	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~GraphicW()
		{
			if (components)
			{
				delete components;
			}
		}
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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->BeginInit();
			this->SuspendLayout();
			// 
			// chart
			// 
			this->chart->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			chartArea1->Name = L"ChartArea1";
			this->chart->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart->Legends->Add(legend1);
			this->chart->Location = System::Drawing::Point(-5, 0);
			this->chart->Name = L"chart";
			this->chart->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::Bright;
			series1->BorderColor = System::Drawing::Color::Red;
			series1->BorderWidth = 3;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->Color = System::Drawing::Color::Red;
			series1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			series1->LabelForeColor = System::Drawing::Color::Transparent;
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			series2->BorderWidth = 3;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series2->Color = System::Drawing::Color::Lime;
			series2->Legend = L"Legend1";
			series2->Name = L"Series2";
			series3->BorderWidth = 3;
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series3->Color = System::Drawing::Color::Yellow;
			series3->Legend = L"Legend1";
			series3->Name = L"Series3";
			series3->ShadowColor = System::Drawing::Color::Yellow;
			series4->BorderWidth = 10;
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastLine;
			series4->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			series4->Legend = L"Legend1";
			series4->Name = L"Series4";
			this->chart->Series->Add(series1);
			this->chart->Series->Add(series2);
			this->chart->Series->Add(series3);
			this->chart->Series->Add(series4);
			this->chart->Size = System::Drawing::Size(609, 447);
			this->chart->TabIndex = 0;
			this->chart->Text = L"chart1";
			// 
			// timer1
			// 
			this->timer1->Interval = 5000;
			this->timer1->Tick += gcnew System::EventHandler(this, &GraphicW::timer1_Tick);
			// 
			// GraphicW
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(604, 446);
			this->Controls->Add(this->chart);
			this->Name = L"GraphicW";
			this->Text = L"GraphicW";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &GraphicW::GraphicW_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: int _countSeconds = 0;
		   int _limitSeconds = 20;
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		DateTime timeNow = DateTime::Now;
		int value1 = Convert::ToInt32(temp1);
		int value2 = Convert::ToInt32(temp2);
		int value3 = Convert::ToInt32(temp3);
		int value4 = Convert::ToInt32(pnagr);

		chart->Series[0]->Points->AddXY(timeNow, value1);
		chart->Series[1]->Points->AddXY(timeNow, value2);
		chart->Series[2]->Points->AddXY(timeNow, value3);
		chart->Series[3]->Points->AddXY(timeNow, value4);
		_countSeconds += 5;

		if (_countSeconds == 60)
		{
			_countSeconds = 0;
			chart->ChartAreas[0]->AxisX->Minimum = DateTime::Now.ToOADate();
			chart->ChartAreas[0]->AxisX->Maximum = DateTime::Now.AddMinutes(1).ToOADate();

			chart->ChartAreas[0]->AxisX->IntervalType = DateTimeIntervalType::Seconds;
			chart->ChartAreas[0]->AxisX->Interval = 5;
		}
	}
private: System::Void GraphicW_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	e->Cancel = true;
	this->Hide();
}
};
}
