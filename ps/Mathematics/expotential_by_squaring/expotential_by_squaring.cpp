using ll = long long;
ll ebs(ll v, ll p, ll mod){
    if (p == 1)  return v;
    ll rt = ebs(v, p / 2, mod); rt = (rt * rt) % mod;
    if (p % 2)  rt = (rt * v) % mod;
    return rt;
}
