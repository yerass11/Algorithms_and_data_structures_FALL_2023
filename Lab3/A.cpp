#include <bits/stdc++.h>

using namespace std;

int arr[800][800];

int findRow(int a[][800], int target, int n, int m) {
    int l = 0, r = n - 1, max, min, mid;
    while (l <= r) {
        mid = (r - l) / 2 + l;
        if (mid % 2 == 0) {
            max = a[mid][0];
            min = a[mid][m-1];
        } else {
            max = a[mid][m-1];
            min = a[mid][0];
        }
        if (target <= max && target >= min) {
            return mid;
        } else if (target <= min) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

int findDecreasing(int a[], int target, int m) {
    int l = 0, r = m - 1;
    while(l <= r) {
        int mid = (r - l) / 2 + l;
        if (a[mid] == target) {
            return mid;
        } else if (a[mid] > target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

int findIncreasing(int a[], int target, int m) {
    int l = 0, r = m - 1;
    while (l <= r) {
        int mid = (r - l) / 2 + l;
        if (a[mid] == target) {
            return mid;
        } else if (a[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

int main(){
    int t; cin >> t;
    vector <int> v(t);
    for (int i = 0; i < t; ++i) {
        cin >> v[i];
    }

    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }

    int row, col;

    for (int i = 0; i < t; ++i) {
        row = findRow(arr, v[i], n, m);
        if (row % 2 == 0) {
            col = findDecreasing(arr[row], v[i], m);
        } else {
            col = findIncreasing(arr[row], v[i], m);
        }
        if (row != -1 && col != -1) {
            cout << row << " " << col << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    
    return 0;
}