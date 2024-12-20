// https://leetcode.com/problems/reverse-bits/

// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        uint32_t mask = 0;

        for(int i=0; i<32; i++){

            mask = (mask<<1) | (n&1);
            n = n>>1;
        }

        return mask;

    }
    
};