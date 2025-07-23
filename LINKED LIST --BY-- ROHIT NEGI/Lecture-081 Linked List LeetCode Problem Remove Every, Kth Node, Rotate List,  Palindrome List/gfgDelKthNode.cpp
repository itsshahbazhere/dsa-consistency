// https://www.geeksforgeeks.org/problems/remove-every-kth-node/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

class Solution {
  public:
    Node* deleteK(Node* head, int k) {
        
        if(k==1){
            return NULL;
        }
        
        Node *prev = NULL, *curr = head;
        int cnt = 1;
        
        while(curr){
            //if k== cnt delte this node
            if(cnt == k){
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
                cnt = 1;
            }
            else{
                //not equal the skip this node
                prev = curr;
                curr = curr->next;
                cnt++;
            }
        }
        
        return head;
        
    }
};