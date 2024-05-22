#include <iostream>
#include <limits> 
#include <stdio.h>
#include <vector>
#include <string>
#define NOMINMAX
#include <Windows.h>
#include <random>
#include <cmath>
#include <map>




std::random_device rd; // Инициализация генератора случайных чисел
#define ID_NEW_GAME_BUTTON 15001
#define ID_EXIT_BUTTON 15002
// В глобальной области видимости объявляем идентификатор таймера
#define IDT_TIMER1 1

int height = 1023;
int width = 660;
int Score = 0;
bool StopGame = false;


// Определяем структуру Point
struct Point {
    int x;
    int y;

    // Конструктор для удобного создания точек
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Методы-сеттеры для изменения координат
    void setX(int newX) { x = newX; }
    void setY(int newY) { y = newY; }
};



// Определяем класс Tetromino
class Tetromino {
private:
    std::vector<Point> pointsRect1;
    std::vector<Point> pointsRect2;
    std::vector<Point> pointsRect3;
    std::vector<Point> pointsRect4;

public:
    Tetromino() {}

    // Конструктор
    Tetromino(const std::vector<Point>& pointsRect1, const std::vector<Point>& pointsRect2,
        const std::vector<Point>& pointsRect3, const std::vector<Point>& pointsRect4)
        : pointsRect1(pointsRect1), pointsRect2(pointsRect2), pointsRect3(pointsRect3), pointsRect4(pointsRect4) {}

    // Конструктор копирования
    Tetromino(const Tetromino& other)
        : pointsRect1(other.pointsRect1), pointsRect2(other.pointsRect2),
        pointsRect3(other.pointsRect3), pointsRect4(other.pointsRect4) {}

    // Перегрузка оператора присваивания
    Tetromino& operator=(const Tetromino& other) {
        if (this == &other) {
            return *this; // Проверка на самоприсваивание
        }
        pointsRect1 = other.pointsRect1;
        pointsRect2 = other.pointsRect2;
        pointsRect3 = other.pointsRect3;
        pointsRect4 = other.pointsRect4;
        return *this;
    }

    // Методы для доступа к точкам (геттеры)
    const std::vector<Point>& getPointsRect1() const { return pointsRect1; }
    const std::vector<Point>& getPointsRect2() const { return pointsRect2; }
    const std::vector<Point>& getPointsRect3() const { return pointsRect3; }
    const std::vector<Point>& getPointsRect4() const { return pointsRect4; }

    // Методы для изменения точек (сеттеры)
    void setPointsRect1(const std::vector<Point>& points) { pointsRect1 = points; }
    void setPointsRect2(const std::vector<Point>& points) { pointsRect2 = points; }
    void setPointsRect3(const std::vector<Point>& points) { pointsRect3 = points; }
    void setPointsRect4(const std::vector<Point>& points) { pointsRect4 = points; }
};


