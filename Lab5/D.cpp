#include <iostream>
using namespace std;

long long count = 0;
struct MinHeap{
    long long size = 0;
    long long a[1000000];

    long long parent(long long index){
        return (index - 1) / 2;
    }
    long long left(long long index){
        return (2 * index) + 1;
    }
    long long right(long long index){
        return (2 * index) + 2; 
    }

    void add(long long value){
        long long i = size;
        a[i] = value;
        size++;

        long long p = parent(i);
        while(i != 0 && a[i] < a[p]){
            swap(a[i], a[p]);
            i = p;
            p = parent(i);
        }
    }

    void push_down(long long index){
        long long smallest = index;
        long long l = left(index);
        long long r = right(index);

        if(l < size && a[smallest] > a[l]){
            smallest = l;
        }
        if(r < size && a[smallest] > a[r]){
            smallest = r;
        }
        if(smallest != index){
            swap(a[index], a[smallest]);
            push_down(smallest);
        }
    }

    long long mix(long long comp){
        while(size >= 2 and a[0] < comp){
            count++;
            long long to_change;
            if(size > 2){
                if(a[1] > a[2]){
                    to_change = 2;
                }
                else{
                    to_change = 1;
                }
            }
            else if(size == 2){
                to_change = 1;
            }
            a[to_change] = 2 * a[to_change] + a[0];
            swap(a[0], a[size - 1]);
            size--;
            push_down(to_change);
            push_down(0);
        }
        if(a[0] < comp){
            return -1;
        }
        return count;
    }

    void print(){
        for(long long i = 0; i < size; i++){
            cout << a[i] << ' ';
        }
        cout << endl;
    }
};


int main(){
    long long n, m;
    cin >> n >> m;
    MinHeap heap;
    for(long long i = 0; i < n; i++){
        long long x;
        cin >> x;
        heap.add(x);
    }
    cout << heap.mix(m);

}