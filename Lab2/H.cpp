#include <iostream>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
int size = 0;
int deleted;

Node* insert(Node* head, Node* node, int p){
    /* write your code here */
    size++;
    if(p == 0){
        node->next = head;
        head = node;
        return head;
    }
    else{
        Node *cur = head;
        int i = 0;
        while(cur->next){
            if(i+1 == p){
                Node *t = cur->next;
                cur->next = node;
                cur->next->next = t;
                return head;
            }
            cur = cur->next;
            i++;
        }
        cur->next = node;

        return head;
    }
}
Node* remove(Node* head, int p){
    size--;
    if(p == 0){
        deleted = head->val;
        head = head->next;
    }
    else{
        Node* cur = head;
        int i = 0;
        while(cur->next and cur->next->next){
            if(i+1 == p){
                deleted = cur->next->val;
                cur->next = cur->next->next;
            }
            cur = cur->next;
            i++;
        }
        if(cur->next != NULL and i+1 == p){
            deleted = cur->next->val;
            cur->next = NULL;
        }
    }
    return head;

}
 
Node* replace(Node* head, int p1, int p2){
    head = remove(head, p1);
    head = insert(head, new Node(deleted), p2);
    return head;

}
 
Node* reverse(Node* head){
    Node *next, *cur = head, *prev=NULL;
    while(cur){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;

}
 
void print(Node* head){
    Node* cur = head;
    while(cur){
        cout << cur->val << ' ';
        cur = cur->next;
    }
    cout << endl;
}
 
Node* cyclic_left(Node* head, int x){
    Node* cur = new Node();
    cur->next = head;
    Node *copy_head = head;

    if(x == size){
        return head;
    }

    while(cur->next){
        cur = cur->next;
    }
    for(int i = 0; i < x; i++){
        cur->next = new Node(copy_head->val);
        copy_head = copy_head->next;
        cur = cur->next;
    }
    for(int i = 0; i < x; i++){
        head = head->next;
    }
    return head;


}
 
Node* cyclic_right(Node* head, int x){
    return cyclic_left(head, size - x);

}
 
int main(){
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}