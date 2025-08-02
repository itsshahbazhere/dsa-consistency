// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

#include<bits/stdc++.h>
using namespace std;

// approach 3 (optimized solution)
// T.C - O(N)
// S.C - O(N)

class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        
        int n = arr.size();
        stack<int>st;
        vector<int>ans(n,0);
        
        // find NSR & NSL;
        
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                int index = st.top();
                st.pop();
                if(st.empty()){
                    int range = i;
                    ans[range-1] = max(ans[range-1], arr[index]);
                }
                else{
                    int range = i-st.top()-1;
                    ans[range-1] = max(ans[range-1], arr[index]);
                }
                
            }
            st.push(i);
        }
        

        while(!st.empty()){
            int index  = st.top();
            st.pop();
            if(st.empty()){
                int range = n;
                ans[range-1] = max(ans[range-1], arr[index]);
            }
            else{
                int range = n-st.top()-1;
                ans[range-1] = max(ans[range-1], arr[index]);
            }
        }
        
        for(int i=n-2; i>=0; i--){
            ans[i] = max(ans[i], ans[i+1]);
        }
        
        return ans;
        
    }
};



// approach 2 (TLE)
// T.C - O(N^2)
// S.C - O(N)

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
                if(st.empty()){
                    v[index] = i;
                }
                else{
                    v[index] = i-st.top()-1;
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
            if(st.empty()){
                v[index] = n;
                }
            else{
                v[index] = n-st.top()-1;
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





// approach - 1 
// T.C - O(N^2)
// S.C - O(1)

class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int row = mat.size();
        int col = mat[0].size();
        int celRow = -1;

        for(int i=0; i<row; i++){
            int cnt = 0;
            
            for(int j=0; j<col; j++){
                if(i==j){
                    continue;
                }
                else if(mat[i][j] == 1){
                    break;
                }
                else if(mat[i][j] == 0){
                    cnt++;
                }
            }
            if(cnt==col-1){
                celRow = i;
                break;
            }
        }
        
        for(int i=0; i<row; i++){
            if(mat[i][celRow] == 0){
                if(i!=celRow){
                    return -1;
                }
            }
        }
        
        return celRow;
    }
};


int main(){

    vector<vector<int>>mat={{1}};

    Solution obj;

    int ans = obj.celebrity(mat);

    cout<<"Celebrity index: "<<ans<<endl;

    return 0;

}
