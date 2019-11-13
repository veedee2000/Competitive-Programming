class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        queue<int>q;
        for(int i = 0;i < a.size();i++){
            if(!a[i]) q.push(i);
        }
        int now = 0,ans = 0,start = 0;
        for(int i = 0;i < a.size();i++){
            if(a[i]){
                ans = max(ans,++now);
            }
            else{
                if(k > 0){
                    k--;
                    ans = max(ans,++now);
                }
                else{
                    while(start != q.front()) ++start;
                    ++start;
                    q.pop();
                    now = (i - start + 1);
                }
            }
        }
        return ans;
    }
};
