#include<iostream>
using namespace std;


// child class inherit data memebers and fucntion from prarent class is called inheritance
class Parent{

    public:
        int age;
        char Level;
        string name;
    
    public:
        void sleep(){
            cout<<"This is Inheritance";
        }
};

class Child: public Parent{

    public:
    string color;
};

int main(){

    Child object1;

    cout<<object1.age<<endl; //access parent data
    cout<<object1.color<<endl; //access child data
    object1.sleep();


   



    return 0;
}