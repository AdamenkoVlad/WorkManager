#pragma once

#include <Windows.h>
#include <string>

namespace MyProgram {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MainMenuForm : public System::Windows::Forms::Form
    {
    public:
        MainMenuForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~MainMenuForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::Button^ buttonExit;
    private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
           void InitializeComponent(void)
           {
               this->Icon = gcnew System::Drawing::Icon("зображення_2024-05-07_195625444.ico");
               this->buttonExit = gcnew System::Windows::Forms::Button();
               this->SuspendLayout();
               // 
               // buttonExit
               // 
               this->buttonExit->Location = System::Drawing::Point(70, 50);
               this->buttonExit->Name = L"buttonExit";
               this->buttonExit->Size = System::Drawing::Size(120, 30);
               this->buttonExit->Text = L"Вийти з програми";
               this->buttonExit->Click += gcnew System::EventHandler(this, &MainMenuForm::buttonExit_Click);
               // 
               // MainMenuForm
               // 
               this->ClientSize = System::Drawing::Size(260, 120);
               this->Controls->Add(this->buttonExit);
               this->Name = L"MainMenuForm";
               this->Text = L"Головне меню";
               this->ResumeLayout(false);
           }
#pragma endregion

    private:
        System::Void buttonExit_Click(System::Object^ sender, System::EventArgs^ e)
        {
            if (MessageBox::Show("Бажаєте вийти з програми?", "Головне меню", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
            {
                Application::Exit();
            }
        }
    };

}
