#include "dynemic_Array.h"
#include <iostream>


DynamicArray::DynamicArray()
 : size_(0), capacity_(0), data_(nullptr)
{
}

DynamicArray::DynamicArray(std::size_t capacity)
 : size_(0), capacity_(capacity), data_(new double[capacity] {})
{
}

DynamicArray::DynamicArray(std::size_t size, double value)
 : size_(size), capacity_(size), data_(new double[size])
{
    for(std::size_t i=0; i<size; ++i)
    {
        data_[i] = value;
    }
}

DynamicArray::DynamicArray(const DynamicArray &other)
 : size_(other.size_), capacity_(size), data_(new double[size])
{
    for(std::size_t i=0; i<size; ++i)
    {
        data_[i] = other.data_;
    }
}

DynamicArray::DynamicArray(DynamicArray &&other)
 : size_(other.size_),data()
{
    size_ = std::move(other.size_);
    capacity_ = std::move(other.capacity_);
    data_
}

DynamicArray &DynamicArray::operator=(const DynamicArray &other)
{
    size_ = other.size_;
    capacity_ = other.capacity_;
    return *this;
    // TODO: insert return statement here
}

DynamicArray &DynamicArray::operator=(DynamicArray &&other)
{
    size_ = std::move(other.size_);
    capacity_ = std::move(other.capacity_);
    return *this;
}





void DynamicArray::assign(std::size_t size, double value)
{
}

double &DynamicArray::at(std::size_t index)
{
    // TODO: insert return statement here
}

const double &DynamicArray::at(std::size_t index) const
{
    // TODO: insert return statement here
}

std::size_t DynamicArray::size() const
{
    return std::size_t();
}

std::size_t DynamicArray::capacity() const
{
    return std::size_t();
}

void DynamicArray::clear()
{
}

bool DynamicArray::empty() const
{
    return false;
}

void DynamicArray::pushBack(double value)
{

}

void DynamicArray::popBack()
{
    
}
