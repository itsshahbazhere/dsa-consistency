// https://www.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        
        Node *first = new Node(0);
        first->next = head;
        head = first;
        
        while(first->next){
            int cnt = k;
            Node *second = first->next;
            Node *prev = first;
            Node *curr = second;
            
            while(cnt && curr){
                Node *fut = curr->next;
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