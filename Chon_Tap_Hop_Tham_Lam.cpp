#include <bits/stdc++.h>
using namespace std;
int main (){
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    int n; 
    int a[1000];
    cin >> n ;
    // nhap mang 
    int sum_all=0; 
    for (int i=0;i<n;i++){
        cin >> a[i]; 
        sum_all+=a[i];
    }
    // ===========================> greedy <====================
    sort(a, a + n, greater<int>());
    int count=0;int sum_private=0; 
    for(int i = 0; i < n  ; i ++){
        sum_private += a[i];
        count ++;  
        if(sum_private > sum_all - sum_private) break; 
            count ++; 
            sum_private += a[i]; 
    }
    cout << count ; 


    // ==============================> program dynamic <==============
    //dp[i] số phần tử ích nhất có thể đạt tổng i
    vector<int> dp(sum_all + 1, INT_MAX);
    dp[0] = 0;

    for(int i = 0; i < n; i++){
        for(int j = sum_all; j >= a[i]; j--){
            if(dp[j - a[i]] != INT_MAX){
                dp[j] = min(dp[j], dp[j - a[i]] + 1);
            }
        }
    }

    int res = INT_MAX;
    for(int j = sum_all/2 + 1; j <= sum_all; j++){
        res = min(res, dp[j]);
    }

    cout << res;
    return 0 ; 
}