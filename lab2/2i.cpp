#include <bits/stdc++.h>
  
using namespace std;

struct Node{
	Node * prev;
	Node * next;
	string val;
	Node(string _val){
		prev = NULL;
		next = NULL;
		val = _val;
	}	
};

Node * head = NULL;
Node * tail = NULL;
int cnt = 0;

void print(Node *head){
	Node *temp = head;
	while(temp){
		cout << temp->val << ' ';
		temp = temp->next;
	}
	cout << endl;
}

void clear(){
	while(head){
		head = head->next;
	}
	tail = NULL;
	head = tail;
	cnt = 0;
}

void add_back(string s){
	cnt++;
	if(head == NULL){
		head = tail = new Node(s);
	}
	else{
		Node *newNode = new Node(s);
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}

}
void add_front(string s){
	cnt++;
	if(head == NULL){
		head = tail = new Node(s);
	}
	else{
		Node *newNode = new Node(s);
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
		return;
	}
	
}
bool empty(){
	return cnt==0;
}

void erase_front(){
	cnt--;
	if(empty()){
		return;
	}
	Node *temp;
	if(!head->next){
		clear();
		return;
	}
	if(head->next){
		temp = head->next->next;
	}
	head = head->next;
	head->prev = NULL;
	head->next = temp;
	
}
void erase_back(){
	if(empty()){
		return;
	}
	if(cnt == 1){
		head = tail = NULL;
		cnt--;
		return;
	}

	Node *temp;
	if(tail->prev){
		temp = tail->prev->prev;
	}
	tail = tail->prev;
	tail->next = NULL;
	tail->prev = temp;
	cnt--;
}

string front(){
	return head->val;
}
string back(){
	return tail->val;
}
  
int main()
{
	string s;
   	while(cin >> s){
		if(s == "print"){
			print(head);
		}
   		if(s == "add_front"){
   			string t;
   			cin >> t;
   			add_front(t);
   			cout << "ok" << endl;
   		}
   		if(s == "add_back"){
   			string t;
   			cin >> t;
   			add_back(t);
   			cout << "ok" << endl;
   		}
   		if(s == "erase_front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else
   			{
   				cout << front() << endl;
   				erase_front();
   			}
   		}
   		if(s == "erase_back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   				erase_back();
   			}
   		}
   		if(s == "front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << front() << endl;
   			}
   		}
   		if(s == "back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   			}
   		}
   		if(s == "clear"){
   			clear();
   			cout << "ok" << endl;
   		}
   		if(s == "exit"){
   			cout << "goodbye" << endl;
   			break;
   		}
   		// cout << "hi" << endl;
   	}
    return 0;
}