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

string ans = "";
vi xs;

void uplevel(int idx, int base)
{
    int end = idx;
    int mn = xs[idx];

    //finding min and endpoint
    while(end >= 0 && xs[end] > base){
        mn = min(mn, xs[end]);
        end--;
    }

    //recursion if greater than min
    for(int i = idx; i > end; i--){
        if(xs[i] > mn) uplevel(i, mn);
        ans += "L";
    }

    //adding "R"s to the answer string and subtracting the counts through the array
    int sub = mn - base;
    for(int i = end + 1; i <= idx; i++){
        ans += "R";
        xs[i] -= sub;
    }

    //going back and forth as appropriate
    for(int i = 1; i < sub/2; i++){
        for(int i = end + 1; i <= idx; i++)
            ans += "L";
        for(int i = end + 1; i <= idx; i++)
            ans += "R";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#if 0
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
#endif

    int n; cin >> n;
    for(int i = 0; i < n; i++) { int add; cin >> add; xs.eb(add); }

    //algo:
    //traverse all the way to the right
    //start going left
    //recursively call everytime value increases and return the next starting position everytime it decreases
    for(int i = 0; i < n; i++) ans += "R";

    //THERE IS SOME LOGIC ERROR
    int idx = n-1;
    while(idx >= 0) {
        if(xs[idx] > 2) uplevel(idx, 2);
        idx--;
        ans += "L";
    }

    cout << ans << endl;

    return 0;
}


