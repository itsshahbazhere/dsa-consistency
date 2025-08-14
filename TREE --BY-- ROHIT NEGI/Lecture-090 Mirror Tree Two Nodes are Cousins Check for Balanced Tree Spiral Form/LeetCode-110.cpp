// https://leetcode.com/problems/balanced-binary-tree/


// my approach
// T.C - O(n)
// S.C - O(n)

class Solution {
public:
    int height(TreeNode* root, bool &valid){
        if(!root) return 0;

        int l = 1 + height(root->left, valid);
        int r = 1 + height(root->right, valid);

        if(abs(l-r)>1){
            valid = false;
        }

        return  max(l, r);
    }
    bool isBalanced(TreeNode* root) {
        
        bool valid = true;
        height(root, valid);

        return valid;

    }
};

// my approach
// T.C - O(n^2)
// S.C - O(n)

class Solution {
public:
    int height(TreeNode* root){
        if(!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(!root){
            return 1;
        }
        int leftHeight = 0;
        int rightHeight = 0;
        leftHeight += height(root->left);
        rightHeight += height(root->right);
        if(abs(leftHeight - rightHeight) > 1){
            return 0;
        }

        return isBalanced(root->left) && isBalanced(root->right);

    }
};