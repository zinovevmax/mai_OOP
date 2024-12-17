#include "Thirteen.h"
#include <algorithm>
#include <cctype>
#include <stdexcept> // Добавляем заголовочный файл для исключений

// Конструктор по умолчанию
Thirteen::Thirteen() {}

// Конструктор, инициализирующий массив заданным количеством элементов
Thirteen::Thirteen(const size_t & n, unsigned char t) : digits(n, t) {
    if (t >= 13) {
        throw std::invalid_argument("Digit must be less than 13");
    }
}

// Конструктор, инициализирующий массив списком инициализации
Thirteen::Thirteen(const std::initializer_list<unsigned char> &t) : digits(t) {
    for (auto digit : t) {
        if (digit >= 13) {
            throw std::invalid_argument("Digit must be less than 13");
        }
    }
    normalize();
}

// Конструктор, инициализирующий массив строкой
Thirteen::Thirteen(const std::string &t) : originalString(t) {
    for (auto it = t.rbegin(); it != t.rend(); ++it) {
        addDigit(toDigit(*it));
    }
    normalize();
}

// Конструктор копирования
Thirteen::Thirteen(const Thirteen& other) : digits(other.digits), originalString(other.originalString) {}

// Конструктор перемещения
Thirteen::Thirteen(Thirteen&& other) noexcept : digits(std::move(other.digits)), originalString(std::move(other.originalString)) {}

// Деструктор
Thirteen::~Thirteen() noexcept {}

// Оператор присваивания копированием
Thirteen& Thirteen::operator=(const Thirteen& other) {
    if (this != &other) {
        digits = other.digits;
        originalString = other.originalString;
    }
    return *this;
}

// Оператор присваивания перемещением
Thirteen& Thirteen::operator=(Thirteen&& other) noexcept {
    if (this != &other) {
        digits = std::move(other.digits);
        originalString = std::move(other.originalString);
    }
    return *this;
}

// Оператор сложения
Thirteen Thirteen::operator+(const Thirteen& other) const {
    Thirteen result;
    size_t maxSize = std::max(digits.size(), other.digits.size());
    result.digits.resize(maxSize, 0);

    unsigned char carry = 0;
    for (size_t i = 0; i < maxSize; ++i) {
        unsigned char digit1 = (i < digits.size()) ? digits[i] : 0;
        unsigned char digit2 = (i < other.digits.size()) ? other.digits[i] : 0;
        unsigned char sum = digit1 + digit2 + carry;
        result.digits[i] = sum % 13;
        carry = sum / 13;
    }

    if (carry > 0) {
        result.digits.push_back(carry);
    }

    return result;
}

// Оператор вычитания
Thirteen Thirteen::operator-(const Thirteen& other) const {
    if (*this < other) {
        throw std::invalid_argument("Subtraction result is negative");
    }

    Thirteen result;
    size_t maxSize = std::max(digits.size(), other.digits.size());
    result.digits.resize(maxSize, 0);

    unsigned char borrow = 0;
    for (size_t i = 0; i < maxSize; ++i) {
        unsigned char digit1 = (i < digits.size()) ? digits[i] : 0;
        unsigned char digit2 = (i < other.digits.size()) ? other.digits[i] : 0;
        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 13;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.digits[i] = diff;
    }

    result.normalize();
    return result;
}

// Оператор сложения с присваиванием
Thirteen& Thirteen::operator+=(const Thirteen& other) {
    *this = *this + other;
    return *this;
}

// Оператор вычитания с присваиванием
Thirteen& Thirteen::operator-=(const Thirteen& other) {
    *this = *this - other;
    return *this;
}

// Оператор равенства
bool Thirteen::operator==(const Thirteen& other) const {
    return digits == other.digits;
}

// Оператор неравенства
bool Thirteen::operator!=(const Thirteen& other) const {
    return !(*this == other);
}

// Оператор меньше
bool Thirteen::operator<(const Thirteen& other) const {
    if (digits.size() != other.digits.size()) {
        return digits.size() < other.digits.size();
    }
    for (int i = digits.size() - 1; i >= 0; --i) {
        if (digits[i] != other.digits[i]) {
            return digits[i] < other.digits[i];
        }
    }
    return false;
}

// Оператор больше
bool Thirteen::operator>(const Thirteen& other) const {
    return other < *this;
}

// Оператор меньше или равно
bool Thirteen::operator<=(const Thirteen& other) const {
    return !(other < *this);
}

// Оператор больше или равно
bool Thirteen::operator>=(const Thirteen& other) const {
    return !(*this < other);
}

// Метод для преобразования числа в строку
std::string Thirteen::toString() const {
    if (!originalString.empty()) {
        return originalString;
    }
    std::string result;
    for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
        result += toChar(*it);
    }
    return result;
}

// Метод для нормализации числа (удаление ведущих нулей)
void Thirteen::normalize() {
    while (digits.size() > 1 && digits.back() == 0) {
        digits.pop_back();
    }
}

// Метод для добавления цифры в число
void Thirteen::addDigit(unsigned char digit) {
    if (digit >= 13) {
        throw std::invalid_argument("Digit must be less than 13");
    }
    digits.push_back(digit);
}

// Метод для преобразования символа в цифру
unsigned char Thirteen::toDigit(char c) {
    if (std::isdigit(c)) {
        return c - '0';
    } else if (c >= 'A' && c <= 'C') {
        return c - 'A' + 10;
    } else {
        throw std::invalid_argument("Invalid character for thirteen-base digit");
    }
}

// Метод для преобразования цифры в символ
char Thirteen::toChar(unsigned char digit) {
    if (digit < 10) {
        return digit + '0';
    } else {
        return digit - 10 + 'A';
    }
}
