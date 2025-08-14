// https://leetcode.com/problems/count-complete-tree-nodes/submissions/1730192858/


// Approach - 2
// T.C - O(N)
// S.C - O(N)

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return  0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};


// Approach - 1
// T.C - O(N)
// S.C - O(N)
class Solution {
public:
    int preOrder(TreeNode* root, int &cnt){
        if(root == NULL) 
            return 0;
        cnt++;
        preOrder(root->left,cnt);
        preOrder(root->right,cnt);
        return cnt;
    }
    int countNodes(TreeNode* root) {
        int cnt = 0;
        preOrder(root,cnt);
        return cnt;

    }
};
