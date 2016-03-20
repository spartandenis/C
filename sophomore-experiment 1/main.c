#include <stdio.h>
#include <stdlib.h>
#define MaxNumberOfLevels 16
#define MaxLevel (MaxNumberOfLevels-1)
// newNodeOfLevel生成一个nodeStructure结构体，同时生成l个node *数组指针
#define newNodeOfLevel(l) (node)malloc(sizeof(struct nodeStructure)+(l)*sizeof(node *))

typedef struct polynode
{
    double coef;
    int exp;
    struct polynode *link;
} polynode, *list, *pointer;

typedef int position;

void init (list l);
void addtolist (double c, int e, list *back);
void showlist(list l);
list getinput();
list creat();
void change(list l);
void calculate(list l,float f);
void add(list l1,list l2);
void subtract (list l1,list l2);
list checkzero(list l2);
list multiply(list l1,list l2,list lx);
list deletepoint(list l, position pos );
list divisiona(list l1,list l2,list pww);
//list divisiona(list l1,list l2);



int main()
{

    int iii;
    do{

    printf("**************************************\n");
    printf("请输入相应的数字来进行相应的操作：\n");
    printf("1：降序排列、计算；\n2：加法；\n3：减法；\n4：乘法；\n5：除法； \n0：quit；\n");
    printf("**************************************\n");

    scanf("%d",&iii);

    switch(iii){

//--------------------------降序排列及计算某点值---------------------------
    case 1:{
        list l;
        init(l);
        printf("请输入多项式:");
        l=getinput();
        printf("\n您输入的多项式为：");
        showlist(l);
        change(l);
        printf("\n您输入的多项式降序排列后为：");
        showlist(l);
        printf("\n请输入您想计算在x点的多项式的值:");
        float f;
        scanf("%f",&f);
        printf("\n多项式在%f点的值为：",f);
        calculate(l,f);
        printf("\n");
        printf("\n");
    }
    break;


//--------------------------加法---------------------------
    case 2:{
        list l1,l2;
        init(l1);
        init(l2);
        printf("请输入您想相加的两个多项式中的第一个:");
        l1=getinput();
        printf("请输入您想相加的两个多项式中的第二个:");
        l2=getinput();
        printf("两个多项式相加为:");
        add(l1,l2);
        showlist(l2);
        printf("\n");
        printf("\n");
    }
    break;


//--------------------------减法---------------------------
    case 3:{
        list l3,l4;
        init(l3);
        init(l4);
        printf("请输入您想相减的两个多项式中的第一个:");
        l3=getinput();
        printf("请输入您想相减的两个多项式中的第二个:");
        l4=getinput();
        printf("两个多项式相减为:");
        subtract(l4,l3);
        l3=checkzero(l3);//相减后应将链表中系数为0的项去掉。
        showlist(l3);
        printf("\n");
        printf("\n");
    }
    break;


//--------------------------乘法---------------------------
    case 4:{
        list l5,l6,lx;
        init(l5);
        init(l6);
        init(lx);
        lx=creat();

        printf("请输入您想相乘的两个多项式中的第一个:");
        l5=getinput();
        printf("请输入您想相乘的两个多项式中的第二个:");
        l6=getinput();
        printf("两个多项式相乘为:");
        lx=multiply(l5,l6,lx);
        showlist(lx);
        printf("\n");
        printf("\n");
    }
    break;


//--------------------------除法---------------------------
    case 5:{
        list l7,l8,lza,lzb;
        init(l7);
        init(l8);
        init(lza);
        init(lzb);
        lza=creat();
        lzb=creat();
        list pww;
        init(pww);
        pww=creat();

        printf("请输入您想相除的两个多项式中的第一个:");
        l7=getinput();
        printf("请输入您想相除的两个多项式中的第二个:");
        l8=getinput();
        printf("两个多项式相除的余式为:");
        change(l7);
        change(l8);

        lza = divisiona(l7,l8,pww);
        showlist(lza);
        printf("\n");
        printf("\n");
    }
    break;


//--------------------------对删除的测试---------------------------
//    list l5;
//    init(l5);
//    printf("请输入:");
//    l5=getinput();
//    printf("请输入删除第几位:");
//    int poss=0;
//    scanf("%d",&poss);
//    l5=deletepoint(l5,poss);
//    printf("删除该位的链表为：");
//    showlist(l5);

    }

    }while(iii!=0);
    printf("\n---the end---\n");
}

//--------------------------main方法结束---------------------------

void init (list l)
{
    l = (list)malloc(sizeof(polynode));
    l->link = NULL;
}


