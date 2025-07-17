// https://leetcode.com/problems/middle-of-the-linked-list/description/

//slow fast pointer approach

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head, *fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};



// normal approach
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        int count = 0;
        ListNode* temp = head;

        while(temp){
            count++;
            temp = temp->next;
        }

        count/=2;
        temp = head;
        while(count--){
            temp = temp->next;
        }
        return temp;

    }
};