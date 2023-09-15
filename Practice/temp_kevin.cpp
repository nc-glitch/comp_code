#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <set>
#include <limits>
#include <climits>
#include <queue>
#include <deque>
#include <functional>
#include <map>
#include <cmath>
#include <bitset>
#include <string>
#include <fstream>
#include <array>
#include <assert.h>
#include <vector>
#include <iostream>
#include <random>
#include <chrono>




#define ll long long
#define FOR(a, c, b) for (ll a = c; a < b; a++)
#define RFOR(a, c, b) for (ll a = c; a >= b; a--)
#ifndef ONLINE_JUDGE
#define dbg(x) cerr << "DBG: " << #x << " = "; cout << x << '\n';
#else
#define dbg(x)
#endif

#define pll pair<ll, ll>
#define pi pair
#define vi vector
#define ff first
#define ld long double
#define ss second
#define all(x) x.begin(), x.end()
#define pb push_back
#define m_p make_pair
#define FR_ ios_base::sync_with_stdio(false);cin.tie(NULL);const static bool __called_FR_=true
typedef std::vector<long long> vll;


using namespace std;
template<typename T1, typename T2>
ostream& operator<<(ostream& ostream, const pi<T1, T2>& p) { return (ostream << p.first << ", " << p.second); }

template <typename T>
void _pp(vi<T> arr, bool spacesBetween = 1, bool end = 1) {
    FOR(i, 0, arr.size()) {
        cout << arr[i];
        if (spacesBetween) cout << " ";
    }

    if (end) cout << '\n';
}

template <typename T>
void _pp(vi<vi<T>> arr) {
    FOR(i, 0, arr.size()) {
        FOR(j, 0, arr[i].size()) {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}


template <typename T>
void _pp(vi<vi<T>> arr, const bool spacesBetween) {
    FOR(i, 0, arr.size()) {
        FOR(j, 0, arr[i].size()) {
            cout << arr[i][j];
            if (spacesBetween) cout << " ";
        }
        cout << '\n';
    }
    //cout << '\n';
}




template <typename T>
void inp(vi<T>& arr) {
    for (auto& el : arr) cin >> el;
}
template <typename T>
void inp(vi<T>& arr, ll n) {
    FOR(i, 0, n) cin >> arr[i];
}



struct Rect {
    ll x1, y1, x2, y2;

    ll getH() {
        return (y2 - y1);
    }
    ll getW() {
        return (x2 - x1);
    }
    ll area() {
        return (y2 - y1) * (x2 - x1);
    }

};

// determine 1d intersection by max(min(rightmost) - max(leftmost), 0)

ll intersect_area(Rect p, Rect q) {
    ll xOverlap = max(0ll, min(p.x2, q.x2) - max(p.x1, q.x1));
    ll yOverlap = max(0ll, min(p.y2, q.y2) - max(p.y1, q.y1));
    return xOverlap * yOverlap;
}


bool does_intersect(Rect s1, Rect s2) {
    int bl_a_x = s1.x1, bl_a_y = s1.y1, tr_a_x = s1.x2, tr_a_y = s1.y2;
    int bl_b_x = s2.x1, bl_b_y = s2.y1, tr_b_x = s2.x2, tr_b_y = s2.y2;

    // no overlap
    if (bl_a_x >= tr_b_x || tr_a_x <= bl_b_x
        || bl_a_y >= tr_b_y || tr_a_y <= bl_b_y) {
        return false;
    }
    else {
        return true;
    }
}


void open(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);

}

/*
[0, inf]
not found will output value < lo
*/
ll b_search_max(ll lo, ll hi, function<bool(ll)> f) {
    lo--;
    while (lo < hi) {
        ll mid = lo + (hi - lo + 1ll) / 2ll;
        if (f(mid)) {
            lo = mid;
        }
        else {
            hi = mid - 1ll;
        }

    }
    return lo;
}

/*
[0, inf]
not found will output value > hi
*/
ll b_search_min(ll lo, ll hi, function<bool(ll)> f) {
    hi++;
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (f(mid)) {
            hi = mid;
        }
        else {
            lo = mid + 1;
        }
    }
    return lo;
}


// Function to calculate gcd of two numbers
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}


// Function to return LCM of two numbers
ll lcm(ll a, ll b)
{
    ll v2 = a * b;
    ll v = (a / gcd(a, b)) * b;
    if (v < 0) return -1;
    return v;
}



vector<ll> getDivisors(ll n, bool skip_one_and_itself)
{

    vector<ll> ans;

    // Note that this loop runs till square root
    for (ll i = 1; i <= sqrt(n); i++)
    {
        if (i == 1 && skip_one_and_itself) continue;
        if (n % i == 0)
        {
            // If divisors are equal, print only one
            if (n / i == i)
                ans.push_back(i);

            else // Otherwise print both
            {
                ans.push_back(i);
                ans.push_back(n / i);
            }

        }
    }
    return ans;
}

