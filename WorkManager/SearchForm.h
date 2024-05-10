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

    public ref class SearchForm : public System::Windows::Forms::Form
    {
    public:
        SearchForm(void)
        {
            InitializeComponent();
        }
        String^ GetSearchTerm()
        {
            return textBoxSearch->Text;
        }
    protected:
        ~SearchForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::TextBox^ textBoxSearch;
    private: System::Windows::Forms::Button^ buttonSearch;
    private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
           void InitializeComponent(void)
           {
               this->Icon = gcnew System::Drawing::Icon("����������_2024-05-07_195625444.ico");
               this->textBoxSearch = gcnew System::Windows::Forms::TextBox();
               this->buttonSearch = gcnew System::Windows::Forms::Button();
               this->SuspendLayout();
               // 
               // textBoxSearch
               // 
               this->textBoxSearch->Location = System::Drawing::Point(50, 50);
               this->textBoxSearch->Name = L"textBoxSearch";
               this->textBoxSearch->Size = System::Drawing::Size(200, 20);
               this->textBoxSearch->TabIndex = 0;
               // 
               // buttonSearch
               // 
               this->buttonSearch->Location = System::Drawing::Point(100, 100);
               this->buttonSearch->Name = L"buttonSearch";
               this->buttonSearch->Size = System::Drawing::Size(100, 30);
               this->buttonSearch->Text = L"Search";
               this->buttonSearch->Click += gcnew System::EventHandler(this, &SearchForm::buttonSearch_Click);
               // 
               // SearchForm
               // 
               this->ClientSize = System::Drawing::Size(300, 200);
               this->Controls->Add(this->textBoxSearch);
               this->Controls->Add(this->buttonSearch);
               this->Name = L"�����";
               this->Text = L"�����";
               this->ResumeLayout(false);
               this->PerformLayout();
           }
#pragma endregion

    private:
        System::Void buttonSearch_Click(System::Object^ sender, System::EventArgs^ e)
        {
            // �������� ����� ������ � ���������� ����
            String^ searchString = textBoxSearch->Text;

            // ����� �� ������ ��������������� ��� ����� ��� ������ � ��������� ��� ��� �������� ���� 䳿 � ���
            // ���������, �� ������ ���������� ������� ���������� � ������ ��� ��� �������� ����� � ��� �����

            // ��� �� ������ ������ ��� ��� ��� ������� ����� ������
        }
    private: System::Void searchButton_Click(System::Object^ sender, System::EventArgs^ e) {
            // ��������� ������ ���������� ����� ������
            SearchForm^ searchForm = gcnew SearchForm();

            // �������� ����� ������
            searchForm->ShowDialog();

            // ��������� ���������� ������
            String^ searchTerm = searchForm->GetSearchTerm();

            // �������� 䳿 � ��������� ����������� ������
            // ���������, ������� ���� � �������
            Console::WriteLine("Search term: " + searchTerm);
        }
    };

}
