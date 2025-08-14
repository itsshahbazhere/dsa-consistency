// https://leetcode.com/problems/cousins-in-binary-tree/

// my approach
// T.C - O(n)
// S.C - O(n)

class Solution {
public:
    bool parent(TreeNode* root, int x, int y){
        
        if(!root)
            return 0;
        if(root->left && root->right){
            if((root->left->val == x && root->right->val == y) || (root->right->val == x && root->left->val == y)){
                return 1;
            }
        }

        return parent(root->left,x,y) || parent(root->right,x,y);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        
        queue<TreeNode*>q;
        q.push(root);

        int level = 0, xLevel = -1, yLevel = -1;
       
        while(!q.empty()){
            int cnt = q.size();
            while(cnt--){
                TreeNode* temp = q.front();
                if(temp->val == x){
                    xLevel = level;
                }
                if(temp->val == y){
                    yLevel = level;
                }
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                q.pop();

            }

            level++;

            if(xLevel != yLevel)
                return 0;
            if(xLevel != -1) // yLevel != -1 both same
                break;
        }

        return !parent(root,x,y);
    }
};