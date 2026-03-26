#include <bits/stdc++.h>
using namespace std;
void add(char a[],char b[]);
void reverse(int a[],int n);
int main(){
    freopen("xlsl.inp", "r", stdin);
    freopen("xlsl.out", "w", stdout);
    char s1[1000]; 
    char s2[1000]; 
    cin.getline(s1,1000);
    cin.getline(s2,1000);
    cout<< s2 ;
    return 0; 
}
// mat dinh so s1 dai hon 
void add(char a[],char b[]){
    int s1=strlen(a); int s2=strlen(b);
    int n ;
    int x[s1] , y[s1], z[s1+1];
    for (int i=0;i<s1;i++) x[i]=a[i]-'0';
    for (int i=0;i<s2;i++) y[i]=b[i]-'0';
}
void reverse(int a[],int n){

}
