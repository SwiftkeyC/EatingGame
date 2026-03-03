#include <bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false); cin.tie(nullptr);

int main() {
    ios;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int S = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            S += a[i];
        }

        vector<char> canWin(n, 0);

        for (int start = 0; start < n; start++) {
            vector<int> b = a;
            int remaining = S;
            int idx = start;
            int last = -1;

            while (remaining > 0) {
                if (b[idx] > 0) {
                    b[idx]--;
                    remaining--;
                    last = idx;
                }
                idx = (idx + 1) % n;
            }

            canWin[last] = 1;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) ans += canWin[i];
        cout << ans << "\n";
    }

    return 0;
}
