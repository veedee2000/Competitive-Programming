class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        sort(D.begin(),D.end());
        map<int,int>mp;
        for(auto x:D) mp[x]++;
        int ans = 0;
        for(auto a:A){
            for(auto b:B){
                for(auto c:C){
                    int n = D.size();
                    int l=0,r=n-1,m;
                    int sum = -a-b-c;
                    if(n == 1){
                        if(D[0] == sum) ++ans;
                        continue;
                    }
                    while(l <= r-1){
                        m = l + (r - l)/2;
                        if(l == r-1){
                            if(sum == D[l]) ans += mp[D[l]];
                            else if(sum == D[r]) ans += mp[D[r]];
                            break;
                        }
                        else{
                            if(sum == D[m]){
                                {ans += mp[D[m]]; break;}
                            }
                            else if(sum < D[m]){
                                r = m;
                            }
                            else l = m;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
