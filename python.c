#include<stdio.h>
#include<stdlib.h>
int main(){
    int *ptr = NULL;
    int num = 0;
    while(1)
    {
        printf("1 for insert\n2 for update\n3 for delete\n4 for sort\n5 for searching\n6 for closing\n");
        int choice;
        scanf("%d",&choice);
        if(choice ==6)
        {
            printf("The program will close now!");
            free(ptr);
            break;
        }
        switch (choice)
        {
        case 1:
            { 
                
                printf("Enter your preferred size: ");
                scanf("%d",&num);

                ptr = (int*) malloc(num*sizeof(int));
                if(ptr == NULL){
                    printf("Memory allocation failed");
                    return 1;
                }
                
                printf("Enter the numbers one by one\n");

                for(int i = 0; i<=num; i++)
                {
                    scanf("%d",&ptr[i]);
                }
                printf("The numbers you have enterred are: ");
                for(int i = 0; i<=num;i++)
                { 
                    printf("%d ",ptr[i]);
                }
                printf("\n");
                break;
            }    
        case 5:
        {
            int option;
            printf("Which number would you like to searc for?\n");
            printf("Type 1 for the number via input order\n2 for via index");
            scanf("%d",&option);
            if(option == 1)
            {
                int opt;
                scanf("%d",&opt);
                printf("%d\n",ptr[opt-1]);
            }
            
        }
        default:
            break;
        }

    }



}