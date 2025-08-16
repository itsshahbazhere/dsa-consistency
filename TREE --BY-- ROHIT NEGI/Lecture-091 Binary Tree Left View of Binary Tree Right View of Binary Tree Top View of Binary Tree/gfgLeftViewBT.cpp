// https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1?page=1&difficulty%5B%5D=0&category%5B%5D=Tree&sortBy=submissions


// approach - 2 recursive
// T.C - O(n)
// S.C - O(n)

class Solution {
  public:
    void lview(Node* root, int level, vector<int>&ans){
        if(!root)
        return;
        
        if(ans.size() == level)
        ans.push_back(root->data);
        
        lview(root->left, level+1, ans);
        lview(root->right, level+1, ans);
    }
    vector<int> leftView(Node *root) {
        
        vector<int>ans;
        lview(root,0,ans);
        
        return ans;
        
    }
};



// approach -1
// T.C - O(n)
// S.C - O(n)

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int>ans;
        queue<Node*>q;
        if(root) q.push(root);
        
        while(!q.empty()){
            int cnt = q.size();
            ans.push_back(q.front()->data);
            while(cnt--){
                Node* temp = q.front();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                q.pop();
            }
        }
        
        return ans;
        
    }
};