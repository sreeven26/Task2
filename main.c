#include <stdio.h>
#include "student.h"
#include "validation.h"
#include "grading.h"
#include "display.h"

int main() {
    struct Students s[MAX], temp;
    FILE *fp = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");

    int n, count = 0;
    fscanf(fp, "%d", &n);

    for (int i = 0; i < n; i++) {
        int valid = 1;

        fscanf(fp, "%s", temp.id);
        if (!validID(temp.id, s, count)) {
            fprintf(fout, "Invalid/Duplicate ID: %s\n", temp.id);
            valid = 0;
        }

        fscanf(fp, "%s", temp.name);
        if (!validName(temp.name)) {
            fprintf(fout, "Invalid Name: %s\n", temp.name);
            valid = 0;
        }

        temp.total = 0;
        for (int j = 0; j < subs; j++) {
            fscanf(fp, "%d", &temp.marks[j]);
            if (!validMarks(temp.marks[j]))
                valid = 0;
            temp.total += temp.marks[j];
        }

        if (valid) {
            temp.percentage = temp.total / 5.0;
            assignGrade(&temp);
            s[count++] = temp;
        } else {
            fprintf(fout, "Record skipped.\n");
        }
    }

    if (count > 0)
        display(s, count, fout);
    else
        fprintf(fout, "No valid student record found.\n");

    fclose(fp);
    fclose(fout);
    return 0;
}

// to run: gcc main.c validation.c grading.c display.c -o result
