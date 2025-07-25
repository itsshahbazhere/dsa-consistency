// https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1?page=2&category=Stack&difficulty=Easy&sortBy=submissions

// T.C- O(N)
// S.C- O(N)

class Solution {
  public:
    stack<int> insertAtBottom(stack<int> st, int x) {
        
        stack<int>s;
        
        while(!st.empty()){
            s.push(st.top());
            st.pop();
        }
        
        st.push(x);
        
        while(!s.empty()){
            st.push(s.top());
            s.pop();
        }
        
        return st;
    }
};