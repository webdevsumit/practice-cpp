#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_set>
#include <cstring>
// #include "Hero.cpp"

using namespace std;

class Human {
    public:
    int height;
    int weight;
    int age;

    // public:
    int getAge(){
        return this->age;
    }

    void setWeight(int w){
        this->weight = w;
    }

};

class Male: public Human {
    public:
    string color;

    void sleep(){
        cout<<"Male Sleeping" <<endl;
    }
};

class AngryMale: public Male {

};







class Animal {
    public:
    int age;
    int weight;

    void bark() {
        cout<< "Barking "<<endl;
    }

};

class Hybrid: public Animal, public Human {

};

// Hybrid means using more than one type...

int main(){

    Hybrid o1;
    // Solving Inheritance Ambiguity...
    cout<<"Age from Human class : "<<o1.Animal::age <<endl;
    o1.bark();

    return 0;    
}