/* (1) ���������ڽý�������, (2) 2310131, (3) �����, (4) main.c (5) 2025.05.31 */
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//���Ḯ��Ʈ ��� ����
typedef struct listN{
	int key;
	struct listN* link; //nodepointer 
}listN; 
//������:front,rear,length
typedef struct head{
	int length;
	listN *front, *rear;
}head; 
//��� ����
void addLastNode(head* h, int x){
	listN* newNode;
	listN* temp;
	newNode=(listN*)malloc(sizeof(listN));
	newNode->key = x;
	newNode->link = NULL;
	if(h->length==0){ //���鸮��Ʈ 
		h->front= h->rear =newNode;
	}
	else{
		temp=h->front;//ù��� 
		while(temp->link!=NULL){ //����嵵���ϸ鳡 
		temp=temp->link; //���� 
		}
		temp->link = newNode; //������� ��ũ��
		h->rear = newNode;
	}
	 
} 
//���������Լ�
void selectionSort(head* h){ //Ű����, ������ �Ǿ�
	//������
	listN *min, *temp, *lock;
	lock = min = h->front;//ù��� 
	temp = h->front->link; //�����ź��ͺ� 
	int change;
	while(lock!=NULL){//���Ұ��̾���
	min=lock;
	temp=lock->link; 
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
	}
}
//���° ������� ã��
int ordernode (listN* front, listN* result){ //������ ������ ���� 
	int n=1;
	listN* temp = front; //���� 
	while(temp!=result){ //ó������ ������ ù��°��� 
		temp=temp->link;
		n++;
	}
	return n;
}
//�߰��� ���ϱ�
listN* findmid(listN* left, listN* right){
	int n = ordernode(left, right);
	listN* mid = left; //������ 
	int i;
	for(i=0;i<n/2;i++){ //�տ������� �߰����� 
		mid = mid->link;
	}
	return mid;
} 
//����Ž��  **������ �ٲٰ� mid��길 
listN* binsearch(head* h,int key,listN* left, listN* right)
{ 
	listN* mid;
	mid = findmid(left, right);
	//if(mid == NULL) return NULL;
	if(left->key < right->key) //�ߺ����� ���� 
	{
		if(key == mid->key) return mid;
		else if(key < mid->key) return binsearch(h,key,left,mid);
		else if(key > mid->key) return binsearch(h,key,mid->link,right);
	}
	else return NULL; //��ã�� 
}

int main(int argc, char *argv[]) {
	//���Ḯ��Ʈ ���İ˻�
	//�Է�����
	int a[31]={66,2,67,69,8,11,43,49,5,6,70,71,73,75,48,12,14,7,15,24,46,42,51,55,56,59,1,3,80,96,99};
	//0.�Է¹޾� ���Ḯ��Ʈ ����
	head* listh = (head*)malloc(sizeof(head)); //����Ʈ��� 
	listh->length=0;
	listh->front=listh->rear = NULL; 
	int i;
	for(i=0;i<31;i++){
		addLastNode(listh,a[i]); 
		listh->length++; //�ϳ��� ���� 
	}
	//1.����: 31���� �� �Է����� �޾� �������ķ� ���� 
	selectionSort(listh);
	//2.����Ž�� ���α׷� ����
	int key; //ã�� ���� 
	printf("�˻������Է�: ");
	scanf("%d",&key);
	listN* result = binsearch(listh, key, listh->front, listh->rear);
	int index = ordernode(listh->front, result);
	//3.��� : �������翩��, ���°�������
	if(result==NULL){
		printf("False\n");
		printf("No Result in List\n");
	} else {
		printf("True\n");
		printf("%d��%d���� ��忡 �����Ѵ�.\n", result->key, index);
	}
	return 0;
}
