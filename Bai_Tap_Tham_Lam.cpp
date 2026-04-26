/*
(2 điểm) Cài đặt một giải thuật theo phương pháp tham lam (Greedy) để 
tìm một đường đi từ 1 ô trên dòng 0 (cạnh trên) xuống dòng N-1 (cạnh dưới) 
của ma trận, sao cho tổng giá trị các phần tử nằm trên đường đi là lớn nhất. 
Nguyên tắc đi như sau: ở mỗi bước, chỉ có thể đi xuống dòng liền kề với dòng
 hiện tại và chỉ được chọn 1 trong 3 vị trí gần vị trí hiện tại nhất. Tức là, 
 từ vị trí hiện tại (i, j), ta chỉ có thể đi đến các vị trí 
 (i+1, j-1), (i+1, j) hoặc (i+1, j+1).
    vd: 
    1 14 15 4 
    12 7 6 9 
    8 11 10 5 
    13 2 3 16 
    in ra tổng lớn nhất : 50 chọn (15 9 10 16 ) ; 
    */

//======================> DÙNG PROGRAM DYNAMIC   <===========================

/*
#include <bits/stdc++.h>
using namespace std;
void nhap(int n,int a[100][100]){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin >> a[i][j]; 
        }
    }
}
int main (){
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    int n ;
    int a[100][100]; 
    cin >> n ; 
    nhap(n,a); 
    int value_max = INT_MIN; 

    int dp[100][100]; 
    // khoi tao hang dau 
    for (int k=0;k<n;k++){
        dp[0][k]=a[0][k]; 
    }
    for (int i = 1 ; i < n ; i ++ ){
        for (int j = 0 ; j < n ;  j ++ ){
            int number_max= dp[i-1][j]; 
            if (j > 0 ) number_max = max(number_max,dp[i-1][j-1]);
            if(j<n-1) number_max = max(number_max,dp[i-1][j+1]);
            dp[i][j]=number_max+a[i][j];
        }
    }
    for (int j=0;j<n;j++){
        value_max=max(value_max,dp[n-1][j]);
    }
    cout << value_max ; 

    return 0 ; 
}
*/ 

//==================================> VÉT CẠN <===============================
#include <bits/stdc++.h>
using namespace std;

int n, a[100][100];
int ans = INT_MIN;

void Try(int i, int j, int sum){
    sum += a[i][j];

    if(i == n-1){
        ans = max(ans, sum);
        return;
    }

    if(j > 0) Try(i+1, j-1, sum);
    Try(i+1, j, sum);
    if(j < n-1) Try(i+1, j+1, sum);
}

int main(){
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> a[i][j];

    for(int j=0;j<n;j++){
        Try(0, j, 0);
    }

    cout << ans;
}