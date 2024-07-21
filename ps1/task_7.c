#include<superkarel.h>

void turn_right();
void turn_round();
void fill_doors();
void warehouse();

int main(){
    set_step_delay(100);
    turn_on("task_7.kw");
    fill_doors();
    warehouse();
    warehouse();
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

void fill_doors()
{
    while(front_is_clear())
    {
        if(left_is_clear())
        {
            turn_left();
            step();
            put_beeper();
            turn_round();
            step();
            turn_left();
        }
        step();
    }
    if(left_is_clear())
    {
        turn_left();
        step();
        put_beeper();
        turn_round();
        step();
        turn_left();
    }
    turn_round();
    while(front_is_clear())
    {
        step();
    }
    turn_round();
}

void warehouse()
{
    do
    {
        if(left_is_clear())
        {
            turn_left();
            step();
            put_beeper();
            step();
            while(no_beepers_present())
            {
                if(front_is_clear() && right_is_blocked())
                {
                    step();
                    continue;
                }
                else if (right_is_clear())
                {
                    turn_right();
                    step();
                    continue;
                }
                if(front_is_blocked() && right_is_blocked() && left_is_blocked())
                {
                    turn_round();
                    continue;
                }
                if(front_is_blocked() && right_is_blocked())
                {
                    turn_left();
                }
            }
            pick_beeper();
            if(no_beepers_present())
            {
                put_beeper();
                turn_round();
                step();
                while(no_beepers_present())
                {
                    if(front_is_clear() && left_is_blocked())
                    {
                        step();
                        continue;
                    }
                    else if(left_is_clear())
                    {
                        turn_left();
                        step();
                    }
                    if(front_is_blocked() && right_is_blocked() && left_is_blocked())
                    {
                        turn_round();
                        continue;
                    }
                    if(front_is_blocked() && left_is_blocked())
                    {
                        turn_right();
                    }
                }
            }
            pick_beeper();
            step();
            turn_left();
            if(front_is_clear())
            {
                step();
            }
        }  
        else if(front_is_clear())
        {
            step();
        }
    }while(front_is_clear());
}
