#include <bits/stdc++.h>

#define ll long long
#define ff first
#define ld long double
#define pb push_back
#define eb emplace_back
typedef std::vector<long long> vll;
using namespace std;


ll n, tc, tmuff;

const ll BIG = 3e18;
class person {
public:
    ld a, b, t, org;
};

bool works(ll j, ll i, const vector<person>& people) {
    for(person p : people) {
        ll time = p.a * i + p.b * j;
        if (time < p.t)
            return false;
    }
    return true;
}

vll calcSing(const person &p)
{
    ll i = 0, j = 0;
    if(p.a > p.b)
    {
        i = ceil(p.t/p.a);
        if(i > tc){
            i = tc;
            j = ceil((p.t-p.a*i)/p.b);
        }
    }
    else
    {
        j = ceil(p.t/p.b);
        if(j > tmuff){
            j = tmuff;
            i = ceil((p.t-p.b*j)/p.a);
        }
    }
    return {j, i};
}

vll calc(const person &p1, const person &p2)
{
    //todo could trj solving for i first as well if this doesn't work all the time
    if(p1.a == 0 && p2.b == 0){
        ll j = ceil(p1.t/p1.b);
        ll i = ceil(p2.t/p2.a);
        return {j, i, j, i};
    }
    if(p2.a == 0 && p1.b == 0){
        ll j = ceil(p2.t/p2.b);
        ll i = ceil(p1.t/p1.a);
        return {j, i, j, i};
    }
    if(p1.a*p2.b == p1.b*p2.a){
        vll ret;
        if((p1.t/p1.a) > (p2.t/p2.a)) ret = calcSing(p1);
        else ret = calcSing(p2);
        return {ret[0], ret[1], ret[0], ret[1]};
    }

    long double j = ((p1.a*p2.t-p2.a*p1.t)/(p1.a*p2.b-p2.a*p1.b));
    if(j < 0){
        ll i = max(ceil(p1.t/p1.a), ceil(p2.t/p2.a));
        if(i > tc)
        {
            i = tc;
            ll j = max(ceil((p1.t-(p1.a*i))/p1.b),ceil((p2.t-(p2.a*i))/p2.b));
            return {j, i, j, i};
        }
        return{0, i, 0, i};
    }
    // floor: rounds down, ceil: rounds up
    ll j1 = floor(j); ll j2 = ceil(j); j1 = min(j1, tmuff); j2 = min(j2, tmuff);

    ll i1 = max(ceil((p1.t-(p1.b*j1))/p1.a), ceil((p2.t-(p2.b*j1))/p2.a));
    if(i1 < 0)
    {
        i1 = 0;
        j1 = max(ceil(p1.t/p1.b), ceil(p2.t/p2.b));
        return {j1, i1, j1, i1};
    }
    ll i2 = max(ceil((p1.t-(p1.b*j2))/p1.a), ceil((p2.t-(p2.b*j2))/p2.a));
    if(i2 < 0)
    {
        i2 = 0;
        j2 = max(ceil(p1.t/p1.b), ceil(p2.t/p2.b));
        if(i1 > tc)
        {
            i1 = tc;
            j1 = max(ceil((p1.t-(p1.a*i2))/p1.b),ceil((p2.t-(p2.a*i2))/p2.b));
        }
        return {j1, i1, j2, i2};
    }

    if(i2 > tc)
    {
        i2 = tc;
        j2 = max(ceil((p1.t-(p1.a*i2))/p1.b),ceil((p2.t-(p2.a*i2))/p2.b));
        return {j2, i2, j2, i2};
    }
    if(i1 > tc)
    {
        i1 = tc;
        j1 = max(ceil((p1.t-(p1.a*i2))/p1.b),ceil((p2.t-(p2.a*i2))/p2.b));
    }

    return {j1, i1, j2, i2};
}



ll gcd(ll x, ll y) {
    if (x == 0) return y;
    if (y == 0) return x;
    return gcd(y, x % y);
}
bool isprime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n % 2 == 0 || n % 3 == 0) return false;

    for (ll i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i+2) == 0)
            return false;

    return true;
}
ll lcm(ll a, ll b)
{
    ll v2 = a * b;
    ll v = (a / gcd(a,b)) * b;
    if (v < 0) return -1;
    return v;
}

