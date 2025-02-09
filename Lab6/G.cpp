#include<bits/stdc++.h>

using namespace std;

struct User{
    string name;
    string username;
};

bool cmp(User u1, User u2){
    if(u1.username == u2.username){
        return u1.username < u2.username;
    }
    return u1.name < u2.name;
}

int partition(vector<User> & us, int low, int high){
    User pivot = us[high];
    int i = low - 1;
    for(int j = low; j <= high - 1; j++){
        if(cmp(us[j], pivot)){
            i++;
            swap(us[j], us[i]);
        }   
    }
    swap(us[i+1], us[high]);
    return i + 1;
}

void quickSort(vector <User> &us, int low, int high){
    if(low < high){
        int pivot = partition(us,low, high);
        quickSort(us, low, pivot - 1);
        quickSort(us, pivot + 1, high);
    }
}

int main(){
    int n; 
    cin >> n;
    vector<User> us(n);
    for(auto & user : us){
        cin >> user.name;
        cin >> user.username;

    }
    quickSort(us, 0, n - 1);
    for(auto i : us){
        cout << i.name << " " << i.username<< endl;
    }
}