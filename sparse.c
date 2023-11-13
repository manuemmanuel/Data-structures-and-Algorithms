#include <stdio.h>
void main() {
    int row, column, i, j, array[50][50], k = 1, count = 0;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &row, &column);
    printf("Enter the matrix: ");
    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            scanf("%d", &array[i][j]);
        }
    }
    struct sparse {
        int rows;
        int columns;
        int value;
    } b[50];
    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            if (array[i][j] != 0) {
                b[k].rows = i;
                b[k].columns = j;
                b[k].value = array[i][j];
                k++;
                count++;
            }
        }
    }
    b[0].rows = row;
    b[0].columns = column;
    b[0].value = count;
    printf("The tuple matrix:\n");
    for (i = 0; i < count+1; i++) {
        printf("%d %d %d\n", b[i].rows, b[i].columns, b[i].value);
    }
}
