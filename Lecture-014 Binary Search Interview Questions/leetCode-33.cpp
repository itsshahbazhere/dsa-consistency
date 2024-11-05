// 33. Search in Rotated Sorted Array
// link:https://leetcode.com/problems/search-in-rotated-sorted-array/description/

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n=nums.size();

        int pivot=getPivotIdx(nums,n);
    
        if(target>= nums[pivot] && target<= nums[n-1]){
            return binarySearch(nums,pivot,n-1,target);
        }
        else{//k>= arr[0] && k< arr[pivot]
            return binarySearch(nums,0,pivot-1,target);
        }
    }

    int getPivotIdx(vector<int>&arr,int n){
         
        int start=0;
        int end=n-1;
        int mid= start + (end-start)/2;

        while(start<end){
            
            if(arr[mid]>=arr[0]){
                start=mid+1;
            }
            else{
                end=mid;
            }

            mid= start + (end-start)/2;

        }
        return start;
    }

    int binarySearch(vector<int>&arr, int start, int end, int key){


        int mid=start+(end-start)/2;

        while(start<=end){

            if(arr[mid]==key){
                return mid;
            }
            else if(arr[mid]>key){
                end=mid-1;
            }
            else{//arr[mid]<key
                start=mid+1;
            }

            mid=start+(end-start)/2;
        }
        return -1;
    }

};






//also written as---
class Solution {
private:
    int pivotIdx(vector<int>& nums, int target){

        int start = 0;
        int end = nums.size()-1;
        int mid =  start+ (end-start)/2;

        while(start<end){
            if(nums[start] < nums[end]){
                return start;
            }
            else if(nums[0] <= nums[mid]){
                start = mid+1;
            }
            else{
                end = mid;
            }
            mid =  start+ (end-start)/2;
        }

        return start;
    }

    int binarySearch(int start, int end, int target, vector<int>&nums){

        int mid = start+(end-start)/2;
        while(start<=end){
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid]>target){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
            mid = start+(end-start)/2;
        }

        return -1;

    }
   
public:
    int search(vector<int>& nums, int target) {
        int pivotIndex = pivotIdx(nums,target);
        int search1 = binarySearch(0, pivotIndex-1, target, nums);
        int search2 = binarySearch(pivotIndex, nums.size()-1, target ,nums);
        
        if(search1 != -1){
            return search1;
        }

        return search2;

    }
};