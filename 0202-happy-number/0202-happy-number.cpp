class Solution {
public:
    bool isHappy(int n) {
        if(n == 1) {
            return true;
        }
        vector<int> visited;
        int sq;
        while(find(visited.begin(), visited.end(), n) == visited.end()) {
            visited.push_back(n);
            sq = 0;
            while(n != 0) {
                sq += (n % 10) * (n % 10);
                n = n/10;
            }
            if(sq == 1) {
                return true;
            }
            n = sq;
        }
        return false;
    }
};