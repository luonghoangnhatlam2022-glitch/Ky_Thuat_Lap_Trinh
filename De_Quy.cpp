#include <bits/stdc++.h>
using namespace std;
int Tongn(int n){
    if(n==1)
        return 1;
    else 
        return (n+Tongn(n-1));
}
int GiaiThua(int n){
    if(n==1) 
        return 1;
    else   
        return (GiaiThua(n-1)*n);
}
long long  Fibonaci(int n){
    if(n<=1) 
        return n; 
    else 
    return Fibonaci(n-1)+Fibonaci(n-2);
}
long long nCk(int n,int k){
    if(n==k || k==0) return 1; 
    else 
        return nCk(n-1,k)+nCk(n-1,k-1);
}
int UCLN(int a,int b){
    if(b==0) return a;
    else 
        return UCLN(b,a%b);
}
int binpow(int a,int b){
    if(b==0) return 1; 
    int x=binpow(a,b/2);
    if(b%2==1)
        return a*x*x;
    else 
        return x*x;
}
int countfigure(int n){
    if(n<10) 
        return 1; 
    else 
        return countfigure(n/10)+1; 
}
int main(){
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    int n;
    cin>> n; 
    cout << "Tong Cac So Tu 1-n: " << Tongn(n);
    cout << endl; 
    cout << "N!=: " << GiaiThua(n);
    cout << endl ;
    cout << "So FiBo thu: " <<  Fibonaci(n)<< endl; 
    cout << nCk(10,2) << '\n';
    cout << UCLN(12,3)<< '\n';
    cout << binpow(2,10)<< '\n';
    cout << countfigure(11000);
    return 0; 
}