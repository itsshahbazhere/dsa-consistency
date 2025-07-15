
#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    
    //construrctor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    //destructor
    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory is free for node with data "<<value<<endl;
    }
};


//length of circular singly linked list
int lengthLL(Node* tail){
    Node* temp = tail;
    int cnt = 0;
    do{
        cnt++;
        temp = temp->next;
    } while(temp!=tail);

    return cnt;
}


// Insert at any position in singly linked list
void insertAtAnyPosition(Node* &tail, int d, int element){
    
    Node* temp = new Node(d);
    //empty list
    if(tail == NULL){
        tail = temp;
        temp->next = temp;

    }
    else{
        //non empty list
        Node* curr = tail;
        int len = lengthLL(tail);
        int cnt = 1;

        while(curr->data != element){ //10 20 30 40 50
            curr = curr->next;
            cnt++;
            if(cnt>len){
                cout<<"No element found to insert new element "<<endl;
            }
        }
        temp->next = curr->next;
        curr->next = temp;

    }

}

void deleteAtAnyNode(Node* &tail, int data){

    if(tail == NULL){
        cout<<"there is no node to delete..."<<endl;
    }
    else{


        Node* prev = tail;
        Node* curr = tail->next;

        if(data == tail->data && prev == curr){
            tail->next = NULL;
            delete tail;
            return;
        }

        int cnt = 1;
        int len = lengthLL(tail);
        while(curr->data!=data){
            prev = curr;
            curr = curr->next; //10 20 30 40 50
            cnt++;
            if(cnt>len){ 
                cout<<"node not found"<<endl;
                return;
            }
            
        }
    
        if(curr == tail){
            tail = tail->next;
        }



        prev->next = curr->next;
        curr->next = NULL;
        delete curr;

        
    }
    

}


//traversal or print singly linked list
void print(Node* &tail){

    Node* temp = tail;

    if(tail == NULL){
        cout<<"there is no node to print..."<<endl;
    }
    else{
        do{
            cout<<temp->data<<" ";
            temp = temp->next;
        } while(temp != tail);
    }

    cout<<endl;

}

//main function
int main(){


    //create head and tail pointer of Node type
    Node* tail = NULL;


    //INSERTION IN LINKED LIST
    insertAtAnyPosition(tail,5,1);
    insertAtAnyPosition(tail,6,5);
    insertAtAnyPosition(tail,7,6);
    insertAtAnyPosition(tail,8,7);
    insertAtAnyPosition(tail,9,6);

    //printing all data
    print(tail);

    //DELETION IN LINKED LIST AT ANY POSITION
    deleteAtAnyNode(tail, 5);
    deleteAtAnyNode(tail, 8);
    deleteAtAnyNode(tail, 9);


    //printing all data
    print(tail);

    //cheking list are circular or not
    // cout<<tail->data<<" "<<tail->next->data<<" "<<tail->next->next->data<<" "<<tail->next->next->next->data<<" "<<tail->next->next->next->next->data<<" "<<tail->next->next->next->next->next->data<<endl;





    return 0;
}