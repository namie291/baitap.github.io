#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
struct city_st;
	  	void NhapN(city_st fc[],int n );
	  	void hienthithongtinthanhpho(struct city_st ht);
	  	void sapxeptheoten(struct city_st *fc,int n);
	  	void thongkethanhpho(struct city_st *fc,int n);
	  	void timtheoquocgia(struct city_st *fc,int n);
	  	void timtheonam(struct city_st *fc,int n);
        void hienthiDSTP(struct city_st*, int n);
        void hienthitheoCot();
	    void ghiFile(struct city_st* fc,int n);

    struct city_st
	  {
		  char city_nm[30];
		  char country[30];
		  int year,Stt;
	  }; 
	  
	typedef struct city_st cs;
	  	  
	void NhapN(city_st fc[],int n )
	  {
	        for(int i=0;i<n;i++)
	         {  
		       printf("\n\tNhap thong tin  thanh pho thu:%d",i+1);
		       printf("\nNhap so thu tu cho thanh pho thu %d :",i+1);
		       scanf("%d",&fc[i].Stt);
		       printf("\n\tNhap ten thanh pho:");
		       fflush(stdin);
		       gets(fc[i].city_nm);
		       printf("\n\tNhap quoc gia :");
		       fflush(stdin);
		       gets(fc[i].country);
		       printf("\n\tNhap nam thanh lap :");
		       scanf("%d",&fc[i].year);
		     } 
	  }
    void hienthithongtinthanhpho(struct city_st ht)
              {
              	printf("||%-3d||%-20s ||%-20s ||%-20d \n",ht.Stt, ht.city_nm,ht.country,ht.year);
            
			  }
	void sapxeptheoten(struct city_st *fc,int n)
			  {
			  	int i,j;
			for(i=0;i<n-1;i++)
              {
                for(j=n-1;j>i;j--)
                    {
                  if(strcmp(fc[j].city_nm,fc[j-1].city_nm)>0)
                    	{
                    	    struct city_st a=fc[j];
                    	   	fc[j]=fc[j-1];
                    	   	fc[j-1]=a;
						}
					}
			   }
			  }
			void thongkethanhpho(struct city_st *fc,int n)
			    {
				   char QuocGia[30];
				   int dem=0;
				   city_st city_QG[50];
				   printf("\nNhap quoc gia ban muom tim so thanh pho :");
				   fflush(stdin);
				   gets(QuocGia);
			for(int i=0; i<n; i++)
			   {
	        	if(strcmp(fc[i].country, QuocGia) == 0)
				{
		           dem+=1;
		           city_QG[dem-1]=fc[i];
		        }
            	} 
	        if(dem>0)
			  {
	             printf("Theo thong ke ta duoc :\n **** %s co %d thanh pho\n", QuocGia, dem); 
              }
           else
	             printf("Khong co thanh pho nao thuoc quoc gia nay\n"); 	 
}
	void timtheoquocgia(struct city_st *fc,int n)
		   {
		   	char city_nm[30];
		   	printf("Nhap Quoc Gia :");
		   	fflush(stdin);
		   	gets(city_nm);
		   	hienthitheoCot();
		   	int i,timS=0;
		   	for(i=0;i<n;i++)
		   	   {
		   	   	 if(strcmp(city_nm,fc[i].country)==0)
		   	   	    { 
		   	   	        hienthithongtinthanhpho(fc[i]);
		   	   	        timS =1;
				    }
			   }
				 if(timS ==0)
				     {
				       	printf("\n Khong co thanh pho thuoc quoc gia nay !",city_nm);
				     }
		   	
		   }
	void timtheonam(struct city_st *fc,int n)
		    {
		    	int nam;
		    	printf("\nNhap nam :");
		    	scanf("%d",&nam);
		    	hienthitheoCot();
		    	int timS=0;
		    for(int i=0;i<n;i++)
		    	 {
		    	   if(nam == fc[i].year)
		    		 {
		    			hienthithongtinthanhpho(fc[i]);
		    			timS=1;
					 }
				 }
				   if(timS ==0)
				    {
					     printf("\n khong co thanh pho thuoc nam nay!");
			     	}
			}
	void hienthitheoCot()
		  {
			   printf("-----------------------------------------------------""-----------------------------\n");
	           printf("||%-2s||%-20s ||%-20s ||%-30s \n", "STT" , "Ten", "Quoc Gia", "Nam" );
				
				
		  }
	void hienthiDSTP(struct city_st *fc,int n)
		  {
			  	hienthitheoCot();
			    	for(int i=0;i<n;i++)
			    	  {
			    	  	hienthithongtinthanhpho(fc[i]);
					  }
					  	printf("------------------------------------------""-----------------------------\n");
	      }
	void ghiFile(struct city_st* fc,int n)
		  {
		    FILE *fnp;
	        fnp=fopen("city.dat", "w");
	        fprintf(fnp, "STT||%-20s||%-20s||%s\n", "Ten", "Quoc gia", "Nam"); 
	    for(int i=0; i<n; i++)
		  {
		if(i<=8) 
            fprintf(fnp, "00%d||%-20s||%-20s||%d\n", i+1, fc[i].city_nm, fc[i].country, fc[i].year);
		else 
		    fprintf(fnp, "0%d||%-20s||%-20s||%d\n", i+1, fc[i].city_nm, fc[i].country, fc[i].year);
          }   
            fclose(fnp);
		  }
		

    int main()
	  {
	    int n,key;
     	struct city_st fc[MAX];
    	bool daNhap = false;
	do{
		printf("\nNhap so luong thanh pho ");
		scanf("%d",&n);
	  }while(n<=0);
	while(true){
		system("cls");
		printf("                       ------------------------------------------------------\n");
		printf("                       |          Chuong Trinh Quan Li Thanh Pho            |\n");
		printf("                       |      1. Nhap du lieu cua tung thanh pho.           |\n");
		printf("                       |      2. Hien thi thong tin cac thanh pho.          |\n");
		printf("                       |      3. Sap xep,thong ke thanh pho theo thu tu Z->A|\n");
		printf("                       |      4.Tim thanh pho theo quoc gia.                |\n");
		printf("                       |      5. Tim thanh pho theo nam.                    |\n");
		printf("                       |      6. Ghi vao tap tin nhi phan city.dat.         |\n");
		printf("                       |      0. Thoat chuong trinh.                        |\n");
		printf("                       ------------------------------------------------------\n");
		printf("                       ------------------- vui long chon !-------------------\n");
		scanf("%d",&key);
		switch(key){
			case 1:
				printf("Ban da chon nhap thong tin cho thanh pho\n");
			NhapN(fc,n);
				printf("Ban da nhap thanh cong !\n");
			daNhap = true;
				printf("Bam bat ki phim nao de tiep tuc !");
				 getch();
				break;
			case 2:
			if (daNhap){
				printf("Ban da  chon hien thi thong tin thanh pho! \n");
			hienthiDSTP(fc,n);
				}
				else {
					printf("Ban can phai nhap thong tin thanh pho truoc! \n");
				}
				printf("Bam bat ki phim nao de tiep tuc\n");
				  getch();
				break;
			case 3:
				if(daNhap){
					printf("Ban da chon sap xep theo thu tu Z -> A \n");
					printf("Thong tin thanh pho sau khi sap xep :\n");
				sapxeptheoten(fc,n);
				hienthiDSTP(fc,n);
					printf("Nhap quoc gia ban muon tim kiem so thanh pho :\n");
				thongkethanhpho(fc,n);
				}
				else{
					printf("Ban phai nhap thong tin thanh pho truoc!\n");
				}
				printf("Bam bat ki phim nao de tiep tuc!");
				getch();
				break;
			
			case 4:
				if(daNhap){
					printf("Ban da chon tim thanh pho theo theo quoc gia !\n");
					timtheoquocgia(fc,n);
				}
				else{
					printf("Ban phai nhap thong tin cho thanh pho truoc!\n");
				}
				printf("Bam bat ki phim nao de tiep tuc\n");
				getch();
				break;
			case 5:
				if(daNhap){
					printf("Ban da chon tim thanh pho theo nam !\n");
					timtheonam(fc,n);
				}
				else{
					printf("Ban phai nhap thong tin cho thanh pho truoc!\n");
				}
				printf("Bam bat ki phim nao de tiep tuc\n");
				getch();
				break;
			case 6:
				if(daNhap){
					printf("Ban da chon ghi vao tap tin nhi phan city.dat !\n");
				ghiFile(fc,n);
				}
				else{
					printf("Ban phai nhap thong tin cho thanh pho truoc!\n");
				}
				printf("Bam bat ki phim nao de tiep tuc\n");
				  getch();
				break;
			case 0:
				printf("Thoat khoi chuong trinh :\n");
				getch();
				return 0;
			default :
				printf("Khong co chuc nang nay\n");
				printf("Bam phim bat ki de tiep tuc!");
				  getch();
				break;	
			}	
		}
	}
