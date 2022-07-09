#include <string>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using std::string;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length())
        {
          return false;
        }

        std::unordered_map<char,char> map; //stores mapping of t[i] with s[i]
        std::unordered_set<char> set; //stores mapping of s[i] with t[i]
        
        //to store first occurence of each character and its corresponding character in other string 
        for(size_t i = 0; i < t.size(); ++i){
            if(map.find(t[i])!=map.end()){
              // Return false if 1st occurence of c1 is mapped to a different character.
              if(map[s[i]]!=t[i])
                return false;
            }
            // If c1 encountered for first time and has not been mapped yet
            else{
              // return false if t[i] already mapped to some other char in s[i]
              if(set.find(s[i])==set.end()){
                return false;
              }
              map[s[i]] = t[i];
              set.insert(t[i]);

            }
        }
        return true;
    }
};

int main()
{
  string s1 = "AAB";
  string s2 = "XXY";
  Solution sol1;
  assert(sol1.isIsomorphic(s1, s2) == 0);
}

