//Author: Dhrubo Roy Partho
//Inspired by: Saifullah Mansur
//Date: 03/10/2023
//Program Outcome: You can learn to build a dynamic singly linked "Linked List"

#include<bits/stdc++.h>
using namespace std;

//You can custom struct node as typedef struct node Node
//Then you can use struct node by Node
struct node{
    int data;
    struct node *next;      //Self referential structure
};

struct node *head = NULL;
struct node *tail = NULL;

//This function add new values at the end of the data structure
void insert(int value)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
    }
    tail = newNode;
    return;
}

void show_data()
{
    struct node *ptr = head;
    while(ptr != NULL){
        cout<<ptr->data<<" -> ";   //Optional '->'. You can use space
        ptr = ptr->next;
    }
    cout<<"NULL"<<endl;     //Optional NULL
    return;
}

//Not strictly need to free memory. OS does this works automatically itself. But it is a good practice.
void free_memory()
{
    struct node *ptr = head->next;
    while(ptr != NULL){
        free(head);
        head = ptr;
        ptr = ptr->next;
    }
    return;
}

int main()
{
    int t;
    cout<<"How many data do you want to enter: ";
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        insert(x);    //Add data at the end
    }
    show_data();    //Show the data of link list
    free_memory();    //Free allocated memory
    return 0;
}
