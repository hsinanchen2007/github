/* File name: Critical.cpp */
/* August 2017 */

#include <stdio.h>
#include <stdlib.h>

#define MAXV  100    /*最大節點數*/
#define MAX(x, y) (x < y ) ? y : x
#define MIN(x, y) (x > y ) ? y : x
#define empty -1

/*相鄰節點資料結構*/
typedef struct nodeTag {
    int vertex;
    int duration;
    struct nodeTag *link;
}  Node;

/*相鄰串列頭資料結構*/
typedef struct headnodeTag {
    int count;
    Node *link;
}  HeadNode;

struct Stackstruct {
    int top;
    int item[MAXV+1];
};

class Critical {
private:
    HeadNode *adjlist1[MAXV+1];    /*相鄰串列*/
    HeadNode *adjlist2[MAXV+1];    /*反相鄰串列*/
    struct Stackstruct Stack1 = { empty };
    struct Stackstruct Stack2 = { empty };
    int N;   /*頂點總數*/
    
    /*起始頂點, 終點頂點, 最早及最晚時間*/
    int source, sink, ES[MAXV+1], LC[MAXV+1];
    int CriticalNode[MAXV+1] , nodeCount, pathCount;
public:
    Critical();
    void initialES();
    void initialLC();
    void buildAdjlist();
    void showAdjlist(HeadNode *[]);
    void ToplogicalSort( HeadNode *[], int []);
    void printSteps(int [], int);
    void printCriticalNode();
    void printCriticalPath();
    void printESLC();
    void printPathNode(Node *, int);
    void Push(struct Stackstruct *, int );
    int  Pop(struct Stackstruct * );
};

Critical::Critical() {
    buildAdjlist();
    showAdjlist(adjlist1);          /*顯示相鄰串列*/
    initialES();                    /*起始ES(最早時間)*/
    ToplogicalSort(adjlist1, ES);   /*以拓排序法求出ES*/
    initialLC();                    /*起始LC(最晚時間)*/
    showAdjlist(adjlist2);          /*顯示反相鄰串列*/
    ToplogicalSort(adjlist2, LC);   /*以拓排序法求出LC*/
    printESLC();                     /*列出最早及最晚時間*/
    printCriticalNode();           /*列出臨界點*/
    printCriticalPath();           /*列出臨路徑*/
}

void Critical::buildAdjlist()
{
    FILE *fptr;
    int vi, vj, w;
    Node *node;
    fptr = fopen("critical.dat", "r");
    if ( fptr == NULL ) {
        perror("critical.dat");
        getchar();
        exit(1);
    }
    fscanf(fptr, "%d", &N);
    /*起始相鄰串列, count為前行者的數目 */
    for ( vi = 1; vi <= N; vi++){
        adjlist1[vi] = (HeadNode *)malloc(sizeof(HeadNode));
        adjlist2[vi] = (HeadNode *)malloc(sizeof(HeadNode));
        adjlist1[vi]->count = 0;
        adjlist2[vi]->count = 0;
        adjlist1[vi]->link = NULL;
        adjlist2[vi]->link = NULL;
    }
    /* 讀取vi到vj的權w(duration)並串至相鄰串列及反相鄰串列 */
    while( fscanf(fptr, "%d %d %d", &vi, &vj, &w) !=EOF){
        node = (Node *)malloc(sizeof(Node));
        node->vertex = vj;
        node->duration = w;
        node->link = adjlist1[vi]->link;
        adjlist1[vi]->link = node;
        adjlist1[vj]->count++;      /*前行者數加1*/
        node = (Node *)malloc(sizeof(Node));
        node->vertex = vi;
        node->duration = w;         node->link = adjlist2[vj]->link;
        adjlist2[vj]->link = node;
        adjlist2[vi]->count++;      /*前行者數加1*/
    }
    fclose(fptr);
    /*找出開始頂點*/
    for (vi =1; vi <= N; vi++ )
        if ( adjlist1[vi]->count == 0 ){
            source = vi;
            break;
        }
    /*找出結束結點*/
    for ( vi = 1;vi <= N; vi++ )
        if ( adjlist1[vi]->link == NULL ){
            sink = vi;
            break;
        }
}

/*顯示相鄰串列函數*/
void Critical::showAdjlist(HeadNode *adjlist[])
{
    int v;
    Node *ptr;
    
    /*判斷為相鄰串列adjlist1或反相鄰串列adjlist2*/
    if ( adjlist == adjlist1)
        puts("\nThe adjacency lists [adjlist1] of the Graph");
    else
        puts("\n\nThe inverse adjaccny list[adjlist2]of the Graph");
    puts("Headnodes    adjacency nodes");
    puts("  /count        /duration   ");
    puts("------------------------------");
    for (v = 1; v <= N; v++){
        printf("V%d: %d", v, adjlist[v]->count);
        ptr = adjlist[v]->link;
        while ( ptr != NULL ){
            printf(" --> V%d(%d)", ptr->vertex, ptr->duration);
            ptr = ptr->link;
        }
        printf("\n");
    }
}

