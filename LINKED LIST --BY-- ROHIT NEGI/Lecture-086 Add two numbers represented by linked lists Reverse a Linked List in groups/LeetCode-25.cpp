// https://leetcode.com/problems/reverse-nodes-in-k-group/

class Solution {
public:
    int length(ListNode *curr){
        int cnt = 0;
        while(curr){
            curr = curr->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *first = new ListNode(0);
        first->next = head;
        head = first;
        
        while(first->next){
            int cnt = k;
            ListNode *second = first->next;
            ListNode *prev = first;
            ListNode *curr = second;
            
            if(length(curr)<k) break; //different from gfg logic not reverse if length of curr < k

            while(cnt && curr){
                ListNode *fut = curr->next;
                curr->next = prev;
                prev = curr;
                curr = fut;
                cnt--;
            }
            
            first->next = prev;
            second->next = curr;
            first = second;
        }
        
        first = head;
        head = head->next;
        delete first;
        return head;
    }
};