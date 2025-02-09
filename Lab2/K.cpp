#include <bits/stdc++.h>
using namespace std;

struct Node{
    char val;
    bool visit;
    Node *next;

    Node(char _val){
        val = _val;
        visit = false;
        next = NULL;
    }
};

void print(Node *head){
    Node *temp = head;
    while(temp){
        cout << temp->visit << ' ';
        temp = temp->next;
    }
    cout << endl;
}

int size = 0;
void find_duplicate(Node *head, char c){
    Node *temp = head;
    bool to_change = false;
    int cnt = 0;
    char ans;
    for(int i = 0; i < size-1; i++){
        if(temp->visit == false){
            if(temp->val != c){
                if(cnt == 0){
                    ans = temp->val;
                    cnt++;
                }
            }
        }
        if(temp->val == c){
            to_change = true;
            temp->visit = true;
        }
        temp = temp->next;
    }
    if(cnt == 1){
        cout << ans << ' ';
        if(to_change){
            temp->visit = true;
        }
        return;
    }
    if(to_change){
        temp->visit = true;
        cout << -1 << ' ';
    }
    else{
        cout << temp->val << ' ';
    }



}


int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        Node *head;
        Node *cur;
        int n;
        cin >> n;
        char c;
        for(int j = 0; j < n; j++){
            cin >> c;
            size++;
            if(j == 0){
                head = new Node(c);
                cur = head;
            }
            else{
                cur->next = new Node(c);
                cur = cur->next;
            }
            find_duplicate(head, c);
        }
        size = 0;
        cout << endl;
    }
}