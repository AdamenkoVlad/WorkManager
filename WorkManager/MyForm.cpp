#include "MyForm.h"
#include <Windows.h>
#include <tlhelp32.h>
#include <psapi.h >
#include "AboutForm.h"
#include "MainMenuForm.h"
#include "SearchForm.h"


namespace MyProgram {

    MainForm::MainForm(void)
    {
        InitializeComponent();
        DisplayProcessList();
        void MainForm_Load(System::Object ^ sender, System::EventArgs ^ e);
       
      
      


    }

    MainForm::~MainForm()
    {
        if (components)
        {
            delete components;
        }
    }

    void MainForm::InitializeComponent(void)
    {
        this->Icon = gcnew System::Drawing::Icon("����������_2024-05-07_195625444.ico");

        this->components = gcnew System::ComponentModel::Container();
        this->listViewProcesses = gcnew System::Windows::Forms::ListView();
        this->mainMenuStrip = gcnew System::Windows::Forms::MenuStrip();

        InitializeListView();
        InitializeMenu();

        // ������������ ����
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(800, 450);
        
        this->Text = "WorkManager";


        this->btnRefresh = gcnew System::Windows::Forms::Button();
        this->btnRefresh->Text = "������� �������";
        this->btnRefresh->Size = System::Drawing::Size(180, 22); // ����� ������
        this->btnRefresh->Click += gcnew System::EventHandler(this, &MainForm::btnRefresh_Click); // �������� ��䳿 ��� ������

        // ������������ ������ (�������� �� ��������� ����)
        int menuRight = this->mainMenuStrip->Location.X + this->mainMenuStrip->Width; // ����� ������� ��������� ����
        int menuTop = this->mainMenuStrip->Location.Y; // ������ ������� ��������� ����
        int btnWidth = 40; // ������ ������
        int btnHeight = 20; // ������ ������
        this->btnRefresh->Location = System::Drawing::Point(350,0);

        // ��������� ������ �� ����������
        this->Controls->Add(this->btnRefresh);

        this->Controls->Add(this->listViewProcesses);
        this->Controls->Add(this->mainMenuStrip);

        this->ResumeLayout(false);
        this->PerformLayout();
        this->listViewProcesses->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::listViewProcesses_MouseClick);
        this->listViewProcesses->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::listViewProcesses_MouseDoubleClick);


       
    }
    void MainForm::InitializeListView()
    {
        // ������������ ������������ ListView
        this->listViewProcesses->View = System::Windows::Forms::View::Details; // ��� � ����� �������
        this->listViewProcesses->Dock = System::Windows::Forms::DockStyle::Fill; // ����� ���� ��������� ������
        this->listViewProcesses->GridLines = true; // ���������� �� �� ���������
        this->listViewProcesses->FullRowSelect = true; // ������� ���� �����

        // ��������� ��������
        this->listViewProcesses->Columns->Add(gcnew System::Windows::Forms::ColumnHeader());
        this->listViewProcesses->Columns[0]->Text = L"Process Name";
        this->listViewProcesses->Columns[0]->Tag = "String"; // ��������� ���������� ��� ��� ����� � �������

        this->listViewProcesses->Columns->Add(gcnew System::Windows::Forms::ColumnHeader());
        this->listViewProcesses->Columns[1]->Text = L"Process ID";
        this->listViewProcesses->Columns[1]->Tag = "Numeric"; // ��������� ���������� ��� ��� ����� � �������

        // ��������� ����� ��������
        this->listViewProcesses->Columns->Add(gcnew System::Windows::Forms::ColumnHeader());
        this->listViewProcesses->Columns[2]->Text = L"Memory Usage";
        this->listViewProcesses->Columns[2]->Tag = "Numeric"; // ��������� ���������� ��� ��� ����� � �������

        this->listViewProcesses->Columns->Add(gcnew System::Windows::Forms::ColumnHeader());
        this->listViewProcesses->Columns[3]->Text = L"Priority";
        this->listViewProcesses->Columns[3]->Tag = "String"; // ��������� ���������� ��� ��� ����� � �������

        // ��������� ��������� ���� ��� ���������� ��������
        for (int i = 0; i < this->listViewProcesses->Columns->Count; i++)
        {
            this->listViewProcesses->Columns[i]->Width = -2; // ����������� ������ �������
            this->listViewProcesses->Columns[i]->Tag = gcnew String("String");
            this->listViewProcesses->ColumnClick += gcnew System::Windows::Forms::ColumnClickEventHandler(this, &MainForm::OnColumnClick);
        }
    
    }
    void MainForm::InitializeMenu()
    {
        // ������������ ��������� ����
        this->mainMenuStrip->Location = System::Drawing::Point(0, 0);
        this->mainMenuStrip->Name = L"mainMenuStrip";
        this->mainMenuStrip->Size = System::Drawing::Size(800, 24);
        this->mainMenuStrip->TabIndex = 0;
        this->mainMenuStrip->Text = L"mainMenuStrip";

        // �������� ��������� ������� ����
        this->�����������ToolStripMenuItem = gcnew System::Windows::Forms::ToolStripMenuItem();
        this->�����������ToolStripMenuItem->Name = L"�����������ToolStripMenuItem";
        this->�����������ToolStripMenuItem->Size = System::Drawing::Size(180, 22);
        this->�����������ToolStripMenuItem->Text = L"������� ����";
        this->�����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::�����������ToolStripMenuItem_Click);

        // ��������� �������� �� ��������� ����
        this->mainMenuStrip->Items->Add(this->�����������ToolStripMenuItem);

        this->�����ToolStripMenuItem = gcnew System::Windows::Forms::ToolStripMenuItem();
        this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
        this->�����ToolStripMenuItem->Size = System::Drawing::Size(53, 20);
        this->�����ToolStripMenuItem->Text = L"�����";
        this->�����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::�����ToolStripMenuItem_Click);

        this->mainMenuStrip->Items->Insert(1, this->�����ToolStripMenuItem);


        // ���� ������ ������� "��� ��������"
        this->�����������ToolStripMenuItem = gcnew System::Windows::Forms::ToolStripMenuItem();
        this->�����������ToolStripMenuItem->Name = L"�����������ToolStripMenuItem";
        this->�����������ToolStripMenuItem->Size = System::Drawing::Size(180, 22);
        this->�����������ToolStripMenuItem->Text = L"��� ����������";
        this->�����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::�����������ToolStripMenuItem_Click);


        // ��������� �������� �� ��������� ����
        this->mainMenuStrip->Items->Add(this->�����������ToolStripMenuItem);
    }


    void MainForm::�����������ToolStripMenuItem_Click(Object^ sender, EventArgs^ e)
    {
        // �������� ��� ��������� ������� ����
        ShowMainMenuForm();
    }


    void MainForm::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        // ³���������� ���� ��� �������� ������� ������ �� ��������� ������
        SearchForm^ searchForm = gcnew SearchForm();
        if (searchForm->ShowDialog() == System::Windows::Forms::DialogResult::OK)
        {
            // ��������� ������� ������ � �����
            String^ searchTerm = searchForm->GetSearchTerm();

            // ��������� ������ �� ����������� ����������
            SearchProcesses(searchTerm);
        }
    }
    void MainForm::SearchProcesses(String^ searchTerm)
    {
        // �������� ������ �������
        listViewProcesses->Items->Clear();

        // ��������� ������ �� ������� �������
        // ��� �� ������ ���������� ��� �������� ������, ���� ������� ����� �������

        // ���������, ����� ��������� �� ������� � �������� �� ����� � ������� ������
        HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        if (hProcessSnap == INVALID_HANDLE_VALUE)
        {
            return;
        }

        PROCESSENTRY32 pe32;
        pe32.dwSize = sizeof(PROCESSENTRY32);
        if (Process32First(hProcessSnap, &pe32))
        {
            do
            {
                String^ processName = gcnew String(pe32.szExeFile);
                if (processName->IndexOf(searchTerm, StringComparison::InvariantCultureIgnoreCase) != -1)
                {
                    ListViewItem^ item = gcnew ListViewItem(processName);
                    item->SubItems->Add(pe32.th32ProcessID.ToString());
                    // ��������� ������� ���������� ��� ������ �� ��������� ���� �� ������
                    listViewProcesses->Items->Add(item);
                }
            } while (Process32Next(hProcessSnap, &pe32));
        }

        CloseHandle(hProcessSnap);
    }

    void MainForm::listViewProcesses_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
    {
        // ��������, �� ���� ��������� ��� ������ ���� ����
        if (e->Button == System::Windows::Forms::MouseButtons::Left && e->Clicks == 2)
        {
            // ��������� ��������� �������� ������
            ListViewItem^ selectedItem = listViewProcesses->GetItemAt(e->X, e->Y);
            if (selectedItem != nullptr)
            {
                // ��������� ID ��������� �������
                String^ processID = selectedItem->SubItems[1]->Text;
                int pid = Convert::ToInt32(processID);

                // ��������, �� ������ ����
                HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, pid);
                if (hProcess != NULL)
                {
                    // ³���������� ���������� ���� ��� ������������ �������� �������
                    if (MessageBox::Show("������ ������� ��� ������?", "ϳ�����������", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
                    {
                        // ���������� �������
                        TerminateProcess(hProcess, 0);
                    }
                    CloseHandle(hProcess);
                }
                else
                {
                    MessageBox::Show("�� ������� ������ ������.", "�������", MessageBoxButtons::OK, MessageBoxIcon::Error);
                }

                // ��������� ������ ������� ���� �������� ��� ��������� �������
                DisplayProcessList();
            }
        }
    }


    // ��������� ����� DisplayProcessList
    void MainForm::DisplayProcessList()
    {
        listViewProcesses->Items->Clear();

        HANDLE hProcessSnap;
        PROCESSENTRY32 pe32;

        hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        if (hProcessSnap == INVALID_HANDLE_VALUE)
        {
            return;
        }

        pe32.dwSize = sizeof(PROCESSENTRY32);

        if (!Process32First(hProcessSnap, &pe32))
        {
            CloseHandle(hProcessSnap);
            return;
        }

        do
        {
            ListViewItem^ item = gcnew ListViewItem(gcnew String(pe32.szExeFile));
            item->SubItems->Add(pe32.th32ProcessID.ToString());

            // ��������� ���������� ��� ���'���, ��� ����� ������
            PROCESS_MEMORY_COUNTERS pmc;
            HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pe32.th32ProcessID);
            if (hProcess != NULL && GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)))
            {
                // ���������� ����� � ���������
                float memoryInMB = static_cast<float>(pmc.WorkingSetSize) / (1024 * 1024);
                item->SubItems->Add(memoryInMB.ToString("N2")); // �������� �� ���� ����� ���� ����
            }
            else
            {
                item->SubItems->Add("N/A");
            }
            CloseHandle(hProcess);

            // ��������� ��������� �������
            HANDLE hProcessPriority = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, pe32.th32ProcessID);
            if (hProcessPriority != NULL)
            {
                int priority = GetPriorityClass(hProcessPriority);
                switch (priority)
                {
                case IDLE_PRIORITY_CLASS:
                    item->SubItems->Add("Idle");
                    break;
                case BELOW_NORMAL_PRIORITY_CLASS:
                    item->SubItems->Add("Below Normal");
                    break;
                case NORMAL_PRIORITY_CLASS:
                    item->SubItems->Add("Normal");
                    break;
                case ABOVE_NORMAL_PRIORITY_CLASS:
                    item->SubItems->Add("Above Normal");
                    break;
                case HIGH_PRIORITY_CLASS:
                    item->SubItems->Add("High");
                    break;
                case REALTIME_PRIORITY_CLASS:
                    item->SubItems->Add("Realtime");
                    break;
                default:
                    item->SubItems->Add("Unknown");
                }
            }
            else
            {
                item->SubItems->Add("N/A");
            }
            CloseHandle(hProcessPriority);

            listViewProcesses->Items->Add(item);

        } while (Process32Next(hProcessSnap, &pe32));

        CloseHandle(hProcessSnap);
    }

    

    void MainForm::OnColumnClick(System::Object^ sender, System::Windows::Forms::ColumnClickEventArgs^ e)
    {
        ListView^ lv = (ListView^)sender;

        // ���������� ������� ���������� (���������� ��� ���������)
        if (lv->Sorting == SortOrder::Ascending || lv->Sorting == SortOrder::None)
        {
            lv->Sorting = SortOrder::Descending;
        }
        else
        {
            lv->Sorting = SortOrder::Ascending;
        }

        // ��������� ���������� ����� ListViewItemComparer � �������� ���� � ���������� ListViewItemSorter
        lv->ListViewItemSorter = gcnew ListViewItemComparer(e->Column, lv->Sorting);
        lv->Sort();
    }
 
    // ����������� ����� ListViewItemComparer
    ListViewItemComparer::ListViewItemComparer(int column, SortOrder order) : col(column), order(order) {}

    // ����� ��������� �������� ��� ���������� ListView
    int ListViewItemComparer::Compare(System::Object^ x, System::Object^ y)
    {
        ListViewItem^ lx = (ListViewItem^)x;
        ListViewItem^ ly = (ListViewItem^)y;

        // ��������� �� ����� �����
        if (lx->ListView->Columns[col]->Tag->ToString() == "Numeric")
        {
            // ��������� ���� ��� ����� ��������
            return Decimal::Compare(Decimal::Parse(lx->SubItems[col]->Text), Decimal::Parse(ly->SubItems[col]->Text)) * (order == SortOrder::Ascending ? 1 : -1);
        }
        else
        {
            // ��������� ���� ��� ����� ��������
            return String::Compare(lx->SubItems[col]->Text, ly->SubItems[col]->Text) * (order == SortOrder::Ascending ? 1 : -1);
        }
    }


    void MainForm::MainForm_Load(System::Object^ sender, System::EventArgs^ e)
    {
        DisplayProcessList();
    }



    void MainForm::listViewProcesses_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
    {
        // ��������, �� ���� ��������� ����� ������ ����
        if (e->Button == System::Windows::Forms::MouseButtons::Right)
        {
            // ��������� ��������� �������� ������
            ListViewItem^ selectedItem = listViewProcesses->GetItemAt(e->X, e->Y);
            if (selectedItem != nullptr)
            {
                // ��������� ���������� ��� ������
                String^ processName = selectedItem->SubItems[0]->Text; // ����� �������
                String^ processID = selectedItem->SubItems[1]->Text; // ID �������

                // ³������� ������� ��� ��������� ����������
                HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, Convert::ToInt32(processID));
                if (hProcess != NULL)
                {
                    // ��������� ����� �� ������������ ����� �������
                    wchar_t path[MAX_PATH];
                    DWORD pathLength = GetModuleFileNameEx(hProcess, NULL, path, MAX_PATH);
                    CloseHandle(hProcess);

                    if (pathLength != 0)
                    {
                        // ����������� ����� �� ������������ ����� � ����� .NET
                        String^ processLocation = gcnew String(path);

                        // ��������� ���� ������� �������
                        FILETIME creationTime, exitTime, kernelTime, userTime;
                        GetProcessTimes(hProcess, &creationTime, &exitTime, &kernelTime, &userTime);
                        SYSTEMTIME utcSystemTime, localSystemTime;
                        FileTimeToSystemTime(&creationTime, &utcSystemTime);
                        SystemTimeToTzSpecificLocalTime(NULL, &utcSystemTime, &localSystemTime);
                        System::DateTime startTime(localSystemTime.wYear, localSystemTime.wMonth, localSystemTime.wDay,
                            localSystemTime.wHour, localSystemTime.wMinute, localSystemTime.wSecond,
                            localSystemTime.wMilliseconds);
                        String^ startTimeString = startTime.ToString();

                        // ��������� ����������� � ����������� ��� ������
                        String^ message = "Process Name: " + processName + "\n"
                            + "Process ID: " + processID + "\n"
                            + "Location: " + processLocation + "\n"
                            + "Start Time: " + startTimeString;

                        // ³���������� �����������
                        MessageBox::Show(message, "Process Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
                    }
                    else
                    {
                        MessageBox::Show("Failed to get process location.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    }
                }
                else
                {
                    MessageBox::Show("Failed to open process.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                }
            }
        }
    }




}