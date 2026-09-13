#include <iostream>
#include <limits>
#include <cstdlib>
#include "lab_tasks.h"
#include <locale>

void clearScreen() {
    std::system("cls");  
}


void pauseAndClear() {
    std::cout << "\n----------------------------------------\n";
    std::cout << "Нажмите Enter, чтобы вернуться в главное меню...";

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    clearScreen();
}

void printMenu() {
    std::cout << "========================================\n";
    std::cout << "      ЛАБОРАТОРНАЯ РАБОТА №1 (C++)      \n";
    std::cout << "========================================\n";
    std::cout << "1. Задание 1: Разница между max и min элементами\n";
    std::cout << "2. Задание 2: Массив со случайными числами\n";
    std::cout << "3. Задание 3: Массив динамического размера\n";
    std::cout << "4. Задание 4: Суммы строк и столбцов матрицы\n";
    std::cout << "5. Задание 5: Поиск студента по параметрам\n";
    std::cout << "0. Выход из программы\n";
    std::cout << "========================================\n";
    std::cout << "Выберите пункт меню (1-5): ";
}

int main() {
    setlocale(LC_ALL, "rus");
    int choice = -1;

    clearScreen();

    while (true) {
        printMenu();

        if (!(std::cin >> choice)) {
            std::cout << "\nОшибка ввода! Пожалуйста, введите число.\n";
            std::cin.clear();
            pauseAndClear();
            continue;
        }

        switch (choice) {
        case 1:
            clearScreen();
            runTask1();
            pauseAndClear();
            break;

        case 2:
            clearScreen();
            runTask2();
            pauseAndClear();
            break;

        case 3:
            clearScreen();
            runTask3();
            pauseAndClear();
            break;

        case 4:
            clearScreen();
            runTask4();
            pauseAndClear();
            break;

        case 5:
            clearScreen();
            runTask5();
            pauseAndClear();
            break;

        case 0:
            clearScreen();
            std::cout << "Завершение работы программы. До свидания!\n";
            return 0;

        default:
            std::cout << "\nНекорректный пункт! Выберите число от 0 до 5.\n";
            pauseAndClear();
            break;
        }
    }

    return 0;
}