class Solution {
private:
    const string letterMap[10] = {
        " ",    //0
        "",     //1
        "abc",  //2
        "def",  //3
        "ghi",  //4
        "jkl",  //5
        "mno",  //6
        "pqrs", //7
        "tuv",  //8
        "wxyz"  //9
    };
    
    vector<string> res;
    
    // s stores the string converted by digits[0..index-1]
    // find the letters corresponding to digits[index] to get the possible string corresponding to digits[0..index]
    void findCombination(const string &digits, int index, const string &s){
        
        if( index == digits.size() ){
            // store the s
            res.push_back(s);
            return;
        }
        
        char c = digits[index];
        assert( c >= '0' && c <= '9' && c != '1');
        string letters = letterMap[c-'0'];
        for(int i = 0; i < letters.size(); i++)
            findCombination(digits, index+1, s+letters[i]);
        
        return;
    }
public:
    vector<string> letterCombinations(string digits) {
        
        res.clear();
        if(digits == "")
            return res;
        
        findCombination(digits, 0, "");
        
        return res;
    }
};