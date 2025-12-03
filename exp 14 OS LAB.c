#include <stdio.h>
#include <string.h>

struct File {
    char name[20];
};

int main() {
    struct File dir[10];
    int count = 0;
    int ch, i;
    char f[20];

    while (1) {
        printf("1. Add file\n2. Search file\n3. List files\n4. Exit\nEnter choice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter file name to add: ");
            scanf("%s", f);
            if (count < 10) {
                strcpy(dir[count++].name, f);
            } else {
                printf("Directory full!\n");
            }
        }
        else if (ch == 2) {
            printf("Enter file name to search: ");
            scanf("%s", f);
            int found = 0;
            for (i = 0; i < count; i++) {
                if (strcmp(f, dir[i].name) == 0) {
                    found = 1;
                    printf("Found %s\n", f);
                    break; // stop after first match
                }
            }
            if (!found) {
                printf("Not found\n");
            }
        }
        else if (ch == 3) {
            printf("Files in directory:\n");
            for (i = 0; i < count; i++) {
                printf("%s\n", dir[i].name);
            }
        }
        else if (ch == 4) {
            break;
        }
        else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

