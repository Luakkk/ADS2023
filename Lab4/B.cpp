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
    Node *root;
    Node* insert(Node* cur, int val){
        if(!cur){
            return new Node(val);
        }
        if(val > cur->val){
            cur->right = insert(cur->right, val);
        }
        else{
            cur->left = insert(cur->left, val);
        }
        return cur;
    }

    int size(Node *cur){
        if(!cur){
            return 0;
        }
        return(size(cur->left) + 1 + size(cur->right));
    }
    Node* find(Node* cur, int val){
        if(cur->val < val){
            return find(cur->right, val);
        }
        else if(cur->val > val){
            return find(cur->left, val);
        }
        return cur;
    }
public:
    BST(){
        root = NULL;
    }
    void insert(int val){
        root = insert(root, val);
    }
    int size(int val){
        return size(find(root, val));
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
    int k;
    cin >> k;
    cout << tree.size(k);
}