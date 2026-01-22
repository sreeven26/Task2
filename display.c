#include "display.h"

void display(struct Students s[], int n, FILE *fout) {
    float avg = 0, max = s[0].percentage, min = s[0].percentage;
    int gradeCount[8] = {0};

    fprintf(fout,"\nID       Name    S1  S2  S3  S4  S5  Total  Percent  Grade  CGPA\n");
    for (int i = 0; i < n; i++) {
        fprintf(fout,"%s %s   ", s[i].id, s[i].name);
        for (int j = 0; j < subs; j++)
            fprintf(fout,"%d  ", s[i].marks[j]);

        fprintf(fout,"%d    %.2f    %s      %.2f\n",
               s[i].total, s[i].percentage, s[i].grade, s[i].cgpa);

        avg += s[i].percentage;
        if (s[i].percentage > max) max = s[i].percentage;
        if (s[i].percentage < min) min = s[i].percentage;

        if (s[i].grade[0] == 'O') gradeCount[0]++;
        else if (s[i].grade[0] == 'A' && s[i].grade[1] == '+') gradeCount[1]++;
        else if (s[i].grade[0] == 'A') gradeCount[2]++;
        else if (s[i].grade[0] == 'B' && s[i].grade[1] == '+') gradeCount[3]++;
        else if (s[i].grade[0] == 'B') gradeCount[4]++;
        else if (s[i].grade[0] == 'C') gradeCount[5]++;
        else if (s[i].grade[0] == 'D') gradeCount[6]++;
        else gradeCount[7]++;
    }

    avg /= n;

    fprintf(fout,"\nClass Statistics\n");
    fprintf(fout,"Class Average Percentage : %f\n", avg);
    fprintf(fout,"Highest Percentage       : %f\n", max);
    fprintf(fout,"Lowest Percentage        : %f\n", min);

    fprintf(fout,"\nGrade Distribution\n");
    fprintf(fout,"O  : %d\nA+ : %d\nA  : %d\nB+ : %d\nB  : %d\nC  : %d\nD  : %d\nF  : %d\n",
           gradeCount[0], gradeCount[1], gradeCount[2],gradeCount[3], gradeCount[4], gradeCount[5],gradeCount[6], gradeCount[7]);
}
