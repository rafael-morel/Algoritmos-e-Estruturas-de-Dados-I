#include <stdio.h>

int main() {
    int a, b, c, x, y, z;

    scanf("%d %d %d", &a, &b, &c);

    x = a, y = b, z = c;

    if (x > y) { int temp = x; x = y; y = temp; }
    if (x > z) { int temp = x; x = z; z = temp; }
    if (y > z) { int temp = y; y = z; z = temp; }

    printf("%d\n%d\n%d\n\n", x, y, z);
    printf("%d\n%d\n%d\n", a, b, c);

    return 0;
}
