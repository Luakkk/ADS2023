#include <iostream>
#include <algorithm>
using namespace std;
int binarySearch(int startindex, int endindex, int n, int p, int a[])
{
    int l= 0, r = n-1;
    while(l <= r){
        int mid = l + (r-l) / 2;
        if(a[mid] == p){
            startindex = mid;
            r= mid - 1;
        }
        else if(a[mid] > p)
            r= mid - 1;
        else
            l = mid + 1;
    }
    l=0,r=n-1;

    while(l<=r){
        int mid = l + (r-l) / 2;
        if(a[mid] == p){
            endindex = mid;
            l = mid + 1;
        }
        else if(a[mid] > p)
            r = mid - 1;
        else
            l= mid + 1;
    }
    if(endindex == -1 )
        endindex = r;
    return endindex;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    int P;
    cin >> P;
    for(int i = 0; i < P; i++){
        int p;cin>>p;
        int startindex = -1,  endindex = -1;
        endindex = binarySearch(startindex, endindex, n, p, a);
        int ans = 0;
        for(int i = 0; i < endindex+1; i++)
        {ans += a[i];}
        cout << endindex + 1 << ' ' << ans << "\n" ;
    }
}