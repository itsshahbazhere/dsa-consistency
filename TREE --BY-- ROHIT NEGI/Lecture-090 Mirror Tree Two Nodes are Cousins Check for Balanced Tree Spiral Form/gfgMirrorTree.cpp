// https://www.geeksforgeeks.org/problems/mirror-tree/1?page=1&difficulty%5B%5D=0&category%5B%5D=Tree&sortBy=submissions

class Solution {
  public:
    void mirror(Node* node) {
        
        if(node == NULL){
            return;
        }
        Node *temp = node->left;
        node->left = node->right;
        node->right = temp;
        
        mirror(node->left);
        mirror(node->right);
        return;
    }
};