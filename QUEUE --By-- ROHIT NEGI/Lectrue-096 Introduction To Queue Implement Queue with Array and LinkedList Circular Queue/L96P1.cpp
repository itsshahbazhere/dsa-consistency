#include<bits/stdc++.h>
using namespace std;

class Queue{

    int *arr;
    int front, rear, size;

    public:

    Queue(int n){
        arr = new int[n];
        front = rear = -1;
        size = n;
    }


    Queue(){
        cout<<"default construtor\n";
    }

    bool isEmpty(){
        return front == -1;
    }
    bool isFull(){
        return rear == size-1;
    }
    void push(int x){
        if(isEmpty()){
            front = rear = 0;
            arr[0] = x;
        }
        else if(isFull()){
            cout<<"Queue Overflow...\n";
        }
        else{
            rear = rear + 1;
            arr[rear] = x;
        }
    }

    void pop(){
        if(isEmpty()){
            cout<<"Queue Underflow...\n";
            return;
        }
        else if(front == rear){
            front = rear = -1;
            return;
        }
        else{
            front = front+1;
        }
    }

    int start(){
        if(isEmpty()){
            cout<<"Queue is Empty[]..\n";
            return -1;
        }
        else{
            return arr[front];
        }
    }
};


int main(){

    Queue obj(5);
    obj.pop(); // underflow
    cout<<obj.isEmpty()<<endl; // yes 1

    cout<<obj.isFull()<<endl; // no 0

    obj.push(5);
    obj.push(4);
    obj.push(3);
    obj.push(2);
    obj.push(1);
    obj.push(1); //overflow

    cout<<obj.isFull()<<endl; // yes 1
    
    obj.pop();
    obj.pop();
    obj.pop();

    obj.push(50); //overflow ❌ this is wrong bcz array has 2 empty block that why we use circular queue

    cout<<obj.start()<<endl; //2

    cout<<obj.isEmpty()<<endl; // No 0


    return 0;
}