#include<stdio.h>
#include<math.h>
int main(){
  int n1; int n2; int choice;
 while(1){  
  printf("Chose 1 through 4 , \n 1 for addition\n 2 for subtraction\n 3 for multiplication\n 4 for division \n 5 to close the program\n");
  scanf("%d", &choice);
  if ( choice == 5){
    printf("Ending the program\n");
    break;
}
  printf("Enter two numbers\n");
  scanf("%d %d",&n1,&n2);  
 switch (choice) {
    case 1 :
        printf("Result: %d \n", n1 + n2 );
        break;
    case 2 :
        printf("Result: %d \n", n1 - n2);
        break;
    case 3 :
        printf("Result: %d \n", n1 * n2);
        break;
    case 4 :
          if ( n2 == 0){
            printf("Invalid input");
          } else{
            printf("Result: %d \n", n1 / n2);
          }
        break;
    default:
          printf("Invalid input \n");
          break;
       }
      }    
      printf("\n");
    

return 0;
    }
