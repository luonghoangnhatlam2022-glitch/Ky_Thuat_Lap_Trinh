#include <bits/stdc++.h>
using namespace std;
// tìm kiếm nhị phân 
int binary_search(int a[], int n, int k){
    if ( n <= 0 ) return 0 ; 

    int left = 0 ; 
    int right = n - 1 ; 

    while( left < right ){
        int mid = ( right + left ) / 2 ;
        if(a[mid] == k) return mid;
        if(a[mid] > k ) right = mid - 1 ;
        else left = mid + 1 ;
    }

    return -1 ; 
}

// tìm kiếm nhị phân mà tìm vị trí cuối cùng của phần tử đó  
int binary_search_arrive_final(int a[], int n, int k){
    if ( n <= 0 ) return 0 ; 

    int left = 0 ; 
    int right = n - 1 ; 

    int saving = -1 ;
    while( left <= right ){
        int mid = ( right + left ) / 2 ;
        if(a[mid] == k) {
            saving = mid ;
            left = mid + 1 ; 
        }
        else if( a[mid] > k ) right = mid - 1 ;
        
        else left = mid + 1  ;
    }
    return saving ; 
}

// tìm kiếm nhị phân tìm vị trí đầu tiên 
int binary_search_arrive_first(int a[], int n, int k){
    if ( n <= 0 ) return 0 ; 

    int left = 0 ; 
    int right = n - 1 ; 

    int saving = -1 ;
    while( left <= right ){
        int mid = ( right + left ) / 2 ;
        if( a[mid] == k ) {
            saving = mid ;
            right = mid - 1  ; 
        }
        else if( a[mid] > k ) right = mid - 1 ;
        
        else left = mid + 1  ;
    }
    return saving ; 
}
////////////////////////////////////////////// 
// đệ quy 
// tìm kiếm nhị phân 
int binary_search_recursion(int left , int right ,int k , int a[] ){
    if( left >= right ) return left ;

    int mid = (left + right ) / 2 ; 

    if(a[mid] == k ) return mid ;
    if(a[mid] > k) 
        return binary_search_recursion( left , mid -1 , k ,a);
    else 
        return binary_search_recursion(mid + 1,right , k , a );
}


// đệ quy tìm kiếm nhị phân vị trí cuối 
int binary_search_recursion_final(int left , int right ,int k , int a[] ){
    if( left > right ) return -1 ;

    int mid = (left + right ) / 2 ; 

    if(a[mid] == k ) {
        int res = binary_search_recursion_final(mid + 1 , right , k ,a);
        if(res != -1 ) return res; 
        return mid ;
    }
    else if (a[mid] > k) 
        return binary_search_recursion_final( left , mid -1 , k ,a);
    else 
        return binary_search_recursion_final(mid + 1,right , k , a );
}

// đệ quy tìm vị trí đầu tiên 
int binary_search_recursion_first(int left , int right ,int k , int a[] ){
    if( left > right ) return -1 ;

    int mid = (left + right ) / 2 ; 

    if(a[mid] == k ) {
        int res = binary_search_recursion_final(left , mid -1  , k ,a);
        if(res !=  -1 ) return res ; 
        return mid ; 

    }
    else if (a[mid] > k) 
        return binary_search_recursion_first( left , mid -1 , k ,a);
    else 
        return binary_search_recursion_first(mid + 1,right , k , a );
}

int main (){
    freopen("nhap.inp","r",stdin);
    freopen("xuat.out","w",stdout); 
    int n ; 
    cin >>  n ; 
    int k ; cin >> k ; 
    int a[100];
    for (int i=0 ; i<n ; i++ ) {
        cin >> a[i]; 
    }
    
    cout << binary_search_recursion_final(0,n-1,k,a); 
}