/* Returns 1 if y is a power of x */
bool isPower(ll x, ll y)
{
    // The only power of 1 is 1 itself
    if (x == 1)
        return (y == 1);

    // Repeatedly comput power of x
    ll pow = 1;
    while (pow < y)
        pow *= x;

    // Check if power of x becomes y
    return (pow == y);
}
// right -> left
bool isBitSet(ll num, int bit)
{
    return ((num >> bit) & 1ll);
}

void setBit(ll& n, int k)
{
    n = (n | (1ll << k));
}


void clearBit(ll& n, int k)
{
    n = (n & (~(1ll << k)));
}

void toggleBit(ll& n, int k)
{
    n = (n ^ (1ll << k));
}


ll fastExp(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;

    if (base == 0) return 0ll;

    while (exp > 0) {

        if (exp & 1)
            res = (res * base) % mod;

        exp = exp >> 1;

        base = (base * base) % mod;
    }
    return res % mod;
}

vi<ll> genSequential(ll min, ll max, ll inc = 1) {
    vi<ll> arr(max - min + 1);
    ll idx = 0;
    for (ll i = min; i <= max; i += inc) {
        arr[idx++] = i;
    }
    return arr;
}


vi<ll> primesTo(int n)
{
    bitset<16384> Primes;
    Primes[0] = 1;
    for (int i = 3; i * i <= n; i += 2) {
        if (Primes[i / 2] == 0) {
            for (int j = 3 * i; j <= n; j += 2 * i)
                Primes[j / 2] = 1;
        }

    }
    vi<ll> ans;
    for (int i = 1; i <= n; i++) {
        if (i == 2)
            ans.pb(i);
        else if (i % 2 == 1 && Primes[i / 2] == 0)
            ans.pb(i);
    }
    return ans;
}

struct segObj {
    ll val;
    static const ll nullv = LLONG_MIN;

    segObj() : val(0ll) {}
    segObj(const ll& v) : val(v) {}
    operator ll() const { return val; }
    segObj op(const segObj& other) {
        if (val == nullv) {
            return other.val;
        }
        if (other.val == nullv) {
            return val;
        }

        return gcd(val, other.val);
    }

    segObj lazy_op(const segObj& v, const size_t size) {
        return val + v.val;
    }
};

template <typename num_t>
struct SegTree {


    void build(const vi<ll>& arr) {
        n = static_cast<int>(arr.size());
        tree = vector<num_t>(4 * n, 0);
        lazy = vector<num_t>(4 * n, 0);
        init(0, 0, n - 1, arr);
    }


    void update(int l, int r, num_t v) {
        if (l > r) return;
        update(0, 0, n - 1, l, r, v);
    }

    num_t query(int l, int r) {
        if (l > r) return num_t::nullv;

        return query(0, 0, n - 1, l, r);
    }

private:
    int n;
    vector<num_t> tree, lazy;

    num_t init(int i, int l, int r, const vi<ll>& arr) {
        if (l == r) return tree[i] = arr[l];

        int mid = (l + r) / 2;
        num_t a = init(2 * i + 1, l, mid, arr),
                b = init(2 * i + 2, mid + 1, r, arr);
        return tree[i] = a.op(b);
    }


    num_t update(int i, int tl, int tr, int ql, int qr, num_t v) {
        eval_lazy(i, tl, tr);

        if (tr < ql || qr < tl) return tree[i];
        if (ql <= tl && tr <= qr) {
            lazy[i] = lazy[i].val + v.val;
            eval_lazy(i, tl, tr);
            return tree[i];
        }

        int mid = (tl + tr) / 2;
        num_t a = update(2 * i + 1, tl, mid, ql, qr, v),
                b = update(2 * i + 2, mid + 1, tr, ql, qr, v);
        return tree[i] = a.op(b);
    }



    num_t query(int i, int tl, int tr, int ql, int qr) {
        eval_lazy(i, tl, tr);

        if (ql <= tl && tr <= qr) return tree[i];
        if (tr < ql || qr < tl) return num_t::nullv;

        int mid = (tl + tr) / 2;
        num_t a = query(2 * i + 1, tl, mid, ql, qr),
                b = query(2 * i + 2, mid + 1, tr, ql, qr);
        return a.op(b);
    }

    void eval_lazy(int i, int l, int r) {
        tree[i] = tree[i].lazy_op(lazy[i], (r - l + 1));
        if (l != r) {
            lazy[i * 2 + 1] = lazy[i].val + lazy[i * 2 + 1].val;
            lazy[i * 2 + 2] = lazy[i].val + lazy[i * 2 + 2].val;
        }

        lazy[i] = num_t();
    }
};

string to_binary(ll num) {
    return std::bitset<8>(num).to_string();
}
