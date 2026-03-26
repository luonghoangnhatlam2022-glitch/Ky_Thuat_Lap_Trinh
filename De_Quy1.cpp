#include <bits/stdc++.h>
using namespace std;
int GiaiThua(int n){
    if(n==1) 
        return 1;
    else 
        return GiaiThua(n-1)*n;
}
int P(int x,int y){
    if(y==1) 
        return x;
    else 
        return P(x,y-1)*x;
}
double S(int n){
    if(n==1) 
        return 1;
    else 
        return (double)(1)/n +S(n-1);
}
int Dem_So(int n){
    if(n/10==0) 
        return 1;
    else 
        return Dem_So(n/10)+1;
}
void Day_So_Giam(int n){
    cout << n << " ";
    if(n==1)
        return ;
    else
    {
        Day_So_Giam(n-1);
        cout << n << " ";
    }
}
void Day_So_Tang(int i,int n){
    cout << i << " ";
    if(n==i)
        return ;
    else
    {
        Day_So_Tang(i+1,n);
        cout << i << " ";
    }
}
///////////////////////////////////////
bool isEven(int n);
bool isOdd(int n);
bool isEven(int n){
    if(n==0) 
        return true;
    else 
        return isOdd(n-1);
}
bool isOdd(int n){
    if(n==0)
        return false ; 
    else 
        return isEven(n-1);
}
/////////////////////////////////// hổ tương
    /*Tính số hạng thứ n của dãy:
    x(0) = 1, y(0) = 0
    x(n) = x(n – 1) + y(n – 1)
    y(n) = 3*x(n – 1) + 2*y(n – 1)
    */
long yn(int n);
long xn(int n) {
    if (n == 0) return 1;
    return yn(n-1)+xn(n-1);
}
long yn(int n) {
    if (n == 0)  return 0;
    return 3*xn(n-1)+2*yn(n-1);
}
//////////////////////////////////// phi tuyến 
/*
Tính số hạng thứ n của dãy:
x(0) = 1
x(n) =n^2 *x(0) + (n-1)^2 *x(1) + ... + 2^2 * x(n-2) +1^2 * x(n-1) 
*/
long long Sx(int x){
    if (x == 0) return 1;
    long s = 0;
    for (int i=1; i<=x; i++)
        s = s + i*i*Sx(x-i);
    return s;
}
int main(){
    freopen("input1.inp", "r", stdin);
    freopen("output1.out", "w", stdout);
    int n1;
    int x,y;
    cin>>n1; 
    cin >> x>> y ;
    cout << GiaiThua(n1)<< '\n';
    cout << P(x,y)<< '\n';
    cout << S(n1)<< '\n';
    int count=123;
    cout << Dem_So(count)<< '\n';
    Day_So_Giam(5);
    cout << endl; 
    Day_So_Tang(1,5);
    cout << endl; 
    //////////////////////////////// 
    // đệ quy hỗ tương 
    int so =7;
    if(isEven(so))
        cout << "Even";
    else 
        cout << "Odd";
    ////////////////////
    cout <<endl << yn(3); 
    /////////////////// 
    cout << endl << Sx(3);
    return 0 ;
}