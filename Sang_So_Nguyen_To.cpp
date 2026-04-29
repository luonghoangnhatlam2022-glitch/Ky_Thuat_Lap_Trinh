#include <bits/stdc++.h>
using namespace std;
int main (){
    freopen("input.inp","r",stdin); 
    freopen("output.out","w",stdout); 
    int Danh_Dau[99999]; // toi da co the chua 
    int n; 
    cin >> n ;
    cout << "=============Sang So Nguyen To Tu 1 To n==========="<< '\n'; 
    // khoi tao 
    for (int i=2;i<=n;i++) Danh_Dau[i]=1; 
    Danh_Dau[0]=0; 
    Danh_Dau[1]=0; 

    // danh dau boi chung 
    for(int i =2;i<=sqrt(n);i++){
        if (Danh_Dau[i]==1)
            for (int j = i * i ;j <= n;j+=i){
               Danh_Dau[j]=0; 
            }
    }

    // xuat cac gia tri 
    for (int i=2;i<=n;i++){
        if( Danh_Dau[i]==1 ) cout << i << " ";     
    }



    cout << '\n' << "==============Sang So Nguyen To Tren Doan R To L============ "<< '\n'; 
    int Tick[99999]; 
    int L ; int R ; 
    cin >> L ; 
    cin >> R ; 

    // khoi tao  
    for(int i = L; i <= R ;i++) Tick[i]=1; 

    // danh dau gia tri tu L to R  
    for (int i = 2 ; i <= sqrt(R) ; i++) {
        if(Tick[i]==1)
            for (int j = max( i*i , (L+i-1)/(i*i)); j <=`R ; j +=i){
                Tick[j]=0; 
            }
    }

    // xuat cac gia tri 
    for (int i=L;i<=R;i++){
        if(Tick[i]==1) cout << i << " " ; 
    }
    return 0; 
}