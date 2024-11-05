// 724. Find Pivot Index
// link: https://leetcode.com/problems/find-pivot-index/description/


//approach 2 beats 100% 
// TIME COMPLEXITY - O(n)
// SPACE COMPLEXITY - O(1)

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int total = 0;
        for(int i=0; i<nums.size(); i++){
            total += nums[i];
        }

        int left_total = 0;
        for(int i=0; i<nums.size(); i++){

            left_total += nums[i]; // 1 8 11 17
            if(left_total == total){ // 1=28 8=27 11=20 17=17 return i
                return i;
            }
            total -= nums[i]; //27 20 17
        }


        return -1;
    }
};


//approach 1 
// TIME COMPLEXITY - O(n)
// SPACE COMPLEXITY - O(n)

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int prefix_sum = 0;
        int suffix_sum = 0;
        int n =nums.size();

        vector<int>prefix(n);
        vector<int>suffix(n);

        for(int i=0; i<n; i++){
            prefix_sum += nums[i];
            prefix[i] = prefix_sum;
        }

        for(int i=n-1; i>=0; i--){
            suffix_sum += nums[i];
            suffix[i] = suffix_sum;
        }

        for(int i=0; i<n; i++){
            if(prefix[i] == suffix[i]){
                return i;
            }
        }


        return -1;
    }
};