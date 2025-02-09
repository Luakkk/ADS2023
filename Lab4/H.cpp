#include <iostream>
#include <stack>
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
    void traverse(Node* cur_copy, int summ){
        stack <Node*> st;
        Node* cur = cur_copy;
        while(!st.empty() or cur != NULL){
            while(cur){
                st.push(cur);
                cur = cur->right;
            }
            if(!st.empty() and cur == NULL){
                summ += st.top()->val;
                cout << summ << ' ';
                cur = st.top()->left;
                st.pop();
            }
        }
    }
public:
    BST(){
        root = NULL;
    }
    void insert(int val){
        root = insert(root, val);
    }
    void traverse(int summ){
        traverse(root, 0);
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
    tree.traverse(0);
}