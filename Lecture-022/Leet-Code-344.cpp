// - Reverse a String: https://leetcode.com/problems/reverse-string/description/

class Solution {
public:
    void reverseString(vector<char>& s) {

        int len = s.size();
        int start=0;
        int end = len -1;
        while(start<end){
            swap(s[start++] , s[end--]);
        }
        
    }
};