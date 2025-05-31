/* (1) 지능형전자시스템전공, (2) 2310131, (3) 김수안, (4) main.c (5) 2025.05.31 */
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//연결리스트 노드 구조
typedef struct listN{
	int key;
	struct listN* link; //nodepointer 
}listN; 
//노드 생성
void addLastNode(listN* h, int x){
	listN* newNode;
	listN* temp;
	newNode=(listN*)malloc(sizeof(listN));
	newNode->key = x;
	newNode->link = NULL;
	if(h==NULL){ //공백리스트 
		h=newNode; //헤더다음첫노드 
		return;
	}
	temp=h;//첫노드 
	while(temp->link!=NULL){ //끝노드도착하면끝 
		temp=temp->link; //전진 
	}
	temp->link = newNode; //끝노드의 링크가 
} 
//선택정렬함수
void selectionSort(listN* h){ //키값비교, 작은거 맨앞
	//포인터
	listN *min, *temp, *lock;
	lock = h;
	min = h;
	temp = h->link; //다음거부터비교 
	int change;
	while(lock!=NULL){//비교할것이없다 
		while(temp!=NULL){
			if(min->key > temp->key){
				min=temp;
			}
			temp=temp->link;
		}
		change = lock->key;
		lock->key = min->key; //최소값이 처음으로 
		min->key = change;
		//증가
		lock=lock->link;//다음에 고정할것 
		min=lock;
		temp=lock->link;
	}
}
//이진탐색  **헤더노드 바꾸고 mid계산만 
int binsearch(listN* h,int key,listN* left, listN* right, int* time)
{ 
	listN* mid;
	for(i=0;i<31/2;i++){
		if(front)
	}
	if(left->key <=right->key)
	{
		int mid = (left+right)/2;
		*time= *time+1; //역참조, 밑에서 비교 
		if(key == a[mid]) return mid;
		else if(key < mid->key) return binsearch(a,key,left,mid++,time);
		else if(key > mid->key) return binsearch(a,key,mid++,right,time);
	}
	else return -1; //못찾음 
}
int main(int argc, char *argv[]) {
	//연결리스트 정렬검색
	//입력정의
	int a[31]={66,2,67,69,8,11,43,49,5,6,70,71,73,75,48,12,14,7,15,24,46,42,51,55,56,59,1,3,80,96,99};
	//0.입력받아 연결리스트 형성
	listN* listh; //리스트포인터 
	listh=NULL; 
	int i;
	for(i=0;i<31;i++){
		addLastNode(listh,a[i]); 
	}
	//1.정렬: 31개의 수 입력으로 받아 선택정렬로 정렬 
	selectionSort(listh);
	//2.이진탐색 프로그램 구현
	
	//3.출력 : 숫자존재여부, 몇번째노드인지
	 
	return 0;
}
