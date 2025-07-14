#include<iostream>
using namespace std;

class SinglyLL{
    public:
        int data;
        SinglyLL* next;
    
    SinglyLL(int data){
        this->data = data;
        this->next = NULL;
    }
};


//length of singly linked list
int lengthLL(SinglyLL* head){
    SinglyLL* temp = head;
    int cnt = 0;
    while(temp!= NULL){
        cnt++;
        temp = temp->next;
    }

    return cnt;
}


//insert at head position in singly linked list
void insertAtHead(SinglyLL* &head, SinglyLL* &tail, int data){
    SinglyLL* temp = new SinglyLL(data);

    if(head == NULL){
        head = temp;
        tail = temp;
    }
    else{
        temp->next = head;
        head=temp;
    }
}

//insert at tail position in singly linked list
void insertAtTail(SinglyLL* &head, SinglyLL* &tail, int data){

    SinglyLL* temp = new SinglyLL(data);
    if(tail == NULL){
        tail = temp;
        head = temp;
    }
    else{
        SinglyLL* curr = tail;
        while(curr->next!=NULL){
            curr = curr->next;
        }

        temp->next = curr->next;
        curr->next = temp;
        tail = temp;
    }

}


// Insert at any position in singly linked list
void insertAtAnyPosition(SinglyLL* &head, SinglyLL* &tail, int data, int position){
    SinglyLL* temp = new SinglyLL(data);
    int cnt = 1;
    SinglyLL* curr = head;
    if(position <= 0 || position > lengthLL(head)+1){
        cout<<"Enter a valid position"<<endl;
    }
    else{
        if(position == 1){
            insertAtHead(head, tail, data);
        }
        else{
            while(cnt<position-1){ //1<6(4-1)
            curr = curr->next;
            cnt++;
            }
            temp->next = curr->next;
            curr->next = temp;

            if(temp->next == NULL){
                tail = temp;
            }
        }
    }

}

//traversal or print singly linked list
void print(SinglyLL* &head){
    SinglyLL* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;

}

//main function
int main(){


    //create head and tail pointer of SinglyLL type
    SinglyLL* head = NULL;
    SinglyLL* tail = NULL;

    //calling every functions
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    insertAtTail(head, tail, 50);
    insertAtTail(head, tail, 60);
    insertAtTail(head, tail, 70);

    insertAtAnyPosition(head, tail, 80, 1);
    
    //printing data and tail value
    cout<<head->data<<" "<<tail->data<<" "<<endl;
    cout<<lengthLL(head)<<endl;


    //printing all data
    print(head);




    return 0;
}