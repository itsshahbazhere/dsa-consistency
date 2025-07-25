// https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

// Approach-3 Using Stack same but start from right to left
// T.C- O(N)
// S.C- O(N)

class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        
        int n = arr.size();
        vector<int>ans(n,-1);
        stack<int>st;
            
        for(int i=n-1; i>=0; i--){
            
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = arr[st.top()];
            }
            st.push(i);
            
        }
        
        return ans;
        
    }
};

// Approach-2 Using Stack
// T.C- O(N)
// S.C- O(N)


class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        
        int n = arr.size();
        vector<int>ans(n,-1);
        stack<int>st;
            
        for(int i=0; i<arr.size(); i++){
            while(!st.empty() && arr[st.top()]<arr[i]){
                ans[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        
        return ans;
        
    }
};



// Approach-1 Brute Force
// T.C- O(N^2)
// S.C- O(N)

class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        
        int n = arr.size();
        vector<int>ans(n,-1);
            
        for(int i=0; i<arr.size(); i++){
            for(int j=i+1; j<arr.size(); j++){
                if(arr[j]>arr[i]){
                    ans[i] = arr[j];
                    break;
                }
            }
        }
        
        return ans;
        
    }
};