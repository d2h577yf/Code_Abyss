#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
    char S1[101],S2[101];
    int j,cnt = 0,max = 0;
    double similarity;
    memset(S1,'\0',sizeof(S1));
    memset(S2,'\0',sizeof(S2));
    scanf("%[^\n]",S1);
    getchar();
    scanf("%[^\n]",S2);

    /*for(int i = 0;S1[i] != 0;i++){
        if(S1[i] >= 'a' && S1[i] <= 'z'){
            S1[i] -= 32;
        }
    }
    for(int i = 0;S2[i] != 0;i++){
        if(S2[i] >= 'a' && S2[i] <= 'z'){
            S2[i] -= 32;
        }
    }*/

    for(int i = 0;S1[i] != '\0';i++){
        S1[i] = tolower(S1[i]);
    }
    for(int i = 0;S2[i] != '\0';i++){
        S2[i] = tolower(S2[i]);
    }
    for(j = 0;S1[j] != 0;j++){
        for(int k = 0;S2[k] != 0;k++){
            cnt = 0;
            if(S1[j] == S2[k]){
                cnt++;
                for(int l = 1;S1[j + l] != 0 && S2[k + l] != 0;l++){
                    if(S1[j + l] == S2[k + l]){
                        cnt++;
                    }else{
                        break;
                    }
                }
                if(max < cnt){
                    max = cnt;
                }
            }
        }
    }

        similarity = 2.0 * (double)max / (double)(strlen(S1) + strlen(S2));

    printf("%.3f\n",similarity);

    return 0;
}