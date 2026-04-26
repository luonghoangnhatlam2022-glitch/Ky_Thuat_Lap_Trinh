/*Cho biết bạn có thể thực hiện một trong hai thao tác sau nhiều lần trên mảng a gồm n số nguyên.

• Chọn a[i], bạn thu được a[i] điểm
• Chọn a[i] và a[i+1], thu được a[i]*a[i+1] điểm

Khi một số đã được chọn, nó sẽ bị bỏ ra và không thể được chọn lại. Bạn cần thực hiện các thao tác sao cho số điểm đạt được là lớn nhất.

Dữ liệu vào:
• Dòng đầu tiên gồm số nguyên dương n là phần tử của mảng a.
• Dòng tiếp theo gồm n số nguyên lần lượt là giá trị của các phần tử trong mảng.

Dữ liệu ra:
• Điểm số lớn nhất có thể đạt được (bạn có thể không chọn một số phần tử).

Ràng buộc:
• 1 ≤ n ≤ 100
• -9 ≤ a[i] ≤ 9

Ví dụ

Dữ liệu vào
9
-4 1 1 8 7 3 -3 -2 2

Dữ liệu ra
69
Giải thích
Bạn sẽ lần lượt chọn a[1], a[2], (a[3], a[4]), a[5], (a[6], a[7]), và a[8].
Điểm số thu được là 1 + 1 + 8 * 7 + 3 + (-3) * (-2) + 2 = 69.
*/
#include <bits/stdc++.h>
using namespace std;
void input(int n ,int a[]){
    for (int i=0;i<n;i++){
        cin >> a[i]; 
    }
}
int main(){
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    int n; 
    cin >> n ;
    int a[100]; 
    input(n,a);

    int dp[100]; 
    dp[0]=a[0]; 
    dp[1]=max(a[0]*a[1],a[1]); 
    for (int i=2;i<n;i++){
        dp[i]=max(dp[i-2]+a[i-1]*a[i],dp[i-1]+a[i]);
    }
    for (int i=0 ; i < n; i++){
        cout << dp[i] << " ";
    }
/*
Cho mảng a gồm n số nguyên. Cho biết số phần tử tối thiểu mà tổng của chúng 
lớn hơn tổng các phần tử còn lại của mảng.
Dữ liệu vào:
• Dòng đầu tiên gồm số nguyên dương n là phần tử của mảng a.
• Dòng tiếp theo gồm n số nguyên lần lượt là giá trị của các phần tử trong 
mảng.
Dữ liệu ra:
• Số phần tử tối thiểu theo mô tả trên.
Ràng buộc:
• 1 ≤ n ≤ 100
• -100 ≤ a[i] ≤ 100
Ví dụ
Dữ liệu vào
4
4 2 5 1
Dữ liệu ra
2
Giải thích
Tập con {4, 5} hoặc {2, 5} là các tập con có 2 phần tử
 mà tổng của chúng lớn hơn tổng các phần tử còn lại. Tập con 
 chỉ một phần tử có tổng lớn nhất là 5 (bé hơn tổng các phần 
 tử còn lại là 7).
    */
}