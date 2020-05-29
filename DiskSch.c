#include<stdio.h>
#include<math.h>
typedef struct diskInfo {
	int trackNo;
	int if_scanned;
} DI;
DI diskSch[200];
DI temptable[200];
int disk_pos = 0;
int counter(DI disk[]) {
	int i = 0;
	while (1) {
		if (disk[i].trackNo != -1) {
			i++;
		}
		else break;
	}
	return i;
}
void rstScan(DI diskSch[]) {
	for (int a = 0; a < 200; a++) {
		diskSch[a].if_scanned = 0;
	}
}
int findPos(DI disk[]) {
	int i = 0;
	while (1) {
		if (disk[i].trackNo != -1)
		{
			if (disk_pos <= disk[i].trackNo) break;
			else i++;
		}
		else break;
	}
	return i;
}
void diskJobinit(DI disk[]) {
	for (int a = 0; a < 200; a++) {
		disk[a].trackNo = -1;
		rstScan(disk);
	}
	int i = 0;
		while (i < 200) {
			int trackNum;
			printf("ÇëÊäÈëÐèÒª·ÃÎÊµÄ´ÅµÀºÅ£¨ÊäÈë-1ÒÔÍË³ö£©:\n");
			scanf_s("%d", &trackNum);
			if (trackNum == -1) break;
			else {
				diskSch[i].trackNo = trackNum;
				i++;
			}
			system("CLS");
		}
}
void jobSorter(DI disk[]){
	for (int i = 0; i < 200; i++) {
		for (int j = 0; j < 199; j++) {
			int temp;
			if (disk[j].trackNo > disk[j + 1].trackNo && disk[j].trackNo != -1 && disk[j+1].trackNo != -1) {
				temp = disk[j].trackNo;
				disk[j].trackNo = disk[j + 1].trackNo;
				disk[j + 1].trackNo = temp;
			}
		}
	}
}
void init(DI disk[]) {
	system("COLOR 1f");
	diskJobinit(disk);
	system("CLS");
	printf("ÇëÊäÈë´ÅÍ·Î»ÖÃ£º\n");
	scanf_s("%d", &disk_pos);
	system("CLS");
	jobSorter(disk);
}
void func_C_look(DI disk[]) {
	printf("C-LOOKËã·¨´ÅµÀÉ¨ÃèË³Ðò£º\n");
	rstScan(disk);
	int i = findPos(disk);
	printf("%d->", disk_pos);
	while (1) {
		if (disk[i % 200].if_scanned == 0) {
			if (disk[i % 200].trackNo != -1) {
				printf("%d->", disk[i % 200].trackNo);
			}
			disk[i % 200].if_scanned = 1;
			i++;
		}
		else {
			printf("END\n");
			break;
		}
	}
}
void func_look(DI disk[]) {
	printf("LOOKËã·¨´ÅµÀÉ¨ÃèË³Ðò£º\n");
	rstScan(disk);
	int i = findPos(disk);
	int temp;
	temp = i - 1;
	printf("%d->", disk_pos);
	while (i<200) {
		if (disk[i].if_scanned == 0) {
			if (disk[i].trackNo != -1) {
				printf("%d->", disk[i].trackNo);
			}
			disk[i].if_scanned = 1;
			i++;
		}
		else break;
	}
	while (temp >= 0) {
		if (disk[temp].if_scanned == 0) {
			if (disk[temp].trackNo != -1) {
				printf("%d->", disk[temp].trackNo);
			}
			disk[temp].if_scanned = 1;
			temp--;
		}
		else break;
	}
	printf("END\n");
}
void func_SSTF_proc(DI disk[]) {
	rstScan(disk);
	int i = 0;
	int min=2147483647;
	int index=0;		
	while (1) {
		if (disk[i].trackNo != -1) {
			if (temptable[i].if_scanned != 1) {
				temptable[i].trackNo = abs(disk[i].trackNo - disk_pos);
			}
			else temptable[i].trackNo = 0;
			i++;
		}
		else break;
	}
	for (int x = 0; x < i; x++) {
		if (min > temptable[x].trackNo && temptable[x].trackNo != 0) {
			min = temptable[x].trackNo;
			index = x;
		}
	}
	printf("%d->", disk[index].trackNo);
	disk_pos = disk[index].trackNo;
	temptable[index].if_scanned = 1;
}
void func_SSTF_main(DI disk[]) {
	int j = counter(disk);
	int count = 0;
	printf("SSTFËã·¨´ÅµÀÉ¨ÃèË³Ðò£º\n%d->", disk_pos);
	for (count; count < j; count++) {
		func_SSTF_proc(disk);
	}
	printf("END\n");
}
int main() {
	init(diskSch);
	func_C_look(diskSch);
	func_look(diskSch);
	func_SSTF_main(diskSch);
}