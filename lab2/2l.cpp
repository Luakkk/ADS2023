# include <iostream>
# include <algorithm>
# include <cassert>
 
using namespace std;
 
struct Node {
  int val;
  Node *next;
 
  Node() {
    val = 0;
    next = NULL;
  }
 
};
 
 
int maxValue = -1000000;
 
int findMaxSum(int n, Node *head) {
    int i = 1; 
    Node *cur = head;
    while(i <= n){
        int tempAns = 0;
        while(cur){
            tempAns += cur->val;
            if(tempAns > maxValue){
                maxValue = tempAns;
            }
            cur = cur->next;
        }
        i++;
        head = head->next;
        cur = head;

    }
    return maxValue;
 
}
 
int main() {
    int n;
    cin >> n;
    
    Node *head, *tail;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        Node *cur = new Node();
        cur -> val = x;
    
        if (i == 1) {
        head = tail = cur;
        } else {
        tail -> next = cur;
        tail = cur;
        }
    }
    Node *newHead = head;
    cout << findMaxSum(n, newHead) << "\n";
    return 0;
}
