#include<bits/stdc++.h>

using namespace std;

const int64_t maxn= 1 << 20;

int64_t a[maxn+2];

struct tree{
    int64_t l,r;
    long long pre,add;
}t[4*maxn+2];

void bulid(int64_t p,int64_t l,int64_t r){
    t[p].l=l;t[p].r=r;
    if(l==r){
        t[p].pre=a[l];
        return;
    }
    int64_t mid=l+r>>1;
    bulid(p*2,l,mid);
    bulid(p*2+1,mid+1,r);
    t[p].pre=t[p*2].pre+t[p*2+1].pre;
} 

void spread(int64_t p){
    if(t[p].add){
        t[p*2].pre+=t[p].add*(t[p*2].r-t[p*2].l+1);
        t[p*2+1].pre+=t[p].add*(t[p*2+1].r-t[p*2+1].l+1);
        t[p*2].add+=t[p].add;
        t[p*2+1].add+=t[p].add;
        t[p].add=0;
    }
}

void change(int64_t p,int64_t x,int64_t y,int64_t z){
    if(x<=t[p].l && y>=t[p].r){
        t[p].pre+=(long long)z*(t[p].r-t[p].l+1);
        t[p].add+=z;
        return;
    }
    spread(p);
    int64_t mid=t[p].l+t[p].r>>1;
    if(x<=mid) change(p*2,x,y,z);
    if(y>mid) change(p*2+1,x,y,z);
    t[p].pre=t[p*2].pre+t[p*2+1].pre;   
}

long long ask(int64_t p,int64_t x,int64_t y){
    if(x<=t[p].l && y>=t[p].r) return t[p].pre;
    spread(p);
    int64_t mid=t[p].l+t[p].r>>1;
    long long ans=0;
    if(x<=mid) ans+=ask(p*2,x,y);
    if(y>mid) ans+=ask(p*2+1,x,y);
    return ans;
}

int main(){
    int64_t n,m,level=1;
    scanf("%lld%lld",&n,&m);
    while (pow(2, level) <= n) level++;
    level = pow(2, level) - 1;
    for(int64_t i=1;i<=n;i++)
    scanf("%lld",&a[i]);
    bulid(1,1,n);
    for(int64_t i=1;i<=m;i++)
    {
        int64_t x,y,z;
        scanf("%lld%lld%lld",&x,&y,&z);
        change(1,x,y,z);
        cout<< ask(1,1,n) * level<<endl;
    }
    return 0;
}