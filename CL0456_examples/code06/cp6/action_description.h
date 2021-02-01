// action_description.h : include file for action description interface
//

#pragma once

#include "river_def.h"

typedef struct tagActionDescription
{
    ACTION_NAME act;
    const char *description; //對應動作的人類語言描述
}ACTION_DESCRIPTION;


const char *GetActionDescription(ACTION_NAME act);



