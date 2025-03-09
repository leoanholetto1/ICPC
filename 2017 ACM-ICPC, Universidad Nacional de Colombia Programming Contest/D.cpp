#include <stdio.h>
#include <algorithm>
#include <string>

int main() {

    int n;
    scanf("%d", &n);

    std::string s = "";
    while(n) {
        s += (n&1) ? 'A' : 'B';
        if(n&1) n = ((n-1) >> 1);
        else n = ((n-2) >> 1);
    }
    for(int i = 0; i < s.size(); i++)
        printf("%c", s[s.size()-i-1]);

    return 0;
}