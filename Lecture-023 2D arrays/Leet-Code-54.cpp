// https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int>ans;

        int row = matrix.size();
        int col = matrix[0].size();

        int totalElement = row*col;

        int startRow = 0;
        int startCol = 0;
        int endRow = row-1;
        int endCol = col-1;

        int cnt = 0;

        while(cnt < totalElement){

            //printing first row
            for(int i=startCol; cnt < totalElement && i<=endCol; i++){
                ans.push_back(matrix[startRow][i]);
                cnt++;
            }
            startRow++;

            //printing lastCol
            for(int i=startRow; cnt < totalElement && i<=endRow; i++){
                ans.push_back(matrix[i][endCol]);
                cnt++;
            }
            endCol--;

            //printing last row
            for(int i=endCol; cnt < totalElement && i>=startCol; i--){
                ans.push_back(matrix[endRow][i]);
                cnt++;
            }
            endRow--;

            //printing first col
            for(int i=endRow; cnt < totalElement && i>=startRow; i--){
                ans.push_back(matrix[i][startCol]);
                cnt++;
            }
            startCol++;

        }

        return ans;
    }
};