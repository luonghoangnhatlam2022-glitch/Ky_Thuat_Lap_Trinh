/* day con tang dai nhat 
   truy suat day do ra 
*/
#include <bits/stdc++.h>
using namespace std; 
int L[1000]; // độ dài lớn nhất tính từ i 
int a[1000]; // vaule của các phần tử 
int Parents[1000]; // là đi đâu để đến i
// chỉ số i đứng trước i của dãy LIS 
void xuat(int n,int a[]){
    for (int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl; 
}
int main (){
    freopen("input.inp","r", stdin);
    freopen("output.out","w", stdout);
    int n; cin >> n;  
    for (int i=0;i<n;i++){
        cin>> a[i];
    }
    for (int i=0;i<n;i++){
        cout << i << " ";
    }
    cout << endl; 
    xuat(n,a);
    int result=1; // để lưu đồ dài lớn nhất 
    int position; // vị trí cần đến để đi đến vị trí cuối cùng 
    L[0]=1;
    Parents[0]=-1;
    for (int i=1;i<n;i++){
        L[i]=1; 
        for (int j=0;j<i;j++){
            if(a[i]>a[j]){
                L[i]=max(L[j]+1,L[i]);
                Parents[i]=j;
            }
        }
        if(L[i] > result){
            result= L[i];
            position=i ;
        }
    }
    xuat(n,L);
    xuat(n,Parents);
    cout << "Do Dai Day Tang Lon Nhat La: " << result << '\n'; 
    vector<int> save ;  
    while( position!=-1){
        save.push_back(a[position]);
        position=Parents[position];
    }
    reverse(save.begin(), save.end());
    for (int x : save){
        cout << x << " "; 
    }
    return 0 ; 
}