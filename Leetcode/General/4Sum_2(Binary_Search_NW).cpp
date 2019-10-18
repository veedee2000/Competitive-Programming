class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        sort(D.begin(),D.end());
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
                            if(sum == D[l] or sum == D[r]) ++ans;
                            break;
                        }
                        else{
                            if(sum == D[m]){
                                {++ans; break;}
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
