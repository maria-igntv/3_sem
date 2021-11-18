#include <iostream>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[1000000] ;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }


    int k = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            k = k + 1;
        }
    }
    cout << k + 1 << "\n";

    return 0;
}