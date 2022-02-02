#include <stdio.h>

int main()
{
    int a,b,c;

    scanf("%d %d %d", &a,&b,&c);
    int max;
    if(c < a){
        max = a;
        a = c;
        c = max;
    }
    if(c < b){
        max = b;
        b = c;
        b = max;
    }
    int t=(a*a)+(b*b);
    int g=c*c;
    if( a+b > c )
    {
        if(t == g)
        {
            printf("right triangle");
        }
        else if(t > g)
        {
            printf("acute triangle");
        }
        else
        {
            printf("obtuse triange");
        }
    }
    else
        printf("can not construct");
    printf("\n");
return 0;

}