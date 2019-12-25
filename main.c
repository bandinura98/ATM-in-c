#include <stdio.h>
#include <string.h>

struct client{
	char name[15];
	char surname[15];
	char clientID[15];
	int Password;
	int debt;
	int money;
};



int main(){
	int i,x,temp,while1 = 0;
	char op[15];
	struct client *c = (struct client*) malloc(1*sizeof(struct client));//bir tane yazılır banka burası
	struct client *d = (struct client*) malloc(1*sizeof(struct client));//only for read
	struct client *u = (struct client*) malloc(1*sizeof(struct client));//for update
	
	
	printf("please chose an operator enter/createaccaunt/exit");
	scanf("%s",op);
	
	if(strcmp(op,"createaccaunt")==0){
	
	
	FILE *temperoryfile = fopen("temp.txt","r");
	fscanf(temperoryfile,"%d",&temp);
	//her hangi bir yazdırma işlemi sonucunda kaybolan verilerin önüne geçmek amaçlı yapılmış bir harekettir
	//temp++;
	fclose(temperoryfile);
	
	
	
	printf("enter client");
	
	printf("enter name : ");
	scanf("%s",c->name);
	
	printf("surname : ");
	scanf("%s",c->surname);
	
	printf("id : ");
	scanf("%s",c->clientID);
	
	printf("pw : ");
	scanf("%d",&c->Password);
	
	c->money = 0;
	c->debt = 0;
		printf("%d",temp);
	struct client *read_write = (struct client*) malloc((temp)*sizeof(struct client));//kayıp olmasını istemediğim verileri oluşturuyorum
	
	FILE *FileInputHolder = fopen("kayit.txt","r+");
	for(i = 0; i < temp; i++){
		
		printf("read operations");
		
	fread(read_write+i,sizeof(struct client),1,FileInputHolder);//hepsini okuyup araziye attık yazınca kaybolma sıkıntısı olmıcak
	}
	strcpy((read_write+(temp-1))->name,c->name);//son elemanın içini doldurmuş bulunmaktayız
	strcpy((read_write+(temp-1))->surname,c->surname);
	strcpy((read_write+(temp-1))->clientID,c->clientID);
	(read_write+(temp-1))->Password = c->Password;
	(read_write+(temp-1))->money = c->money;
	(read_write+(temp-1))->debt = c->debt;
	
	fclose(FileInputHolder);//bütün herşey okunduğu için dosyayı kapatmaktayım daha öncede kapayabilirdim ama yapmamayı keyfe keder tercih ettim
	
	FILE *std ;
	
	std = fopen("kayit.txt","w+");//dosya yazıma açıldı
	
	for(i=0; i<temp; i++){
	
	fwrite((read_write+i),sizeof(struct client),1,std);//içinde temp kadar yer var zaten temp kadar yazsın bırakın
	
	}
	
	fclose(std);//kayıt dosyası yazıma kapanmış bulunmaktadır
	
	
	
	FILE *temperoryfile2 = fopen("temp.txt","w");
	temp++;
	fprintf(temperoryfile2,"%d",temp);//her hangi bir yazdırma işlemi sonucunda kaybolan verilerin önüne geçmek amaçlı yapılmış bir harekettir
	fclose(temperoryfile2);
	
	
	return 0;//intlicez
	}
	else if(strcmp(op,"enter")==0){//kullanıcı girişi için arama yapma bölgesi
	
	
	FILE *temperoryfile = fopen("temp.txt","r");
	fscanf(temperoryfile,"%d",&temp);
	//her hangi bir yazdırma işlemi sonucunda kaybolan verilerin önüne geçmek amaçlı yapılmış bir harekettir
	//temp++;
	fclose(temperoryfile);
	
	
	
	
	FILE *aramafile = fopen("kayit.txt","r+");
	struct client *arayici = (struct client*)malloc((temp)*sizeof(struct client));//dosya boyutu kadar büyük
			
		for(i = 0; i < temp; i++){
			
			printf("read operations");
			
			fread(arayici+i,sizeof(struct client),1,aramafile);//hepsini okuyup araziye attık yazınca kaybolma sıkıntısı olmıcak
			
		}
			fclose(aramafile);
			
			printf("please enter the informations given below \nname : \nsurname : \nID : \npassword : ");
				printf("enter the operaions");
				
				printf("enter name : ");
				scanf("%s",d->name);
				
				printf("surname : ");
				scanf("%s",d->surname);
					
				printf("id : ");
				scanf("%s",d->clientID);
				
				printf("pw : ");
				scanf("%d",&c->Password);
				
				d->money = 0;
				d->debt = 0;
				
				
				printf("import terminated!!!");
				for(i = 0; i < temp-1; i++){
				if(strcmp((arayici+i)->name,d->name)==0){
					
					if(strcmp((arayici+i)->surname,d->surname)==0){
						
						if(strcmp((arayici+i)->clientID,d->clientID)==0){
							
							if((arayici+i)->Password==d->Password){
								printf("login successful");//bütün veriler doğru ise giriş işlemi başarılı çekiyo
								
								while1 = 1;
							}
						}
					}
				}
			}
			
			
			
			
			
			FILE *temperoryfile2 = fopen("temp.txt","w");
			temp++;
			fprintf(temperoryfile2,"%d",temp);//her hangi bir yazdırma işlemi sonucunda kaybolan verilerin önüne geçmek amaçlı yapılmış bir harekettir
			fclose(temperoryfile2);
			
			
			
		}else if(strcmp(op,"exit")==0){
			while1=0;
		}
		
		while(while1){//eft parayatırma havle paraçekme borcagirme 
			printf("please chose your operation given below \neft\ntransfer\nlodgement\nwithdraw_money\ndebt_money\nexit");
			scanf("%s",op);
			if(strcmp(op,"eft")==0){//next update will be soon 
				
				
				FILE *temperoryfile = fopen("temp.txt","r");
				fscanf(temperoryfile,"%d",&temp);
				fclose(temperoryfile);
				
				
				
				char x[15];
				printf("please enter the accaunt number");
				scanf("%s",x);
				
				
				
				c->name[0] = 0;
				c->surname[0] = 0;
				c->clientID[0] = 0;
				
				
				printf("enter money");
				scanf("%d",&c->money);
				
				c->Password = 0;
				c->debt = 0;
				
				

				struct client *arayici = (struct client*)malloc(temp*sizeof(struct client));//dosya boyutu kadar büyük
			

				for(i = 0; i<temp; i++){
					if(strcmp((arayici+i)->clientID,x)==0){
						int inputofamaunt;
						printf("enter the amount");
						scanf("%d",&inputofamaunt);
						
						struct client *arayicii = (struct client*)malloc(1*sizeof(struct client));
						FILE *aarayici =fopen("kayit.txt","r+");//olmadı a+ olmadı w+ w+ 1 s2me yaramaz amma
						for(i = 0;i<temp;i++){
							fread(arayicii,sizeof(struct client),1,aarayici);
							printf("\n\n%s\n\n",d->name);
							if((arayicii+i)->clientID==c->clientID){
								(d)->money-=inputofamaunt;
								//printf("%s",d->name);
								fseek(aarayici,-1*sizeof(struct client), SEEK_CUR);
								fwrite(d,sizeof(struct client),1,aarayici);
							
						}
						if((arayicii+i)->clientID==x){
							(arayicii+i)->money+=inputofamaunt;
								//printf("%s",d->name);
								fseek(aarayici,-1*sizeof(struct client), SEEK_CUR);
								fwrite(arayicii,sizeof(struct client),1,aarayici);
						}
					}fclose(aarayici);
				}
				//clientID
				
				
				
				
				
				
				
				
				
				
				
			}}else if(strcmp(op,"transfer")==0){
						
				
				FILE *temperoryfile = fopen("temp.txt","r");
				fscanf(temperoryfile,"%d",&temp);
				fclose(temperoryfile);
				
				
				
				char x[15];
				printf("please enter the accaunt number");
				scanf("%s",x);
				
				
				
				c->name[0] = 0;
				c->surname[0] = 0;
				c->clientID[0] = 0;
				
				
				printf("enter money");
				scanf("%d",&c->money);
				
				c->Password = 0;
				c->debt = 0;
				
				
				
				struct client *arayici = (struct client*)malloc(temp*sizeof(struct client));//dosya boyutu kadar büyük
			
				
				for(i = 0; i<temp; i++){
					if(strcmp((arayici+i)->clientID,x)==0){
						int inputofamaunt;
						printf("enter the amount");
						scanf("%d",&inputofamaunt);
						
						struct client *arayicii = (struct client*)malloc(1*sizeof(struct client));
						FILE *aarayici =fopen("kayit.txt","r+");//olmadı a+ olmadı w+ w+ 1 s2me yaramaz amma
						for(i = 0;i<temp;i++){
							fread(arayicii,sizeof(struct client),1,aarayici);
							printf("\n\n%s\n\n",d->name);
							if((arayicii+i)->clientID==c->clientID){
								(d)->money-=inputofamaunt;
								//printf("%s",d->name);
								fseek(aarayici,-1*sizeof(struct client), SEEK_CUR);
								fwrite(d,sizeof(struct client),1,aarayici);
							
						}
						if((arayicii+i)->clientID==x){
							(arayicii+i)->money+=inputofamaunt;
								//printf("%s",d->name);
								fseek(aarayici,-1*sizeof(struct client), SEEK_CUR);
								fwrite(arayicii,sizeof(struct client),1,aarayici);
						}
					}fclose(aarayici);
				}
				//clientID
				
				
			}}else if(strcmp(op,"lodgement")==0){
				
				FILE *temperoryfile = fopen("temp.txt","r");
				fscanf(temperoryfile,"%d",&temp);
				//her hangi bir yazdırma işlemi sonucunda kaybolan verilerin önüne geçmek amaçlı yapılmış bir harekettir
				//temp++;
				fclose(temperoryfile);
				
				int imputamt;
				printf("how much RAND do you wanna yatırmaque");//güney afrika cumhuriyeti parası
				scanf("%d",&imputamt);
				
					FILE *aramafile = fopen("kayit.txt","r+");
					struct client *arayici = (struct client*)malloc((temp)*sizeof(struct client));//dosya boyutu kadar büyük
					
					for(i = 0; i < temp; i++){
					
					printf("read operations");
					
					fread(arayici+i,sizeof(struct client),1,aramafile);//hepsini okuyup araziye attık yazınca kaybolma sıkıntısı olmıcak
					}
					
					
						struct client *arayicii = (struct client*)malloc(1*sizeof(struct client));
						FILE *aarayici =fopen("kayit.txt","r+");//olmadı a+ olmadı w+ w+ 1 s2me yaramaz amma
					
					for(i = 0;i<temp;i++){
							fread(arayicii,sizeof(struct client),1,aarayici);
							printf("\n\n%s\n\n",d->name);
							if((arayicii+i)->money==c->money){
								(d)->money+=imputamt;
								//printf("%s",d->name);
								fseek(aarayici,-1*sizeof(struct client), SEEK_CUR);
								fwrite(d,sizeof(struct client),1,aarayici);
							
						}
					
					
					
					
					
		}
			fclose(aramafile);
				
				
				
			
			
			
		}else if(strcmp(op,"withdraw_money")==0){
				
				FILE *temperoryfile = fopen("temp.txt","r");
				fscanf(temperoryfile,"%d",&temp);
				//her hangi bir yazdırma işlemi sonucunda kaybolan verilerin önüne geçmek amaçlı yapılmış bir harekettir
				//temp++;
				fclose(temperoryfile);
				
					
				int imputamt;
				printf("how much RAND do you wanna yatırmaque");//güney afrika cumhuriyeti parası
				scanf("%d",&imputamt);
				
					FILE *aramafile = fopen("kayit.txt","r+");
					struct client *arayici = (struct client*)malloc((temp)*sizeof(struct client));//dosya boyutu kadar büyük
					
					for(i = 0; i < temp; i++){
					
					printf("read operations");
					
					fread(arayici+i,sizeof(struct client),1,aramafile);//hepsini okuyup araziye attık yazınca kaybolma sıkıntısı olmıcak
					}
					
					
						struct client *arayicii = (struct client*)malloc(1*sizeof(struct client));
						FILE *aarayici =fopen("kayit.txt","r+");//olmadı a+ olmadı w+ w+ 1 s2me yaramaz amma
					
					for(i = 0;i<temp;i++){
							fread(arayicii,sizeof(struct client),1,aarayici);
							printf("\n\n%s\n\n",d->name);
							if((arayicii+i)->money==c->money){
								(d)->money-=imputamt;
								//printf("%s",d->name);
								fseek(aarayici,-1*sizeof(struct client), SEEK_CUR);
								fwrite(d,sizeof(struct client),1,aarayici);
							
						}
					
					
					
					
					
	}
			fclose(aramafile);
				
				
				
			}else if(strcmp(op,"debt_money")==0){
				
				FILE *temperoryfile = fopen("temp.txt","r");
				fscanf(temperoryfile,"%d",&temp);
				//her hangi bir yazdırma işlemi sonucunda kaybolan verilerin önüne geçmek amaçlı yapılmış bir harekettir
				//temp++;
				fclose(temperoryfile);
				
					
				int imputamt;
				printf("how much RAND do you wanna yatırmaque");//güney afrika cumhuriyeti parası
				scanf("%d",&imputamt);
				
					FILE *aramafile = fopen("kayit.txt","r+");
					struct client *arayici = (struct client*)malloc((temp)*sizeof(struct client));//dosya boyutu kadar büyük
					
					for(i = 0; i < temp; i++){
					
					printf("read oprations");
					
					fread(arayici+i,sizeof(struct client),1,aramafile);//hepsini okuyup araziye attık yazınca kaybolma sıkıntısı olmıcak
					}
					fclose(aramafile);

					
						struct client *arayicii = (struct client*)malloc(1*sizeof(struct client));
						FILE *aarayici =fopen("kayit.txt","a+");//olmadı a+ olmadı w+ w+ 1 s2me yaramaz amma
					
					for(i = 0;i<temp;i++){
							fread(arayicii,sizeof(struct client),1,aarayici);
							if((arayicii+i)->money==c->money){
								d->debt+=imputamt;
								//printf("%s",d->name);
								fseek(aarayici,-1*sizeof(struct client), SEEK_CUR);
								fwrite(d,sizeof(struct client),1,aarayici);
							
						}else{
							fwrite((arayici+i),sizeof(struct client),1,aarayici);
						}
					
					
					
					
					
	}
			fclose(arayicii);	
			}else if(strcmp(op,"exit")==0){
				return 0;
			}}
		return 0;
}
