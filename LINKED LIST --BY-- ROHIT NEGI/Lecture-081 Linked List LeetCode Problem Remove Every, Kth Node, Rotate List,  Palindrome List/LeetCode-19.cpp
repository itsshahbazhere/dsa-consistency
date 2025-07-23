// https://leetcode.com/problems/remove-nth-node-from-end-of-list/


// TC- O(N)
// SC- O(1)

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

            ListNode* temp = head;
            int cnt = 0;
            while(temp){
                temp=temp->next;
                cnt++;
            }

            ListNode *prev = NULL, *curr = head;

            cnt-=n; //5

            //edge case
            if(cnt == 0){
                temp = head;
                head = head->next;
                delete temp;
                return head;

            }
            while(cnt--){ //3,2 //2,3, //1,4 //0
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            delete curr;

            return head;
    }
};