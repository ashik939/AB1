#include <stdio.h>

void heapify(int marks[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && marks[left] > marks[largest])
        largest = left;

    if (right < n && marks[right] > marks[largest])
        largest = right;

    if (largest != i)
    {
        int temp = marks[i];
        marks[i] = marks[largest];
        marks[largest] = temp;

        heapify(marks, n, largest);
    }
}

void heapSort(int marks[], int n)
{
    // Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(marks, n, i);

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--)
    {
        int temp = marks[0];
        marks[0] = marks[i];
        marks[i] = temp;

        heapify(marks, i, 0);
    }
}

int main()
{
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    int marks[n];

    printf("Enter student marks:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Student %d: ", i + 1);
        scanf("%d", &marks[i]);
    }

    printf("\nMarks Before Sorting:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", marks[i]);

    heapSort(marks, n);

    printf("\n\nMarks After Sorting (Ascending Order):\n");
    for (int i = 0; i < n; i++)
        printf("%d ", marks[i]);

    printf("\n");

    return 0;
}
