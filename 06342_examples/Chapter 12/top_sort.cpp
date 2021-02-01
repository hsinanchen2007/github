/* file name : top_sort.cpp */
/* 拓樸排序 */

#include <stdlib.h>
#include <iostream>
using namespace std;

#define MAX_V 100  /*最大節點數*/
#define TRUE 1
#define FALSE 0

/*定義資料結構*/
typedef struct node_tag {
    int vertex;
    struct node_tag *link;
} Node;

class TopSort {
public:
    Node *adjlist[MAX_V+1];  /*宣告相鄰串列*/
    int visited[MAX_V+1];  /*記錄頂點是否已拜訪*/
    int Top_order[MAX_V+1];
    int N;
    int place;
    void build_adjlist();
    void show_adjlist();
    void topological();
    void top_sort(int);
    Node *searchlast(Node *);
};

int main()
{
    int i;
    TopSort obj;
    obj.build_adjlist(); /*以相鄰串列表示圖形*/
    obj.show_adjlist();  /*顯示串列之資料*/
    obj.topological();     /*圖形之蹤向優先搜尋，以頂點1為起始頂點*/
    puts("\n------Toplogical order sort------");
    for ( i = 0; i < obj.N; i++ )
        cout << "V " << obj.Top_order[i];
    system("PAUSE");
    return 0;
}

void TopSort::build_adjlist()
{
    FILE *fptr;
    Node *node,*lastnode;
    int vi,vj;
    fptr = fopen("top_sort.dat","r");
    if ( fptr == NULL )
    {
        perror("top_sort.dat");
        exit(0);
    }
    
    /*讀取節點總數*/
    fscanf(fptr,"%d",&N);
    for ( vi = 1; vi <= N; vi++)
    {
        /*設定陣列及各串列起始值*/
        adjlist[vi] = (Node *)malloc(sizeof(Node));
        adjlist[vi]->vertex = vi;
        adjlist[vi]->link = NULL;
    }
    
    /*讀取節點資料*/
    while( fscanf(fptr,"%d %d",&vi,&vj) != EOF)
    {
        node = (Node *)malloc(sizeof(Node));
        node->vertex = vj;
        node->link = NULL;
        if ( adjlist[vi]->link == NULL)
            adjlist[vi]->link = node;
        else
        {
            lastnode = searchlast(adjlist[vi]);
            lastnode->link = node;
        }
    }
    fclose(fptr);
}

/*顯示各相鄰串列之資料*/
void TopSort::show_adjlist()
{
    int v;
    Node *ptr;
    
    puts("Head    adjacency nodes");
    puts("------------------------------");
    for (v = 1; v <= N; v++)
    {
        cout << "V " << adjlist[v]->vertex;
        ptr = adjlist[v]->link;
        while ( ptr != NULL )
        {
            cout << "--> V " << ptr->vertex;
            ptr = ptr->link;
        }
        cout << "\n";
    }
}

/*圖形之蹤向優先搜尋*/
void TopSort::topological()
{
    int v;
    
    for ( v = 1;v <= N; v++)
        visited[v] = FALSE;
    place = N;
    for ( v = 1; v <= N; v++ )
        if ( !visited[v] )
            top_sort(v);
}

void TopSort::top_sort(int k)
{
    Node *ptr;
    int w;
    
    visited[k] = TRUE;          /*設定v頂點為已拜訪過*/
    ptr = adjlist[k]->link;     /*拜訪v相鄰頂點*/
    while ( ptr != NULL )
    {
        w = ptr->vertex; /* w 為v的立即後繼者 */ 
        if ( !visited[w] )
            top_sort(w);
        ptr = ptr->link;
    }
    Top_order[--place] = k;
}

/*搜尋串列最後節點函數*/
Node *TopSort::searchlast( Node *linklist )
{
    Node *ptr;
    ptr = linklist;
    while ( ptr->link != NULL ) ptr = ptr->link;
    return ptr;
}


