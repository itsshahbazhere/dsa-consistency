// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/

// T.C- O(N)
// S.C- O(N)

class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int cnt = 0;
        stack<char>st;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '('){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    cnt++;
                }
                else{
                    st.pop();
                }
            }
        }

        return cnt+st.size();
    }
};