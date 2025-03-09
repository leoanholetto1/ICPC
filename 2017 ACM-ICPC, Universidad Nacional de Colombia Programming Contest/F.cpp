#include <stdio.h>
#include <algorithm>
#include <string>

bool check(int a, int b, int c) {
    return (a < b + c && b < c + a && c < a + b);
}

int main() {

    int n;
    scanf("%d", &n);

    while(n--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if(check(a, b, c)) continue;
        puts("NO");
        return 0;
    }
    puts("YES");

    return 0;
}