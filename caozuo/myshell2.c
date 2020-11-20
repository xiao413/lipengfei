#include<stdio.h>
#include<dirent.h>
#include<stddef.h>
#include<string.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<pwd.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<fcntl.h>
#include<time.h>
#include<sys/time.h>
#define MAXPATH 50

void rename_();
void clear_();
void whoami_();

void exit_();
void error_();
void pwd_();
void mkdir_();

void rmdir_();
void date_();
void cat_();
void touch_();
void list_();

#define buffsize 1024
int main()
{
	char string[30];
	while(1)
	{
	        printf("$");
		scanf("%s",string);
		fflush(stdin);
		if(strcmp(string,"whoami")==0)
		{
			whoami_();
		}
		else if(strcmp(string,"rename")==0)
                {
                        rename_();
                }
                else if(strcmp(string,"date")==0)
		{
			date_();
		}
		else if(strcmp(string,"pwd")==0)
		{
			pwd_();
		}
		else if(strcmp(string,"mkdir")==0)
                {
                        mkdir_();
                }
                else if(strcmp(string,"ls")==0)
                 {
                          list_();
                 }
		else if(strcmp(string,"rmdir")==0)
                {
                        rmdir_();
                }

		else if(strcmp(string,"clear")==0)
                {
                        clear_();
                }
                else if(strcmp(string,"cat")==0)
                {
                        cat_();
                }
                else if(strcmp(string,"touch")==0)
                {
                        touch_();
                }
                else if(strcmp(string,"exit")==0)
		{
			exit_();
		}
               
		else
			error_();
	}
	return 0;
}


void whoami_()
{
	uid_t id;
	struct passwd * pa;
	id=geteuid();
	pa=getpwuid(id);
	printf("%s\n",pa->pw_name);
}

void rename_()
{
	char newname[30],oldname[30];
	printf("pleace input the old name:");
	scanf("%s",oldname);
	fflush(stdin);
	printf("pleace input the new name:");
	scanf("%s",newname);
	fflush(stdin);
	if(rename(oldname,newname)!=0)
	{
		printf("change name default!");
	}
}

void clear_()
{
	printf("\x1b[H\x1b[2J");
}

void pwd_()
{
	char path[MAXPATH];
	puts(getcwd(path,MAXPATH));
}

void mkdir_()
{
        char argc[30];
        scanf("%s",argc);
        fflush(stdin);
        if(mkdir(argc,0755)!=0)
                printf("mkdir default!\n");
}

void rmdir_()
{
        char dir[30];
        scanf("%s",dir);
        rmdir(dir);

}

void date_()
{
	time_t t;
	time(&t);
	printf("Today's date and time: %s", ctime(&t));
}

void cat_(int argc,char *argv[])
{
  
      if(argc == 2)//将文件中的打印到标准输出
      {
          FILE *fp;
          if( !(fp = fopen( argv[1], "r" )) )
         {
             fprintf(stderr,"cannot open file %s.",argv[1]);
             exit(-1);
         }
         int c;
         while( (c = fgetc(fp) ) != EOF )
         {
             fputc(c,stdout);
         }
         fclose(fp);
     }
     else if( argc == 3)
     {
         FILE *src ;
         FILE *dest;
         if( !( src = fopen( argv[1], "r" ) ) )
         {
             fprintf(stderr, "%s: cannot open file %s\n", argv[0],argv[1]);
             exit(-1);
         }
         if( !( dest = fopen( argv[2], "w+" ) ) )
         {
             fprintf(stderr, "%s: cannot open file %s\n", argv[0],argv[1]);
             exit(-1);
         }
         int c;
         while( (c = fgetc(src))!=EOF)
         {
             fputc(c,dest);
         }
         fclose(src);
         fclose(dest);
     } 
 
}


void touch_()
{
	char str1[30];
	scanf("%s",str1);
	fflush(stdin);
	if(access(str1,F_OK)==0){
		struct timespec newtime[2];
		newtime[0].tv_nsec=UTIME_NOW;
		newtime[1].tv_nsec=UTIME_NOW;
		utimensat(AT_FDCWD,str1,newtime,0);
	}else{
		open(str1,O_CREAT,0644);
	}
}

void list_()
{
	char command4[50];
	struct dirent *entry;
	DIR *olist=NULL;
	scanf("%s",command4);
	fflush(stdin);
	if((olist=opendir(command4))==NULL)
	{
		printf("opendir  default!\n");
	}
	while(entry=readdir(olist))
	{
		if(strncmp(entry->d_name,".",1) == 0 )
			continue;
		printf("%s\t",entry->d_name);
	}
	printf("\n");
	if(closedir(olist)!=0)
		printf("closedir  default!\n");
}

      
void error_()
{
	printf("input default!\n");
}
void exit_()
{
	exit(0);
}

