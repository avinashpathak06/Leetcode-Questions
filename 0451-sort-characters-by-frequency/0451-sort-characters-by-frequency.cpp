class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        map<char,int>m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        vector<pair<int,char>>v;
        for(auto i: m){
            pair<int,char>p;
            p = make_pair(i.second,i.first);
            v.push_back(p);
        }
        cout<<endl;
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        for(auto i: v){
            int d = i.first;
            for(int j=0;j<d;j++){
                ans+=i.second;
            }
        }
        return ans;
    }
};