#include<stdio.h>
#include<stdlib.h>
#include "produceConsume.h"
#include <stdbool.h>
#define SIZE 5

int cq[SIZE];
int front=0;
int rear=0;
int cnt=0;

int outCount(){
  return cnt;
}

void send(int data){
	adding(data);
}

int check_speed(float data){
	if (data<30 || data>150 ){
		return 0;
	}else{
		return 1;
	}
}

int check(float data){
	if (data == 0 ){
		return 0;
	}else{
		return 1;
	}
}

void adding(unsigned int data){
	if(cnt!=SIZE){
		cq[rear]=data;
		rear = (rear +1) % SIZE;
		++cnt;
	}
}

void recv1(char** data){
	int tmp;
	tmp = remov();
	if(tmp != -1)
		sprintf(data,"consumed %d",tmp);
	else
		sprintf(data,"consumed nothing");
}

int remov(void){
	int val;
	if(cnt!=0){
		val=cq[front];
		front = (front+1) % SIZE;
		cnt--;
		return val;
	}else
		return -1;

}
