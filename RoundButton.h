#pragma once


public ref class RoundButton : public System::Windows::Forms::Button
{
protected:

    virtual void OnPaint(System::Windows::Forms::PaintEventArgs^ e) override
    {
        Button::OnPaint(e);

        System::Drawing::Graphics^ g = e->Graphics;
        g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;
        System::Drawing::SolidBrush^ brush = gcnew System::Drawing::SolidBrush(this->BackColor);
        g->FillEllipse(brush, 0, 0, this->Width - 1, this->Height - 1);
    }

public:
    RoundButton()
    {
        this->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
        this->Size = System::Drawing::Size(30, 30);
    }
};