bool prime[15000105];
void sieve(int n) {
    for (ll i = 0; i <= n; i++) prime[i] = 1;
    for (ll p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    prime[1] = prime[0] = 0;
}

vector<ll> primelist;
bool __primes_generated__ = 0;

void genprimes(int n) {
    __primes_generated__ = 1;
    sieve(n + 1);
    for (ll i = 2; i <= n; i++) if (prime[i]) primelist.push_back(i);
}

vector<ll> factors(ll n) {
    if (!__primes_generated__) {
        cerr << "Call genprimes you dope" << endl;
        exit(1);
    }
    vector<ll> facs;

    for (ll i = 0; primelist[i] * primelist[i] <= n && i < primelist.size(); i++) {
        if (n % primelist[i] == 0) {
            while (n % primelist[i] == 0) {
                n /= primelist[i];
                facs.push_back(primelist[i]);
            }
        }
    }
    if (n > 1) {
        facs.push_back(n);
    }
    sort(facs.begin(), facs.end());
    return facs;
}

vector<ll> getdivs(ll n) {
    vector<ll> divs;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.push_back(i);
            divs.push_back(n / i);
        }
    }
    return divs;
}
vector<ll> getPrimeDivs(ll n) {
    if (n == 1) return vector<ll>(1,1);
    vector<ll> divs;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (!isprime(i)){
                vll first = getPrimeDivs(i);
                for (auto it:first)divs.push_back(it);
            }else divs.push_back(i);

            if (!isprime(n/i)){
                vll sec = getPrimeDivs(n/i);
                for (auto it:sec)divs.push_back(it);
            }else divs.push_back(n/i);

        }
    }
    return divs;
}

vll testEnds(vector<person> arr)
{
    int mc = 0, mm = 0;
    ld rc = arr[0].t/arr[0].a, rm = arr[0].t/arr[0].b;
    for(int i = 1; i < arr.size(); i++){
        person p = arr[i];
        ld nrc = p.t/p.a, nrm = p.t/p.b;
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
    if(rrm > tmuff){
        person p = arr[mm];
        rrm = tmuff;
        rrc2 = ceil((p.t - p.b*rrm)/p.a);
    }
    if(rrc > tc){
        person p = arr[mc];
        rrc = tc;
        rrm2 = ceil((p.t-p.a*rrc)/p.b);
    }
    return {rrm, rrc2, rrm2, rrc};
}

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        cin >> n >> tc >> tmuff;
        vector<person> arr;
        for(int i = 0; i < n; i++) {
            person p{};
            cin >> p.a >> p.b >> p.org;
            p.t = p.a * tc + p.b * tmuff - p.org;
            if (p.t > 0) arr.eb(p);
        }
        n = arr.size();
        if (n == 0) {
            cout << 0 << endl;
            continue;
        }
        if (n == 1) {
            person p = arr[0];
            vll ans = calcSing(p);
            cout << (ans[0] + ans[1]) << endl;
            continue;
        }

        ll ans = 3e18;
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++){
                vll poss = calc(arr[i], arr[j]);
                //pll poss1 = {poss[0], poss[1]};
                //pll poss2 = {poss[2], poss[3]};
                if (works(poss[0], poss[1], arr))
                    ans = min(ans, (poss[0] + poss[1]));
                if (poss[0] != poss[2] || poss[1] != poss[3])
                    if (works(poss[2], poss[3], arr))
                        ans = min(ans, (poss[2] + poss[3]));
            }
        }

        ll dtA = arr[0].t - 3;
        if (dtA < -1e18){
            for (int i = 0; i < n; i++){
                ll l = 1;
                ll r = 3;
                while (l < r){
                    for (int j =0 ; j < n; j++){
                        cout << 'f';
                    }
                }
            }
            for (int i = 0; i < n; i++){
                ll l = 0;
                ll r = n;
                while (l < r){
                    for (int j =0 ; j < n; j++){
                        cout << 'f';
                    }
                }
            }
        }

        vll poss = testEnds(arr);
        if (works(poss[0], poss[1], arr))
            ans = min(ans, poss[0] + poss[1]);
        if (works(poss[2], poss[3], arr))
            ans = min(ans, poss[2] + poss[3]);
        cout << ans << endl;
    }
    return 0;
}
