#ifndef THIRTEEN_H
#define THIRTEEN_H

#include <vector>
#include <stdexcept>
#include <string>
#include <initializer_list>

// Класс Twelve для работы с беззнаковыми целыми двенадцатиричными числами
class Thirteen {
public:
    // Конструктор по умолчанию
    Thirteen();

    // Конструктор, инициализирующий массив заданным количеством элементов
    Thirteen(const size_t & n, unsigned char t = 0);

    // Конструктор, инициализирующий массив списком инициализации
    Thirteen(const std::initializer_list<unsigned char> &t);

    // Конструктор, инициализирующий массив строкой
    Thirteen(const std::string &t);

    // Конструктор копирования
    Thirteen(const Thirteen& other);

    // Конструктор перемещения
    Thirteen(Thirteen&& other) noexcept;

    // Деструктор
    ~Thirteen() noexcept;

    // Оператор присваивания копированием
    Thirteen& operator=(const Thirteen& other);

    // Оператор присваивания перемещением
    Thirteen& operator=(Thirteen&& other) noexcept;

    // Оператор сложения
    Thirteen operator+(const Thirteen& other) const;

    // Оператор вычитания
    Thirteen operator-(const Thirteen& other) const;

    // Оператор сложения с присваиванием
    Thirteen& operator+=(const Thirteen& other);

    // Оператор вычитания с присваиванием
    Thirteen& operator-=(const Thirteen& other);

    // Оператор равенства
    bool operator==(const Thirteen& other) const;

    // Оператор неравенства
    bool operator!=(const Thirteen& other) const;

    // Оператор меньше
    bool operator<(const Thirteen& other) const;

    // Оператор больше
    bool operator>(const Thirteen& other) const;

    // Оператор меньше или равно
    bool operator<=(const Thirteen& other) const;

    // Оператор больше или равно
    bool operator>=(const Thirteen& other) const;

    // Метод для преобразования числа в строку
    std::string toString() const;

private:
    // Вектор для хранения цифр числа
    std::vector<unsigned char> digits;

    // Исходная строка, если была передана в конструктор
    std::string originalString;

    // Метод для нормализации числа (удаление ведущих нулей)
    void normalize();

    // Метод для добавления цифры в число
    void addDigit(unsigned char digit);

    // Метод для преобразования символа в цифру
    static unsigned char toDigit(char c);

    // Метод для преобразования цифры в символ
    static char toChar(unsigned char digit);
};

#endif
