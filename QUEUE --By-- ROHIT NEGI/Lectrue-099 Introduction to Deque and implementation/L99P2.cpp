#include<iostream>
using namespace std;

class Dequeue{

    int *arr;
    int size, front, rear;

    public:
    Dequeue(int x){
        arr = new int[x];
        front = rear = -1;
        size = x;
    }

    void push_back(int x){
        if(isEmpty()){
            front = rear = 0;
            arr[0] = x;
            cout<<"push back-> "<<x<<endl;
            return;
        }
        else{
            rear = (rear+1)%size;
            if(rear == front){
                cout<<"Dequeue overflow...."<<endl;
                return;
            }
            else{
                arr[rear] = x;
                cout<<"push back-> "<<x<<endl;
                return;
            }
        }
    }

    void push_front(int x){
        if(isEmpty()){
            front = rear = 0;
            arr[0] = x;
            cout<<"push front-> "<<x<<endl;
            return;
        }
        else{
            front = (front-1+size)%size;
            if(front == rear){
                cout<<"Dequeue overflow..."<<endl;
                return;
            }
            else{
                arr[front] = x;
                cout<<"push front-> "<<x<<endl;
                return;
            }
        }
    }

    void pop_front(){
        if(isEmpty()){
            cout<<"Dequeue underflow..."<<endl;
        }
        else{
            cout<<"pop front-> "<<arr[front]<<endl;
            if(front == rear){
                front = rear = -1;
                return;
            }
            front = (front+1)%size;
            return;
        }
    }

    void pop_back(){
        if(isEmpty()){
            cout<<"Dequeue underflow..."<<endl;
        }
        else{
            cout<<"pop back-> "<<arr[rear]<<endl;
            if(front == rear){
                front = rear = -1;
                return;
            }
            rear = (rear-1+size)%size;
            return;
        }
    }

    void start(){
        if(front == -1){
            cout<<"Dequeue is empty..."<<endl;
        }
        else{
            cout<<"front data -> "<<arr[front]<<endl;
        }
    }

    void end(){
        if(rear == -1){
            cout<<"Dequeue is empty..."<<endl;
        }
        else{
            cout<<"back data -> "<<arr[rear]<<endl;
        }

    }
    bool isEmpty(){
        return front == -1 && rear == -1;
    }

};
int main(){

    Dequeue q(5);

    cout<<"dequeue is empty? "<<q.isEmpty()<<endl; // 1

    q.start(); //empty
    q.end(); //empty
    q.pop_front(); //underflow
    q.pop_back(); //underflow

    q.push_back(5); //5
    q.push_back(6); //6
    q.push_front(8); //8
    q.push_front(9); //9
    q.push_back(10); //10
    // 5 6 10b 9f 8


    q.start(); //9
    q.end(); //10


    q.pop_front(); //9
    q.pop_front(); //8
    q.pop_front(); //5
    // 0 6f 10b 0 0


    q.start(); //6
    q.end(); //10

    cout<<"dequeue is empty? "<<q.isEmpty()<<endl; // 0


    
    q.push_back(3); //3
    q.push_back(45); //45
    q.push_back(16); //16
    // 16b 6f 10 3 45


    q.start(); //6
    q.end(); //16


    
    q.pop_back(); //16
    q.pop_back(); //45
    // 0 6f 10 3b 0


    q.start(); //6
    q.end(); //3


    q.pop_front(); //6
    q.pop_front(); //10
    q.pop_front(); //3
    // 0 0 0 0 0  f,b = -1


    q.start(); //empty

    q.end(); //empty

    cout<<"dequeue is empty? "<<q.isEmpty()<<endl; // 1


    return 0;
}