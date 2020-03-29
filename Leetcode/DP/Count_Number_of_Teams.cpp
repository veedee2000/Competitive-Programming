  class Solution{
      public:
        int numTeams(vector<int>& soldiers) {
            int n = soldiers.size(),res = 0;
            vector<int>countG(n,0),countL(n,0);

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < i; j++) {
                    if(soldiers[j] < soldiers[i]) {
                        countG[i]++;
                        res += countG[j];
                    }
                    if(soldiers[j] > soldiers[i]) {
                        countL[i]++;
                        res += countL[j];
                    }
                }
            }
            return res;
        }
  };
