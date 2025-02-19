#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<unistd.h>
#include<string.h>

struct kontainer {
	int kodekt;
	int beratkt;
	char jenisbarang[20];
	struct kontainer *next;
};
typedef struct kontainer kontainer;

int kodeauto=0;
void showdoublelinkedlist(kontainer *head);
void addkontainer(kontainer **head);
void sorting(kontainer **head);
void viewkontainer(kontainer *head);
void cekkontainer(kontainer *head);
void destroyKontainer(kontainer **head);

int main(){
	kontainer *pHead = NULL;
	int pil;
	
	do{
		system("cls");
		printf("1. Tambahkan Gerbong Kereta \n");
		printf("2. Lihat status gerbong\n");
		printf("3. Lihat status gerbong dengan metode double linked list\n");		
		printf("4. Delete data\n");
		printf("5. exit \n");
		printf("Pilih menu : ");
		scanf("%d", &pil);
		
		switch(pil){
			case  1 :
				addkontainer(&pHead);
				sorting(&pHead);
				break;
			case  2 :
				viewkontainer(pHead);
				cekkontainer(pHead);
				getch();
				break;
			case 3 :
				showdoublelinkedlist(pHead);
				getch();
				break;
			case 4 :
				destroyKontainer(&pHead);
				showdoublelinkedlist(pHead);
				getch();
				break;	
			case 5 : 
				printf("exit");
				break;
			default :
				printf("menu has not found!\n");
				break;
		}
	} while(pil != 4);
}

void destroyKontainer(kontainer **pHead){
	kontainer *pTemp, *pCur;
	pTemp = *pHead;
	while(*pHead != NULL){
		if(*pHead == NULL){
			printf("data kosong");
		}
		else if(pTemp->next == NULL){
			printf("2");
			free(pTemp);
			*pHead = NULL;
		}
		else{
			printf("3");
			pCur = *pHead;
			*pHead = pCur->next;
			free(pCur);
		}
	}
	return;
}

void showdoublelinkedlist(kontainer *pHead){
	kontainer *pWalker;
	system("cls");
	pWalker=pHead;
	while (pWalker!=NULL){
		printf("%d->", pWalker->kodekt);
		pWalker=pWalker->next;
	}
	printf("NULL");
}

void addkontainer(kontainer **pHead){
	kontainer *newNode, *pTemp;
	newNode=(kontainer *)malloc(sizeof(kontainer));
	kodeauto++;
	int pil1;
	
	system("cls");
	printf("Tambahkan Gerbong Kereta Api \n\n");
	fflush(stdin);
	newNode->kodekt = kodeauto;
	printf("Masukan berat barang : ");
	scanf("%d", &newNode->beratkt);
	printf("\nPilih jenis barang : \n");
	printf("  1. Pokok \n");
	printf("  2. Sekunder \n");
	printf("  3. Kimia \n");
	printf("pilih menu : ");
	scanf("%d", &pil1);
		switch(pil1){
			case 1 :
				strcpy(newNode->jenisbarang, "pokok");
				break;
			case 2 :
				strcpy(newNode->jenisbarang, "sekunder");
				break;
			case 3 :
				strcpy(newNode->jenisbarang, "kimia");
				break;
			default :
				printf ("your choose has not found! \n");
				break;
		}
	newNode->next = NULL;
		if (*pHead == NULL){
			*pHead = newNode;
		} else {
			pTemp = *pHead;
			while(pTemp->next != NULL){
				pTemp = pTemp->next;
			}
			pTemp->next = newNode;
		}
}

void sorting(kontainer **pHead){
	kontainer *pWalker, *pSwap, *pTemp;
	pWalker = *pHead;
	pSwap = (kontainer *)malloc(sizeof(kontainer));
	
	while(pWalker->next != NULL){
		pTemp = pWalker;
			while(pTemp != NULL){
				if(pTemp->beratkt > pWalker->beratkt){
					pSwap->kodekt = pWalker->kodekt;
					pSwap->beratkt = pWalker->beratkt;
					strcpy(pSwap->jenisbarang, pWalker->jenisbarang);
					pWalker->kodekt = pTemp->kodekt;
					pWalker->beratkt = pTemp->beratkt;
					strcpy(pWalker->jenisbarang, pTemp->jenisbarang);
					pTemp->kodekt = pSwap->kodekt;
					pTemp->beratkt = pSwap->beratkt;
					strcpy(pTemp->jenisbarang, pSwap->jenisbarang);
				}
				pTemp = pTemp->next;
			}
		pWalker = pWalker->next;
	}
}

void viewkontainer(kontainer *pHead){
	kontainer *pWalker;
	pWalker = pHead;
	system("cls");
	
	printf("Lihat data kontainer \n\n");
	
	if(pHead == NULL){
		printf("Data is not found!");
	} else {
		printf("kepala kereta \n");
		while(pWalker != NULL){
			printf("||\n");
			printf("__\n");
			printf("Kode kontainer : %d \n", pWalker->kodekt);
			printf("berat kontainer : %d \n", pWalker->beratkt);
			printf("jenis barang : %s \n", pWalker->jenisbarang);
			printf("__\n");	
			pWalker = pWalker->next;
		}
	}
}

void cekkontainer(kontainer *pHead){
	kontainer *pWalker;
	pWalker = pHead;
	int flag=1;
	
	printf("Pengecekan kontainer\n\n");
	
	if (pHead == NULL){
		printf("Data kontainer has not found for to the chek \n");
		return;
	}else {
		while(pWalker->next != NULL){
			if((strcmp(pWalker->jenisbarang, "pokok")==0) && (strcmp(pWalker->next->jenisbarang,"Kimia")==0) || (strcmp(pWalker->jenisbarang, "kimia")==0) && (strcmp(pWalker->next->jenisbarang, "sekunder")==0)){
				printf("kontainer %d berisi %s dan kontainer %d berisi %s tidak boleh berdeketan \n",pWalker->kodekt, pWalker->jenisbarang, pWalker->next->kodekt, pWalker->next->jenisbarang);
				flag = 0;
			}
			pWalker = pWalker->next;
		}
		printf("\n\n");
		if(flag == 0){
			printf("PENGIRIMAN TIDAK DAPAT DILAKUKAN\n\n");
		}else if (flag == 1){
			printf("PENGIRIMANAN DAPAT DIKIRIM\n\n");
		}
	}
}

