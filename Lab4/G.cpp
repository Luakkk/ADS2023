#include <iostream>
#include <stack>
#include <cmath>
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
        else if(cur->val > val){
            cur->left = insert(cur->left, val);
        }
        return cur;
    }

    int max_depth(Node* cur){
        if(!cur){
            return 0; 
        }
        int left_depth = max_depth(cur->left);
        int right_depth = max_depth(cur->right);

        return max(left_depth, right_depth) + 1;
    }
    int max_distance(Node* copy_cur, int maxn){
        Node* cur = copy_cur;
        stack <Node*> st;
        while(!st.empty() or cur != NULL){
            while(cur){
                st.push(cur);
                cur = cur->left;
            }
            if(!st.empty() and cur == NULL){
                int x = max_depth(st.top()->left) + max_depth(st.top()->right) + 1;
                if(maxn < x){
                    maxn = x;
                }
                cur = st.top()->right;
                st.pop();
            }
        }
        return maxn;
    }
public:
    BST(){
        root = NULL;
    }
    void insert(int val){
        root = insert(root, val);
    }
    int max_distance(int maxn){
        return max_distance(root, maxn);
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
    cout << tree.max_distance(-1);
}