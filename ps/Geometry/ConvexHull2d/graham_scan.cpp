void graham_scan(vector<pt<ll>>& vec){
    swap(vec[0], *min_element(vec.begin(), vec.end()));
    pt<ll> point = vec[0];
    sort(vec.begin() + 1, vec.end(), [point](pt<ll> a, pt<ll> b){
        ll ccw = point.cross(a, b);
        if (ccw != 0)   return ccw > 0;
        return a.dist2() < b.dist2();
    });
    vector<pt<ll>> st;
    for (auto now: vec){
        while (st.size() > 1 && st[st.size() - 2].cross(st[st.size() - 1], now) <= 0){
            st.pop_back();
        }
        st.emplace_back(now);
    }
    for (auto [x, y]: st){
        cout << "(" << x << ", " << y << ")\n";
    }
}
