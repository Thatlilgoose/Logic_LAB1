#include "lab_tasks.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <limits>
#include <windows.h>
#include <cstdlib>
#include <ctime>   




static std::string toLowerRu(std::string str) {
    for (char& c : str) {
        c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    }
    return str;
}



// Задание 1: Разница между MAX и MIN
void runTask1() {
    std::cout << "--- Задание 1: Разница max и min ---\n\n";
    std::vector<int> numbers = { 15, 3, 42, -7, 88, 10, 0, 24 };

    std::cout << "Исходный массив: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    int min_val = *std::min_element(numbers.begin(), numbers.end());
    int max_val = *std::max_element(numbers.begin(), numbers.end());

    std::cout << "Минимальный элемент: " << min_val << "\n";
    std::cout << "Максимальный элемент: " << max_val << "\n";
    std::cout << "Разница (Max - Min): " << max_val - min_val << "\n";
}


// Задание 2: Массив со случайными числами

void runTask2() {
    std::cout << "--- Задание 2: Случайные числа ---\n\n";

    const int size = 10;
    std::vector<int> arr(size);

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    
    for (int i = 0; i < size; ++i) {
        arr[i] = 1 + std::rand() % 100;
    }

    std::cout << "Сгенерированный массив: ";
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

// Задание 3: Массив динамического размера
void runTask3() {
    std::cout << "--- Задание 3: Динамический массив ---\n\n";
    int size = 0;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    while (true) {
        std::cout << "Введите размер массива (положительное целое число): ";
        if (std::cin >> size && size > 0) {
            break;
        }
        std::cout << "Ошибка: введено нечисловое или не положительное значение! Попробуйте снова.\n";
        std::cin.clear();
        std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    }

    int* dynamicArray = new int[size];


    for (int i = 0; i < size; ++i) {
        dynamicArray[i] = 1 + std::rand() % 100;
    }


    std::cout << "\nВведенный динамический массив: ";
    for (int i = 0; i < size; ++i) {
        std::cout << dynamicArray[i] << " ";
    }
    std::cout << "\n";
    delete dynamicArray;
}


// Задание 4: Суммы строк и столбцов матрицы
void runTask4() {
    std::cout << "--- Задание 4: Суммы и ненулевые элементы в двумерном массиве ---\n\n";

    const int rows = 3;
    const int cols = 4;

    
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    

    // 2. Заполнение матрицы случайными числами
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = -10 + std::rand() % 21;
        }
    }

    // 3. Вывод матрицы на экран
    std::cout << "Сгенерированная матрица:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }

    // 4. Подсчёт количества ненулевых элементов
    int nonZeroCount = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] != 0) {
                nonZeroCount++;
            }
        }
    }
    std::cout << "\nКоличество ненулевых элементов: " << nonZeroCount << "\n";

    // 5. Расчёт сумм по строкам
    std::cout << "\nСуммы по строкам:\n";
    for (int i = 0; i < rows; ++i) {
        int rowSum = 0;
        for (int j = 0; j < cols; ++j) {
            rowSum += matrix[i][j];
        }
        std::cout << "Строка " << i << ": " << rowSum << "\n";
    }

    // 6. Расчёт сумм по столбцам
    std::cout << "\nСуммы по столбцам:\n";
    for (int j = 0; j < cols; ++j) {
        int colSum = 0;
        for (int i = 0; i < rows; ++i) {
            colSum += matrix[i][j];
        }
        std::cout << "Столбец " << j << ": " << colSum << "\n";
    }

    // 7. Освобождение выделенной памяти
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i]; // Освобождаем каждую строку
    }
    delete[] matrix; // Освобождаем массив указателей
}


// Задание 5: Поиск студента

// Структура узла односвязного списка
struct StudentNode {
    std::string surname;
    std::string name;
    std::string thirdname;
    std::string faculty;

    StudentNode* next = nullptr;
};

static StudentNode* g_head = nullptr;
static StudentNode* g_tail = nullptr;


