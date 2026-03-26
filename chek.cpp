/*#include <bits/stdc++.h>
using namespace std;
int X[100];
void in(int n){
    for (int i=0;i<n;i++){
        cout << X[i];
    }
    cout << endl;
}
void SinhBit(int n){
    int k=n-1;
    while(true){
        if(X[k]==0 && k>=0){
            X[k]=1;
            for (int i=k+1;i<n;i++){
                X[i]=0;
            }
            in(n);
        }else
            k--;
        if(k==0) break;
    }
}
int main(){
    int n;
    cin>> n;
    for (int i=0;i<n;i++){
        X[i]=0;
    }

    SinhBit(n);
    return 0 ;
}*/
/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int x[100];
    // cấu hình khởi tạo: 1 2 ... k
    for (int i = 1; i <= k; i++) {
        x[i] = i;
    }
    int i, j;
    while (true) {
        // in cấu hình hiện tại
        cout << "(";
        for (i = 1; i <= k - 1; i++){
            cout << x[i] << ", ";
        }
        cout << x[k] << ")" << endl;
        // sinh cấu hình tiếp theo
        i = k;
        while (i > 0 && x[i] == n - k + i) {
            i--;
        }
        if (i == 0) break;
        x[i]++;
        for (j = i + 1; j <= k; j++) {
            x[j] = x[j - 1] + 1;
        }
    }
    return 0;
}*/
/*
#include <bits/stdc++.h>
using namespace std;
int Binary(int r,int l,int x,int a[]){
    if(l>r) return -1;

    int mid = (l+r)/2;

    if(a[mid]==x){
        int temp=Binary(mid-1,l,x,a);
        if(temp!= -1 ) return temp;
        return mid;
    }
    if(a[mid]<x){
        return Binary(mid-1,l,x,a);
    }else
        return Binary(r,mid+1,x,a);
}
int main(){
    return 0 ;
}*/

/*
#include <bits/stdc++.h>
using namespace std;
void KhoiTao(int n,int a[]){
    for (int i=1;i<=n;i++){
        a[i]=0;
    }
}
void Xuat(int n,int a[]){
    for (int i=1;i<=n;i++){
        cout << a[i];
    }
    cout << endl;
}
bool check=false;
void SinhNhiPhan(int n, int a[]){
    int i=n;

    while(a[i]==1 && i>=1){
        a[i]=0;
        i--;
    }

    if(i==0){
        check=true;
    }
    else
        a[i]=1;
}
bool condition(int n,int a[]){
    for (int i=1;i<=n;i++){
        if(a[i]==1){
            if(a[i]==a[i+1]) return false;
        }
    }
    return true ;
}
int main(){
    int n;
    int a[1000];
    cin>> n ;
    KhoiTao(n,a);
    while(!check){
        if(condition(n,a)){
        Xuat(n,a);
        }
        SinhNhiPhan(n,a);
    }
    return 0 ;
}
*/
#include <bits/stdc++.h>
using namespace std;
int n=3;
int a[100];
void in(int j,int a[]){
    for (int i=0;i<j;i++){
        cout << a[i];
    }
    cout << endl;
}
bool condition(int j, int a[]){
    for (int i=0;i<j-1;i++){
        if(a[i]==1){
            if(a[i]==a[i+1]) return false ;
        }
    } return true ;
}
void SinhBit(int k){
    for (int i=0;i<=1;i++){
        a[k]=i;
        if(k==n-1){
            if(condition(n,a))
                in(n,a);
        }else
            {
                SinhBit(k+1);
            }
    }
}
int main (){
    SinhBit(0);
}


















