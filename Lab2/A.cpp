#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *next;
    
    Node(){}

    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};
class LinkedList{ 
    private: 
        Node * head; 
        Node * cur; 
    public: 
        LinkedList(){ 
            head=NULL; 
            cur=head; 
        }

    void fill(int x){
        if(cur == NULL){
            head = new Node(x);
            cur = head;
        }
        else{
            cur->next = new Node(x);
            cur = cur->next;
        }
    }
    int getClosest(int k){
        int minIndex = 0;
        int i = 0;

        Node *cur = head;
        int minVal = abs(k - cur->val);
        while(cur){
            if(abs(cur->val - k) < minVal){
                minVal = abs(cur->val - k);
                minIndex = i;
            }
            i++;
            cur = cur->next;
        }
        return minIndex;
    }
};

int main(){
    int n;
    cin >> n;
    LinkedList list;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        list.fill(x);
    }
    int k;
    cin >> k;

    cout << list.getClosest(k);

}