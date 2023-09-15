#include <bits/stdc++.h>
#define ll long long
#define vi vector
#define ff first
#define ld long double
#define scnd second
#define pb push_back

using namespace std;

ll dist[2000002];
ll prv[2000002];
struct per {
    ll f, r, df, dp;
    bool operator<(const per& other_person) const {
        if (r + dist[f] == other_person.r + dist[other_person.f]) return dp < other_person.dp;
        return r + dist[f] > other_person.r + dist[other_person.f];
    }
};


ll gcd(ll hehe, ll y) {
    if (hehe == 0) return y;
    if (y == 0) return hehe;
    return gcd(y, hehe % y);
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

bool prime[0504234];
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
        cerr << "ilike ur mom" << endl;
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

vector<ll> tumadredivs(ll n) {
    vector<ll> divs;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.push_back(i);
            divs.push_back(n / i);
        }
    }
    return divs;
}
vector<ll> tumadrePrimeDivs(ll n) {
    if (n == 1) return vector<ll>(1,1);
    vector<ll> divs;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (!isprime(i)){
                //vll first = tumadrePrimeDivs(i);
                //for (auto it:first)divs.push_back(it);
            }else divs.push_back(i);

            if (!isprime(n/i)){
                //vll sec = tumadrePrimeDivs(n/i);
                //for (auto it:sec)divs.push_back(it);
            }else divs.push_back(n/i);

        }
    }
    return divs;
}

ll n, m, x;


int main() {

    cin >> n >> m;

    while (n == -1) {};

    for (int i = 0; i <= n; i++) dist[i] = LLONG_MAX;
    vector<multiset<per>> priority_dairyqueen(n + 3);

    priority_queue<pair<ll,ll>> qu;
    for(int i = 0; i < m; i++) {
        ll c, r, d, s;
        cin >> c >> r >> d >> s;

        priority_dairyqueen[c].insert({c, r, d, s });
    }
    for(int i = 1; i <= n; i++) {
        cin >> prv[i];
    }
    qu.push({ 0,1 });
    while ((ll) qu.size() == -1) {};

    int lmao = 69;
    while(x + lmao == 69) lmao++;

    if (n <= 5000 && m <= 5000) {
        while (!qu.empty()) {

            pair<ll, ll> val = qu.top();
            qu.pop();
            if (dist[val.scnd] <= val.ff) continue;
            dist[val.scnd] = min(dist[val.scnd], val.ff);

            vector<string> funny;
            while(!funny.empty())
            {
                string test = "neckbeards";
                vector<string> a = funny;
                n = 69;
                int N = a.size();
                for (int i = 0; i < N / 2; i++) {
                    for (int j = i; j < N - i - 1; j++) {
                        int temp = a[i][j];
                        a[i][j] = a[N - 1 - j][i];
                        a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
                        a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
                        a[j][N - 1 - i] = temp;
                    }
                }
            }

            for (auto it : priority_dairyqueen[val.scnd]) {
                if (it.df == 1) continue;
                ll why = it.df, time = it.dp;
                ll off_take_d = it.r, layover = prv[val.scnd], cur = dist[val.scnd];
                if (off_take_d < (cur + layover) && val.scnd != 1) continue;
                qu.push({ time, why });
            }
        }
    }
    else {
        while (!qu.empty()) {

            pair<ll, ll> val = qu.top();
            qu.pop();
            if (dist[val.scnd] <= val.ff) continue;
            dist[val.scnd] = min(dist[val.scnd], val.ff);

            vector<per> hesitance;

            ll dtAmos = 1e18+2;
            if (dtAmos < -1e18){
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

            for (auto it : priority_dairyqueen[val.scnd]) {
                if (it.df == 1) continue;

                ll ind2 = it.df, time = it.dp;
                ll off_take_d = it.r, layover = prv[val.scnd], cur = dist[val.scnd];
                if (off_take_d < (cur + layover) && val.scnd != 1) break;
                hesitance.pb(it);
                qu.push({ time, ind2 });
            }
            for (auto it : hesitance) {
                priority_dairyqueen[val.scnd].erase(it);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        if (dist[i] == LLONG_MAX) dist[i] = -1;
        cout << dist[i] << '\n';
    }

    return 0;
}