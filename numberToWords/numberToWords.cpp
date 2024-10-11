#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    setlocale(LC_ALL, "Russian");
    const int size = 1000;
    std::vector<int>arr(size);
    int positiveCount = 0, evenCount = 0;

    std::srand(static_cast<unsigned int>(std::time(0)));

    for (int i = 0; i < size; ++i) {
        arr[i] = std::rand() % 1001 - 500;
    }

    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
        if ((i + 1) % 10 == 0) {
            std::cout << std::endl;
        }
    }

    for (int i = 0; i < size; ++i) {
        int num = arr[i];
        if (num > 0) positiveCount++;
        if (num % 2 == 0) evenCount++;
    }

    std::cout << "кол-во положительных чисел:  " << positiveCount << std::endl;
    std::cout << "кол-во четных чисел: " << evenCount << std::endl;

    std::cout << "пары чисел, сумма которых равна 100:" << std::endl;
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[i] + arr[j] == 100) {
                std::cout << "(" << arr[i] << ", " << arr[j] << ")" << std::endl;
            }
        }
    }

    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }

    std::cout << "Отсортированный массив:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
        if ((i + 1) % 10 == 0) {
            std::cout << std::endl;
        }
    }

    return 0;
}


//#include <iostream>
//#include "numberToWord.h"
//int main()
//{
//    setlocale(LC_ALL, "Russian");
//    int a{ 0 };
//    for (size_t i = 0; i < 20; i++)
//    {
//        std::cout << getUnitsAsWord(i, a) << "\n";
//    }
//    
//}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
