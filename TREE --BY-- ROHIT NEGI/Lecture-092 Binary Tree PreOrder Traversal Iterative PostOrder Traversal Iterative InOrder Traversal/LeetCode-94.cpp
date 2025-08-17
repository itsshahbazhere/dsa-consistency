// https://leetcode.com/problems/binary-tree-inorder-traversal/

// T.C - O(N)
// S.C - O(N)


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>st;
        stack<bool>check;
        if(root){
            st.push(root);
            check.push(0);
        }

        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();
            if(check.top()){
                ans.push_back(temp->val);
                check.pop();
            }
            else{
                check.pop();
                if(temp->right){
                    st.push(temp->right);
                    check.push(0);
                }
                st.push(temp);
                check.push(1);
                if(temp->left){
                    st.push(temp->left);
                    check.push(0);
                }
            }
        }

        return ans;
    }
};