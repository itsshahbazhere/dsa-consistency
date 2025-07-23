// https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

class Solution {
  public:
    
    Node* reverse(Node *curr, Node *prev){
        if(curr == NULL) return prev;

        Node *fut = curr->next;
        curr->next = prev;
        return reverse(fut,curr);
    }
    Node* addTwoLists(Node* num1, Node* num2) {
        
        Node* curr1 = reverse(num1,NULL);
        Node* curr2 = reverse(num2,NULL);

        Node* node = new Node(0);
        Node* tail = node;
        int carry = 0;

        while(curr1 && curr2){
            int sum = curr1->data + curr2->data + carry;
            tail->next = new Node(sum%10);
            tail = tail->next;
            curr1 = curr1->next;
            curr2 = curr2->next;
            carry = sum/10;
        }

        while(curr1){
            int sum = curr1->data + carry;
            tail->next = new Node(sum%10);
            tail = tail->next;
            curr1 = curr1->next;
            carry = sum/10;
        }
        
        while(curr2){
            int sum = curr2->data + carry;
            tail->next = new Node(sum%10);
            tail = tail->next;
            curr2 = curr2->next;
            carry = sum/10;
        }

        if(carry>0){
            tail->next = new Node(carry);
            tail = tail->next;
        }
        
        //delete 1st 0 node
        Node *node1 = node;
        node = node->next;
        delete node1;

        //reverse ans
        Node *head = reverse(node, NULL);
        
        //delete leading 0 node
        while( head!=NULL && head->next!=NULL && head->data == 0){
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        
        return head;
        
    }
};