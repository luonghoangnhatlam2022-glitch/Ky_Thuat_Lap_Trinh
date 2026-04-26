#include <iostream>
#include <fstream> 
using namespace std;
int main() {
   
    // ofstream mở file với mục đích để ghi file 
	// cach 1 
    ofstream f("space.txt", ios::out);
	f << "play football";
	f.close();

    // cach 2 
    ofstream a("space.txt");  // mặc định có ios::out 
    a << "hello"; 
    a.close();

    // cach 3  
    ofstream b; 
    b.open("space.txt"); 
    b << "nice to meet you" ; 
    b.close();

     freopen("xuat.out","w",stdout); 

    // ifstream dùng đễ đọc file 
    // luu y no chi doc toi khoang trang roi cat ngang 
    // VD: nice to meet you ==> s == nice 
    ifstream c; 
    c.open("space.txt"); 
    string s;
    c >> s ;    
    cout << s ; 
    c.close();

    fstream z;
    z.open("space.txt", ios::in | ios::out);
    z << "Hello";
    z.close();
    z.seekg(0);
    string ss;
    z >> ss;
}
