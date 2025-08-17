// https://leetcode.com/problems/binary-tree-postorder-traversal/description/

// T.C - O(N)
// S.C - O(N)

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>st;
        if(root)
        st.push(root);

        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            if(temp->left)
            st.push(temp->left);
            if(temp->right)
            st.push(temp->right);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};