// https://www.geeksforgeeks.org/problems/postorder-traversal/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Tree&sortBy=submissions

class Solution {
  public:
    void postOrd(vector<int>&ans ,Node* root){
        if(root == NULL) return;
        postOrd(ans,root->left);
        postOrd(ans,root->right);
        ans.push_back(root->data);
    }
    
    vector<int> postOrder(Node* root) {
        vector<int>ans;
        postOrd(ans, root);
        return ans;
    }
};