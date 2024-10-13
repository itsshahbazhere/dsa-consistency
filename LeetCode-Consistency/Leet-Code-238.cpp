// https://leetcode.com/problems/product-of-array-except-self/

// Time Complexity: O(n)
// Space Complexity: O(1)
//2nd approach--------optimised then previous one

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int product = 1;
        int zeroesCnt = 0;

        //calculating product except 0
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                zeroesCnt++;
                continue;
            }
            product *= nums[i];
        }
        

        for(int i=0; i<nums.size(); i++){
    
            if(zeroesCnt > 1){ //cnt>1 its means we put zeroes in all array
                nums[i] = 0;
            }
            else if(zeroesCnt == 0){ //if cnt==0 its means we put products
                int value = product/nums[i];
                nums[i] = value;
            }
            else if(nums[i] == 0){ //it means there is only one zero so,
                nums[i] = product; //we put product in 0's value
            }
            else{
                nums[i] = 0;    //in other we want to put zero
            }
        }     

        return nums;
        
    }
};


//1st approach----------------
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int>ans;
        int product = 1;
        int cnt = 0;

        //calculating product except 0
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                cnt++;
                continue;
            }
            product *= nums[i];
        }

        //if there is'nt any zero then solve directly
        if(cnt == 0){

            for(int i=0; i<nums.size(); i++){
                int value = product/nums[i];
                ans.push_back(value);
            }
    
        }

        //else there is exist any zero in array then handle those case
        else{
            for(int i=0; i<nums.size(); i++){
                if(cnt>=2){
                    ans.push_back(0);
                }
                else if(nums[i] == 0){
                    ans.push_back(product);
                }
                else{
                    ans.push_back(0);
                }
            }
        }
        

        return ans;
        
    }
};