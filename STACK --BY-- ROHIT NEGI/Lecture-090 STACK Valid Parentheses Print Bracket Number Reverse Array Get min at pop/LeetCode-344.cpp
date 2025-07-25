// https://leetcode.com/problems/reverse-string/

// T.C- O(N)
// S.C- O(N)

class Solution {
public:
    void reverseString(vector<char>& s) {
        
        stack<char>st;
        for(int i=0; i<s.size(); i++){
            st.push(s[i]);
        }

        int i=0;
        while(!st.empty()){
            s[i++] = st.top();
            st.pop();
        }
    }
};