#include<iostream>
using namespace std;

//implementation of queue using linked list

class Node{

    public:

    int data;
    Node *next;

    Node(int n){
        data = n;
        next = NULL;
    }

};

class Queue{


    Node* front;
    Node* rear;
    int size;

public:

    Queue(){
        front = rear = NULL;
        size = 0;
    }
    bool isEmpty(){
        return front == NULL;
    }
    int length(){
        return size;
    }
    void push(int n){

        if(isEmpty()){
            front = new Node(n);
            rear = front;
            cout<<n<<" is pushed successfully"<<endl;
            size++;
            return;
        }

        rear->next = new Node(n);
        rear = rear->next;
        cout<<n<<" is pushed successfully"<<endl;
        size++;

    }
    void pop(){
        if(isEmpty()){
            cout<<"Queue underflow"<<endl;
            return;
        }

        Node* temp = front;
        front = front->next;
        cout<<temp->data<<" is pop successfully"<<endl;
        delete temp;
        size--;
    }

    int start(){
        if(isEmpty()){
            cout<<"Queue is empty..."<<endl;
            return -1;
        }
        return front->data;
    }

};

int main(){

    Queue q;

    cout<<q.isEmpty()<<endl; //1
    cout<<q.length()<<endl; // 0
    cout<<q.start(); // empty -1
    cout<<endl;
    q.push(5);
    q.push(4);
    q.push(3);
    q.push(2);

    cout<<q.isEmpty()<<endl; //0
    cout<<q.length()<<endl; // 4
    cout<<q.start()<<endl; // 5

    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop(); //underflow

    cout<<q.isEmpty()<<endl; //1
    cout<<q.length()<<endl; // 0
    cout<<q.start()<<endl; // empty -1

}