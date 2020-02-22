class Solution {
public:
    string convert(string s, int numRows) {
        if(!s.size()) return "";
        int elementSize = 2 * numRows - 2;
        if(elementSize < 2) return s;
        int column = (numRows - 1) * (s.size() / elementSize);
        column += (s.size() % elementSize > 0) + max((int) s.size() % elementSize - numRows,0);
        vector<vector<char>>v(numRows,vector<char>(column,'$'));
        int rowNow = -1,columnNow = -1,index = 0;
        for(int i = 0;i < s.size();i++){
            if(i % elementSize < numRows){
                if(i % elementSize == 0) rowNow = 0,columnNow++;
                else rowNow++;
            }
            else rowNow--,columnNow++;
            v[rowNow][columnNow] = s[index++];
        }
        string ans;
        for(auto line:v){
            for(auto c:line) if(c != '$') ans.push_back(c);
        }
        return ans;
    }
};
