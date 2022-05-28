#include <iostream>

using namespace std;
const int maxE = (int)1e6 + 2;
int a , b , k;
int E[maxE + 5];
void eratos()
{
    E[1] = 0;
    for (int i = 2; i <= maxE; i++) E[i] = 1;
    for (int i = 2; i * i <= maxE; i++)
        if (E[i] == 1)
        for (int j = 2*i; j <= maxE; j += i) E[j] = 0;
    //for (int i = 2; i <= 100; i++) cout << E[i] << " "; cout << "\n";
    for (int i = 2; i <= maxE; i++) E[i] = E[i - 1] + E[i]; // prefix_sum
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    eratos();
    cin >> k;
    while (k--)
    {
        cin >> a >> b;
        cout << E[b] - E[a - 1] << "\n";
    }
    return 0;
}
