#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(){}

    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

Node *filter(Node* head){
    Node *cur = head;
    while(cur->next and cur->next->next){
        cur->next = cur->next->next;
        cur = cur->next;
    }
    if(cur->next != NULL){
        cur->next = NULL;
    }
    return head;
}

void print(Node* head) {
	Node* cur = head;
	while (cur != NULL) {
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;
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
    }

    head = filter(head);
    print(head);
}
