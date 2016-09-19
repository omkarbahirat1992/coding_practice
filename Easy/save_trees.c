#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct tagCartPoint {
    int x, y;
}CartPointType;

typedef struct tagPolePoint {
    int r;      //Radius
    int  theta; //angle from x-axis
}PolePointType;

void accept_coordinates(CartPointType *CartPlist, int n)
{
    int i;
    for (i = 0; i < n ; i++) {
        scanf("%d%d", &CartPlist[i].x, &CartPlist[i].y);
    }
}

void prepare_Poler_coordinates(CartPointType *CartPlist, PolePointType *PolePlist, int n)
{
        int i;
/*        printf("tan-1(1) = %f\n", atan(1));
        printf("tan(0.785398) = %g\n", tan(0.785398));
*/
        for (i = 0; i < n; i++) {
                PolePlist->r = sqrt((CartPlist->x*CartPlist->x) + (CartPlist->y * CartPlist->y));              
                PolePlist->theta = atan(CartPlist->y / CartPlist->x);
        }

}
//    prepare_sorted_coordinates(CartPlist, PolePlist, n);
int calculate_area(CartPointType *CartPlist, int n)
{
    int i, area = 0, j = n - 1;
    for (i = 0; i < n; i++) {
//        fprintf(stdout, "x1 = %d, y1 = %d\n", CartPlist[i].x, Plist[i].y);
//        fprintf(stdout, "x2 = %d, y2 = %d\n\n", CartPlist[j].x, Plist[j].y);
        area += (CartPlist[j].y - CartPlist[i].y) * (CartPlist[j].x + CartPlist[i].x);
//        fprintf(stdout, "area = %d\n", area);
        j = i;
    }
//    area /= 2;
    return area;
}

int main(void)
{
    CartPointType *CartPlist = NULL;
    PolePointType *PolePlist = NULL;
    int n;
    printf("Enter number of Points:- \n");
    scanf("%d", &n);
    CartPlist = (CartPointType*)malloc(n * sizeof(CartPointType));
    if (CartPlist == NULL) {
        fprintf(stderr, "Error in memory allocation\n");
        exit(-1);
    }
    PolePlist = (PolePointType*)malloc(n * sizeof(PolePointType));
    if (PolePlist == NULL) {
        fprintf(stderr, "Error in memory allocation\n");
        exit(-1);
    }
    accept_coordinates(CartPlist, n);
    prepare_Poler_coordinates(CartPlist, PolePlist, n);
//    prepare_sorted_coordinates(CartPlist, PolePlist, n);
//    fprintf(stdout, "area = %d\n", calculate_area(CartPlist, n));
    fprintf(stdout, "Twice area = %d\n", calculate_area(CartPlist, n));
    free(CartPlist);
    return 0;
}
