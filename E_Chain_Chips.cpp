/**
 *       Author :   Mehedi Hasan 
 *       Created:   Fri 07.Apr.2023 19:32:56
 *       File   :   E_Chain_Chips.cpp
**/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ar array
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define eb emplace_back

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using order_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define vt vector
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define summ(a) (accumulate(all(a), 0LL))
#define PI 2 * acos(0)
#define torad(x) (x) * ((2 * acos(0)) / 180.0)
#define eps 1e-15
#define pii pair<int, int>
#define pll pair<ll, ll>
#define PQ priority_queue
#define ff first
#define ss second
#define inf 0x3f3f3f3f

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)

template<class T> bool umin(T& a, const T& b) {
    return b<a?a=b, 1:0;
}
template<class T> bool umax(T& a, const T& b) { 
    return a<b?a=b, 1:0;
} 

ll FIRSTTRUE(function<bool(ll)> f, ll lb, ll rb) {
    while(lb<rb) {
        ll mb=(lb+rb)>>1;
        f(mb)?rb=mb:lb=mb+1; 
    } 
    return lb;
}
ll LASTTRUE(function<bool(ll)> f, ll lb, ll rb) {
    while(lb<rb) {
        ll mb=(lb+rb+1)>>1;
        f(mb)?lb=mb:rb=mb-1; 
    } 
    return lb;
}

template<class A> void read(vt<A>& v);
template<class A, size_t S> void read(ar<A, S>& a);
template<class T> void read(T& x) {
    cin >> x;
}
void read(double& d) {
    string t;
    read(t);
    d=stod(t);
}
void read(long double& d) {
    string t;
    read(t);
    d=stold(t);
}
template<class H, class... T> void read(H& h, T&... t) {
    read(h);
    read(t...);
}
template<class A> void read(vt<A>& x) {
    EACH(a, x)
        read(a);
}
template<class A, size_t S> void read(array<A, S>& x) {
    EACH(a, x)
        read(a);
}

string to_string(char c) {
    return string(1, c);
}
string to_string(bool b) {
    return b?"true":"false";
}
string to_string(const char* s) {
    return string(s);
}
string to_string(string s) {
    return s;
}
string to_string(vt<bool> v) {
    string res;
    FOR(sz(v))
        res+=char('0'+v[i]);
    return res;
}

template<size_t S> string to_string(bitset<S> b) {
    string res;
    FOR(S)
        res+=char('0'+b[i]);
    return res;
}
template<class T> string to_string(T v) {
    bool f=1;
    string res;
    EACH(x, v) {
        if(!f)
            res+=' ';
        f=0;
        res+=to_string(x);
    }
    return res;
}

template<class A> void write(A x) {
    cout << to_string(x);
}
template<class H, class... T> void write(const H& h, const T&... t) { 
    write(h);
    write(t...);
}
void print() {
    write("\n");
}
template<class H, class... T> void print(const H& h, const T&... t) { 
    write(h);
    if(sizeof...(t))
        write(' ');
    print(t...);
}

void DBG() {
    cerr << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
    cerr << to_string(h);
    if(sizeof...(t))
        cerr << ", ";
    DBG(t...);
}

#define _DEBUG
#ifdef _DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

template<class T> void offset(ll o, T& x) {
    x+=o;
}
template<class T> void offset(ll o, vt<T>& x) {
    EACH(a, x)
        offset(o, a);
}
template<class T, size_t S> void offset(ll o, ar<T, S>& x) {
    EACH(a, x)
        offset(o, a);
}

mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a, ll b) {
    return uniform_int_distribution<ll>(a, b)(mt_rng);
}

template<class T, class U> void vti(vt<T> &v, U x, size_t n) {
    v=vt<T>(n, x);
}
template<class T, class U> void vti(vt<T> &v, U x, size_t n, size_t m...) {
    v=vt<T>(n);
    EACH(a, v)
        vti(a, x, m);
}

const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
const int mod = 1e9 + 7;
const ll INF = 1e14;
const int mxN = 1e6 + 10;
const int N = 1e3 + 10;
int n,m;
struct bol {
    ll a1=0,a2,a3,a4;
};

struct segment_tree {
    vector<bol> t;
    int n;
    segment_tree(int _n){
        t.resize(4* _n+1);
        n=_n;
    }

    bol merge(bol &a,bol &b){
        bol c;
        c.a1= min({a.a1+b.a3, a.a2+b.a1});
        c.a2= min({a.a1+b.a4, a.a2+b.a2});
        c.a3= min({a.a3+b.a3, a.a4+b.a1});
        c.a4= min({a.a3+b.a4, a.a4+b.a2});
        return c;
    }

    void update(int node,int l,int r,int id,int vala){
        if(l==r){
            t[node].a2=t[node].a3=t[node].a4=vala;
            return;
        }
        int mid = (l+r)/2;
        if(id<= mid)
            update(2*node,l,mid,id,vala);
        else
            update(2*node+1, mid+1,r,id,vala);
        t[node] = merge(t[2*node],t[2*node+1]);
        return;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    read(n);
    n--;
    segment_tree seg(n);
    FOR(i,1,n+1){
        int a;
        read(a);
        seg.update(1,1,n,i,a);
    }
    int t=1;
    read(t);
    FOR(t) {
        int k,x;
        read(k,x);
        seg.update(1,1,n,k,x);
        print(2*seg.t[1].a4);
    }
}