static class  TetrominoFactory
{
public: static   Tetromino CreateFig1()
{
    Point p1 = Point(0, 0);
    Point p2 = Point(10, 0);
    Point p3 = Point(10, 10);
    Point p4 = Point(0, 10);

    Point p5 = Point(11, 0);
    Point p6 = Point(21, 0);
    Point p7 = Point(21, 10);
    Point p8 = Point(11, 10);

    Point p9 = Point(22, 0);
    Point p10 = Point(32, 0);
    Point p11 = Point(32, 10);
    Point p12 = Point(22, 10);

    Point p13 = Point(33, 0);
    Point p14 = Point(43, 0);
    Point p15 = Point(43, 10);
    Point p16 = Point(33, 10);

    return  Tetromino({ p1, p2, p3, p4 }, { p5, p6, p7, p8 }, { p9, p10, p11, p12 }, { p13, p14, p15, p16 });
}

public: static Tetromino CreateFig2()
{
    Point p1 = Point(0, 0);
    Point p2 = Point(10, 0);
    Point p3 = Point(10, 10);
    Point p4 = Point(0, 10);

    Point p5 = Point(11, 0);
    Point p6 = Point(21, 0);
    Point p7 = Point(21, 10);
    Point p8 = Point(11, 10);

    Point p9 = Point(22, 0);
    Point p10 = Point(32, 0);
    Point p11 = Point(32, 10);
    Point p12 = Point(22, 10);

    Point p13 = Point(22, 11);
    Point p14 = Point(32, 11);
    Point p15 = Point(32, 21);
    Point p16 = Point(22, 21);

    return  Tetromino({ p1, p2, p3, p4 }, { p5, p6, p7, p8 }, { p9, p10, p11, p12 }, { p13, p14, p15, p16 });
}

public:  static  Tetromino CreateFig3()
{
    Point p1 = Point(0, 0);
    Point p2 = Point(10, 0);
    Point p3 = Point(10, 10);
    Point p4 = Point(0, 10);

    Point p5 = Point(11, 0);
    Point p6 = Point(21, 0);
    Point p7 = Point(21, 10);
    Point p8 = Point(11, 10);

    Point p9 = Point(22, 0);
    Point p10 = Point(32, 0);
    Point p11 = Point(32, 10);
    Point p12 = Point(22, 10);

    Point p13 = Point(0, 11);
    Point p14 = Point(10, 11);
    Point p15 = Point(10, 21);
    Point p16 = Point(0, 21);

    return  Tetromino({ p1, p2, p3, p4 }, { p5, p6, p7, p8 }, { p9, p10, p11, p12 }, { p13, p14, p15, p16 });
}
public:   static    Tetromino CreateFig4()
{
    Point p1 = Point(0, 0);
    Point p2 = Point(10, 0);
    Point p3 = Point(10, 10);
    Point p4 = Point(0, 10);

    Point p5 = Point(11, 0);
    Point p6 = Point(21, 0);
    Point p7 = Point(21, 10);
    Point p8 = Point(11, 10);

    Point p9 = Point(22, 0);
    Point p10 = Point(32, 0);
    Point p11 = Point(32, 10);
    Point p12 = Point(22, 10);

    Point p13 = Point(11, 11);
    Point p14 = Point(21, 11);
    Point p15 = Point(21, 21);
    Point p16 = Point(11, 21);

    return  Tetromino({ p1, p2, p3, p4 }, { p5, p6, p7, p8 }, { p9, p10, p11, p12 }, { p13, p14, p15, p16 });
}
public:   static   Tetromino CreateFig5()
{
    Point p1 = Point(0, 0);
    Point p2 = Point(10, 0);
    Point p3 = Point(10, 10);
    Point p4 = Point(0, 10);

    Point p5 = Point(11, 0);
    Point p6 = Point(21, 0);
    Point p7 = Point(21, 10);
    Point p8 = Point(11, 10);

    Point p9 = Point(0, 11);
    Point p10 = Point(10, 11);
    Point p11 = Point(10, 21);
    Point p12 = Point(0, 21);

    Point p13 = Point(11, 11);
    Point p14 = Point(21, 11);
    Point p15 = Point(21, 21);
    Point p16 = Point(11, 21);

    return  Tetromino({ p1, p2, p3, p4 }, { p5, p6, p7, p8 }, { p9, p10, p11, p12 }, { p13, p14, p15, p16 });
}
public: static   Tetromino CreateFig6()
{
    Point p1 = Point(0, 0);
    Point p2 = Point(10, 0);
    Point p3 = Point(10, 10);
    Point p4 = Point(0, 10);

    Point p5 = Point(11, 0);
    Point p6 = Point(21, 0);
    Point p7 = Point(21, 10);
    Point p8 = Point(11, 10);

    Point p9 = Point(11, 11);
    Point p10 = Point(21, 11);
    Point p11 = Point(21, 21);
    Point p12 = Point(11, 21);

    Point p13 = Point(22, 11);
    Point p14 = Point(32, 11);
    Point p15 = Point(32, 21);
    Point p16 = Point(22, 21);

    return  Tetromino({ p1, p2, p3, p4 }, { p5, p6, p7, p8 }, { p9, p10, p11, p12 }, { p13, p14, p15, p16 });
}
public:   static  Tetromino CreateFig7()
{
    Point p1 = Point(11, 0);
    Point p2 = Point(21, 0);
    Point p3 = Point(21, 10);
    Point p4 = Point(11, 10);

    Point p5 = Point(22, 0);
    Point p6 = Point(32, 0);
    Point p7 = Point(32, 10);
    Point p8 = Point(22, 10);

    Point p9 = Point(0, 11);
    Point p10 = Point(10, 11);
    Point p11 = Point(10, 21);
    Point p12 = Point(0, 21);

    Point p13 = Point(11, 11);
    Point p14 = Point(21, 11);
    Point p15 = Point(21, 21);
    Point p16 = Point(11, 21);

    return  Tetromino({ p1, p2, p3, p4 }, { p5, p6, p7, p8 }, { p9, p10, p11, p12 }, { p13, p14, p15, p16 });
}

public:  static  Tetromino CreateFig1_1()
{
    Point p1 = Point(0, 0);
    Point p2 = Point(10, 0);
    Point p3 = Point(10, 10);
    Point p4 = Point(0, 10);

    Point p5 = Point(0, 11);
    Point p6 = Point(10, 11);
    Point p7 = Point(10, 21);
    Point p8 = Point(0, 21);

    Point p9 = Point(0, 22);
    Point p10 = Point(10, 22);
    Point p11 = Point(10, 32);
    Point p12 = Point(0, 32);

    Point p13 = Point(0, 33);
    Point p14 = Point(10, 33);
    Point p15 = Point(10, 43);
    Point p16 = Point(0, 43);

    return  Tetromino({ p1, p2, p3, p4 }, { p5, p6, p7, p8 }, { p9, p10, p11, p12 }, { p13, p14, p15, p16 });
}

public:  static   Tetromino CreateFig2_1()
{
    Point p1 = Point(11, 0);
    Point p2 = Point(21, 0);
    Point p3 = Point(21, 10);
    Point p4 = Point(11, 10);

    Point p5 = Point(11, 11);
    Point p6 = Point(21, 11);
    Point p7 = Point(21, 21);
    Point p8 = Point(11, 21);

    Point p9 = Point(11, 22);
    Point p10 = Point(21, 22);
    Point p11 = Point(21, 32);
    Point p12 = Point(11, 32);

    Point p13 = Point(0, 22);
    Point p14 = Point(10, 22);
    Point p15 = Point(10, 32);
    Point p16 = Point(0, 32);

    return  Tetromino({ p1, p2, p3, p4 }, { p5, p6, p7, p8 }, { p9, p10, p11, p12 }, { p13, p14, p15, p16 });
}


public:  static  Tetromino CreateFig2_2()
{
    Point p1 = Point(0, 11);
    Point p2 = Point(10, 11);
    Point p3 = Point(10, 21);
    Point p4 = Point(0, 21);

    Point p5 = Point(11, 11);
    Point p6 = Point(21, 11);
    Point p7 = Point(21, 21);
    Point p8 = Point(11, 21);

    Point p9 = Point(22, 11);
    Point p10 = Point(32, 11);
    Point p11 = Point(32, 21);
    Point p12 = Point(22, 21);

    Point p13 = Point(0, 0);
    Point p14 = Point(10, 0);
    Point p15 = Point(10, 10);
    Point p16 = Point(0, 10);

    return  Tetromino({ p1, p2, p3, p4 }, { p5, p6, p7, p8 }, { p9, p10, p11, p12 }, { p13, p14, p15, p16 });
}

public:  static Tetromino CreateFig2_3()
{
    Point p1 = Point(0, 0);
    Point p2 = Point(10, 0);
    Point p3 = Point(10, 10);
    Point p4 = Point(0, 10);

    Point p5 = Point(0, 11);
    Point p6 = Point(10, 11);
    Point p7 = Point(10, 21);
    Point p8 = Point(0, 21);

    Point p9 = Point(0, 22);
    Point p10 = Point(10, 22);
    Point p11 = Point(10, 32);
    Point p12 = Point(0, 32);

    Point p13 = Point(11, 0);
    Point p14 = Point(21, 0);
    Point p15 = Point(21, 10);
    Point p16 = Point(11, 10);

    return  Tetromino({ p1, p2, p3, p4 }, { p5, p6, p7, p8 }, { p9, p10, p11, p12 }, { p13, p14, p15, p16 });
}
public:  static  Tetromino CreateFig3_1()
{

    Point p1 = Point(11, 0);
    Point p2 = Point(21, 0);
    Point p3 = Point(21, 10);
    Point p4 = Point(11, 10);

    Point p5 = Point(11, 11);
    Point p6 = Point(21, 11);
    Point p7 = Point(21, 21);
    Point p8 = Point(11, 21);

    Point p9 = Point(11, 22);
    Point p10 = Point(21, 22);
    Point p11 = Point(21, 32);
    Point p12 = Point(11, 32);

    Point p13 = Point(0, 0);
    Point p14 = Point(10, 0);
    Point p15 = Point(10, 10);
    Point p16 = Point(0, 10);

    return  Tetromino({ p1, p2, p3, p4 }, { p5, p6, p7, p8 }, { p9, p10, p11, p12 }, { p13, p14, p15, p16 });
}

public: static   Tetromino CreateFig3_2()
{

    Point p1 = Point(0, 11);
    Point p2 = Point(10, 11);
    Point p3 = Point(10, 21);
    Point p4 = Point(0, 21);

    Point p5 = Point(11, 11);
    Point p6 = Point(21, 11);
    Point p7 = Point(21, 21);
    Point p8 = Point(11, 21);

    Point p9 = Point(22, 11);
    Point p10 = Point(32, 11);
    Point p11 = Point(32, 21);
    Point p12 = Point(22, 21);

    Point p13 = Point(22, 0);
    Point p14 = Point(32, 0);
    Point p15 = Point(32, 10);
    Point p16 = Point(22, 10);

    return  Tetromino({ p1, p2, p3, p4 }, { p5, p6, p7, p8 }, { p9, p10, p11, p12 }, { p13, p14, p15, p16 });
}

public: static   Tetromino CreateFig3_3()
{

    Point p1 = Point(0, 0);
    Point p2 = Point(10, 0);
    Point p3 = Point(10, 10);
    Point p4 = Point(0, 10);

    Point p5 = Point(0, 11);
    Point p6 = Point(10, 11);
    Point p7 = Point(10, 21);
    Point p8 = Point(0, 21);

    Point p9 = Point(0, 22);
    Point p10 = Point(10, 22);
    Point p11 = Point(10, 32);
    Point p12 = Point(0, 32);

    Point p13 = Point(11, 22);
    Point p14 = Point(21, 22);
    Point p15 = Point(21, 32);
    Point p16 = Point(11, 32);


    return  Tetromino({ p1, p2, p3, p4 }, { p5, p6, p7, p8 }, { p9, p10, p11, p12 }, { p13, p14, p15, p16 });
}

public: static  Tetromino CreateFig4_1()
{
    Point p1 = Point(11, 0);
    Point p2 = Point(21, 0);
    Point p3 = Point(21, 10);
    Point p4 = Point(11, 10);

    Point p5 = Point(11, 11);
    Point p6 = Point(21, 11);
    Point p7 = Point(21, 21);
    Point p8 = Point(11, 21);

    Point p9 = Point(11, 22);
    Point p10 = Point(21, 22);
    Point p11 = Point(21, 32);
    Point p12 = Point(11, 32);

    Point p13 = Point(0, 11);
    Point p14 = Point(10, 11);
    Point p15 = Point(10, 21);
    Point p16 = Point(0, 21);

    return  Tetromino({ p1, p2, p3, p4 }, { p5, p6, p7, p8 }, { p9, p10, p11, p12 }, { p13, p14, p15, p16 });
}
public:  static  Tetromino CreateFig4_2()
{
    Point p1 = Point(0, 11);
    Point p2 = Point(10, 11);
    Point p3 = Point(10, 21);
    Point p4 = Point(0, 21);

    Point p5 = Point(11, 11);
    Point p6 = Point(21, 11);
    Point p7 = Point(21, 21);
    Point p8 = Point(11, 21);

    Point p9 = Point(22, 11);
    Point p10 = Point(32, 11);
    Point p11 = Point(32, 21);
    Point p12 = Point(22, 21);

    Point p13 = Point(11, 0);
    Point p14 = Point(21, 0);
    Point p15 = Point(21, 10);
    Point p16 = Point(11, 10);


    return  Tetromino({ p1, p2, p3, p4 }, { p5, p6, p7, p8 }, { p9, p10, p11, p12 }, { p13, p14, p15, p16 });
}

public:  static   Tetromino CreateFig4_3()
{
    Point p1 = Point(0, 0);
    Point p2 = Point(10, 0);
    Point p3 = Point(10, 10);
    Point p4 = Point(0, 10);

    Point p5 = Point(0, 11);
    Point p6 = Point(10, 11);
    Point p7 = Point(10, 21);
    Point p8 = Point(0, 21);

    Point p9 = Point(0, 22);
    Point p10 = Point(10, 22);
    Point p11 = Point(10, 32);
    Point p12 = Point(0, 32);

    Point p13 = Point(11, 11);
    Point p14 = Point(21, 11);
    Point p15 = Point(21, 21);
    Point p16 = Point(11, 21);

    return  Tetromino({ p1, p2, p3, p4 }, { p5, p6, p7, p8 }, { p9, p10, p11, p12 }, { p13, p14, p15, p16 });
}

public: static   Tetromino CreateFig6_1()
{

    Point p1 = Point(11, 0);
    Point p2 = Point(21, 0);
    Point p3 = Point(21, 10);
    Point p4 = Point(11, 10);

    Point p5 = Point(11, 11);
    Point p6 = Point(21, 11);
    Point p7 = Point(21, 21);
    Point p8 = Point(11, 21);

    Point p9 = Point(0, 11);
    Point p10 = Point(10, 11);
    Point p11 = Point(10, 21);
    Point p12 = Point(0, 21);

    Point p13 = Point(0, 22);
    Point p14 = Point(10, 22);
    Point p15 = Point(10, 32);
    Point p16 = Point(0, 32);


    return  Tetromino({ p1, p2, p3, p4 }, { p5, p6, p7, p8 }, { p9, p10, p11, p12 }, { p13, p14, p15, p16 });
}

public:   static Tetromino CreateFig7_1()
{

    Point p1 = Point(0, 0);
    Point p2 = Point(10, 0);
    Point p3 = Point(10, 10);
    Point p4 = Point(0, 10);

    Point p5 = Point(11, 11);
    Point p6 = Point(21, 11);
    Point p7 = Point(21, 21);
    Point p8 = Point(11, 21);

    Point p9 = Point(0, 11);
    Point p10 = Point(10, 11);
    Point p11 = Point(10, 21);
    Point p12 = Point(0, 21);

    Point p13 = Point(11, 22);
    Point p14 = Point(21, 22);
    Point p15 = Point(21, 32);
    Point p16 = Point(11, 32);

    return  Tetromino({ p1, p2, p3, p4 }, { p5, p6, p7, p8 }, { p9, p10, p11, p12 }, { p13, p14, p15, p16 });
}

};

