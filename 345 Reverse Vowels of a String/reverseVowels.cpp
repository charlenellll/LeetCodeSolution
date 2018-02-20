// Solution 2: Normal and easy
// the swap() I use here is the normal swap we use in an array !!!!! not the one in the string class.
// in C++, string has already implemented its own swap() function, which is used to swap the content of two trings.Use it like: str1.swap(str2);
// 12ms, 40.77%

class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        int p = 0, q = n-1;
        while( p < q ){
            while( !isVowel(s[p]) && p < q ) p++;
            while( !isVowel(s[q]) && p < q ) q--;
            swap(s[p++],s[q--]);
        }
        return s;
    }
    bool isVowel(char c){
        c = tolower(c);
        if( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }
};


// Solution 3: special for this case, not applicable for all circumstances
// find_first_of("all the characters you want to match", start position) and find_last_of("", end position)
// 12ms, 40.77%
class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        int p = 0, q = n-1;
        while( p < q ){
            p = s.find_first_of("aeiouAEIOU", p);
            q = s.find_last_of("aeiouAEIOU", q);
            if( p < q )
                swap(s[p++], s[q--]);
        }
        return s;
    }
};

// I was misled by some blogs that there is no swap() function to swap elements inside a string
// They said in string the swap() can only swap the content of two strings, so I implemented it by myself. It was trivial! And not worth it!
// actually they're talking about the s1.swap(&s2), what I need is swap(char1,char2) and it works well.

// Solution 1 :Trivial
// 12ms, 40.77%

class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        if( n <= 1 ) return s;
        string res = "", right = "";
        int p = 0, q = n-1;
        while( p < q ){
            while( !isVowel(s[p]) && p < q ) res += s[p], p++;
            while( !isVowel(s[q]) && p < q ) right += s[q], q--;
            // swap s[p] and s[q]
            if( p < q ) // trivial
                res += s[q], right += s[p];
            if( p == q ) res += s[p]; //trivial
            p++, q--;
        }
        if( p == q ) res += s[p]; // trivial
        reverse( right.begin(), right.end() );
        res = res + right;
        return res;
    }
    bool isVowel(char c){
        if( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        return false;
    }
};