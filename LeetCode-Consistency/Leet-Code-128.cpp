// https://leetcode.com/problems/longest-consecutive-sequence/


//approach-3 use set
// TIME COMPLEXITY - O(nlogn)
// SPACE COMPLEXITY - O(1)



//approach-2 better approach
// TIME COMPLEXITY - O(nlogn)
// SPACE COMPLEXITY - O(1)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        int longestSeq = 0;
        int cnt = 0;
        int lastSmaller = INT_MIN;

        for(int i=0;i<nums.size(); i++){
            
            if(nums[i]-1 == lastSmaller){
                cnt++;
                lastSmaller = nums[i];
            }
            else if(nums[i] != lastSmaller){
                cnt = 1;
                lastSmaller = nums[i];
            }

            longestSeq = max(longestSeq,cnt);
            
        }




        return longestSeq;
    }
};




//approach-1 bruite force
// TIME COMPLEXITY - O(n^3)
// SPACE COMPLEXITY - O(1)

class Solution {
private:
    bool ls(vector<int>& nums, int n){
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==n){
                return true;
            }
        }
        return false;
    }

public:
    int longestConsecutive(vector<int>& nums) {
        
        int longestSeq = 0;

        for(int i=0; i<nums.size(); i++){

            int cnt = 1;
            int n = nums[i];
            while(ls(nums,n+1) == true){
                cnt++;
                n = n+1;
            }
            longestSeq = max(longestSeq, cnt);

        }

        return longestSeq;
    }
};