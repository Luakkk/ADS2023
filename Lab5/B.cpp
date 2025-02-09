#include <iostream>
#include <algorithm>
using namespace std;

struct MaxHeap{
    int a[100000];
    int size;

    int parent(int index){
        return (index - 1) / 2;
    }
    
    int left(int index){
        return (2 * index) + 1;
    }
    int right(int index){
        return (2 * index) + 2;
    }

    void add(int value){
        int i = size;
        a[i] = value;
        size++;

        int p = parent(i);
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

        if(l < size && a[largest] < a[l]){
            largest = l;
        }

        if(r < size && a[largest] < a[r]){
            largest = r;
        }

        if(largest != index){
            swap(a[index], a[largest]);
            push_down(largest);
        }
    }

    int merge(){
        while(size > 2){
            int to_change;
            if(size == 2){
                if(a[0] == a[1]){
                    return 0;
                }
                return abs(a[0] - a[1]);
            }
            int temp = a[0];
            a[0] = 0;
            swap(a[0], a[size-1]);
            size--;
            if(a[1] >= a[2]){
                a[1] = temp - a[1];
                if(a[1] == 0){
                    swap(a[1], a[size-1]);
                    size--;
                }
                push_down(1);
            }
            else{
                a[2] = temp - a[2];
                if(a[2] == 0){
                    swap(a[2], a[size-1]);
                    size--;
                }
                push_down(2);
            }
            push_down(0);
        }
        if(size == 0){
            return 0;
        }
        if(size == 1){
            return a[0];
        }
        if(size == 2){
            return abs(a[0] - a[1]);
        }

    }

};

int main(){
    int n;
    cin >> n;
    MaxHeap heap;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        heap.add(x);
    }
    cout << heap.merge();

}