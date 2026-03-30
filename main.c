#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float train[][2] = {

    {0,0},
    {1,2},
    {2,4},
    {3,6},
    {4,8},
};

#define train_count (sizeof(train) / sizeof(train[0]))

float rand_float()
{
    return (float) rand() / (float) RAND_MAX;
}

float cost_function(float w, float b)
{
    float result = 0.0f;

    for (size_t i=0; i < train_count; ++i)
    {
        float x = train[i][0];
        float y = x * w + b; 

        float distance = y - train[i][1];
        result += distance * distance;
        
       // printf("predicted = %f, actual = %f\n", y, train[i][1]);
    }

    result /= train_count;

    return result;
}

int main()
{
    // srand(time(0));
    srand(42);

    float w = rand_float() * 10.0f;
    float b = rand_float() * 10.0f;

    float h = 1e-3;
    float step_size = 1e-2f; // learing rate

    // printf("%f\n", cost_function(w));

    for (size_t i=0; i < 1000; ++i)
    {

        float distance_cost_function = ((cost_function(w + h, b) - cost_function(w, b)) / h); 
        float distance_bias = ((cost_function(w, b + h) - cost_function(w, b)) / h); 

        w -=  step_size * distance_cost_function;
        b -=  step_size * distance_bias;

        printf("cost = %f, w = %f, bias = %f\n", cost_function(w, b), w, b);
    }


        printf("w = %f\n", w);

    return 0;

}

