// https://www.geeksforgeeks.org/problems/multiply-two-linked-lists/1

//somthing wrong not giving correct output


class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        
        long long num1 = 0, num2 = 0;
        
        Node *curr1 = first, *curr2 = second;
        
        while(curr1){
            num1 = curr1->data + num1*10;
            curr1 = curr1->next;
        }
        
        while(curr2){
            num2 = curr2->data + num2*10;
            curr2 = curr2->next;
        }
        
        return num1*num2;
    }
};