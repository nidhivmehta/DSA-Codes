class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, pair<int, int>>> v;
        
        int dist;
        for(auto it: points) {
            dist = pow(it[0], 2) + pow(it[1], 2);
            v.push_back({dist, {it[0], it[1]}});
        }
        
        sort(v.begin(), v.end());
        vector<vector<int>> kOrigin(k);
            
        for(int i=0; i<k; i++) {
            kOrigin[i].push_back(v[i].second.first);
            kOrigin[i].push_back(v[i].second.second);
        }
        
        return kOrigin;
        
    }
};