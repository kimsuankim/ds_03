/* (1) ���������ڽý�������, (2) 2310131, (3) �����, (4) main.c (5) 2025.05.31 */
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//���Ḯ��Ʈ ��� ����
typedef struct listN{
	int key;
	struct listN* link; //nodepointer 
}listN; 
//��� ����
void addLastNode(listN* h, int x){
	listN* newNode;
	listN* temp;
	newNode=(listN*)malloc(sizeof(listN));
	newNode->key = x;
	newNode->link = NULL;
	if(h==NULL){ //���鸮��Ʈ 
		h=newNode; //�������ù��� 
		return;
	}
	temp=h;//ù��� 
	while(temp->link!=NULL){ //����嵵���ϸ鳡 
		temp=temp->link; //���� 
	}
	temp->link = newNode; //������� ��ũ�� 
} 
//���������Լ�
void selectionSort(listN* h){ //Ű����, ������ �Ǿ�
	//������
	listN *min, *temp, *lock;
	lock = h;
	min = h;
	temp = h->link; //�����ź��ͺ� 
	int change;
	while(lock!=NULL){//���Ұ��̾��� 
		while(temp!=NULL){
			if(min->key > temp->key){
				min=temp;
			}
			temp=temp->link;
		}
		change = lock->key;
		lock->key = min->key; //�ּҰ��� ó������ 
		min->key = change;
		//����
		lock=lock->link;//������ �����Ұ� 
		min=lock;
		temp=lock->link;
	}
}
//����Ž��  **������ �ٲٰ� mid��길 
int binsearch(listN* h,int key,listN* left, listN* right, int* time)
{ 
	listN* mid;
	for(i=0;i<31/2;i++){
		if(front)
	}
	if(left->key <=right->key)
	{
		int mid = (left+right)/2;
		*time= *time+1; //������, �ؿ��� �� 
		if(key == a[mid]) return mid;
		else if(key < mid->key) return binsearch(a,key,left,mid++,time);
		else if(key > mid->key) return binsearch(a,key,mid++,right,time);
	}
	else return -1; //��ã�� 
}
int main(int argc, char *argv[]) {
	//���Ḯ��Ʈ ���İ˻�
	//�Է�����
	int a[31]={66,2,67,69,8,11,43,49,5,6,70,71,73,75,48,12,14,7,15,24,46,42,51,55,56,59,1,3,80,96,99};
	//0.�Է¹޾� ���Ḯ��Ʈ ����
	listN* listh; //����Ʈ������ 
	listh=NULL; 
	int i;
	for(i=0;i<31;i++){
		addLastNode(listh,a[i]); 
	}
	//1.����: 31���� �� �Է����� �޾� �������ķ� ���� 
	selectionSort(listh);
	//2.����Ž�� ���α׷� ����
	
	//3.��� : �������翩��, ���°�������
	 
	return 0;
}
