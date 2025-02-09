#include <iostream>
using namespace std;

int size = 0;

struct Node
{
    int val;
    Node *next;

    Node() {}

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert(Node* head, int val, int index){
    Node *temp = head;
    for(int i = 0; i < index - 1; i++){
        temp = temp->next;
    }
    Node *nextNode = temp->next;
    temp->next = new Node(val);
    temp->next->next = nextNode;
}

void insertAtBeginning(Node **head, int val){
    Node *newNode = new Node(val);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node **head, int val){
    Node *temp = *head;
    Node *newNode = new Node(val);
    while(temp->next){
        temp = temp->next;
    }
    temp->next = newNode;
}


void print(Node *head){
    Node *cur = head;
    while(cur){
        cout << cur->val << ' ';
        cur = cur->next;
    }
}

int main(){
    int n;
    cin >> n;
    Node *head;
    Node *cur;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(i == 0){
            head = new Node(x);
            cur = head;
        }
        else{
            cur->next = new Node(x);
            cur = cur->next;
        }
        size++;
    }

    int val, index;
    cin >> val;
    cin >> index;
    if(index == 0){
        insertAtBeginning(&head, val);
    }
    else if(index == n){
        insertAtEnd(&head, val);
    }
    else{
        insert(head, val, index);
    }
    print(head);
}