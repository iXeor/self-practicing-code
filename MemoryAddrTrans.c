#include<stdio.h>
int page[100];
int page_size;
int count;
void init() {
	int i = 0;
	while (i < 100) {
		int temp = 0;
		printf("��ָ����%dҳ��Ӧ�Ŀ��(������ʮ����������������-1���˳�)��\n",i);
		scanf_s("%x",&temp);
		system("CLS");
		if (temp == -1) break;
		else page[i++] = temp;
	}
	
	printf("�����뵥ҳ��С��\n");
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
		printf("�Ƿ���ַ�����������룺\n");
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
	printf("�������߼���ַ��\n");
	scanf_s("%x", &logic_addr);
	calc(logic_addr);
}