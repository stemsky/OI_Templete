using ull=unsigned long long;using ll=long long;
ull qpow(ull a, ull b) {
    ull res=1;
    while (b>0) {
        if (b&1)res*=a;
        a*=a;b>>=1;
    }
    return res;
}

int mod=998244353;
ull qpow_mod(ull a, ull b) {
    ull res=1;
    a%=mod;
    while (b>0) {
        if (b&1)res=res*a%mod;
        a=a*a%mod;b>>=1;
    }
    return res;
}