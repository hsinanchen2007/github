// gs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

const int UNIT_COUNT = 4;

typedef struct tagPartner
{
    char *name;   //名字
    int next;     //下一個邀請物件
    int current;  //目前舞伴，-1表示還沒有舞伴
    int pCount; //偏愛列表中舞伴個數
    int perfect[UNIT_COUNT]; //偏愛列表
}PARTNER;

bool IsAllPartnerMatch(PARTNER *partners, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(partners[i].current == -1)
        {
            return false;
        }
    }

    return true;
}

int FindFreePartner(PARTNER *partners, int n)
{
    for(int i = 0; i < n; i++)
    {
        if((partners[i].current == -1) && (partners[i].next < partners[i].pCount))
        {
            return i;
        }
    }

    return -1;
}
//這裡也是演算法一致性處理的一個技巧
int GetPerfectPosition(PARTNER *partner, int id)
{
    for(int i = 0; i < partner->pCount; i++)
    {
        if(partner->perfect[i] == id)
        {
            return i;
        }
    }

    //返回一個非常大的值，意味著根本排不上對
    return 0x7FFFFFFF;
}

void InitFreeBoyStack(std::stack<int>& freeBoys, int count)
{
    for(int i = 0; i < count; i++)
    {
        freeBoys.push(i);
    }
}
#if 0
bool Gale_Shapley(BOY *boys, GIRL *girls, int count)
{
    bool success = true;
    std::stack<int> freeBoys;

    InitFreeBoyStack(freeBoys, count);
    while(!freeBoys.empty())
    {
        int bid = freeBoys.top();
        freeBoys.pop();
        int gid = boys[bid].perfect[boys[bid].next];
        if(girls[gid].current == -1)//這個女孩還沒有舞伴？
        {
            boys[bid].current = gid;//結交新舞伴
            girls[gid].current = bid;
        }
        else
        {
            //女孩已經有舞伴，前舞伴是bpid
            int bpid = girls[gid].current;
            if(GetGirlPerfectPosition(&girls[gid], bpid) > GetGirlPerfectPosition(&girls[gid], bid))
            {
                //女孩喜歡bid勝過其前舞伴bpid，於是甩掉前舞伴
                boys[bpid].current = -1; //前舞伴恢復自由身
                if(boys[bpid].next >= boys[bpid].cCount)
                {
                    success = false; //沒希望了
                    break;
                }
                freeBoys.push(bpid);
                boys[bid].current = gid; //結交新舞伴
                girls[gid].current = bid;
            }
            else
            {
                //女孩更喜歡前舞伴，所以，bid，等下一次吧
                if(boys[bid].next >= boys[bid].cCount)
                {
                    success = false; //沒希望了
                    break;
                }
                freeBoys.push(bid);
            }
        }
        boys[bid].next++; //無論是否配對成功，對同一個女孩只嘗試配對一次
    }

    return success;
}
#endif
#if 0
bool Gale_Shapley(BOY *boys, GIRL *girls, int count)
{
    bool success = true;
    std::stack<int> freeBoys;

    InitFreeBoyStack(freeBoys, count);
    while(!freeBoys.empty())
    {
        int bid = freeBoys.top();
        freeBoys.pop();
        for(int i = boys[bid].next; i < boys[bid].pCount; i++)
        {
            int gid = boys[bid].perfect[i];
            if(girls[gid].current == -1)//這個女孩還沒有舞伴？
            {
                boys[bid].current = gid;//結交新舞伴
                girls[gid].current = bid;
                boys[bid].next = i + 1;
                break;
            }
            else
            {
                //女孩已經有舞伴，前舞伴是bpid
                int bpid = girls[gid].current;
                if(GetGirlPerfectPosition(&girls[gid], bpid) > GetGirlPerfectPosition(&girls[gid], bid))
                {
                    //女孩喜歡bid勝過其前舞伴bpid，於是甩掉前舞伴
                    boys[bpid].current = -1; //前舞伴恢復自由身
                    freeBoys.push(bpid);
                    boys[bid].current = gid; //結交新舞伴
                    girls[gid].current = bid;
                    boys[bid].next = i + 1;
                    break;
                }
            }
        }
        if(boys[bid].current == -1)
        {
            success = false;
            break;
        }
    }

    return success;
}
#endif
#if 1
bool Gale_Shapley(PARTNER *boys, PARTNER *girls, int count)
{
    int bid = FindFreePartner(boys, count);
    while(bid >= 0)
    {
        int gid = boys[bid].perfect[boys[bid].next];
        if(girls[gid].current == -1)
        {
            boys[bid].current = gid;
            girls[gid].current = bid;
        }
        else
        {
            int bpid = girls[gid].current;
            //女孩喜歡bid勝過其目前舞伴bpid
            if(GetPerfectPosition(&girls[gid], bpid) > GetPerfectPosition(&girls[gid], bid))
            {
                boys[bpid].current = -1; //目前舞伴恢復自由身
                boys[bid].current = gid; //結交新舞伴
                girls[gid].current = bid;
            }
        }
        boys[bid].next++; //無論是否配對成功，對同一個女孩只邀請一次
        bid = FindFreePartner(boys, count);
    }

    return IsAllPartnerMatch(boys, count);
}
/*
if((GetPerfectPosition(&girls[gid], bpid) == -1) 
    && (GetPerfectPosition(&girls[gid], bid) == -1))
{
    //目前舞伴bpid和bid都不在女孩的喜歡列表中，太糟糕了
    ...
}
else if(GetPerfectPosition(&girls[gid], bpid) == -1)
{
    //目前舞伴bpid不在女孩的喜歡列表中，bid有機會
    ...
}
else if(GetPerfectPosition(&girls[gid], bid) == -1)
{
    //bid不在女孩的喜歡列表中，目前舞伴bpid維持原狀
    ...
}
else if(GetPerfectPosition(&girls[gid], bpid) > GetPerfectPosition(&girls[gid], bid))
{
    //女孩喜歡bid勝過其目前舞伴bpid
    ...
}
else
{
    //女孩喜歡目前舞伴bpid勝過bid
    ...
}
*/
#endif

