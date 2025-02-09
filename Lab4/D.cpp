#include <iostream>
using namespace std;
struct Node{
    int val;
    int level;
    Node *left;
    Node *right;
    Node(int val, int level){
        this->val = val;
        this->level = level;
        left = right = NULL;
    }
};

class BST{
private:
    Node* root;
    Node* insert(Node* cur, int val, int level){
        if(!cur){
            return new Node(val, level);
        }
        if(cur->val < val){
            cur->right = insert(cur->right, val, level+1);
        }
        else{
            cur->left = insert(cur->left, val, level+1);
        }
        return cur;
    }
    void count(Node* cur, int a[]){
        if(!cur){
            return;
        }
        a[cur->level] += cur->val;
        count(cur->left, a);
        count(cur->right, a);
    }
public:
    BST(){
        root = NULL;
    }
    void insert(int val, int level){
        root = insert(root, val, level);
    }
    void count(int a[]){
        count(root, a);
    }
};

int main(){
    int n;
    cin >> n;
    BST tree;
    int a[5000];
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        tree.insert(x, 0);
    }
    tree.count(a);
    int i = 0;
    while(a[i] != 0){
        i++;
    }
    cout << i << endl;
    int j = 0;
    while(a[j] != 0){
        cout << a[j] << ' ';
        j++; 
    }
}