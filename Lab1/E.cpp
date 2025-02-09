#include <bits/stdc++.h>
using namespace std;

int main(){
	deque <int> d1, d2;
	for(int i = 0; i < 5; i++){
		int x;
		cin >> x;
		d1.push_back(x); 
	}
	for(int i = 0; i < 5; i++){
		int x;
		cin >> x;
		d2.push_back(x);
	}
	
	int cnt = 0;
	while(!d1.empty() and !d2.empty()){
		cnt += 1;
		if(cnt > pow(10, 6)){
			cout << "blin nichya";
			return 0;
		}
		
		if(d1.front() == 0 and d2.front() == 9){
			d1.push_back(d1.front());
			d1.push_back(d2.front());
			d1.pop_front();
			d2.pop_front();
		}
		else if(d1.front() == 9 and d2.front() == 0){
			d2.push_back(d1.front());
			d2.push_back(d2.front());
			d1.pop_front();
			d2.pop_front();
		}
		else if(d1.front() > d2.front()){
			d1.push_back(d1.front());
			d1.push_back(d2.front());
			d1.pop_front();
			d2.pop_front();
		}
        else if(d1.front() < d2.front()){
            d2.push_back(d1.front());
            d2.push_back(d2.front());
            d1.pop_front();
            d2.pop_front();
            
        }
	}
	if(d1.empty()){
		cout << "Nursik" << ' ' << cnt;
	}
	else{
		cout << "Boris" << ' ' << cnt;
	}
}