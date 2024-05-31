const int N = 1<<25;
//containing minimum divisor
long long sieve[N+1];
void build_sieve(){
	sieve[1]=1;
	sieve[0]=0;
	for(int i = 2;i<=N;i++){
		//to find prime
		while(sieve[i])i++;
		//i is prime now
		sieve[i]=i;
		for(int j = i*2;j<=N;j+=i)if(!sieve[j])sieve[j]=i;
	}
}
