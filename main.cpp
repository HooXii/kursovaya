#include <iostream>
#include <cmath>
#include <locale>

// Функция для решения квадратного уравнения методом Ньютона
double solveQuadraticEquationNewton(double a, double b, double c) {
    double x0 = 0.0;  
    double epsilon = 1e-6;  

    double x = x0;
    double fx = a * x * x + b * x + c;
    double dfx = 2 * a * x + b;

    while (std::abs(fx) > epsilon) {
        x = x - fx / dfx;
        fx = a * x * x + b * x + c;
        dfx = 2 * a * x + b;
    }

    return x;
}

// Функция для решения квадратного уравнения методом бисекции
double solveQuadraticEquationBisection(double a, double b, double c) {
    double left = -1000.0; 
    double right = 1000.0;  
    double epsilon = 1e-6; 

    double x = (left + right) / 2;
    double fx = a * x * x + b * x + c;

    while (std::abs(fx) > epsilon) {
        if (fx * (a * left * left + b * left + c) < 0) {
            right = x;
        }
        else {
            left = x;
        }

        x = (left + right) / 2;
        fx = a * x * x + b * x + c;
    }

    return x;
}

// Функция для решения квадратного уравнения методом регули фальси
double solveQuadraticEquationRegulaFalsi(double a, double b, double c) {
    double left = -1000.0;  
    double right = 1000.0;  
    double epsilon = 1e-6;  

    double x = left;
    double fx = a * x * x + b * x + c;

    double root = 0.0;

    while (std::abs(fx) > epsilon) {
        double xNext = (left * a * fx - x * a * (b + a * x)) / (a * (fx - a * (b - a * x)));

        if (a * fx < 0) {
            right = x;
        }
        else {
            left = x;
        }

        x = xNext;
        fx = a * x * x + b * x + c;

        root = x;
    }

    return root;
}

int main() {
    setlocale(LC_ALL, "");  

    double a, b, c;
    std::cout << "Введите коэффициенты квадратного уравнения (ax^2 + bx + c = 0):" << std::endl;
    std::cout << "Введите коэффициент a: ";
    std::cin >> a;
    std::cout << "Введите коэффициент b: ";
    std::cin >> b;
    std::cout << "Введите коэффициент c: ";
    std::cin >> c;

    double rootNewton = solveQuadraticEquationNewton(a, b, c);
    double rootBisection = solveQuadraticEquationBisection(a, b, c);
    double rootRegulaFalsi = solveQuadraticEquationRegulaFalsi(a, b, c);

    std::cout << "Корень квадратного уравнения (метод Ньютона): " << rootNewton << std::endl;
    std::cout << "Корень квадратного уравнения (метод бисекции): " << rootBisection << std::endl;
    std::cout << "Корень квадратного уравнения (метод регули фальси): " << rootRegulaFalsi << std::endl;

    return 0;
}