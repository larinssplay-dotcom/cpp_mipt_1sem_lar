#include <iostream>

#include "animals.h"

Animal::Animal() = default;
Animal::~Animal() = default;
Animal::Animal(const Animal& other) = default;
Animal::Animal(Animal&& other) = default;
Animal& Animal::operator = (const Animal& other) = default;
Animal& Animal::operator = (Animal&& other) = default;

void Animal::AnMoving()
{
    std::cout << "i move maybe" << std::endl;
}

void Animal::AnEat()
{
    std::cout << "i eat smth" << std::endl;
}

void Animal::AnSound()
{
    std::cout << "some sound" << std::endl;
}

// Cat::Cat() : Animal() {}
// Cat::~Cat() = default;
// Cat::Cat(const Cat& cat) = default;
// Cat::Cat(Cat&& cat) = default;
// Cat& Cat::operator = (const Cat& cat) = default;
// Cat& Cat::operator = (Cat&& cat) = default;

void Cat::AnMoving()
{
    std::cout << "i move queue" << std::endl;

}

void Cat::AnEat()
{
    std::cout << "i eat mouse" << std::endl;
}

void Cat::AnSound()
{
    std::cout << "mew mew mew" << std::endl;
}


