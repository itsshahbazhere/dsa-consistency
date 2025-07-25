// https://www.geeksforgeeks.org/problems/make-the-array-beautiful--170647/1

// T.C- O(N)
// S.C- O(N)


class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        
        stack<int>st;
        
        
        for(int i=0; i<arr.size(); i++){
            if(st.empty()){
                st.push(arr[i]);
            }
            else{
                if(st.top()>=0){
                    if(arr[i]>=0){
                        st.push(arr[i]);
                    }
                    else{
                        st.pop();
                    }
                }
                else{
                    if(arr[i]<0){
                        st.push(arr[i]);
                    }
                    else{
                        st.pop();
                    }
                }
            }
        }
        
        
        vector<int>ans(st.size());
        
        int i = st.size()-1;
        while(!st.empty()){
            ans[i--] = st.top();
            st.pop();
        }
        
        return ans;
        
    }
};
