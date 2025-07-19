// https://www.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

//approach-2 TC-O(N) SC-O(1)
class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        
        Node* curr = head1;
    
        while(curr->next != NULL){
            curr = curr->next;
        }
        
        curr->next = head1;
        
        Node *slow = head2, *fast = head2;
        
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        
        if(fast == NULL || fast->next == NULL) return NULL;
        
        slow = head2;
        
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        
        return slow;
        
    }
};




// approach-1 TC-O(N) SC-O(1)
class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        
        if(head1 == NULL || head2 == NULL) return NULL;
        Node *curr1 = head1, *curr2 = head2;
        
        int cnt1 = 1 , cnt2 = 1;
        
        while(curr1){
            curr1 = curr1->next;
            cnt1++;
        }
        while(curr2){
            curr2 = curr2->next;
            cnt2++;
        }
        
        curr1 = head1, curr2 = head2;
    
    
        while(cnt1>cnt2){
            curr1 = curr1->next;
            cnt1--;
        }
      
        while(cnt2>cnt1){
            curr2 = curr2->next;
            cnt2--;
        }
        
        while(curr1 != curr2){
            curr1 = curr1->next;
            curr2 = curr2->next;
            if(curr1 == NULL || curr2 == NULL) return NULL;
        }
        
        return curr1;
        
        
    }
};