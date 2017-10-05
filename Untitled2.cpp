#include <stdio.h>
#include <conio.h>
#include <math.h>
#define nMax 100

int main(){
	//kamus
   int x[nMax+1];
   int y[nMax+1];
   int x2[nMax+1];
   int y2[nMax+1];
   int xy[nMax+1];
   int n,i,elemen;
   int sigma_x=0,sigma_y=0,sigma_x2=0,sigma_y2=0,sigma_xy=0;
   float selisih[nMax+1];
   float m=0,c=0,error,sigma_prediksi=0,sigma_selisih=0;
   float prediksi[nMax+1];
   
   //algoritma
   Home:
   printf("Perhitungan perkiraan lama waktu \n\n");
   printf("Masukan jumlah n : ");scanf("%d", &n);
   //n kurang dari 2
   if(n<2){
   	printf("eror");
      getch();
      goto Home;
      //jika lebih dari 100
   }else if (n>100){
   		printf("Teralu banyak");
      	getch();
    	goto Home;
   }
   	
   else{
   for(i=1;i<=n;i++){
   	printf("Jarak ke tempat pelanggan ke-%d = ",i);scanf("%d", &elemen);
      x[i]=elemen;
      sigma_x=sigma_x+x[i];
   }
	for(i=1;i<=n;i++){
   	x2[i]=x[i]*x[i];
      sigma_x2=sigma_x2+x2[i];
   }
   printf("\n");
   for(i=1;i<=n;i++){
   	printf("Perkiraan waktu yang ditempuh ke-%d = ",i);scanf("%d", &elemen);
      y[i]=elemen;
      sigma_y=sigma_y+y[i];
   }
	for(i=1;i<=n;i++){
   	y2[i]=y[i]*y[i];
      sigma_y2=sigma_y2+y2[i];
      xy[i]=x[i]*y[i];
      sigma_xy=sigma_xy+xy[i];
   }
	m = ((n*sigma_xy)-(sigma_x*sigma_y))/((n*sigma_x2)-pow(sigma_x,2));
	c = ((sigma_y*sigma_x2)-(sigma_x*sigma_xy))/((n*sigma_x2)-pow(sigma_x,2));
   for(i=1;i<=n;i++){
      prediksi[i]=(m*x[i])+c;
   }
	printf("\nJarak ke tempat pelanggan \n");
  	for(i=1;i<=n;i++){
   		printf("|%dKM| ",x[i]);
  }
  printf("\n\nPerkiraan waktu yang ditempuh\n");
  	for(i=1;i<=n;i++){
   		printf("|%djam| ",y[i]);
  }
  printf("\n\nPrediksi Waktu\n");
  for(i=1;i<=n;i++){
  		printf("|%.2f|",prediksi[i]);
  }
  printf("\n\nSelisih waktu perkiraan prediksi\n");
  for(i=1;i<=n;i++){
      selisih[i]=y[i]-prediksi[i];
      if(selisih[i]<0){
      	selisih[i]=prediksi[i]-y[i];
      }
      printf("|%.2f|",selisih[i]);
      sigma_selisih=sigma_selisih+selisih[i];
  }
  printf("\n\nError\n");
  printf("|%.2f|",sigma_selisih/n);
}

getch();
return 0;
}
