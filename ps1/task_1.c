#include<superkarel.h>

void turn_right();
void turn_round();
void find_beeper();

int main()
{
    turn_on("task_1.kw");
    set_step_delay(200);
    while(front_is_blocked())
    {
        turn_left();
    }
    find_beeper();
    while(not_facing_west())
    {
        turn_left();
    }
    turn_off();
    return 0;
}

void turn_right()
{
    turn_left();
    turn_left();
    turn_left();
}

void turn_round()
{
    turn_left();
    turn_left();
}

void find_beeper()
{
    if(front_is_clear() && right_is_blocked())
    {
        step();
    }
    else
    {
       turn_right();
       step();
    }
    if(front_is_blocked() && right_is_blocked() && left_is_clear())
    {
        turn_left();
    }
    if(front_is_blocked() && right_is_blocked() && left_is_blocked())
    {
        turn_round();
    }
    if(no_beepers_present())
    {
        find_beeper();
    }
    else
    {
        pick_beeper();
    }

    if(front_is_blocked() && right_is_blocked() && left_is_blocked())
    {
        turn_round();
    }
    if(front_is_blocked() && left_is_blocked() && right_is_clear())
    {
        turn_right();
    }
    if(front_is_clear() && left_is_blocked())
    {
        step();
    }
    else
    {
        turn_left();
        step();
    }
}
