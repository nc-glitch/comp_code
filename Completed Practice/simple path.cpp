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

class pt{
public:
    char dir;
    int n = 1;
};

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
    vector<vector<pt>> pts; vector<int> cx;
    for(int i = 0; i < n; i++){
        string input; cin >> input;
        vector<pt> add;
        for(char &d : input){
            pt a; a.dir = d;
            add.eb(a);
        }
        pts.eb(add);

        int c; cin >> c;
        cx.eb(c);
    }

    vi cy;
    for(int i = 0; i < n; i++){
        int ad; cin >> ad;
        cy.eb(ad);
    }

    //loop through all indexes, appropriately adding cows to each square until final square is reached and add the multiple of cost and number
    int tc = 0;
    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++){
            pt &cur = pts[j][i];
            if(cur.dir == 'R'){
                if(i == n - 1) tc += cx[j]*cur.n;
                else pts[j][i+1].n += cur.n;
            }
            else{
                if(j == n - 1) tc += cy[i]*cur.n;
                else pts[j+1][i].n += cur.n;
            }
        }
    }

    vector<int> ans; ans.eb(tc);

    int q; cin >> q;
    for(int idx = 0; idx < q; idx++){
        int x, y; cin >> y >> x; x--; y--;
        pt &curr = pts[y][x];
        int cws = curr.n;

        int i = x, j = y;
        while(i != n && j != n){
            pts[j][i].n -= cws;
            if(pts[j][i].dir == 'R') i++;
            else j++;
        }
        if(i == n) tc -= cws*cx[j];
        else tc -= cws*cy[i];

        if(curr.dir == 'R') curr.dir = 'D';
        else curr.dir = 'R';
        i = x; j = y;
        while(i != n && j != n){
            pts[j][i].n += cws;
            if(pts[j][i].dir == 'R') i++;
            else j++;
        }
        if(i == n) tc += cws*cx[j];
        else tc += cws*cy[i];

        ans.eb(tc);
    }

    for(int &num : ans)
        cout << num << endl;

    return 0;
}


