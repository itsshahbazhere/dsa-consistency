#include<iostream>
#include<stack>
using namespace std;

int main(){

    stack<int>S;

    //check empty or not
    cout<<S.empty()<<endl;

    //size operation
    cout<<S.size()<<endl;


    //push operation
    S.push(5);
    S.push(6);
    S.push(7);
    S.push(8);

    //pop operation
    S.pop();


    //size operation
    cout<<S.size()<<endl;


    //top element
    cout<<S.top()<<endl;

    //check empty or not
    cout<<S.empty()<<endl;






}