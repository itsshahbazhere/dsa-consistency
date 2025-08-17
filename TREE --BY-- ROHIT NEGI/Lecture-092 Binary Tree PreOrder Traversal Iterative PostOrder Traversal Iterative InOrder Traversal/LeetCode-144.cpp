// https://leetcode.com/problems/binary-tree-preorder-traversal/

// T.C - O(N)
// S.C - O(N)

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        vector<int>ans;
        if(root)
        st.push(root);

        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            if(temp->right)
            st.push(temp->right);
            if(temp->left)
            st.push(temp->left);
        }

        return ans;
    }
};