/* cho ma tran n*m và các số phần tử không âm hãy bắt đầu đi từ
vị trí ô 1 1 đến ô n * m sao cho tổng đường đi là nhỏ nhất với điều
kiện là chỉ đi lên hoặc đi sang phải  M hàng N cột  */
#include <bits/stdc++.h>
using namespace std ;

void NhapMang(int n,int m,int Array[][100]){
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            cin >> Array[i][j];
        }
    }
}
void Xuat(int n,int m,int Array[][100]){
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            cout << Array[i][j] << " " ;
        }
        cout << endl;
    }
}
int dp[100][100]; // dp[i][j] la gia tri nho nhat khi di den o i,j
int value=INT_MAX;
void tim_duong_di(int n,int m,int Array[][100]){
    // vi tri bat dau 
    dp[1][1]=Array[1][1]; 
    
    // tinh gia tri cua hang dau tien
    for (int i=2;i<=n;i++){
        dp[1][i]=Array[1][i]+ dp[1][i-1];
    }

    // tinh gia tri cua cot dau tien
    for (int i=2;i<=m;i++){
        dp[i][1]=Array[i][1]+ dp[i-1][1];
    }

    // xet vi tri phia tren hay ben trai cong vao voi gia tri hien tai xem nao nho hon thi lay 
    for (int i=2;i<=m;i++){
        for (int j=2;j<=n;j++){
            dp[i][j]=min(dp[i-1][j]+ Array[i][j],dp[i][j-1]+ Array[i][j]);
        }
    }
}
int main(){
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    int n, m ;
    cin >> m >> n ;
    int A[100][100];
    NhapMang(n,m,A);
    tim_duong_di(n,m,A);
    Xuat(n,m,dp);

    cout << dp[m][n];
    return 0 ;
}

/* 
input 
3 3
1 3 1
1 5 1
4 2 1

output 
1 4 5 
2 7 6 
6 8 7 
7
*/

