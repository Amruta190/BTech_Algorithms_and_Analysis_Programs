#include<stdio.h>
int main()
{
        char set[10]="0123456789";
        char scratch;
        int lastpermutation = 0;
        int i, j, k, l;
        printf("%s\n",set);
        while (!lastpermutation)
        {
                //find largest j such that set[j] < set[j+1]; if no such j then done
                j = -1;
                for (i = 0; i < 10; i++)
                {
                        if (set[i+1] > set[i])
                        {
                                j = i;
                        }
                }
                if (j == -1)
                {
                        lastpermutation = 1;
                }
                if (!lastpermutation)
                {
                        for (i = j+1; i < 10; i++)
                        {
                                if (set[i] > set[j])
                                {
                                        l = i;
                                }
                        }
                        scratch = set[j];
                        set[j] = set[l];
                        set[l] = scratch;
                        //reverse j+1 to end
                        k = (9-j)/2; // number of pairs to swap
                        for (i = 0; i < k; i++)
                        {
                                scratch = set[j+1+i];
                                set[j+1+i] = set[9-i];
                                set[9-i] = scratch;
                        }
                        printf("%s\n",set);
             }
        }
        return 0;
}