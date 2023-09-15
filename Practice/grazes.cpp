#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

typedef vector<long long> vll;
typedef vector<vector<ll> > vvll;

struct place{
    ll i,j,time;bool operator<(const place& c1)const{
        return time < c1.time;
    }

};


ll dist(ll y1, ll x1, ll y2, ll x2) {

    ll dx = x1 - x2; dx = dx * dx;
    ll dy = y1 - y2; dy = dy * dy;
    return dx + dy;
}

//ll dist(ll y1, ll x1, ll y2, ll x2) { return abs(y2 - y1) + abs(x2 - x1); }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll g, n;
    cin >> g >> n;
    set<place> grazes;

    for(int i = 0; i < g; i++)
    {
        place add;
        cin >> add.j >> add.i >> add.time;
        grazes.emplace(add);
    }
    vector<place> cws;
    for(int i = 0; i < n; i++)
    {
        place add;
        cin >> add.j >> add.i >> add.time;
        cws.emplace_back(add);
    }

    ll c = 0;
    for(place cw : cws)
    {
        auto ptrnxt = grazes.lower_bound(cw);
        place nxt = *ptrnxt;

        ll dt = nxt.time - cw.time; dt = dt * dt;
        if(ptrnxt != grazes.end() && dist(nxt.i, nxt.j, cw.i, cw.j) > dt){
            c++; continue;
        }

        if(ptrnxt != grazes.begin()) {
            place prv = *prev(ptrnxt);
            dt = cw.time - prv.time; dt = dt * dt;
            if (dist(prv.i, prv.j, cw.i, cw.j) > dt)
                c++;
        }
    }

    cout << c << endl;

    return 0;
}
#if 0

2 4
0 0 100
50 0 200
0 50 50
1000 1000 0
50 0 200
10 0 170

#endif
#if 0
remove all people on time
    count all cookies and muffins
    continually decrement the greater of the two by one until someone is content
        sorting by shortest waiting time
        removing just enough to make them ok
        go to next person
    remove content person
    recalculate
    continue until no one is left
#endif
