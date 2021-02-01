#include "StdAfx.h"
#include "testAnalysis.h"
#include "GameState.h"
/*
int test_state1[GAME_CELLS] = 
{
    1,1,2,1,1,1,0,0,2,2,2,0,0,1,1,  //1�G�@�ӨR�T�A2�G�@�Ӭ��T��
    0,0,2,1,1,1,1,1,0,0,2,1,1,1,0,  //1�G�@�Ӥ��l
    0,1,2,1,1,1,2,0,1,0,1,1,1,1,0,  //1�G�@�Ӭ��|
    1,1,0,1,1,1,0,2,2,2,2,1,1,1,0,  //1�G�@�ӨR�T�A2�G�@�ӨR�|
    2,2,2,2,2,1,0,0,0,1,1,1,1,1,0,  //1�G�@�Ӥ��l�A2�G�@�Ӥ��l
    0,2,2,0,0,0,1,1,1,0,0,2,2,1,0,  //1�G�@�Ӭ��T�A2�G�@�Ӭ��G
    0,0,2,1,1,1,0,0,0,0,2,1,1,1,0,  //1�G�@�ӨR�T
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,  //1�G�@�Ӥ��l
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,  //             2�G�@�Ӥ��l
    0,1,1,1,1,2,2,2,0,0,2,2,2,2,2,  //1�G�@�ӨR�|�A2�G�@�ӨR�T�A�@�Ӥ��l
    2,1,2,1,2,2,2,0,0,0,2,2,0,1,0,  //             2�G�@�ӨR�T�A�@�Ӭ��G
    2,1,2,1,1,1,0,0,2,2,2,0,0,1,0,  //1�G�@�ӨR�T�A2�G�@�Ӭ��T
    2,1,2,1,1,1,2,0,1,0,2,2,1,1,0,
    0,1,2,1,0,1,2,0,0,0,2,1,2,1,2,
    0,0,2,1,1,0,2,0,0,0,2,1,1,1,0
};
*/
int test_state1[GAME_CELLS] = 
{
    1,1,1,0,2,2,2,2,1,  //1�G�@�ӨR�T�A2�G�@�ӨR�|
    2,2,1,0,0,0,1,1,1,  //1�G�@�Ӥ��l�A2�G�@�Ӥ��l
    0,0,0,1,1,1,0,0,2,  //1�G�@�Ӭ��T�A2�G�@�Ӭ��G
    1,1,1,0,0,0,0,2,1,  //1�G�@�ӨR�T
    1,1,1,1,1,1,1,1,1,  //1�G�@�Ӥ��l
    2,2,2,2,2,2,2,2,2,  //             2�G�@�Ӥ��l
    1,1,2,2,2,0,0,2,2,  //1�G�@�ӨR�|�A2�G�@�ӨR�T�A�@�Ӥ��l
    1,2,2,2,0,0,0,2,2,  //             2�G�@�ӨR�T�A�@�Ӭ��G
    1,1,1,0,0,2,2,2,0   //1�G�@�ӨR�T�A2�G�@�Ӭ��T
};
void TestStateAnalysis()
{
    GameState state1;
    state1.InitGameState(PLAYER_A);
    state1.SetGameState(test_state1, PLAYER_A);

    EvaluatorData ev_data;
    state1.SearchPatterns(ev_data);
    assert(ev_data.GetCounter(3, PLAYER_A, true) == 4);
    assert(ev_data.GetCounter(3, PLAYER_A, false) == 1);
    assert(ev_data.GetCounter(4, PLAYER_A, true) == 1);
    assert(ev_data.GetCounter(4, PLAYER_A, false) == 1);
    assert(ev_data.GetCounter(5, PLAYER_A, false) == 3);


    assert(ev_data.GetCounter(2, PLAYER_B, true) == 0);
    assert(ev_data.GetCounter(2, PLAYER_B, false) == 2);
    assert(ev_data.GetCounter(3, PLAYER_B, true) == 2);
    assert(ev_data.GetCounter(3, PLAYER_B, false) == 2);
    assert(ev_data.GetCounter(4, PLAYER_B, true) == 1);
    assert(ev_data.GetCounter(4, PLAYER_B, false) == 0);
    assert(ev_data.GetCounter(5, PLAYER_B, false) == 3);
}
