#pragma once

class Animal
{
public:
    Animal();
    virtual ~Animal();
    Animal(const Animal& other);
    Animal(Animal&& other);
    Animal& operator=(const Animal& other);
    Animal& operator=(Animal&& other);

    virtual void AnSound();
    virtual void AnEat();
    virtual void AnMoving();

};

class Cat : public Animal
{
public:
    Cat();
    virtual ~Cat();
    Cat(const Cat& cat1);
    Cat(Animal&& cat1);
    Cat& operator=(const Cat& cat1);
    Cat&& operator=(Cat&& cat1);

    virtual void AnSound() override;
    virtual void AnEat() override;
    virtual void AnMoving() override;

};