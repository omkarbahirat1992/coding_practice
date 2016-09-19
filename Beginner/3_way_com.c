#include <stdio.h>
#include <math.h>

struct point {
    int x;
    int y;
};

int in_range(int range, struct point p1, struct point p2)
{
    int delta_y = p2.y - p1.y;
    int delta_x = p2.x - p1.x;
    if (sqrt((delta_x * delta_x) + (delta_y * delta_y)) <= range )
        return 1;
    return 0;
}

int main(void)
{
    int n;  //Number of test cases
    struct point chef, server, s_chef;
    int range;

    scanf("%d", &n);
    while (n--) {
        scanf("%d", &range);
        scanf("%d%d", &chef.x, &chef.y);
        scanf("%d%d", &server.x, &server.y);
        scanf("%d%d", &s_chef.x, &s_chef.y);
        if (in_range(range, chef, server) && in_range(range, chef, s_chef))
            printf("yes\n");
        else if (in_range(range, server, chef) && in_range(range, server, s_chef))
            printf("yes\n");
        else if (in_range(range, s_chef, chef) && in_range(range, s_chef, server))
            printf("yes\n");
        else
            printf("no\n");
    }
    
    return 0;
}