/*以拓排序法計算最早時間(ES)及最晚時間(LC)*/
void Critical::ToplogicalSort(HeadNode *adjlist[], int ESLC[])
{
    int vi, vj , k, dur;
    Node *ptr;
    
    /*將沒有前行者的頂點推入堆疊*/
    for ( vi = 1; vi <= N; vi++ )
        if ( adjlist[vi]->count == 0 )
            Push(&Stack1, vi);
    printSteps(ESLC, 0);   /*列出堆疊及ESLC狀況*/
    for ( k=1; k<= N; k++ ){
        if (  Stack1.top == empty ){
            printf("\nCyclic Path found....\n");
            getchar();
            exit(1);
        }
        /*從堆疊彈出頂點*/
        vi = Pop(&Stack1);
        ptr = adjlist[vi]->link;  /*ptr指向vi的相鄰邊串列*/
        while ( ptr != NULL ){
            vj = ptr->vertex;     /*vj為vi的立即後行者*/
            dur = ptr->duration;
            adjlist[vj]->count--;  /*vj 前行者數減1*/
            if ( adjlist[vj]->count == 0 )
                Push(&Stack1, vj);
            if ( adjlist == adjlist1 ) /*判斷計算ES或LC*/
                ESLC[vj] = MAX(ESLC[vj], ESLC[vi]+dur);
            else
                ESLC[vj] = MIN(ESLC[vj], ESLC[vi]-dur);
            ptr = ptr->link;
        }
        printSteps(ESLC, vi);
    }
}

/*顯示目前堆疊狀況及ES或LC值*/
void Critical::printSteps(int ESLC[], int v)
{
    int i;
    
    if ( v == 0 ){
        printf("\nComputation of ESLC :\n");
        printf("----------------------\n");
        printf("ESLC[N]  : ");
        for (i = 1;i <= N; i++ ) printf(" [%d]", i);
        printf("     Current Stack");
        printf("\ninitial   :");
    }
    else
        printf("\nPopout V%d :", v);
    for ( i = 1; i <= N; i++ )
        printf(" %3d", ESLC[i]);
    printf("     ");
    for ( i =0; i <= Stack1.top; i++ )
        printf(" %d, ", Stack1.item[i]);
}

/*顯示各頂點的最早時間(ES)及早晚時間(LC)值*/
void Critical::printESLC()
{
    int i;
    
    printf("\n");
    for ( i = 1; i<= N; i++ )
        printf("\nES(%d) = %3d   LC(%d) = %3d ES  - LC = %3d",
               i, ES[i], i, LC[i], ES[i] - LC[i]);
}

/*列出臨界點*/
void Critical::printCriticalNode()
{
    int v;
    
    for ( v =1; v<= N;v++ )
        if ( LC[v] == ES[v] )    /*當LC == ES 時頂點為臨界點*/
            CriticalNode[++nodeCount] = v;
    printf("\n\nThe Critical Nodes of the Graph :\n");
    for ( v = 1; v<= nodeCount; v++ )
        printf("%d, ", CriticalNode[v]);
}

/*列出界路徑*/
void Critical::printCriticalPath()
{
    printf("\n\nThe Critical Paths of the Graph :");
    /*從起始頂點開始找尋臨界路徑*/
    printPathNode(adjlist1[source]->link, source);
}

void Critical::printPathNode(Node *ptr, int v)
{
    int  i;
    /* 判斷相鄰頂點是否為臨界點，將臨界點推入堆疊
        並從該臨界點繼續遞迴呼叫printPathNode() */
    while ( ptr != NULL ){
        for ( i = 1;i<= nodeCount;i++)
            if ( CriticalNode[i] == ptr->vertex ){
                Push(&Stack1, reinterpret_cast<intptr_t>(ptr));
                Push(&Stack2, v);
                v = ptr->vertex;
                ptr = adjlist1[v]->link;
                printPathNode(ptr, v);
            }
        ptr = ptr->link;
    }
    if ( v == source ){
        printf("\n\nThere are %d Critical paths from %d to %d\n",
               pathCount, source, sink);
        exit(0);
    }
    /* 當到達終點節點時即找到一臨界路徑 */
    /* 列出堆疊Stack1所存放的臨界點及Stack2所存放的臨界活動        */
    if ( v == sink ){
        printf("\n");
        for ( i = 0;i <= Stack2.top; i++){
            v = Stack2.item[i];
            ptr =(Node *) Stack1.item[i];
            printf("V%d--%d-->", v, ptr->duration);
        }
        printf("V%d", sink);
        pathCount++;
    }
    /* 彈出堆疊中的前一層臨界頂點及臨界活，繼續搜尋其相鄰頂點是否有臨界路徑 */
    ptr = (Node *)Pop(&Stack1);
    ptr = ptr->link;
    v = Pop(&Stack2);
    printPathNode(ptr, v);
}

/*起始ES初值*/
void Critical::initialES()
{
    int i;
    for ( i = 1;i <= N; i++ ) ES[i] = 0;
}

/*起始LC初值, LC初值為ES最大值*/
void Critical::initialLC()
{
    int i , max = 0;
    for ( i = 1; i <= N; i++ ) max= MAX(max, ES[i]);
    for ( i = 1; i <= N; i++ ) LC[i] = max;
}

void Critical::Push( struct Stackstruct *stack, int value )
{
    if ( stack->top >= MAXV){
        printf("Stack is Overflow!!\n");
        getchar();
        exit(1);
    }
    else
        stack->item[++stack->top] = value;
}

int Critical::Pop(struct Stackstruct *stack)
{
    if ( stack->top == empty ){
        printf("Stack is empty!!");
        getchar();
        exit(1);
    }
    else
        return (stack->item[stack->top--]);
}



int main()
{
    Critical obj;
    return 0;
}