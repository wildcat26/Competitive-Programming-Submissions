#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector <int> budget(n, 0);
    for (int i = 0; i < n; ++i) {
       cin >> budget[i];
    }
    sort(budget.begin(), budget.end());
    cin >> q;
    int cost;
    int low, mid, high;
    while (q--) {
       cin >> cost;
       low = 0, high = n - 1;
       while (low <= high) {
          mid = (low + high)/2;
          if (low == mid) {
             if (budget[high] <= cost)
                cout << high + 1 << "\n";
             else if (budget[low] <= cost)
                cout << low + 1 << "\n";
             else cout << "0\n";
             break;
          }
          if (budget[mid] <= cost)
             low = mid;
          else
             high = mid - 1;
       }
    }
	return 0;
}
