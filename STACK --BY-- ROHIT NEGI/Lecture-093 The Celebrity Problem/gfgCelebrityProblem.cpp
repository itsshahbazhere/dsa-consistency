// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

#include<bits/stdc++.h>
using namespace std;


// approach 2
// T.C - O(N)
// S.C - O(N)

class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int row = mat.size();
        int col = mat[0].size();

        stack<int>st;
        for(int i=0; i<row; i++){
            st.push(i);
        }

        while(st.size()>1){
            int index1 = st.top();
            st.pop();
            int index2 = st.top();
            st.pop();
            if(mat[index1][index2] == 0 && mat[index2][index1] == 1){
                st.push(index1);
            }
            else if(mat[index1][index2] == 1 && mat[index2][index1] == 0){
                st.push(index2);
            }
        }
        

        if(st.empty()) return -1;

        for(int i=0; i<row; i++){
            if(mat[i][st.top()] != 1 || mat[st.top()][i] == 1){
                if(st.top() != i){
                    return -1;
                }
            }
        }

        return st.top();
    }
};




// approach - 1 
// T.C - O(N^2)
// S.C - O(1)


class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int row = mat.size();
        int col = mat[0].size();
        int celRow = -1;

        for(int i=0; i<row; i++){
            int cnt = 0;
            
            for(int j=0; j<col; j++){
                if(i==j){
                    continue;
                }
                else if(mat[i][j] == 1){
                    break;
                }
                else if(mat[i][j] == 0){
                    cnt++;
                }
            }
            if(cnt==col-1){
                celRow = i;
                break;
            }
        }
        
        for(int i=0; i<row; i++){
            if(mat[i][celRow] == 0){
                if(i!=celRow){
                    return -1;
                }
            }
        }
        
        return celRow;
    }
};


int main(){

    vector<vector<int>>mat={{1}};

    Solution obj;

    int ans = obj.celebrity(mat);

    cout<<"Celebrity index: "<<ans<<endl;

    return 0;

}
