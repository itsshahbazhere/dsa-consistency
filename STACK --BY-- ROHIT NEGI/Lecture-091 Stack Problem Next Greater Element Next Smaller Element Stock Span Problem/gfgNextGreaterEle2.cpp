// https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab





// rohit negi approach same loop using %
// T.C- O(N)
// S.C- O(N)

class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        
        int n = arr.size();
        vector<int>ans(n,-1);
        stack<int>st;
        
        for(int i=0; i<2*n; i++){
            while(!st.empty() && arr[i%n]>arr[st.top()]){
                ans[st.top()] = arr[i%n];
                st.pop();
            }
            if(i<n){
                st.push(i);
            }
            
        }
        
        return ans;
    }
    
};


// my approach 
// T.C- O(N)
// S.C- O(N)


class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        
        int n = arr.size();
        vector<int>ans(n,-1);
        stack<int>st;
        
        for(int i=0; i<arr.size(); i++){
            while(!st.empty() && arr[i]>arr[st.top()]){
                ans[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        
        for(int i=0; i<=st.top(); i++){
            while(!st.empty() && arr[i]>arr[st.top()]){
                ans[st.top()] = arr[i];
                st.pop();
            }
        }
        
        return ans;
    }
    
};