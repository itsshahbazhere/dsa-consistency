//same as gfgMergeSortedList.cpp file

class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        Node *head = new Node(0);
        Node *curr = head;

        while(head1 && head2){
            if(head1->data <= head2->data){
                curr->next = head1;
                curr = head1;
                head1 = head1->next;
                curr->next = NULL;
            }
            else{
                curr->next = head2;
                curr = head2;
                head2 = head2->next;
                curr->next = NULL;
            }
        }
        
        if(head1){
            curr->next = head1;
        }
        else{
            curr->next = head2;
        }
        
        curr = head;
        head = head->next;
        delete curr;
        return head;
  
        return head;
        
    }
};