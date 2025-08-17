/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
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