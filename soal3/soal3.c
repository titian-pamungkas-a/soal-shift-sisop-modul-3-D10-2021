#include <pthread.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int cekfile(const char *file);
void *pindah(void *);
void ceksemuafile(char *current);

int main(int argc, char *argv[])
{
    if (strcmp(argv[1], "-f") == 0)
    {
        pthread_t thread;
        int i;
        for (i = 2; i < argc; i++)
        {
            int ada = cekfile(argv[i]);
            if (ada)
                printf("File %d : Berhasil Dikategorikan\n", i-1);
            else
                printf("File %d : Sad, gagal :(\n", i-1);
            int err = pthread_create(&thread, NULL, pindah, (void *)argv[i]);
            pthread_join(thread, NULL);
        }
    }
    else if (strcmp(argv[1], "-d") == 0)
    {
    	ceksemuafile(argv[2]);
        struct stat status;
        int err = stat(argv[2], &status);
        if (err == -1)
            printf("Yah, gagal disimpan :(\n");
        else
            printf("Direktori sukses disimpan!\n");
    }
    else if (strcmp(argv[1], "*") == 0){
        char cwd[PATH_MAX];
        if (getcwd(cwd, sizeof(cwd)) != NULL)
        {
            ceksemuafile(cwd);
        }
    }
}

int cekfile(const char *file)
{
    struct stat status;
    if (stat(file, &status) == 0) return 1;
    else return 0;
}

void *pindah(void *name)
{
    char cwd[PATH_MAX];
    char path[50], newfile[50], currentfile[50], newpath[50];
    char hide[50], hidden[50];
    strcpy(currentfile, name);
    strcpy(hidden, name);
    char *x = strrchr(hidden, '/');
    strcpy(hide, x);
    if (hide[1] == '.')
    {
        strcpy(path, "Hidden");
    }
    else if (strstr(name, ".") != NULL)
    {
        strcpy(newfile, name);
        strtok(newfile, ".");
        char *token = strtok(NULL, "");
        int i;
        for (i = 0; token[i]; i++)
        {
            token[i] = tolower(token[i]);
        }
        strcpy(path, token);
    }
    else
        strcpy(path, "Unknown");
    if (cekfile(currentfile))
        mkdir(path, 0777);
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        char *nama = strrchr(name, '/');
        strcpy(newpath, cwd);
        strcat(newpath, "/");
        strcat(newpath, path);
        strcat(newpath, nama);
        rename(name, newpath);
    }
}

void ceksemuafile(char *current)
{
    char path[200];
    struct dirent *p;
    struct stat status;
    DIR *dir = opendir(current);
    int n = 0;
    if (!dir)
        return;
    while ((p = readdir(dir)) != NULL)
    {
        if (strcmp(p->d_name, ".") != 0 && strcmp(p->d_name, "..") != 0 && strcmp(p->d_name, "soal3.c") != 0 && strcmp(p->d_name, "soal3") != 0)
        {
            strcpy(path, current);
            strcat(path, "/");
            strcat(path, p->d_name);
            if (stat(path, &status) == 0 && S_ISREG(status.st_mode))
            {
                pthread_t thread;
                int err = pthread_create(&thread, NULL, pindah, (void *)path);
                pthread_join(thread, NULL);
            }
            ceksemuafile(path);
        }
    }
    closedir(dir);
}
