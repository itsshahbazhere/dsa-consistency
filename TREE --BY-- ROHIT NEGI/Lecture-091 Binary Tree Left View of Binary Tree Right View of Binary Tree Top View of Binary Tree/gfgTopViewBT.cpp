// https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1?page=1&difficulty%5B%5D=1&category%5B%5D=Tree&sortBy=submissions



// T.C - O(n)
// S.C - O(n)
// recursive solution

class Solution {
  public:
    void find(Node* root, int pos, int &l, int &r){
        if(!root) 
        return;
        
        l = min(l,pos);
        r = max(r,pos);
        find(root->left, pos-1,l,r);
        find(root->right, pos+1,l,r);
        
    }
    void tView(Node* root, vector<int>&ans, vector<int>&level, int pos, int lev){
        if(!root)
        return;
        
        if(level[pos]>lev){
            level[pos] = lev;
            ans[pos] = root->data;
        }
        
        tView(root->left, ans,level,pos-1,lev+1);
        tView(root->right,ans,level,pos+1,lev+1);
    }
    vector<int> topView(Node *root) {
        
        int l = 0;
        int r = 0;
        find(root,0,l,r);
        
        vector<int>ans(r-l+1);
        vector<int>level(r-l+1,INT_MAX);
        
        tView(root,ans,level,-1*l,0);
        
        
        return ans;
        
    }
};




// T.C - O(n)
// S.C - O(n)

class Solution {
  public:
    void find(Node* root, int pos, int &l, int &r){
        if(!root) 
        return;
        
        l = min(l,pos);
        r = max(r,pos);
        find(root->left, pos-1,l,r);
        find(root->right, pos+1,l,r);
        
    }
    vector<int> topView(Node *root) {
        
        int l = 0;
        int r = 0;
        find(root,0,l,r);
        vector<int>ans(r-l+1);
        vector<bool>filled(r-l+1,0);
        queue<Node*>q;
        queue<int>index;
        q.push(root);
        index.push(-1*l);
        
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            int pos = index.front();
            index.pop();
            
            if(!filled[pos]){
                filled[pos] = 1;
                ans[pos] = temp->data;
            }
            
            if(temp->left){
                q.push(temp->left);
                index.push(pos-1);
            }
            if(temp->right){
                q.push(temp->right);
                index.push(pos+1);
            }
            
        }
        
        return ans;
        
    }
};