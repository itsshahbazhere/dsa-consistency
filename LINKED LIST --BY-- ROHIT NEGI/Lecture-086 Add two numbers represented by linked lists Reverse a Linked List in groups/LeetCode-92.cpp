// https://leetcode.com/problems/reverse-linked-list-ii/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        int cnt = 1;
        
        ListNode *first = NULL;
        ListNode *second = head;
        
        while(cnt<left){
            first = second;
            second = second->next;
            cnt++;
        }
        
        ListNode *prev = first;
        ListNode *curr = second;
        while(cnt<=right){
            ListNode *fut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fut;
            cnt++;
        }
        
        if(first){
            first->next = prev;
        }
        else{
            head = prev;
        }
        second->next = curr;
        
        return head;
    }
};