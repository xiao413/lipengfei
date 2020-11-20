#include <sys/stat.h>	
#include <fcntl.h>		
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
 
int main(int argc,char *argv[])
{
 
	DIR *dir;    //目录流指针
	struct dirent *rent;    //dirent结构体
 
	dir=opendir(".");    //打开当前目录
 
	char str[100];
	memset(str,0,100);
	
	while((rent=readdir(dir)))
	{
		strcpy(str,rent->d_name);
		if(str[0]=='.')
			continue;
		printf("%s  ",str);
		
	}
	//换行
	//printf("\n");
			puts("");	
			 
			 	closedir(dir);
			 		
		 			return 0;
			 			}
