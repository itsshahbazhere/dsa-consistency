// https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

// my approach
// T.C- O(N)
// S.C- O(N)


class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        
        int n = arr.size();
        vector<int>ans(n,1);
        stack<int>st;
        
        //find left greater
        
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[i]>arr[st.top()]){
                ans[st.top()] = st.top()-i;
                st.pop();
            }
            st.push(i);
        }
        
        while(!st.empty()){
            ans[st.top()]  = st.top() + 1;
            st.pop();
        }
        
        return ans;
    }
};