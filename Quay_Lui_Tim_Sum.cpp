// Tìm tổ hợp có tổng bằng X  
/* input: 3 10
          4 2 3 
    output: { 2 2 2 2 2}
            { 2 2 2 4 } 
            { 2 2 3 3 }
            { 2 4 4 }
            { 3 3 4 }
*/
#include<bits/stdc++.h>
using namespace std;
int S; 
int n; 
int a[100];
string s ; 
vector<string> save;
/// in hết tất cả các tổ hợp cho phép trùng  
void Try(int sum){
    if(S==sum){
        save.push_back(s);
    }
    for (int i=1;i<=n;i++){
        
        if(sum+a[i]<=S){
            int len=s.size();
            
            s+=to_string(a[i])+ " ";
            Try(sum+a[i]);

            s.erase(len);
        }
    }
}
void Try1(int st, int sum){
    if(sum == S){
        save.push_back(s);
        return;
    }

    for(int i=st;i<=n;i++){
        if(sum + a[i] <= S){
            int len = s.size();

            s += to_string(a[i]) + " ";
            Try1(i, sum + a[i]);   // vẫn cho phép dùng lại a[i]

            s.erase(len);
        }
    }
}
int X[100];
void Try2(int i,int start,int sum){
    for (int j=start;j<=n;j++){
        X[i]=a[j];                              
        sum+=a[j];
        if(sum==S){
            for (int id=1;id<=i;id++){
                cout << X[id]<< " ";
            }cout << endl; 
        }else if(sum<S){
            Try2(i+1,j,sum);
        }
        sum-=a[j];
    }
}

int main (){
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    int sum;
    cin>> n >> S ;
    for (int i=1;i<=n;i++){
        cin>> a[i];
    }
    sort(a+1,a+1+n);
    Try2(1,1,0);
    /*for (string s: save){
        cout << "{ " << s << " }"<< endl; 
    }
    return 0 ; */

}