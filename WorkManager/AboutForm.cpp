// AboutForm.cpp

#include "AboutForm.h"

namespace MyProgram {
    AboutForm::AboutForm() {
        InitializeComponent(); // Використовуйте правильне ім'я методу
        components = gcnew System::ComponentModel::Container();
    }

    AboutForm::~AboutForm() {
        if (components) {
            delete components;
        }
    }

    void AboutForm::InitializeComponent() {
        this->Icon = gcnew System::Drawing::Icon("зображення_2024-05-07_195625444.ico");
       
            
        this->pictureBox1 = gcnew System::Windows::Forms::PictureBox();
        this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
        this->pictureBox1->Location = System::Drawing::Point(this->Width - this->pictureBox1->Width - 10, 10);
       // this->pictureBox1->Size = System::Drawing::Size(150, 150); // Зміна розмірів до 150x150
        Image^ image = Image::FromFile("free-icon-font-apps-add-3917631.png"); 
        Image^ resizedImage = gcnew Bitmap(image, 30, 30);

        // Встановлення зміненого зображення у контейнер PictureBox
        this->pictureBox1->Image = resizedImage;
        this->Controls->Add(this->pictureBox1);
        

            

        this->label1 = gcnew System::Windows::Forms::Label();
        this->label2 = gcnew System::Windows::Forms::Label();
        this->label3 = gcnew System::Windows::Forms::Label();
        this->label4 = gcnew System::Windows::Forms::Label();
        this->groupBox = gcnew System::Windows::Forms::GroupBox(); // Додамо новий GroupBox
        this->label5 = gcnew System::Windows::Forms::Label();

        this->label1->Text = "Author: [Адаменко Владислав 4пі-21б]";
        this->label1->Location = System::Drawing::Point(10, 100);
        this->label1->AutoSize = true;

        this->label2->Text = "Застосунок для керування процесами Windows";
        this->label2->Location = System::Drawing::Point(10, 70);
        this->label2->AutoSize = true;

        this->label3->Text = "Version: [1.0]";
        this->label3->Location = System::Drawing::Point(10, 40);
        this->label3->AutoSize = true;

        this->label4->Text = "WorkManager";
        this->label4->Location = System::Drawing::Point(10, 10);
        this->label4->AutoSize = true;

        this->groupBox->Text = "Головний функціонал застосунку"; // Встановлюємо заголовок GroupBox
        this->groupBox->Location = System::Drawing::Point(10, 130); // Розташовуємо GroupBox
        this->groupBox->Size = System::Drawing::Size(240, 100); // Задаємо розмір GroupBox
        this->groupBox->Controls->Add(this->label5); // Додаємо Label в GroupBox

        String^ labelText = 
            "1. Відображення працюючих процесів\n"
            "2. Закриття процесу\n"
            "3. Сортування списку процесів\n"
            "4. Пошук процесів\n"
            "5. Відображення інформації про програму";
        this->label5->Text = labelText;
        this->label5->Location = System::Drawing::Point(10, 20);
        this->label5->AutoSize = true;

        this->Name = L"Про застосунок";
        this->Text = L"Про застосунок";
        this->Controls->Add(this->label1);
        this->Controls->Add(this->label2);
        this->Controls->Add(this->label3);
        this->Controls->Add(this->label4);
        this->Controls->Add(this->groupBox);
        
    }
}
