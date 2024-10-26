https://leetcode.com/contest/biweekly-contest-142/problems/find-the-original-typed-string-i/submissions/1434309169/


// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int possibleStringCount(string word) {

        int cnt = 1;
        for(int i=0; i<word.length()-1; i++){
            if(word[i] == word[i+1]){
                cnt++;
            }
            
        }

        return cnt;
        
    }
};