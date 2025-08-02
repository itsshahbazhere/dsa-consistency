// https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

#include<bits/stdc++.h>
using namespace std;




//approach-1
// T.C - O(1)
// S.C - O(N)
class Solution {
  public:
  
    stack<int>st1; //store actual element
    stack<int>st2; //store min element
    
    Solution() {
        
        
    }

    // Add an element to the top of Stack
    void push(int x) {
        if(st1.empty()){
            st1.push(x);
            st2.push(x);
        }
        else{
            st2.push(min(x,st2.top()));
            st1.push(x);
        }
    }

    // Remove the top element from the Stack
        
    void pop() {
        if(!st1.empty()){
            st1.pop();
            st2.pop();
        }
    }
        
    // Returns top element of the Stack
    int peek() {
        return st1.empty()? -1:st1.top();
    }

    // Finds minimum element of Stack
    int getMin() {
        return st2.empty()? -1:st2.top();
    }

};