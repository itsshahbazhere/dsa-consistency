// https://leetcode.com/problems/rotate-string/?envType=daily-question&envId=2024-11-03


//approach-2
// Time Complexity: O(N) //concatinating two string or find string
// Space Complexity: O(N) //forcreating new string s+s

class Solution {
public:
    bool rotateString(string s, string goal) {
        return (s.length() == goal.length() && (s+s).find(goal) != string::npos);
    }
};




//approach-1
// Time Complexity: O(N^2)
// Space Complexity: O(1)

class Solution {
public:
    bool rotateString(string s, string goal) {

        

        for(int i=0; i<s.length(); i++){
            if(s==goal){
                return true;
            }
            else{
                char temp = s[0];
                for(int j=1; j<s.length(); j++){
                    s[j-1] = s[j];
                }
                s[s.length()-1] = temp;
            }
        }

        return false;
        
    }
};