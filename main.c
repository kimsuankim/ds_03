/* (1) 지능형전자시스템전공, (2) 2310131, (3) 김수안, (4) main.c (5) 2025.05.31 */
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//연결리스트 노드 구조
typedef struct listN{
	int key;
	struct listN* link; //nodepointer 
}listN; 
//헤더노드:front,rear,length
typedef struct head{
	int length;
	listN *front, *rear;
}head; 
//노드 생성
void addLastNode(head* h, int x){
	listN* newNode;
	listN* temp;
	newNode=(listN*)malloc(sizeof(listN));
	newNode->key = x;
	newNode->link = NULL;
	if(h->length==0){ //공백리스트 
		h->front= h->rear =newNode;
	}
	else{
		temp=h->front;//첫노드 
		while(temp->link!=NULL){ //끝노드도착하면끝 
		temp=temp->link; //전진 
		}
		temp->link = newNode; //끝노드의 링크가
		h->rear = newNode;
	}
	 
} 
//선택정렬함수
void selectionSort(head* h){ //키값비교, 작은거 맨앞
	//포인터
	listN *min, *temp, *lock;
	lock = min = h->front;//첫노드 
	temp = h->front->link; //다음거부터비교 
	int change;
	while(lock!=NULL){//비교할것이없다
	min=lock;
	temp=lock->link; 
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
	}
}
//몇번째 노드인지 찾기
int ordernode (listN* front, listN* result){ //포인터 사이의 길이 
	int n=1;
	listN* temp = front; //시작 
	while(temp!=result){ //처음부터 같으면 첫번째노드 
		temp=temp->link;
		n++;
	}
	return n;
}
//중간값 구하기
listN* findmid(listN* left, listN* right){
	int n = ordernode(left, right);
	listN* mid = left; //시작점 
	int i;
	for(i=0;i<n/2;i++){ //앞에서부터 중간까지 
		mid = mid->link;
	}
	return mid;
} 
//이진탐색  **헤더노드 바꾸고 mid계산만 
listN* binsearch(head* h,int key,listN* left, listN* right)
{ 
	listN* mid;
	mid = findmid(left, right);
	//if(mid == NULL) return NULL;
	if(left->key < right->key) //중복없음 가정 
	{
		if(key == mid->key) return mid;
		else if(key < mid->key) return binsearch(h,key,left,mid);
		else if(key > mid->key) return binsearch(h,key,mid->link,right);
	}
	else return NULL; //못찾음 
}

int main(int argc, char *argv[]) {
	//연결리스트 정렬검색
	//입력정의
	int a[31]={66,2,67,69,8,11,43,49,5,6,70,71,73,75,48,12,14,7,15,24,46,42,51,55,56,59,1,3,80,96,99};
	//0.입력받아 연결리스트 형성
	head* listh = (head*)malloc(sizeof(head)); //리스트헤더 
	listh->length=0;
	listh->front=listh->rear = NULL; 
	int i;
	for(i=0;i<31;i++){
		addLastNode(listh,a[i]); 
		listh->length++; //하나씩 삽입 
	}
	//1.정렬: 31개의 수 입력으로 받아 선택정렬로 정렬 
	selectionSort(listh);
	//2.이진탐색 프로그램 구현
	int key; //찾을 숫자 
	printf("검색숫자입력: ");
	scanf("%d",&key);
	listN* result = binsearch(listh, key, listh->front, listh->rear);
	int index = ordernode(listh->front, result);
	//3.출력 : 숫자존재여부, 몇번째노드인지
	if(result==NULL){
		printf("False\n");
		printf("No Result in List\n");
	} else {
		printf("True\n");
		printf("%d는%d번쨰 노드에 존재한다.\n", result->key, index);
	}
	return 0;
}
