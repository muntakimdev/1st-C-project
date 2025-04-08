#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = NULL;
    int num = 0;
    int isArrayInitialized = 0;  // Flag to track if the array has been initialized

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Insert\n2. Update\n3. Delete\n4. Sort\n5. Search\n6. Exit\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 6) {
            printf("The program will close now!\n");
            free(ptr);
            break;
        }

        switch (choice) {
            case 1: { // Insert
                if (isArrayInitialized) {
                    printf("Array is already initialized. No need to insert again.\n");
                    break;
                }

                printf("Enter your preferred size: ");
                scanf("%d", &num);

                ptr = (int*) malloc(num * sizeof(int));
                if (ptr == NULL) {
                    printf("Memory allocation failed.\n");
                    return 1;
                }

                printf("Enter the numbers one by one:\n");
                for (int i = 0; i < num; i++) {
                    scanf("%d", &ptr[i]);
                }

                printf("The numbers you have entered are: ");
                for (int i = 0; i < num; i++) {
                    printf("%d ", ptr[i]);
                }
                printf("\n");

                isArrayInitialized = 1;  // Set the flag to true after first insertion
                break;
            }

            case 2: { // Update
                if (!isArrayInitialized) {
                    printf("Array is not initialized. Please insert first.\n");
                    break;
                }

                int index, newVal;
                printf("Enter index to update (0 to %d): ", num - 1);
                scanf("%d", &index);

                if (index < 0 || index >= num) {
                    printf("Invalid index.\n");
                    break;
                }

                printf("Enter new value: ");
                scanf("%d", &newVal);
                ptr[index] = newVal;

                printf("Updated array: ");
                for (int i = 0; i < num; i++) {
                    printf("%d ", ptr[i]);
                }
                printf("\n");
                break;
            }

            case 3: { // Delete
                if (!isArrayInitialized || num == 0) {
                    printf("No data to delete.\n");
                    break;
                }

                int index;
                printf("Enter index to delete (0 to %d): ", num - 1);
                scanf("%d", &index);

                if (index < 0 || index >= num) {
                    printf("Invalid index.\n");
                    break;
                }

                // Shift elements to the left
                for (int i = index; i < num - 1; i++) {
                    ptr[i] = ptr[i + 1];
                }

                num--; // Reduce array size by 1

                // Reallocate memory
                ptr = realloc(ptr, num * sizeof(int));

                printf("Element deleted. Updated array: ");
                for (int i = 0; i < num; i++) {
                    printf("%d ", ptr[i]);
                }
                printf("\n");
                break;
            }

            case 4: { // Sort
                if (!isArrayInitialized || num == 0) {
                    printf("Array is empty. Nothing to sort.\n");
                    break;
                }

                // Bubble sort
                for (int i = 0; i < num - 1; i++) {
                    for (int j = 0; j < num - i - 1; j++) {
                        if (ptr[j] > ptr[j + 1]) {
                            int temp = ptr[j];
                            ptr[j] = ptr[j + 1];
                            ptr[j + 1] = temp;
                        }
                    }
                }

                printf("Sorted array: ");
                for (int i = 0; i < num; i++) {
                    printf("%d ", ptr[i]);
                }
                printf("\n");
                break;
            }

            case 5: { // Search
                if (!isArrayInitialized || num == 0) {
                    printf("Array is empty. Insert data first.\n");
                    break;
                }

                int option;
                printf("Search by:\n1. Input order (1-based)\n2. Index (0-based)\n");
                scanf("%d", &option);

                int opt;
                printf("Enter the position: ");
                scanf("%d", &opt);

                if (option == 1) {
                    if (opt < 1 || opt > num) {
                        printf("Invalid position.\n");
                    } else {
                        printf("Number at position %d is %d\n", opt, ptr[opt - 1]);
                    }
                } else if (option == 2) {
                    if (opt < 0 || opt >= num) {
                        printf("Invalid index.\n");
                    } else {
                        printf("Number at index %d is %d\n", opt, ptr[opt]);
                    }
                } else {
                    printf("Invalid search option chosen.\n");
                }

                break;
            }

            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    }

    return 0;
}