list getinput()
{
    list first,back, abc;//abc指针用来去掉头结点。
    first=(list)malloc(sizeof(polynode));
    first->link=NULL;
    back = first;//首尾指针指向同一个结点。
    int count ;
    scanf("%d",&count);
    double coef;
    int exp;

    for(count; count>0; count--) //循环count次
    {
        scanf("%lf %d",&coef,&exp);
        addtolist(coef,exp,&back);
    }

    abc=first;
    first=first->link;
    free(abc);

    return first;
}


list creat()
{
    list first,back, abc;//abc指针用来去掉头结点。
    first=(list)malloc(sizeof(polynode));
    first->link=NULL;
    back = first;//首尾指针指向同一个结点。

    addtolist(0,0,&back);

    abc=first;
    first=first->link;
    free(abc);

    return first;
}


//加到链表的最末尾。
void addtolist (double c, int e, list *back)
{
    list p= (list)malloc(sizeof(polynode));
    p->coef=c;
    p->exp=e;
    p->link=NULL;

    (*back)->link=p;
    (*back)=p;
}


void showlist(list l)
{
    while(l)
    {
//        printf("执行一次showlist");
        printf("%lf %d ",l->coef,l->exp);
        l=l->link;
    }
    printf("\n");
}


//降序排列。
void change(list l)
{
    list p1= (list)malloc(sizeof(polynode));
    list p2= (list)malloc(sizeof(polynode));
    p1=l;p2=p1->link;
    int temp1;
    double temp2;

    while(p1)//利用冒泡排序法进行比较并交换节点中的元素。
    {
        p2=p1->link;
        while(p2)
        {
            if((p1->exp)<(p2->exp))
            {
                temp1=p1->exp;
                p1->exp=p2->exp;
                p2->exp=temp1;

                temp2=p1->coef;
                p1->coef=p2->coef;
                p2->coef=temp2;
            }
            p2=p2->link;
        }
        p1=p1->link;
    }
}

//计算多项式在某一点的值。
void calculate(list l,float f){
    float sum=0;
    list p= (list)malloc(sizeof(polynode));
    p=l;
    while(p){
        sum+=(p->coef)*pow(f,p->exp);
        p=p->link;
    }
    printf("%lf",sum);
}

//两个多项式相加。
void add(list l1,list l2){
    list p1= (list)malloc(sizeof(polynode));
    list p2= (list)malloc(sizeof(polynode));
    p1=l1;
    p2=l2;
    int count=0;
    while (p1){
        p2=l2;
        count=0;//count 用来确定l2中有没有与l1中的每一个元素相同的元素。
        while(p2){
            if((p1->exp)==(p2->exp)){
                p2->coef+=p1->coef;
                count++;
            }
            p2=p2->link;
        }
        if(count==0){//l1中的某个元素在l2中并没有出现过。
            list back= (list)malloc(sizeof(polynode));
            back=l2;
            while(back->link){
                back=back->link;
            }
            addtolist(p1->coef,p1->exp,&back);//将结果加至l2，最后输出的是l2。
        }
        p1=p1->link;
    }
}

//两个多项式相减。
//和加法相比只需加一个系数=0的讨论。
void subtract (list l1,list l2){
    list p1= (list)malloc(sizeof(polynode));
    list p2= (list)malloc(sizeof(polynode));
    p1=l1;
    p2=l2;
    int count=0;
    while (p1){
        p2=l2;
        count=0;//count 用来确定l2中有没有与l1中的每一个元素相同的元素。
        while(p2){
            if((p1->exp)==(p2->exp)){
                p2->coef-=p1->coef;
                count++;
            }
            p2=p2->link;
        }
        if(count==0){//l1中的某个元素在l2中并没有出现过。
            list back= (list)malloc(sizeof(polynode));
            back=l2;
            while(back->link){
                back=back->link;
            }
            addtolist((p1->coef)*(-1),p1->exp,&back);//将结果加至l2，最后输出的是l2。
        }
        p1=p1->link;
    }
}


//检查某个链表是否含有系数为0的项。
list checkzero(list l2){
    while(l2->coef==0){//这个while循环排除了头结点系数为空的可能。
        list p4= (list)malloc(sizeof(polynode));
        p4=l2;
        if(l2->link!=NULL){
            l2=l2->link;
        }else{
            printf("全部都减光啦！");
        }
        free(p4);
    }

    list p3= (list)malloc(sizeof(polynode));
    p3=l2;

    while(p3){
        if(p3->coef==0){
            list p5= (list)malloc(sizeof(polynode));//创建一个指针来找系数为0的结点的前一个。
            p5=l2;
            while(p5->link!=p3){//找到系数为0的结点的前一个。
                p5=p5->link;
            }
            if(p3->link==NULL){//如果是最后一个结点系数为0。
                p5->link=NULL;
            }else{//如果系数为0的结点不是最后一个结点。
                p5->link=p3->link;
            }
        }
        p3=p3->link;
    }
    return l2;
}

