#include<stdio.h>
#include<cstdio>
#include<iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define MAX_NUM 1024

int main(int argc, char* argv[])
{   
    char buf[MAX_NUM];  /*������*/
    FILE* fp;            /*�ļ�ָ��*/
    int len;             /*���ַ�����*/
	int flag = 0;
	int total = 0;
	if (argc != 3) {
		printf("��������ȷ�Ĳ���!");
		return 0;
	}
	for (int i = 0; i < 2; i++) {
		if (argv[1][0] == '-' && flag == 0 && i == 0) {
			flag = 1;
		}
		if (argv[1][1] == 'c' && flag == 1) {
			if ((fp = fopen(argv[2], "r")) == NULL)
			{
				perror("fail to read");
				exit(1);
			}
			//�ļ���ȡ������������˳�
			while (!feof(fp) && !ferror(fp)) {
				fgets(buf, MAX_NUM, fp);//ÿ�ζ�ȡһ�л���MAX_NUM���ַ�
				len = strlen(buf);
				if (buf[len - 1] == '\n') {
					buf[len - 1] = '\0';  //ȥ�����з������
					len--;
				}
				if (len == 0) continue;	//�����հ���
				total += len;
			}
			printf("�ı��е��ַ���Ϊ��%d \n", total);
			break;
		}
		else if (argv[1][1] == 'w' && flag == 1) {
			if ((fp = fopen(argv[2], "r")) == NULL)
			{
				perror("fail to read");
				exit(1);
			}
			//�ļ���ȡ������������˳�
			while (!feof(fp) && !ferror(fp)) {
				if (fgets(buf, MAX_NUM, fp) != NULL) {
					len = strlen(buf);
					total++;
					for (i = 0; i < len - 1; i++) {
						if (buf[i] == ' ' || buf[i] == ',') {
							total++;
						}

					}
				}

			}
			printf("�ı��еĵ�����Ϊ��%d \n", total);
		}

	}
	return 0;
}
