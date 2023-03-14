#include<stdio.h>



struct page_mag{
    struct page
    { 
        char con[10];
    }
    page[10];
 }
p[10];


void paging();
int PROCESS_SIZE,PAGE_SIZE,TOTAL_PAGES;
int E,PAGE_FRAME[10],PM,LM;
int pf[10];


void paging(){

     void pagestore(),pagerestore();
    int ch;
    do
    {
        printf("\n1.pagstore\n2.pagrestore\n3.return to main\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        { 
            case 1:pagestore();break;
            case 2:pagerestore();break;
            default:continue;
        }}
        while(ch!=3);
}
void pagestore()
{
    int i,j,log_mem_size;

    //get logical memory size (odd only)
    do
    {
        printf("\nEnter logical memory size:");
        scanf("%d",&log_mem_size);
    }while(log_mem_size%2!=0);

    //get process size
    printf("\nenter process size:");
    scanf("%d",&PROCESS_SIZE);

    //enter page size
    do
    {
        printf("\n Enter page size:");
        scanf("%d",&PAGE_SIZE);
    }while(PAGE_SIZE%2!=0);


    TOTAL_PAGES=PROCESS_SIZE/PAGE_SIZE;

    if (PROCESS_SIZE%PAGE_SIZE !=0 )
            TOTAL_PAGES++;
        
   
    for(i=0;i<TOTAL_PAGES;i++)
        {
                    printf("\n enter content of page[%d]:",i);
                for(j=0;j<PAGE_SIZE;j++){
                    printf("\n Enter content[%d]:",j);
                    scanf("%s",p[i].page[j].con);
                    E++;

                    if(E==PAGE_SIZE)
                        break;
                }
        }

    
    printf("\nEnter the frame numbers corresponding to the page numbers:\n");

    for(i=0;i<TOTAL_PAGES;i++)
        {
        b1:
            printf("\n Enter the frame number of the page %d:",i);scanf("%d",&PAGE_FRAME[i]);
            // frame must be unique
            for(j=0;j<i;j++)
                if(PAGE_FRAME[j]==PAGE_FRAME[i])
                            goto b1;
        }

        printf("\n Physical memory:\n");

        for(i=0;i<TOTAL_PAGES;i++)
        {
            printf("\n content of page[%d]:",i);
            for(j=0;j<PAGE_SIZE;j++)
            {
                PM=PAGE_FRAME[i]*PAGE_SIZE+j;printf("\n frame no:%d",PAGE_FRAME[i]);
                printf("\n content[%d]:%s",PM,p[i].page[j].con);
                E++;
                if(E==PAGE_SIZE)
                    break;

            }  

        }
    

}


void pagerestore(){
int page,pn,po,fn;
    printf("Enter the logical memory address:");
    scanf("%d",&LM);
    pn=LM/PAGE_SIZE;
    po=LM%PAGE_SIZE;
    fn=pf[pn];
    PM=fn*PAGE_SIZE+po;
    printf("\n logical memory address:%d",LM);
    printf("\n page no:%d",pn);
    printf("\n frame no: %d",fn);
    printf("\n physical memory address: %d",PM);
    printf("\n content:%s",p[pn].page[po].con);
}
void main()
{

int ch;
// clrscr()
do
{
    printf("\tmemory management menu");
    printf("\n1.pageing\n4.exit\n");
    printf("\n Enter your choice:");
    scanf("%d",&ch);
    switch(ch)
    { 
        case 1:paging();break;
        case 4:return;
    }
    }
    while(ch!=4);
    }