#include<iostream>
using namespace std;

class Complex {

    public:
        int a;
        int b;

        //function overriding 
        void sleep(int a){
            cout<<"sleep1"<<endl;
        }
        void sleep(char b){
            cout<<"sleep2"<<endl;
        }
        void sleep(){
            cout<<"sleep3"<<endl;
        }

   
};

int main() {
    
    Complex obj1;

    obj1.sleep();





}