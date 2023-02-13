// Online C compiler to run C program online
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Mahasiswa{
	int id;
	char nama[50];
	char fakultas[60];
	char jurusan[60];
	char kota_asal[60];
	float ipk;
	struct Mahasiswa *next;
}Mahasiswa;

Mahasiswa *head_mhs = NULL, *current_mhs = NULL;

int autoIncrementMahasiswa(){
	int id=0;
	for(current_mhs = head_mhs;current_mhs;current_mhs=current_mhs->next)
		id = current_mhs->id;
	return id+1;
}

void TambahMahasiswa(){
	Mahasiswa mhs, *node;
	printf("Masukan Nama : ");
	scanf(" %[^\n]",mhs.nama);
	printf("Masukan Fakultas : ");
	scanf(" %[^\n]",mhs.fakultas);
	printf("Masukan Jurusan : ");
	scanf(" %[^\n]",mhs.jurusan);
	printf("Masukan Kota Asal : ");
	scanf(" %[^\n]",mhs.kota_asal);
	printf("Masukan IPK : ");
	scanf("%f",&mhs.ipk);
	
	node = (Mahasiswa*)malloc(sizeof(Mahasiswa));
	node->id=autoIncrementMahasiswa();
	strcpy(node->nama, mhs.nama);
	strcpy(node->fakultas, mhs.fakultas);
	strcpy(node->jurusan, mhs.jurusan);
	strcpy(node->kota_asal, mhs.kota_asal);
	node->ipk=mhs.ipk;
	node->next = NULL;
	
	if(head_mhs==NULL){
		head_mhs=node;
	}else{
		current_mhs=head_mhs;
		while(current_mhs->next!=NULL)
			current_mhs = current_mhs->next;
		current_mhs->next=node;
	}
}

void EditMahasiswa(){
	int id,ditemukan=0;
	printf("Enter ID Mahasiswa Yang Ingin Diedit : ");
	scanf("%d",&id);
	
	current_mhs=head_mhs;
	while(current_mhs!=NULL){
		if(current_mhs->id==id){
			printf("Masukan Nama : ");
			scanf("%s",current_mhs->nama);
			printf("Masukan Fakultas : ");
			scanf("%s",current_mhs->fakultas);
			printf("Masukan Jurusan : ");
			scanf("%s",current_mhs->jurusan);
			printf("Masukan Kota : ");
			scanf("%s",current_mhs->kota_asal);
			printf("Masukan IPK : ");
			scanf("%f",&current_mhs->ipk);
			ditemukan=1;
		}
		current_mhs = current_mhs->next;
	}
	if(ditemukan){
		printf("\n\nData Mahasiswa Berhasil Diedit!\n\n");
	}else{
		printf("\n\nData Mahasiwa Tidak Ditemukan!\n\n");
	}
	system("pause");
}

void hapusMahasiswa(){
	int id,ditemukan=0;
	printf("Enter ID Mahasiswa Yang Ingin Diedit : ");
	scanf("%d",&id);
	
	current_mhs=head_mhs;
	if(current_mhs->id==id){
		head_mhs=current_mhs->next;
		free(current_mhs);
		ditemukan=1;
	}
	while(current_mhs->next!=NULL){
		Mahasiswa *tmp = current_mhs->next;
		if(tmp->id==id){
			current_mhs->next=tmp->next;
			free(tmp);
			ditemukan=1;
			break;
		}
		current_mhs=current_mhs->next;
	}
	if(ditemukan){
		printf("\n\nData Mahasiswa Berhasil Dihapus!\n\n");
	}else{
		printf("\n\nData Mahasiwa Tidak Ditemukan!\n\n");
	}
	system("pause");
}

void readMahasiswaFile(){
	head_mhs = NULL, current_mhs = NULL;
	FILE *fp=fopen("Data_Mahasiswa.txt","r");
	Mahasiswa mhs1, *node;
	while(fscanf(fp,"%d,%[^,],%[^,],%[^,],%[^,],%f\n",&mhs1.id,mhs1.nama,mhs1.fakultas,mhs1.jurusan,
	mhs1.kota_asal,&mhs1.ipk)!=EOF){
		node = (Mahasiswa*)malloc(sizeof(Mahasiswa));
		node->id = mhs1.id;
		strcpy(node->nama,mhs1.nama);
		strcpy(node->fakultas,mhs1.fakultas);
		strcpy(node->jurusan,mhs1.jurusan);
		strcpy(node->kota_asal,mhs1.kota_asal);
		node->ipk=mhs1.ipk;
		node->next = NULL;
		
		if(head_mhs == NULL){
			current_mhs = head_mhs = node;
		}else{
			current_mhs = current_mhs->next = node;
		}
	}
	fclose(fp);
}

void writeMahasiswaFile(){
	FILE *fp=fopen("Data_Mahasiswa.txt","w");
	
	for(current_mhs=head_mhs;current_mhs;current_mhs=current_mhs->next){
		fprintf(fp,"%d,%s,%s,%s,%s,%.2f\n",current_mhs->id,current_mhs->nama,
		current_mhs->fakultas,current_mhs->jurusan,current_mhs->kota_asal,current_mhs->ipk);
	}
	
	fclose(fp);
}

void TampilkanMahasiswa(){
	printf("\n%-5s%-23s%-15s%-35s%-10s%10s\n","ID","Nama","Fakultas","Jurusan","Kota Asal","IPK");
	printf("------------------------------------------------------------------------------------------------------------\n");
	for(current_mhs=head_mhs;current_mhs!=NULL;current_mhs=current_mhs->next){
		printf("%-5d%-23s%-15s%-35s%-10s%10.2f\n",current_mhs->id,current_mhs->nama,
		current_mhs->fakultas,current_mhs->jurusan,current_mhs->kota_asal,current_mhs->ipk);
	}
	printf("------------------------------------------------------------------------------------------------------------\n\n\n");
	system("pause");
}

int main() {
	int menu;
	readMahasiswaFile();
    do{
    	system("cls");
    	printf("\n-----------------------------------------");
    	printf("\n\t\tMenu Mahasiswa");
    	printf("\n-----------------------------------------");
    	printf("\n1. Tambah Data");
    	printf("\n2. Edit Data");
    	printf("\n3. Hapus Data");
    	printf("\n4. Tampilkan Data");
    	printf("\n0. Keluar Program");
    	printf("\n-----------------------------------------");
    	printf("\nMasukan Pilihan : ");
    	scanf("%d",&menu);
    	
    	switch(menu){
    		case 1:TambahMahasiswa();break;
    		case 2:EditMahasiswa();break;
    		case 3:hapusMahasiswa();break;
    		case 4:TampilkanMahasiswa();break;
    		case 0:
			writeMahasiswaFile();
			printf("\n\nData Telah Disimpan Pada File (Data_Mahasiswa.txt)\n\n");
			system("pause");
			break;
    		default:break;
		}
	}
	while(menu!=0);
    return 0;
}
