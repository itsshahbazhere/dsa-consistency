// https://www.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

#include<bits/stdc++.h>
using namespace std;




class twoStacks {
  public:
    
    int *arr;
    int top1, top2;
    int size;
    
    twoStacks(int n=100) {
        arr = new int[n];
        top1 = -1;
        top2 = n;
        size = n;
    }
    
    
    // Function to push an integer into the stack1.
    void push1(int x) {
        if(top1 + 1 == top2){
            return;
        }
        else{
            top1++;
            arr[top1] = x;
        }
        
        
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        if(top2 - 1 == top1){
            return;
        }
        else{
            top2--;
            arr[top2] = x;
        }
        
    }

    // Function to remove an element from top of the stack1.

        
    int pop1() {
        if(top1 == -1){
            return -1;
        }
        int ele = arr[top1];
        top1--;
        return ele;
    }

        
    // Function to remove an element from top of the stack2.
    int pop2() {
        if(top2 == size){
            return -1;
        }
        int ele = arr[top2];
        top2++;
        return ele;
    }
};