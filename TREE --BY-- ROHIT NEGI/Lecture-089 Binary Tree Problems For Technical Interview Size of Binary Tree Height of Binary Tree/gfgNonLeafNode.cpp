// https://www.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Tree&sortBy=submissions



// Approach - 1
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


// Approach - 1
// T.C - O(N)
// S.C - O(N)

class Solution {
  public:
    int totalNode(Node* root){
        if(root == NULL){
            return 0;
        }
        return 1+totalNode(root->left)+totalNode(root->right);
    }
    int leafNode(Node *root){
        if(root == NULL)
            return 0;
        
        if(root->left == NULL && root->right == NULL)
            return 1;
            
        return leafNode(root->left)+leafNode(root->right);
    }
    int countNonLeafNodes(Node* root) {
        
        return totalNode(root) - leafNode(root);
        
    }
};

