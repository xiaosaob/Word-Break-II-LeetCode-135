// Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

// Return all such possible sentences.

// For example, given
// s = "catsanddog",
// dict = ["cat", "cats", "and", "sand", "dog"].

// A solution is ["cats and dog", "cat sand dog"].

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> res;
        int n = s.size();
        vector<bool> possible(n+1,true);
        helper(s,0,dict,"",res,possible);
        return res;
    }
    
    void helper(string s, int startIdx, unordered_set<string> &dict, string curStr, vector<string> &res, vector<bool> &possible) {
        if(startIdx == s.size()) {
            res.push_back(curStr);
            return;
        } 
        for(int i = startIdx; i < s.size(); ++i) {
            if(dict.count(s.substr(startIdx,i-startIdx+1)) && possible[i+1]) {
                int oldsize = res.size();
                string tmpStr = curStr == "" ? s.substr(startIdx,i-startIdx+1) : curStr+" "+s.substr(startIdx,i-startIdx+1);
                helper(s,i+1,dict,tmpStr,res,possible);
                if(res.size() == oldsize)
                    possible[i+1] = false;
            }
        }
    }
};
