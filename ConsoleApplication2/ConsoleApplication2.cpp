#include <iostream>
#include <cmath>
#include <limits> // Для проверки ввода

using namespace std;

// Функция для вычисления площади поверхности цилиндра
double calculateCylinderSurfaceArea(double radius, double height) {
    const double PI = 3.141592653589793;
    double baseArea = PI * radius * radius;       // Площадь основания
    double lateralArea = 2 * PI * radius * height; // Боковая поверхность
    return 2 * baseArea + lateralArea;            // Полная площадь
}

// Функция для ввода положительных значений
double getPositiveInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        // Проверка ввода
        if (cin.fail() || value <= 0) {
            cin.clear(); // Сбрасываем ошибку состояния
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер ввода
            cout << "Ошибка: введите положительное число.\n";
        }
        else {
            return value; // Корректное значение
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Программа для вычисления площади поверхности цилиндра.\n";

    // Ввод радиуса и высоты с проверкой
    double radius = getPositiveInput("Введите радиус основания цилиндра (положительное число): ");
    double height = getPositiveInput("Введите высоту цилиндра (положительное число): ");

    // Вычисление площади поверхности
    double surfaceArea = calculateCylinderSurfaceArea(radius, height);

    // Вывод результата
    cout << "Площадь поверхности цилиндра: " << surfaceArea << " квадратных единиц.\n";

    // Задержка перед закрытием окна
    cout << "Нажмите Enter для завершения программы...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер
    cin.get(); // Ждем ввода
    return 0;
}
