#include <iostream>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        left = right = NULL;
    }
};

class BST{
private:
    Node* root;
    Node* insert(Node* cur, int val){
        if(!cur){
            return new Node(val);
        }
        if(cur->val < val){
            cur->right = insert(cur->right, val);
        }
        else{
            cur->left = insert(cur->left, val);
        }
        return cur;
    }
    
    Node* find(Node* cur, int val){
        if(cur->val == val){
            return cur;
        }
        else if(cur->val < val){
            return find(cur->right, val);
        }
        return find(cur->left, val);
    }

    void preorder(Node *cur){
        if(!cur){
            return;
        }
        cout << cur->val << ' ';
        preorder(cur->left);
        preorder(cur->right);
    }

public:
    BST(){
        root = NULL;
    }
    void insert(int val){
        root = insert(root, val);
    }
    
    Node* find(int val){
        return find(root, val);
    }

    void preorder(int val){
        return preorder(find(val));
    }
};

int main(){
    int n;
    cin >> n;
    BST tree;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        tree.insert(x);
    }
    int x;
    cin >> x;
    tree.preorder(x);
}