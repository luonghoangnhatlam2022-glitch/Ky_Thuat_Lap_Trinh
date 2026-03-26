#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n = 4;
int a[100];
bool used[100];
// dùng quay lui để tính tất cả các tổ hợp của n
void backtrack(int k) {
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            a[k] = i;
            used[i] = true;

            if (k == n) {            
                for (int j = 1; j <= n; j++)
                    cout << a[j] << " ";
                cout << endl;
            } 
            else {
                backtrack(k + 1);
            }

            used[i] = false; // quay lui
        }
    }
}
///// dùng quay lui để tính nhị phân số chữ số là n 
int x=3;
int bit[100];

void SinhBit (int index) {
    if(index== x){
        for (int i=0;i<x;i++){
            cout << bit[i];
        }
        cout << endl; 
        return ;
    }
    bit[index]=0;
    SinhBit(index+1);
    bit[index]=1;
    SinhBit(index+1);
}
int k=4;
int t,X[100];
void SinhBit2(int index){
    for (int i=0;i<=1;i++){ 
        X[index]=i;
        if(index==k) {
            for (int i=1;i<=k; i++) 
                cout << X[i];
            cout << endl; 
            //return; 
        }
        else
            SinhBit2(index+1); 
    }
}
/////// tìm chỉnh hợp chập k của n 
// nCk in ra hết các gia tri 
int n1=5;
int k1=3; 
int X1[100];
void nCk(int i) {
    for (int j=X[i-1]+1;j<=n1-k1+i;j++){
        X[i]=j;
        if(i==k1){
            for (int t=1;t<=k1;t++){
                cout << X[t];
            }
            cout << endl; 
        }
        else 
            nCk(i+1);
    }
}
int nn=4 ,A[200][200]; 
string s ; 
void FindWay(int i,int j ){
    if(i == nn && j == nn){
        cout << s << endl ;
    }

    if(i + 1 <= nn && A[i+1][j]==1){
        s+="D";
        FindWay(i+1,j);
        s.pop_back(); // xoa D 
    }

    if(j + 1 <= nn && A[i][j+1]==1){
        s+="R";
        FindWay(i,j+1);
        s.pop_back();
    }
}
/// ///////// tìm đường đi theo 4 hướng 
int side=4, Array[100][100];
int destination=side;
string in;
void FindWayMax(int i,int j){
    if(i==destination && j== destination ){
        cout << in << endl ;
    }

    if( i+1 <= side && Array[i+1][j]==1){
        in+="D";
        Array[i+1][j]=0;
        FindWayMax(i+1,j);
        Array[i+1][j]=1;
        in.pop_back();
    }

    if( j+1 <= side && Array[i][j+1]==1){
        in+="R";
        Array[i][j+1]=0;
        FindWayMax(i,j+1);
        Array[i][j+1]=1;
        in.pop_back();
    }

    if( i-1 >=1 && Array[i-1][j]==1){
        in+="T";
        Array[i-1][j]=0;
        FindWayMax(i-1,j);
        Array[i-1][j]=1;
        in.pop_back();
    }

    if( j-1 >=1 && Array[i][j-1]==1){
        in+="L";
        Array[i][j-1]=0;
        FindWayMax(i,j-1);
        Array[i][j-1]=1;
        in.pop_back();
    }
}
////// CACH KHAC 
int Array1[100][100];
int dx[4]= {-1,0,0,1};
int dy[4]= {0,-1,1,0};
string path="ULRD";
vector<string> v ;
void FindWayOther(int i,int j){
    if(i==n && j==n ){
        v.push_back(s);
    }
    for (int k=0;k<4;k++){
        int i1=i+dx[k];
        int j1=j+dy[k];
        if(i1>=1 && j1>=1 && i1<=n && i1<=n && Array1[i1][j1]){
            s+=path[k];
            Array1[i1][j1]=0;
            FindWayOther(i1,j1);
            Array1[i1][j1]=1;
            s.pop_back();
        }
    }
}
int main() {
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    //backtrack(1);
    //SinhBit(0);
    //SinhBit2(1);
    //nCk(1);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin>> Array1[i][j];
        }
    }
    //FindWay(1,1);
    if(Array1[1][1] && Array1[n][n]){
        Array[1][1]=0;
        FindWayOther(1,1);
    }
    else cout << -1;
    if(v.size()>0){
        sort(v.begin(),v.end());
            for (string s: v){
                cout << s<< endl; 
    }
    }
}