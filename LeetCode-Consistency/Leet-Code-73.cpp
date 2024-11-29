// https://leetcode.com/problems/set-matrix-zeroes/description/


//optimal solution
// my approach-3
// TIME COMPLEXITY: O(row*col)             
// SPACE COMPLEXITY: O(1)       


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {


        int rowSize = matrix.size();
        int colSize = matrix[0].size();


        int row0 = 1;
        int col0 = 1;

        for(int i=0; i<rowSize; i++){
            for(int j=0; j<colSize; j++){
                if(matrix[i][j] == 0){
                    if(i!=0){
                        matrix[i][0] = 0;
                    }
                    else{
                        row0 = 0;
                    }
                    if(j!=0){
                        matrix[0][j] = 0;
                    }
                    else{
                        col0 = 0;
                    }
                }
            }
        } 


        for(int i=1; i<rowSize; i++){
            for(int j=1; j<colSize; j++){
                if(matrix[i][0]==0 || matrix[0][j] == 0){
                    if(matrix[i][j]!=0){
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        if(col0 == 0){
            for(int i=0; i<rowSize; i++){
                matrix[i][0] = 0;
            }
        }
        if(row0 == 0){
            for(int i=0; i<colSize; i++){
                matrix[0][i] = 0;
            }
        }
        
    }
};




// my approach-2
// TIME COMPLEXITY: O(n^2)              if row=col= n
// SPACE COMPLEXITY: O(n)               if row=col =n
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {


        int row = matrix.size();
        int col = matrix[0].size();

        vector<int>markRow(row,0);
        vector<int>markCol(col,0);

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j] == 0){
                    markRow[i] = 1;
                    markCol[j] = 1;
                }
            }
        }

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(markRow[i] || markCol[j]){
                    matrix[i][j] = 0;
                }
            }
        }
        
    }
};





// my approach-1
// k = no of 0's, m = no of rows, n = no of cols 
// TIME COMPLEXITY: O((n*m) + k.(m+n))
// SPACE COMPLEXITY: O(k)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int row = matrix.size();
        int col = matrix[0].size();
        
        vector<vector<int>>temp;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j] == 0){
                    temp.push_back({i,j});
                }
            }
        }

        int rowIndex = 0;
        while(rowIndex<temp.size()){

            for(int i=0; i<col; i++){
                matrix[temp[rowIndex][0]][i] = 0;
            }
            for(int j=0; j<row; j++){
                matrix[j][temp[rowIndex][1]] = 0;
            }
            rowIndex++;

        }
        
    }
};