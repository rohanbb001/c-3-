#include <stdio.h>
#include <stdlib.h>

int main() {
    int N1, N2;
    printf("N1 X N2 행렬 크기 입력 (예: 5 5): ");
    scanf("%d %d", &N1, &N2);

    // 2차원 배열 동적 할당
    int** arr = (int**)malloc(sizeof(int*) * N1);
    for (int i = 0; i < N1; i++) {
        arr[i] = (int*)malloc(sizeof(int) * N2);
    }

    // 우, 하, 좌, 상 방향 벡터
    int dr[] = { 0, 1, 0, -1 };
    int dc[] = { 1, 0, -1, 0 };

    int r = 0, c = 0, dir = 0;

    // 초기화
    for (int i = 0; i < N1; i++)
        for (int j = 0; j < N2; j++) arr[i][j] = 0;

    for (int num = 1; num <= N1 * N2; num++) {
        arr[r][c] = num;

        int nr = r + dr[dir];
        int nc = c + dc[dir];

        // 벽에 부딪히거나 이미 숫자가 채워져 있다면 방향 전환
        if (nr < 0 || nr >= N1 || nc < 0 || nc >= N2 || arr[nr][nc] != 0) {
            dir = (dir + 1) % 4;
            nr = r + dr[dir];
            nc = c + dc[dir];
        }
        r = nr;
        c = nc;
    }

    // 출력
    for (int i = 0; i < N1; i++) {
        for (int j = 0; j < N2; j++) {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }

    // 메모리 해제
    for (int i = 0; i < N1; i++) free(arr[i]);
    free(arr);
    return 0;
}