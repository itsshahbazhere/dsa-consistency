// https://leetcode.com/problems/majority-element/


// optimal approach
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int cnt = 0;
        int ele = INT_MIN;

        for(int i=0; i<nums.size(); i++){

            if(cnt == 0){
                ele = nums[i];
                cnt++;
            }
            else if(ele == nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }

        }

        int cnt1 = 0;
        for(int i=0; i<nums.size(); i++){
            if(ele == nums[i]){
                cnt1++;
                if(cnt1>nums.size()/2){
                    return ele;
                }
            }
        }

        return -1;
        
    }
};


// TIME COMPLEXITY: O(nlogn)
// SPACE COMPLEXITY: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int cnt=1, i=0;

        while(i<n){

            if(cnt>n/2) return nums[i];
            if(nums[i] == nums[i+1]) cnt++;
            else cnt=1;
            i++;
        }
        return -1;
    }
};