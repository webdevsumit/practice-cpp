#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_set>
#include <cstring>
// #include "Hero.cpp"

using namespace std;

class Hero{
private:
    int health;
public:
    // Properties
    char level;
    char *name;

    static int staticdate;

    Hero(){
        name = new char[100];
    }

    void print(){
        cout<< "Health : " << this->getHealth() <<endl;
        cout<< "level : " << this->level <<endl;
        cout<< "name : " << this->name <<endl;
    }

    int getHealth(){
        return health;
    }
    void setHealth(int health){
        this->health = health;
    }
    int getLevel(){
        return level;
    }
    void setLevel(int level){
        this->level = level;
    }

    void setName(char name[]){
        strcpy(this->name, name);
    }
};

int Hero::staticdate = 5;

int main(){

    cout<<"Static data : "<<Hero::staticdate<<endl;

    Hero ramesh;
    ramesh.setHealth(60);
    ramesh.setLevel('A');
    char nm[7] = "Rakesh";
    ramesh.setName(nm);
    ramesh.print();
    // cout<< sizeof(ramesh) <<endl;
    // cout<< "Health : " << ramesh.getHealth() <<endl;

    Hero s(ramesh);
    s.print();


    Hero *n = new Hero();
    delete n;

    return 0;
}