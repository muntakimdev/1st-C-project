#include<stdio.h>
int main(){

    while(1)
    {
        printf("1 for insert\n2 for update\n3 for delete\n4 for sort\n5 for searching\n6 for closing\n");
        int choice;
        scanf("%d",&choice);
        if(choice ==6)
        {
            printf("The program will close now!");
            break;
        }
        switch (choice)
        {
        case 1:
            { 
                int num;
                printf("Enter your preferred size: ");
                scanf("%d",&num);

               int num_array[num];
               printf("Enter the numbers one by one\n");

                for(int i = 0; i<=num; i++)
                {
                    scanf("%d",&num_array[i]);
                }
                printf("The numbers you have enterred are: ");
                for(int i = 0; i<=num;i++)
                { 
                    printf("%d ",num_array[i]);
                }
                printf("\n");
                break;
            }    
        
        default:
            break;
        }

    }



}