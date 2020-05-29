#include<stdio.h>
typedef struct  processBlock {
	char processName[2];
	int timeBlockSize;
	int processPriority;
	int if_finished;
} PB;
PB process[]={"P1",10,3,0,"P2",1,1,0,"P3",2,3,0,"P4",1,4,0,"P5",5,2,0};
int procCheck(PB proc) {
	if (proc.timeBlockSize <= 0) {
		proc.if_finished = 1;
	}
	return proc.if_finished;
}
int allProcCheck(PB proc[]) {
	int a=0;
	for (int i = 0; i < 5; i++) {
		a += procCheck(proc[i]);
	}
	return a;
}
void TimingCalc(PB proc[]) {
	printf("进程周转时间统计：\n");
	int times = 5;
	int j = 4;
	while (times != -1) {
		int time = 0;
		for (int i = 0; i < times; i++) {
			time += proc[i].timeBlockSize;
		}
		if (j != -1) {
			printf("进程名称：%s\t|\t", proc[j--].processName);
		}
		if (time != 0) {
			printf("周转时间：%d\n", time);
		}
		times--;
	}
}
void waitingTimingCalc(PB proc[]) {
	printf("进程等待时间统计：\n");
	int times = 4;
	int advtime = 0;
	int t = 4;
	int j = 4;
	while (times != -1) {
		int time = 0;
		for (int i = 0; i < times; i++) {
			time += proc[i].timeBlockSize;
		}
		if (j != -1) {
			printf("进程名称：%s\t|\t", proc[j--].processName);
		}

		printf("等待时间：%d\n", time);
		times--;
	}
	printf("--------------\n平均等待时间：\n--------------\n");
	while (t != -1) {
		for (int i = 0; i < t; i++) {
			advtime += proc[i].timeBlockSize;
		}
		t--;
	}
	printf("%0.1f\n", ((float)advtime / 5.0));
}
void SPF(){
	PB temp;
	PB SPFArray[5];
	for (int j = 0; j < 5; j++) {
		SPFArray[j] = process[j];
	}
	for (int l = 0; l < 5; l++) {
		for (int i = 0; i < 4; i++) {
			if (SPFArray[i].timeBlockSize > SPFArray[i + 1].timeBlockSize) {
				temp = SPFArray[i];
				SPFArray[i] = SPFArray[i + 1];
				SPFArray[i + 1] = temp;
			}
		}
	}
	printf("短进程调度法进程调度顺序:\n");
	for (int k = 0; k < 5; k++) {
		if (k + 1 < 5) {
			printf("%s->", SPFArray[k].processName);
		}
		else printf("%s\n\n", SPFArray[k].processName);
	}
	TimingCalc(SPFArray);
	waitingTimingCalc(SPFArray);
	printf("-----------------------------------------------\n");
}
void PSA() {
	PB temp;
	PB PSAArray[5];
	for (int j = 0; j < 5; j++) {
		PSAArray[j] = process[j];
	}
	for (int l = 0; l < 5; l++) {
		for (int i = 1; i < 5; i++) {
			if (PSAArray[i-1].processPriority < PSAArray[i].processPriority) {
				temp = PSAArray[i];
				PSAArray[i] = PSAArray[i - 1];
				PSAArray[i - 1] = temp;
			}
		}
	}
	printf("非剥夺优先级调度法进程调度顺序:\n");
	for (int k = 0; k < 5; k++) {
		if (k + 1 < 5) {
			printf("%s->", PSAArray[k].processName);
		}
		else printf("%s\n\n", PSAArray[k].processName);
	}
	TimingCalc(PSAArray);
	waitingTimingCalc(PSAArray);
	printf("-----------------------------------------------\n");
}
void RR(int timeBlock) {
	PB RRArray[5];
	int i = 0;
	int a = 0;
	int count = 0;
	int data[5];
	int datab[5];
	for (int j = 0; j < 5; j++) {
		RRArray[j] = process[j];
	}
	printf("时间片轮转调度法进程调度顺序:\n");
	while (allProcCheck(RRArray) != 5) {
		int x = i % 5;
		if (procCheck(RRArray[x]) == 0) {
			RRArray[x].timeBlockSize -= timeBlock;
			printf("%s->", RRArray[x].processName);
			if (RRArray[x].timeBlockSize >= 0) data[x] = (count+1)*timeBlock;
			else data[x] = count*timeBlock+process[x].timeBlockSize % 2;
			count++;
		}
		i++;
	}
	printf("END\n\n");
	printf("进程周转时间统计：\n");
	for (int k = 0; k < 5; k++) {
		printf("进程名称：%s\t|\t周转时间：%d\n",RRArray[k].processName,data[k]);
	}
	printf("进程等待时间统计：\n");
	for (int m = 0; m < 5; m++) {
		datab[m] = data[m] - process[m].timeBlockSize;
		printf("进程名称：%s\t|\t等待时间：%d\n", RRArray[m].processName, datab[m]);
	}
	printf("--------------\n平均等待时间：\n--------------\n");
	for (int n = 0; n < 5; n++) {
		a += datab[n];
	}
	printf("%0.1f\n", (float)a/5.0);
	printf("-----------------------------------------------\n");
}
int main() {	
	SPF();
	system("PAUSE");
	system("CLS");
	PSA();
	system("PAUSE");
	system("CLS");
	RR(2);
}