#include <iostream>
using namespace std;
struct Node{
    int val;
    Node *left;
    Node *right;

    Node(int val){
        this->val = val;
        left = right = NULL;
    }
};

class BST{
private:
    Node *root;
    Node *insert(Node *cur, int val){
        if(!cur){
            return new Node(val);
        }
        if(val > cur->val){
            cur->right =  insert(cur->right, val);
        }
        else{
            cur->left = insert(cur->left, val);
        }
        return cur;
    }
    bool is_available(Node* cur, string s){
        if(!cur->left and !cur->right){
            return s.size() == 0;
        }
        if(s.size() == 0){
            return(cur != NULL);
        }
        if(s[0] == 'L'){
            if(!cur->left){
                return false;
            }
            return is_available(cur->left, s.substr(1, s.size() - 1));
        }
        else if(s[0] == 'R'){
            if(!cur->right){
                return false;
            }
            return is_available(cur->right, s.substr(1, s.size() - 1));
        }
    }
public:
    BST(){
        root = NULL;
    }
    void insert(int val){
        root = insert(root, val);
    }

    bool is_available(string s){
        return is_available(root, s);
    }
};


int main(){
    int n, m;
    cin >> n >> m;
    BST tree;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        tree.insert(x);
    }
    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        if(tree.is_available(s)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}