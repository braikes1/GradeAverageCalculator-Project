#include <stdio.h>

const int STD = 2;
const int EXM = 3;

void input(float (*x)[EXM]);
void calculate_stdavg(float (*x)[EXM], float *stdavg);
void calculate_exmavg(float (*x)[EXM], float *exmavg);
void display(float (*x)[EXM], float *stdavg, float *exmavg);

int main() {
    float grades[STD][EXM];
    float stdavg[STD], exmavg[EXM];
    input(grades);
    calculate_stdavg(grades, stdavg);
    calculate_exmavg(grades, exmavg);
    display(grades, stdavg, exmavg);
    return 0;
}

void input(float (*x)[EXM]){
    for (int i = 0; i < STD; i++){
        for (int j = 0; j < EXM; j++){
            printf("Enter grades for Exam %d of Student %d: ", j+1, i+1);
            scanf("%f", *(x + i) + j);
        }
        printf("\n");
    }
}

void calculate_stdavg(float (*x)[EXM], float *stdavg){
    for (int i = 0; i < STD; i++){
        float sum = 0;
        for(int j = 0; j < EXM; j++){
            sum += *(*(x + i) + j);
        }
        *(stdavg + i) = sum / EXM;
    }
}

void calculate_exmavg(float (*x)[EXM], float *exmavg){
    for (int i = 0; i < EXM; i++){
        float sum = 0;
        for(int j = 0; j < STD; j++){
            sum += *(*(x + j) + i);
        }
        *(exmavg + i) = sum / STD;
    }
}

void display(float (*x)[EXM], float *stdavg, float *exmavg){
    for (int i = 0; i < STD; i++){
        for(int j = 0; j < EXM; j++){
            printf("Student: %d, grades for Exam %d is: %.2f\n", i+1, j+1, *(*(x + i) + j));
        }
        printf("Student %d Average grades are: %.2f\n", i+1, *(stdavg + i));
        printf("\n");
    }
    for(int i = 0; i < EXM; i++){
        printf("Average of Exam %d is %.2f\n", i+1, *(exmavg + i));
    }
}

