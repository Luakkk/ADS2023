#include <bits/stdc++.h>
using namespace std;
struct node{
    string val;
    node *next;
node(){};
node(string val){
    this -> val = val;
    this -> next = NULL;
}

}
;
struct LinkedList{
    node *head;
    node *tail;

LinkedList(){
    this -> head = NULL;
    this -> tail = NULL;
}
void push_db(string s){
    node *tmp = new node(s);
    if(this -> head == NULL){
        this -> head = tmp;
        this -> tail = tmp;

    }
    else{
        tmp->next = this-> head ; 
        this -> head = tmp;
    }

}
;
void chistka(){
    node * cur = this -> head;
    
    while(cur != NULL and cur -> next !=NULL){
    
            if(cur-> val == cur->next-> val){
                node *del = cur -> next;
                cur ->next = cur -> next ->next;
                delete del;
            }

        
            else cur = cur -> next;
            
        }
        
    
                
    }


;
int  get_size(){
    int size= 0;
    node *v = this -> head;

    while( v !=NULL){
        size++;
        v = v->next;
    }
    return size  ;
    
}

void print(){
    cout << "All in all: ";
    cout << get_size()<< endl;
    cout <<"Students: "<< endl;
    node *v = this ->head;
    
    while(v != NULL){
            
            cout << v->val <<endl;
            
            v = v-> next;
        }
    

}
}
;
int main(){
    LinkedList *ll = new LinkedList();
    int n ;
    cin >> n;
    string s;
    int cnt = 1;
    while(cin>> s ){
        if(cnt == n){
            ll->push_db(s);
            break;
        }
        ll-> push_db(s);
        cnt++;
        
    }
    ll-> chistka();
    
    ll->print();

    }
