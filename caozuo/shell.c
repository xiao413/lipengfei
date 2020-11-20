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
#define buffsize 1024

void whoami_();
void rename_();
void clear_();

void pwd_();
void mkdir_();
void rmdir_();

void date_();
void list_();
void touch_();
void find_();



void exit_();
void error_();
#define buffsize 1024

int main()
{
	char string[30];
	while(1)
	{
	                printf("$");
		scanf("%s",string);
		fflush(stdin);//清空输入缓冲区
		if(strcmp(string,"whoami")==0)
		{
			whoami_();
		}
		else if(strcmp(string,"rename")==0)
                {
                        rename_();
                }
                else if(strcmp(string,"clear")==0)
                {
                        clear_();
                }
                else if(strcmp(string,"pwd")==0)
		{
			pwd_();
		}
		else if(strcmp(string,"mkdir")==0)
                {
                        mkdir_();
                }

		else if(strcmp(string,"rmdir")==0)
                {
                        rmdir_();
                }
                else if(strcmp(string,"date")==0)
		{
			date_();
		}
                
                else if(strcmp(string,"touch")==0)
                {
                        touch_();
                }
                 else if(strcmp(string,"ls")==0)
                {
                        list_();
                }
                else if(strcmp(string,"find")==0)
                {
                        find_();
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
	uid_t id;//定义用户id类型
	struct passwd * pa;
	id=geteuid();//获得有效用户名
	pa=getpwuid(id);//通过用户的uid查找用户的passwd数据，返回空指针
	printf("%s\n",pa->pw_name);//输出pa所指向的结构体包含的数据项id赋值给变量
}

void rename_()
{
	char newname[30],oldname[30];//定义字符	
	scanf("%s%s",oldname,newname);
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
        char dir1[10];
	int a;
        scanf("%s",dir1);
        fflush(stdin);
	a = mkdir(dir1,0755);
        if(a != 0)
                printf("新建目录失败!\n");
}

void rmdir_()
{
        char dir2[10];
	int b;
        scanf("%s",dir2);
	fflush(stdin);//清空输入缓冲区
        b = rmdir(dir2);
	if(b != 0)
                printf("删除目录失败!\n");

}

void date_()
{
	time_t t;
	time(&t);
	printf("时间为: %s", ctime(&t));
}


void list_()
{
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
	}

void touch_()
        {
        char str1[30];
	scanf("%s",str1);
        fflush(stdin);
        if(access(str1,F_OK)==0){
		 									struct timespec newtime[2];	 									                                
//mytouch 命令的核心模块用于创建或者更新文件时间戳		 
        newtime[0].tv_nsec=UTIME_NOW;		 			
        newtime[1].tv_nsec=UTIME_NOW;		 	
        utimensat(AT_FDCWD,str1,newtime,0);	
        }else{								                     open(str1,O_CREAT,0644);		 				//函数 open 是 UNIX 系统的系统调用函shu 	                                	
}					                                	}
        
void find_(){		 							       char str1[30],str2[30];
       scanf("%s",str1);                               
       fflush(stdin);		 		
       scanf("%s",str2);		 					       fflush(stdin);		 						       list_(str1,str2);                              
           }				                                	void error_()	 									                                						{                                					       printf("输入错误!\n");						
        }
void exit_()
        {		 							     exit(0);		 							        }
