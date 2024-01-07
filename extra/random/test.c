#include <stdbool.h>
#include <stdio.h>

void helper();
void tester();

int main() {
    bool x = true;
    if (x) {
        printf("x is true!");
        helper();
        tester();
        }
}

void helper() {
    int i;
    int j;

    for (i = 0, j = 10; i < 100; i++, j++)
        printf("%d, %d\n", i, j);
}

void tester() {
    int j;
    int k;

    printf("enter the value for j!: ");
    if (scanf("%d", &j) != 1) {
        printf("error: invalid int input!\n");
        return;
    }

    printf("enter the value for k!: ");
    if (scanf("%d", &k) != 1) {
        printf("error: invalid int input!\n");
        return;
    }

    if (j < 10 && k > 20) {
        printf("brev\n");
    } else {
        printf("shorty\n");
    } 
}

void getter() {

}
