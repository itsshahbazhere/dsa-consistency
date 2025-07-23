// https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab



// T.C = O(N)
// S.C = O(N) this is only node creation not mapping space here we need
// this is most optimized solution

class Solution {
  public:
    Node *cloneLinkedList(Node *head) {
        // Write your code here
        
        //creation of list
        Node *prev = head;
        Node *curr = head;
        
        while(prev){
            curr = prev->next;
            prev->next = new Node(prev->data);
            prev = prev->next;
            prev->next = curr;
            prev = curr;
        }
        
        Node *cloneHead = head->next;
        
        prev = head;
         
        while(prev){
            curr = prev->next;
            if(prev->random){
                curr->random = prev->random->next;
            }
            prev = curr->next;

        }
        
        prev = head;
        
        while(prev->next){
            curr = prev->next;
            prev->next = curr->next;
            prev = curr;
        }
        
        
        return cloneHead;
        
        
        
    }
};



// T.C = O(N)
// S.C = O(N)

class Solution {
  public:
    Node *cloneLinkedList(Node *head) {
        
        
        //assiging next pointer
        
        Node *clone = new Node(0);
        Node *tail = clone;
        Node *temp = head;
        
        while(temp){
            tail->next = new Node(temp->data);
            tail = tail->next;
            temp = temp->next;
        }
        
        temp = clone;
        clone = clone->next;
        delete temp;
        
        //mapping both address
        
        unordered_map<Node*,Node*>m;
        temp = head;
        Node *cloneTemp = clone;
        
        while(temp){
            m[temp] = cloneTemp;
            temp = temp->next;
            cloneTemp = cloneTemp->next;
        }
        
        temp = head;
        cloneTemp = clone;
        
        //assigning random pointer
        
        while(temp){
            cloneTemp->random = m[temp->random];
            cloneTemp = cloneTemp->next; 
            temp = temp->next;
        }
        
        return clone;
        
        
        
    }
};


// T.C = O(N^2)
// S.C = O(N)
class Solution {
  public:
  
    Node *randomPtr(Node *head, Node *clone, Node *random){
        
        while(head != random){
            head = head->next;
            clone = clone->next;
        }
        
        return clone;
        
    }
    Node *cloneLinkedList(Node *head) {
        
        
        //assiging next pointer
        
        Node *clone = new Node(0);
        Node *tail = clone;
        Node *temp = head;
        
        while(temp){
            tail->next = new Node(temp->data);
            tail = tail->next;
            temp = temp->next;
        }
        
        temp = clone;
        clone = clone->next;
        delete temp;
        
        //assigning random pointer
        
        temp = head;
        Node *cloneTemp = clone;
        
        while(temp){
            
            cloneTemp->random = randomPtr(head, clone, temp->random);
            cloneTemp = cloneTemp->next; 
            temp = temp->next;
        }
        
        
        return clone;
        
        
        
    }
};