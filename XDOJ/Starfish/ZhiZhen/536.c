#include<stdio.h>

void paint(int, int (*)[4], int *);

int main()
{
	int n,l[100][4];
	int result[300];
	int i;

	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&l[i][0],&l[i][1],&l[i][2],&l[i][3]);
	}

	paint(n,l,result);
	for(i=0;i<=result[0];i++)
	{
		printf("%d %d\n",result[i*2],result[i*2+1]);
	}

	return 0;
}

void paint(int n, int (*l)[4], int *result){
    int table[100][100],max = 0,check = 1;
    for(int i = 0;i < 100;i++){
        for(int j = 0;j < 100;j++){
            table[i][j] = 0;
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = l[i][1];j < l[i][3];j++){
            for(int k = l[i][0];k < l[i][2];k++){
                table[j][k]++;
            }
        }
    }
    for(int i = 0;i < 100;i++){
        for(int j = 0;j < 100;j++){
            if(max < table[i][j]){
                max = table[i][j];
            }
        }
    }
    for(int i = 0;i < 300;i++){
        result[i] = 0;
    }
    for(int k = max;k >= 0;k--){
        result[check-1] = k;
        for(int i = 0;i < 100;i++){
            for(int j = 0;j < 100;j++){
                if(table[i][j] == k){
                    result[check]++;
                }
            }
        }
        check += 2;
    }
}