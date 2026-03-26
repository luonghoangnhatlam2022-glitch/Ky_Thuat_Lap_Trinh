#include <bits/stdc++.h>
using namespace std;
int main(){
    int n ;
    cin >> n;
    int a[1020];
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    int count=0;
    int count_best=0;
    int save=a[1];
    for (int i=1;i<=n-1;i++){
        if(a[i]==a[i+1]) {
            count ++;
        }
        else
        {
            if(count>count_best) save=a[i];
        }
    }
    cout << save ;
    return 0 ;
}
