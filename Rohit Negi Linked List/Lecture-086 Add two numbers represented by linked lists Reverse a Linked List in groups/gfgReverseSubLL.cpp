// https://www.geeksforgeeks.org/problems/reverse-a-sublist-of-a-linked-list/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

class Solution {
  public:
    Node* reverseBetween(int a, int b, Node* head) {
        // code here
        int cnt = 1;
        
        Node *first = NULL;
        Node *second = head;
        
        while(cnt<a){
            first = second;
            second = second->next;
            cnt++;
        }
        
        Node *prev = first;
        Node *curr = second;
        while(cnt<=b){
            Node *fut = curr->next;
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