// https://www.geeksforgeeks.org/problems/smallest-number-on-left3403/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

// T.C- O(N)
// S.C- O(N)


class Solution {
  public:
    vector<int> leftSmaller(vector<int> arr) {
        
        int n = arr.size();
        vector<int>ans(n,-1);
        stack<int>st;
        
        for(int i=n-1; i>=0; i--){
            while(!st.empty() &&  arr[i]<arr[st.top()]){
                ans[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        
        return ans;
    }
};