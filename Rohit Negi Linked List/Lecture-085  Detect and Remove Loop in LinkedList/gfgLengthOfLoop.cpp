// https://www.geeksforgeeks.org/problems/find-length-of-loop/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab


//without making function clean code

class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        
        Node *slow = head, *fast = head;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        
        //if loop is break there is only two posibility ---
        
        // 1st
        if(fast == NULL || fast->next == NULL) return 0; 
        
        //2nd slow == fast
        
        int cnt = 1;
        slow = slow->next;
        while(slow!=fast){
            slow = slow->next;
            cnt++;
        }
        
        return cnt;
        
    }
};


//with making function
class Solution {
  public:
    
    Node* isLoop(Node *head){
        if(head == NULL || head->next == NULL) return NULL;
        
        Node* slow = head, *fast = head;
        
        while(fast){
            slow = slow->next;
            fast = fast->next;
            if(fast){
                fast = fast->next;
            }
            
            if(slow == fast){
                return slow;
            }
        }
        
        return NULL;
    }
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        
        Node *slow = isLoop(head), *fast = isLoop(head);
        if(slow == NULL){
            return 0;
        }
        
        int cnt = 1;
        slow = slow->next;
        while(slow!=fast){
            slow = slow->next;
            cnt++;
        }
        
        return cnt;
        
    }
};