// https://leetcode.com/problems/fizz-buzz/

// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(n)

class Solution {
public:
    vector<string> fizzBuzz(int n) {

        vector<string>ans(n);

        for(int i=0;i<n;i++){
            if((i+1)%(3*5) == 0){
                ans[i] = "FizzBuzz";
            }
            else if((i+1)%3 == 0){
                ans[i] = "Fizz";
            }
            else if((i+1)%5==0){
                ans[i] = "Buzz";
            }
            else{
                string num = to_string(i+1);
                ans[i] = num;
            }
        }
        return ans;
    }
};