#include <bits/stdc++.h>

#define ll long long
#define FOR(a, c, b) for (ll a = c; a < b; a++)
#define RFOR(a, c, b) for (ll a = c; a >= b; a--)
#ifndef ONLINE_JUDGE
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
#define eb emplace_back
#define m_p make_pair
//#define FR_ ios_base::sync_with_stdio(false);cin.tie(NULL);const static bool __called_FR_=true
typedef std::vector<long long> vll;
using namespace std;


ll n, tc_, tm_;

const ll BIG = 3e18;
class person {
public:
    ld a, b, c;
};

bool check(ll y, ll x, const vector<person>& people) {
    for(person p : people) {
        ll time = p.a * x + p.b * y;
        if (time < p.c)
            return false;
    }
    return true;
}

vll SolveSing(const person &p)
{
    ll x = 0, y = 0;
    if(p.a > p.b)
    {
        x = ceil(p.c/p.a);
        if(x >= tc_){
            x = tc_ - 1;
            y = ceil((p.c-p.a*x)/p.b);
        }
    }
    else
    {
        y = ceil(p.c/p.b);
        if(y >= tm_){
            y = tm_ - 1;
            x = ceil((p.c-p.b*y)/p.a);
        }
    }
    return {y, x};
}

vll Solve(const person &p1, const person &p2)
{
    //todo could try solving for x first as well if this doesn't work all the time
    if(p1.a == 0 && p2.b == 0){
        ll y = ceil(p1.c/p1.b);
        ll x = ceil(p2.c/p2.a);
        return {y, x, y, x};
    }
    if(p2.a == 0 && p1.b == 0){
        ll y = ceil(p2.c/p2.b);
        ll x = ceil(p1.c/p1.a);
        return {y, x, y, x};
    }
    if(p1.a*p2.b == p1.b*p2.a){
        vll ret;
        if((p1.c/p1.a) > (p2.c/p2.a)) ret = SolveSing(p1);
        else ret = SolveSing(p2);
        return {ret[0], ret[1], ret[0], ret[1]};
    }

    long double y = ((p1.a*p2.c-p2.a*p1.c)/(p1.a*p2.b-p2.a*p1.b));
    if(y < 0){
        ll x = max(ceil(p1.c/p1.a), ceil(p2.c/p2.a));
        if(x >= tc_)
        {
            x = tc_ - 1;
            ll Y = max(ceil((p1.c-(p1.a*x))/p1.b),ceil((p2.c-(p2.a*x))/p2.b));
            return {Y, x, Y, x};
        }
        return{0, x, 0, x};
    }
    // floor: rounds down, ceil: rounds up
    ll y1 = floor(y); ll y2 = ceil(y); y1 = min(y1, tm_ - 1); y2 = min(y2, tm_ - 1);

    ll x1 = max(ceil((p1.c-(p1.b*y1))/p1.a), ceil((p2.c-(p2.b*y1))/p2.a));
    if(x1 < 0)
    {
        x1 = 0;
        y1 = max(ceil(p1.c/p1.b), ceil(p2.c/p2.b));
        return {y1, x1, y1, x1};
    }
    ll x2 = max(ceil((p1.c-(p1.b*y2))/p1.a), ceil((p2.c-(p2.b*y2))/p2.a));
    if(x2 < 0)
    {
        x2 = 0;
        y2 = max(ceil(p1.c/p1.b), ceil(p2.c/p2.b));
        if(x1 >= tc_)
        {
            x1 = tc_ - 1;
            y1 = max(ceil((p1.c-(p1.a*x2))/p1.b),ceil((p2.c-(p2.a*x2))/p2.b));
        }
        return {y1, x1, y2, x2};
    }

    if(x2 >= tc_)
    {
        x2 = tc_ - 1;
        y2 = max(ceil((p1.c-(p1.a*x2))/p1.b),ceil((p2.c-(p2.a*x2))/p2.b));
        return {y2, x2, y2, x2};
    }
    if(x1 >= tc_)
    {
        x1 = tc_ - 1;
        y1 = max(ceil((p1.c-(p1.a*x2))/p1.b),ceil((p2.c-(p2.a*x2))/p2.b));
    }

    return {y1, x1, y2, x2};
}

vll testEnds(vector<person> arr)
{
    int mc = 0, mm = 0;
    ld rc = arr[0].c/arr[0].a, rm = arr[0].c/arr[0].b;
    for(int i = 1; i < arr.size(); i++){
        person p = arr[i];
        ld nrc = p.c/p.a, nrm = p.c/p.b;
        if(nrc > rc) {
            rc = nrc;
            mc = i;
        }
        if(nrm > rm) {
            rm = nrm;
            mm = i;
        }
    }
    ll rrc = ceil(rc), rrm = ceil(rm);
    ll rrc2 = 0; ll rrm2 = 0;
    if(rrm >= tm_){
        person p = arr[mm];
        rrm = tm_ - 1;
        rrc2 = ceil((p.c - p.b*rrm)/p.a);
    }
    if(rrc >= tc_){
        person p = arr[mc];
        rrc = tc_ - 1;
        rrm2 = ceil((p.c-p.a*rrc)/p.b);
    }
    return {rrm, rrc2, rrm2, rrc};
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while(t--){
        cin >> n >> tc_ >> tm_;
        vi<person> arr;
        FOR(i, 0, n) {
            person p{};
            cin >> p.a >> p.b >> p.c;
            p.c = p.a * tc_ + p.b * tm_ - p.c;
            if(p.c > 0) arr.eb(p);
        }
        n = arr.size();
        if(n == 0) {
            cout << 0 << endl;
            continue;
        }
        if(n == 1){
            person p = arr[0];
            vll ans = SolveSing(p);
            cout << (ans[0] + ans[1]) << endl;
            continue;
        }

        ll ans = BIG;
        FOR(i, 0, n-1) {
            FOR(j, i + 1, n) {
                vll poss = Solve(arr[i], arr[j]);
                //pll poss1 = {poss[0], poss[1]};
                //pll poss2 = {poss[2], poss[3]};
                if (check(poss[0], poss[1], arr))
                    ans = min(ans, (poss[0] + poss[1]));
                if (poss[0] != poss[2] || poss[1] != poss[3]) if (check(poss[2], poss[3], arr))
                    ans = min(ans, (poss[2] + poss[3]));
            }
        }
        vll poss = testEnds(arr);
        if (check(poss[0], poss[1], arr))
            ans = min(ans, poss[0] + poss[1]);
        if (check(poss[2], poss[3], arr))
            ans = min(ans, poss[2] + poss[3]);
        if(ans == BIG) cout << 0 << endl;
        else cout << ans << endl;
    }
    return 0;
}
#if 0
2

3 7 9
4 3 18
2 4 19
1 1 6

5 7 3
5 9 45
5 2 31
6 4 28
4 1 8
5 2 22

j = 3 check
-->
11
6
#endif