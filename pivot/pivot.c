#include <stdio.h>

#define LEFT    1
#define RIGHT   2
#define NONE    0

int PivotNumber(int *ptr)
{
    int lacc, racc;
    int l, r, nb;
    int direction;
    
    lacc = racc = 0;
    l = 0;
    nb = ptr[0];
    ptr++; // skip nbElement
    r = nb - 1 ;
    
    direction = NONE;
    while (nb > 0) {
        // Accumulate
        if(direction == NONE || direction == LEFT  ) lacc += ptr[l];
        if(direction == NONE || direction == RIGHT  ) racc += ptr[r];
                
        if(lacc <= racc) {
            direction = LEFT;
            l++;
            //fprintf(stdout, "Left[%d]<=Right[%d]--[%d/%d/%d]\n", lacc, racc, l, nb, r-l);
        } else {
            direction = RIGHT;
            r--;
            //fprintf(stdout, "Left[%d]>Right[%d]--[%d/%d/%d]\n", lacc, racc, r, nb, r-l);
        }
        if(( r - l) <= 1) {
            if (lacc == racc) {
                return l;
            } else {
                break;
            }
        }
    }
    return -1;
}

int main(int argv, char **argc)
{
    //int in[] = { 7, 1, 5 ,2, 16, 2, 2, 4 }; // 3
    //int in[] = { 0 }; // -1
    //int in[] = { 2, 0, 0 }; // any index
    //int in[] = { 5, 3, 5 ,6 ,7 ,7 }; // hum ...
    //int in[] = { 4, 1, 2, 2, 1}; // -1
    int in[] = { 5, 1, 2, 666, 2, 1}; // 3
    fprintf(stdout, "Result[%d]\n", PivotNumber(in));
}
