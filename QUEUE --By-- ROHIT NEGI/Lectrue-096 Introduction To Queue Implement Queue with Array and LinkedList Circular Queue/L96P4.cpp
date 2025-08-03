#include<iostream>
#include<queue>
using namespace std;
int main(){

    queue<int>q;

    cout<<q.size()<<endl; //0
    cout<<q.empty()<<endl; //1
    cout<<q.front()<<endl; //empty
    // q.pop(); //undeflow

    q.push(5);
    q.push(4);
    q.push(9);
    q.push(4);
    q.push(1);

    cout<<q.size()<<endl; //5
    cout<<q.empty()<<endl; //0
    cout<<q.front()<<endl; //5


    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    // q.pop(); //underflow

    cout<<q.size()<<endl; //0
    cout<<q.empty()<<endl; //1
    cout<<q.front()<<endl; //empty






    return 0;
}