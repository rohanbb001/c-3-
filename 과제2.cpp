#include <stdio.h>

int main() {
    int N1 = 4, N2 = 3; // 예시 크기 (4행 3열)
    int A[4][3];
    int B[3][4]; // 행과 열이 바뀌므로 3행 4열
    int num = 1;

    // 배열 A 채우기
    for (int i = 0; i < N1; i++) {
        for (int j = 0; j < N2; j++) {
            A[i][j] = num++;
        }
    }

    // 행과 열을 바꾸어 배열 B에 저장
    for (int i = 0; i < N1; i++) {
        for (int j = 0; j < N2; j++) {
            B[j][i] = A[i][j];
        }
    }

    // 배열 A 출력
    printf("--- 배열 A ---\n");
    for (int i = 0; i < N1; i++) {
        for (int j = 0; j < N2; j++) {
            printf("%2d ", A[i][j]);
        }
        printf("\n");
    }

    // 배열 B 출력
    printf("\n--- 배열 B ---\n");
    for (int i = 0; i < N2; i++) {
        for (int j = 0; j < N1; j++) {
            printf("%2d ", B[i][j]);
        }
        printf("\n");
    }

    return 0;
}