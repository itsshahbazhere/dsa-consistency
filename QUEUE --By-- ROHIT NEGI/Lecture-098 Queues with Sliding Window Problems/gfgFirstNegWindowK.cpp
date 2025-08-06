// https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

#include<iostream>
#include<vector>
#include<queue>
using namespace std;



// Approach - 2
// T.C- O(N)
// S.C- O(K)


class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        
        vector<int>ans;
        queue<int>q;
        
        for(int i=0; i<k-1; i++){
            if(arr[i]<0){
                q.push(i);
            }
            
        }
        
        for(int i=k-1; i<arr.size(); i++){
            if(arr[i]<0){
                q.push(i);
            }
            if(q.empty()){
                ans.push_back(0);
            }
            else{
                if(q.front()<= i-k){
                    q.pop();
                }
                if(q.empty()){
                    ans.push_back(0);
                }
                else{
                    ans.push_back(arr[q.front()]);
                }
                
            }
        }
        
        return ans;
    }
};






// Approach - 1
// T.C- O(NK)
// S.C- O(K)

class Solution {
  public:
    int displayNeg(queue<int>q){
        while(!q.empty()){
            if(q.front()<0){
                return q.front();
            }
            else{
                q.pop();
            }
        }
        return 0;
    }
    vector<int> firstNegInt(vector<int>& arr, int k) {
        
        vector<int>ans;
        queue<int>q;
        
        for(int i=0; i<k-1; i++){
            q.push(arr[i]);
        }
        
        for(int i=k-1; i<arr.size(); i++){
            q.push(arr[i]);
            ans.push_back(displayNeg(q));
            q.pop();
        }
        
        return ans;
    }
};