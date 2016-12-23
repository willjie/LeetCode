/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

/*��������������ʼ����ʱ��û�㶮���ø�ɶ�ģ��������˱��˵ķ����󣬲�֪��ʵ���ϸ�쳲��������зǳ����ƣ�����������n�㣬��ô���������n���أ���Ϊÿ��ֻ����1��2������ô������n��ķ���Ҫô�Ǵӵ�n-1��һ�������ģ�
Ҫ�����Ǵ�n-2��2�������ģ�
���Ե��ƹ�ʽ�ǳ����׵ľ͵ó��ˣ�dp[n] = dp[n-1] + dp[n-2]��
*/

class Solution {
public:
    int climbStairs(int n) {
        
        /*����������Ҫ�õ���̬�滮*/     /*dp[n] = dp[n-1] + dp[n-2]*/
        
          vector<int> Dp(n+1);
          Dp[0] = 1;
          Dp[1] = 1;
          
          for(int i = 2; i<=n;i++)
          {
              Dp[i] = Dp[i-1] + Dp[i-2];
          }
          
          return Dp[n];
        
        
        
    }
};