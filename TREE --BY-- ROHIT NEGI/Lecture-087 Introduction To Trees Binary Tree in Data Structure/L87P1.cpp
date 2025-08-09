#include<iostream>
#include<queue>
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

int main(){

    int x, first, second;
    queue<Node*>q;
    cout<<"Enter root element: ";
    cin>>x;
    Node *root = new Node(x);
    q.push(root);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();

        //creating left node
        cout<<"Enter left element of "<<temp->data<<": ";
        cin>>first;
        if(first!=-1){
            temp->left = new Node(first);
            q.push(temp->left);
        }


        //creating right node
        cout<<"Enter right element of "<<temp->data<<": ";
        cin>>second;
        if(second!=-1){
            temp->right = new Node(second);
            q.push(temp->right);
        }

    }
}


/*

        1
       / \
      2   3
     / \  /
    4   5 10
       /
      50

*/
