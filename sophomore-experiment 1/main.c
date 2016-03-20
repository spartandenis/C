#include <stdio.h>
#include <stdlib.h>
#define MaxNumberOfLevels 16
#define MaxLevel (MaxNumberOfLevels-1)
// newNodeOfLevel����һ��nodeStructure�ṹ�壬ͬʱ����l��node *����ָ��
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
    printf("��������Ӧ��������������Ӧ�Ĳ�����\n");
    printf("1���������С����㣻\n2���ӷ���\n3��������\n4���˷���\n5�������� \n0��quit��\n");
    printf("**************************************\n");

    scanf("%d",&iii);

    switch(iii){

//--------------------------�������м�����ĳ��ֵ---------------------------
    case 1:{
        list l;
        init(l);
        printf("���������ʽ:");
        l=getinput();
        printf("\n������Ķ���ʽΪ��");
        showlist(l);
        change(l);
        printf("\n������Ķ���ʽ�������к�Ϊ��");
        showlist(l);
        printf("\n���������������x��Ķ���ʽ��ֵ:");
        float f;
        scanf("%f",&f);
        printf("\n����ʽ��%f���ֵΪ��",f);
        calculate(l,f);
        printf("\n");
        printf("\n");
    }
    break;


//--------------------------�ӷ�---------------------------
    case 2:{
        list l1,l2;
        init(l1);
        init(l2);
        printf("������������ӵ���������ʽ�еĵ�һ��:");
        l1=getinput();
        printf("������������ӵ���������ʽ�еĵڶ���:");
        l2=getinput();
        printf("��������ʽ���Ϊ:");
        add(l1,l2);
        showlist(l2);
        printf("\n");
        printf("\n");
    }
    break;


//--------------------------����---------------------------
    case 3:{
        list l3,l4;
        init(l3);
        init(l4);
        printf("�����������������������ʽ�еĵ�һ��:");
        l3=getinput();
        printf("�����������������������ʽ�еĵڶ���:");
        l4=getinput();
        printf("��������ʽ���Ϊ:");
        subtract(l4,l3);
        l3=checkzero(l3);//�����Ӧ��������ϵ��Ϊ0����ȥ����
        showlist(l3);
        printf("\n");
        printf("\n");
    }
    break;


//--------------------------�˷�---------------------------
    case 4:{
        list l5,l6,lx;
        init(l5);
        init(l6);
        init(lx);
        lx=creat();

        printf("������������˵���������ʽ�еĵ�һ��:");
        l5=getinput();
        printf("������������˵���������ʽ�еĵڶ���:");
        l6=getinput();
        printf("��������ʽ���Ϊ:");
        lx=multiply(l5,l6,lx);
        showlist(lx);
        printf("\n");
        printf("\n");
    }
    break;


//--------------------------����---------------------------
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

        printf("�����������������������ʽ�еĵ�һ��:");
        l7=getinput();
        printf("�����������������������ʽ�еĵڶ���:");
        l8=getinput();
        printf("��������ʽ�������ʽΪ:");
        change(l7);
        change(l8);

        lza = divisiona(l7,l8,pww);
        showlist(lza);
        printf("\n");
        printf("\n");
    }
    break;


//--------------------------��ɾ���Ĳ���---------------------------
//    list l5;
//    init(l5);
//    printf("������:");
//    l5=getinput();
//    printf("������ɾ���ڼ�λ:");
//    int poss=0;
//    scanf("%d",&poss);
//    l5=deletepoint(l5,poss);
//    printf("ɾ����λ������Ϊ��");
//    showlist(l5);

    }

    }while(iii!=0);
    printf("\n---the end---\n");
}

//--------------------------main��������---------------------------

void init (list l)
{
    l = (list)malloc(sizeof(polynode));
    l->link = NULL;
}


list getinput()
{
    list first,back, abc;//abcָ������ȥ��ͷ��㡣
    first=(list)malloc(sizeof(polynode));
    first->link=NULL;
    back = first;//��βָ��ָ��ͬһ����㡣
    int count ;
    scanf("%d",&count);
    double coef;
    int exp;

    for(count; count>0; count--) //ѭ��count��
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
    list first,back, abc;//abcָ������ȥ��ͷ��㡣
    first=(list)malloc(sizeof(polynode));
    first->link=NULL;
    back = first;//��βָ��ָ��ͬһ����㡣

    addtolist(0,0,&back);

    abc=first;
    first=first->link;
    free(abc);

    return first;
}


//�ӵ��������ĩβ��
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
//        printf("ִ��һ��showlist");
        printf("%lf %d ",l->coef,l->exp);
        l=l->link;
    }
    printf("\n");
}


