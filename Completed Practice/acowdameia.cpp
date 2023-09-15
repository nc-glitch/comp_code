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

struct edge{
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


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#if 0
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);
#endif

    //n papers, l citations
    //h: largest number where researcher has h papers with h citations
    //nlog(n)
    int n, l;
    cin >> n >> l;
    vi pps;
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        pps.emplace_back(a);
    }
    sort(pps.begin(), pps.end());

    int count = 0, tries = l;
    while(pps[n - count - 1] >= count + 1 && count < n) count++;
    int t = 0;
    while(t < count && pps[n - count + t] == count){
        l--; t++;
    }
    while(pps[n - count - 1] >= count && count < n && l > 0){
        count++; l--;
    }

    cout << count;

    return 0;
}