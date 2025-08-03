#include<iostream>
#include<queue>
using namespace std;

int main(){

    queue<int>q;

    q.push(5);
    q.push(4);
    q.push(3);
    q.push(3);

    int size = q.size();

    while(size--){
        cout<<q.front()<<" ";
        q.push(q.front());
        q.pop();
    }
}