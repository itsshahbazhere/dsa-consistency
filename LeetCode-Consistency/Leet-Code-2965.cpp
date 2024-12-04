// https://leetcode.com/problems/find-missing-and-repeated-values/submissions/1468284077/


// TIME COMPLEXITY - O(N^2)
// SPACE COMPLEXITY - O(N^2)

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        int n = grid.size();
        vector<int>ans(2);
        int totalNo = n*n;
        vector<int>count(totalNo,0);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int index = grid[i][j];
                count[index-1]++;
            }
        }

        for(int i=0;i<totalNo; i++){
            if(count[i] == 2){
                ans[0] = i+1;
            }
            if(count[i] == 0){
                ans[1] = i+1;
            }
        }

        return ans;
        
    }
};