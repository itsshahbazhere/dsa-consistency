#include<iostream>
using namespace std;


// single  data model and function wrap in single clas called encapsulation
class Hero{

    private:
        int age;
        char Level;
        string name;
    
    public:
        void sleep(){
            cout<<"This is Encapsulation";
        }
};

int main(){

    Hero object1;

    object1.sleep();

    return 0;
}