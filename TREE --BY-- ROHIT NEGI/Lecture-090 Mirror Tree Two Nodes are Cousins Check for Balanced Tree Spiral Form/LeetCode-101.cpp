// https://leetcode.com/problems/symmetric-tree/

class Solution {
public:
    bool check(TreeNode* real, TreeNode* mirror){
        if(!real && !mirror)
            return 1;
        else if((!real && mirror) || (!mirror && real)){
            return 0; 
        }
        if(real->val != mirror->val)
            return 0;
        return check(real->left, mirror->right) && check(real->right, mirror->left);
    }
    bool isSymmetric(TreeNode* root) {
        
        return check(root->left, root->right);
    }
};