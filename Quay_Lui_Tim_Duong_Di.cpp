#include <bits/stdc++.h>
using namespace std; 
int save=INT_MAX;
int price; 
int  visited[100];
int X[100],a[100][100];
int n;
// luu vi tri 
void Try(int k){
    for (int j=1;j<=n;j++){
        if(visited[j]==0){
            visited[j]=1;
            X[k]=j;
            price+=a[X[k-1]][X[k]];
            if(k==n){
                save=min(save, price+a[X[n]][1]);  
            }
            else {
                Try(k+1);
            }
            visited[j]=0;
            price-=a[X[k-1]][X[k]];
        }
    }
}
int main(){
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    visited[1]=1;
    X[1]=1;
    cin >> n ; 
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    Try(2);
    cout << save ;
    return 0 ; 

}