#include<iostream>
#include<deque>
using namespace std;

class Stack{
    deque<int>d;
    public:
    void push_back(int x){
        d.push_back(x);
        cout<<"Data push into stack -> "<<x<<endl;
    }
    void pop_back(){
        cout<<"Data pop into stack -> "<<d.back()<<endl;
        d.pop_back();
    }

    void top(){
        cout<<"Data top of the stack -> "<<d.back()<<endl;
    }

};

class Queue{
    deque<int>d;
    public:
    void push_back(int x){
        d.push_back(x);
        cout<<"Data push into queue -> "<<x<<endl;
    }
    void pop_front(){
        cout<<"Data pop into queue -> "<<d.front()<<endl;
        d.pop_front();
    }

    void top(){
        cout<<"Data top of the queue -> "<<d.front()<<endl;
    }
};

int main(){

    Stack st;
    Queue q;

    st.push_back(5);
    st.push_back(6);
    st.top();
    st.pop_back();
    st.pop_back();



    q.push_back(10);
    q.push_back(11);
    q.top();
    q.pop_front();
    q.pop_front();



}
