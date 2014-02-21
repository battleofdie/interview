// Silly and ugly code, I am not satisfied with this code.

class Solution {
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s == NULL) return false;
        
        while(*s != '\0' && *s == ' ') s++;
        if(*s == '\0') return false;
        
        int len = strlen(s);
        while(*(s+len-1) == ' ') len--;

        int left=0, left_dot = 0, right=0, right_dot=0;
        bool has_e = false;

        const char* end = s + len - 1;
        while(s <= end)
        {
            if(*s == 'e' || *s == 'E')
            {
                if(has_e) return false;
                has_e = true;
                if(left == 0) return false; // like: e12
            }
            else if(*s >= '0' && *s <= '9')
            {
                if(has_e) right++;
                else left++;
            }
            else if(*s == '.')
            {
                if(has_e) right_dot++;
                else left_dot++;
            }
            else if(*s == '-')
            {
               if(has_e)
               {
                  if(right_dot > 0) return false;
                  if(right > 0) return false;
                  s++;
                  while(s != end && *s == ' ') s++;
                  s--;
               }
               else
               {
                  if(left_dot > 0) return false;
                  if(left > 0) return false;
                  s++;
                  while(s != end && *s == ' ') s++;
                  s--;
               }
            }
            else if(*s == '+')
            {
               if(s[1] == ' ') return false;
               if(has_e)
               {
                   if(right_dot > 0) return false;
                  if(right > 0) return false;
               }
               else
               {
                   if(left_dot > 0) return false;
                  if(left > 0) return false;
               }
            }
            else
                return false;
            
            s++;
        }//while
        
        if(has_e)
            return left > 0 && left_dot < 2 && right > 0 && right_dot == 0;
        else
            return left > 0 && left_dot < 2;
    }
};
