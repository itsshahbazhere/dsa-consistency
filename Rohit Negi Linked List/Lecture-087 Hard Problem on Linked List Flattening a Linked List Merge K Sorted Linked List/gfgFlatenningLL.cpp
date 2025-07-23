// https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

// T.C- O(N^2M)
// S.C- O(1)
// WE CAN OPTIMISED BY MERGE SORT
class Solution {
  public:
    Node *merge(Node* &head1, Node *&head2){
        Node *head = new Node(0);
        Node *tail = head;
        
        while(head1 && head2){
            if(head1->data <= head2->data){
                tail->bottom = head1;
                tail = tail->bottom;
                head1 = head1->bottom;
                tail->bottom = NULL;
            }
            else{
                tail->bottom = head2;
                tail = tail->bottom;
                head2 = head2->bottom;
                tail->bottom = NULL;
            }
        }
        
        if(head1){
            tail->bottom = head1;
        }
        else{
            tail->bottom = head2;
        }
        
        tail = head;
        head = head->bottom;
        delete tail;
        
        return head;
    }
    
    Node *flatten(Node *root) {
        
        if(root == NULL) return root;
        
        Node *head1 = root;
        
        while(head1->next){
            
            Node *head2 = head1->next;
            Node *head3 = head1->next->next;
            
            head1->next = NULL;
            head2->next = NULL;
            head1 = merge(head1, head2);
            
            head1->next = head3;
        }
        
        root = head1;
        
        return head1;
        
        
    }
};