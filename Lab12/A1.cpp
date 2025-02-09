#include <bits/stdc++.h>

using namespace std;

int p[200002];
pair<long, pair<long, long> > pairs[200002];
long w, ans=0;


int getParent(int v){
    if(v==p[v]){
        return v;
    }
    return p[v]=getParent((int)p[v]);
}

static int merge(int u, int v, int r){
    u=getParent(u);
    v=getParent(v);
    if(u==v){
        return v;
    }
    p[u]=v;
    ans+=w;
    return v;
}


int main(){
    int n;
    int m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int l,r,w; cin>>l>>r>>w;
        l--;
        r--;
        pairs[i]=make_pair(w,make_pair(l,r));
    }
    for(int i=0;i<n;i++){
            p[i]=i;
    }
    sort(pairs,pairs+m);
    for(int i=0;i<m;i++){
            w=pairs[i].first;
            for(long j=pairs[i].second.first+1;j<=pairs[i].second.second;j++){
                j=merge((int)pairs[i].second.first,(int)j,(int)pairs[i].second.second);
                if(j>pairs[i].second.second)break;
            }
        }
    cout<<ans;
    return 0;

}