#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

vector<long long> v;
struct Node{
    long long val;
    Node* left;
    Node* right;

    Node(long long val){
        this->val = val;
        left = right = NULL;
    }
};

class BST{
private:
    Node* root;
    Node* insert(Node* cur, long long val){
        if(!cur){
            return new Node(val);
        }
        else if(cur->val < val){
            cur->right = insert(cur->right, val);
        }
        else{
            cur->left = insert(cur->left, val);
        }
        return cur;
    }
    void traverse(Node* cur){
        if(!cur){
            return;
        }
        traverse(cur->left);
        v.push_back(cur->val);
        traverse(cur->right);
    }

public:
    BST(){
        root = NULL;
    }
    void insert(long long val){
        root = insert(root, val);
    }
    void traverse(){
        traverse(root);
    }
};


void fill_balanced(int left, int right){
    if(left <= right){
        int mid = left + (right - left) / 2;
        cout << v[mid] << ' ';
        fill_balanced(left, mid-1);
        fill_balanced(mid+1, right);
    }
    return;
}

int main(){
    long long n;
    cin >> n;
    BST tree;
    for(int i = 0; i < pow(2, n) - 1; i++){
        long long x;
        cin >> x;
        tree.insert(x);
    }
    tree.traverse();
    fill_balanced(0, v.size() - 1);

}