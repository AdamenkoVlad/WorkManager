// AboutForm.cpp

#include "AboutForm.h"

namespace MyProgram {
    AboutForm::AboutForm() {
        InitializeComponent(); // �������������� ��������� ��'� ������
        components = gcnew System::ComponentModel::Container();
    }

    AboutForm::~AboutForm() {
        if (components) {
            delete components;
        }
    }

    void AboutForm::InitializeComponent() {
        this->Icon = gcnew System::Drawing::Icon("����������_2024-05-07_195625444.ico");
       
            
        this->pictureBox1 = gcnew System::Windows::Forms::PictureBox();
        this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
        this->pictureBox1->Location = System::Drawing::Point(this->Width - this->pictureBox1->Width - 10, 10);
       // this->pictureBox1->Size = System::Drawing::Size(150, 150); // ���� ������ �� 150x150
        Image^ image = Image::FromFile("free-icon-font-apps-add-3917631.png"); 
        Image^ resizedImage = gcnew Bitmap(image, 30, 30);

        // ������������ �������� ���������� � ��������� PictureBox
        this->pictureBox1->Image = resizedImage;
        this->Controls->Add(this->pictureBox1);
        

            

        this->label1 = gcnew System::Windows::Forms::Label();
        this->label2 = gcnew System::Windows::Forms::Label();
        this->label3 = gcnew System::Windows::Forms::Label();
        this->label4 = gcnew System::Windows::Forms::Label();
        this->groupBox = gcnew System::Windows::Forms::GroupBox(); // ������ ����� GroupBox
        this->label5 = gcnew System::Windows::Forms::Label();

        this->label1->Text = "Author: [�������� ��������� 4�-21�]";
        this->label1->Location = System::Drawing::Point(10, 100);
        this->label1->AutoSize = true;

        this->label2->Text = "���������� ��� ��������� ��������� Windows";
        this->label2->Location = System::Drawing::Point(10, 70);
        this->label2->AutoSize = true;

        this->label3->Text = "Version: [1.0]";
        this->label3->Location = System::Drawing::Point(10, 40);
        this->label3->AutoSize = true;

        this->label4->Text = "WorkManager";
        this->label4->Location = System::Drawing::Point(10, 10);
        this->label4->AutoSize = true;

        this->groupBox->Text = "�������� ���������� ����������"; // ������������ ��������� GroupBox
        this->groupBox->Location = System::Drawing::Point(10, 130); // ����������� GroupBox
        this->groupBox->Size = System::Drawing::Size(240, 100); // ������ ����� GroupBox
        this->groupBox->Controls->Add(this->label5); // ������ Label � GroupBox

        String^ labelText = 
            "1. ³���������� ��������� �������\n"
            "2. �������� �������\n"
            "3. ���������� ������ �������\n"
            "4. ����� �������\n"
            "5. ³���������� ���������� ��� ��������";
        this->label5->Text = labelText;
        this->label5->Location = System::Drawing::Point(10, 20);
        this->label5->AutoSize = true;

        this->Name = L"��� ����������";
        this->Text = L"��� ����������";
        this->Controls->Add(this->label1);
        this->Controls->Add(this->label2);
        this->Controls->Add(this->label3);
        this->Controls->Add(this->label4);
        this->Controls->Add(this->groupBox);
        
    }
}
