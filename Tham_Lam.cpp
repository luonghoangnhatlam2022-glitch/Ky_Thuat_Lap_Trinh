#include <bits/stdc++.h>
using namespace std ;
int main(){\
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    int n ; // phai la boi cua 50 
    cin >>  n; 
    int price[4]={50,100,200,500}; 
    int count = 0 ;
    for (int i = 3 ; i > 0 ;i -- ){
            count += n/price[i]; 
            n = n % price[i];
    }
    cout << count; 
    return 0 ; 
}