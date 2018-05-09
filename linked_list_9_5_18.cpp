/*
writing a simple program to perform various operation on linked list

written by : SUMAN KUMAR (suman9868)
date : 09 may 2018
time : 5:30 pm
*/

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class Linked_list{
    private:
        Node *head;
    public:
        Linked_list(){
            head = NULL;
        }
        void add_node_end(int n);
        void add_node_front(int n);
        void add_node_after_old(int old, int n);
        void display();
        void delete_node_front();
        void delete_node_last();
        void delete_node_value(int n);
};

void Linked_list::delete_node_value(int n){
    Node *temp,*pre;
    temp = head;
    while(temp->data != n and temp){
        pre = temp;
        temp = temp -> next;
    }
    pre->next = temp -> next;
}

void Linked_list::delete_node_last(){

    Node *pre,*cur;
    cur = head;
    while(cur -> next){
        pre = cur;
        cur = cur -> next;
    }
    pre -> next = NULL;
    delete cur;
    //temp = NULL;
    //head = temp;
}

void Linked_list::delete_node_front(){
    Node *temp;
    temp = head;
    head = head -> next;
    cout <<"\ndeleted node is : "<<temp -> data;
    delete temp;
}

void Linked_list::add_node_after_old(int old, int n){
    Node *temp = new Node;
    temp -> data = n;
    temp -> next = NULL;

    Node *t = head;
    while(t->data != old){
        t = t -> next;
    }
    if(t){
        temp -> next = t -> next;
        t -> next = temp;
    }
}

void Linked_list::add_node_end(int n){
    Node *temp = new Node;
    temp->data = n;
    temp -> next = NULL;

    if(head == NULL){
        //cout<<"first element is going to add"<<endl;
        head = temp;
    }
    else{
        Node *temp_temp;// = new Node;
        temp_temp = head;
        while(temp_temp->next){
            temp_temp = temp_temp -> next;
        }
        temp_temp -> next = temp;
    }
}

void Linked_list::add_node_front(int n){
    Node *temp = new Node;
    temp -> data = n;
    temp -> next = NULL;

    if(head == NULL){
        head = temp;
    }
    else{
        temp -> next = head;
        head = temp;
    }
}

void Linked_list::display(){
    Node *temp;// = new Node;
    temp = head;
    cout << "\nNow printing all the elements "<<endl;
    //cout << temp -> data<<endl;
    while(temp){
        cout<< temp -> data << endl;
        temp = temp -> next;
    }
}

int main(){

    Linked_list ll;
    ll.add_node_end(10);
    ll.add_node_end(20);
    ll.add_node_front(5);
    ll.add_node_after_old(10,15);
    ll.add_node_after_old(20,25);
    ll.add_node_front(1);
    ll.display();
    ll.delete_node_front();
    ll.display();
    ll.delete_node_last();
    ll.display();
    //ll.delete_node_last();
    //ll.display();
    ll.delete_node_value(15);
    ll.display();

    ll.delete_node_value(11);
    ll.display();
    return 0;
}
