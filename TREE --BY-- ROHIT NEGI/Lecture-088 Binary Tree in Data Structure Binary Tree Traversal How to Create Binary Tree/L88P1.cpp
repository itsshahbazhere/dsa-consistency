#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node *left, *right;
    Node(int value){
        data = value;
        left = right = NULL;
    }
};

void preOrder(Node *root){
    if(root == NULL) return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node *root){
    if(root == NULL) return;
    
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void postOrder(Node *root){
    if(root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

Node* binaryTree(){
    int x;
    cin>>x;

    if(x==-1){
        return NULL;
    }
    Node *temp = new Node(x);
    cout<<"Enter the left child of "<<temp->data<<": ";
    temp->left = binaryTree();
    cout<<"Enter the right child of "<<temp->data<<": ";
    temp->right = binaryTree();
    return temp;

}

int main(){

    Node *root;
    cout<<"Enter root node value: ";
    root = binaryTree();

    cout<<"Pre-Order: ";
    preOrder(root);

    cout<<endl<<"In-Order: ";
    inOrder(root);

    cout<<endl<<"Post-Order: ";
    postOrder(root);
    cout<<endl;




}



/*

------------TREE------------

        1
       / \
      2   7
     / \    \
    3   6    8
   / \      / \
  4   5    9  10


----------CREATION-----------

Enter root node value: 1
Enter the left child of 1: 2
Enter the left child of 2: 3
Enter the left child of 3: 4
Enter the left child of 4: -1
Enter the right child of 4: -1
Enter the right child of 3: 5
Enter the left child of 5: -1
Enter the right child of 5: -1
Enter the right child of 2: 6
Enter the left child of 6: -1
Enter the right child of 6: -1
Enter the right child of 1: 7
Enter the left child of 7: -1
Enter the right child of 7: 8
Enter the left child of 8: 9
Enter the left child of 9: -1
Enter the right child of 9: -1
Enter the right child of 8: 10
Enter the left child of 10: -1
Enter the right child of 10: -1


----------TRAVERSAL-----------

Pre-Order: 1 2 3 4 5 6 7 8 9 10 
In-Order: 4 3 5 2 6 1 7 9 8 10 
Post-Order: 4 5 3 6 2 9 10 8 7 1 



*/