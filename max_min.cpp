#include <iostream>
#include <climits>

using namespace std;

int main()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Nhap day so: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int max = INT_MIN;
    int min = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    cout << "Gia tri lon nhat: " << max << endl;
    cout << "Gia tri nho nhat: " << min << endl;
    delete[] arr;
    return 0;
}
