#include<superkarel.h>

void turn_right();
void turn_round();
void check_beeper();
void repair();
void next_line();

int main(){
    set_step_delay(100);
    turn_on("task_4.kw");
    do
    {
        check_beeper();
        turn_round();
        while(front_is_clear())
        {
            step();
        }
        turn_left();
        if(front_is_blocked())
        {
            break;
        }
        step();
    }while(1);
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

void check_beeper()
{
    turn_left();
    while(front_is_clear())
    {
        if(beepers_present())
        {
            repair();
            return;
        }
        step();
    }
    if(beepers_present())
    {
        repair();
    }
}

void repair()
{
    turn_round();
    while(front_is_clear())
    {
        step();
    }
    turn_round();
    while(front_is_clear())
    {
        if(no_beepers_present())
        {
            put_beeper();
        }
        step();
    }
    if(no_beepers_present())
    {
        put_beeper();
    }
}
