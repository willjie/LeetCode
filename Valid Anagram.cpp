/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        sort(s.begin(),s.end());      //进行排序
        sort(t.begin(),t.end());      //进行排序
        
        if(s == t)
        {
            return true;
        }
        return false;
        
    }
};