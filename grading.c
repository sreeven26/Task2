#include "grading.h"

void assignGrade(struct Students *s) {
    float p = s->percentage;

    if (p >= 90) {
        s->grade[0] = 'O'; s->grade[1] = '\0';
        s->cgpa = 10;
    }
    else if (p >= 85) {
        s->grade[0] = 'A'; s->grade[1] = '+'; s->grade[2] = '\0';
        s->cgpa = 9;
    }
    else if (p >= 75) {
        s->grade[0] = 'A'; s->grade[1] = '\0';
        s->cgpa = 8;
    }
    else if (p >= 65) {
        s->grade[0] = 'B'; s->grade[1] = '+'; s->grade[2] = '\0';
        s->cgpa = 7;
    }
    else if (p >= 60) {
        s->grade[0] = 'B'; s->grade[1] = '\0';
        s->cgpa = 6;
    }
    else if (p >= 55) {
        s->grade[0] = 'C'; s->grade[1] = '\0';
        s->cgpa = 5;
    }
    else if (p >= 50) {
        s->grade[0] = 'D'; s->grade[1] = '\0';
        s->cgpa = 4;
    }
    else {
        s->grade[0] = 'F'; s->grade[1] = '\0';
        s->cgpa = 0;
    }
}
