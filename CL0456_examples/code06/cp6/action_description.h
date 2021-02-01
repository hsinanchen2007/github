// action_description.h : include file for action description interface
//

#pragma once

#include "river_def.h"

typedef struct tagActionDescription
{
    ACTION_NAME act;
    const char *description; //�����ʧ@���H���y���y�z
}ACTION_DESCRIPTION;


const char *GetActionDescription(ACTION_NAME act);



