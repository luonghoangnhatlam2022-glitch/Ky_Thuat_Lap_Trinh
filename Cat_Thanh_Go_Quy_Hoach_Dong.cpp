/*đề bài :
cho một thanh gỗ dài L, bạn cần cắt thanh gỗ tại các vị trí cho trước 
c1,c2,c3,..ck chi phí mỗi lần cắt bằng độ dài của đoạn gỗ đang bị cắt 
.hãy tìm cách cắt sao cho tổng chi phí là nhỏ nhất 
vd: thanh gỗ L=10 / cắt tại 2 4 7 

*/
#include <bits/stdc++.h> 
using namespace std; 
void khai_bao(int n,int cut[]){
    for (int i=1;i<=n;i++){
        cin >> cut[i];
    }
}
int main (){
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    int cut[100];
    int L; // do dai thanh go 
    cin >> L ; 
    int n ; // so lan cat 
    cin >> n ; 
    khai_bao(n,cut); 
    
    // dp[i][j] la chi phi nho nhat de cat doan tu c[i] den c[j] 
    int dp[1000][1000]={0};
    cut[0]=0; cut[n+1]=L;  // khởi thêm đầu cuối cho mảng cut 
 
    for (int i = 0 ; i <= n + 1 ; i++  ){ 
        int length= i + 2 ; 
        for (int j = length ; j + length <= n + 1 ; j++ ) {

            for(int k = i ; k < j ; k++ ){
                dp[i][j]=min(dp[i][k],dp[k][j]) + cut[j]-cut[i];
            }       
        }
    }



    return 0 ; 

}