// https://leetcode.com/problems/pascals-triangle/description/

/* 
    there are three question in pascal's traingle
    1.find element at given row and col
    2.print all element of given row
    3.print entire pascal's traingle    
*/



// 3.print entire pascal's traingle --optimal approach
// TIME COMPLEXITY = O(N^2)
// SPACE COMPLEXITY = O(N^2)

class Solution {
private:
    vector<int>createRows(int rowNo){

        long long ans = 1;
        vector<int>ansRow;
        ansRow.push_back(1);
        for(int col=1; col<rowNo; col++){
            ans = ans*(rowNo-col);
            ans = ans/col;
            ansRow.push_back(ans);
        }

        return ansRow;
    }
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>>ans;
        for(int i=1; i<=numRows; i++){
            ans.push_back(createRows(i));
        }
        return ans;
        
    }
};


// 1.find element at given row and col




// 2.print all element of given row


