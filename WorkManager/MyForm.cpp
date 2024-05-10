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
        this->Icon = gcnew System::Drawing::Icon("зображення_2024-05-07_195625444.ico");

        this->components = gcnew System::ComponentModel::Container();
        this->listViewProcesses = gcnew System::Windows::Forms::ListView();
        this->mainMenuStrip = gcnew System::Windows::Forms::MenuStrip();

        InitializeListView();
        InitializeMenu();

        // Налаштування вікна
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(800, 450);
        
        this->Text = "WorkManager";


        this->btnRefresh = gcnew System::Windows::Forms::Button();
        this->btnRefresh->Text = "Оновити процеси";
        this->btnRefresh->Size = System::Drawing::Size(180, 22); // Розмір кнопки
        this->btnRefresh->Click += gcnew System::EventHandler(this, &MainForm::btnRefresh_Click); // Обробник події для кнопки

        // Розташування кнопки (праворуч від головного меню)
        int menuRight = this->mainMenuStrip->Location.X + this->mainMenuStrip->Width; // Права границя головного меню
        int menuTop = this->mainMenuStrip->Location.Y; // Верхня границя головного меню
        int btnWidth = 40; // Ширина кнопки
        int btnHeight = 20; // Висота кнопки
        this->btnRefresh->Location = System::Drawing::Point(350,0);

        // Додавання кнопки до контейнера
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
        // Налаштування властивостей ListView
        this->listViewProcesses->View = System::Windows::Forms::View::Details; // Вид в режимі деталей
        this->listViewProcesses->Dock = System::Windows::Forms::DockStyle::Fill; // Займає весь доступний простір
        this->listViewProcesses->GridLines = true; // Показувати лінії між стовпцями
        this->listViewProcesses->FullRowSelect = true; // Виділяти повні рядки

        // Додавання стовпців
        this->listViewProcesses->Columns->Add(gcnew System::Windows::Forms::ColumnHeader());
        this->listViewProcesses->Columns[0]->Text = L"Process Name";
        this->listViewProcesses->Columns[0]->Tag = "String"; // Додаткова інформація про тип даних у стовпці

        this->listViewProcesses->Columns->Add(gcnew System::Windows::Forms::ColumnHeader());
        this->listViewProcesses->Columns[1]->Text = L"Process ID";
        this->listViewProcesses->Columns[1]->Tag = "Numeric"; // Додаткова інформація про тип даних у стовпці

        // Додавання нових стовпців
        this->listViewProcesses->Columns->Add(gcnew System::Windows::Forms::ColumnHeader());
        this->listViewProcesses->Columns[2]->Text = L"Memory Usage";
        this->listViewProcesses->Columns[2]->Tag = "Numeric"; // Додаткова інформація про тип даних у стовпці

        this->listViewProcesses->Columns->Add(gcnew System::Windows::Forms::ColumnHeader());
        this->listViewProcesses->Columns[3]->Text = L"Priority";
        this->listViewProcesses->Columns[3]->Tag = "String"; // Додаткова інформація про тип даних у стовпці

        // Додавання обробників подій для сортування стовпців
        for (int i = 0; i < this->listViewProcesses->Columns->Count; i++)
        {
            this->listViewProcesses->Columns[i]->Width = -2; // Автоматична ширина стовпця
            this->listViewProcesses->Columns[i]->Tag = gcnew String("String");
            this->listViewProcesses->ColumnClick += gcnew System::Windows::Forms::ColumnClickEventHandler(this, &MainForm::OnColumnClick);
        }
    
    }
    void MainForm::InitializeMenu()
    {
        // Налаштування головного меню
        this->mainMenuStrip->Location = System::Drawing::Point(0, 0);
        this->mainMenuStrip->Name = L"mainMenuStrip";
        this->mainMenuStrip->Size = System::Drawing::Size(800, 24);
        this->mainMenuStrip->TabIndex = 0;
        this->mainMenuStrip->Text = L"mainMenuStrip";

        // Спочатку оголошуємо головне меню
        this->головнеМенюToolStripMenuItem = gcnew System::Windows::Forms::ToolStripMenuItem();
        this->головнеМенюToolStripMenuItem->Name = L"головнеМенюToolStripMenuItem";
        this->головнеМенюToolStripMenuItem->Size = System::Drawing::Size(180, 22);
        this->головнеМенюToolStripMenuItem->Text = L"Головне меню";
        this->головнеМенюToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::головнеМенюToolStripMenuItem_Click);

        // Додавання елементів до головного меню
        this->mainMenuStrip->Items->Add(this->головнеМенюToolStripMenuItem);

        this->пошукToolStripMenuItem = gcnew System::Windows::Forms::ToolStripMenuItem();
        this->пошукToolStripMenuItem->Name = L"пошукToolStripMenuItem";
        this->пошукToolStripMenuItem->Size = System::Drawing::Size(53, 20);
        this->пошукToolStripMenuItem->Text = L"Пошук";
        this->пошукToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::пошукToolStripMenuItem_Click);

        this->mainMenuStrip->Items->Insert(1, this->пошукToolStripMenuItem);


        // Потім додаємо елемент "Про програму"
        this->проПрограмуToolStripMenuItem = gcnew System::Windows::Forms::ToolStripMenuItem();
        this->проПрограмуToolStripMenuItem->Name = L"проПрограмуToolStripMenuItem";
        this->проПрограмуToolStripMenuItem->Size = System::Drawing::Size(180, 22);
        this->проПрограмуToolStripMenuItem->Text = L"Про застосунок";
        this->проПрограмуToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::проПрограмуToolStripMenuItem_Click);


        // Додавання елементів до головного меню
        this->mainMenuStrip->Items->Add(this->проПрограмуToolStripMenuItem);
    }


    void MainForm::головнеМенюToolStripMenuItem_Click(Object^ sender, EventArgs^ e)
    {
        // Показати або приховати головне меню
        ShowMainMenuForm();
    }


    void MainForm::пошукToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        // Відображення вікна для введення критеріїв пошуку та виконання пошуку
        SearchForm^ searchForm = gcnew SearchForm();
        if (searchForm->ShowDialog() == System::Windows::Forms::DialogResult::OK)
        {
            // Отримання критеріїв пошуку з форми
            String^ searchTerm = searchForm->GetSearchTerm();

            // Виконання пошуку та відображення результатів
            SearchProcesses(searchTerm);
        }
    }
    void MainForm::SearchProcesses(String^ searchTerm)
    {
        // Очищення списку процесів
        listViewProcesses->Items->Clear();

        // Виконання пошуку за заданим критерієм
        // Тут ви можете реалізувати ваш алгоритм пошуку, який відповідає вашим вимогам

        // Наприклад, можна перебрати всі процеси і порівняти їх імена з критерієм пошуку
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
                    // Додаткова обробка інформації про процес та додавання його до списку
                    listViewProcesses->Items->Add(item);
                }
            } while (Process32Next(hProcessSnap, &pe32));
        }

        CloseHandle(hProcessSnap);
    }

    void MainForm::listViewProcesses_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
    {
        // Перевірка, чи була натиснута ліва кнопка миші двічі
        if (e->Button == System::Windows::Forms::MouseButtons::Left && e->Clicks == 2)
        {
            // Отримання виділеного елемента списку
            ListViewItem^ selectedItem = listViewProcesses->GetItemAt(e->X, e->Y);
            if (selectedItem != nullptr)
            {
                // Отримання ID вибраного процесу
                String^ processID = selectedItem->SubItems[1]->Text;
                int pid = Convert::ToInt32(processID);

                // Перевірка, чи процес існує
                HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, pid);
                if (hProcess != NULL)
                {
                    // Відображення діалогового вікна для підтвердження закриття процесу
                    if (MessageBox::Show("Бажаєте закрити цей процес?", "Підтвердження", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
                    {
                        // Завершення процесу
                        TerminateProcess(hProcess, 0);
                    }
                    CloseHandle(hProcess);
                }
                else
                {
                    MessageBox::Show("Не вдалося знайти процес.", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
                }

                // Оновлення списку процесів після закриття або оновлення процесу
                DisplayProcessList();
            }
        }
    }


    // Оновлений метод DisplayProcessList
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

            // Отримання інформації про пам'ять, яку займає процес
            PROCESS_MEMORY_COUNTERS pmc;
            HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pe32.th32ProcessID);
            if (hProcess != NULL && GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)))
            {
                // Конвертуємо байти в мегабайти
                float memoryInMB = static_cast<float>(pmc.WorkingSetSize) / (1024 * 1024);
                item->SubItems->Add(memoryInMB.ToString("N2")); // Виводимо до двох знаків після коми
            }
            else
            {
                item->SubItems->Add("N/A");
            }
            CloseHandle(hProcess);

            // Отримання пріоритету процесу
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

        // Визначення порядку сортування (зростаючий або спадаючий)
        if (lv->Sorting == SortOrder::Ascending || lv->Sorting == SortOrder::None)
        {
            lv->Sorting = SortOrder::Descending;
        }
        else
        {
            lv->Sorting = SortOrder::Ascending;
        }

        // Створення екземпляра класу ListViewItemComparer і передача його у властивість ListViewItemSorter
        lv->ListViewItemSorter = gcnew ListViewItemComparer(e->Column, lv->Sorting);
        lv->Sort();
    }
 
    // Конструктор класу ListViewItemComparer
    ListViewItemComparer::ListViewItemComparer(int column, SortOrder order) : col(column), order(order) {}

    // Метод порівняння елементів для сортування ListView
    int ListViewItemComparer::Compare(System::Object^ x, System::Object^ y)
    {
        ListViewItem^ lx = (ListViewItem^)x;
        ListViewItem^ ly = (ListViewItem^)y;

        // Порівняння за типом даних
        if (lx->ListView->Columns[col]->Tag->ToString() == "Numeric")
        {
            // Порівняння якщо тип даних числовий
            return Decimal::Compare(Decimal::Parse(lx->SubItems[col]->Text), Decimal::Parse(ly->SubItems[col]->Text)) * (order == SortOrder::Ascending ? 1 : -1);
        }
        else
        {
            // Порівняння якщо тип даних рядковий
            return String::Compare(lx->SubItems[col]->Text, ly->SubItems[col]->Text) * (order == SortOrder::Ascending ? 1 : -1);
        }
    }


    void MainForm::MainForm_Load(System::Object^ sender, System::EventArgs^ e)
    {
        DisplayProcessList();
    }



    void MainForm::listViewProcesses_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
    {
        // Перевірка, чи була натиснута права кнопка миші
        if (e->Button == System::Windows::Forms::MouseButtons::Right)
        {
            // Отримання виділеного елемента списку
            ListViewItem^ selectedItem = listViewProcesses->GetItemAt(e->X, e->Y);
            if (selectedItem != nullptr)
            {
                // Отримання інформації про процес
                String^ processName = selectedItem->SubItems[0]->Text; // Назва процесу
                String^ processID = selectedItem->SubItems[1]->Text; // ID процесу

                // Відкриття процесу для отримання інформації
                HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, Convert::ToInt32(processID));
                if (hProcess != NULL)
                {
                    // Отримання шляху до виконуваного файлу процесу
                    wchar_t path[MAX_PATH];
                    DWORD pathLength = GetModuleFileNameEx(hProcess, NULL, path, MAX_PATH);
                    CloseHandle(hProcess);

                    if (pathLength != 0)
                    {
                        // Конвертація шляху до виконуваного файлу в рядок .NET
                        String^ processLocation = gcnew String(path);

                        // Отримання часу запуску процесу
                        FILETIME creationTime, exitTime, kernelTime, userTime;
                        GetProcessTimes(hProcess, &creationTime, &exitTime, &kernelTime, &userTime);
                        SYSTEMTIME utcSystemTime, localSystemTime;
                        FileTimeToSystemTime(&creationTime, &utcSystemTime);
                        SystemTimeToTzSpecificLocalTime(NULL, &utcSystemTime, &localSystemTime);
                        System::DateTime startTime(localSystemTime.wYear, localSystemTime.wMonth, localSystemTime.wDay,
                            localSystemTime.wHour, localSystemTime.wMinute, localSystemTime.wSecond,
                            localSystemTime.wMilliseconds);
                        String^ startTimeString = startTime.ToString();

                        // Створення повідомлення з інформацією про процес
                        String^ message = "Process Name: " + processName + "\n"
                            + "Process ID: " + processID + "\n"
                            + "Location: " + processLocation + "\n"
                            + "Start Time: " + startTimeString;

                        // Відображення повідомлення
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