/*
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
*/

/这道题就是一个二分查找，找到那个临界点*/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int low = 1;
        int high = n;
        int mid = 0;
        while(low < high)
        {
            mid = low +  (high - low) / 2;   //求中点(不知道为什么 MID = (LOW + HIGH) / 2 就不对
            
            if(isBadVersion(mid)) high = mid;
            else low = mid + 1;
        }
        return low;
        
        
    }
};