#include <stdio.h>

int romanToInt(char* s) {
    int charSet[255]={0};
    int total= 0;
    //I
    charSet['I'] = 1;
    charSet['V'] = 5;
    charSet['X'] = 10;
    charSet['L'] = 50;
    charSet['C']= 100;
    charSet['D'] = 500;
    charSet['M'] = 1000;

    int index = 0;
    int offset = 0;
    while (s[index]!=0)
    {
        if (s[index] == 'I')
        {
            total+=charSet[s[index]];
            offset = -2;
        }
        else if (s[index] == 'X')
        {
            if (offset == -2) //previous token is I
            {
                total+=charSet[s[index]] +offset;
                offset = 0;
            }
            else {
                total+=charSet[s[index]];
                offset = -20;
            }
        }
        else if (s[index] == 'C')
        {
            if (offset == -20) //previous token is I
            {
                total+=charSet[s[index]] +offset;
                offset = 0;
            }
            else {
                total+=charSet[s[index]];
                offset = -200;
            }
        }
        else if (s[index] == 'V')
        {
            if (offset == -2)
                total += charSet[s[index]] +offset;
            else
                total += charSet[s[index]];
            offset = 0;
        }
        else if (s[index] == 'L' )
        {
            if (offset == -20)
                total += charSet[s[index]] +offset;
            else
                total += charSet[s[index]];
            offset = 0;
        }
        else if (s[index] == 'D' || s[index] == 'M')
        {
            if (offset == -200)
                total += charSet[s[index]] +offset;
            else
                total += charSet[s[index]];
            offset = 0;
        }
        else {
            total+=charSet[s[index]];
        }
        index++;
    }
    return total;
}
int main() {

    romanToInt("MCMXCIV");
    return 0;
}