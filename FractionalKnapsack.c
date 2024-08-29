#include<stdio.h>

int fractionKnapsack(int weights[], int profit[], int capacity, int n){
    int i, j;
    double ratio[n];
    //Calculating ratio

    for(i = 0; i < n; i++){
        ratio[i] = (double)profit[i] / weights[i];
    }
    // sorting the ratio in descending order and weight and profit;
    // Here we can change the sorting algorithm for less time complexity;

    for(i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(ratio[i] < ratio[j]){
                double t = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = t;

                t = weights[i];
                weights[i] = weights[j];
                weights[j] = t;

                t = profit[i];
                profit[i] = profit[j];
                profit[j] = t;

            }
        }
    }
    double total_profit = 0;
    int remaining_capacity = capacity;

    // calculating the total profit;
    for(i = 0; i < n; i++){
        if(weights[i] <= remaining_capacity){
            total_profit += profit[i];
            remaining_capacity -= weights[i];
        }
        else{
            double fraction = (double)remaining_capacity/weights[i];
            total_profit += fraction * profit[i];
            break;
        }
    }
    return (int)total_profit;
    
}

int main(){
    int weights[] = {10, 20, 30};
    int profit[] = {60, 100, 120};
    int capacity = 50;
    int n = sizeof(weights) / sizeof(weights[0]);
    float total_profit = fractionKnapsack(weights, profit, capacity, n);

    printf("The maximum profit is: %f\n",total_profit);
    return 0;
}