//�������С�
void change(list l)
{
    list p1= (list)malloc(sizeof(polynode));
    list p2= (list)malloc(sizeof(polynode));
    p1=l;p2=p1->link;
    int temp1;
    double temp2;

    while(p1)//����ð�����򷨽��бȽϲ������ڵ��е�Ԫ�ء�
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

//�������ʽ��ĳһ���ֵ��
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

//��������ʽ��ӡ�
void add(list l1,list l2){
    list p1= (list)malloc(sizeof(polynode));
    list p2= (list)malloc(sizeof(polynode));
    p1=l1;
    p2=l2;
    int count=0;
    while (p1){
        p2=l2;
        count=0;//count ����ȷ��l2����û����l1�е�ÿһ��Ԫ����ͬ��Ԫ�ء�
        while(p2){
            if((p1->exp)==(p2->exp)){
                p2->coef+=p1->coef;
                count++;
            }
            p2=p2->link;
        }
        if(count==0){//l1�е�ĳ��Ԫ����l2�в�û�г��ֹ���
            list back= (list)malloc(sizeof(polynode));
            back=l2;
            while(back->link){
                back=back->link;
            }
            addtolist(p1->coef,p1->exp,&back);//���������l2������������l2��
        }
        p1=p1->link;
    }
}

//��������ʽ�����
//�ͼӷ����ֻ���һ��ϵ��=0�����ۡ�
void subtract (list l1,list l2){
    list p1= (list)malloc(sizeof(polynode));
    list p2= (list)malloc(sizeof(polynode));
    p1=l1;
    p2=l2;
    int count=0;
    while (p1){
        p2=l2;
        count=0;//count ����ȷ��l2����û����l1�е�ÿһ��Ԫ����ͬ��Ԫ�ء�
        while(p2){
            if((p1->exp)==(p2->exp)){
                p2->coef-=p1->coef;
                count++;
            }
            p2=p2->link;
        }
        if(count==0){//l1�е�ĳ��Ԫ����l2�в�û�г��ֹ���
            list back= (list)malloc(sizeof(polynode));
            back=l2;
            while(back->link){
                back=back->link;
            }
            addtolist((p1->coef)*(-1),p1->exp,&back);//���������l2������������l2��
        }
        p1=p1->link;
    }
}


//���ĳ�������Ƿ���ϵ��Ϊ0���
list checkzero(list l2){
    while(l2->coef==0){//���whileѭ���ų���ͷ���ϵ��Ϊ�յĿ��ܡ�
        list p4= (list)malloc(sizeof(polynode));
        p4=l2;
        if(l2->link!=NULL){
            l2=l2->link;
        }else{
            printf("ȫ������������");
        }
        free(p4);
    }

    list p3= (list)malloc(sizeof(polynode));
    p3=l2;

    while(p3){
        if(p3->coef==0){
            list p5= (list)malloc(sizeof(polynode));//����һ��ָ������ϵ��Ϊ0�Ľ���ǰһ����
            p5=l2;
            while(p5->link!=p3){//�ҵ�ϵ��Ϊ0�Ľ���ǰһ����
                p5=p5->link;
            }
            if(p3->link==NULL){//��������һ�����ϵ��Ϊ0��
                p5->link=NULL;
            }else{//���ϵ��Ϊ0�Ľ�㲻�����һ����㡣
                p5->link=p3->link;
            }
        }
        p3=p3->link;
    }
    return l2;
}

//��������ʽ��ˡ�
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
//        printf("p1ִ��һ��");
        while(p2){
//            printf("p2ִ��һ��");
            addtolist((p1->coef)*(p2->coef),(p1->exp)+(p2->exp),&back);
            p2=p2->link;
        }
        p2=l2;
        p1=p1->link;
    }
    l3=l3->link;
    //���濼�Ǻϲ�ͬ����������

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
//                printf("%d\n",count);//����count��ֵ��
                deletepoint(l4,count);
            }
            p4=p4->link;
            count++;
        }
        p3=p3->link;
        p4=p3->link;
    }
    //---------------�ֽ���------

    return l4;
}


//ɾ�������еĵڼ��Ž�㡣
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


//��������ʽ�����
list divisiona(list l1,list l2,list pww){
    list pyu,p2,p4,t,temp;
//    p3->link=NULL;
//        p3=pww;
    double m1;
    int n1;

    //pyu���������ʽ
    pyu=(list)malloc(sizeof(polynode));
//    init(pyu);
//    pyu=creat();
    pyu->link=NULL;

    p2=pyu;

    p4=(list)malloc(sizeof(polynode));
    p4->link=NULL;


//    init(p4);
//    p4=creat();

    if(l2->link==NULL)//���ֻ��һ���ڵ�
    {
        while(l1->link)
        {
            m1=(l1->coef)/(l2->coef);
            n1=(l1->exp)-(l2->exp);
            addtolist(m1,n1,&p2);
            l1=l1->link;//����
        }
        if(l1->exp==0)
        {
//            printf("��ʽ: ");
            p4->exp=0;
            p4->coef=l1->coef;
            p4->link=NULL;
            showlist(p4);
        }
        else
        {
//            printf("��ʽ: ");
            p4->exp=(l1->exp)-(l2->exp);
            p4->coef=(l1->coef)/(l2->coef);
            p4->link=NULL;
            showlist(p4);
        }

        printf("��������ʽ������̶���ʽΪ");
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
//    printf("��ʽΪ:");
    showlist(p4);
    printf("��������ʽ������̶���ʽΪ");
    pyu=pyu->link;
    return pyu;
}


