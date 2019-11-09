class Solution {
public:
    
    bool static compare(string &s1,string &s2){
        return (s1.size() < s2.size());
    }
    
    int longestStrChain(vector<string>& words) {
        if (words.size() < 2)
            return words.size();
        
        
        unordered_map<string, int> len;
        for (string w : words)
            len[w] = 1;
        
        sort(words.begin(), words.end(),compare);
        for (string & w : words){
            //remove one letter from each of the word if its size is more than 1
            int w_len = w.length();
            if(w_len != 1){

                for (int i = 0; i < w.size(); i++){
                    string new_w = "";
                    if(i != 0)
                        new_w = w.substr(0, i) + w.substr(i + 1, w_len - i - 1);
                    else
                        new_w = w.substr(1, w_len - 1);
                    
                        if (len.find(new_w) != len.end()) // if there exist a substring of w with one letter removed, then see if chain from that string is long enough
                        len[w] = max(len[w], len[new_w] + 1);
                }
            }
        }
        //get max length
        int ans = 1;
        for (string & w : words)
            ans = max(ans, len[w]);
        return ans;
    }
    
};
