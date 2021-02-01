// graph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

const int MAX_VERTEXNODE = 20;

typedef struct tagVertexNode
{
    char *name;   //���ʦW��
    int days;     //�������ʩһݮɶ�
    int sTime;    //���ʳ̦��}�l�ɶ�
    int inCount;  //���ʪ��e�X�`�I�Ӽ�
    int adjacentNode[MAX_VERTEXNODE]; //�۾F���ʲM��(�`�I����)
    int adjacent; //�۾F���ʪ��Ӽ�
}VERTEX_NODE;

typedef struct tagGraph
{
    int count; //�Ϫ����I�Ӽ�
    VERTEX_NODE vertexs[MAX_VERTEXNODE]; //�Ϫ����I�C��
}GRAPH;

GRAPH graph = 
{
    9,
    {
        {"P1", 8, 0, 0, {2, 6}, 2},
        {"P2", 5, 0, 0, {2, 4}, 2},
        {"P3", 6, 8, 2, {3}, 1},
        {"P4", 4, 14,2, {5, 8}, 2},
        {"P5", 7, 5, 1, {3, 5}, 2},
        {"P6", 7, 18, 2, {}, 0},
        {"P7", 4, 8, 1, {7}, 1},
        {"P8", 3, 12, 1, {8}, 1},
        {"P9", 4, 18, 2, {}, 0}
    }
};

struct QUEUE_ITEM  
{    
    int node;
    int sTime;
    bool operator < (const QUEUE_ITEM &a) const   
    {    
        return sTime > a.sTime;//�̤p���u��     
    }    
};   

void EnQueue(std::priority_queue<QUEUE_ITEM>& q, int node, int sTime)
{
    QUEUE_ITEM item = {node, sTime};
    q.push(item);
}

int DeQueue(std::priority_queue<QUEUE_ITEM>& q)
{
    int node = q.top().node;
    q.pop();
    return node;
}

    //std::priority_queue<QUEUE_ITEM, std::vector<QUEUE_ITEM>, PriorityCmp> nodeQueue;
bool TopologicalSorting(GRAPH *g, std::vector<int>& sortedNode)
{
    std::priority_queue<QUEUE_ITEM> nodeQueue;

    for(int i = 0; i < g->count; i++)
    {
        if(g->vertexs[i].inCount == 0)
        {
            EnQueue(nodeQueue, i, g->vertexs[i].sTime);
        }
    }

    while(nodeQueue.size() != 0)
    {
        int node = DeQueue(nodeQueue); //���Ӷ}�l�ɶ��u�����ǥX��C
        sortedNode.push_back(node);//��X�ثe�`�I
        //���X�`�Inode���Ҧ��F���I�A�N��ܦ��V��inCount�ȴ�1
        for(int j = 0; j < g->vertexs[node].adjacent; j++)
        {
            int adjNode = g->vertexs[node].adjacentNode[j];
            g->vertexs[adjNode].inCount--;
            //�p�GinCount�Ȭ�0�A�h�Ӹ`�I�J��C
            if(g->vertexs[adjNode].inCount == 0)
            {
                EnQueue(nodeQueue, adjNode, g->vertexs[adjNode].sTime);
            }
        }
    }

    return (sortedNode.size() == g->count);
}

void PrintSorting(GRAPH *g, const std::vector<int>& sortedNode)
{
    std::vector<int>::const_iterator cit = sortedNode.begin();
    for(;cit != sortedNode.end(); ++cit)
    {
        std::cout << g->vertexs[*cit].name << std::endl;
    }
}

int main(int argc, char* argv[])
{
    std::vector<int> sortedNode;
    if(!TopologicalSorting(&graph, sortedNode))
    {
        std::cout << "Graph has circle!" << std::endl;
        return -1;
    }
    PrintSorting(&graph, sortedNode);
	return 0;
}

