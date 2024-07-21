#include<superkarel.h>

void turn_right();
void turn_round();
void find_treasure();

int main(){
    set_step_delay(100);
    turn_on("task_6.kw");
    find_treasure();
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

void find_treasure()
{
    while(1)
    {
        while(no_beepers_present())
        {
            step();
        }
        pick_beeper();
        if(beepers_present())
        {
            pick_beeper();
            if(beepers_present())
            {
                pick_beeper();
                if(beepers_present())
                {
                    pick_beeper();
                    if(beepers_present())
                    {
                        pick_beeper();
                        return;
                    }
                    else
                    {
                        while(not_facing_east())
                        {
                            turn_left();
                        }
                    }
                }
                else
                {
                    while(not_facing_south())
                    {
                        turn_left();
                    }
                }
            }
            else
            {
                while(not_facing_west())
                {
                    turn_left();
                }
            }
        }
        else
        {
            while(not_facing_north())
            {
                turn_left();
            }
        }
    }
}
