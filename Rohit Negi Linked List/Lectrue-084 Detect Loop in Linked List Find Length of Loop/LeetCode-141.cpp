// https://leetcode.com/problems/linked-list-cycle/description/

class Solution {
public:
    
    bool hasCycle(ListNode *head) {
        
        if(head == NULL || head->next == NULL){
            return 0;
        }
        ListNode *slow = head, *fast = head;
        while(fast){
            slow = slow->next;
            fast = fast->next;
            if(fast){
                fast = fast->next;
            }
            if(slow == fast) return 1;
        }

        return 0;
    }
};