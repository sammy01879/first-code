
#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter rod length: ";
    cin >> n;

    int price[n+1];

    cout << "Enter price for each length:\n";
    for(int i = 1; i <= n; i++) {
        cout << "Length " << i << " price: ";
        cin >> price[i];
    }

    int dp[n+1];

    dp[0] = 0;

    // Dynamic Programming
    for(int i = 1; i <= n; i++) {
        int maxProfit = -1;

        for(int j = 1; j <= i; j++) {
            int current = price[j] + dp[i - j];

            if(current > maxProfit) {
                maxProfit = current;
            }
        }

        dp[i] = maxProfit;
    }

    cout << "\nMaximum Profit = " << dp[n];

    return 0;
}
