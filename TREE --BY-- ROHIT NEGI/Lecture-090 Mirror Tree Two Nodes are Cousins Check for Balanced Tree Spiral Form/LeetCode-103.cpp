// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;

        stack<TreeNode*>ltoR;
        stack<TreeNode*>rtoL;

        if(root)
            rtoL.push(root);
        
        while(!ltoR.empty() || !rtoL.empty()){
            vector<int>level;
            if(!rtoL.empty()){
                while(!rtoL.empty()){
                    TreeNode* temp = rtoL.top();
                    level.push_back(temp->val);
                    if(temp->left)
                        ltoR.push(temp->left);
                    if(temp->right)
                        ltoR.push(temp->right);
                    rtoL.pop();
                }
            }
            else{
                while(!ltoR.empty()){
                    TreeNode* temp = ltoR.top();
                    level.push_back(temp->val);
                    if(temp->right)
                        rtoL.push(temp->right);
                    if(temp->left)
                        rtoL.push(temp->left);
                    ltoR.pop();
                }
            }

            ans.push_back(level);
            
        }
        return ans;
    }
};