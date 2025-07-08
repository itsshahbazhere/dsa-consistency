#include<iostream>
using namespace std;


// signle child class inherit data memebers and fucntion from sigle  prarent class is called  single inheritance
class GrandFather{

    public:
        int age;
        char Level;
        string name;
    
    public:
        void sleep(){
            cout<<"This is multilevel Inheritance";
        }
};

class Father: public GrandFather{

    public:
    string color;
};

class Child: public Father{

    public:
    string name;
};

int main(){

    Child object1;

    cout<<object1.age<<endl; //access grand data
    cout<<object1.color<<endl; //access father data
    cout<<object1.name<<endl; //access own data
    object1.sleep();


   



    return 0;
}