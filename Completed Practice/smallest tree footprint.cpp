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

class cow{
public:
    int x, y;
    vi edges;
    bool visited = false;
};


//OPTIMIZATIONS (didn't need in the end)
//Stop if range is already too big
// rerunning problem though (still not too bad though)

//dfs is slightly faster

void dfs(int begin, int &mn, vector<cow> &arr){
    stack<int> stk;
    stk.emplace(begin);

    cow &start = arr[begin];
    start.visited = true;
    int mnx = start.x, mxx = start.x, mny = start.y, mxy = start.y;

    while(!stk.empty()){
        cow &curr = arr[stk.top()]; stk.pop();
        mnx = min(mnx, curr.x); mxx = max(mxx, curr.x);
        mny = min(mny, curr.y); mxy = max(mxy, curr.y);

        vi &edges = curr.edges;
        for(int i : edges) {
            if (!arr[i].visited) {
                arr[i].visited = true;
                stk.push(i);
            }
        }
    }

    mn = min(mn, 2*(mxy + mxx - mnx - mny));
}

int main()
{
    //Silver, 2019, Fence Planning
    //VERY OPTIMIZATION DEPENDENT (even small mistakes massively slow it down)

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#if 1
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
#endif

    int n, m; cin >> n >> m;

    vector<cow> arr; arr.eb();
    for(int t = 0; t < n; t++){
        cow add;
        cin >> add.x >> add.y;
        arr.eb(add);
    }
    //construct networks of cows as edges are read in with max and mins
    for(int t = 0; t < m; t++){
        int c1, c2;
        cin >> c1 >> c2;
        arr[c1].edges.eb(c2);
        arr[c2].edges.eb(c1);
    }



    //check each network setting the perimeter to be the minimum
    int mn = 1e9; int c = 1;
    for(int i = 1; i <= n; i++)
        if(!arr[i].visited) dfs(i, mn, arr);

    cout << mn << endl;

    return 0;
}

