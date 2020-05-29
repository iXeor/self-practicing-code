#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
typedef struct {
	char filename[1024];
	int if_using;
} bitmap;
bitmap bmap[16][16];
char fname[1024];
void init() {
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			strcpy(bmap[i][j].filename,"NULL");
			bmap[i][j].if_using = 0;
		}
	}
}
int checkFreespace() {
	int freespace = 0;
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			if (bmap[i][j].if_using == 0) {
				freespace++;
			}
		}
	}
	return freespace;
}
int checkFileexist(char fileName[]) {
	int count = 0;
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			if (strcmp(bmap[i][j].filename,fileName) == 0) {
				count++;
			}
		}
	}
	if (count == 0) return 0;
	else return 1;
}
void alloc(char filename[],int blocksize) {
	int count = 0;
	if (blocksize <= checkFreespace()) {
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 16; j++) {
				if (bmap[i][j].if_using == 0 && count != blocksize) {
					strcpy(bmap[i][j].filename, filename);
					bmap[i][j].if_using = 1;
					count++;
				}
			}
		}
		printf("��ӳɹ���\n");
	}
	else {
		printf("ʣ��ռ䲻��\n");
	}
}
void deleteFileblock(char filename[]) {
	if (checkFileexist(filename)) {
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 16; j++) {
				if (strcmp(bmap[i][j].filename, filename) == 0) {
					bmap[i][j].if_using = 0;
					strcpy(bmap[i][j].filename, "NULL");
				}
			}
		}
		printf("ɾ���ɹ���\n");
	}
	else printf("�ļ��������ڣ�\n");
}
void dispmap() {
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			printf("%d ", bmap[i][j].if_using);
		}
		printf("\n");
	}
}
void dispFilename() {
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			printf("%s ", bmap[i][j].filename);
		}
		printf("\n");
	}
}
void selector(int x) {
	int blocksize;
	switch (x) {
	case 1:
		system("cls");
		printf("λʾͼ��\n");
		dispmap();
		break;
	case 2:
		printf("�����ļ�\n�������ļ�����\n");
		rewind(stdin);
		gets(fname);
		printf("�������ļ���ռ��������\n");
		scanf("%d", &blocksize);
		alloc(fname,blocksize);
		break;
	case 3:
		printf("ɾ���ļ�\n�������ļ�����\n");
		rewind(stdin);
		gets(fname);
		deleteFileblock(fname);
		break;
	case 4:
		printf("��ʾ��������Ӧ�ļ�����\n");
		dispFilename();
		break;
	default:
		break;
	}
}
void autoexec() {
	while (1) {
		system("cls");
		printf("��ѡ��Ҫʹ�õĹ��ܣ�\n(1) ��ʾλʾͼ\n(2) �����ļ�\n(3) ɾ���ļ�\n(4) ��ʾ�����Ӧ�ļ���\n(-1) �˳�\n");
		int x;
		scanf("%d", &x);
		if (x != -1) {
			selector(x);
			system("pause");
		}
		else break;
	}
}
main() {
	init();
	autoexec();
}