//
//  main.cpp
//  Karp
//
//  Created by Peeraphat Komolruchinonth on 17/9/18.
//  Copyright © 2018 Peeraphat Komolruchinonth. All rights reserved.
//

#include <iostream>
#define REHASH(a,b,h)((((h)-(a)*d)<<1)+(b))
void KR(char *x,int m,char *y,int n);
using namespace std;
int main(int argc, const char * argv[]) {
    KR("ab",2,"bababc",6);
    return 0;
}
void KR(char *x,int m,char *y,int n)
{
    int d,hx,hy,i,j;
    //Preprocessing
    
    for(d=i=1;i<m;++i)
    {
        d=(d<<1);
        printf("d=%d\n",d);
    }
    for(hy=hx=i=0;i<m;++i)
    {
        hx = ((hx<<1)+x[i]);
        printf("hx = %d and x[%d] = %d\n",hx,i,x[i]);
        hy = ((hy<<1)+y[i]);
        printf("hy = %d and y[%d] = %d\n",hy,i,y[i]);
    }
    //Searching
    j=0;
    while(j <= n-m)
    {
        if(hx == hy && memcmp(x,y + j,m)==0)
            printf("Found At : %d\n",j);
        hy = REHASH(y[j],y[j+m],hy);
        j++;
    }
}
