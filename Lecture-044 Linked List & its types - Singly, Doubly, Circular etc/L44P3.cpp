#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
    
    //construrctor
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    //destructor
    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
            prev = NULL;
        }
        cout<<"memory is free for node with data "<<value<<endl;
    }
};


//length of singly linked list
int lengthLL(Node* head){
    Node* temp = head;
    int cnt = 0;
    while(temp!= NULL){
        cnt++;
        temp = temp->next;
    }

    return cnt;
}


// Insert at any position in singly linked list
void insertAtAnyPosition(Node* &head, Node* &tail, int data, int position){
    Node* temp = new Node(data);
    int cnt = 1;
    Node* curr = head;
    if(position <= 0 || position > lengthLL(head)+1){
        cout<<"Enter a valid position"<<endl;
    }
    else{
        if(position == 1){
            if(head == NULL){
                head = temp;
                tail = temp;
            }
            else{
                temp->next = head;
                head->prev = temp;
                head=temp;
            }
        }
        else{
            while(cnt<position-1){
                curr = curr->next;
                cnt++;
            }
            temp->next = curr->next;
            if(curr->next == NULL){
                tail = temp;
            }
            else{
                curr->next->prev = temp;
            }
            curr->next = temp;
            temp->prev = curr;
        }
    }

}

void deleteAtAnyPosition(Node* &head, Node* &tail, int position){
    if(head == NULL){
        cout<<"there is no node to delete..."<<endl;
    }
    else if(position <=0 || position>lengthLL(head)){
        cout<<"Position is not valid"<<endl;
    }
    else{

        Node* prev = NULL;
        Node* curr = head;

        if(position == 1){
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
            head->prev = NULL;
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
        else{
            curr->next->prev = prev;
            curr->next = NULL;
        }
        
        curr->prev=NULL;
        delete curr;
    }
    

}


//traversal or print singly linked list
void print(Node* &head){
    Node* temp = head;
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


    //create head and tail pointer of Node type
    Node* head = NULL;
    Node* tail = NULL;


    //INSERTION IN LINKED LIST
    insertAtAnyPosition(head,tail,5,1);
    insertAtAnyPosition(head, tail, 0, 2);
    insertAtAnyPosition(head, tail, 50, 1);
    insertAtAnyPosition(head, tail, 31, 4);
    insertAtAnyPosition(head, tail, 85, 1);

    //printing all data
    print(head); 

    //DELETION IN LINKED LIST AT ANY POSITION
    deleteAtAnyPosition(head, tail, 5);


    //printing all data
    print(head);

    //printing data and tail value
    cout<<head->next->prev->data<<" "<<tail->prev->next->data<<" "<<endl;




    return 0;
}