// https://leetcode.com/problems/find-lucky-integer-in-an-array/

class Solution {
public:
    int findLucky(vector<int>& arr) {

        vector<int>count(501, 0);

        for(int i=0;i<arr.size();i++){
            int index = arr[i];
            count[index]++;
        }

        int ans = -1;
        for(int i=1; i<=500; i++){
            if(i==count[i]){
                ans = i;
            }
        }

        return ans;

    }
};