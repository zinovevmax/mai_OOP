#include <iostream>
#include <cmath>

bool isPerfectSquare(int x) {
    double sqrt_x = std::sqrt(x);
    return sqrt_x == static_cast<int>(sqrt_x); // Проверяем, является ли корень целым числом
}

std::pair<int, int> closestPairToNum(int upperLimit) {
    for (int m = upperLimit - 1; m > 0; --m) {
        for (int n = m - 1; n > 0; --n) {
            if (isPerfectSquare(m + n) && isPerfectSquare(m - n)) {
                return {m, n};
            }
        }
    }
    return {-1, -1}; // Возвращаем (-1, -1), если подходящая пара не найдена
}