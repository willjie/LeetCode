/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        sort(s.begin(),s.end());      //��������
        sort(t.begin(),t.end());      //��������
        
        if(s == t)
        {
            return true;
        }
        return false;
        
    }
};