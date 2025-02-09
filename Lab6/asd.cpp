#include<iostream>
#include<iostream>
#include<algorithm>
using namespace std;
class Date {
   public:
      int d, m, y;
};
bool compare(const Date &date1, const Date &date2){
   if (date1.y < date2.y)
      return true;
   if (date1.y == date2.y && date1.m < date2.m)
      return true;
   if (date1.y == date2.y && date1.m == date2.m && date1.d < date2.d)
      return true;
   return false;
}

void sortDateArray(vector<date> & arr, int n) {
   sort(arr, arr+n, compare);
}
int main() {
   int g;
   cin >> g;
   Date arr[g];
   for (int i = 0; i < g; g++){
    int a, b, c;
    char d;
    cin >> a >> d >> b >> d >> c;
   }
   int n = sizeof(arr)/sizeof(arr[0]);
   sortDateArray(arr, n);
   cout << "Sorted dates are" << endl;
   for (int i=0; i<n; i++) {
      cout << arr[i].d << " " << arr[i].m << " " << arr[i].y << endl;
   }
}