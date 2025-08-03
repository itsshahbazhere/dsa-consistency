// https://leetcode.com/problems/largest-rectangle-in-histogram/


// T.C- O(N^2)
// S.C- O(N)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        stack<int>st;
        int ans = 0;

        for(int i=0; i<n; i++){

            while(!st.empty() && heights[st.top()]>heights[i]){
                int index = st.top();
                st.pop();
                if(!st.empty()){
                    ans = max(ans, heights[index]*(i-st.top()-1));
                }
                else{
                    ans = max(ans, heights[index]*i);
                }
            }
            st.push(i);
        }

        while(!st.empty()){
            int index = st.top();
            st.pop();
            if(!st.empty()){
                ans = max(ans, heights[index]*(n-st.top()-1));
            }
            else{
                ans = max(ans, heights[index]*n);
            }
        }


        return ans;
    }
};



// iteration in 3 loop optimized solution is first one
// T.C- O(N)
// S.C- O(N)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        vector<int>left(n);
        vector<int>right(n);
        stack<int>st;

        //right smallest
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()){
            right[st.top()] = n;
            st.pop();
        }

        //left smalllest
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] > heights[i]){
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()){
            left[st.top()] = -1;
            st.pop();
        }

        int ans = 0;

        for(int i=0; i<n; i++){
            int area = heights[i]*(right[i]-left[i]-1);
            ans = max(ans, area);
        }

        return ans;

    }
};