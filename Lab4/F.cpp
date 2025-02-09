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

    int inorder_traverse(Node* cur_copy, int count){
        stack <Node*> st;
        Node* cur = cur_copy;
        while(!st.empty() or cur != NULL){
            while(cur){
                st.push(cur);
                cur = cur->left;
            }
            if(!st.empty() and cur==NULL){
                cur = st.top();
                st.pop();
                if(cur->left and cur->right){
                    count++;
                }
                cur = cur->right;
            }
        }
        return count;
        
    }
public:
    BST(){
        root = NULL;
    }
    void insert(int val){
        root = insert(root, val);
    }
    int inorder_traverse(int count){
        return inorder_traverse(root, count);
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
    cout << tree.inorder_traverse(0);
}