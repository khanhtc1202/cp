#include <iostream>
using namespace std;

class Mammal
{
public:
    Mammal(int a) {
      age = a;
    }
    virtual void Eat() {cout << "Mammal eats food"<<endl;}
    virtual void Speak() {cout << "Mammal speaks mammalian!!"<<endl;}
    virtual int get_Age(){return age;}

protected:
    int age;
};

class Dog: public Mammal
{
public:
    Dog(int age=0) : Mammal(age) {}
    void Eat() {cout << "Dog eats meat"<<endl;}
    void Speak() {cout << "Dog barks: ruff! ruff!"<<endl;}
    // int get_Age(){return age;}
};

class Cat: public Mammal
{
public:
    Cat(int age=0): Mammal(age){}
    void Eat() {cout << "Cat eats meat"<<endl;}
    void Speak() {cout << "Cat meows: Meow! Meow!" <<endl;}
    // int get_Age(){return age;}
};

int main(void) {
   Mammal *m;
   Dog doggo(5); //making object of child class Dog
   Cat catty(4); //making object of child class Cat
   
//   m = &doggo;
//   m->Eat();
//   m->Speak();
   doggo.Eat();
   cout << "Dog's age is: "<<doggo.get_Age()<<endl;
   m= &catty;
   m->Eat();
   m->Speak();
   cout << "Cat's age is: "<<m->get_Age()<<endl;
   
  
   return 0;
}