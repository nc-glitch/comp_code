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


struct state {
    ll x, y, time;
    bool operator<(const state& y) const { return time < y.time; }
};

int main() {

    FR_;
    ll t = 1;
    static_assert(__called_FR_, "");
    // cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vi<state> grazings(n);
        FOR(i, 0, n) {
            state x;
            cin >> x.x;
            cin >> x.y;
            cin >> x.time;
            grazings[i] = x;
        }
        sort(all(grazings));
        ll ans = 0;
        FOR(i, 0, m) {
            state cur;
            cin >> cur.x;
            cin >> cur.y;
            cin >> cur.time;
            auto it = lower_bound(all(grazings), cur);
            if (it == grazings.begin()) {
                state after = *it;
                ll dxA = after.x - cur.x;
                ll dyA = after.y - cur.y;
                ll dtA = after.time - cur.time;
                if (dxA * dxA + dyA * dyA > dtA*dtA) {
                    ++ans;
                    continue;
                }
            }
            else if (it == grazings.end()) {
                state prev = *(it - 1);
                ll dxP = prev.x - cur.x;
                ll dyP = prev.y - cur.y;
                ll dtP = cur.time - prev.time;
                if (dxP * dxP + dyP * dyP > dtP * dtP) {
                    ++ans;
                    continue;
                }
            }
            else {
                state prev = *(it-1);
                state after = *it;
                ll dxP = prev.x - cur.x;
                ll dyP = prev.y - cur.y;
                ll dtP = cur.time - prev.time;
                if (dxP * dxP + dyP * dyP > dtP * dtP) {
                    ++ans;
                    continue;
                }
                ll dxA = after.x - cur.x;
                ll dyA = after.y - cur.y;
                ll dtA = after.time - cur.time;
                if (dxA * dxA + dyA * dyA > dtA * dtA) {
                    ++ans;
                    continue;
                }
            }


        }
        cout << ans << '\n';


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