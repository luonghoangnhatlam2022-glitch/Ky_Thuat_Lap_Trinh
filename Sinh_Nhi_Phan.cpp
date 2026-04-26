#include <bits/stdc++.h>
using namespace std ;
// Khởi Tạo Giá Trị Ban Đầu 
void khoi_tao(int a[],int n ){
    for (int i = 1 ;i <= n; i++ ) {
        a[i]= 0 ; 
    }
}
void xuat_nhi_phan(int n ,int a[]){
    for (int i =1 ; i <=n ;i ++){
        cout << a[i] ; 
    }
    cout << endl; 
}


// Sinh Nhi Phan Binh Thuong 
bool check = true; 
void sinh_nhi_phan(int n ,int a[]){
    int i = n ; 
    while(a[i] == 1 && i >= 0 ){
        a[i] = 0 ; 
        i --;  
    }
    if( i == 0 ) check = false ; 
    else  a[i] = 1 ; 
}


/// Cho hai số nguyên dương n và k (k≤n). Liệt kê tất cả các dãy nhị phân độ dài n
//có đúng k chữ số 1. 
//(Ví dụ: Với n = 4 và k = 2, các dãy thỏa mãn là: 0011, 0101, 0110, 1001, 1010, 1100).
int n, k, a[100];
void in() {
    int b[100] = {0};
    for (int i = 1; i <= k; i++)
        b[a[i]] = 1;

    for (int i = 1; i <= n; i++)
        cout << b[i];
    cout << endl;
}
void sinh_dieu_kien(){
for (int i = 1; i <= k; i++)
        a[i] = i ;

    while (true) {
        in();

        int i = k;
        while (i > 0 && a[i] == n - k + i)
            i--;

        if (i == 0) break;

        a[i]++;
        for (int j = i + 1; j <= k; j++)
            a[j] = a[j - 1] + 1;
    }
}
int main (){
    freopen("nhap.inp","r",stdin); 
    freopen("xuat.out","w",stdout); 
    int n , k ; 
    int a[100]; 
    cin >> n >> k ; 
    sinh_dieu_kien();
    return 0 ; 
}
