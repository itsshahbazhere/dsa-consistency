// https://leetcode.com/problems/sum-of-two-integers/description/

// Time Complexity: O(1) 
// Space Complexity: O(1) 

class Solution {
public:
    int getSum(int a, int b) {

        //base case
        if(b==0) return a;
        int sum = a^b;
        int carry = (unsigned int)(a&b) << 1;
        return getSum(sum,carry);
        
    }
};