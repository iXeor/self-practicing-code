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
		printf("添加成功！\n");
	}
	else {
		printf("剩余空间不足\n");
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
		printf("删除成功！\n");
	}
	else printf("文件名不存在！\n");
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
		printf("位示图：\n");
		dispmap();
		break;
	case 2:
		printf("增加文件\n请输入文件名：\n");
		rewind(stdin);
		gets(fname);
		printf("请输入文件所占区块数：\n");
		scanf("%d", &blocksize);
		alloc(fname,blocksize);
		break;
	case 3:
		printf("删除文件\n请输入文件名：\n");
		rewind(stdin);
		gets(fname);
		deleteFileblock(fname);
		break;
	case 4:
		printf("显示各块所对应文件名：\n");
		dispFilename();
		break;
	default:
		break;
	}
}
void autoexec() {
	while (1) {
		system("cls");
		printf("请选择要使用的功能：\n(1) 显示位示图\n(2) 增加文件\n(3) 删除文件\n(4) 显示各块对应文件名\n(-1) 退出\n");
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