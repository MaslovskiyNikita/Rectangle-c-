/*. Создать класс четырехугольник, члены класса – координаты четырех точек.
Предусмотреть в классе методы проверки существования четырехугольника вычисления и вывода сведений о фигуре
– длины сторон, диагоналей, периметр, площадь. Создать производный класс – параллелограмм, предусмотреть в классе проверку,
является ли фигура параллелограммом. Написать программу, демонстрирующую работу с классом: 
дано N четырехугольников и M параллелограммов, найти среднюю площадь N четырехугольников
и параллелограммы наименьшей и наибольшей площади.*/

#include <iostream>
#include <cmath>
#include "Point2.h"
#include "Rectangle.h"
#include "Parallelogram.h"




int main() {
    int N, M;
    double sumAreaRectangles = 0;
    double minAreaParallelogram = 0;
    double maxAreaParallelogram = 0;

    setlocale(LC_ALL, "rus");

    Rectangle* rectangles = nullptr;
    Parallelogram* parallelograms = nullptr;

    int choice;
    do {
        std::cout << "Меню:" << std::endl;
        std::cout << "1. Просмотр текущего состояния объектов" << std::endl;
        std::cout << "2. Создание объектов" << std::endl;
        std::cout << "3. Выход" << std::endl;
        std::cout << "Выберите пункт меню: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            if (rectangles != nullptr && parallelograms != nullptr) {
                std::cout << "Средняя площадь четырехугольников: " << sumAreaRectangles / N << std::endl;
                std::cout << "Наименьшая площадь параллелограмма: " << minAreaParallelogram << std::endl;
                std::cout << "Наибольшая площадь параллелограмма: " << maxAreaParallelogram << std::endl;
                for (int i = 0; i < N; ++i) {
                    std::cout << "===============================" << std::endl;
                    std::cout << "Четырехугольник " << i + 1 << ":" << std::endl;
                    std::cout << "Длина сторон: " << rectangles[i].GetTopSide() << ", " << rectangles[i].GetLeftSide() << ", " << rectangles[i].GetBottomSide() << ", " << rectangles[i].GetRightSide() << std::endl;
                    std::cout << "Площадь: " << rectangles[i].GetArea() << std::endl;
                    std::cout << "Периметр: " << rectangles[i].GetPerimetr() << std::endl;
                    std::cout << std::endl;
                }
                for (int i = 0; i < M; ++i) {
                    std::cout << "Параллелограмм " << i + 1 << ":" << std::endl;
                    std::cout << "Длина сторон: " << parallelograms[i].GetTopSide() << ", " << parallelograms[i].GetLeftSide() << ", " << parallelograms[i].GetBottomSide() << ", " << parallelograms[i].GetRightSide() << std::endl;
                    std::cout << "Площадь: " << parallelograms[i].GetArea() << std::endl;
                    std::cout << "Периметр: " << parallelograms[i].GetPerimetr() << std::endl;
                    std::cout << std::endl;
                }
            }
            else {
                std::cout << "Объекты не созданы." << std::endl;
            }
            break;
        }
        case 2: {
            std::cout << "Введите количество четырехугольников (N): ";
            std::cin >> N;
            std::cout << "Введите количество параллелограммов (M): ";
            std::cin >> M;

            rectangles = new Rectangle[N];
            parallelograms = new Parallelogram[M];

            for (int i = 0; i < N; ++i) {
                double x1, y1, x2, y2, x3, y3, x4, y4;
                std::cout << "Введите координаты четырехугольника " << i + 1 << ":\n";
                std::cout << "x1 y1: ";
                std::cin >> x1 >> y1;
                std::cout << "x2 y2: ";
                std::cin >> x2 >> y2;
                std::cout << "x3 y3: ";
                std::cin >> x3 >> y3;
                std::cout << "x4 y4: ";
                std::cin >> x4 >> y4;

                rectangles[i] = Rectangle(Point2(x1, y1), Point2(x2, y2), Point2(x3, y3), Point2(x4, y4));
                if (rectangles[i].isValid()) {
                    sumAreaRectangles += rectangles[i].GetArea();
                }
                else {
                    std::cout << "Введенный четырехугольник не является четырехугольником." << std::endl;
                }
            }

            for (int i = 0; i < M; ++i) {
                double x1, y1, x2, y2, x3, y3, x4, y4;
                std::cout << "Введите координаты параллелограмма " << i + 1 << ":\n";
                std::cout << "x1 y1: ";
                std::cin >> x1 >> y1;
                std::cout << "x2 y2: ";
                std::cin >> x2 >> y2;
                std::cout << "x3 y3: ";
                std::cin >> x3 >> y3;
                std::cout << "x4 y4: ";
                std::cin >> x4 >> y4;

                parallelograms[i] = Parallelogram(Point2(x1, y1), Point2(x2, y2), Point2(x3, y3), Point2(x4, y4));
                if (parallelograms[i].isValid() && parallelograms[i].isParallelogram()) {
                    if (i == 0) {
                        minAreaParallelogram = parallelograms[i].GetArea();
                        maxAreaParallelogram = parallelograms[i].GetArea();
                    }
                    else {
                        if (parallelograms[i].GetArea() < minAreaParallelogram) {
                            minAreaParallelogram = parallelograms[i].GetArea();
                        }
                        if (parallelograms[i].GetArea() > maxAreaParallelogram) {
                            maxAreaParallelogram = parallelograms[i].GetArea();
                        }
                    }
                }
                else {
                    std::cout << "Введенный параллелограмм не является параллелограммом ." << std::endl;
                }
            }
            break;
        }
        case 3: {
            delete[] rectangles;
            delete[] parallelograms;
            rectangles = nullptr;
            parallelograms = nullptr;
            std::cout << "Выход из программы." << std::endl;
            return 0;
        }
        default: {
            std::cout << "Неправильный выбор. Пожалуйста, выберите еще раз." << std::endl;
        }
        }
    } while (true);
    return 0;
}