#include <iostream>
#include <algorithm>
using namespace std;

long long ans = 0;
struct MinHeap{
    long long a[200000];
    long long size = 0;

    long long parent(long long index){
        return (index - 1 ) / 2;
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
    void print(){
        for(long long i = 0; i < size; i++){
            cout << a[i] << ' ';
        }
    }

    void heapify(long long index){
        long long l = left(index);
        long long r = right(index);
        if(l >= size and r >= size){
            return;
        }
        //we need to check only left
        if(r >= size){
            if(a[l] < a[index]){
                swap(a[index], a[l]);
            }
            return;
        }

        if(a[l] > a[r]){
            if(a[index] >= a[r]){
                swap(a[index], a[r]);
                heapify(r);
            }
            return;
        }
        else{
            if(a[index] >= a[l]){
                swap(a[index], a[l]);
                heapify(l);
            }
            return;
        }
    } 

    void merge(){
        while(size > 1){
            long long to_change;
            if(size > 2){
                if(a[1] > a[2]){
                    ans += a[0] + a[2];
                    a[2] += a[0];
                    a[0] = 0;
                    to_change = 2;
                }
                else{
                    ans += a[0] + a[1];
                    a[1] += a[0];
                    a[0] = 0;
                    to_change = 1;
                }
            }
            else if(size == 2){
                ans = ans + a[0] + a[1];
                a[0] += a[1];
                to_change = 1;
            }
            swap(a[0], a[size - 1]);
            size--;
            // prlong long();
            // cout << endl;
            //left part
            if(to_change == 1){
                heapify(1);
            }
            else{
                heapify(2);
            }
            heapify(0);
            // prlong long();
            // cout << endl;
        }
    }
};

void swap(long long* x, long long* y){
    long long temp = *x;
    *x = *y;
    *y = temp;
}


int main(){
    long long n;
    cin >> n;
    MinHeap heap;
    for(long long i = 0; i < n; i++){
        long long x;
        cin >> x;
        heap.add(x);
    }
    
    // heap.prlong long();
    // cout << endl;
    heap.merge();

    cout << ans;

}