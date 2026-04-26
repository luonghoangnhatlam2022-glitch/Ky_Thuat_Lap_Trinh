#include <bits/stdc++.h>
using namespace std;
int X[100];
bool chek[100];
int n1; int m;
vector<int> s[100]; 
int sz=0;
void ChinhHop(int k){
    for (int i=1;i<=n1;i++){
        if(chek[i]==false){
            //chek[i]=true;
            X[k]=i;
            if(k == m){
                ++sz;
                for (int i=1;i<=m;i++){
                    s[sz].push_back(X[i]);
                }
            }else 
                ChinhHop(k+1);
        }
        //chek[i]=false;
    }
}
int CheoNguoc[100];
int CheoXuoi[100];
int Ngang[100];
int A[100];
int n=5;
void Dat_Hau(int i){
    for (int j=1;j<=n;j++){
        if(Ngang[j]==0 && CheoNguoc[i+j+1]==0 && CheoXuoi[n-j+i]==0){
            Ngang[j]=1 ;
            CheoNguoc[i+j+1]=1;
            CheoXuoi[n-j+i]=1;
            A[i]=j;
            if(i==n){
                for (int k=1;k<=n;k++){
                    cout << "{" << k <<","<< A[k] << "}" << " ";
                }
                cout << endl; 
            }
            else Dat_Hau(i+1);
        Ngang[j]=0;
        CheoXuoi[n-j+i]=0;
        CheoNguoc[i+j+1]=0;
    }
    }
}
int main(){
    freopen("nhap.inp", "r", stdin);
    freopen("xuat.out", "w", stdout);
   /* cin>> n1 ;
    cin>> m ;
    ChinhHop(1);
    cout<< sz; 
    cout << endl; 
    for(int i=1;i<=sz;i++){
        for(int x: s[i]){
            cout << x << " ";
        }
         cout << endl; 
    }*/
    Dat_Hau(1);
    return 0 ; 
}