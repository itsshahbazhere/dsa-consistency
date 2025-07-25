https://www.geeksforgeeks.org/problems/get-min-at-pop/1?page=1&category=Stack&difficulty=Easy&sortBy=submissions

// T.C- O(N)
// S.C- O(N)

// Function to push all the elements into the stack.
stack<int> _push(int arr[], int n) {
    
    stack<int>st;
    
    for(int i=0; i<n; i++){
        if(st.empty()){
            st.push(arr[i]);
        }
        else{
            st.push(min(st.top(),arr[i]));
        }
    }
    return st;
}

// Function to print minimum value in stack each time while popping.
void _getMinAtPop(stack<int> s) {
    
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
 
}
