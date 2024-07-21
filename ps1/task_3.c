#include<superkarel.h>

void turn_right();
void turn_round();
void next_line();
void colect_line();
void put_line();
void sort();

int main(){
    set_step_delay(100);
    turn_on("task_3.kw");
    colect_line();
    put_line();
    while(not_facing_west())
    {
        turn_left();
    }
    sort();
    while(front_is_clear())
    {
        if(beepers_present() && right_is_clear())
        {
            sort();
        }
        step();
    }
    turn_round();
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

void next_line()
{
    turn_round();
    while(front_is_clear())
    {
        step();
    }
    turn_left();
    step();
    turn_left();
}

void colect_line()
{
    do
    {
        while(front_is_clear())
        {
            while(beepers_present())
            {
                pick_beeper();
            }
            step();
        }
        while(beepers_present())
        {
            pick_beeper();
        }
        while(beepers_in_bag())
        {
            put_beeper();
        }
        if(no_beepers_present())
        {
            turn_left();
            step();
            turn_left();
            break;
        }
        if(front_is_blocked() && right_is_blocked())
        {
            turn_round();
            break;
        }
        next_line();
    }
    while(1);
}

void put_line()
{
    do
    {
        while(beepers_present())
        {
            pick_beeper();
        }
        while(beepers_in_bag())
        {
            put_beeper();
            step();
        }
        turn_round();
        while(front_is_clear())
        {
            step();
        }
        if(left_is_clear())
        {
            turn_left();
            step();
            if(no_beepers_present())
            {
                turn_round();
                step();
                turn_right();
                break;
            }
            turn_left();
        }
        else
        {
            break;
        }
     }while(1);
}

void sort()
{
    while(beepers_present() || beepers_in_bag())
    {
        if(beepers_present() && right_is_clear())
        {
            turn_left();
            do
            {
                step();
            }while(beepers_present() && front_is_clear());
            if(beepers_present())
            {
                turn_round();
            }
            else
            {
                turn_round();
                step();
            }
            while(beepers_present())
            {
                while(beepers_present())
                {
                    pick_beeper();
                }
                step();
            }
            turn_round();
            step();
            turn_right();
        }
        while(beepers_in_bag())
        {
            if(beepers_in_bag() && right_is_blocked())
            {
                turn_left();
                do
                {
                    put_beeper();
                    if(front_is_clear())
                    {
                        step();
                    }
                }while(beepers_in_bag());
                turn_round();
                while(front_is_clear())
                {
                    while(beepers_present())
                    {
                        pick_beeper();
                    }
                    if(beepers_in_bag())
                    {
                        put_beeper();
                    }
                    step();
                }
                while(beepers_present())
                {
                    pick_beeper();
                }
                if(beepers_in_bag())
                {
                put_beeper();
                }
                turn_left();
                if(no_beepers_in_bag())
                {
                    while(not_facing_east())
                    {
                        turn_round();
                    }
                    while(front_is_clear())
                    {
                        step();
                    }
                    turn_round();
                    break;
                }
            }
            step();
        }
        step();
    }
}
