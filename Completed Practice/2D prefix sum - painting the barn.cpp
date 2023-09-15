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

#define MAX 300009
ll n,m;
str s;

class rect{
public:
    int num = 0, x1, x2, y1, y2;

    bool operator<(const rect &a)const{
        if(x1<a.x1) return true;
        if(x1>a.x1) return false;
        if(x2<a.x2) return true;
        if(x2>a.x2) return false;
        if(y1<a.y1) return true;
        if(y1>a.y1) return false;
        if(y2<a.y2) return true;
        return false;
    }
};

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#if 1
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
#endif

    static int arr[1002][1002];
    for(auto &j : arr) for(auto &i : j) i = 0;

    //use prefix sum setting the start as 1 and the end as -1 from row y1 to y2 - 1
    //run prefix
    int n, k; cin >> n >> k;
    for(int t = 0; t < n; t++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int r = y1; r < y2; r++){
            arr[r][x1]++;
            arr[r][x2]--;
        }
    }

    int c = 0;
    for(int j = 1; j < 1002; j++){
        for(int i = 1; i < 1002; i++){
            arr[j][i] += arr[j][i-1];
            if(arr[j][i] == k) c++;
        }
    }

    cout << c << endl;
}
