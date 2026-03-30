#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// OR-Gate
float or_train[][3] = {

    {0,0, 0},
    {0,1, 1},
    {1,0, 1},
    {1,1, 1},
};


// AND-Gate
float and_train[][3] = {

    {0,0, 0},
    {0,1, 0},
    {1,0, 0},
    {1,1, 1},
};


// NAND-Gate
float nand_train[][3] = {

    {0,0, 1},
    {0,1, 1},
    {1,0, 1},
    {1,1, 0},
};


// XOR-Gate (x|y) & ~(x&y)
float xor_train[][3] = {

    {0,0, 0},
    {0,1, 1},
    {1,0, 1},
    {1,1, 0},
};

typedef float sample[3];

sample *train = xor_train;
size_t train_count = 4;


float sigmoidf(float x)
{
    return 1.f / ( 1.f + expf(-x));
}

float rand_float()
{
    return (float) rand() / (float) RAND_MAX;
}

float cost_function(float w1, float w2, float b)
{
    float result = 0.0f;

    for (size_t i=0; i < train_count; ++i)
    {
        float x1 = train[i][0];
        float x2 = train[i][1];

        float y = sigmoidf(x1*w1 + x2*w2 + b); 

        float distance = y - train[i][2];
        result += distance * distance;
        
       // printf("predicted = %f, actual = %f\n", y, train[i][1]);
    }

    result /= train_count;

    return result;
}


int main()
{

    //srand(time(0));
    srand(42);

    float w1 = rand_float();
    float w2 = rand_float();
    float b = rand_float();

    float h = 1e-3;
    float step_size = 1e-2f; // learing rate


    // the training 
    for (size_t i=0; i < 1000 * 1000; ++i)
    {


        float distance_cost_function_w1 = ((cost_function(w1 + h, w2, b) - cost_function(w1, w2, b)) / h); 
        float distance_cost_function_w2 = ((cost_function(w1, w2 + h, b) - cost_function(w1, w2, b)) / h); 
        float distance_bias = ((cost_function(w1, w2, b + h) - cost_function(w1, w2, b)) / h); 

        w1 -=  step_size * distance_cost_function_w1;
        w2 -=  step_size * distance_cost_function_w2;
        b -=  step_size * distance_bias;


        printf("cost = %f, w1 = %f, w2 = %f, bias = %f\n", cost_function(w1, w2, b), w1, w2, b);
    }


    for ( size_t i=0; i < 2; ++i)
    {
        for( size_t j=0; j < 2; ++j)
        {
            printf("%ld | %ld = %f\n", i, j, sigmoidf(i*w1 + j*w2 + b));
        }
    }


    return 0;

}

