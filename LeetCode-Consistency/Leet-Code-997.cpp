// https://leetcode.com/problems/find-the-town-judge/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        int size = trust.size();
        vector<int>temp(n+1,0);

        for(int i=0; i<size; i++){
            temp[ trust[i][0] ]--; //decreasing bcz judge trust noBody (if judge come then -1)
            temp[ trust[i][1] ]++; //counting total trust 
        }

        for(int i=1; i<=n; i++){
            /* only n-1 people trust judge bcz n is itself judge (if judge will not come in
        trust to people part it will execute or if all people is present in this trust array)*/

            if(temp[i] == n-1){ 
                return i;
            }
        }

        return -1;
        
        
    }
};