int sizes[] = { 2, 4, 4, 4, 1, 2, 2 };
int scale = 3;
std::vector<Tetromino> Figrnd_out;

std::vector<Tetromino> Figrnd_group;
Tetromino Figrnd{};
int mod = 0;
int current_mod = 0;
std::vector<std::vector<Tetromino>>Figs;
int speed_moveY = 2;


void Scale(int scale, std::vector<std::vector<Tetromino>>& Figs)
{
    // Перебираем все фигуры в массиве Figs
    for (int i = 0; i < Figs.size(); i++)
    {
        std::vector<Tetromino> tetrominos = Figs[i]; // Получаем массив фигур
        int size = sizes[i]; // Получаем размер текущего массива фигур

        // Перебираем каждую фигуру в массиве фигур
        for (int j = 0; j < size; j++)
        {
            Tetromino& tetromino = tetrominos[j]; // Получаем фигуру по ссылке

            // Создаем векторы точек перед циклом
            std::vector<Point> Rect1, Rect2, Rect3, Rect4;

            // Получаем векторы точек перед циклом
            const std::vector<Point>& pointsRect1 = tetromino.getPointsRect1();
            const std::vector<Point>& pointsRect2 = tetromino.getPointsRect2();
            const std::vector<Point>& pointsRect3 = tetromino.getPointsRect3();
            const std::vector<Point>& pointsRect4 = tetromino.getPointsRect4();

            // Перебираем все точки в каждом прямоугольнике фигуры
            for (int k = 0; k < pointsRect1.size(); k++)
            {
                // Масштабируем координаты каждой точки на указанный масштаб
                Rect1.push_back(Point(pointsRect1[k].x * scale, pointsRect1[k].y * scale));
                Rect2.push_back(Point(pointsRect2[k].x * scale, pointsRect2[k].y * scale));
                Rect3.push_back(Point(pointsRect3[k].x * scale, pointsRect3[k].y * scale));
                Rect4.push_back(Point(pointsRect4[k].x * scale, pointsRect4[k].y * scale));
            }

            // Устанавливаем новые векторы точек
            tetromino.setPointsRect1(Rect1);
            tetromino.setPointsRect2(Rect2);
            tetromino.setPointsRect3(Rect3);
            tetromino.setPointsRect4(Rect4);
        }
        Figs[i] = tetrominos;
    }
}

