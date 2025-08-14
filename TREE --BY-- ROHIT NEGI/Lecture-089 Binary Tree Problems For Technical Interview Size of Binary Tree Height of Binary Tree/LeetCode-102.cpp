// https://leetcode.com/problems/binary-tree-level-order-traversal/

// Approach - 1
// T.C - O(N)
// S.C - O(N)


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;

        queue<TreeNode*>q;
        if(root)
            q.push(root);
        
        while(!q.empty()){
            vector<int>level;
            int cnt = q.size();
            while(cnt--){
                TreeNode* temp = q.front(); 
                level.push_back(temp->val);

                if(temp->left != NULL){
                    q.push(temp->left);
                }
                if(temp->right != NULL){
                    q.push(temp->right);
                } 
                q.pop();
            }

            ans.push_back(level);
        }

        return ans;
    }
};