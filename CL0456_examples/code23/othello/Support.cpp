#include "StdAfx.h"
#include "Support.h"


int line_idx_tbl[LINE_DIRECTION][LINE_CELLS] = 
{
    {0, 1, 2}, //�Ĥ@��
    {3, 4, 5}, //�ĤG��
    {6, 7, 8}, //�ĤT��
    {0, 3, 6}, //�Ĥ@�C
    {1, 4, 7}, //�ĤG�C
    {2, 5, 8}, //�ĤT�C
    {0, 4, 8}, //����e�u
    {2, 4, 6}, //�ϥ�e�u
};