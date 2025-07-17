// https://leetcode.com/problems/palindrome-linked-list/description/

//extra space complexity O(n) for vector<int>v
class Solution {
public:
    bool isPalindrome(ListNode* head) {

        ListNode *temp = head;
        vector<int>v;

        while(temp){
            v.push_back(temp->val);
            temp = temp->next;
        }

        int i=0, j=v.size()-1;
        while(i<=j){
            if(v[i++] != v[j--]){
                return 0;
            }
        }

        return 1;
    }
};


//optimized way O(n) time and O(1) space

class Solution {
public:
    bool isPalindrome(ListNode* head) {

        if(head->next == NULL) return 1;
        ListNode* temp = head;
        int cnt = 0;
        while(temp){
            temp= temp->next;
            cnt++;
        }

        cnt/=2;
        ListNode *prev = NULL, *curr = head, *fut = NULL;

        while(cnt--){
            prev = curr;
            curr = curr->next;
        }

        prev->next = NULL;
        prev = NULL;
        while(curr){
            fut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fut;
        }

        ListNode *head1 = head, *head2 = prev;

        while(head1){
            if(head1->val != head2->val){
                return 0;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        return 1;
    }
};