// https://www.geeksforgeeks.org/problems/print-bracket-number4058/1?page=1&difficulty%5B%5D=0&category%5B%5D=Stack&sortBy=submissions

// T.C- O(N)
// S.C- O(N)

class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        
        
        vector<int>ans;
        int cnt = 0;
        
        stack<int>st;
        
        for(int i=0; i<str.length(); i++){
            if(str[i] == '('){
                cnt++;
                ans.push_back(cnt);
                st.push(cnt);
            }
            else if(str[i] == ')'){
                ans.push_back(st.top());
                st.pop();
            }
        }
        
        return ans;
    }
};