#pragma once

#include <cstdint>

class DynamicArray
{
private:
    std::size_t size_;
    std::size_t capacity_;
    double* data_;

public:
    DynamicArray();
    DynamicArray(std::size_t capacity);
    DynamicArray(std::size_t size, double value);

    DynamicArray(const DynamicArray& other);
    DynamicArray(DynamicArray&& other);

    DynamicArray& operator=(const DynamicArray& other);
    DynamicArray& operator=(DynamicArray& other);

    void assign(std::size_t size, double value);
    double& at(std::size_t index);
    const double& at(std::size_t index) const;

    std::size_t size() const;
    std::size_t capacity() const;

    void clear();

    bool empty() const;

    void pushBack(double value);
    void popBack();





};