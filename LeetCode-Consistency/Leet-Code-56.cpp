// https://leetcode.com/problems/merge-intervals/description/

// TIME COMPLEXITY: O(nlogn)
// SPACE COMPLEXITY: O(n)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        //if its not already sorted then
        sort(intervals.begin(), intervals.end());

        vector<vector<int>>ans;
        
        int row = intervals.size();

        for(int i=0; i<row; i++){

            if(ans.empty() || ans.back()[1] < intervals[i][0]){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1] = max(intervals[i][1], ans.back()[1]);
            }

        }

        return ans;
        
    }
};