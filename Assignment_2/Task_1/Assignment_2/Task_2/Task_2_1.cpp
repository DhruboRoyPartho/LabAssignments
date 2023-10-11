#include<bits/stdc++.h>
using namespace std;

typedef struct node Node;
struct node{
    int data;
    struct node *next;
};

Node *head = NULL;
Node *tail = NULL;

void insert(int value)
{
    Node *ptr = head;
    while(ptr != NULL){
        if(ptr->data == value)
            return;
        ptr = ptr->next;
    }
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
    }
    else{
        tail->next = newNode;
    }
    tail = newNode;
    return;
}

void display()
{
    Node* ptr = head;
    while(ptr != NULL){
        cout<<ptr->data<<" -> ";
        ptr = ptr->next;
    }
    cout<<"NULL"<<endl;
    return;
}

int main()
{
    int n;
    cout<<"How many number do you want to enter: ";
    cin>>n;
    cout<<"Enter numbers: ";
    while(n--){
        int x;
        cin>>x;
        insert(x);
    }
    cout<<"You have entered(after remove duplicate):\n";
    display();
    return 0;
}
