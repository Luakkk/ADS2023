#include <bits/stdc++.h>
using namespace std;

int main(){
	string s1, s2;
	cin >> s1 >> s2;
	stack <char> st1;
	stack <char> st2;
	
	for(int i = 0; i < s1.size(); i++){
		if(s1[i] == '#'){
			if(st1.size() != 0){
				st1.pop();
			}
		}
		else{
			st1.push(s1[i]);
		}
	}	
	
	for(int i = 0; i < s2.size(); i++){
		if(s2[i] == '#'){
			if(st2.size() != 0){
				st2.pop();
			}
		}
		else{
			st2.push(s2[i]);
		}
	}
	if(st1.size() != st2.size()){
		cout << "No";
	}
	else{
		while(!st1.empty() and !st2.empty()){
			if(st1.top() == st2.top()){
				st1.pop();
				st2.pop();			
			}
			else{
				cout << "No";
				return 0;
			}
		}
		cout << "Yes";
	}		
}