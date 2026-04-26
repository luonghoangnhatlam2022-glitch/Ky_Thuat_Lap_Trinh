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
    while (a.size() > b.size()) b= "0"+ b ; 
    string result = ""; 
    int nho=0;
    for (int i=a.size()-1;i>=0;i--){
        int number = (a[i]-'0') -(b[i]-'0')- nho; 
        if ( nho < 0 ) {
            number +=10; 
            nho++; 
        }
        result.push_back(number+'0');
    }
    while(result.size()>0 && result.back()=='0') result.pop_back(); \
    reverse(result.begin(),result.end()); 
    return result; 
}
string mul(string a,string b){
    int do_dai_a=a.size();
    int do_dai_b=b.size();
        vector <int > result(do_dai_a+do_dai_b,0);
        for (int i=do_dai_a-1;i>=0;i--){
            for (int j=do_dai_b-1;j>=0;j--){
                int number=(a[i]-'0')*(b[j]-'0') + result[i+j+1];
                result[i+j+1]=number%10;
                result[i+j]+=number/10;
            }
        }
        string s="";
        for (int x : result){
            if(!(s=="" && x == 0)){
                s.push_back(x+'0');
            }
        }
        return s;
}
int main (){
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout); 
    string a; 
    string b; 
    cin >> a ; 
    cin >> b ; 
    cout << cong_hai_so_lon(a,b); 
    cout << endl; 
    cout<< tru_hai_so_lon(a,b);
    cout << endl ; 
    // tính giai thưa big number 
    int n ;
    cin >> n ;
    string res="1";
    for (int i=2;i<=n;i++){
        res=mul(res,to_string(i));
    }
    cout <<  res;
    return 0; 
}