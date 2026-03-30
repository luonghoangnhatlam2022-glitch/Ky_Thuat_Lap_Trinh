// bai 1
/*
#include <bits/stdc++.h>
using namespace std;
int main (){
    int n ;
    int m ;
    cin>> n >> m ;
    int F[1000];
    F[0]=0;F[1]=1;
    for (int i=2;i<=n;i++){
        F[i]=F[i-1]+F[i-2];
    }
    cout << F[n]%m;

    return 0;
}*/
// bai 2
/*#include <bits/stdc++.h>
using namespace std;
int main (){
    int a[1000];
    int n ;
    cin >> n ;
    int TongVang=0;
    for (int i=0;i<n;i++){
        cin >> a[i];
        TongVang+=a[i];
    }
    int ChenhLechmin=INT_MAX;
    int TongHienTai=0;
    for (int i=0;i<n-1;i++){
        TongHienTai+=a[i];
        if(ChenhLechmin>TongVang-2*TongHienTai){
            ChenhLechmin=TongVang-2*TongHienTai;
        }
    }
    cout << ChenhLechmin;
    return 0;
}
*/
//bai 3
#include <bits/stdc++.h>
using namespace std;
void nhapmatran(int n ,int a[][1000]){
    for (int i=1;i,=n;i++){
        for (int j=1;j<=n;j++){
            cin >> a[i][j];        }
    }
}
int main (){
    int n ;
    int a[1000][1000];
    nhapmatran(n,a);
    for (int i=1;i<=n;i++){

        for (int j=1;j<=n;j++){

        }
    }
    return 0 ;
}
/*
// bai 4
#include <bits/stdc++.h>
using namespace std ;
int main (){
    int n;
    int a[100][100];
    int A[100];
    cin >> n ;
    int m = 1 ;
    int L[100]; // luu do dai lon nhat
    for (int i=1;i<=n;i++){
        for (int j=1;j<=2;j++){
        cin>> a[i][j];
        if(j==1) A[m++]=a[i][j];
        }
    }
    sort(A+1,A+n+1);
    int result=1;
    for (int i=1;i<=n;i++){
        L[i]=1;
        for (int j=1;j<=i-1;j++){
            if(A[i] > A[j] && A[i]-A[j]==1){
                L[i]=max(L[i],L[j]+1);
            }
            if(L[i]>result) result=L[i];
        }
    }
    cout << result ;
    return 0 ;
}*/
