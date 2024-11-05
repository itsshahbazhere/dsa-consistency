// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/


// TIME COMPLEXITY: O(logn)
// SPACE COMPLEXITY: O(1)


class Solution {
private:
    int firstIndex(vector<int>& nums, int target){

        int start = 0;
        int end = nums.size()-1;
        int mid = start + (end-start)/2;

        int startIdx = -1;

        while(start<=end){

            if(nums[mid] == target){
                startIdx = mid;
                end = mid-1;
            }
            else if(nums[mid] >  target){
                end = mid -1;
            }
            else{
                start = mid +1;
            }
            mid = start + (end-start)/2;
        }

        return startIdx;

    }

    int lastIndex(vector<int>& nums, int target){

        int start = 0;
        int end = nums.size()-1;
        int mid = start + (end-start)/2;

        int endIdx = -1;

        while(start<=end){

            if(nums[mid] == target){
                endIdx = mid;
                start = mid+1;
            }
            else if(nums[mid] >  target){
                end = mid -1;
            }
            else{
                start = mid +1;
            }
            mid = start + (end-start)/2;
        }

        return endIdx;

    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int index1 = firstIndex(nums,target);
        int index2 = lastIndex(nums,target);

        return {index1, index2};
        
    }
};