int minYfromOutbyX(const std::vector<Tetromino>& Figrnd_out, int X1)
{
    // Создаем вектор для хранения минимальных значений Y для каждого массива точек
    std::vector<int> minYList;

    // Перебираем все элементы Figrnd_out
    for (const Tetromino& fig : Figrnd_out)
    {
        // Находим минимальное значение Y для каждого массива точек в текущем элементе Figrnd_out
        int aYt1 = std::numeric_limits<int>::max();
        int aYt2 = std::numeric_limits<int>::max();
        int aYt3 = std::numeric_limits<int>::max();
        int aYt4 = std::numeric_limits<int>::max();

        for (const Point& point : fig.getPointsRect1()) {
            if (point.x == X1 && point.y < aYt1) {
                aYt1 = point.y;
            }
        }
        for (const Point& point : fig.getPointsRect2()) {
            if (point.x == X1 && point.y < aYt2) {
                aYt2 = point.y;
            }
        }
        for (const Point& point : fig.getPointsRect3()) {
            if (point.x == X1 && point.y < aYt3) {
                aYt3 = point.y;
            }
        }
        for (const Point& point : fig.getPointsRect4()) {
            if (point.x == X1 && point.y < aYt4) {
                aYt4 = point.y;
            }
        }

        // Находим минимальное значение Y среди найденных значений
        int minY = std::min({ aYt1, aYt2, aYt3, aYt4 });

        // Добавляем найденное минимальное значение Y в вектор
        minYList.push_back(minY);
    }

    // Находим минимальное значение Y среди всех найденных значений
    return *std::min_element(minYList.begin(), minYList.end());
}



bool Moving(Tetromino Figrnd, std::vector<Tetromino> Figrnd_out)
{
    auto X1 = std::min_element(Figrnd.getPointsRect1().begin(), Figrnd.getPointsRect1().end(), [](const Point& a, const Point& b) {
        return a.x < b.x;
        });
    auto Y1 = std::max_element(Figrnd.getPointsRect1().begin(), Figrnd.getPointsRect1().end(), [](const Point& a, const Point& b) {
        return a.y < b.y;
        });
    int Y1min = minYfromOutbyX(Figrnd_out, X1->x);

    auto X2 = std::min_element(Figrnd.getPointsRect2().begin(), Figrnd.getPointsRect2().end(), [](const Point& a, const Point& b) {
        return a.x < b.x;
        });
    auto Y2 = std::max_element(Figrnd.getPointsRect2().begin(), Figrnd.getPointsRect2().end(), [](const Point& a, const Point& b) {
        return a.y < b.y;
        });
    int Y2min = minYfromOutbyX(Figrnd_out, X2->x);

    auto X3 = std::min_element(Figrnd.getPointsRect3().begin(), Figrnd.getPointsRect3().end(), [](const Point& a, const Point& b) {
        return a.x < b.x;
        });
    auto Y3 = std::max_element(Figrnd.getPointsRect3().begin(), Figrnd.getPointsRect3().end(), [](const Point& a, const Point& b) {
        return a.y < b.y;
        });
    int Y3min = minYfromOutbyX(Figrnd_out, X3->x);

    auto X4 = std::min_element(Figrnd.getPointsRect4().begin(), Figrnd.getPointsRect4().end(), [](const Point& a, const Point& b) {
        return a.x < b.x;
        });
    auto Y4 = std::max_element(Figrnd.getPointsRect4().begin(), Figrnd.getPointsRect4().end(), [](const Point& a, const Point& b) {
        return a.y < b.y;
        });
    int Y4min = minYfromOutbyX(Figrnd_out, X4->x);

    if (
        Y1->y + 1 < Y1min &&
        Y2->y + 1 < Y2min &&
        Y3->y + 1 < Y3min &&
        Y4->y + 1 < Y4min
        )
    {
        return true;
    }
    return false;
}


int maxFixY(const Tetromino& Figrnd, int h)
{
    int maxY = 0; // Инициализируем переменную для хранения максимального значения Y

    // Перебираем все массивы точек в объекте Tetromino
    for (const auto& pointsRect : { Figrnd.getPointsRect1(), Figrnd.getPointsRect2(), Figrnd.getPointsRect3(), Figrnd.getPointsRect4() })
    {
        // Перебираем все точки в текущем массиве точек
        for (const auto& point : pointsRect)
        {
            // Обновляем значение maxY, если значение Y текущей точки больше текущего максимального значения maxY
            if (point.y > maxY)
            {
                maxY = point.y;
            }
        }
    }

    maxY = maxY - 10 * scale;

    int delta = h;

    for (int i = 0; i <= h / (11 * scale); i++)
    {
        int d = maxY - i * 11 * scale;
        if (std::abs(d) < std::abs(delta)) { delta = d; }
    }

    return delta;
}




