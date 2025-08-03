#include<bits/stdc++.h>
using namespace std;


// 1st approach
class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        
        int size = q.size();
        
        if(k>size){
            return q;
        }
        
        vector<int>v;
        
        while(!q.empty()){
            v.push_back(q.front());
            q.pop();
        }
        
        for(int i=k-1; i>=0; i--){
            q.push(v[i]);
        }
        
        for(int i=k; i<v.size(); i++){
            q.push(v[i]);
        }
        
        return q;
    }
};



// 2nd approach
class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        stack<int>st;
        
        if(k>q.size()) return q;
        
        while(k--){
            st.push(q.front());
            q.pop();
        }
        
        int size = q.size();
        
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        
        while(size--){
            q.push(q.front());
            q.pop();
        }
        
        return q;
    }
};