class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& a) {
        vector<int>v_even,v_odd,v;
        for(auto x:a){
            if(x%2 == 0) v_even.push_back(x);
            else v_odd.push_back(x);
        }
        int e = 0, o = 0;
        for(int i=0;i<a.size();i++){
            if(i%2 != 0){
                v.push_back(v_odd[o++]);
                // ++o;
            }
            else{
                v.push_back(v_even[e++]);
                // ++e;
            }
        }
        return v;
    }
};
