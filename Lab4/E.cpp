#include <iostream>
#include <queue>
using namespace std;
int a[1000000];
struct Node{
    int val;
    int level;
    Node* left;
    Node* right;
    
    Node(int val, int level){
        this->val = val;
        this->level = level;
        left = right = NULL;
    }
};

class BST{
private:
    Node* root;
    Node* insert(Node* cur, int val){
        if(!cur){
            return new Node(val, 0);
        }
        return cur;
    }
    void insert(Node* cur, int x, int y, int z, int level){
        if(!cur){
            return;
        }
        if(cur->val == x){
            if(z == 0){
                cur->left = new Node(y, level + 1);
                return;
            }
            else{
                cur->right = new Node(y, level + 1);
                return;
            }
        }
        insert(cur->left, x, y, z, level+1);
        insert(cur->right, x, y, z, level+1);
    }

    void traverse(Node* root){
        if(!root){
            return;
        }
        traverse(root->left);
        a[root->level] += 1;
        traverse(root->right);
    }
public:
    BST(){
        root = NULL;
    }
    void insert(int x, int y, int z, int level){
        insert(root, x, y, z, level);
    }
    void insert(int val){
        root = insert(root, val);
    }
    void traverse(){
        traverse(root);
    }
};

int main(){
    int n;
    cin >> n;
    BST tree;
    for(int i = 0; i < n-1; i++){
        int x, y, z;
        cin >> x >> y >> z;
        a[i] = 0;
        if(i == 0){
            tree.insert(x);
        }
        tree.insert(x,y,z, 0);
    }
    tree.traverse();
    int i = 0;
    int max_width = -1;
    while(a[i] != 0){
        if(max_width < a[i]){
            max_width = a[i];
        }
        i++;
    }
    cout << max_width;
}