// https://www.geeksforgeeks.org/problems/preorder-traversal/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Tree&sortBy=submissions

class Solution {
  public:
    
    void pre(vector<int>&ans ,Node* root){
        if(root == NULL) return;
        ans.push_back(root->data);
        pre(ans,root->left);
        pre(ans,root->right);
    }
    
    vector<int> preorder(Node* root) {
        vector<int>ans;
        pre(ans, root);
        return ans;
    }
};