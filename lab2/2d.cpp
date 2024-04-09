#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
    int val;
    int count;
    Node *next;

    Node(int _val){
        val = _val;
        count = 1;
        next = NULL;
    }
};

void set_count(Node *head, int val){
    Node *temp = head;
    int ans = 0;
    while(temp->next){
        if(temp->val == val){
            ans++;
        }
        temp = temp->next;
    }
    temp->count += ans;
}

int maxn = -1;
vector <int> v;
void find_max(Node *head){
    Node *temp = head;
    while(temp){
        if(temp->count > maxn){
            maxn = temp->count; 
        }
        temp  = temp->next;
    }
}

void fill_vector(Node *head){
    Node *temp = head;
    while(temp){
        if(temp->count == maxn){
            v.push_back(temp->val);
        }
        temp = temp->next;
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
        set_count(head, x);
    }

    find_max(head);
    fill_vector(head);
    sort(v.begin(), v.end());
    for(int i = v.size() - 1; i >= 0; i--){
        cout << v[i] << ' ';
    }

}
