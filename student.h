#ifndef STUDENT_H
#define STUDENT_H

#define subs 5
#define MAX 100

struct Students {
    char id[30];
    char name[50];
    int marks[subs];
    int total;
    float percentage;
    char grade[3];
    float cgpa;
};

#endif
