#include <iostream>
using namespace std;

int a[100000];
int size = 0;

int top(){
    if(size == 0){
        return -1;
    } 
    return a[size-1];
}

void push(int val){
    a[size] = val;
    size++;
}

void pop(){ 
    if(size == 0){
        return;
    }
    size--;
    return;
}

int main(){
    int n;
    cin >> n;
    int ans[n];
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        while(size > 0){
            if(top() > x){
                pop();
            }
            else{
                ans[i] = top();
                break;
            }
        }
        if(size == 0){
            ans[i] = -1;
        }
        push(x);
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << ' ';
    }

}