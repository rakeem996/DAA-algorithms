#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)


bool compare(pii p1, pii p2){
    double v1 = (double) p1.ff/p1.ss;
    double v2 = (double) p2.ff/p2.ss;
    cout<<"comparing "<<v1<<" "<<v2<<endl;
    return v1>v2;
}

signed main(){
    cout<<"enter the numeber of elements : ";
    int n;
    cin>> n;
    
    vii a(n);

    rep(i,0,n){
        cout<<"enter the value and the weight : ";
        cin>> a[i].ff >> a[i].ss;
    }

    int W;
    cout<<"enter the total weight : ";
    cin>> W;


    cout<<"enter the sorting where we wil compare the v/w or the elements "<<endl;
    sort(a.begin(),a.end(),compare);

    int ans = 0;

    rep(i,0,n){

        if(W >= a[i].ss){
            ans+=a[i].ff;
            W-=a[i].ss;
            continue;
        }

        double vw = (double) a[i].ff/a[i].ss;
        ans += vw * W;
        W=0;
        break;
    }

    cout<<"the max value is : "<<ans<<endl;
    return 05;
}