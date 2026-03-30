#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {

    float or_w1;
    float or_w2;
    float or_b;

    float nand_w1;
    float nand_w2;
    float nand_b;

    float  and_w1;
    float  and_w2;
    float  and_b;

} Xor;

float sigmoidf(float x)
{
    return 1.f / (1.f + exp(-x));
}

float forward(Xor model, float x1, float x2)
{
    float a = sigmoidf(model.or_w1*x1 + model.or_w2*x2 + model.or_b); // first layer
    float b = sigmoidf(model.nand_w1*x1 + model.nand_w2*x2 + model.nand_b); // first layer 

    return sigmoidf( a*model.and_w1 + b*model.and_w2 + model.and_b); // last layer (neuron)
}

typedef float sample[3];
size_t train_count = 4;

// XOR-gate
float xor_train[][3] = {

    {0,0,0},
    {0,1,1},
    {1,0,1},
    {1,1,0},
};

sample *train = xor_train;

float cost_function(Xor model)
{
    float result = 0.0f;

    for (size_t i=0; i < train_count; ++i)
    {
        float x1 = train[i][0];
        float x2 = train[i][1];

        float y = forward(model, x1, x2); 

        float distance = y - train[i][2];
        result += distance * distance;
        
       // printf("predicted = %f, actual = %f\n", y, train[i][1]);
    }

    result /= train_count;

    return result;
}

float rand_float()
{
    return (float) rand() / (float) RAND_MAX;
}

void rand_xor_values(Xor *model)
{
    model->or_w1 = rand_float();
    model->or_w2 = rand_float();
    model->or_b = rand_float();   
            
    model->nand_w1 = rand_float();
    model->nand_w2 = rand_float();
    model->nand_b = rand_float(); 
          
    model->and_w1 = rand_float();
    model->and_w2 = rand_float();
    model->and_b = rand_float();
}

void print_xor(Xor *model)
{
    printf("%f\n",model->or_w1); 
    printf("%f\n",model->or_w2);
    printf("%f\n",model->or_b); 
            
    printf("%f\n",model->nand_w1);
    printf("%f\n",model->nand_w2);
    printf("%f\n",model->nand_b);
         
    printf("%f\n",model->and_w1);
    printf("%f\n",model->and_w2);
    printf("%f\n",model->and_b);

}


Xor finit_diff(Xor model)
{
    Xor gradient;

    float cost = cost_function(model);
    float previous;
    float h = 1e-3;


    previous = model.or_w1;
    model.or_w1 += h;
    gradient.or_w1 = (cost_function(model) - cost) / h;
    model.or_w1 = previous;


    previous = model.or_w2;
    model.or_w2 += h;
    gradient.or_w2 = (cost_function(model) - cost) / h;
    model.or_w2 = previous;


    previous = model.or_b;
    model.or_b += h;
    gradient.or_b = (cost_function(model) - cost) / h;
    model.or_b = previous;

////////////////////////////////////////////////////////

    previous = model.nand_w1;
    model.nand_w1 += h;
    gradient.nand_w1 = (cost_function(model) - cost) / h;
    model.nand_w1 = previous;


    previous = model.nand_w2;
    model.nand_w2 += h;
    gradient.nand_w2 = (cost_function(model) - cost) / h;
    model.nand_w2 = previous;


    previous = model.nand_b;
    model.nand_b += h;
    gradient.nand_b = (cost_function(model) - cost) / h;
    model.nand_b = previous;

////////////////////////////////////////////////////////
    
    previous = model.and_w1;
    model.and_w1 += h;
    gradient.and_w1 = (cost_function(model) - cost) / h;
    model.and_w1 = previous;

    
    previous = model.and_w2;
    model.and_w2 += h;
    gradient.and_w2 = (cost_function(model) - cost) / h;
    model.and_w2 = previous;


    previous = model.and_b;
    model.and_b += h;
    gradient.and_b = (cost_function(model) - cost) / h;
    model.and_b = previous;


    return gradient;
}

Xor train_model(Xor model, Xor gradient, float learning_rate)
{
    model.or_w1 -= learning_rate * gradient.or_w1;
    model.or_w2 -= learning_rate * gradient.or_w2;
    model.or_b -= learning_rate * gradient.or_b;


    model.nand_w1 -= learning_rate * gradient.nand_w1;
    model.nand_w2 -= learning_rate * gradient.nand_w2;
    model.nand_b -= learning_rate * gradient.nand_b;

    model.and_w1 -= learning_rate * gradient.and_w1;
    model.and_w2 -= learning_rate * gradient.and_w2;
    model.and_b -= learning_rate * gradient.and_b;

    return model;
}

int main()
{
    Xor model; 
    rand_xor_values(&model);

    float learning_rate = 1e-2;

    for (int i=0; i < 1000000; ++i)
    {
        Xor gradient = finit_diff(model);
        model = train_model(model, gradient, learning_rate);
        //printf("cost = %f\n", cost_function(model));
        //printf("%f\n", cost_function(model));
    }


    printf("%f\n", cost_function(model));


    for (int i=0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            printf("%d ^ %d = %f\n", i, j, forward(model, i, j));
        }
    }
}












