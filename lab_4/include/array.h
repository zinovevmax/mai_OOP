#ifndef ARRAY_H
#define ARRAY_H

#include <memory>
#include <stdexcept>
#include <iostream>
#include <algorithm>

template <typename T>
class Array {
public:
    Array(size_t size) : size(size), data(std::make_unique<T[]>(size)) {}

    ~Array() = default;

    Array(const Array& other) : size(other.size), data(std::make_unique<T[]>(other.size)) {
        std::copy(other.data.get(), other.data.get() + size, data.get());
    }

    Array(Array&& other) noexcept : size(other.size), data(std::move(other.data)) {
        other.size = 0;
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            size = other.size;
            data = std::make_unique<T[]>(size);
            std::copy(other.data.get(), other.data.get() + size, data.get());
        }
        return *this;
    }

    Array& operator=(Array&& other) noexcept {
        if (this != &other) {
            size = other.size;
            data = std::move(other.data);
            other.size = 0;
        }
        return *this;
    }

    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    size_t getSize() const {
        return size;
    }

    void resize(size_t newSize) {
        std::unique_ptr<T[]> newData = std::make_unique<T[]>(newSize);
        size_t copySize = std::min(size, newSize);
        std::move(data.get(), data.get() + copySize, newData.get());
        data = std::move(newData);
        size = newSize;
    }

private:
    size_t size;
    std::unique_ptr<T[]> data;
};

#endif
