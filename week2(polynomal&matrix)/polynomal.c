#include<stdio.h>

typedef struct{
    float coef;
    int expon;
} Node;

void print_poly(Node *start, Node *finish) {
    if (start == finish) {
        printf("0\n");
        return;
    }
    
    Node *p = start;
    while (p < finish) {
        if (p != start && p->coef > 0) {
            printf(" +");
        }
        
        printf("%.1f x^%d", p->coef, p->expon);
        p++;
    }
    printf("\n");
}

int compare(Node a,Node b){
    if(a.expon > b.expon) return 0;
    else if(a.expon < b.expon) return 1;
    else return 2;
}
void padd(Node *sa,Node *fa,Node *sb,Node *fb,Node **avail){
    while(sa < fa && sb < fb){
        switch(compare(*sa,*sb)){
            case 0:
                (*avail)->coef = sa->coef;
                (*avail)->expon = sa->expon;
                (*avail)++;sa++;
                break;
            case 1:
                (*avail)->coef = sb->coef;
                (*avail)->expon = sb->expon;
                (*avail)++;sb++;
                break;
            case 2:
                if(sa->coef + sb->coef != 0){
                    (*avail)->coef = sa->coef + sb->coef;
                    (*avail)->expon = sa->expon;
                    (*avail)++;
                }
                sa++;sb++;
                break;
        }
    }

    while(sa < fa){
        (*avail)->coef = sa->coef;
        (*avail)->expon = sa->expon;
        (*avail)++;sa++;
    }
    while(sb < fb){
        (*avail)->coef = sb->coef;
        (*avail)->expon = sb->expon;
        (*avail)++;sb++;
    }
    return;
}
int main(){
    int Max = 100;
    Node term[Max], *start[Max];
    Node *avail = term, **ps = start;
    *ps = term;ps++;
    float coef;int expon;
    while(scanf("%f %d",&coef,&expon)){
        if(coef == 0) break;
        avail->coef = coef;
        avail->expon = expon;
        avail++;
    }
    *ps = avail;ps++;
    while(scanf("%f %d",&coef,&expon)){
        if(coef == 0) break;
        avail->coef = coef;
        avail->expon = expon;
        avail++;
    }
    *ps = avail;ps++;
    printf("done\n");
    int ans;
    while(scanf("%d",&ans)){
        if(ans){
            int a,b;scanf("%d %d",&a,&b);
            padd(start[a],start[a+1],start[b],start[b+1],&avail);
            *ps = avail;ps++;
        }
        else break;
    }
    /*
    test
    print_poly(start[0],start[1]);
    print_poly(start[1],start[2]);
    print_poly(start[2],start[3]);
    */
    return 0;
}