static RECT GetRECT(const std::vector<Point>& points)
{
    RECT rect;
    if (points.size() >= 4) // Проверяем, содержит ли вектор как минимум четыре точки
    {
        rect.left = points[0].x;
        rect.top = points[0].y;
        rect.right = points[2].x;
        rect.bottom = points[2].y;
    }
    else // Если вектор содержит меньше четырех точек, используем значения по умолчанию
    {
        rect.left = 0;
        rect.top = 0;
        rect.right = 0;
        rect.bottom = 0;
    }
    return rect;
}

void DrawTetrominoRects(HDC hdc, Tetromino& tetromino, COLORREF color) {
    HBRUSH hBrush = CreateSolidBrush(color); // Создаем кисть с нужным цветом
    RECT rect1 = GetRECT(tetromino.getPointsRect1());
    FillRect(hdc, &rect1, hBrush);
    RECT rect2 = GetRECT(tetromino.getPointsRect2());
    FillRect(hdc, &rect2, hBrush);
    RECT rect3 = GetRECT(tetromino.getPointsRect3());
    FillRect(hdc, &rect3, hBrush);
    RECT rect4 = GetRECT(tetromino.getPointsRect4());
    FillRect(hdc, &rect4, hBrush);

    //FillRect(hdc, &GetRECT(tetromino.getPointsRect1()), hBrush);
    //FillRect(hdc, &GetRECT(tetromino.getPointsRect2()), hBrush);
    //FillRect(hdc, &GetRECT(tetromino.getPointsRect3()), hBrush);
    //FillRect(hdc, &GetRECT(tetromino.getPointsRect4()), hBrush);
    DeleteObject(hBrush); // Освобождаем ресурсы кисти
}

void MoveXY(Tetromino& t, int deltaX, int deltaY)
{

    // Создаем векторы точек перед циклом
    std::vector<Point> Rect1, Rect2, Rect3, Rect4;

    // Получаем векторы точек перед циклом
    const std::vector<Point>& pointsRect1 = t.getPointsRect1();
    const std::vector<Point>& pointsRect2 = t.getPointsRect2();
    const std::vector<Point>& pointsRect3 = t.getPointsRect3();
    const std::vector<Point>& pointsRect4 = t.getPointsRect4();

    for (int k = 0; k < pointsRect1.size(); k++)
    {
        // Масштабируем координаты каждой точки на указанный масштаб
        Rect1.push_back(Point(pointsRect1[k].x + deltaX, pointsRect1[k].y + deltaY));
        Rect2.push_back(Point(pointsRect2[k].x + deltaX, pointsRect2[k].y + deltaY));
        Rect3.push_back(Point(pointsRect3[k].x + deltaX, pointsRect3[k].y + deltaY));
        Rect4.push_back(Point(pointsRect4[k].x + deltaX, pointsRect4[k].y + deltaY));
    }

    // Устанавливаем новые векторы точек
    t.setPointsRect1(Rect1);
    t.setPointsRect2(Rect2);
    t.setPointsRect3(Rect3);
    t.setPointsRect4(Rect4);
}

void updateRectPoints(Tetromino& fig, int dY) {
    auto pointsRect1 = fig.getPointsRect1();
    for (auto& point : pointsRect1) {
        point.y -= dY;
    }
    fig.setPointsRect1(pointsRect1);

    auto pointsRect2 = fig.getPointsRect2();
    for (auto& point : pointsRect2) {
        point.y -= dY;
    }
    fig.setPointsRect2(pointsRect2);

    auto pointsRect3 = fig.getPointsRect3();
    for (auto& point : pointsRect3) {
        point.y -= dY;
    }
    fig.setPointsRect3(pointsRect3);

    auto pointsRect4 = fig.getPointsRect4();
    for (auto& point : pointsRect4) {
        point.y -= dY;
    }
    fig.setPointsRect4(pointsRect4);
}
void incrementYlines(std::map<int, int>& lines, const std::vector<Point>& rect) {
    // Находим минимальное значение Y в векторе точек
    auto minPointIt = std::min_element(rect.begin(), rect.end(), [](const Point& a, const Point& b) {
        return a.y < b.y;
        });

    if (minPointIt != rect.end()) {
        int Ymin = minPointIt->y;
        int y = Ymin / (scale * 11);

        if (Ymin < height) {
            // Увеличиваем количество заполненных клеток в соответствующей строке
            lines[y]++;
        }
    }
}

void DeleteLineRect(std::vector<Point>& rect, int coordY) {
    // Находим минимальное значение Y в векторе точек
    auto minYIt = std::min_element(rect.begin(), rect.end(), [](const Point& a, const Point& b) {
        return a.y < b.y;
        });

    if (minYIt == rect.end()) {
        return; // Если вектор пустой, выходим из функции
    }

    int minY = minYIt->y;

    std::vector<Point> newRect = rect; // Создаем копию вектора

    if (coordY == minY) {
        for (auto& point : newRect) {
            point.x = std::numeric_limits<int>::max();
            point.y = std::numeric_limits<int>::max();
        }
    }
    else if (coordY > minY) {
        for (auto& point : newRect) {
            point.y += scale * 11;
        }
    }

    rect = newRect; // Заменяем исходный вектор модифицированной копией
}

