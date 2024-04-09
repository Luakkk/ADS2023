#include <iostream>
#include <cmath>
using namespace std;
int main(){
int cnt = 0;
int n ;   cin >> n;
    for(int i = 2; i <= sqrt(n); i++ ){
        if(n % i == 0) cnt ++;
    }
    if(cnt == 0 and n != 1){
    cout << "YES";
    }
    else{ cout<<"NO";
    }
return 0;
}