static void clearStudentList() {
    StudentNode* current = g_head;
    while (current != nullptr) {
        StudentNode* temp = current;
        current = current->next;
        delete temp;
    }
    g_head = nullptr;
    g_tail = nullptr;
}


static void addStudents() {
    std::cout << "\n--- Ввод данных (для окончания введите '*' вместо фамилии) ---\n";
    while (true) {
        std::string inputSurname;
        std::cout << "\nФамилия (или '*'): ";
        std::cin >> inputSurname;

        if (inputSurname == "*") {
            break;
        }

        StudentNode* newNode = new StudentNode();
        newNode->surname = inputSurname;

        std::cout << "Имя: ";
        std::cin >> newNode->name;
        std::cout << "Отчество: ";
        std::cin >> newNode->thirdname;
        std::cout << "Факультет: ";
        std::cin >> newNode->faculty;

      
        if (g_head == nullptr) {
            g_head = newNode;
            g_tail = newNode;
        }
        else {
            g_tail->next = newNode;
            g_tail = newNode;
        }
        std::cout << "Студент добавлен!\n";
    }
}


static void printStudentList() {
    if (g_head == nullptr) {
        std::cout << "\nСписок студентов пуст.\n";
        return;
    }

    std::cout << "\n================ СОХРАНЁННЫЙ СПИСОК ================\n";
    StudentNode* current = g_head;
    int index = 1;
    while (current != nullptr) {
        std::cout << index++ << ". " << current->surname << " "
            << current->name << " " << current->thirdname
            << " | Факультет: " << current->faculty << "\n";
        current = current->next;
    }
    std::cout << "====================================================\n";
}


static void searchInList() {
    if (g_head == nullptr) {
        std::cout << "\nСписок пуст, поиск невозможен. Сначала добавьте студентов.\n";
        return;
    }

    std::string searchQuery;
    std::cout << "\nВведите подстроку для поиска: ";
    std::cin >> searchQuery;

    std::string queryLower = toLowerRu(searchQuery);
    bool found = false;

    std::cout << "\nРезультаты поиска:\n";
    StudentNode* current = g_head;
    while (current != nullptr) {
        std::string sSurname = toLowerRu(current->surname);
        std::string sName = toLowerRu(current->name);
        std::string sThirdname = toLowerRu(current->thirdname);
        std::string sFaculty = toLowerRu(current->faculty);

        if (sSurname.find(queryLower) != std::string::npos ||
            sName.find(queryLower) != std::string::npos ||
            sThirdname.find(queryLower) != std::string::npos ||
            sFaculty.find(queryLower) != std::string::npos)
        {
            std::cout << "-> " << current->surname << " " << current->name << " "
                << current->thirdname << " | Факультет: " << current->faculty << "\n";
            found = true;
        }
        current = current->next;
    }

    if (!found) {
        std::cout << "Записи с подстрокой \"" << searchQuery << "\" не найдены.\n";
    }
}


void runTask5() {
#if defined(_WIN32) || defined(_WIN64)
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif

    while (true) {
        std::cout << "\n--- Задание 5: База данных студентов (Список) ---\n";
        std::cout << "1. Добавить студентов в список (до символа '*')\n";
        std::cout << "2. Показать весь сохранённый список\n";
        std::cout << "3. Поиск по неполному совпадению\n";
        std::cout << "4. Полностью очистить список\n";
        std::cout << "0. Вернуться в главное меню\n";
        std::cout << "Выберите действие: ";

        int choice;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
            std::cout << "Некорректный ввод!\n";
            continue;
        }

        if (choice == 0) break;

        switch (choice) {
        case 1:
            addStudents();
            break;
        case 2:
            printStudentList();
            break;
        case 3:
            searchInList();
            break;
        case 4:
            clearStudentList();
            std::cout << "\nСписок успешно очищен.\n";
            break;
        default:
            std::cout << "Неверный пункт меню.\n";
            break;
        }
    }
}