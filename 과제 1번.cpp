#include <stdio.h>

int main() {
	int arr[5][5] = { 0 };//전부 0응로 초기화
	int num = 1;

	for (int i = 0; i < 5; i++) {
		//모래시계모양ㅇ을 만들기 위한 시작과 끝 계산
		int start = (i < 3) ? i : 4 - i;
		int end = (i < 3) ? 4 - i : i;

		for (int j = start; j <= end; j++) {
			arr[i][j] = num++;
		}
	}

	//출력
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf(" % 2d", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}