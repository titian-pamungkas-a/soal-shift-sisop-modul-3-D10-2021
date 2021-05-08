#include <stdio.h>

int main(){
	int i, j, k, l, sum=0;
	int a[4][3], b[3][6], c[4][6];
	for (i=0;i<4;i++){
		for (j=0;j<3;j++){
			scanf("%d", &a[i][j]);
		}
	}
	printf("\n");
	for (k=0;k<3;k++){
		for (l=0;l<6;l++){
			scanf("%d", &b[k][l]);
		}
	}
	printf("\n");
	for (i=0;i<4;i++){
		for (j=0;j<6;j++){
			for (k=0;k<3;k++){
				sum += a[i][k]*b[k][j];
			}
			c[i][j] = sum;
			sum = 0;
		}
	}
	for (i=0;i<4;i++){
		for (j=0;j<6;j++){
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
	return 0;
}


