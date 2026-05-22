
#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;

    cout << "Enter array size: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> lis(n, 1);

    for(int i = 1; i < n; i++) {

        for(int j = 0; j < i; j++) {

            if(arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        ans = max(ans, lis[i]);
    }

    cout << "Length of LIS = " << ans;

    return 0;
}
