// bai 1
#include <bits/stdc++.h>
using namespace std;
// bai 1
long long Pn(int n){
    if(n==1) return 1;
    return (2*n-1) * Pn(n-1);
}
// bai 2
int tim_kiem_vi_tri(int local,int a[],int x){
    if(a[local] == x ) return local ;
    if( local < 0 ) return -1;
    return tim_kiem_vi_tri( local-1, a, x);
}
int tim_kiem_nhi_phan(int right ,int left ,int a[],int x ,int n ){
    int mid = (left+right) / 2 ;

    if(left >= right ) return mid;

    if(x > a[mid] )
            return tim_kiem_nhi_phan(right , mid + 1 , a , x , n );
    else if(x< a[mid])
            return tim_kiem_nhi_phan(mid - 1 , left , a , x , n );
    else {
        if(a[mid+1] == x ){
            return tim_kiem_nhi_phan(right,mid + 1, a , x, n );
        }
        return mid ;
    }

}
// bai 4
int Fibo(int dp[],int n){
    dp[0]=0; dp[1]=1;
    for (int i = 2; i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

// bai 3
int n ;
void check(int n,int k,int saving[]){
    int count = 0;
    for (int i=1 ; i <= n; i++){
        if( saving[i] == 1 ) count ++ ;
    }
    if(count == k ) {
        for (int i=1;i<=n;i++){
            cout << saving[i];
        }
        cout <<endl;
    }
}
int saving[100];
void Try(int x,int k ){
    for (int i=0;i <= 1;i++){
        saving[x] = i ;
        if ( x == n ) {
            check(n,k,saving);
        }
        else {
            Try(x+1,k);
            // saving[x] -= i;
        }
    }
}

int main (){
    cin >> n;
    int k ;
    cin >> k ;
    Try(1,k);
    return 0 ;
}
