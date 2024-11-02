// https://leetcode.com/problems/circular-sentence/?envType=daily-question&envId=2024-11-02

// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution {
public:
    bool isCircularSentence(string sentence) {
        
        int len = sentence.length();
        if(sentence[0] != sentence[len-1]){
            return false;
        }
        for(int i=0; i<len; i++){
            if(sentence[i] == ' '){
                if(sentence[i-1] != sentence[i+1]){
                    return false;
                }
            }
        }

        return true;
    }
};