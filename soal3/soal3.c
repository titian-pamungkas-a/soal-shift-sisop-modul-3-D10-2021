#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
//#include <sys/wait.h>
#include <dirent.h>

int main(int argc, char* argv[]){
	DIR *d;
  	struct dirent *dir;
  	d = opendir(".");
  	int i, j;
  	char str[] = "Titian.casd";
  	char type[10];
  	if (d) {
    	/*while ((dir = readdir(d)) != NULL) {
      		printf("%s\n", dir->d_name);
      		
    	}*/
    	//printf("%d %s\n", argc, argv[0]);
    	//mkdir("nasdal");
    	for (i=1;i<argc;i++){
    		//printf("%s", str.substr(2, 4));
    		//printf("%d %s\n", argc, argv[0]);
   			char * token = strtok(str, ".");
			while( token != NULL ) {
				//printf("%d %s\n", argc, argv[0]);
   				//printf( "%s\n", token ); //printing each token
   				strcpy(type, token);
   				token = strtok(NULL, ".");
   				
			}
			//printf( "%s\n", type );
			mkdir(type);
			rename(type, type);
		}

    	closedir(d);
  	}
  return(0);
}

