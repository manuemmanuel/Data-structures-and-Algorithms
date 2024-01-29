#include<stdio.h>
#include<stdlib.h>

void main() {
    int num_terms_poly1, num_terms_poly2, i, coefficient, exponent;
    
    struct Node {
        int coef;
        int expo;
        struct Node* link;
    } *result_head = NULL, *poly1_head = NULL, *poly2_head = NULL, *result_ptr = NULL, *poly1_ptr = NULL, *poly2_ptr = NULL, *temp = NULL;

    printf("Enter the number of terms in polynomial 1:\n");
    scanf("%d", &num_terms_poly1);

    printf("Enter the number of terms in polynomial 2:\n");
    scanf("%d", &num_terms_poly2);

    if (num_terms_poly1 != 0)
        printf("Enter the terms of polynomial 1 in descending order:\n");
    for (i = 0; i < num_terms_poly1; i++) {
        printf("Enter the coefficient of term %d: ", i + 1);
        scanf("%d", &coefficient);
        printf("Enter the exponent of term %d: ", i + 1);
        scanf("%d", &exponent);

        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->coef = coefficient;
        temp->expo = exponent;
        temp->link = NULL;

        if (poly1_head == NULL) {
            poly1_head = temp;
            poly1_ptr = temp;
        }
        else {
            poly1_ptr->link = temp;
            poly1_ptr = temp;
        }
    }

    if (num_terms_poly2 != 0)
        printf("Enter the terms of polynomial 2 in descending order:\n");
    for (i = 0; i < num_terms_poly2; i++) {
        printf("Enter the coefficient of term %d: ", i + 1);
        scanf("%d", &coefficient);
        printf("Enter the exponent of term %d: ", i + 1);
        scanf("%d", &exponent);

        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->coef = coefficient;
        temp->expo = exponent;
        temp->link = NULL;

        if (poly2_head == NULL) {
            poly2_head = temp;
            poly2_ptr = temp;
        }
        else {
            poly2_ptr->link = temp;
            poly2_ptr = temp;
        }
    }

    printf("First polynomial: ");
    poly1_ptr = poly1_head;
    while (poly1_ptr != NULL) {
        if (poly1_ptr->link == NULL)
            printf("%dX^%d", poly1_ptr->coef, poly1_ptr->expo);
        else
            printf("%dX^%d + ", poly1_ptr->coef, poly1_ptr->expo);
        poly1_ptr = poly1_ptr->link;
    }
    printf("\n");

    printf("Second polynomial: ");
    poly2_ptr = poly2_head;
    while (poly2_ptr != NULL) {
        if (poly2_ptr->link == NULL)
            printf("%dX^%d", poly2_ptr->coef, poly2_ptr->expo);
        else
            printf("%dX^%d + ", poly2_ptr->coef, poly2_ptr->expo);
        poly2_ptr = poly2_ptr->link;
    }
    printf("\n");

    // Adding polynomials
    poly1_ptr = poly1_head;
    poly2_ptr = poly2_head;
    while (poly1_ptr != NULL && poly2_ptr != NULL) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        if (poly1_ptr->expo == poly2_ptr->expo) {
            temp->coef = poly1_ptr->coef + poly2_ptr->coef;
            temp->expo = poly1_ptr->expo;
            temp->link = NULL;
            poly1_ptr = poly1_ptr->link;
            poly2_ptr = poly2_ptr->link;
        }
        else if (poly1_ptr->expo > poly2_ptr->expo) {
            temp->coef = poly1_ptr->coef;
            temp->expo = poly1_ptr->expo;
            temp->link = NULL;
            poly1_ptr = poly1_ptr->link;
        }
        else {
            temp->coef = poly2_ptr->coef;
            temp->expo = poly2_ptr->expo;
            temp->link = NULL;
            poly2_ptr = poly2_ptr->link;
        }
        if (result_head == NULL) {
            result_head = temp;
            result_ptr = temp;
        }
        else {
            result_ptr->link = temp;
            result_ptr = temp;
        }
    }

    // Adding remaining terms of polynomial 1
    while (poly1_ptr != NULL) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->coef = poly1_ptr->coef;
        temp->expo = poly1_ptr->expo;
        temp->link = NULL;
        poly1_ptr = poly1_ptr->link;
        if (result_head == NULL) {
            result_head = temp;
            result_ptr = temp;
        }
        else {
            result_ptr->link = temp;
            result_ptr = temp;
        }
    }

    // Adding remaining terms of polynomial 2
    while (poly2_ptr != NULL) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->coef = poly2_ptr->coef;
        temp->expo = poly2_ptr->expo;
        temp->link = NULL;
        poly2_ptr = poly2_ptr->link;
        if (result_head == NULL) {
            result_head = temp;
            result_ptr = temp;
        }
        else {
            result_ptr->link = temp;
            result_ptr = temp;
        }
    }

    // Displaying resultant polynomial
    printf("Resultant polynomial: ");
    result_ptr = result_head;
    while (result_ptr != NULL) {
        if (result_ptr->link == NULL)
            printf("%dX^%d", result_ptr->coef, result_ptr->expo);
        else
            printf("%dX^%d + ", result_ptr->coef, result_ptr->expo);
        result_ptr = result_ptr->link;
    }
    printf("\n");

    // Freeing memory
    while (poly1_head != NULL) {
        temp = poly1_head;
        poly1_head = poly1_head->link;
        free(temp);
    }
    while (poly2_head != NULL) {
        temp = poly2_head;
        poly2_head = poly2_head->link;
        free(temp);
    }
    while (result_head != NULL) {
        temp = result_head;
        result_head = result_head->link;
        free(temp);
    }
}
