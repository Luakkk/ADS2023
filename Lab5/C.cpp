#include <iostream>
using namespace std;

struct MaxHeap{
    int a[100000];
    int size = 0;

    int parent(int index){
        return (index - 1) / 2;
    }

    int left(int index){
        return (2 * index) + 1;
    }
    int right(int index){
        return (2 * index) + 2;
    }

    int get_max(){
        return a[0];
    }

    void add(int value){
        long long i = size;
        a[i] = value;
        size++;

        long long p = parent(i);
        while(i != 0 && a[p] < a[i]){
            swap(a[i], a[p]);
            i = p;
            p = parent(i);
        }
    }
    void print(){
        for(int i = 0; i < size; i++){
            cout << a[i] << ' ';
        }
        cout << endl;
    }

    void push_down(int index){
        int largest = index;
        int l = left(index);
        int r = right(index);

        if(l < size && a[l] > a[largest]){
            largest = l;
        }
        if(r < size && a[r] > a[largest]){
            largest = r;
        }

        if(largest != index){
            swap(a[index], a[largest]);
            push_down(largest);
        }
    }
};

int main(){
    int n, k;
    cin >> n >> k;
    long long ans = 0;
    MaxHeap heap;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        heap.add(x);
    }

    for(int i = 0; i < k; i++){
        ans += heap.get_max();
        heap.a[0] -= 1;
        heap.push_down(0);
        if(heap.a[0] == 0){
            swap(heap.a[0], heap.a[heap.size - 1]);
            heap.size--;
        }
    }
    cout << ans;
}