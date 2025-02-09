#include <iostream>
using namespace std;
struct Node{
    int val;
    int count;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->count = 1;
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
        else if(cur->val > val){
            cur->left = insert(cur->left, val);
        }
        else if(cur->val == val){
            cur->count++;
        }
        return cur;
    }
    void cnt(Node* cur, int val){
        if(!cur){
            cout << 0 << endl;
            return;
        }
        if(cur->val < val){
            cnt(cur->right,val);
        }
        else if(cur->val > val){
            cnt(cur->left, val);
        }
        else{
            cout << cur->count << endl;
        }
        return;
    }

    void remove(Node* cur, int val){
        if(!cur){
            return; 
        }
        if(cur->val < val){
            remove(cur->right, val);
        }
        else if(cur->val > val){
            remove(cur->left, val);
        }
        else{
            if(cur->count > 0){
                cur->count--;
            }
        }
        return;
    }

    void traverse(Node* cur){
        if(!cur){
            return;
        }
        traverse(cur->left);
        cout << cur->val << ' ';
        traverse(cur->right);
    }

public:
    BST(){
        root = NULL;
    }
    void insert(int val){
        root = insert(root, val);
    }
    void cnt(int val){
        cnt(root, val);
    }
    void remove(int val){
        remove(root, val);
    }
    void traverse(){
        traverse(root);
    }
};

int main(){
    int n;
    cin >> n;
    BST tree;
    for(int i = 0; i < n; i++){
        string s;
        int x;
        cin >> s >> x;
        if(s == "insert"){
            tree.insert(x);
        }
        else if(s == "cnt"){
            tree.cnt(x);
        }
        else if(s == "delete"){
            tree.remove(x);
        }
    }
}