#include<iostream>
using namespace std;

class SinglyLL{
    public:
        int data;
        SinglyLL* next;
    
    //construrctor
    SinglyLL(int data){
        this->data = data;
        this->next = NULL;
    }

    //destructor
    ~SinglyLL(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory is free for node with data "<<value<<endl;
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

void deleteAtAnyPosition(SinglyLL* &head, SinglyLL* &tail, int position){
    if(head == NULL){
        cout<<"there is no node to delete..."<<endl;
    }
    else if(position <=0 || position>lengthLL(head)){
        cout<<"Position is not valid"<<endl;
    }
    else{

        SinglyLL* prev = NULL;
        SinglyLL* curr = head;

        if(position == 1){
            SinglyLL* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
            return;
        }

        int cnt = 1;
        while(cnt<position){
            cnt++;
            prev =curr;
            curr = curr->next;
        }
        
        prev->next = curr->next;
        if(curr->next == NULL){
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
    

}


//traversal or print singly linked list
void print(SinglyLL* &head){
    SinglyLL* temp = head;
    if(head == NULL){
        cout<<"there is no node to print..."<<endl;
    }
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


    //INSERTION IN LINKED LIST
    insertAtAnyPosition(head, tail, 80, 1);
    insertAtAnyPosition(head, tail, 0, 2);
    insertAtAnyPosition(head, tail, 50, 3);
    insertAtAnyPosition(head, tail, 8531, 4);
    insertAtAnyPosition(head, tail, 85, 1);

    //printing all data
    print(head); 

    //DELETION IN LINKED LIST AT ANY POSITION
    deleteAtAnyPosition(head, tail, 1);


    //printing all data
    print(head);

    //printing data and tail value
    cout<<head->data<<" "<<tail->data<<" "<<endl;




    return 0;
}