#pragma once

#include <algorithm>
#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <utility>
#include <string>

class Thirteen {
public:
    unsigned char* arr;
    size_t size;

public:
    Thirteen();
    Thirteen(const size_t n, const unsigned char c);
private:
    Thirteen(const size_t n, const unsigned char* c);
public:
    Thirteen(const std::initializer_list<unsigned char>& init);
    Thirteen(const std::string &t);
    Thirteen(const Thirteen& other);
    Thirteen& operator=(const Thirteen& other);
    Thirteen& operator=(Thirteen&& other) noexcept;
    Thirteen(Thirteen&& other) noexcept; 
    virtual ~Thirteen() noexcept;

    bool operator==(const Thirteen& other);
    bool operator!=(const Thirteen& other);
    bool operator>(const Thirteen& other);
    bool operator<(const Thirteen& other);

    Thirteen operator+(const Thirteen& other);
    Thirteen operator-(const Thirteen& other);

private:
    void Numerical_optimization();
};
