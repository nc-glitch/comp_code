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


using namespace std;
template<typename T1, typename T2>
ostream& operator<<(ostream& ostream, const pi<T1, T2>& p) { return (ostream << p.first << ", " << p.second); }


struct person {
    ll a, b, c;
};


void func2(vector<pll>& vec) {

    ll ans = 1e18;
    for (int i = 0; i < vec.size(); i++) {
        ans = min(ans, vec[i].first + vec[i].second);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //    freopen("mountains.in", "r", stdin);
    //    freopen("mountains.out", "w", stdout);
    ll tries = 1;

    cin >> tries;
    while (tries--) {
        ll n, c, m;
        cin >> n >> c >> m;

        vector<person> nums;
        for (int i = 0; i < n; i++) {
            ll a, b, C;
            cin >> a >> b >> C;
            nums.pb({ a,b,C });
        }

        ll bst = 1e18;
        ll x, y;
        for (int i = 1; i <= c; i++) {

            ll lo = 0, hi = m + 1;

            while (lo < hi - 1) {
                ll mid = (lo + hi) / 2;

                bool work = true;
                for (auto it : nums) {
                    ll time = i * it.a + mid * it.b;
                    if (time > it.c) {
                        // waited too long
                        work = false;
                        break;
                    }
                }

                if (work) lo = mid;
                else hi = mid;

            }

            for (int j = 1; j <= m; j++) {
                bool work = true;




            }

            if (lo == 0) continue;

            ll cost = (c - i) + (m - lo);

            bst = min(bst, cost);
            if (bst == cost) {
                x = i, y = lo;
            }

        }

        //        cout << endl;
        cout << bst << endl;

    }
    return 0;
}
/*
3 3
1 0 2 10
2 11 2 0
2 1 3 20
10 1 10
*/