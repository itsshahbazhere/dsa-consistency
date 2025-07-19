// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

//another approach without extra space

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if(head == NULL || head->next == NULL) return head;

        ListNode *prev = head, *curr = head->next;

        while(curr){
            if(prev->val == curr->val){
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }

        return head;

    }
};



// approach 1 it take extra space O(n)

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if(head == NULL || head->next == NULL) return head;

        vector<int>v;
        v.push_back(head->val);
        ListNode* temp = head->next;
        while(temp){
            if(v[v.size()-1] != temp->val){
                v.push_back(temp->val);
            }
            temp = temp->next;
        }
        temp = head;
        for(int i=0; i<v.size(); i++){
            temp->val = v[i];
            temp = temp->next;
        }

        temp = head;
        int size = v.size()-1;
        while(size--){
            temp = temp->next;
        }
        temp->next = NULL;

        return head;

    }
};