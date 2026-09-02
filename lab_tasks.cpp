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

    // Цикл повторного запроса при неверном вводе размера
    while (true) {
        std::cout << "Введите размер массива (положительное целое число): ";
        if (std::cin >> size && size > 0) {
            break; // Ввод корректен
        }
        std::cout << "Ошибка: введено нечисловое или не положительное значение! Попробуйте снова.\n";
        std::cin.clear();
        std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    }

    std::vector<int> dynamicArray(size);

    std::cout << "\nВведите " << size << " целых чисел:\n";
    for (int i = 0; i < size; ++i) {
        while (true) {
            std::cout << "Элемент [" << i << "]: ";
            if (std::cin >> dynamicArray[i]) {
                break;
            }
            std::cout << "Ошибка: нужно ввести целое число!\n";
            std::cin.clear();
            std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
        }
    }

    std::cout << "\nВведенный динамический массив: ";
    for (int val : dynamicArray) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}


// Задание 4: Суммы строк и столбцов матрицы
void runTask4() {
    std::cout << "--- Задание 4: Суммы в двумерном массиве ---\n\n";
    const int rows = 3;
    const int cols = 4;

    std::vector<std::vector<int>> matrix = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12}
    };

    std::cout << "Исходная матрица:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }

    std::cout << "\nСуммы по строкам:\n";
    for (int i = 0; i < rows; ++i) {
        int rowSum = 0;
        for (int j = 0; j < cols; ++j) {
            rowSum += matrix[i][j];
        }
        std::cout << "Строка " << i << ": " << rowSum << "\n";
    }

    std::cout << "\nСуммы по столбцам:\n";
    for (int j = 0; j < cols; ++j) {
        int colSum = 0;
        for (int i = 0; i < rows; ++i) {
            colSum += matrix[i][j];
        }
        std::cout << "Столбец " << j << ": " << colSum << "\n";
    }
}


// Задание 5: Поиск студента
struct Student {
    std::string surname;
    std::string name;
    std::string thirdname;
    std::string faculty;
    
};

void runTask5() {
#if defined(_WIN32) || defined(_WIN64)
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif

    std::cout << "--- Задание 5: Поиск студента ---\n\n";

    std::vector<Student> students = {
        {"Иванов", "Иван", "Иванович", "ФВТ",},
        {"Петров", "Петр", "Петрович", "ФИТЕ",},
        {"Сидоров", "Алексей", "Алексеевич", "ЛЕЧФАК",},
        {"Иванова", "Мария", "Фёдоровна", "Физфак",}
    };

    std::string searchQuery;
    std::cout << "Введите параметр для поиска (Фамилию, Имя, Отчество, Факультет): ";
    std::cin >> searchQuery;

    std::string queryLower = toLowerRu(searchQuery);
    bool found = false;

    std::cout << "\nРезультаты поиска:\n";
    for (const auto& student : students) {
        std::string sSurname = toLowerRu(student.surname);
        std::string sName = toLowerRu(student.name);
        std::string sThirdname = toLowerRu(student.thirdname);
        std::string sFaculty = toLowerRu(student.faculty);
        

        if (sSurname == queryLower ||
            sName == queryLower ||
            sFaculty == queryLower ||
            sThirdname == queryLower)
        {
            std::cout << "-> " << student.surname << " " << student.name << " " << student.thirdname
                << " | Факультет: " << student.faculty;
            found = true;
        }
    }

    if (!found) {
        std::cout << "Студент с параметром \"" << searchQuery << "\" не найден.\n"; 
    }
}