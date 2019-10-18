#include "parse.h"


using namespace std;

void read_program_file(string filename, list<string>& program)  {
    string line;
    ifstream infile(filename);

    if (infile.is_open())  {
        while (getline(infile, line))
        {
            program.push_back(line);
            // cout << line << '\n';
        }
        infile.close();
    } else  cout << "Unable to open file";



    // FILE *fp;
    // char str[MAX_PROGRAM_LINE_LEN];
    // int count = 0;
    // char **trimmed_program;
    // (*program_str) = (char **)malloc(MAX_PROGRAM_LEN * sizeof(char *));

    // fp = fopen(filename, "r");
    // if (fp == NULL) {
    //     printf("Could not open file %s", filename);
    //     exit(0);
    // }

    // while (fgets(str, MAX_PROGRAM_LINE_LEN, fp) != NULL)  {
    //     (*program_str)[count] = (char *)malloc(strlen(str) * sizeof(char));
    //     strcpy((*program_str)[count], str);

    //     count++;
    // }
    // printf("\n");
    // fclose(fp);

    // trimmed_program = (char **)realloc((*program_str), count*sizeof(char*));
    // (*program_str) = trimmed_program;

    // printf("Contents:\n", count);

    // for (int j = 0; j < count; j++) {
    //     printf("\t\t%s", (*program_str)[j]);
    // }
    // printf("\n");


}

int find_fn(char *fn, char ***program, int program_len)  {
    int correct_letters = 0;
    for (int i = 0; i < program_len; i++)  {
        correct_letters = 0;
        for (int l = 0; l < strlen(fn); l++)  {
            if (fn[l] != (*program)[i][l])  break;
            correct_letters++;
        }
        if (correct_letters == strlen(fn))  return i+1;
    }
    return -1;
}