#include <string.h>
#include "validation.h"

int validID(char id[], struct Students s[], int count) {
    for (int i = 0; id[i] != '\0'; i++) {
        if (!((id[i] >= 'A' && id[i] <= 'Z') ||
              (id[i] >= 'a' && id[i] <= 'z') ||
              (id[i] >= '0' && id[i] <= '9')))
            return 0;
    }

    for (int i = 0; i < count; i++) {
        if (strcmp(id, s[i].id) == 0)
            return 0;
    }
    return 1;
}

int validName(char name[]) {
    for (int i = 0; name[i] != '\0'; i++) {
        if (!((name[i] >= 'A' && name[i] <= 'Z') ||
              (name[i] >= 'a' && name[i] <= 'z')))
            return 0;
    }
    return 1;
}

int validMarks(int m) {
    return (m >= 0 && m <= 100);
}
