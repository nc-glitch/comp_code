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

void add(vvi& arr, int y, int x, vector<pair<int, int>>& qu)
{
    pair<int, int> p1 = {y-1,x}, p2 = {y+1, x}, p3 = {y, x-1}, p4 = {y, x+1};
    if(arr[p1.first][p1.second] == 0){
        qu.eb(p1);
        arr[p1.first][p1.second] = 1;
    }
    if(arr[p2.first][p2.second] == 0){
        qu.eb(p2);
        arr[p2.first][p2.second] = 2;
    }
    if(arr[p3.first][p3.second] == 0){
        qu.eb(p3);
        arr[p3.first][p3.second] = 3;
    }
    if(arr[p4.first][p4.second] == 0){
        qu.eb(p4);
        arr[p4.first][p4.second] = 4;
    }
}

//create a queue of nodes to check, repeatedly removing the first node, but still adding all of the first's new connected nodes
bool bfs(vvi& arr, int y, int x, int by, int bx)
{
    vector<pair<int, int>> qu;
    add(arr, y, x, qu);
    while(!qu.empty())
    {
        pair<int, int> curr = qu[0];
        if(curr.first == by && curr.second == bx) return true;
        add(arr, curr.first, curr.second, qu);
        qu.erase(qu.begin());
    }
    return false;
}

string goingBack(vvi& arr, int y, int x)
{
    int dir = arr[y][x];
    if(dir == 1) return goingBack(arr, y+1, x) + "U";
    else if(dir == 2) return goingBack(arr, y-1, x) + "D";
    else if(dir == 3) return goingBack(arr, y, x + 1) + "L";
    else if(dir == 4) return goingBack(arr, y, x - 1) + "R";
    else return "";
}

int main() {
    ios_base::sync_with_stdio(0);

    cin.tie(0);
    cout.tie(0);

#if 0
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
#endif

    //given map of building, count the rooms
    int n, m; // height, width
    cin >> n >> m;

    vvi arr;
    for(int i = 0; i < 1002; i++)
    {
        vi add;
        for(int j = 0; j < 1002; j++) add.eb(-1);
        arr.eb(add);
    }
    int ax, ay, bx, by;
    for(int i = 1; i <= n; i++)
    {
        string s; cin >> s;
        for(int j = 1; j <= m; j++) {
            if (s[j - 1] == '.') arr[i][j] = 0;
            else if(s[j-1] == 'A'){
                ax = j; ay = i;
            }
            else if(s[j-1] == 'B'){
                arr[i][j] = 0;
                bx = j; by = i;
            }
        }
    }

    bool pos = bfs(arr, ay, ax, by, bx);

//    for(int i = 1; i <= n; i++)
//    {
//        for(int j = 1; j <= m; j++)
//        {
//            int v = arr[i][j];
//            if(v < 0) cout << v << " ";
//            else cout << " " << v << " ";
//        }
//        cout << endl;
//    }

    if(pos)
    {
        string ans = goingBack(arr, by, bx);
        cout << "YES" << endl;
        cout << ans.length() << endl;
        cout << ans << endl;
    }
    else cout << "NO" << endl;

    return 0;
}