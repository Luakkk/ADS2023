#include <bits/stdc++.h>

using namespace std;

struct Date{
    int day; 
    int month;
    int year;
};

void swap(vector<Date>& vec, int a, int b)
{
    Date temp = vec[a];
    vec[a] = vec[b];
    vec[b] = temp;
}
void func(vector<Date>& vec, int a, int b)
{
    if (vec[a].year > vec[b].year)
    {
        swap(vec, a, b);
    }
    else if (vec[a].year == vec[b].year && vec[a].month > vec[b].month)
    {
        swap(vec, a, b);
    }
    else if (vec[a].year == vec[b].year && vec[a].month == vec[b].month && vec[a].day > vec[b].day)
    {
        swap(vec, a, b);
    }
}

int partition(vector<Date>& vec, int left, int right, int index)
{
    int pivot;
    int value;

    if (index == 2)          
        pivot = vec[right].year;
    if (index == 1)
        pivot = vec[right].month;
    if (index == 0)
        pivot = vec[right].day;

    int i = left - 1;

    for (int j = left; j <= right - 1; j++)
    {
        if (index == 2)
            value = vec[j].year;
        if (index == 1)
            value = vec[j].month;
        if (index == 0)
            value = vec[j].day;

        if (value <= pivot)
        {
            i++;

            func(vec, i, j);
        }
    }
    func(vec, i + 1, right);

    return i + 1;
}
void quick_sort(vector<Date>& vec, int left, int right, int index)
{
    if (left < right)
    {
        int p = partition(vec, left, right, index);
        quick_sort(vec, left, p - 1, index);
        quick_sort(vec, p + 1, right, index);
    }
}


int main(){
    int n;
    cin >> n;
    Date date;
    vector<Date> vec(n);
    for(auto &date : vec ){
        char g;
        cin >> date.day;
        cin >> g;
        cin >> date.month;
        cin >> g;
        cin >> date.year;
    }
    quick_sort(vec,0, vec.size() - 1, 0);
    quick_sort(vec,0, vec.size() - 1, 1);
    quick_sort(vec,0, vec.size() - 1, 2);
   
   

    
    for(auto i : vec){
        if(i.day < 10 && i.month < 10){
            cout  << '0' << i.day << "-" << '0' << i.month << '-' << i.year << endl;
            
        }
        if(i.month >= 10 && i.day < 10){
            cout  << '0' << i.day << "-" << i.month << '-' << i.year << endl;
            
        }
        if(i.day >= 10 && i.month < 10){
            cout << i.day << "-" <<'0'<< i.month << '-' << i.year << endl;
        }
        else if(i.day >= 10 && i.month >= 10)
            cout  << i.day << "-" << i.month << '-' << i.year << endl;
    }
   

}