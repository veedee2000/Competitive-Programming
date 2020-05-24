class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>>contentToFiles;
        vector<vector<string>>duplicates;
        
        for(auto dir:paths){
            stringstream stream(dir);
            string s, path;
            int count = 0;
            while(stream >> s){
                if(!count++) path = s;
                else{
                    pair<string,string>parsedString = regex(s);
                    contentToFiles[parsedString.second].push_back(path + "/" + parsedString.first);
                }
            }
        }
        for(auto contents:contentToFiles){
            if(contents.second.size() > 1) duplicates.push_back(contents.second);
        }
        return duplicates;
    }
    
    pair<string,string> regex(string& s){
        int begin = 0, end = s.size() - 1;
        while(s[begin++] != '(') {}
        return {s.substr(0,begin - 1),s.substr(begin,end - begin + 1)};
    }
    
};
