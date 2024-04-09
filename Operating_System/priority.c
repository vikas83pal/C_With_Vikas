#include<stdio.h>

int main() {

    int n;
    printf("Enter The Number of processes: ");
    scanf("%d", &n);

    int p[n], bt[n], tat[n], wt[n], temp,pt[n],ct[n];
    float avgwt = 0, avgtat = 0;

    for (int i = 0; i < n; i++) {
        printf("Enter The Burst Time Of P%d: ", i);
        scanf("%d", &bt[i]);
        printf("Enter The priority Of P%d: ", i);
        scanf("%d",&pt[i]);
        p[i] = i;
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (pt[j] > pt[j + 1]) {
                
                
                temp = pt[j];
                pt[j] = pt[j + 1];
                pt[j + 1] = temp;
                
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    
    int sum=0;
    for(int i=0;i<n;i++){
       sum=sum+bt[i];
       ct[i]=sum;
       }

    wt[0] = 0;

    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        avgwt=avgwt+wt[i];

    }
    for (int i = 0; i < n; i++) {


        tat[i] = wt[i] + bt[i];
        avgtat=avgtat+tat[i];
    }

    printf("Process\tBt\tCt\tTat\twt\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("Average Waiting Time: %f\n", avgwt/n);
    printf("Average Turnaround Time: %f\n", avgtat/n);

    return 0;
}