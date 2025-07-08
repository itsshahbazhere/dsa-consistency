#include<iostream>
using namespace std;


// signle child class inherit data memebers and fucntion from more than a parents class
class Parent1{

    public:
        int age;
        char Level;
        string name;
    
        void sleep1(){
            cout<<"This is parent1"<<endl;
        }
};
class Parent2{

    public:
        int year;
        char section;
        string subject;

        void sleep2(){
            cout<<"This is parent2"<<endl;
        }
};

class Child: public Parent1, public Parent2{

    public:
    string lab;
};

int main(){

    Child object1;

    object1.sleep1(); //parent1 data
    object1.sleep2(); //parent2 data
    cout<<object1.lab<<endl; //own data 




   



    return 0;
}