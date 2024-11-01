// https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/?envType=daily-question&envId=2024-11-01

// Time Complexity: O(N)
// Space Complexity: O(N)


class Solution {
public:
    string makeFancyString(string s) {

        string ans="";
        ans.push_back(s[0]);
        int cnt = 1;

        for(int i=1; i<s.length(); i++){
            
            if(s[i] == ans.back()){
                cnt++;
                if(cnt <= 2) ans.push_back(s[i]);
            }
            else{
                cnt=1;
                ans.push_back(s[i]);
            }
            
        }
        
        return ans;
        
    }
};