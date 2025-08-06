
#include<iostream>
#include<deque>
using namespace std;

int main(){

    deque<int>d;

    // cout<<d.front()<<endl; //empty -thats why give error
    // cout<<d.back()<<endl; //empty


    cout<<d.empty()<<endl; // 1

    d.push_back(5);  // 5
    d.push_back(6);  // 5 6
    d.push_back(7);  // 5 6 7
    d.push_front(8); // 8 5 6 7
    d.push_front(2); // 2 8 5 6 7
    d.push_front(1); // 1 2 8 5 6 7


    cout<<d.front()<<endl; // 1
    cout<<d.back()<<endl; // 7


    d.pop_back(); // 1 2 8 5 6 7
    d.pop_back(); // 1 2 8 5 6
    d.pop_front(); // 2 8 5 6
    d.pop_front(); // 8 5 6


    cout<<d.front()<<endl; // 8
    cout<<d.back()<<endl; // 6

    cout<<d.empty()<<endl; // 0





    return 0;
}
