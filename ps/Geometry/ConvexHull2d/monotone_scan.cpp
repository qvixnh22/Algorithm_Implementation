char ccw(std::pair<long long,long long> a, std::pair<long long,long long> b, std::pair<long long,long long> c){
	long long t = (a.first*b.second + b.first*c.second + c.first*a.second)-(a.second*b.first + b.second*c.first + c.second*a.first);
	return t?t<0?-1:1:0;
}
void convex(std::vector<std::pair<long long,long long>>& vc){
	if(vc.size()<3)return;
	std::vector<std::pair<long long,long long>> ans;
	std::sort(vc.begin(),vc.end());
	
	std::stack<std::pair<long long,long long>> stk;

  //upper hull
	stk.push(vc[vc.size()-1]);stk.push(vc[vc.size()-2]);
	for(int i = vc.size()-3;i>=0;){
		auto mid = stk.top();stk.pop();
		auto from = stk.top();
		if(ccw(from,mid,vc[i])>0){
			stk.push(mid);
			stk.push(vc[i--]);
		}else if(stk.size()==1)stk.push(vc[i--]);
	}
	
	stk.pop();while(!stk.empty()){
		ans.push_back(stk.top());
		stk.pop();
	}

  //lower hull
	stk.push(vc[0]);stk.push(vc[1]);
	for(int i = 2;i<vc.size();){
		auto mid = stk.top();stk.pop();
		auto from = stk.top();
		int c = ccw(from,mid,vc[i]);
		if(c>0){
			stk.push(mid);
			stk.push(vc[i++]);
		}else if(stk.size()==1)stk.push(vc[i++]);
	}
	
	stk.pop();while(!stk.empty()){
		ans.push_back(stk.top());
		stk.pop();
	}
	
	vc.resize(ans.size());
	for(int i = 0;i<ans.size();i++)vc[i]=ans[i];
}
