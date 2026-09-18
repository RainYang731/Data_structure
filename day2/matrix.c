#include<stdio.h>
#define Max 1000
typedef struct{
    int row;
    int col;
    int value;
} terms;

typedef struct{
    int r;int c;
} matrix;
void transport(terms *start,terms *finish,terms **avail,matrix **mp,matrix rc){
    int rowterm[Max] = {0};
    int startpos[Max] = {0};
    for(terms *i = start;i<finish;i++){
        rowterm[i->col]++;
    }
    startpos[0] = 0;
    for(int i=1;i < rc.c;i++){
        startpos[i] = rowterm[i-1]+startpos[i-1];
    }
    for(terms *i = start;i<finish;i++){
        terms *tmp = (*avail)+startpos[i->col];
        tmp->col = i->row;
        tmp->row = i->col;
        tmp->value = i->value;
        startpos[i->col]++; 
    }
    (*mp)->c = rc.r;(*mp)->r = rc.c;(*mp)++;
    (*avail) = (*avail) + (finish-start);
}
int main(){
    terms term[Max];
    int r,c,tmp;
    terms *start[Max],*trans[Max];matrix ma[Max];
    terms **ps = start,*avail = term;matrix *mp = ma;
    while(scanf("%d %d",&r,&c)){
        if(r==0 || c==0) break;
        *ps = avail;ps++;
        mp->r = r;mp->c = c;mp++;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                scanf("%d",&tmp);if(tmp == 0) continue;
                avail->row = i;
                avail->col = j;
                avail->value = tmp;
                avail++;
            }
        }
    }*ps = avail;ps++;
    printf("done\n");
    int op;
    while(scanf("%d",&op)){
        if(op==0) break;
        switch(op){
            case 1:
                int a;scanf("%d",&a);
                trans[a] = *ps;
                trans[ps-start] = start[a];
                transport(start[a],start[a+1],&avail,&mp,ma[a]);
                *ps = avail;ps++;
                break;
        }
    }
}