// https://leetcode.com/problems/copy-list-with-random-pointer/


class Solution {
public:
    Node* copyRandomList(Node* head) {
        

        if(head == NULL) return NULL; //edge case
        //creation of list
        Node *prev = head;
        Node *curr = head;
        
        while(prev){
            curr = prev->next;
            prev->next = new Node(prev->val);
            prev = prev->next;
            prev->next = curr;
            prev = curr;
        }
        
        Node *cloneHead = head->next;
        
        prev = head;
         
        while(prev){
            curr = prev->next;
            if(prev->random){
                curr->random = prev->random->next;
            }
            prev = curr->next;

        }
        
        prev = head;
        
        while(prev->next){
            curr = prev->next;
            prev->next = curr->next;
            prev = curr;
        }
        
        
        return cloneHead;


    }
};
