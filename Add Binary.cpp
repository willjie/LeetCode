//äºŒè¿›åˆ¶å­—ç¬¦ä¸²ç›¸åŠ ã€‚
/*¶ş½øÖÆÊıÏë¼Ó£¬²¢ÇÒ±£´æÔÚstringÖĞ£¬Òª×¢ÒâµÄÊÇÈçºÎ½«stringºÍintÖ®¼ä»¥Ïà×ª»»£¬
²¢ÇÒÃ¿Î»Ïà¼ÓÊ±£¬»áÓĞ½øÎ»µÄ¿ÉÄÜ£¬»áÓ°ÏìÖ®ºóÏà¼ÓµÄ½á¹û¡£
¶øÇÒÁ½¸öÊäÈëstringµÄ³¤¶ÈÒ²¿ÉÄÜ»á²»Í¬¡£
ÕâÊ±ÎÒÃÇĞèÒªĞÂ½¨Ò»¸östring£¬ËüµÄ³¤¶ÈÊÇÁ½ÌõÊäÈëstringÖĞµÄ½Ï´óµÄÄÇ¸ö£¬
²¢ÇÒ°Ñ½Ï¶ÌµÄÄÇ¸öÊäÈëstringÍ¨¹ıÔÚ¿ªÍ·¼Ó×Ö·û¡®0¡¯À´²¹µÄ½Ï´óµÄÄÇ¸ö³¤¶È¡£
ÕâÊ±ºòÎÒÃÇÖğ¸ö´ÓÁ½¸östringµÄÄ©Î²¿ªÊ¼È¡³ö×Ö·û£¬È»ºó×ªÎªÊı×Ö£¬
Ïë¼Ó£¬Èç¹û´óÓÚµÈÓÚ2£¬Ôò±ê¼Ç½øÎ»±êÖ¾carry£¬²¢ÇÒ¸øĞÂstring¼ÓÈëÒ»¸ö×Ö·û¡®0¡¯¡£
*/

class Solution {
public:
    string addBinary(string a, string b) {
        
        string c = "";
        bool flag = false;     /*½øÎ»±êÖ¾*/
        
        int temp = 0;
        int length_a = a.size();
        int length_b = b.size();
        
        if (length_a > length_b)
        {
            for(int i = 0; i < length_a-length_b;i++)
            {
                b.insert(b.begin(),'0');               /*ÊÇÁ½¸ö¼ÓÊıÎ»Êı¶ÔÆë*/
            }
        }
        else if(length_a < length_b)
        {
            for(int i = 0; i < length_b-length_a; i++)
            {
                a.insert(a.begin(),'0');
            }
        }
        for(int i = a.size()-1; i >= 0; i--)
        {
            if(flag)            /*ÅĞ¶ÏÊÇ·ñÓĞ½øÎ»*/
            {
                 temp = a[i] -'0' + (b[i] - '0') + 1;
            }
            else
            {
                 temp = a[i] -'0' + (b[i] - '0');
            }
            switch (temp)
            {
                case 0: c.insert(c.begin(),'0'); flag = false; break;        /*Í¨¹ıÏòÇ°²åÈëÀ´µÃ³ö½á¹û*/
                case 1: c.insert(c.begin(),'1'); flag = false; break;
                case 2: c.insert(c.begin(),'0'); flag = true; break;
                case 3:  c.insert(c.begin(),'1'); flag = true; break;
            }
        }
        if(flag)
        {
            c.insert(c.begin(),'1');
        }
        
        return c;
    }
};