void InitPriorityTable()
{
    PARTNER girls[] = 
    {
        {"Laura", 0, -1, 3, {2,0,1} }, //Laura
        {"Marcy", 0, -1, 3, {0,2,1} },  //Marcy
        {"Nancy", 0, -1, 3, {1,0,2} } //Nancy
    };

    PARTNER boys[] = 
    {
        {"Albert", 0, -1, 3, {0,2,1} }, //Albert
        {"Brad",   0, -1, 3, {1,2,0} }, //Brad
        {"Chuck",  0, -1, 3, {0,1,2} } //Chuck
    };
    int priority[UNIT_COUNT][UNIT_COUNT];

for(int w = 0; w < UNIT_COUNT; w++)
{
    //初始化成最大值，原理同上
    for(int j = 0; j < UNIT_COUNT; j++)
    {
        priority[w][j] = 0x7FFFFFFF;
    }
    //給偏愛舞伴指定位置關係
    int pos = 0;
    for(int m = 0; m < girls[w].pCount; m++)
    {
        priority[w][girls[w].perfect[m]] = pos++;
    }
}
//if(priority[gid][bpid] > priority[gid][bid])
//{}
}

void PrintResult(PARTNER *boys, PARTNER *girls, int count)
{
    for(int i = 0; i < count; i++)
    {
        std::cout << boys[i].name << "[" 
                  << GetPerfectPosition(&boys[i], boys[i].current)
                  << "] <---> " << girls[boys[i].current].name << "["
                  << GetPerfectPosition(&girls[boys[i].current], i)
                  << "]" << std::endl;
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[])
{
#if 0

    PARTNER girls[] = 
    {
        {"Laura", 0, -1, 3, {2,0,1} }, //Laura
        {"Marcy", 0, -1, 3, {0,2,1} },  //Marcy
        {"Nancy", 0, -1, 3, {1,0,2} } //Nancy
    };

    PARTNER boys[] = 
    {
        {"Albert", 0, -1, 3, {0,2,1} }, //Albert
        {"Brad",   0, -1, 3, {1,2,0} }, //Brad
        {"Chuck",  0, -1, 3, {0,1,2} } //Chuck
    };
/*
Albert Laura Nancy Marcy
Brad Marcy Nancy Laura
Chuck Laura Marcy Nancy

Laura Chuck Albert Brad
Marcy Albert Chuck Brad
Nancy Brad Albert Chuck


Albert Nancy
Brad Marcy
Chuck Laura
*/
#endif
#if 1
PARTNER girls[] = 
{
    {"A", 0, -1, 4, {2,3,1,0} },
    {"B", 0, -1, 4, {2,1,3,0} },
    {"C", 0, -1, 4, {0,2,3,1} },
    {"D", 0, -1, 4, {1,3,2,0} }
};

PARTNER boys[] = 
{
    {"1", 0, -1, 4, {0,3,2,1} },
    {"2", 0, -1, 4, {0,1,2,3} },
    {"3", 0, -1, 4, {0,2,3,1} },
    {"4", 0, -1, 4, {1,0,3,2} }
};
#endif

#if 0
PARTNER girls[] = 
{
    {"girl0", 0, -1, 5, {2,1,4,0,3} },
    {"girl1", 0, -1, 5, {1,3,0,4,2} },
    {"girl2", 0, -1, 5, {0,1,2,4,3} },
    {"girl3", 0, -1, 5, {2,0,3,1,4} },
    {"girl4", 0, -1, 5, {4,1,2,3,0} }
};

PARTNER boys[] = 
{
    {"boy0", 0, -1, 5, {4,1,0,3,2} },
    {"boy1", 0, -1, 5, {3,1,4,0,2} },
    {"boy2", 0, -1, 5, {2,3,4,0,1} },
    {"boy3", 0, -1, 5, {4,0,3,1,2} },
    {"boy4", 0, -1, 5, {3,4,2,0,1} },
};
#endif

    if(Gale_Shapley(boys, girls, UNIT_COUNT))
    {
        PrintResult(boys, girls, UNIT_COUNT);
    }

    return 0;
}
