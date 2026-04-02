/*#include <bits/stdc++.h>
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
*/
#include <bits/stdc++.h>
using namespace std ;
char doi_so_sang_ki_tu(int n){
    char KiTu = n + '0';
    return KiTu; 
}
int doi_ki_tu_sang_so(char n){
    int So = n - '0'; 
    return So; 
}
string cong_hai_so_lon(string a,string b){ // a > b 
    for (int i=b.size();i < a.size();i++) b = "0" + b ; 

    int nho=0;
    int example; 
    string result; 
    for (int i=a.size()-1;i>=0;i--){
        
        example = doi_ki_tu_sang_so(a[i])+doi_ki_tu_sang_so(b[i]) + nho ; 
        nho = example/10 ;
        result = doi_so_sang_ki_tu(example % 10) + result ; 

    }

    if ( nho > 0 ) {
        result = doi_so_sang_ki_tu(nho) + result ;
    }
    return result ; 

}
string tru_hai_so_lon(string a,string b){
    for (int i=b.size();i < a.size();i++) b="0"+b ; 

    int nho=0; 
    int example ; 
    string result;
    for (int i = a.size()-1;i>=0;i--){
        if(a[i]>=b[i]){
            example = doi_ki_tu_sang_so(a[i]) - (doi_ki_tu_sang_so(b[i]) + nho);
            nho=0; 
        }
        else
        {
            example = ( doi_ki_tu_sang_so(a[i]))+ 10  - doi_ki_tu_sang_so(b[i]) - nho ;
            nho=1;
        }

        result = doi_so_sang_ki_tu( example ) + result ; 
    }
    
    if ( nho > 0  ) {
        result = doi_so_sang_ki_tu(nho) + result ;        
    }
    int i=0; 
    while(result[i]=='0'){
        result.erase(0,1);
    }
    return result ; 
    
}
int main (){
    string a; 
    string b; 
    cin >> a ; 
    cin >> b ; 
    cout << cong_hai_so_lon(a,b); 
    cout << endl; 
    cout<< tru_hai_so_lon(a,b);
    return 0; 
}