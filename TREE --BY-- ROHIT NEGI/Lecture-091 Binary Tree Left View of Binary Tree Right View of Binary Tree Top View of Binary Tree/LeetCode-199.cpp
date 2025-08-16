// https://leetcode.com/problems/binary-tree-right-side-view/


// approach - 2 recursive
// T.C - O(n)
// S.C - O(n)


class Solution {
public:
    void rView(TreeNode* root, int level, vector<int>&ans){
        if(!root)
        return;

        if(ans.size() == level)
        ans.push_back(root->val);

        rView(root->right, level+1, ans);
        rView(root->left, level+1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int>ans;
        rView(root,0,ans);
        return ans;
    }
};



// approach - 1
// T.C - O(n)
// S.C - O(n)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int>ans;
        queue<TreeNode*>q;
        if(root)
        q.push(root);

        while(!q.empty()){
            ans.push_back(q.front()->val);
            int size = q.size();
            while(size--){
                TreeNode* temp = q.front();
                if(temp->right) q.push(temp->right);
                if(temp->left) q.push(temp->left);
                q.pop();
            }
        }
        return ans;
    }
};