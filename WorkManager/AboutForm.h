// AboutForm.h

#pragma once

namespace MyProgram {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class AboutForm : public System::Windows::Forms::Form {
    public:
        AboutForm(void);
        ~AboutForm();

    protected:
        System::ComponentModel::Container^ components;

    private:
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::Label^ label3;
        System::Windows::Forms::Label^ label4;
        System::Windows::Forms::GroupBox^ groupBox; 
        System::Windows::Forms::Label^ label5; 
        System::Windows::Forms::PictureBox^ pictureBox1;

    private:
        void InitializeComponent(void);
    };
}
