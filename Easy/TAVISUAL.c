#include <stdio.h>

int main(void)
{
        int T;
        scanf("%d", &T);
        while (T--) {
                int N, C, Q, L, R;
                scanf("%d %d %d", &N, &C, &Q);
                while (Q--) {
                        int lhs_pos, rhs_pos;
                        scanf("%d %d", &L, &R);
                        if (L <= C && C <= R) {
                                lhs_pos = C - L;
                                rhs_pos = R - C;
                                if (lhs_pos < rhs_pos) {
                                        C = R - lhs_pos;
                                } else if (rhs_pos < lhs_pos) {
                                        C = L + rhs_pos;
                                }
                        }
                }
                printf("%d\n", C);
        }
        return 0;
}
