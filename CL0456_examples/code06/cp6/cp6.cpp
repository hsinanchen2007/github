// cp6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "item_state.h"

ACTION_EFFECTION actEffect[] = 
{
    { ONE_MONSTER_GO ,            REMOTE, -1,  0 },
    { TWO_MONSTER_GO ,            REMOTE, -2,  0 },
    { ONE_MONK_GO ,               REMOTE,  0, -1 },
    { TWO_MONK_GO ,               REMOTE,  0, -2 },
    { ONE_MONSTER_ONE_MONK_GO ,   REMOTE, -1, -1 },
    { ONE_MONSTER_BACK ,          LOCAL ,  1,  0 },
    { TWO_MONSTER_BACK ,          LOCAL ,  2,  0 },
    { ONE_MONK_BACK ,             LOCAL ,  0,  1 },
    { TWO_MONK_BACK ,             LOCAL ,  0,  2 },
    { ONE_MONSTER_ONE_MONK_BACK , LOCAL ,  1,  1 }
};

bool IsSameItemState(ItemState state1, ItemState state2)
{
    return state1.IsSameState(state2);
}

bool IsProcessedState(std::deque<ItemState>& states, ItemState& newState)
{
    std::deque<ItemState>::iterator it = states.end();
    
    it = find_if( states.begin(), states.end(), 
                  std::bind2nd(std::ptr_fun(IsSameItemState), newState) );

    return (it != states.end());
}

void PrintResult(std::deque<ItemState>& states)
{
    std::cout << "Find Result : " << std::endl;
    for_each(states.begin(), states.end(), std::mem_fun_ref(&ItemState::PrintStates));
    std::cout << std::endl << std::endl;
}

bool MakeActionNewState(const ItemState& curState, ACTION_EFFECTION& ae, ItemState& newState)
{
    if(curState.CanTakeAction(ae))
    {
        newState = curState;
        newState.local_monster  += ae.move_monster;
        newState.local_monk     += ae.move_monk;
        newState.remote_monster -= ae.move_monster;
        newState.remote_monk    -= ae.move_monk;
        newState.boat    = ae.boat_to;
        newState.curAct  = ae.act;

        return true;
    }

    return false;
}

void SearchState(std::deque<ItemState>& states);

void SearchStateOnNewAction(std::deque<ItemState>& states, 
                             ItemState& current, ACTION_EFFECTION& ae)
{
    ItemState next;
    if(MakeActionNewState(current, ae, next))
    {
        if(next.IsValidState() && !IsProcessedState(states, next))
        {
            states.push_back(next);
            SearchState(states);
            states.pop_back();
        }
    }
}

void SearchState(std::deque<ItemState>& states)
{
    ItemState current = states.back(); /*每次都從目前狀態開始*/
    if(current.IsFinalState())
    {
        PrintResult(states);
        return;
    }

    /*嘗試用10種動作分別與目前狀態組合*/
    for(int i = 0; i < sizeof(actEffect) / sizeof(actEffect[0]); i++)
    {
        SearchStateOnNewAction(states, current, actEffect[i]);
    }
}


int main(int argc, char* argv[])
{
    std::deque<ItemState> states;
    ItemState init;

    states.push_back(init);
    SearchState(states);

    assert(states.size() == 1); /*窮舉結束後states應該還是只有一個初始狀態*/

    return 0;
}
