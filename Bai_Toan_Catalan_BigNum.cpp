// tinh Catalan(n)= (2n)! / (n+1)! n!  = (n+2)(n+3)...(2n)/ 1.2.3.4...n 
#include <bits/stdc++.h>
using namespace std ;
int main (){
    int n ;
    cin >> n ; 
    vector < long long > tu_so; 
    vector < long long > mau_so; 
    
    tu_so.push_back(n+2);
    // mau_so.push_back(1); 
 
    for (int i = 3 ; i <= n ; i ++) {
        int nho_tu = 0 ; 
        for (int j = 1 ; j <= tu_so.size() ;j++) {
            
            tu_so[j] = (tu_so[j] * (n + i)) % 100;


        }
    }
    return 0 ; 
}