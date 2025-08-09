// https://www.geeksforgeeks.org/problems/inorder-traversal/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Tree&sortBy=submissions

class Solution {
  public:
    void inOrd(vector<int>&ans ,Node* root){
        if(root == NULL) return;
        inOrd(ans,root->left);
        ans.push_back(root->data);
        inOrd(ans,root->right);
    }
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        vector<int>ans;
        inOrd(ans,root);
        return ans;
    }
};