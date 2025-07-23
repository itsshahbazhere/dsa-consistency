// https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1


//approach 1-  O(n) space complexity


class Solution {
  public:
    Node* segregate(Node* head) {
        
        vector<int>arr;
        Node *temp = head;
        while(temp){
            arr.push_back(temp->data);
            temp = temp->next;
        }
        
        int start = 0;
        int mid = 0;
        int end = arr.size()-1;
        
        while(mid<=end){
            if(arr[mid] == 0){
                int temp = arr[mid];
                arr[mid] = arr[start];
                arr[start] = temp;
                start++;
                mid++;
            } else if(arr[mid] == 1){
                mid++;
            } else{
                int temp = arr[mid];
                arr[mid] = arr[end];
                arr[end] = temp;
                end--;
            }
        }
        
        temp = head;
      
        for(int i=0; i<arr.size(); i++){
            temp->data = arr[i];
            temp = temp->next;
        }
        
        return head;
        
    }
};


//approach - 2 //with const space O(1)

class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node *temp = head;
        int count0 = 0, count1 = 0, count2 = 0;
        
        while(temp){
            if(temp->data == 0){
                count0++;
            }else if(temp->data == 1){
                count1++;
            } else{
                count2++;
            }
            temp = temp->next;
        }
        
        temp = head;
        
        while(count0--){
            temp->data = 0;
            temp = temp->next;
        }
        while(count1--){
            temp->data = 1;
            temp = temp->next;
        }
        while(count2--){
            temp->data = 2;
            temp = temp->next;
        }
        
        // while(temp){
        //     if(count0 > 0){  //we cant do that like if(count0--) bcz -1 is also true
        //         temp->data = 0;
        //         count0--;
        //     }
        //     else if(count1 > 0){
        //         temp->data = 1;
        //         count1--;
        //     } else{
        //         temp->data = 2;
        //         count2--;
        //     }
        //     temp = temp->next;
        // }
        
        return head;
    }
};



//approach -3: node sort direct

class Solution {
  public:
    Node* segregate(Node* head) {
        
        Node *head1 = new Node(3);
        Node *head2 = new Node(3);
        Node *head3 = new Node(3);
        Node *curr1 = head1, *curr2  = head2, *curr3 = head3;
        Node *temp = head;
        
        while(temp){
            if(temp->data == 0){
                curr1->next = temp;
                curr1 = temp;
                temp = temp->next;
                curr1->next = NULL;
            }
            else if(temp->data == 1){
                curr2->next = temp;
                curr2 = temp;
                temp = temp->next;
                curr2->next = NULL;
            }
            else{
                curr3->next = temp;
                curr3 = temp;
                temp = temp->next;
                curr3->next = NULL;
            }
        }
        
        
        curr1->next = head2;
        curr2->next = head3;
        
        Node *curr = head1, *prev = NULL, *fut = NULL;
        
        while(curr){
            if(curr->data == 3){
                if(curr == head1){
                    head1 = head1->next;
                    delete curr;
                    curr = head1;
                }
                else{
                    fut = curr->next;
                    prev->next = curr->next;
                    delete curr;
                    curr = fut;
                }
            }
            else{
                prev = curr;
                curr = curr->next;
            }
            
            
        }
        
        
        return head1;
       
        
    }
};