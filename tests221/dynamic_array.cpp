#include <utility>
#include <stdexcept>

#include "dynamic_array.h"

DynamicArray::DynamicArray() 
 : size_(0), capacity_(0), data_(nullptr) {}

DynamicArray::DynamicArray(std::size_t capacity) 
 : size_(0), capacity_(capacity), data_(new double[capacity]) {}

DynamicArray::DynamicArray(std::size_t size, double value)
 : size_(size), capacity_(size), data_(new double[size])
{
    for (std::size_t i = 0; i < size; ++i)
    {
        data_[i] = value;
    }
}

DynamicArray::~DynamicArray()
{
    delete[] data_;
}

DynamicArray::DynamicArray(const DynamicArray &other) 
: size_(other.size_), capacity_(other.capacity_), data_(new double[capacity_])
{
    for (std::size_t i = 0; i < size_; ++i)
    {
        data_[i] = other.data_[i];
    }
}

DynamicArray::DynamicArray(DynamicArray &&other)
: size_(other.size_), capacity_(other.capacity_),
 data_(other.data_) 
{
    // Не нужно выделять новую память, просто забираем то, что есть в other, без утечки    
    other.size_ = 0;
    other.capacity_ = 0;
    other.data_ = nullptr;
}

DynamicArray &DynamicArray::operator=(const DynamicArray &other)
{
    if (this != &other) // Надо проверить на присвоение x=x
    {
        DynamicArray tmp(other); // Временный объект
        std::swap(size_, tmp.size_);
        std::swap(capacity_, tmp.capacity_);
        std::swap(data_, tmp.data_); // Поменяли местами указатели, текущий очистится в деструкторе tmp
    }
    return *this;
}

DynamicArray &DynamicArray::operator=(DynamicArray &&other)
{
    if (this != &other) // Надо проверить на присвоение x=x
    {
        size_ = other.size_;
        capacity_ = other.capacity_;
        delete[] data_; // Очищаем текущие данные
        data_ = other.data_; // Забираем данные other
        other.size_ = 0;
        other.capacity_ = 0;
        other.data_ = nullptr;
    }
    return *this;

}

void DynamicArray::assign(std::size_t size, double value)
{
    // Можно сделать без временного объекта, будет оптимальней по ресурсам
    DynamicArray vect(size, value);
    *this = std::move(vect);
}

double &DynamicArray::at(std::size_t index)
{
    if (size_ > index)
    {
        return data_[index];
    }
    // Обработка случая некорректного index
}

const double &DynamicArray::at(std::size_t index) const
{
    if (size_ > index)
    {
        return data_[index];
    }
    // Обработка случая некорректного index
}

double &DynamicArray::operator[](std::size_t index)
{
    return at(index);
}

const double &DynamicArray::operator[](std::size_t index) const
{
    return at(index);
}

std::size_t DynamicArray::size() const
{
    return size_;
}

std::size_t DynamicArray::capacity() const
{
    return capacity_;
}

void DynamicArray::clear()
{
    // Можно сделать аналогично std::vector: занулить только size_
    delete[] data_;
    data_ = nullptr; // Без присвоения на нулевой указатель data_ остается висеть (указывать куда-то)
    size_ = 0;
    capacity_ = 0; // Можно не занулять capacity, тогда можно оставить висячим указатель data_
}

bool DynamicArray::empty() const
{
    if (size_ == 0)
    {
        return true;
    }
    return false;
    // Можно просто return size_ == 0
}

void DynamicArray::pushBack(double value)
{
    if (size_ == capacity_)
    {
        // Явное выделение новой памяти м перезапись в случае нехватки capcaity
        // Обработка capacity == 0
        std::size_t newCapacity = (capacity_ == 0) ? 1 : capacity_ * 2;
        double* newData = new double[newCapacity];
        for (std::size_t i = 0; i < size_; ++i) 
        {
            newData[i] = data_[i];
        }
        delete[] data_;
        data_ = newData;
        capacity_ = newCapacity;
    }
    data_[size_++] = value;
}

void DynamicArray::popBack()
{
    if (size_ != 0)
    {
        data_[--size_] = 0;
        // Можно просто уменьшить size_ на 1 без зануления элемента
    }
    // Обработка ошибки
}
