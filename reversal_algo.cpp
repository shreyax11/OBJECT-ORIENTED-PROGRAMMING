/*Reversal Algorithm.........
The reversal algorithm is a method used to:
1.Reverse an array
2.Rotate an array left or right
by repeatedly reversing parts of the array.
It works in-place, so no extra array is used.
*/
#include <stdio.h>

/* Function to reverse array from start to end */
void reverse(int arr[], int start, int end) 
{
    while (start < end) 
    { 
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

/* Function to display array */
void display(int arr[], int n) 
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* Left rotation */
void leftRotate(int arr[], int n, int k) 
{
    k = k % n;
    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);
    reverse(arr, 0, n - 1);
}

/* Right rotation */
void rightRotate(int arr[], int n, int k) 
{
    k = k % n;
    reverse(arr, n - k, n - 1);
    reverse(arr, 0, n - k - 1);
    reverse(arr, 0, n - 1);
}

int main() 
{
    int arr[100], n, choice, k, l, r;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    while (1) 
    {
        printf("\n---- MENU ----\n");
        printf("1. Reverse Entire Array\n");
        printf("2. Left Rotate Array \n");
        printf("3. Right Rotate Array \n");
        printf("4. Reverse Sub-array \n");
        printf("5. Display Array \n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                reverse(arr, 0, n - 1);
                printf("Array reversed successfully.\n");
                break;
            case 2:
                printf("Enter rotation count k: ");
                scanf("%d", &k);
                leftRotate(arr, n, k);
                printf("Left rotation done.\n");
                break;
            case 3:
                printf("Enter rotation count k: ");
                scanf("%d", &k);
                rightRotate(arr, n, k);
                printf("Right rotation done.\n");
                break;
            case 4:
                printf("Enter starting index: ");
                scanf("%d", &l);
                printf("Enter ending index: ");
                scanf("%d", &r);
                //Reversing only a selected part of the array, not the full array.
                if (l >= 0 && r < n && l < r) 
                {
                    reverse(arr, l, r);
                    printf("Sub-array reversed.\n");
                } else 
                {
                    printf("Invalid indices!\n");
                }
                break;
            case 5:
                printf("Current Array: ");
                display(arr, n);
                break;
            case 6:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
