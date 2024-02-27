#define MAX_N 100,000
vector<int> edge[MAX_N];
bool visited[MAX_N];
void bfs(){
    vector<int> order;
    queue<int> q;
    while (!q.empty()){
        ll v = q.front(); q.pop();
        visited[v] = true; order.emplace_back(v);
        for (int nxt: edge[v]){
            if (visited[nxt])  continue;
            q.push(nxt);
        }
    }
    for (int o: order){
        cout << o << "\n";
    }
}
