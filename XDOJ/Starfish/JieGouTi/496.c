#include <stdio.h>
int main(){
    int w,h,angle;
    scanf("%d %d",&w,&h);
    int num[h][w];
    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            scanf("%d",&num[i][j]);
        }
    }
    scanf("%d",&angle);
        switch (angle){
        case 0:
            printf("%d %d\n",w,h);
            for(int i = 0;i < h;i++){
                for(int j = 0;j < w;j++){
                    printf("%d ",num[i][j]);
                }
                printf("\n");
            }
            break;
        case 90:
            printf("%d %d\n",h,w);
            for(int i = 0;i < w;i++){
                for(int j = h - 1;j >= 0;j--){
                    printf("%d ",num[j][i]);
                }
                printf("\n");
            }
            break;
        case 180:
            printf("%d %d\n",w,h);
            for(int i = h-1;i >= 0;i--){
                for(int j = w-1;j >= 0;j--){
                    printf("%d ",num[i][j]);
                }
                printf("\n");
            }
            break;
        case 270:
            printf("%d %d\n",h,w);
            for(int i = w - 1;i >= 0;i--){
                for(int j = 0;j <h;j++){
                    printf("%d ",num[j][i]);
                }
                printf("\n");
            }
            break;
    }
    return 0;
}