// https://www.geeksforgeeks.org/problems/remove-loop-in-linked-list/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab


//approach-1
// T.C- O(N^2) SC-O(N)
class Solution {
  public:
  
    bool check(vector<Node*>visited, Node *curr){
        for(int i=0; i<visited.size(); i++){
            if(visited[i] == curr){
                return 1;
            }
        }
        return 0;
    }
    
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        
        Node *curr = head;
        vector<Node*>visited;
        
        while(curr!=NULL){
            if(check(visited, curr)){
                break;
            }
            else{
                visited.push_back(curr);
                curr = curr->next;
            }
        }
        
        //if curr is null
        if(curr == NULL){
            return;
        }
        else{
            //if curr isnt null
            Node* prev = curr;
            
            while(prev->next != curr){
                prev = prev->next;
            }
            
            prev->next = NULL;
        }
        
    }
};


//approach-2
// T.C- O(N) SC-O(N)
class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        
        Node *curr = head;
        unordered_map<Node*, bool>visited;
        
        while(curr!=NULL){
            if(visited[curr] == 1){
                break;
            }
            else{
                visited[curr] == 1;
                curr = curr->next;
            }
        }
        
        //if curr is null
        if(curr == NULL){
            return;
        }
        //if curr isnt null
        Node* prev = curr;
            
        while(prev->next != curr){
            prev = prev->next;
        }
            
        prev->next = NULL;
        
    }
};



//approach -3
// TC-O(N), SC-O(1)
class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        
        Node *slow = head, *fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        
        //fast is null 
        if(fast == NULL || fast->next == NULL) return;
        //or
        
        //slow and fast meet at some node
        slow = head;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        while(slow->next!=fast){
            slow = slow->next;
        }
        
        slow->next = NULL;
        
    }
};





//approach-4
// TC-O(N), SC-O(1)
class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        
        Node *slow = head, *fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        
        //fast is null 
        if(fast == NULL || fast->next == NULL) return;
        //or
        
        //slow and fast meet at some node
        int cnt = 1;
        while(slow->next!=fast){
            slow = slow->next;
            cnt++;
        }
        
        fast = head;
        while(cnt--){
            fast = fast->next;
        }
        
        slow = head;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        while(slow->next!=fast){
            slow = slow->next;
        }
        
        
        slow->next = NULL;
        
    }
};