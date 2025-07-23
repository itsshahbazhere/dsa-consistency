// https://www.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab



//approach 2 with const space
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

// approach 1 space takes O(n)
class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        Node *head = new Node(0);
        Node *curr = head;

        while(head1 && head2){

            if(head1->data <= head2->data){
                Node *temp = new Node(head1->data);
                curr->next = temp;
                curr = temp;
                head1 = head1->next;
            }
            else{
                Node *temp = new Node(head2->data);
                curr->next = temp;
                curr = temp;
                head2 = head2->next;
            }
        }
        
        while(head1){
            Node *temp = new Node(head1->data);
            curr->next = temp;
            curr = temp;
            head1 = head1->next;
        }
        while(head2){
            Node *temp = new Node(head2->data);
            curr->next = temp;
            curr = temp;
            head2 = head2->next;
        }
        
        curr = head;
        head = head->next;
        delete curr;
        return head;
        

        


        return head;
        
    }
};