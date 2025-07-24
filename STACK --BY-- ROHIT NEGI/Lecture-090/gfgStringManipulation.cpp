// https://www.geeksforgeeks.org/problems/string-manipulation3706/1?page=1&difficulty%5B%5D=0&category%5B%5D=Stack&sortBy=submissions

// T.C- O(N)
// S.C- O(N)

class Solution {
  public:
    int removeConsecutiveSame(vector<string>& arr) {
        
        stack<string>st;
        
        for(int i=0; i<arr.size(); i++){
            if(st.empty()){
                st.push(arr[i]);
            }
            else{
                if(st.top() == arr[i]){
                    st.pop();
                }
                else{
                    st.push(arr[i]);
                }
            }
        }
        
        return st.size();
    }
};