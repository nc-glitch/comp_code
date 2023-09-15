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

int N;
double x;
struct Point { LL x, y; int segindex; };
struct Segment { Point p, q; int index; };

bool operator< (Point p1, Point p2) { return p1.x==p2.x ? p1.y<p2.y : p1.x<p2.x; }

// Intersection testing (here, using a standard "cross product" trick)
int sign(LL x) { if (x==0) return 0; else return x<0 ? -1 : +1; }
int operator* (Point p1, Point p2) { return sign(p1.x * p2.y - p1.y * p2.x); }
Point operator- (Point p1, Point p2) { Point p = {p1.x-p2.x, p1.y-p2.y}; return p; }

bool isect(Segment &s1, Segment &s2)
{
    Point &p1 = s1.p, &q1 = s1.q, &p2 = s2.p, &q2 = s2.q;
    return ((q2-p1)*(q1-p1)) * ((q1-p1)*(p2-p1)) >= 0 && ((q1-p2)*(q2-p2)) * ((q2-p2)*(p1-p2)) >= 0;
}

// What is the y coordinate of segment s when evaluated at x?
double eval(Segment s) {
    if (s.p.x == s.q.x) return s.p.y;
    return s.p.y + (s.q.y-s.p.y) * (x-s.p.x) / (s.q.x-s.p.x);
}
bool operator< (Segment s1, Segment s2) { return s1.index != s2.index && eval(s1)<eval(s2); }
bool operator== (Segment s1, Segment s2) { return s1.index == s2.index; }

int main(void)
{
    ifstream fin ("cowjump.in");
    vector<Segment> S;
    vector<Point> P;

    fin >> N;
    for (int i=0; i<N; i++) {
        Segment s;
        fin >> s.p.x >> s.p.y >> s.q.x >> s.q.y;
        s.index = s.p.segindex = s.q.segindex = i;
        S.push_back(s);
        P.push_back(s.p); P.push_back(s.q);
    }
    sort (P.begin(), P.end());

    set<Segment> active;
    int ans1, ans2; // sweep across scene to locate just one intersecting pair...
    for (int i=0; i<N*2; i++) {
        ans1 = P[i].segindex; x = P[i].x;
        auto it = active.find(S[ans1]);
        if (it != active.end()) {
            // segment already there -- we've reached its final endpoint.  check intersection with the
            // pair of segments that becomes adjacent when this one is deleted.
            auto after = it, before = it; after++;
            if (before != active.begin() && after != active.end()) {
                before--;
                if (isect(S[before->index], S[after->index]))
                { ans1 = before->index; ans2 = after->index; break; }
            }
            active.erase(it);
        }
        else {
            // new segment to add to active set.
            // check for intersections with only the segments directly above and below (if any)
            auto it = active.lower_bound(S[ans1]);
            if (it != active.end() && isect(S[it->index], S[ans1])) { ans2 = it->index; break; }
            if (it != active.begin()) { it--; if (isect(S[it->index], S[ans1])) { ans2 = it->index; break; } }
            active.insert(S[ans1]);
        }
    }

    if (ans1 > ans2) swap (ans1, ans2);
    int ans2_count = 0;
    for (int i=0; i<N; i++)
        if (S[i].index != ans2 && isect(S[i], S[ans2])) ans2_count++;

    ofstream fout ("cowjump.out");
    fout << (ans2_count > 1 ? ans2+1 : ans1+1) << "\n";
    return 0;
}

