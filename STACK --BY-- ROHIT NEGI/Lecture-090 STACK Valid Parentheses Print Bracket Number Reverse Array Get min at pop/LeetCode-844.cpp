// https://leetcode.com/problems/backspace-string-compare/


// T.C- O(m+n)
// S.C- O(m+n)

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        stack<char>first;
        stack<char>second;

        for(int i=0; i<s.length(); i++){
            if(first.empty()){
                if(s[i] != '#'){
                    first.push(s[i]);
                }
            }
            else{
                if(s[i] == '#'){
                    first.pop();
                }
                else{
                    first.push(s[i]);
                }
            }
        }
        for(int i=0; i<t.length(); i++){
            if(second.empty()){
                if(t[i] != '#'){
                    second.push(t[i]);
                }
            }
            else{
                if(t[i] == '#'){
                    second.pop();
                }
                else{
                    second.push(t[i]);
                }
            }
        }


        return first == second;
    }
};