// https://www.geeksforgeeks.org/problems/sum-of-binary-tree/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Tree&sortBy=submissions


// Approach - 2
// T.C - O(N)
// S.C - O(N)

class Solution {
  public:
    int sumBT(Node* root) {
        if(root == NULL)
            return 0;
        return root->data + sumBT(root->left) + sumBT(root->right);
        
    }
};


// Approach - 1
// T.C - O(N)
// S.C - O(N)

class Solution {
  public:
    int total(Node* root, int &cnt){
        if(root == NULL)
            return 0;
            
        cnt += root->data;
        total(root->left, cnt);
        total(root->right, cnt);
        
        return cnt;
    }
    int sumBT(Node* root) {
        
        int cnt = 0;
        total(root,cnt);
        return cnt;
        
    }
};

