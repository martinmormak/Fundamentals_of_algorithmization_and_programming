#include<superkarel.h>

void turn_right();
void turn_round();
void corner();
void frame();
void center();

int main(){
    set_step_delay(100);
    turn_on("task_5.kw");
    frame();
    center();
    turn_right();
    center();
    while(not_facing_north())
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

void corner()
{
    while(not_facing_west())
    {
        turn_left();
    }
    while(front_is_clear())
    {
        step();
    }
    turn_left();
    while(front_is_clear())
    {
        step();
    }
}

void frame()
{
    corner();
    while(no_beepers_present())
    {
        while(front_is_clear())
        {
            put_beeper();
            step();
        }
        turn_left();
    }
}

void center()
{
    if(front_is_clear())
    {
        step();
        if(front_is_clear())
        {
            step();
            center();
        }
        step();
    }
    else
    {
        turn_round();
    }
}
