// https://leetcode.com/problems/linked-list-cycle-ii/description/

// TC-O(N), SC-O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) break;
        }

        if(fast == NULL || fast->next == NULL){
            return NULL;
        }

        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;

    }
};


//approach-2
// TC-O(N), SC-O(N)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *curr = head;
        unordered_map<ListNode*, bool>visited;
        while(curr!=NULL){
            if(visited[curr] == 1){
                break;
            }
            visited[curr] = 1;
            curr = curr->next;
        }

        //there is two posibility of break loop
        //1st
        if(curr == NULL){
            return NULL;
        }

        //2nd
        return curr;
    }
};