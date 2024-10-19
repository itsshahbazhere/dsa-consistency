// https://leetcode.com/problems/kth-largest-element-in-an-array/

//approach one optimised solution---Quick Select
// TIME COMPLEXITY worst = O(n^2) , avg = O(n)
// SPACE COMPLEXITY = O(1)

class Solution {
private:
    int partition(vector<int>& nums,int s, int e){

        int p = nums[s];

        int i = s+1;
        int j = e;
        while(i<=j){

            if(nums[i]<p && nums[j]>p){
                swap(nums[i++],nums[j--]);
            }

            //happy case
            if(nums[i] >= p){
                i++;
            }
            if(nums[j] <= p){
                j--;
            }

        }
        swap(nums[s],nums[j]);
        return j; //pivot element at jth index
    }
public:
    int findKthLargest(vector<int>& nums, int k) {

        int s = 0;
        int e = nums.size()-1;

        int pivot_idx = 0;
        while(true){

            //partition in decending order
            pivot_idx = partition(nums,s,e);

            if(pivot_idx == k-1){
                break;
            }
            else if(pivot_idx > k-1){
                e = pivot_idx -1;
            }
            else{
                s = pivot_idx +1;
            }
        }

        return nums[pivot_idx];

    }
};
















//approach one brute force---TLE
// TIME COMPLEXITY = O(n^2)
// SPACE COMPLEXITY = O(1)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        int maxi = INT_MIN;
        int cnt = 0;
        int index = -1;
        for(int i=0; i<nums.size(); i++){

            for(int j=0; j<nums.size(); j++){
                if(maxi <= nums[j]){
                    maxi = nums[j];
                    index = j;
                }

            }
            cnt++;
            if(cnt==k){
                return maxi;
            }
            nums[index] = INT_MIN;
            maxi=INT_MIN;

        }
        return -1;

    }
};