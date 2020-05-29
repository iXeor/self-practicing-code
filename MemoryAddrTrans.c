#include<stdio.h>
int page[100];
int page_size;
int count;
void init() {
	int i = 0;
	while (i < 100) {
		int temp = 0;
		printf("请指定第%d页对应的块号(请输入十六进制正数，输入-1以退出)：\n",i);
		scanf_s("%x",&temp);
		system("CLS");
		if (temp == -1) break;
		else page[i++] = temp;
	}
	
	printf("请输入单页大小：\n");
	scanf_s("%d", &page_size);
	system("CLS");
	for (int j = 0; j < 100; j++) {
		if (page[j] != NULL) ++count;
	}
}
void calc(int hexAddr) {
	int page_number;
	int page_drift;
	int phi_addr;
	if (hexAddr < 0 || hexAddr > count*page_size) {
		printf("非法地址，请重新输入：\n");
		scanf_s("%x", &hexAddr);
		calc(hexAddr);
	}
	else {
		page_number = hexAddr / page_size;
		page_drift = hexAddr % page_size;
		phi_addr = page_size * page[page_number] + page_drift;
		printf("%x", phi_addr);
		}
}
main() {
	int logic_addr;
	init();
	printf("请输入逻辑地址：\n");
	scanf_s("%x", &logic_addr);
	calc(logic_addr);
}