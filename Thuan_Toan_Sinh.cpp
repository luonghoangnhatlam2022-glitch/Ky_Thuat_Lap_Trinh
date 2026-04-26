#include <bits/stdc++.h>
using namespace std; 
void KhoiTao(int a[],int n){
    for (int i=0;i<n;i++){
        a[i]=0;
    }
}
void XuatCauHinh(int a[],int n){
    for (int i=0;i<n;i++){
        cout << a[i];
    }
    cout << endl; 
}

bool CheckCauHinh=false;
void SinhNhiPhan(int a[],int n){
    
    int i=n-1;
    while(a[i]==1 && i>=0){
        a[i]=0;
        i--;
    }
    if(i==-1){
        CheckCauHinh=true;
    }
    else
        a[i]=1;
}
/////////////////////////////////////////////////////////////////////////// 

void KhoiTaoToHop(int k,int a[]){
    for(int i=1;i<=k;i++){
        a[i]=i;
    }
}

void XuatToHop(int k,int a[]){
    for (int i=1;i<=k;i++){
        cout << a[i];
    } 
    cout << endl; 
}
bool CheckToHop =false ;
void SinhToHop(int k,int n,int a[]){
    int i=k;
    while(i>=0 && a[i]>=n-k+i){
        i--;
    }
    if(i==0) 
        CheckToHop=true;
    else 
    {
        a[i]++; 
        for (int j=i+1;j<k;j++){
            a[j]=a[j-1]+1;
        }
    }
}
// /////////////////////////////////////////////////////////////////////
void KhoiTaoGiaiThua(int so_N,int a[]){
    for (int i=1;i<=so_N;i++){
        a[i]=i;
    }
}

void XuatGiaiThua(int n,int a[]){
    for (int i=1;i<=n;i++){
        cout << a[i];
    }
    cout << endl; 
}
bool CheckGiaiThua=false; 
void SinhGiaiThua(int n,int a[]){
    int i=n-1; 
    while( i>=0 && a[i] < a[i+1]){
        i--;
    }
    if(i==0){
        CheckGiaiThua=true; 
    }
    else 
    {
        int j=n;
        while(a[j] < a[i]) j--; 
        swap(a[i],a[j]);
    }
}
int main (){
    freopen("nhap.inp","r",stdin);
    freopen("xuat.out","w", stdout);
    
    int n;
    int a[100];
    cin >> n ; 
    KhoiTao(a,n);
    while(!CheckCauHinh){
          // dieu kien them: Example: chỉ lấy bit có 3 số 1 liên tiếp  
        XuatCauHinh(a,n);
        SinhNhiPhan(a,n);
    }
/////////////////////////////////////////////////////////////////////////
    /* int K;
    int N; 
    int A[100];
    cin>> N >> K; 
    KhoiTaoToHop(K,A);
    while(!CheckToHop){
        XuatToHop(K,A);
        SinhToHop(K,N,A);
    }

/////////////////////////////////////////////////////////////////////
    int SoGiaiThua;
    int array[100];
    //KhoiTaoGiaiThua(SoGiaiThua,array);
    while(!CheckGiaiThua){
        XuatGiaiThua(SoGiaiThua,array);
        SinhGiaiThua(SoGiaiThua,array);
    }*/
    return 0; 
}