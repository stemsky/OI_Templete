#include <bits/stdc++.h>
using ll=long long;
const int N=1e6, mod=998244353, g=3,invg=332748118;
ll qpow(ll a, int b) {
    a%=mod;
    ll res=1;
    while (b>0) {
        if (b&1) res=a*res%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

int rev[(N<<1)+5];int n,lim;
void NTT_init(int n_) { // 参数为多项式的次数
    n_<<=1;
    int len=0;lim=1;
    while (lim<=n_) lim<<=1,len++;
    for (int i=0;i<lim;i++) {
        rev[i]=(rev[i>>1]>>1) | ((i&1)<<(len-1));
    }
}
void NTT(ll c[], int opt) {
    for (int i=0;i<lim;i++) if (i<rev[i]) std::swap(c[i],c[rev[i]]);
    for (int i=2;i<=lim;i<<=1) {
        ll gn=qpow(opt==1?g:invg, (mod-1)/i);
        for (int j=0;j<lim;j+=i) {
            ll gk=1;
            for (int k=j;k<j+(i>>1);k++) {
                ll u=c[k], t=gk*c[k+(i>>1)]%mod;
                c[k]=(u+t)%mod;
                c[k+(i>>1)]=(u-t+mod)%mod;
                gk=gk*gn%mod;
            }
        }
    }
    if (opt==-1) {
        ll inv=qpow(lim, mod-2);
        for (int i=0;i<lim;i++) {
            c[i]=c[i]*inv%mod;
        }
    }
}