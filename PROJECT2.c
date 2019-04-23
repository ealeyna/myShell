#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *systemCall(char *array2)
{

    printf("It's me, thread # %s\n", array2);

    system(array2);

    //   printf("Hello World! It's me, thread #%ld!\n", tid);
    //wait(2 * rand());
    //pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    //char str[] ="ls -s ; cat file1.txt | ls -l | cat file2.txt ; grep odevvv file2.txt | ls -l | ls -l";
    //char str[] ="ls -al| pwd ; date";
    //char str[] ="ls -s ; cat file1.txt | ls -l | cat file2.txt ; grep odevvv file2.txt | ls -l | ls -l";
    //"ls -al ; ls -al ; ls -al ; ls -al";
    //"ls -al | ls -al | ls -al | ls -al";
    char *pch;
    char *pch2;

    char str[512];
    char *threadmode[512];
    char *successmode[512];
    int i = 0;
    int threadmodecount = 0;

    if (argv[1] == NULL)
    {
        printf("Please enter your command:>");
        scanf("%[^\n]%*c", str);
        //printf("Girilen %s mesajini parcaliyoruz:n", str);

        pch = strtok(str, "|");

        while (pch != NULL)
        {
            printf("\n");
            printf("Printing pch: %d %s\n", i, pch);
            threadmode[i] = malloc(strlen(pch) + 1);
            strcpy(threadmode[i], pch);
            pch = strtok(NULL, "|");
            i++;
            //result = 1;
        }

        threadmodecount = i;
        //printf("Strlen %d\n", threadmodecount);

        if (threadmodecount != 1)
        {
            for (int i = 0; i < threadmodecount; i++)
            {

                char *str = threadmode[i];
                //printf("ANA STRING %d %s\n", i, str);
                int j = 0;
                pch2 = strtok(str, ";/n");
                while (pch2 != NULL)
                {
                    printf("\n");
                    //printf("Printing pch2: %d %s\n", j, pch2);
                    successmode[j] = malloc(strlen(pch2) + 1);
                    strcpy(successmode[j], pch2);
                    pch2 = strtok(NULL, ";/n");
                    j++;
                }
                if (j == 1)
                {
                    system(successmode[0]);
                }
                else
                {

                    pthread_t threads[j];
                    int rc;

                    for (int t = 0; t < j; t++)
                    {
                        printf("creating thread %ld ", t);
                        printf("for %s\n", successmode[t]);
                        rc = pthread_create(&threads[t], NULL, systemCall, successmode[t]);
                    }
                    for (size_t t = 0; t < i; t++)
                    {
                        //printf("JOIN: creating thread %ld\n", t);
                        rc = pthread_join(threads[t], NULL);
                    }
                }

                /* Last thing that main() should do */
                // pthread_exit(NULL);

                // if(j==1){
                //     system(successmode[0]);
                // }else {
                //   for(int k=0;k<j;k++){
                //         system(successmode[k]);
                //   }

                //successmode arrayindekileri karışık çalıştır.
            }
        }
        else
        {
            pch = strtok(str, ";");
            int j = 0;
            while (pch != NULL)
            {
                printf("\n");
                printf("Printing pch: %d %s\n", j, pch);
                successmode[j] = malloc(strlen(pch) + 1);
                strcpy(successmode[j], pch);
                pch = strtok(NULL, ";");
                j++;
            }
            //printf("Printingj: %d \n", j);
            if (j == 1)
            {
                system(successmode[0]);
            }
            else
            {
                pthread_t threads[j];
                int rc;

                for (int t = 0; t < j; t++)
                {
                    printf("creating thread %d ", t);
                    printf("for %s\n", successmode[t]);
                    rc = pthread_create(&threads[t], NULL, systemCall, successmode[t]);
                }
                //pthread_exit(NULL);

                for (size_t t = 0; t < i; t++)
                {
                    //printf("JOIN: creating thread %ld\n", t);
                    rc = pthread_join(threads[t], NULL);
                }
                //successmode arrayindekileri karışık çalıştır.
            }
        }
    }
    else
    {
        FILE *filep;
        size_t fileLength = 512;
        char *line = malloc(fileLength);
        filep = fopen(argv[1], "r");

        if (filep == NULL)
        {
            printf("Non valid file name please enter again!!!!!\n");
            exit(EXIT_FAILURE);
        }

        while (fgets(line, 500, filep))
        {
            char str[900];
            char str1[900];

            sprintf(str1, "%s", line);

            strcpy(str, "echo \"");
            strcat(str, str1);
            strcat(str, "\"");

            //system(str);
            pch = strtok(str, "|");

            while (pch != NULL)
            {
                printf("\n");
                printf("Printing pch: %d %s\n", i, pch);
                threadmode[i] = malloc(strlen(pch) + 1);
                strcpy(threadmode[i], pch);
                pch = strtok(NULL, "|");
                i++;
            }

            threadmodecount = i;
            //printf("Strlen %d\n", threadmodecount);

            if (threadmodecount != 1)
            {
                for (int i = 0; i < threadmodecount; i++)
                {

                    char *str = threadmode[i];
                    //printf("ANA STRING %d %s\n", i, str);
                    int j = 0;
                    pch2 = strtok(str, ";/n");
                    while (pch2 != NULL)
                    {
                        printf("\n");
                        //printf("Printing pch2: %d %s\n", j, pch2);
                        successmode[j] = malloc(strlen(pch2) + 1);
                        strcpy(successmode[j], pch2);
                        pch2 = strtok(NULL, ";/n");
                        j++;
                    }
                    if (j == 1)
                    {
                        system(successmode[0]);
                    }
                    else
                    {

                        pthread_t threads[j];
                        int rc;

                        for (int t = 0; t < j; t++)
                        {
                            printf("creating thread %ld ", t);
                            printf("for %s\n", successmode[t]);
                            rc = pthread_create(&threads[t], NULL, systemCall, successmode[t]);
                        }
                        for (size_t t = 0; t < i; t++)
                        {
                            //printf("JOIN: creating thread %ld\n", t);
                            rc = pthread_join(threads[t], NULL);
                        }
                    }

                    /* Last thing that main() should do */
                    // pthread_exit(NULL);

                    // if(j==1){
                    //     system(successmode[0]);
                    // }else {
                    //   for(int k=0;k<j;k++){
                    //         system(successmode[k]);
                    //   }

                    //successmode arrayindekileri karışık çalıştır.
                }
            }
            else
            {
                pch = strtok(str, ";");
                int j = 0;
                while (pch != NULL)
                {
                    printf("\n");
                    printf("Printing pch: %d %s\n", j, pch);
                    successmode[j] = malloc(strlen(pch) + 1);
                    strcpy(successmode[j], pch);
                    pch = strtok(NULL, ";");
                    j++;
                }
                //printf("Printingj: %d \n", j);
                if (j == 1)
                {
                    system(successmode[0]);
                }
                else
                {
                    pthread_t threads[j];
                    int rc;

                    for (int t = 0; t < j; t++)
                    {
                        printf("creating thread %d ", t);
                        printf("for %s\n", successmode[t]);
                        rc = pthread_create(&threads[t], NULL, systemCall, successmode[t]);
                    }
                    //pthread_exit(NULL);

                    for (size_t t = 0; t < i; t++)
                    {
                        //printf("JOIN: creating thread %ld\n", t);
                        rc = pthread_join(threads[t], NULL);
                    }
                }
            }
        }

        return 0;
    }
}