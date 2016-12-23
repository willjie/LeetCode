/*Write a function to find the longest common prefix string amongst an array of strings.*/

/*�ҳ��ַ�������������ǰ׺*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string s,s1;
        int count = 0;
        int i = 0;
        if(strs.size() == 0)
        {
            return "";
        }
        if(strs.size() == 1)
        {
            return strs[0];
        }
        int max_length = FindSimilar(strs[0],strs[1]) ;  /*�������仰д��if��ǰ�棬���п���Խ�磬ֻ����ȷ����2�м����ϵ�ʱ����ܽ�0 �� 1���бȽ�*/        
        for(int j = i + 2; j < strs.size(); j++)
        {
           count = FindSimilar(strs[0],strs[j]);

           if(count < max_length)
           {
               max_length = count;
           }
           
        }
        s1 = strs[0];
        for(int i = 0;i < max_length;i++)
        {
            s.push_back(s1[i]);
        }
        return s;
    }
    
    int FindSimilar(string &s1,string &s2)
    {
        int i = 0;
        int j = 0;
        int count = 0;
        while(s1[i] == s2[j] && i < s1.size() && j < s2.size())
        {
            i++;
            j++;
            count++;
        }
        return count;
    }
};