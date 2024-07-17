const int N=1e6, mod=998244353;
using ll=long long;
int n; ll inv[N];
void GetInv(){inv[1]=1;for (int i=2;i<=n;++i) {inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;}}