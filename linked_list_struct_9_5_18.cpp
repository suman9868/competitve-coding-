/*
this is a simple linked list program without using class

submitted by : SUMAN KUMAR(suman9868)
date: 9 may 2018
time : 9 pm

*/
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

void push(Node **t, int n){
    Node *temp = new Node;
    temp -> data = n;
    temp -> next = NULL;

    if((*t) == NULL){
        (*t) = temp;
    }
    else{
        while((*t) -> next != NULL){
            (*t) = (*t) -> next;
        }
        (*t) -> next = temp;
    }
}

void display(Node *temp){
    while(temp){
        cout<<temp -> data<<endl;
        temp = temp -> next;
    }
}

int main(){

    Node *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    display(head);

    return 0;
}
