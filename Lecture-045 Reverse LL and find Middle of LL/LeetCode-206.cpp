// https://leetcode.com/problems/reverse-linked-list/description/

// Array approach

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        vector<int>ans;
        ListNode* curr = head;
        while(curr){
            ans.push_back(curr->val);
            curr = curr->next;
        }

        curr = head;
        int i = ans.size()-1;
        while(curr){
            curr->val = ans[i];
            i--;
            curr = curr->next;
        }

        return head;
    }
};


// Iterative approach

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if(head == NULL || head->next == NULL) return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = curr;

        while(curr!=NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        head = prev;
        return head;
    }
};

//recursion approach

class Solution {
public:
    ListNode* reverseRecursive(ListNode* prev, ListNode* curr){
        if(curr == NULL){
            return prev;
        }
        ListNode* fut = curr->next;
        curr->next = prev;
        return reverseRecursive(curr, fut);
    }
    ListNode* reverseList(ListNode* head) {
        return reverseRecursive(NULL, head);
    }
};