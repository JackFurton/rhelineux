#include <stdio.h>

int main() {
    int temp;
    printf("what temp is it?\n");
    scanf("%d", &temp);

    if (temp >= 70) {
        printf("its HOIT\n");
    } else if (temp >= 30 && temp < 70) {
        printf("its MOILD\n");
    } else {
        printf("ayo its cold n shiit\n");
    }
    return 0;
}
