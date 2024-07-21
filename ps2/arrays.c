#include<stdio.h>
#include<math.h>

float lift_a_car(const int, const int, const int);
float unit_price(const float, const int, const int);
int collatz(const int);
int opposite_number(const int, const int);
void counter(const int[], const int, int[2]);
unsigned long long sum_squared(const int);
int array_min(const int[], const int);
int array_max(const int[], const int);
unsigned long special_counter(const int[], const int);
int special_numbers(const int[], const int, int[]);

int main ()
{
    //printf("%.4f\n", lift_a_car(4, 90, 1650));
    //printf("%.4f\n", unit_price(5.63, 20, 200));
    //printf("%d\n", collatz(35));
    //printf("%d\n", opposite_number(12, 9)); 
    //int input_array[] = {1,2,3,4,5};
    //int result_array[2];
    //counter(input_array, 5, result_array);
    //printf("%d %d\n", result_array[0], result_array[1]);
    //printf("%llu\n", sum_squared(31));
    //int input_array[] = {1,2,3,4,5};
    //printf("%d\n", array_min(input_array, 5));
    //printf("%d\n", array_max(input_array, 5));
    //int input_array[] = {11,12,13,14,15};
    //printf("%lu\n", special_counter(input_array, 5));
    //int input_array[] = {16,17,4,3,5,2};
    //int result_array[6];
    //int count = special_numbers(input_array, 6, result_array);
    //for(int i = 0; i < count; i++)
    //{
    //    printf("%d ", result_array[i]);
    //}
    //printf("\n");
    return 0;
}

float lift_a_car(const int stick_length, const int human_weight, const int car_weight)
{
    float weight = human_weight + car_weight;
    weight = stick_length*human_weight/weight;
    int hundred_weight = weight * 100;
    int thousand_weight = weight * 1000;
    if(thousand_weight-hundred_weight*10<5)
    {
        return hundred_weight/100.0;
    }
    else
    {
        hundred_weight++;
        return hundred_weight/100.0;
    }
}

float unit_price(const float pack_price, const int rolls_count, const int pieces_count)
{
    float price = pack_price*100/(rolls_count*pieces_count);
    int hundred_price = price * 100;
    int thousand_price = price * 1000;

    if(thousand_price-hundred_price*10<5)
    {
        return hundred_price/100.0;
    }
    else
    {
        hundred_price++;
        return hundred_price/100.0;
    }
}

int collatz(const int number)
{
    int count=1;
    int help_number = number;
    while (help_number!=1)
    {
        if(help_number%2==0)
        {
            help_number=help_number/2;
        }
        else
        {
            help_number=3*help_number+1;
        }
        count++;
    }
    return count;
}
int opposite_number(const int n, const int number)
{
    int half=n/2;
    int new_number;
    if(half>number)
    {
        new_number=number+half;
    }
    else
    {
        new_number=number-half;
    }
    return new_number;
}

void counter(const int input_array[], const int array_size, int result_array[2])
{
    result_array[0]=0;
    result_array[1]=0;
    for (int i=0; i<array_size; i++)
    {
        if(i%2==0)
        {
            result_array[0]=result_array[0]+input_array[i];
        }
        else
        {
            result_array[1]=result_array[1]+input_array[i];
        }
    }
    return;
}

unsigned long long sum_squared(const int line)
{
    unsigned long long sum=1;
    unsigned long long num=1;
    unsigned long long help_number=0;
    for(unsigned long index=0; index<=line; index++)
    {
        /*num=tgamma(line+1)/tgamma(index+1)/tgamma(line-index+1);
        printf("%llu; ",num);
        help_number=num*num;
        sum=sum+help_number;*/
        num=num*(line-index)/(index+1);
        //printf("%llu; ",num);
        help_number=num*num;
        sum=sum+help_number;
    }
    return sum;
}

int array_min(const int input_array[], const int array_size)
{
    int min=999999999;
    if(input_array==NULL)
    {
        return -1;
    }
    for(int i=0;i<array_size;i++)
    {
        if(min>input_array[i])
        {
            min=input_array[i];
        }
    }
    return min;
}

int array_max(const int input_array[], const int array_size)
{
    int max=0;
    if(input_array==NULL)
    {
        return -1;
    }
    for(int i=0;i<array_size;i++)
    {
        if(max<input_array[i])
        {
            max=input_array[i];
        }
    }
    return max;
}

unsigned long special_counter(const int input_array[], const int array_size)
{
    int sum=0;
    for(int i=0;i<array_size;i++)
    {
        if(i%2==0)
        {
            sum=sum+input_array[i];
        }
        else
        {
            sum=sum+pow(input_array[i],2);
        }
    }
    return sum;
}

int special_numbers(const int input_array[], const int array_size, int result_array[])
{
    int sum;
    int p=0;
    for(int i=0;i<array_size;i++)
    {
        sum=0;
        for(int x=i+1;x<array_size;x++)
        {
            sum=sum+input_array[x];
        }
        if(sum<input_array[i])
        {
            result_array[p]=input_array[i];
            p=p+1;
        }
    }
    return p;
}
