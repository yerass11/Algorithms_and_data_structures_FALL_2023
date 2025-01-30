#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

bool canDivide(ll max, int arr[], int n, int m) {
    ll sum = 0;
    int cnt = 1;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
        if (sum > max) {
            cnt++;
            sum = arr[i];
        }
    }
    return cnt <= m;
}

int main(){
    int n, k; cin >> n >> k;
    ll r = 0;
    int arr[n];
    int l = INT_MIN;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        r += arr[i];
        if (arr[i] > l) l = arr[i];
    }
    ll ans = r; 

    while (l <= r) {
        ll mid = (r - l) / 2 + l;
        if (canDivide(mid, arr, n, k)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans;

    return 0;
}