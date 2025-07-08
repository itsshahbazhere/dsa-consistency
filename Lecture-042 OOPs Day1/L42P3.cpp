#include<iostream>
using namespace std;

class Hero{

    public:

    int health;
    char level;

    //default constructor
    Hero(){
        cout<<"Default constructor called..."<<endl;;
    }

    // parameterised constructor
    Hero(int health, char level){

        this->health = health;
        this->level = level;
    }


    //copy constructor
    Hero(Hero& temp){

        cout<<"Copy constructor called..."<<endl;
        this->health = temp.health;
        this->level = temp.level;
    }

    void print(){
        cout<<"health: "<<this->health<<endl;
        cout<<"level: "<<this->level<<endl;
    }

};

int main(){

    Hero S(70,'c');
    S.print();

    //copy constructor
    Hero R(S);
    R.print();




    return 0;
}