#include <bits/stdc++.h>
using namespace std;

//__builtin_popcount(n) amount of "1" bits
// log2(num & -num); rightmost bit, first bit pos
// log2(num & num); leftmost bit
//  num/ (-num & num) num without trailing zeroes 10000 = 1 not 16
//
// mask|(1<<i); modify number mask ith bit
//
//for (int i = 0; i < pow(2,n); i++){
//    for (int j = 0; j < n; j++){
//        if ((i >> j) & 1){
//            cout << 'f';
//        }else{
//            cout << 'f';
//        }
//    }
//}

//        scanf("%lld",&n);
#define ll long long
#define ld long double
//#define mod 1000000007
#define mod 998244353
#define ull unsigned long long
#define fbo(a) find_by_order(a) //will give a-th largest element
#define ook(a) order_of_key(a) //will give no. of elements strictly lesser than a
#define setbits(x)      __builtin_popcountll(x)
#define str string
#define fo(i,a,n) for(ll i=a;i<n;i++)
#define eb emplace_back
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define ff first
#define ss second
#define pb push_back
#define sp(x,y)         fixed<<setprecision(y)<<x
#define nl '\n'
#define inf (1LL<<62)
#define si(x)    scanf("%d",&x)
#define sl(x)    scanf("%lld",&x)
#define sss(s)    scanf("%s",s)
#define pi(x) printf("%d\n",x)
#define pl(x)    printf("%lld\n",x)
#define ps(s)    printf("%s\n",s)
#define FOR(a, c, b) for (int a = c; a < b; a++)
#define MIN3(a, b, c) std::min(std::min(a, c))

typedef map<ll, ll> mll;
typedef vector<long long> vll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<vector<ll> > vvll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<string> vs;

class edge{
public:
    ll ind, val;
//    str s;
    bool operator<(const edge& c1)const{
        return val < c1.val;
    }
    //    bool operator==(const cow&c1)const{
    //        if (c == c1.c) return true;
    //        return false;
    //    }
    //    bool operator!=(const cow&c1)const{
    //        if (c == c1.c) return false;
    //        return true;
    //
};

#define MAX 300009
ll n,m;
str s;

class field{
public:
    vi edges;
    bool unchecked;
};


void bfs(int begin, vector<field> &past)
{
    queue<int> qu;
    qu.emplace(begin);
    past[begin].unchecked = false;

    while(!qu.empty())
    {
        vi &edges = past[qu.front()].edges;
        qu.pop();

        while(!edges.empty()){
            past[*edges.begin()].unchecked = false;
            qu.emplace(edges[0]);
            edges.erase(edges.begin());
        }
    }
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#if 1
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
#endif

    //n = # of pastures, m = # of connections
    int n, m; cin >> n >> m;
    vector<field> past; field add; add.unchecked = true;
    for(int i = 0; i <= n; i++) past.emplace_back(add);

    for(int t = 0; t < m; t++){
        char s; int p1, p2;
        cin >> s >> p1 >> p2;
        past[p1].edges.eb(p2);
        past[p2].edges.eb(p1);
    }

    //output is in binary :
    //answer = 2 ^ (number of connected trees)
    //output: 1 followed by the number of connected trees 0's
    int c = 0;
    for(int idx = 1; idx <= n; idx++){
        if(past[idx].unchecked){
            c++;
            bfs(idx, past);
        }
    }

    cout << 1;
    for(int cnt = 0; cnt < c; cnt++) cout << 0;
    cout << endl;
}
