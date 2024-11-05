// 153. Find Minimum in Rotated Sorted Array
// link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        //find pivot index same question
        int start=0;
        int end=nums.size()-1;
        int mid=start + (end-start)/2;

        while(start<end){

            if(nums[start]<nums[end]){ 
                break;
            }
            else if(nums[mid]>=nums[0]){ //test case [2,1]
                start=mid+1;
            }
            else{
                end=mid;
            }
            mid=start + (end-start)/2;
        }

        return nums[start];
    }
};