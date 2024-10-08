//https://leetcode.com/problems/reverse-integer/

class Solution {
public:
    int reverse(int x) {
        int ans=0;
        while(x!=0){
           int rem=x%10;
            if(ans>INT_MAX/10 || ans<INT_MIN/10){
                return 0;
            }
           ans=ans*10+rem;
           x=x/10;
        }
        return ans;
    }
};


// Example 1:

// Input: x = 123
// Output: 321
// Example 2:

// Input: x = -123
// Output: -321
// Example 3:

// Input: x = 120
// Output: 21