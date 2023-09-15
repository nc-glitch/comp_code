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


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

   int tries; cin >> tries;
   while(tries--)
    {
        //object creation
        int n;
        cin >> n;
        int k;
        cin >> k;
        string s;
        cin >> s;
        set<int> g, h;
        string ans = "";
        int c = 0;
        if(n == 1)
        {
            cout << 1 << "\n" << s << endl;
            continue;
        }
        if(k == 0)
        {
            cout << s.length() << "\n" << s << endl;
            continue;
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == 'G') g.emplace(i);
            else h.emplace(i);
            ans += '.';
        }

        //reorder erase to be more accurate
        while (g.size() > 0) {
            c++;
            int start = *g.begin();
            if (start + k >= n) break;
            g.erase(g.begin(), g.upper_bound(start + 2*k));
            ans[start + k] = 'G';
        }
        while (h.size() > 0) {
            c++;
            int start = *h.begin();
            if (start + k >= n) break;
            h.erase(h.begin(), h.upper_bound(start + 2*k));
            ans[start + k] = 'H';
        }
        if(g.size() > 0)
        {
            if(h.size() > 0)
            {
                auto gend = g.end(); gend--;
                auto hend = h.end(); hend--;
                if(*gend > *hend)
                {
                    ans[n - 1] = 'G';
                    ans[n - 2] = 'H';
                }
                else
                {
                    ans[n - 1] = 'H';
                    ans[n - 2] = 'G';
                }
            }
            else if (ans[n - 1] == 'H') ans[n - 2] = 'G';
            else ans[n - 1] = 'G';
        }
        else if(h.size() > 0)
        {
            if(ans[n - 1] == 'G') ans[n - 2] = 'H';
            else ans[n - 1] = 'H';
        }

        cout << c << endl;
        cout << ans << endl;
    }

    return 0;
}
