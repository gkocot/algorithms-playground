#include <stdlib.h>
#include <string.h>

void get_row(char * d, int * index, char * s, size_t l, int row, int column_offset) {
    int i = row;
    int diagonal_offset = 2 * row;
    while (i < l) {
        // printf("%c", s[i]);
        d[*index] = s[i];
        (*index)++;

        if ((diagonal_offset != 0) && (diagonal_offset != column_offset)) {
            if (i + column_offset - diagonal_offset < l) {
                // printf("%c", s[i - diagonal_offset]);
                d[*index] = s[i + column_offset - diagonal_offset];
                (*index)++;
            }
        }

        i += column_offset;
    }
}

void pick_chars1(char * d, int * index, char * s, size_t l, int row, int column_offset) {
    int i = row;
    while (i < l) {
        d[*index] = s[i];
        (*index)++;
        i += column_offset;
    }
}

void pick_chars2(char * d, int * index, char * s, size_t l, int row, int column_offset) {
    int i = row;
    int j = i + column_offset - 2 * row;
    while (i < l) {
        d[*index] = s[i];
        (*index)++;
        i += column_offset;

        if (j < l) {
            d[*index] = s[j];
            (*index)++;
            j += column_offset;
        }
    }
}

char * convert(char * s, int numRows) {
    size_t l = strlen(s);
    int column_offset = numRows > 1 ? (numRows - 2) * 2 + 2 : 1;
    char * result = malloc(l + 1);
    memset(result, 0, l + 1);
    int index = 0;

    // for (int row = 0; row < numRows; row++) {
    //     get_row(result, &index, s, l, row, column_offset);
    // }

    for (int row = 0; row < numRows; row++) {
        if ((row == 0) || (row == numRows - 1)) {
            pick_chars1(result, &index, s, l, row, column_offset);
        }
        else {
            pick_chars2(result, &index, s, l, row, column_offset);
        }
    }

    return result;
}

//"PINALSIGYAHPI
//"PINALSIGYAHRPI"
int main() {
    //printf("%s", convert("A", 1));
    printf("%s", convert("PAYPALISHIRING", 4));
    return 0;
}