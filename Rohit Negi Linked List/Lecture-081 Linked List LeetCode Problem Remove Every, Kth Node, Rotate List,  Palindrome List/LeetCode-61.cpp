// https://leetcode.com/problems/rotate-list/description/


// O(n) extra space vector method
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL) return head;
        vector<int>arr;

        ListNode *temp = head;

        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }

        int size = arr.size();
        temp = head;

        for(int i=size-k%size; i<size; i++){
            temp->val = arr[i];
            temp = temp->next;
        }

        for(int j=0; j<size-k%size; j++){
            temp->val = arr[j];
            temp = temp->next;
        }
        

        return head;


    }
};


//direct node rotate optimized way
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL) return head;
        ListNode *prev = NULL, *curr = head;
        int len = 0;
        while(curr){
            curr=curr->next;
            len++;
        }

        int cnt = k%len;//7%5=2 //2%5=2
        if(cnt == 0) return head; //edge case it also handle if (head->next == NULL) 
        cnt = len-cnt; //5-2 //5-2 = 3
        curr = head;

        while(cnt--){
            prev = curr;
            curr = curr->next;
        }

        prev->next = NULL;
        prev = curr;
        while(curr->next!=NULL){
            curr=curr->next;
        }

        curr->next = head;
        head = prev;
        return head;



    }
};