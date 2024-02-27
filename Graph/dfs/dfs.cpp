#define MAX_N 100000
vector<int> edge[MAX_N];
bool visited[MAX_N];
void dfs(){
    vector<int> order;
    stack<int> s;
    while (!s.empty()){
        ll v = s.top(); s.pop();
        visited[v] = true; order.emplace_back(v);
        for (int nxt: edge[v]){
            if (visited[nxt])  continue;
            s.push(nxt);
        }
    }
    for (int o: order){
        cout << o << "\n";
    }
}
