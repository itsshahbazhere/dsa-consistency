// https://www.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Tree&sortBy=submissions


// Approach - 2
// T.C - O(N)
// S.C - O(N)

class Solution {
  public:
    int countLeaves(Node* root) {
        if(root == NULL){
            return 0;
        }
        if(root->left == NULL && root->right == NULL)
            return 1;
        return countLeaves(root->left) + countLeaves(root->right);
    }
};



// Approach - 2
// T.C - O(N)
// S.C - O(N)
class Solution {
  public:
    int total(Node *root, int &cnt){
        if(root == NULL){
            return 0;
        }
        if(root->left == NULL && root->right == NULL){
            return cnt++;
        }
        
        total(root->left, cnt);
        total(root->right, cnt);
        
        return cnt;
        
    }
    // Function to count the number of leaf nodes in a binary tree.
    int countLeaves(Node* root) {
        int cnt = 0;
        total(root, cnt);
        return cnt;
    }
};