void DrawButton(HDC hdc, RECT rect, const char* text)
{
    // Рисуем кнопку
    DrawEdge(hdc, &rect, EDGE_RAISED, BF_RECT);

    // Заполняем фон кнопки белым цветом
    HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));
    FillRect(hdc, &rect, hBrush);
    DeleteObject(hBrush);

    // Устанавливаем режим прозрачного текста
    SetBkMode(hdc, TRANSPARENT);

    // Преобразуем const char* в LPCWSTR
    wchar_t wtext[100];
    MultiByteToWideChar(CP_ACP, 0, text, -1, wtext, 100);

    // Выводим текст на кнопке
    DrawText(hdc, wtext, -1, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

void GameOver(HWND hwnd)
{
    // Остановить таймер
    KillTimer(hwnd, IDT_TIMER1);

    // Создаем кнопку "New Game"
    CreateWindowEx(
        0,
        L"BUTTON",  // Predefined class; Unicode assumed
        L"New Game",      // Button text
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles
        100,         // x position
        200,         // y position
        150,        // Button width
        50,        // Button height
        hwnd,       // Parent window
        (HMENU)ID_NEW_GAME_BUTTON,       // Button ID
        (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
        NULL);      // Pointer not needed

    // Создаем кнопку "Exit"
    CreateWindowEx(
        0,
        L"BUTTON",  // Predefined class; Unicode assumed
        L"Exit",      // Button text
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles
        300,         // x position
        200,         // y position
        150,        // Button width
        50,        // Button height
        hwnd,       // Parent window
        (HMENU)ID_EXIT_BUTTON,       // Button ID
        (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
        NULL);      // Pointer not needed

    // Обновляем окно
    UpdateWindow(hwnd);
}

void DestroyButtons(HWND hwnd)
{
    // Удаляем кнопку "New Game"
    while (GetDlgItem(hwnd, ID_NEW_GAME_BUTTON)) {
        DestroyWindow(GetDlgItem(hwnd, ID_NEW_GAME_BUTTON));
    }

    // Удаляем кнопку "Exit"
    while (GetDlgItem(hwnd, ID_EXIT_BUTTON)) {
        DestroyWindow(GetDlgItem(hwnd, ID_EXIT_BUTTON));
    }

    // Обновляем окно
    InvalidateRect(hwnd, NULL, TRUE);
    UpdateWindow(hwnd);
}


void SearchLines(std::vector<Tetromino>& Figrnd_out)
{



    int Ny = height / (11 * scale) + 1;
    int Nx = width / (11 * scale);
    // Создаем словарь для хранения количества заполненных клеток в каждой строке
    std::map<int, int> lines;

    // Инициализируем словарь значениями 0
    for (int i = 0; i < Ny; ++i) {
        lines[i] = 0;
    }


    // Перебираем все элементы Figrnd_out
    for (Tetromino& fig : Figrnd_out)
    {

        incrementYlines(lines, fig.getPointsRect1());
        incrementYlines(lines, fig.getPointsRect2());
        incrementYlines(lines, fig.getPointsRect3());
        incrementYlines(lines, fig.getPointsRect4());
    }
    std::vector<int> fullLines{};
    // Проверяем, какие строки полностью заполнены
    for (auto line : lines)
    {
        // Если количество заполненных клеток в строке равно ширине поля, то строка полностью заполнена
        if (line.second == Nx)
        {
            // Добавляем номер строки в список полностью заполненных строк
            fullLines.push_back(line.first * scale * 11);
        }
    }

    if (lines[0] != 0)
    {
        StopGame = true;
    }

    int sc = 0;
    for (int coordY : fullLines)
    {
        for (Tetromino& fig : Figrnd_out) {
            std::vector<Point> points1 = fig.getPointsRect1();
            std::vector<Point> points2 = fig.getPointsRect2();
            std::vector<Point> points3 = fig.getPointsRect3();
            std::vector<Point> points4 = fig.getPointsRect4();

            DeleteLineRect(points1, coordY);
            DeleteLineRect(points2, coordY);
            DeleteLineRect(points3, coordY);
            DeleteLineRect(points4, coordY);

            fig.setPointsRect1(points1);
            fig.setPointsRect2(points2);
            fig.setPointsRect3(points3);
            fig.setPointsRect4(points4);
        }
        sc++;
    }
    if (sc == 1) { Score += 100; }
    else if (sc == 2) { Score += 300; }
    else if (sc == 3) { Score += 500; }
    else if (sc == 4) { Score += 800; }

}

int findMinXInTetromino(const Tetromino& tetromino) {
    int minX = std::numeric_limits<int>::max();

    // Векторы точек в Tetromino
    std::vector<std::vector<Point>> points = {
        tetromino.getPointsRect1(),
        tetromino.getPointsRect2(),
        tetromino.getPointsRect3(),
        tetromino.getPointsRect4()
    };

    for (const auto& rect : points) {
        auto minIt = std::min_element(rect.begin(), rect.end(), [](const Point& a, const Point& b) {
            return a.x < b.x;
            });

        if (minIt != rect.end() && minIt->x < minX) {
            minX = minIt->x;
        }
    }

    return minX;
}

int findMaxXInTetromino(const Tetromino& tetromino) {
    int maxX = std::numeric_limits<int>::min();

    // Векторы точек в Tetromino
    std::vector<std::vector<Point>> points = {
        tetromino.getPointsRect1(),
        tetromino.getPointsRect2(),
        tetromino.getPointsRect3(),
        tetromino.getPointsRect4()
    };

    for (const auto& rect : points) {
        auto maxIt = std::max_element(rect.begin(), rect.end(), [](const Point& a, const Point& b) {
            return a.x < b.x;
            });

        if (maxIt != rect.end() && maxIt->x > maxX) {
            maxX = maxIt->x;
        }
    }

    return maxX;
}

// Двойная буферизация
HBITMAP hbmMem = NULL;
HDC hdcMem = NULL;
HBITMAP hbmOld = NULL;
RECT clientRect;


// Функция для включения двойной буферизации
void SetDoubleBuffered(HWND hwnd, BOOL enabled) {
    if (enabled) {
        SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) | WS_EX_COMPOSITED);
    }
}
void StartTimer(HWND hwnd)
{
    SetTimer(hwnd, IDT_TIMER1, 10, NULL);
}
void Startgame()
{
    // Обновляем окно

    Figrnd_out.clear();
    Score = 0;
    std::mt19937 gen(rd()); // Инициализация генератора случайных чисел Mersenne Twister
    std::uniform_int_distribution<> distr(0, 6); // Инициализация равномерного распределения в заданном диапазоне
    int fig = distr(gen);
    mod = sizes[fig];
    std::uniform_int_distribution<> distr2(0, mod - 1);
    current_mod = distr2(gen);
    Figrnd_group = Figs[fig];

    int deltaX = ((width / 2) / (11 * scale)) * 11 * scale - 11 * scale;
    for (int i = 0; i < mod; i++)
    {
        MoveXY(Figrnd_group[i], deltaX, 0);
    }

    Figrnd = Figrnd_group[current_mod];


    int Ydec = std::round(static_cast<int>(height) / (scale * 11));
    int Y0 = (int)Ydec * (scale * 11);
    //Y0 = 0;
    int stepX = scale * 11;
    for (int j = 0; j <= width / (stepX * 1); j += 4)
    {
        //  Figrnd_out.
        std::vector<Point> Rect1, Rect2, Rect3, Rect4;
        {
            Rect1 = { Point(j * stepX, Y0),  Point(j * stepX + scale * 10, Y0),  Point(j * stepX + scale * 10, Y0 + scale * 10),  Point(j * stepX, Y0 + scale * 10) };
            Rect2 = { Point((j + 1) * stepX, Y0),  Point((j + 1) * stepX + scale * 10, Y0),  Point((j + 1) * stepX + scale * 10, Y0 + scale * 10),  Point((j + 1) * stepX, Y0 + scale * 10) };
            Rect3 = { Point((j + 2) * stepX, Y0),  Point((j + 2) * stepX + scale * 10, Y0),  Point((j + 2) * stepX + scale * 10, Y0 + scale * 10),  Point((j + 2) * stepX, Y0 + scale * 10) };
            Rect4 = { Point((j + 3) * stepX, Y0),  Point((j + 3) * stepX + scale * 10, Y0),  Point((j + 3) * stepX + scale * 10, Y0 + scale * 10),  Point((j + 3) * stepX, Y0 + scale * 10) };
            Figrnd_out.push_back(Tetromino(Rect1, Rect2, Rect3, Rect4));
        }
    }
}



LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {


    switch (uMsg) {

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case ID_NEW_GAME_BUTTON:
            // Обработка нажатия на кнопку "New Game"
            DestroyButtons(hwnd);

            StopGame = false;
            UpdateWindow(hwnd);
            Startgame();
            // InvalidateRect(hwnd, NULL, TRUE); // Перерисовываем окно
            StartTimer(hwnd); // Запуск таймера заново
            // Логика для новой игры...
            break;
        case ID_EXIT_BUTTON:
            // Обработка нажатия на кнопку "Exit"
            DestroyButtons(hwnd);
            PostQuitMessage(0);
            break;
        }
        break;
        

    case WM_KEYDOWN:
        switch (wParam) {
        case 'W':
        case VK_UP:
        {
            // MoveXY(Figrnd_group[i], 0, 1);
            int max = Figrnd_group.size();
            if (current_mod + 1 < max)
            {
                ++current_mod;
            }
            else { current_mod = 0; }
            Figrnd = Figrnd_group[current_mod];


            // InvalidateRect(hwnd, NULL, TRUE); // Перерисовываем окно
            break;
        }
        case 'S':
        case VK_DOWN:
        {
            // MoveXY(Figrnd_group[i], 0, 1);
            int max = Figrnd_group.size();
            if (current_mod - 1 >= 0)
            {
                --current_mod;
            }
            else { current_mod = max - 1; }
            Figrnd = Figrnd_group[current_mod];


            // InvalidateRect(hwnd, NULL, TRUE); // Перерисовываем окно
            break;
        }
        case 'A':
        case VK_LEFT:
        {
            int max = Figrnd_group.size();
            int min = width;
            int minx = 0;

            for (int i = 0; i < max; i++) {
                minx = findMinXInTetromino(Figrnd_group[i]);

                if (minx < min) { min = minx; }
            }
            if (min > 0) {
                for (int i = 0; i < max; i++) {
                    MoveXY(Figrnd_group[i], -scale * 11, 0);
                }
                //  InvalidateRect(hwnd, NULL, TRUE); // Перерисовываем окно
            }
            break;
        }
        case 'D':
        case VK_RIGHT:
        {
            int max = Figrnd_group.size();
            int max_ = 0;
            int maxx = 0;

            for (int i = 0; i < max; i++) {
                maxx = findMaxXInTetromino(Figrnd_group[i]);

                if (maxx > max_) { max_ = maxx; }
            }
            int w = (11 * scale) * width / (11 * scale);

            for (int i = 0; i < max; i++) {
                maxx = findMaxXInTetromino(Figrnd_group[i]);
                if (maxx + (11 * scale) <= width) {
                    MoveXY(Figrnd_group[i], scale * 11, 0);
                }
            }
            //   InvalidateRect(hwnd, NULL, TRUE); // Перерисовываем окно

            break;
        }
        case VK_SPACE:
        case VK_RETURN:
        {
            speed_moveY = 10;
            // InvalidateRect(hwnd, NULL, TRUE); // Перерисовываем окно
            break;
        }
        break;
        }



    case WM_CREATE:
    {
        SetDoubleBuffered(hwnd, true);
        SetTimer(hwnd, IDT_TIMER1, 10, NULL);
        GetClientRect(hwnd, &clientRect);
        hdcMem = CreateCompatibleDC(NULL);
        hbmMem = CreateCompatibleBitmap(GetDC(hwnd), clientRect.right - clientRect.left, clientRect.bottom - clientRect.top);
        hbmOld = (HBITMAP)SelectObject(hdcMem, hbmMem);
        break;
    }

    case WM_TIMER:
    {
        if (StopGame) {

            KillTimer(hwnd, IDT_TIMER1);
            break;
        }
        else {}

        // Проверяем, что сообщение пришло от нашего таймера
        if (wParam == IDT_TIMER1)
        {
            Figrnd = Figrnd_group[current_mod];

            for (int i = 0; i < mod; i++)
            {
                if (
                    Moving(Figrnd, Figrnd_out)
                    )
                {

                    MoveXY(Figrnd_group[i], 0, speed_moveY);
                }
                else
                {
                    speed_moveY = 2;
                    int dY = maxFixY(Figrnd, height);
                    // выравнивание позиций Y

                    updateRectPoints(Figrnd, dY);


                    Figrnd_out.push_back(Figrnd);

                    SearchLines(Figrnd_out);



                    std::mt19937 gen(rd()); // Инициализация генератора случайных чисел Mersenne Twister
                    std::uniform_int_distribution<> distr(0, 6); // Инициализация равномерного распределения в заданном диапазоне
                    int fig = distr(gen);
                    mod = sizes[fig];
                    std::uniform_int_distribution<> distr2(0, mod - 1);
                    current_mod = distr2(gen);
                    Figrnd_group = Figs[fig];


                    int deltaX = ((width / 2) / (11 * scale)) * 11 * scale - 11 * scale;
                    for (int i = 0; i < mod; i++)
                    {
                        MoveXY(Figrnd_group[i], deltaX, 0);
                    }

                    Figrnd = Figrnd_group[current_mod];
                }
            }


            // Вызываем функцию для перерисовки всего окна
            InvalidateRect(hwnd, NULL, FALSE); // Обновляем только нужную область
        }
        break;
    }

    case WM_DESTROY:

        if (hdcMem) {
            SelectObject(hdcMem, hbmOld);
            DeleteObject(hbmMem);
            DeleteDC(hdcMem);
        }
        PostQuitMessage(0);
        return 0;
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);



        // Получаем размер клиентской области
        RECT clientRect;
        GetClientRect(hwnd, &clientRect);
        width = clientRect.right - clientRect.left;
        height = clientRect.bottom - clientRect.top;

        // Создаем контекст памяти для двойной буферизации
        HDC hdcMem = CreateCompatibleDC(hdc);
        HBITMAP hbmMem = CreateCompatibleBitmap(hdc, width, height);
        HGDIOBJ hOld = SelectObject(hdcMem, hbmMem);

        // Заполняем фон черным цветом
        HBRUSH blackBrush = (HBRUSH)GetStockObject(BLACK_BRUSH);
        FillRect(hdcMem, &clientRect, blackBrush);



        // Рисуем тетромино на контексте устройства в памяти
        COLORREF blueColor = RGB(0, 0, 255);
        DrawTetrominoRects(hdcMem, Figrnd, blueColor);
        for (int i = 0; i < Figrnd_out.size(); i++) {
            DrawTetrominoRects(hdcMem, Figrnd_out[i], blueColor);
        }

        // Создаем и выбираем перо
        HPEN hPen = CreatePen(PS_SOLID, 1, RGB(10, 10, 10));
        HPEN hOldPen = (HPEN)SelectObject(hdcMem, hPen);

        for (int i = 0; i < height / (scale * 11); i++) {
            // Задаем начальную позицию
            MoveToEx(hdcMem, i * scale * 11, 0, NULL); // Начальная точка
            // Рисуем линию до точки
            LineTo(hdcMem, i * scale * 11, height);
        }

        // Устанавливаем прозрачный фон для текста
        SetBkMode(hdcMem, TRANSPARENT);

        // Устанавливаем цвет текста в белый
        SetTextColor(hdcMem, RGB(255, 255, 255));

        // Создаем текст для отображения
      

        // Создаем шрифт
        HFONT hFont = CreateFont(
            26,                        // Высота шрифта
            0,                         // Средняя ширина символов
            0,                         // Угол наклона текста
            0,                         // Угол наклона базовой линии
            FW_NORMAL,                 // Толщина шрифта
            TRUE,                      // Курсив
            FALSE,                     // Подчеркнутый
            FALSE,                     // Зачеркнутый
            DEFAULT_CHARSET,           // Набор символов
            OUT_DEFAULT_PRECIS,        // Точность вывода
            CLIP_DEFAULT_PRECIS,       // Точность отсечения
            DEFAULT_QUALITY,           // Качество вывода
            FIXED_PITCH | FF_MODERN,   // Ширина и семейство шрифта
            TEXT("Monotype Corsiva")   // Имя шрифта
        );

        // Сохраняем старый шрифт, чтобы потом восстановить его
        HFONT hOldFont = (HFONT)SelectObject(hdcMem, hFont);

        std::string text = "Score " + std::to_string(Score);

        // Преобразуем std::string в std::wstring
        int size_needed = MultiByteToWideChar(CP_UTF8, 0, &text[0], (int)text.size(), NULL, 0);
        std::wstring wstrTo(size_needed, 0);
        MultiByteToWideChar(CP_UTF8, 0, &text[0], (int)text.size(), &wstrTo[0], size_needed);

        TextOut(hdcMem, 10, 10, wstrTo.c_str(), wstrTo.length());



        if (StopGame) {
            GameOver(hwnd);
            StopGame = false;
        }
        else {}


        // Восстанавливаем старый шрифт и удаляем созданный шрифт
        SelectObject(hdcMem, hOldFont);
        DeleteObject(hFont);

        // Восстанавливаем старое перо и удаляем созданное перо
        SelectObject(hdcMem, hOldPen);
        DeleteObject(hPen);

        // Копируем изображение из контекста устройства в памяти на экран
        BitBlt(hdc, 0, 0, clientRect.right - clientRect.left, clientRect.bottom - clientRect.top, hdcMem, 0, 0, SRCCOPY);

        // Освобождаем ресурсы
        SelectObject(hdcMem, hOld);
        DeleteObject(hbmMem);
        DeleteDC(hdcMem);

        EndPaint(hwnd, &ps);
        return 0;
    }

                 return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int  window()
{
   LPCWSTR CLASS_NAME = L"Sample Window Class";

    // Получение дескриптора экземпляра
    HINSTANCE hInstance = GetModuleHandle(NULL);

    WNDCLASS wc = {};

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    //wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH); // Установка фона окна в черный цвет
    // Регистрация оконного класса
    RegisterClass(&wc);

    // Создание окна
    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        L"Sample Window",
        WS_OVERLAPPEDWINDOW,
        // Размеры и положение окна
        CW_USEDEFAULT, CW_USEDEFAULT,  // Position
        676, 1062,                      // Размеры окна (ширина x высота)
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (hwnd == NULL) {
        return 0;
    }

    // Показ окна
    ShowWindow(hwnd, SW_SHOW);

    // Цикл обработки сообщений
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        //  InvalidateRect(hwnd, NULL, TRUE);
    }
    return 0;
}

int main()
{
    //  std::vector<Tetromino>
    Figs.push_back({ TetrominoFactory::CreateFig1(), TetrominoFactory::CreateFig1_1() });
    Figs.push_back({ TetrominoFactory::CreateFig2(), TetrominoFactory::CreateFig2_1(), TetrominoFactory::CreateFig2_2(), TetrominoFactory::CreateFig2_3() });
    Figs.push_back({ TetrominoFactory::CreateFig3(), TetrominoFactory::CreateFig3_1(), TetrominoFactory::CreateFig3_2(), TetrominoFactory::CreateFig3_3() });
    Figs.push_back({ TetrominoFactory::CreateFig4(), TetrominoFactory::CreateFig4_1(), TetrominoFactory::CreateFig4_2(), TetrominoFactory::CreateFig4_3() });
    Figs.push_back({ TetrominoFactory::CreateFig5() });
    Figs.push_back({ TetrominoFactory::CreateFig6(), TetrominoFactory::CreateFig6_1() });
    Figs.push_back({ TetrominoFactory::CreateFig7(), TetrominoFactory::CreateFig7_1() });

    Scale(scale, Figs);

    Startgame();

  


    window();


    return 0;
}
