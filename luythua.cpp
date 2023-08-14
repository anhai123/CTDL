#include <iostream>
#include <cmath>

using namespace std;

double power(double x, int n)
{
    double result = 1.0;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            result *= x;
        }
        x *= x;
        n /= 2;
    }
    return result;
}

int main()
{
    double x;
    int n;

    cout << "Nhap x: ";
    cin >> x;

    cout << "Nhap n: ";
    cin >> n;

    double result = power(x, n);

    cout << x << "^" << n << " = " << result << endl;

    return 0;
}
