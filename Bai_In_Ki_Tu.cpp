/* nhap vao 1 string tat 
2 abc 
3 def 
4 ghi 
5 jkl 
6 mno 
7 pqs 
8 tuv 
9 wxyz 
vd : 23 
output == > ad ae af bd be bf cd ce cf 
*/ 
#include <bits/stdc++.h>
using namespace std; 
string output ;                                                        // chú ý dấu &
void solve(vector<string> mapping, int index,string digit,vector<string> & saving){
    if(index == digit.size()){
        saving.push_back(output);
        return ; 
    }

    int number = digit[index] - '0';
    string value = mapping[number];

    for (int j=0;j < value.size();j++){
        output.push_back(value[j]);
        solve( mapping , index + 1 , digit ,saving ); 
         output.pop_back();
    }
}
int main (){
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout); 
    string digit; 
    cin >> digit; 

    // mang chua ki tu theo so 
    vector<string> mapping={"","","abc","def","ghi","jkl","mno","pqs","tuv","wxyz"};
    vector<string> saving;
    solve(mapping , 0 , digit , saving);
    for (int i=0;i< saving.size();i++){
        cout << saving[i] << endl ;
    } 
    return 0 ; 
}
  

