#include<stdio.h>
int main()
{
    int i=0,max=1,pre,nxt,cnt=1;
    scanf("%d",&pre);
    if(pre==-1)
    {
        printf("Length is : 0");
    }
    else
    {
        while(1)
        {
            scanf("%d",&nxt);
            if(nxt==-1)
                break;
            if(pre<nxt)
                cnt+=1;
            else
            {
                max=(max>cnt)?max:cnt;
                cnt=1;
            }
            pre=nxt;
        }
        int max1=(max>cnt)?max:cnt;
        printf("Length is %d",max1);
    }
}