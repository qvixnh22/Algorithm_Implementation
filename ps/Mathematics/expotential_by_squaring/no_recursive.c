long long exp(long long a, long long b, long long mod){
	long long ans = 1;
	while(b){
		if(b&1)ans*=a;
		a*=a;
		b>>=1;
		ans%=mod;a%=mod;
	}
	return ans;
}
