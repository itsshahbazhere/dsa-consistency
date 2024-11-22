// H/W
//- Rotate a Matrix by 90 degrees:   https://leetcode.com/problems/rotate-image/description/

//optimised---
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int row = matrix.size();
        int col = matrix[0].size();

        for(int i=0; i<row; i++){
            for(int j=i; j<col; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0; i<row; i++){
            int j=0, k=col-1;
            while(j<k){
                swap(matrix[i][j++], matrix[i][k--]);
            }
        }
    }
};




class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int row = matrix.size();
        int col = matrix[0].size();

        //step 1: transpose the matrix
        vector<vector<int>>tMatrix(col,vector<int>(row));

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                tMatrix[j][i] = matrix[i][j];
            }
        }

        //step 2: reverse each row

        for(int i=0;i<row;i++){

            int s=0;
            int e=col-1;
            while(s<e){
                swap(tMatrix[i][s++],tMatrix[i][e--]);
            }            
        }


        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                matrix[i][j] = tMatrix[i][j];
            }
        }
       
    }
};