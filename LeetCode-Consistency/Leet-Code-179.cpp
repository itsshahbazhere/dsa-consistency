// https://leetcode.com/problems/largest-number/description/

// TIME COMPLEXITY = O(nlogn)
// SPACE COMPLEXITY = O(1)


class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        auto myComparator = [](int &num1, int &num2){
            string s1 = to_string(num1);
            string s2 = to_string(num2);

            // if(s1+s2 > s2+s1){
            //     return true;
            // }
            // return false;

            return s1+s2>s2+s1;

        };

        sort(begin(nums), end(nums), myComparator);  //Comparator Using Lambda Expression

        // if(nums[0] == 0){
        //     return "0";
        // }

        string result = "";
        for(int i=0; i<nums.size(); i++){
            result += to_string(nums[i]);
        }

        if(result[0] == '0'){
            return "0";
        }

        return result;
    }
};