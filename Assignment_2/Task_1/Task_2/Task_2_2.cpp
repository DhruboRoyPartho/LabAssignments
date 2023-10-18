#include <bits/stdc++.h>
using namespace std;

int t_num = 0;
typedef struct node Node;

struct node
{
    int data;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void insertAtEnd(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        tail->next = newNode;
    }
    tail = newNode;
    // cout << "Value " << value << " addded at the end." << endl;
    return;
}

void displayData()
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        t_num++;
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
    // cout<<t_num<<endl;
    return;
}

void swapCons(int n)
{
    Node *cur = head, *tem, *pre;
    tem = cur->next;
    head->next = head->next->next;
    tem->next = head;
    head = tem;

    if (head->next->next == NULL)
    {
        return;
    }

    pre = head->next;
    cur = head->next->next;
    tem = cur->next;
    
    if(t_num %2 != 0 || t_num == 2){
        while (tem != NULL)
        {
            pre->next = tem;
            cur->next = tem->next;
            tem->next = cur;

            pre = pre->next->next;
            cur = pre->next;
            tem = cur->next;
        }
    }
    else{
        while (tem->next != NULL)
        {
            pre->next = tem;
            cur->next = tem->next;
            tem->next = cur;

            pre = pre->next->next;
            cur = pre->next;
            tem = cur->next;
        }
        pre = head;
        while(pre->next->next->next != NULL){
            pre = pre->next;
        }
        cur = pre->next;
        tem = cur->next;
        pre->next = tem;
        cur->next = tem->next;
        tem->next = cur;
    }
}

int main()
{
    cout << "How many number do you want to enter: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insertAtEnd(x);
    }
    displayData();
    swapCons(n);
    displayData();
    return 0;
}