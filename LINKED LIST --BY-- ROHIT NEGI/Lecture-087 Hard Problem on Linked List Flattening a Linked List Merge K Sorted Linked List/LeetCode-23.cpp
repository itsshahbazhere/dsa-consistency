// https://leetcode.com/problems/merge-k-sorted-lists/

// T.C- O(NKlogK)
// S.C- O(1)

class Solution {
public:
    ListNode* merge(ListNode *&head1, ListNode* &head2){
        
        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        
        while(head1 && head2){
            if(head1->val <= head2->val){
                tail->next = head1;
                tail = tail->next;
                head1 = head1->next;
                tail->next = NULL;
            }
            else{
                tail->next = head2;
                tail = tail->next;
                head2 = head2->next;
                tail->next = NULL;
            }
        }
        
        if(head1){
            tail->next = head1;
        }
        else{
            tail->next = head2;
        }
        
        tail = head;
        head = head->next;
        delete tail;
        
        return head;
    }
    void mergeSort(vector<ListNode*>& arr, int start, int end){
        
        if(start >= end) return;
        
        int mid = start + (end-start)/2;
        
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        
        arr[start] = merge(arr[start], arr[mid+1]);
    }
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int size = lists.size();

        if(size == 0) return NULL;

        mergeSort(lists, 0, lists.size()-1);
        return lists[0];
    }
};