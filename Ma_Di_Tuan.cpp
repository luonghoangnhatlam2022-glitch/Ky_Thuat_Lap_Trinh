#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int used[100][100];
int n = 8;

const int di[] = {2, 2, -2, -2, 1, 1, -1, -1};
const int dj[] = {1, -1, 1, -1, 2, -2, 2, -2};

int dem = 1;

void Dat_Ngua(int kx, int ky)
{
    if (dem == n * n) return;

    for (int i = 0; i < 8; i++)
    {
        int hang = kx + di[i];
        int cot = ky + dj[i];

        if (hang >= 1 && hang <= n && cot >= 1 && cot <= n && used[hang][cot] == 0)
        {
            used[hang][cot] = ++dem;

            Dat_Ngua(hang, cot);

            // ⭐ giống code step
            if (dem == n * n) return;

            // backtrack
            used[hang][cot] = 0;
            dem--;
        }
    }
}

int main()
{
    freopen("nhap.inp","r", stdin);
    freopen("output.out","w", stdout);
    used[1][1] = 1;

    Dat_Ngua(1, 1);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << used[i][j] << " ";
        cout << endl;
    }
}