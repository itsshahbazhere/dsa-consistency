// https://leetcode.com/problems/intersection-of-two-linked-lists/description/


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {


        ListNode *currA = headA, *currB = headB;

        int cnt1 = 0, cnt2 = 0;
        while(currA){
            currA = currA->next;
            cnt1++;
        }

        while(currB){
            currB = currB->next;
            cnt2++;
        }

        currA = headA ,currB = headB;

        while(cnt1>cnt2){
            currA = currA->next;
            cnt1--;
        }

        while(cnt2>cnt1){
            currB = currB->next;
            cnt2--;
        }

        while(currA != currB){
            currA=currA->next;
            currB=currB->next;
        }
        
        
        
        return currA;

    }
};