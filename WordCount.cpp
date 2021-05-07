#include<string.h>
#include <stdio.h>
void operate(char*file,char* flag) {//定义文件打开函数，*file为文件位置指针，*flag为命令指针
	
	FILE* f;
	char buffer[1000];//存放字符串的数组
	int len = 0;//文本字符的总长度
	int wordlen = 1;//单词个数
	int symbol = 0;//字符个数
	int ret1;//定义用来标识两个字符串时都相等的，辨别‘-c’
	int ret2;//定义用来标识两个字符串时都相等的，辨别‘-w’
	f = fopen(file, "rb");//打开文件
		while (fgets(buffer, 1000, f) != NULL) {
			len = strlen(buffer);//统计文本字符的总长度
			for (int i = 0;i < len;i++) {//遍历数组
				
					if (buffer[i] == ' ' || buffer[i] == ',') {//根据‘，’和空格统计单词个数
						wordlen++;
					}
				
				if (buffer[i] == ' ' || buffer[i] == '\t' || buffer[i] == '\n') {//统计符号个数
					symbol++;
				}
			}
			ret1=strcmp(flag, "-c");
			ret2 =strcmp(flag, "-w");
			//printf(flag);
			
			if (ret1==0) {
				printf("字符数：%d", symbol);
				
				
			}
			if(ret2 == 0) {
				printf("单词数：%d", wordlen);
			}
			break;
		}
	fclose(f);//关闭文件夹
}
void main(int argc, char*argv[]) {//此处传入两个指针变量
	operate(argv[2], argv[1]);//这里需要注意argv[0]为程序名，所以要从1开始排列
	
}