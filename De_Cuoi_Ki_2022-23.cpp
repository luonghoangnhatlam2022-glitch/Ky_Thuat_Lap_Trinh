#include <bits/stdc++.h> 
using namespace std; 


long long Bai_1_day_fibo(int n,long long fibo[],int m){
    for (int i=2;i<=n;i++){
        fibo[i]=fibo[i-1]%m +fibo[i-2]%m;
    }
    return fibo[n] % m; 
}
// (a+b) mod m == ((a mod m) + (b mod m)) mod m 

int dp[1000]; // co the tao duoc tong j hay khong 
long long Bai_2_cai_tui(int haft, int n, int a[]){
    dp[0]=1; 
    for (int i=1;i<=n;i++){
        for (int j=haft;j>=a[i];j--){
            dp[j]= dp[j] || dp[j-a[i]] ; 
        }
    }
    int tmp = 0 ;  
    for (int i=haft;i>=1;i--){
        if(dp[i]) 
        {
            tmp=i; 
            break ;
        }
    }
    return tmp ; 
}
int main (){
    freopen("input.inp","r", stdin); 
    freopen("xuat.out","w",stdout);
    // bai 1 
    //int n1;
    //int m1;  
    //cin >> n1; cin >> m1; 
    //long long fibo[1000]; 
    //fibo[0]=0; fibo[1]=1; 
    //cout << Bai_1_day_fibo(n1,fibo,m1); 

    //bai 2 
    int n2; 
    int a2[1000]; int S = 0 ; 
    cin >> n2 ;
    for (int i=1;i<=n2;i++){
        cin >> a2[i]; 
        S += a2[i] ; 
    }
    cout << S - 2*Bai_2_cai_tui(S/2 , n2 ,a2);
    cout << endl; 
    for (int i=0;i<=S/2;i++){
        cout << dp[i] << " "; 
    }
}