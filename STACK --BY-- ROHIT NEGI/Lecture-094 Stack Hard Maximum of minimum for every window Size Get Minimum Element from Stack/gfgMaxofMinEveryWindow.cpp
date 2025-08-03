// https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1?page=1&difficulty%5B%5D=2&category%5B%5D=Stack&sortBy=submissions


#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        
        int n = arr.size();
        stack<int>st;
        vector<int>ans(n,0);
        
        vector<int>v(n,0);
        
        // find NSR & NSL;
        
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                int index = st.top();
                st.pop();
                if(!st.empty()){
                    v[index] = i-st.top()-1;
                }
                else{
                    v[index] = i;
                }
                
            }
            st.push(i);
        }
        
        // for(int i=0; i<n; i++){
        //     cout<<v[i]<<" ";
        // }

        // cout<<endl;

        while(!st.empty()){
            int index  = st.top();
            st.pop();
            if(!st.empty() && arr[index] != arr[st.top()]){
                v[index] = n-st.top()-1;
            }
            else{
                v[index] = n;
            }
        }


        // for(int i=0; i<n; i++){
        //     cout<<v[i]<<" ";
        // }
        
        
        // assign max in ans
        
        for(int i=0; i<n; i++){
            for(int j=0; j<v[i]; j++){
                ans[j] = max(ans[j], arr[i]);
            }
        }
        
        return ans;
        
    }
};


int main(){

    Solution obj;
    vector<int>arr = {9,5,4,8,1,6,5,6};
    obj.maxOfMins(arr);

}


// approach-1 brute force approach (TLE)
// T.C - O(N^3)
// S.C - O(N)

/*
class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        
        int n = arr.size();
        vector<int>ans(n,0);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n-i; j++){
                int mini = arr[j];
                for(int k=j; k<j+i+1; k++){
                    mini = min(mini,arr[k]);
                }
                ans[i] = max(mini,ans[i]);
            }
        }
        
        return ans;
        
    }
};

*/