#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

struct Heap {
    ll *a; 
    ll capacity;
    ll size;

    ll parent (ll i) {
        return (i-1) / 2;
    }

    ll left(ll i) {
        return i*2 + 1;
    }

    ll right(ll i) {
        return i*2 + 2;
    }

    void add(ll x) {
        a[size] = x;
        size++;
        heapUp(size-1);
    }

    void heapUp(ll i) {
        if (i > 0) {
            ll p = parent(i);
            if (a[i] < a[p]) {
                swap(a[i], a[p]);
                heapUp(p);
            }
        }
    }

    void heapDown(ll i) {
        ll l = left(i);
        ll r = right(i);
        ll min = i;
        if (l < this->size && a[l] < a[min]) {
            min = l;
        }
        if (r < this->size && a[r] < a[min]) {
            min = r;
        }
        if (i != min) {
            swap(a[i], a[min]);
            heapDown(min);
        }
    }

    void poll() {
        a[0] = a[size-1];
        size = max(ll(0), size-1);
        heapDown(0);
    }

    void print() {
        for (ll i = 0; i < size; ++i) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }

    Heap (ll x) {
        this->a = new ll[x];
        this->size = 0;
        this->capacity = x;
    }
};

int main() {
    ll n, m; cin >> n >> m;
    Heap H(n);
    for (int i = 0; i < n; ++i) {
        ll x; cin >> x;
        H.add(x);
    }
    long long int cnt = 0;
    while (H.a[0] <= m) {
        if (H.size < 2) {
            cout << -1;
            return 0;
        }
        long long frst = H.a[0];
        H.poll();
        long long scnd = H.a[0];
        H.poll();
        H.add(frst + 2 * scnd);
        cnt++;
    }
    cout << cnt;
}
