/*Cho tập tin văn bản chứa nội dung mảng 1 chiều các phân số như sau;
3
-2	3
1	4
4	9

- Dòng đầu chứa 1 số nguyên dương n <= 100, là số lượng các phân số.
- n dòng tiếp theo mỗi dòng chứa 2 số nguyên (từ -100 đến 100, khác 0), lần lượt là giá trị từng 
phân số của mảng.Hãy viết (các) HÀM đọc dữ liệu từ tập tin này vào mảng 1 chiều chứa các phân số, 
tìm và trả về vị trí của phân số có giá trị tuyết đối (số thực) nhỏ nhất. Trường hợp có nhiều phân 
số cần tìm như nhau thì trả về vị trí nhỏ nhất (bên trái nhất).

VD: với tập tin trên, kết quả trả về vị trí 1 (phân số 1/4 có giá trị tuyệt đối là 0.25 – nhỏ nhất).
*/ 
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
struct phan_so
{
    int mau_so ;
    int tu_so ; 
};  
void nhap_phan_so(phan_so array[],int n ){
    for (int i = 0 ; i < n ; i++ ){ 
        cin >> array[i].mau_so; 
        cin >> array[i].tu_so; 
    }
}
int take_a_value(double value[100]){
    ifstream data; 
    data.open("space.txt"); 
    int x ; // lấy gia tri dong đau tien 
    data >> x ; // lấy dòng đầu tiên bỏ 

    int a , b ; 
    for (int i=0 ; i < x ; i++ ){
        data >> a >> b ;

        value[i]=abs((double)a/b); 
    }
    data.close(); 

    // tim vi tri so nho nhat 
    int value_min=INT_MAX; 
    int local ; 
    for (int i=0 ; i < x ; i++ ){
        if(value[i] < value_min ) {
            value_min= value[i]; 
            local = i + 1  ; 
        }
    }
    return local; 

}
int main (){
    int n ; 
    cin >> n ; // n <=100 
    phan_so a[1000]; 
    nhap_phan_so(a,n);
    
    // ghi file 
    ofstream f; 
    f.open("space.txt");
    f << n << '\n';
    for (int i=0 ; i < n ; i++ ){
        f << a[i].mau_so << " "; 
        f << a[i].tu_so << '\n'; 
    }
    f.close();

    double value[1000]; 
    cout <<  take_a_value(value);
    return 0 ; 

}