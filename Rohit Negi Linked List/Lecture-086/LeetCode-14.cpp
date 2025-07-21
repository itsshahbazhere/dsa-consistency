// https://leetcode.com/problems/add-two-numbers/


class Solution {
public:
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;

        ListNode* node = new ListNode(0);
        ListNode* tail = node;
        int carry = 0;

        while(curr1 && curr2){
            int sum = curr1->val + curr2->val + carry;
            tail->next = new ListNode(sum%10);
            tail = tail->next;
            curr1 = curr1->next;
            curr2 = curr2->next;
            carry = sum/10;
        }

        while(curr1){
            int sum = curr1->val + carry;
            tail->next = new ListNode(sum%10);
            tail = tail->next;
            curr1 = curr1->next;
            carry = sum/10;
        }
        
        while(curr2){
            int sum = curr2->val + carry;
            tail->next = new ListNode(sum%10);
            tail = tail->next;
            curr2 = curr2->next;
            carry = sum/10;
        }
        
        if(carry>0){
            tail->next = new ListNode(carry);
            tail = tail->next;
        }

        return node->next;

        
    }
};