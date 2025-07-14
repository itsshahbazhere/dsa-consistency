#include<iostream>
using namespace std;

class Complex {

    public:
        int a;
        int b;

        //operator overloading
        
        void operator+ (Complex &obj){
            int value1 = this->a;
            int value2 = obj.a;

            cout<<"Output: "<<value2-value1;
        }
        

   
};

int main() {
    
    Complex obj1;
    Complex obj2;

    obj1.a = 4;
    obj2.a = 7;

    obj1 + obj2;


}