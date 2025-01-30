#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lowerIndex(vector<int>& arr, int x) {
    int l = 0, h = arr.size() - 1;
    while (l <= h) {
        int mid = (l + h) / 2;
        if (arr[mid] >= x)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}

int upperIndex(vector<int>& arr, int x) {
    int l = 0, h = arr.size() - 1;
    while (l <= h) {
        int mid = (l + h) / 2;
        if (arr[mid] <= x)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return h;
}

vector<int> nonOverlap(int l1, int r1, int l2, int r2) {
    vector<int> result;
    if ((r1 - l1) < (r2 - l2)) {
        swap(r1, r2);
        swap(l1, l2);
    }
    if (r2 <= r1 && l2 >= l1) {
        result.push_back(l1);
        result.push_back(r1);
    } else if (r2 <= r1 && r2 >= l1 && l2 < l1) {
        result.push_back(l1);
        result.push_back(r2 - 1);
    } else if (r2 > r1 && l2 < r1) {
        result.push_back(l1);
        result.push_back(r1);
        result.push_back(l2);
        result.push_back(r2);
    }
    return result;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    while (q--) {
        int l1, r1, l2, r2, res;
        cin >> l1 >> r1 >> l2 >> r2;
        vector<int> newRanges = nonOverlap(l1, r1, l2, r2);
        if (newRanges.size() == 2) {
            res = upperIndex(arr, newRanges[1]) - lowerIndex(arr, newRanges[0]) + 1;
        } else if (newRanges.size() == 4) {
            res = (upperIndex(arr, newRanges[1]) - lowerIndex(arr, newRanges[0]) + 1) +
                (upperIndex(arr, newRanges[3]) - lowerIndex(arr, newRanges[2]) + 1);
        } else {
            res = 0; // Handle the case when newRanges has an unexpected size
        }
        cout << res << "\n";
    }

    return 0;
}

