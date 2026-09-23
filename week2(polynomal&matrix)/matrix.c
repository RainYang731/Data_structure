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
        tmp->row = i->col;
        tmp->col = i->row;
        tmp->value = i->value;
        startpos[i->col]++; 
    }
    (*mp)->c = rc.r;(*mp)->r = rc.c;(*mp)++;
    (*avail) = (*avail) + (finish-start);
}

int compare(terms *a,terms *b){
    if(a->row > b->row) return 1;
    if(a->row < b->row) return 2;

    if(a->col > b->col) return 1;
    if(a->col < b->col) return 2;
    return 3;
}
void add(terms *sa,terms *fa,terms *sb,terms *fb,terms **avail){
    while(sa < fa && sb < fb){
        switch(compare(sa,sb)){
            case 1:
                *(*avail) = *sb;
                sb++;(*avail)++;
                break;
            case 2:
                *(*avail) = *sa;
                sa++;(*avail)++;
                break;
            case 3:
                if(sa->value+sb->value == 0){
                    sa++;sb++;
                    break;
                }
                *(*avail) = *sa;
                (*avail)->value = sa->value+sb->value;
                sa++;sb++;(*avail)++;
                break;
        }
    }
    while(sa < fa){
        **avail = *sa;sa++;(*avail)++;
    }
    while(sb < fb){
        **avail = *sb;sb++;(*avail)++;
    }
}
void mutiply(terms *sa,terms *fa,terms *sb,terms *fb,terms **avail){
    terms *tmpa,*tmpb,*nb,*na;int value,col;
    while(sa < fa){
        tmpa = sa + 1;
        while(tmpa < fa && tmpa->row == sa->row) tmpa++;
        nb = sb;
        while(nb < fb){
            na = sa;value = 0;
            tmpb = nb + 1;
            col = nb->row;
            while(tmpb < fb && tmpb->row == nb->row) tmpb++;
            while(na < tmpa && nb < tmpb){
                if(na->col < nb->col) na++;
                else if(na->col > nb->col) nb++;
                else{
                    value = value + (na->value*nb->value);
                    na++;nb++;
                }
            }
            if(value){
                (*avail)->row = sa->row;
                (*avail)->col = col;
                (*avail)->value = value;
                (*avail)++;
            }
            nb = tmpb;
        }
        sa = tmpa;
    }
}
int main(){
    terms term[Max];
    int r,c,tmp;
    terms *start[Max],*trans[Max];matrix ma[Max];
    terms **ps = start,*avail = term;matrix *mp = ma;
    for(int i=0; i<Max; i++){
        trans[i] = NULL;
    }
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
            case 1:{
                int a;scanf("%d",&a);
                if(trans[a] != NULL) break;
                trans[a] = *ps;
                trans[ps-start] = start[a];
                transport(start[a],start[a+1],&avail,&mp,ma[a]);
                *ps = avail;ps++;
                break;
            }
            case 2:{
                int a,b;scanf("%d %d",&a,&b);
                if(ma[a].c != ma[b].c || ma[a].r != ma[b].r){
                    printf("no\n");break;
                }
                add(start[a],start[a+1],start[b],start[b+1],&avail);
                *ps = avail;ps++;*mp = ma[a];mp++;
                break;
            }
            case 3:{
                //預設轉置過
                int a,b;scanf("%d %d",&a,&b);
                if(ma[a].c != ma[b].c){
                    printf("no\n");break;
                }
                mutiply(start[a],start[a+1],start[b],start[b+1],&avail);
                *ps = avail;ps++;
                mp->r = ma[a].r;mp->c = ma[b].r;mp++;
            }
        }
    }
}