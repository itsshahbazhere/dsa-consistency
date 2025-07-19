// https://www.geeksforgeeks.org/problems/detect-loop-in-linked-list/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

//approach 1:   T.C - O(N^2) S.C- (N)
class Solution {
  public:
    bool check(vector<Node*>&visited, Node *curr){
        for(int i=0; i<visited.size(); i++){
            if(visited[i] == curr){
                return true;
            }
        }
        return false;
    }
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        
        Node *curr = head;
        vector<Node*>visited;
        while(curr!=NULL){
            if(check(visited, curr)){
                return 1;
            }
            visited.push_back(curr);
            curr = curr->next;
        }
        return 0;
        
    }
};



//approach 2: using unordered map-   T.C - O(N) S.C- (N)

class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
    
        unordered_map<Node*, bool>visited;
        Node *curr = head;
        while(curr){
            if(visited[curr] == 1){
                return 1;
            }
            visited[curr] = 1;
            curr = curr->next;
        }
        
        return 0;
    }
};


//approach 3: using show and fast pointer-   T.C - O(N) S.C- (1)
