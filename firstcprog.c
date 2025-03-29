#include <stdio.h>
int main(){
    int a[5] =(1,2,3,4,5);
    for (int i = 0; i < 5; i++)
    {
        if ((char) a[i] == '5')
        {
        printf("%d\n",a[i]);
        }
        else {
            printf("FAIL\n");
        }
    }
    return 0;
}