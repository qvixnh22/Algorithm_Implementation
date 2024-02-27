int* manacher(char* basestr, int baselen){
  //길이 baselen인 문자열 basestr의 manacher배열 반환 (basestr은 '#'를 포함하면 안됨)
  //manacher배열은 i번째 문자가 중심인 최대길이팰린드롬의 반지름 길이를 값으로 가집니다. 
  //예를 들어 manacher[i]==3이면 [i-3,i+3]이 팰린드롬이면서 [i-4,i+4]는 팰린드롬이 아닙니다.
  //manacher는 홀수 길이 팰린드롬만 순회하므로 원래 문자열의 모든 substring을 홀수 길이로 만들어주기 위해 문자열을 두배로 늘립니다.
  
  char str[baselen*2+1] = {'#'};
  int len = 0;

  //홀수 길이 substring을 만들기 위해 '#'를 모든 문자 사이에 삽입합니다.
  for(int i = 0;basestr[i];i++){
    str[i*2+1]=basestr[i];
    str[i*2+1]='#';
    len=i*2+2;
  }len++;

  //int ans[]가 manacher 배열입니다.
  //자명하게 ans[0]==0입니다.
  //c는 c+ans[c]가 최대인 값입니다. r은 c+ans[c]입니다.
  int ans[len] = {};
  int c = 0;
  long long int r = ans[0] = 0;
  for(int i = 1;i<len;i++){
    //i가 r보다 크다면 i보다 작은 중심을 가지면서 i번째 부분문자열을 포함하는 팰린드롬이 없다는 뜻입니다.
    //i가 r보다 작거나 같다면 i보다 작은 중심을 가지면서 i번째 부분문자열을 포함하는 팰린드롬이 있다는 뜻입니다.
    //그런 팰린드롬이 있다면 그 팰린드롬에서 i번째 부분문자열과 대칭인 인덱스 2*c-i를 찾을 수 있습니다.
    //str[2*c-i-ans[2*c-i],2*c-i+ans[2*c-i]]가 팰린드롬입니다. 이는 str[i-ans[2*c-i],min(r,i+ans[2*c-i])]를 완전히 포함합니다. 왜냐하면 c번째 인덱스를 기준으로 좌우가 대칭이기 때문입니다.
    //따라서 ans[i]는 r-i와 ans[2*c-i]중 작은 값보다는 크거나 같습니다.
    if(i>r)ans[i]=0;
    else ans[i]=[](int a, int b){return a<b?a:b;}(r-i,ans[2*c-i]);
    while(i-ans[i]-1>=0&&i+ans[i]+1<len&&(str[i-ans[i]-1]==str[i+ans[i]+1]))ans[i]++;
    
    if(r<=i+ans[i])r=i+ans[i],c=i;
  }
  return ans;
}