//两个多项式相乘。
list multiply(list l1,list l2,list lx){
    list p1= (list)malloc(sizeof(polynode));
    list p2= (list)malloc(sizeof(polynode));
    p1=l1;
    p2=l2;
    list l3= (list)malloc(sizeof(polynode));
    l3=lx;

    list back= (list)malloc(sizeof(polynode));
    back=l3;
    while(back->link){
        back=back->link;
//        printf("ggg");
    }

    while(p1){
//        printf("p1执行一次");
        while(p2){
//            printf("p2执行一次");
            addtolist((p1->coef)*(p2->coef),(p1->exp)+(p2->exp),&back);
            p2=p2->link;
        }
        p2=l2;
        p1=p1->link;
    }
    l3=l3->link;
    //下面考虑合并同类项的情况。

    list l4= (list)malloc(sizeof(polynode));
    l4=l3;
    list p3= (list)malloc(sizeof(polynode));
    list p4= (list)malloc(sizeof(polynode));
    p3=l4;
    p4=l4->link;

    while(p3->link!=NULL){
        list p5= (list)malloc(sizeof(polynode));
        p5=l4;
        int count=2;
        while(p5->link!=p3->link){
            count++;
            p5=p5->link;
        }
        while(p4){
            if((p3->exp)==(p4->exp)){
                p3->coef+=p4->coef;
//                printf("%d\n",count);//检验count的值。
                deletepoint(l4,count);
            }
            p4=p4->link;
            count++;
        }
        p3=p3->link;
        p4=p3->link;
    }
    //---------------分界线------

    return l4;
}


//删除链表中的第几号结点。
list deletepoint(list l, position pos ){
        list ppp= (list)malloc(sizeof(polynode));
        ppp=l;
        printf("\n");

    if(pos==1){
        list p1= (list)malloc(sizeof(polynode));
        p1=l;
        ppp=ppp->link;
        free(p1);
    }else if (pos==2){
        if(ppp->link->link){
            list p2= (list)malloc(sizeof(polynode));
            p2=ppp->link;
            ppp->link=ppp->link->link;
            free(p2);
        }else{
            ppp->link=NULL;
        }
    }else{
        list pcount= (list)malloc(sizeof(polynode));
        pcount=ppp;
        int count ;
        for(count =2;count<pos;count++){
            pcount=pcount->link;
        }

        list p3= (list)malloc(sizeof(polynode));
        p3=pcount->link;
        if(pcount->link->link){
            pcount->link=pcount->link->link;
        }else{
            pcount->link=NULL;
        }
        free(p3);
    }
    return ppp;
}


//两个多项式相除。
list divisiona(list l1,list l2,list pww){
    list pyu,p2,p4,t,temp;
//    p3->link=NULL;
//        p3=pww;
    double m1;
    int n1;

    //pyu用来存放余式
    pyu=(list)malloc(sizeof(polynode));
//    init(pyu);
//    pyu=creat();
    pyu->link=NULL;

    p2=pyu;

    p4=(list)malloc(sizeof(polynode));
    p4->link=NULL;


//    init(p4);
//    p4=creat();

    if(l2->link==NULL)//如果只有一个节点
    {
        while(l1->link)
        {
            m1=(l1->coef)/(l2->coef);
            n1=(l1->exp)-(l2->exp);
            addtolist(m1,n1,&p2);
            l1=l1->link;//遍历
        }
        if(l1->exp==0)
        {
//            printf("余式: ");
            p4->exp=0;
            p4->coef=l1->coef;
            p4->link=NULL;
            showlist(p4);
        }
        else
        {
//            printf("余式: ");
            p4->exp=(l1->exp)-(l2->exp);
            p4->coef=(l1->coef)/(l2->coef);
            p4->link=NULL;
            showlist(p4);
        }

        printf("两个多项式相除的商多项式为");
        pyu=pyu->link;
        return pyu;
    }

    do
    {
        double m2=(l1->coef)/(l2->coef);
        n1=(l1->exp)-(l2->exp);
        addtolist(m2,n1,&p2);
//printf("###########");
//showlist(p2);
//printf("\n\n");
//showlist(l2);
//printf("###########");
        pww=multiply(p2,l2,pww);
//showlist(pww);
        subtract(pww,l1);
        l1=checkzero(l1);
//printf("\n@@@@@@@@@@\n");
//showlist(l1);
        p4=l1;
    }
    while((p4->exp)>=(l2->exp));
//    printf("余式为:");
    showlist(p4);
    printf("两个多项式相除的商多项式为");
    pyu=pyu->link;
    return pyu;
}


