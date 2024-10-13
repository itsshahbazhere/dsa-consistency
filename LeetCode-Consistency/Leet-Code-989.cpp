// https://leetcode.com/problems/add-to-array-form-of-integer/

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {

        int carry = 0;
        int sum  = 0;
        vector<int>ans;

        for(int i=num.size()-1; i>=0; i--){

            int rem = k % 10;

            int sum = carry + rem + num[i];

            carry = sum/10;
            sum = sum%10;
            
            ans.push_back(sum);

            k = k/10;

        }

        while(k!=0){
            
            int rem = k%10;
            sum = carry + rem;

            carry = sum/10;
            sum = sum%10;

            ans.push_back(sum);
            k=k/10;
        }


        if(carry > 0){
            ans.push_back(carry);
        }
       
        reverse(ans.begin(),ans.end());

        return ans;
        
    }
};