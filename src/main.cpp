#include "segments/Segment3D.h"
#include <iostream>
#include <cstdlib>  // Для std::atof

int main(int argc, char* argv[]) {
    if (argc != 13) {
        std::cerr << "Usage: " << argv[0] << " x1 y1 z1 x2 y2 z2 x3 y3 z3 x4 y4 z4\n";
        return 1;
    }

    // Читаем координаты из аргументов командной строки
    double x1 = std::atof(argv[1]);
    double y1 = std::atof(argv[2]);
    double z1 = std::atof(argv[3]);
    double x2 = std::atof(argv[4]);
    double y2 = std::atof(argv[5]);
    double z2 = std::atof(argv[6]);
    double x3 = std::atof(argv[7]);
    double y3 = std::atof(argv[8]);
    double z3 = std::atof(argv[9]);
    double x4 = std::atof(argv[10]);
    double y4 = std::atof(argv[11]);
    double z4 = std::atof(argv[12]);

    // Создаем отрезки
    Point3D p1(x1, y1, z1), p2(x2, y2, z2);
    Point3D p3(x3, y3, z3), p4(x4, y4, z4);
    Segment3D s1(p1, p2);
    Segment3D s2(p3, p4);

    // Вычисляем расстояние
    std::cout << "Distance between segments: " << s1.distance(s2) << std::endl;

    return 0;
}