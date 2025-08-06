#include<iostream>
using namespace std;

class Node{

    public:

    int data;
    Node *next;
    Node *prev;

    Node(int value){
        data = value;
        prev = next = NULL;
    }
};

class Dequeue{
    Node *front;
    Node *rear;

    public:
    Dequeue(){
        front = rear = NULL;
    }

    void push_front(int x){
        if(front == NULL){
            front = rear = new Node(x);
            cout<<"Data push front -> "<<x<<endl;
            return;
        }
        else{
            Node *temp = new Node(x);
            temp->next = front;
            front->prev = temp;
            front = temp;
            cout<<"Data push front -> "<<x<<endl;
            return;
        }

    }

    void push_back(int x){
        if(rear == NULL){
            front = rear = new Node(x);
            cout<<"Data pushed back -> "<<x<<endl;
            return;
        }
        else{
            Node *temp = new Node(x);
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
            cout<<"Data push back -> "<<x<<endl;
            return;
        }
    }

    void pop_back(){
        if(rear == NULL){
            cout<<"Dequeue Underflow...."<<endl;
            return;
        }
        else{
            Node *temp = rear;
            rear = rear->prev;
            cout<<"Data pop back-> "<<temp->data<<endl;
            delete temp;
            if(rear){
                rear->next = NULL;
            }
            else{
                front = NULL;
            }
            return;
        }
    }

    void pop_front(){
        if(front == NULL){
            cout<<"Dequeue Underflow...."<<endl;
            return;
        }
        else{
            Node *temp = front;
            front = front->next;
            cout<<"Data pop back-> "<<temp->data<<endl;
            delete temp;

            if(front){
                front->prev = NULL;
            }
            else{
                rear = NULL;
            }
            
            return;
        }
    }


    void start(){
        if(front == NULL){
            cout<<"Dequeue is Empty..."<<endl;
        }
        else{
            cout<<"Front data -> "<< front->data<<endl;
        }
    }

    void end(){
        if(rear == NULL){
            cout<<"Dequeue is Empty..."<<endl;
        }
        else{
            cout<<"Rear data -> "<< rear->data<<endl;
        }
    }

};

int main(){

    Dequeue q;

    q.start(); //Dequeue is Empty
    q.end(); //Dequeue is Empty
    q.pop_front(); //Dequeue Underflow
    q.pop_back(); //Dequeue Underflow

    q.push_front(5); //Data push front -> 5
    q.push_front(6); //Data push front -> 6
    q.push_back(9); //Data push back -> 9
    q.push_back(10); //Data push back -> 10

    q.start(); //6
    q.end(); //10

    q.pop_front(); //6
    q.pop_back(); //10
    q.pop_front(); //5
    q.pop_back(); //9

    q.pop_back(); //Dequeue Underflow
    q.pop_front(); //Dequeue Underflow

    q.start(); //Dequeue is Empty
    q.end(); //Dequeue is Empty








}