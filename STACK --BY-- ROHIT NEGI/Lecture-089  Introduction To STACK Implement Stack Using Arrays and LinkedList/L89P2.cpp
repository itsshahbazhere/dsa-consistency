#include<iostream>
using namespace std;

class Node{

    public:

    int data;
    Node *next;

    Node(int value){
        data = value;
        next = NULL;
    }
};

class Stack{

    int size;
    Node *top;

    public:
    Stack(){
        top = NULL;
        size = 0;
    }

    void push(int value){
        Node *temp = new Node(value);
        if(temp == NULL){ //yes its dynamic but if heap memory of ram is full then it cant create any node then stack overflow condition occur
            cout<<"Stack overflow\n";
        }
        temp->next = top;
        top = temp;
        size++;
        cout<<"Push "<<temp->data<<" sucessfully\n";
    }

    void pop(){
        if(top == NULL){
            cout<<"Stack UNderflow\n";
            return;
        }
        else{
            Node *temp = top;
            cout<<"Popped "<<temp->data<<" successfully\n";
            top = top->next;
            delete temp;
            size--;
        }
    }

    void peek(){
        if(top == NULL){
            cout<<"Stack is empty\n";
            return;
        }
        cout<<top->data<<" is peek element\n";
        return;
    }
    bool isEmpty(){
        return top == NULL;
    }

    void isSize(){
        cout<<"Size of Stack is "<<size<<endl;
        return;
    }
};


int main(){

    Stack S;
    cout<<S.isEmpty()<<endl;
    S.isSize();
    S.push(5);
    S.push(6);
    S.push(7);
    S.push(8);
    S.push(9);
    S.isSize();
    cout<<S.isEmpty()<<endl;
    S.pop();
    S.pop();
    S.pop();
    S.pop();
    S.pop();
    S.pop();
    cout<<S.isEmpty()<<endl;
    S.isSize();
    


}