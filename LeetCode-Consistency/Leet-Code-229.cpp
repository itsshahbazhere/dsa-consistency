// https://leetcode.com/problems/majority-element-ii/description/


// TIME COMPLEXITY: O(n)             
// SPACE COMPLEXITY: O(1)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        //only two element will majority element bcz cnt of majority is >n/3

        int cnt1 = 0, cnt2 = 0;
        int ele1 = INT_MIN, ele2 = INT_MIN;

        for(int i=0; i<nums.size(); i++){

            if(cnt1 == 0 && ele2 != nums[i]){
                ele1 = nums[i];
                cnt1++;
            }
            else if(cnt2 == 0 && ele1 != nums[i]){
                ele2 = nums[i];
                cnt2++;
            }
            else if(ele1 == nums[i]){
                cnt1++;
            }
            else if(ele2 == nums[i]){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0, cnt2 = 0;

        vector<int>ans; //in worst case only 2 element will store so O(1)
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == ele1) cnt1++;
            if(nums[i] == ele2) cnt2++;
             
        }

        if(cnt1>nums.size()/3) ans.push_back(ele1);
        if(cnt2>nums.size()/3) ans.push_back(ele2);

        return ans;
        
    }
};



// TIME COMPLEXITY: O(nlogn)             
// SPACE COMPLEXITY: O(n) 

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int>ans;
        int cnt = 1;

        int i=0;
        while(i<n){
            
            if(i+1<n && nums[i] == nums[i+1]){
                cnt++;

            }
            else{
                if(cnt>n/3){
                    ans.push_back(nums[i]);
                }
                cnt = 1;
            }
            i++;
        }

        return ans;
        
    }
};