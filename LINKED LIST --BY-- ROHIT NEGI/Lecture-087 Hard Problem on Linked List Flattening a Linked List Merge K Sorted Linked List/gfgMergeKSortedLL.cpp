// https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

// T.C- O(N^2M)
// S.C- O(1)

class Solution {
  public:
  
    Node* merge(Node *&head1, Node* &head2){
        
        Node *head = new Node(0);
        Node *tail = head;
        
        while(head1 && head2){
            if(head1->data <= head2->data){
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
    
    void mergeSort(vector<Node*>& arr, int start, int end){
        
        if(start >= end) return;
        
        int mid = start + (end-start)/2;
        
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        
        arr[start] = merge(arr[start], arr[mid+1]);
    }
    
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        
        
        mergeSort(arr, 0, arr.size()-1);
        
        return arr[0];
        
        // return head;
    }
};


// WE CAN OPTIMISED BY MERGE SORT
// T.C- O(NKlogK)
// S.C- O(1)


class Solution {
  public:
  
    Node* merge(Node *&head1, Node* &head2){
        
        Node *head = new Node(0);
        Node *tail = head;
        
        while(head1 && head2){
            if(head1->data <= head2->data){
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
    
    void mergeSort(vector<Node*>& arr, int start, int end){
        
        if(start >= end) return;
        
        int mid = start + (end-start)/2;
        
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        
        arr[start] = merge(arr[start], arr[mid+1]);
    }
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        
        
        mergeSort(arr, 0, arr.size()-1);
        
        return arr[0];
        
        // return head;
    }