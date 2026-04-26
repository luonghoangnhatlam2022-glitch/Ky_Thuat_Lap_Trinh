#include <bits/stdc++.h>
using namespace std; 
int W[100];
int P[1000];
int dp[100][100]; 
int a[100][100];
/*F[i][j] là giá trị lớn nhất có thể có bằng cách chọn gói
trong các gói {1, 2, ...,i} với giới hạn trọng lượng j. Thì giá trị lớn
nhất khi được chọn trong số n gói với giới hạn trọng lượng M chính là F[n, M].*/
void Nhap(int n,int array[]){
    for (int i=1;i<=n;i++){
        cin >> array[i]; 
    }
}
int main(){
    freopen("input.inp","r",stdin);
    freopen("xuat.out","w",stdout); 
    int S; int n ; 
    cin >> n ; 
    cin >> S ;
    Nhap(n,W); 
    Nhap(n,P);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=S;j++){
            dp[i][j]=dp[i-1][j];
            if(j >= W[i]){
                dp[i][j]=max(dp[i][j],dp[i-1][j-W[i]]+P[i]);
            }
        }
    }
    cout << dp[n][S] << '\n';
    for (int i=0;i <= n;i++){
        for (int j =0 ;j <= S;j++){
            cout << dp[i][j] << " ";
        }
        cout << endl; 
    }
    cout << endl;


    // truy vet  
    int current=S ; 
    for (int i=n;i>=1;i--){
        if (dp[i][current] != dp[i-1][current]){
            cout << "chon vat thu: " << i << endl; 
            current -= W[i];
        }
    }
    return 0; 
}