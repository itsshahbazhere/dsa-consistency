#include<iostream>
using namespace std;

class Stack{

    int *arr;
    int size;
    int top;

    public:
    Stack(int s){
        size = s;
        top = -1;
        arr = new int[s];
    }

    void push(int value){
        if(top == size-1){
            cout<<"Stack overflow\n";
            return;
        }
        else{
            top++;
            arr[top] = value;
            cout<<"Push "<<arr[top]<<" into stack\n";
        }
    }

    void pop(){
        if(top == -1){
            cout<<"Stack Underflow\n";
            return;
        }
        else{
            cout<<"Popped "<<arr[top]<<" from the stack\n";
            top--;
        }
    }

    void isTop(){
        if(top == -1){
            cout<<"Stack is empty\n";
        }
        else{
            cout<<arr[top]<<" This is the top element\n";
        }
       
    }

    int isSize(){
        return top+1; //top+1
    }
    bool isEmpty(){
        return top == -1;
    }
};

int main(){

    Stack S(5);
    cout<<S.isEmpty()<<endl;
    cout<<S.isSize()<<endl;
    S.push(5);
    S.push(6);
    S.push(7);
    S.push(8);
    S.push(9);
    S.push(9);
    S.isTop();
    S.pop();
    S.isTop();
    cout<<S.isEmpty()<<endl;
    cout<<S.isSize()<<endl;


    return 0;
}