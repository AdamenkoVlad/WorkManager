#pragma once

#include <Windows.h>
#include <tlhelp32.h>
#include <psapi.h >
#include <string>
#include <iostream>
#include "AboutForm.h"
#include "MainMenuForm.h"


namespace MyProgram {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;


    public ref class MainForm : public System::Windows::Forms::Form
    {
    public:
        MainForm(void);
        ~MainForm();

    protected:
        void InitializeComponent(void);
        void DisplayProcessList();
        void OnColumnClick(System::Object^ sender, System::Windows::Forms::ColumnClickEventArgs^ e);
        void MainForm_Load(System::Object^ sender, System::EventArgs^ e);

        
        void InitializeMenu();
        void InitializeListView();
        void listViewProcesses_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
        
        void �����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
        void MainForm::listViewProcesses_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
        void MainForm::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
        void MainForm::SearchProcesses(String^ searchTerm);


    private:
        System::Windows::Forms::MenuStrip^ menuStrip1;
        System::Windows::Forms::Button^ btnRefresh;

        System::Windows::Forms::MenuStrip^ mainMenuStrip;
        System::ComponentModel::Container^ components;
        System::Windows::Forms::Label^ labelAuthor;
        System::Windows::Forms::Label^ labelDescription;
        System::Windows::Forms::ToolStripMenuItem^ ���ToolStripMenuItem;
        System::Windows::Forms::ToolStripMenuItem^ �����������ToolStripMenuItem; 
        System::Windows::Forms::ToolStripMenuItem^ �����������ToolStripMenuItem;
        System::Windows::Forms::ListView^ listViewProcesses;
        System::Windows::Forms::ToolStripMenuItem^ �����ToolStripMenuItem;
        



        System::Void �����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
            // ��������� �� ����������� ���� � ����������� ��� ��������
            AboutForm^ aboutForm = gcnew AboutForm();
            aboutForm->ShowDialog();
        }
        void MainForm::ShowMainMenuForm() {
            // ��������� ������ ���������� ����� ��������� ����
            MainMenuForm^ mainMenuForm = gcnew MainMenuForm();

            // ³���������� ����� ��������� ����
            mainMenuForm->ShowDialog();
        }

        // ���������� ��������� ���� ��� �������� ���� "��� ��������"
        System::Void aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
            // ��������� �� ����������� ������ ���� "��� ��������"
            AboutForm^ aboutForm = gcnew AboutForm();
            aboutForm->Show();
        }
    private: System::Void btnRefresh_Click(System::Object^ sender, System::EventArgs^ e) {
        // ������ ������ ��������� ������ �������
        DisplayProcessList();
    }


    };


    // ���������� ����� ListViewItemComparer
    public ref class ListViewItemComparer : public System::Collections::IComparer
    {
    private:
        int col;
        System::Windows::Forms::SortOrder order;

    public:
        ListViewItemComparer(int column, System::Windows::Forms::SortOrder order);
        virtual int Compare(System::Object^ x, System::Object^ y);
    };
}
