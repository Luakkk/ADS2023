#include <iostream>
using namespace std;

struct Node {
	string word;
	Node* next;

	Node() {}

	Node(string word) {
		this->word = word;
		this->next = NULL;
	}
};

// your code goes here

Node* cyclicShift(Node* head, int k) {

    Node *cur = new Node("0");
	cur->next = head;
    Node *temp = head;
	Node *copy_head = head;

    int size = 0;
    while(temp != NULL){
        temp = temp->next;
        size++;
    }
	delete(temp);


	while(cur->next){
		cur = cur->next;
	}
	for(int i = 0; i < k; i++){
		Node *x = new Node(copy_head->word);
		cur->next = x;
		copy_head = copy_head->next;
		cur = cur->next;
	}
	for(int i = 0; i < k; i++){
		head = head->next;
	}
	return head;


}

void print(Node* head) {
	Node* cur = head;
	while (cur != NULL) {
		cout << cur->word << " ";
		cur = cur->next;
	}
	cout << endl;
}

int main() {
	int n; cin >> n;
	int k; cin >> k;
	Node* head;
	Node* cur;
	for (int i = 0; i < n; i++) {
		string word; cin >> word;
		if (i == 0) {
			head = new Node(word);
			cur = head;
		} else {
			cur->next = new Node(word);
			cur = cur->next;
		}
	}
	head = cyclicShift(head, k);
	print(head);
}