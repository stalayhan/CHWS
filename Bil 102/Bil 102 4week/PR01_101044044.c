/*################################################################*/
/* PRO01_101044044.c                                              */
/* ----------------------                                         */
/* Created on 01.04.2012 by Samet Sait Talayhan                   */
/*                                                                */
/* Aciklama                                                       */
/* ----------------------                                         */
/* Projede bir doviz oyunu oynanmaktadir. Oyunda 4 adet para bir- */
/* imi vardir.TL,£,$,€. Kullanici 10000 TL ile baslayip. Parasini */
/* arttirmaya calismaktadir. 3 tane danisman tanimlanmistir,      */
/* bunlarin dogru tahmin etme olasiliklari sirasiyla %75,%50 ve   */ 
/* %40 tir. Her para degisme islemi icin 0.0004 oraninda komisyon */
/* bedeli alinmaktadir.                                           */
/* ----------------------                                         */
/*                                                                */
/*################################################################*/

/*################################################################*/
/*                           Includes                             */
/*################################################################*/
#include <stdio.h>
#include <time.h>

/*################################################################*/
/*                           #defines                             */
/*################################################################*/
#define KOMISYON 0.0004
#define ILK_PARA 10000
#define YUZDE 100

/*--------------------------------------------------------------- */
/*--------------------- Function Prototypes---------------------- */
/*--------------------------------------------------------------- */
double Buyuk (double ,double  ,double );
int Danisman(int, int, int, int, char, double ,double ,double ,double ,double
,double, double);

/*################################################################*/
/* int main()                                                     */
/* ----------                                                     */
/* Return                                                         */
/* ----------                                                     */
/*0 on success                                                    */
/*################################################################*/

int main(void)
{
    int toplamPara = 10000, /* 10.000 TL */
		yatirimRaporuIcin = 10000,
		rastgele, /* 1-3 e kadar rastgele sayi. */
	    inputStatus=0,
		i,        /* Kosul kontrolu */
		day,
		userChoose, /* Kullanicinin */
		danismanParasiA=0,
		danismanParasiB=0,
		danismanParasiC=0,
		gunlukKar=0,
		gunlukKarOrani=0,
		tlKarsiligi=0;
	double euro_kur_sabah,
	       dollar_kur_sabah,                                                 
	       pound_kur_sabah,
		   tl_kur_sabah = 1.00,
		   euro_kur_aksam, 
	       dollar_kur_aksam,
	       pound_kur_aksam,
		   tl_kur_aksam = 1.00,
		   enBuyuk=0,       /* Danismanlar icin. */
		   oran_euro=0,
		   oran_dollar=0,
		   oran_pound=0;
	char ilkSatir, /* txt dosyasi ilk satiri. */  
		 paraTipi = 't', /* Tl='t', Euro='e',Dollar='d',Pound='p' */
		 karsilastirma = 't',   /*Kullanicinin ayni paraTipinde olmasi durumunu
											kontrol etmek icin.*/
		 danismanSecim;
		 
   	FILE *inputFile, *outputFile;

	inputFile = fopen("ExchangeRates.txt", "r");
	outputFile = fopen("InvestmentReport.txt", "w");
	 
	
	fprintf(outputFile,"##############Doviz Oyunu!##############\n");
	
	for(i=0;i<21;i++)
	{
		fscanf(inputFile,"%c",&ilkSatir);
	}

	 printf("##############Doviz Oyunu!##############\n");
	 fscanf(inputFile,"%d%lf%lf%lf",&day ,&euro_kur_sabah, 
		   &dollar_kur_sabah, &pound_kur_sabah );
	 
	while( inputStatus != EOF ) /* Dosya sonunu gormek icin. */
	{
		inputStatus = getc( inputFile );
		fscanf(inputFile,"%d%lf%lf%lf",&day ,&euro_kur_aksam, 
			   &dollar_kur_aksam, &pound_kur_aksam );
		fprintf(outputFile,"Day\tEuro\tDollar\tPound\n");
		fprintf(outputFile,"%d\t%1.4f\t%1.4f\t%1.4f\n",(day-1) ,euro_kur_sabah, 
		   dollar_kur_sabah, pound_kur_sabah);
		
		if(paraTipi == 't') /* TL kontrol */
		{	
			printf("Day	Euro	Dollar	Pound\n");
			printf("%d\t%1.4f\t%1.4f\t%1.4f\n",(day-1),euro_kur_sabah, 
				dollar_kur_sabah, pound_kur_sabah );
			danismanParasiA = (rand() % 13) + 8;
			printf("A danismaninin Ucreti : %dTL\n",danismanParasiA);
			danismanParasiB = (rand() % 11) + 5;
			printf("B danismaninin Ucreti : %dTL\n",danismanParasiB);
			danismanParasiC = (rand() % 35) + 6;
			printf("C danismaninin Ucreti : %dTL\n",danismanParasiC);

			do
			{	
				do
				{	
				printf("Danisman secmek istermisiniz:(E/H): ");
				scanf(" %c",&danismanSecim);
				}while(!(danismanSecim == 'e' || danismanSecim == 'E' ||
					danismanSecim == 'H' || danismanSecim == 'h'));
				do
				{	
					if(danismanSecim == 'e' || danismanSecim == 'E')
					{
					toplamPara =
						Danisman(toplamPara,danismanParasiA,danismanParasiB,
						danismanParasiC,paraTipi,euro_kur_sabah,
						dollar_kur_sabah,
						pound_kur_sabah, euro_kur_aksam,dollar_kur_aksam,
						pound_kur_aksam,tl_kur_sabah);
					}
				}while( !(danismanSecim == 'e' || danismanSecim == 'E' ||
					danismanSecim == 'H' || danismanSecim == 'h') );
			}while( !( danismanSecim == 'H' || danismanSecim == 'h' ) );
			
			do
			{	
			printf("Bir para birimi seciniz: ");
			printf("1.Euro 2.Dollar 3.Pound 4.Paranizi saklayin: ");
			scanf("%d",&userChoose);
			}while( !( userChoose == 1 || userChoose == 2 || userChoose == 3 || 
			                 userChoose == 4 ) );
		}
		
		else if(paraTipi == 'e')
		{	
			printf("Day	Tl    	Dollar	Pound\n");
			printf("%d\t%1.4f\t%1.4f\t%1.4f\n",day,
	   		tl_kur_sabah / euro_kur_sabah, 
			dollar_kur_sabah / euro_kur_sabah,
			pound_kur_sabah / euro_kur_sabah );
			
			tl_kur_sabah = tl_kur_sabah / euro_kur_sabah;
			dollar_kur_sabah = dollar_kur_sabah / euro_kur_sabah;
			pound_kur_sabah = pound_kur_sabah / euro_kur_sabah;
			
			danismanParasiA = (rand() % 13) + 8;
			printf("A danismaninin Ucreti : %dTL\n",danismanParasiA);
			danismanParasiB = (rand() % 11) + 5;
			printf("B danismaninin Ucreti : %dTL\n",danismanParasiB);
			danismanParasiC = (rand() % 35) + 6;
			printf("C danismaninin Ucreti : %dTL\n",danismanParasiC);
			
			do
			{	
				printf("Danisman secmek istermisiniz:(E/H): ");
				scanf(" %c",&danismanSecim);
				do
				{	
					if(danismanSecim == 'e' || danismanSecim == 'E')
					{
					toplamPara =
						Danisman(toplamPara,danismanParasiA,danismanParasiB,
						danismanParasiC,paraTipi,euro_kur_sabah,
						dollar_kur_sabah,
						pound_kur_sabah, euro_kur_aksam,dollar_kur_aksam,
						pound_kur_aksam,tl_kur_sabah);
					}
				}while( !(danismanSecim == 'e' || danismanSecim == 'E' ||
					danismanSecim == 'H' || danismanSecim == 'h') );
			}while( !( danismanSecim == 'H' || danismanSecim == 'h' ) );

			do
			{	
			printf("Bir para birimi seciniz: ");
			printf("1.Paranizi saklayin! 2.Dollar 3.Pound 4.TL: ");
			scanf("%d",&userChoose);
			}while( !( userChoose == 1 || userChoose == 2 || userChoose == 3 || 
			                 userChoose == 4 ) );
		}
				/* Dollar para tipi icin islemler. */
		else if(paraTipi == 'd')
		{	
			printf("Day	Euro	Tl    	Pound\n");
			printf("%d\t%1.4f\t%1.4f\t%1.4f\n",day,
	   		euro_kur_sabah / dollar_kur_sabah, 
			tl_kur_sabah / dollar_kur_sabah,
			pound_kur_sabah / dollar_kur_sabah );
			
			euro_kur_sabah = euro_kur_sabah / dollar_kur_sabah; 
			tl_kur_sabah = tl_kur_sabah / dollar_kur_sabah;
			pound_kur_sabah = pound_kur_sabah / dollar_kur_sabah;
			danismanParasiA = (rand() % 13) + 8;
			printf("A danismaninin Ucreti : %dTL\n",danismanParasiA);
			danismanParasiB = (rand() % 11) + 5;
			printf("B danismaninin Ucreti : %dTL\n",danismanParasiB);
			danismanParasiC = (rand() % 35) + 6;
			printf("C danismaninin Ucreti : %dTL\n",danismanParasiC);

			do
			{	
				printf("Danisman secmek istermisiniz:(E/H): ");
				scanf(" %c",&danismanSecim);
				do
				{	
					if(danismanSecim == 'e' || danismanSecim == 'E')
					{
					toplamPara =
						Danisman(toplamPara,danismanParasiA,danismanParasiB,
						danismanParasiC,paraTipi,euro_kur_sabah,
						dollar_kur_sabah,
						pound_kur_sabah, euro_kur_aksam,dollar_kur_aksam,
						pound_kur_aksam,tl_kur_sabah);
					}
				}while( !(danismanSecim == 'e' || danismanSecim == 'E' ||
					danismanSecim == 'H' || danismanSecim == 'h') );
			}while( !( danismanSecim == 'H' || danismanSecim == 'h' ) );
			
			do
			{	
			printf("Bir para birimi seciniz: ");
			printf("1.Euro 2.Paranizi saklayin! 3.Pound 4.TL: ");
			scanf("%d",&userChoose);
			}while( !( userChoose == 1 || userChoose == 2 || userChoose == 3 || 
			                 userChoose == 4 ) );
		}
				/* Pound para tipi icin islemler. */
		else if(paraTipi == 'p')
		{	
			printf("Day	Euro	Dollar	Tl\n");
			printf("%d\t%1.4f\t%1.4f\t%1.4f\n",day,
			euro_kur_sabah / pound_kur_sabah, 
			dollar_kur_sabah / pound_kur_sabah,
			tl_kur_sabah / pound_kur_sabah );
			
			euro_kur_sabah = euro_kur_sabah / pound_kur_sabah; 
			dollar_kur_sabah = dollar_kur_sabah / pound_kur_sabah;
			tl_kur_sabah = tl_kur_sabah / pound_kur_sabah;
			danismanParasiA = (rand() % 13) + 8;
			printf("A danismaninin Ucreti : %d\n",danismanParasiA);
			danismanParasiB = (rand() % 11) + 5;
			printf("B danismaninin Ucreti : %d\n",danismanParasiB);
			danismanParasiC = (rand() % 35) + 6;
			printf("C danismaninin Ucreti : %d\n",danismanParasiC);
			
			do
			{	
				printf("Danisman secmek istermisiniz:(E/H): ");
				scanf(" %c",&danismanSecim);
				do
				{	
					if(danismanSecim == 'e' || danismanSecim == 'E')
					{
					toplamPara =
						Danisman(toplamPara,danismanParasiA,danismanParasiB,
						danismanParasiC,paraTipi,euro_kur_sabah,
						dollar_kur_sabah,
						pound_kur_sabah, euro_kur_aksam,dollar_kur_aksam,
						pound_kur_aksam,tl_kur_sabah);
					}
				}while( !(danismanSecim == 'e' || danismanSecim == 'E' ||
					danismanSecim == 'H' || danismanSecim == 'h') );
			}while( !( danismanSecim == 'H' || danismanSecim == 'h' ) );
			
			do
			{	
			printf("Bir para birimi seciniz: ");
			printf("1.Euro 2.Dollar 3.Paranizi saklayin! 4.TL: ");
			scanf("%d",&userChoose);
			}while( !( userChoose == 1 || userChoose == 2 || userChoose == 3 || 
			                 userChoose == 4 ) );
		}
		/* Kullanici nin yeni para tipi secimi! */
		switch(userChoose)
		{
			case 1:
			paraTipi = 'e';
			break;
			case 2:
			paraTipi = 'd';
			break;
			case 3:
			paraTipi = 'p';
			break;
			case 4:
			paraTipi= 't';
			break;
		}
	
		if( karsilastirma == paraTipi ) /* Ayni para tipinde kalma durumu. */
		{
			if(paraTipi == 'e' )
			{
				printf("Paraniz simdi bu kadar %d€\n",toplamPara);
				tlKarsiligi = toplamPara * euro_kur_aksam;
				fprintf(outputFile,"Paraniz simdi bu kadar %d€\n",toplamPara);
				fprintf(outputFile,"Paranizin TL karsiligi: %d\n",tlKarsiligi);
				
			}
			else if(paraTipi == 'd' )
			{
				printf("Paraniz simdi bu kadar %d$\n",toplamPara);	
				tlKarsiligi = toplamPara * dollar_kur_aksam;
				fprintf(outputFile,"Paraniz simdi bu kadar %d€\n",toplamPara);
				fprintf(outputFile,"Paranizin TL karsiligi: %d\n",tlKarsiligi);
			}
			else if(paraTipi == 'p' )
			{
				printf("Paraniz simdi bu kadar %d£\n",toplamPara);	
				tlKarsiligi = toplamPara * pound_kur_aksam;
				fprintf(outputFile,"Paraniz simdi bu kadar %d€\n",toplamPara);
				fprintf(outputFile,"Paranizin TL karsiligi: %d\n",tlKarsiligi);
			}
			else if(paraTipi == 't' )
			{
				printf("Paraniz simdi bu kadar %dTL\n",toplamPara);	
				tlKarsiligi = toplamPara * tl_kur_sabah;
				fprintf(outputFile,"Paraniz simdi bu kadar %d€\n",toplamPara);
				fprintf(outputFile,"Paranizin TL karsiligi: %d\n",tlKarsiligi);
			}
		}
		
		else
		{
			if(paraTipi == 'e' )
			{	
				toplamPara = ( toplamPara / euro_kur_sabah );
				toplamPara -= ( toplamPara * KOMISYON );
				printf("Paraniz simdi bu kadar %d€\n",toplamPara);
				tlKarsiligi = toplamPara * euro_kur_aksam;
				fprintf(outputFile,"Paraniz simdi bu kadar %d€\n",toplamPara);
				fprintf(outputFile,"Paranizin TL karsiligi: %d\n",tlKarsiligi);
			}
			else if(paraTipi == 'd' )
			{
				toplamPara = ( toplamPara / dollar_kur_sabah );
				toplamPara -= ( toplamPara * KOMISYON );
															
				printf("Paraniz simdi bu kadar %d$\n",toplamPara);
				tlKarsiligi = toplamPara * dollar_kur_aksam;
				fprintf(outputFile,"Paraniz simdi bu kadar %d$\n",toplamPara);
				fprintf(outputFile,"Paranizin TL karsiligi: %d\n",tlKarsiligi);
			}
			else if(paraTipi == 'p' )
			{	
				toplamPara = ( toplamPara / pound_kur_sabah );
				toplamPara -= ( toplamPara * KOMISYON );
				printf("Paraniz simdi bu kadar %d£\n",toplamPara);
				tlKarsiligi = toplamPara * pound_kur_aksam;
				fprintf(outputFile,"Paraniz simdi bu kadar %d£\n",toplamPara);
				fprintf(outputFile,"Paranizin TL karsiligi: %d\n",tlKarsiligi);
			}
			else if(paraTipi == 't' )
			{	
				toplamPara = ( toplamPara / tl_kur_sabah );
				toplamPara -= ( toplamPara * KOMISYON );
				printf("Paraniz simdi bu kadar %dTL\n",toplamPara);
				tlKarsiligi = toplamPara;
				fprintf(outputFile,"Paraniz simdi bu kadar %dTL\n",toplamPara);
				fprintf(outputFile,"Paranizin TL karsiligi: %d\n",tlKarsiligi);
			}
		}
		
		switch(paraTipi) /* Rapor hesaplamalari */
		{
			case 't':
			gunlukKar =tlKarsiligi - yatirimRaporuIcin;
			printf("Gunluk kar :%dTL\n",gunlukKar);
				if(gunlukKar < 0)
				{
					printf("Gunluk kar orani :Negatif\n");
					fprintf(outputFile,"Gunluk kar orani :Negatif\n");
				}
				else if(gunlukKar = 0)
				{
					printf("Gunluk kar orani :Sifir\n");
					fprintf(outputFile,"Gunluk kar orani :Sifir\n");
				}
				else
				{
					printf("Gunluk kar orani :Pozitif\n");	
					fprintf(outputFile,"Gunluk kar orani :Pozitif\n");
				}	
			break;
			case 'e':
			gunlukKar =tlKarsiligi - yatirimRaporuIcin;
			printf("Gunluk kar :%dTL\n",gunlukKar);
				if(gunlukKar < 0)
				{
					printf("Gunluk kar orani :Negatif\n");
					fprintf(outputFile,"Gunluk kar orani :Negatif\n");
				}
				else if(gunlukKar = 0)
				{
					printf("Gunluk kar orani :Sifir\n");
					fprintf(outputFile,"Gunluk kar orani :Sifir\n");
				}
				else
				{
					printf("Gunluk kar orani :Pozitif\n");	
					fprintf(outputFile,"Gunluk kar orani :Pozitif\n");
				}	
			break;
			case 'd':
			gunlukKar = tlKarsiligi - yatirimRaporuIcin;
			printf("Gunluk kar :%dTL\n",gunlukKar);
				if(gunlukKar < 0)
				{
					printf("Gunluk kar orani :Negatif\n");
					fprintf(outputFile,"Gunluk kar orani :Negatif\n");
				}
				else if(gunlukKar = 0)
				{
					printf("Gunluk kar orani :Sifir\n");
					fprintf(outputFile,"Gunluk kar orani :Sifir\n");
				}
				else
				{
					printf("Gunluk kar orani :Pozitif\n");	
					fprintf(outputFile,"Gunluk kar orani :Pozitif\n");
				}	
			break;
			case 'p':
			gunlukKar =tlKarsiligi - yatirimRaporuIcin;
			printf("Gunluk kar :%dTL\n",gunlukKar);
				if(gunlukKar < 0)
				{
					printf("Gunluk kar orani :Negatif\n");
					fprintf(outputFile,"Gunluk kar orani :Negatif\n");
				}
				else if(gunlukKar = 0)
				{
					printf("Gunluk kar orani :Sifir\n");
					fprintf(outputFile,"Gunluk kar orani :Sifir\n");
				}
				else
				{
					printf("Gunluk kar orani :Pozitif\n");	
					fprintf(outputFile,"Gunluk kar orani :Pozitif\n");
				}	
				break;
		}
		
		printf("########################################\n");
		fprintf(outputFile,"########################################\n");
		yatirimRaporuIcin = tlKarsiligi;

		euro_kur_sabah = euro_kur_aksam; /* aksam kuru bir sonraki gunun sabah
												kuru demektir. */
		dollar_kur_sabah = dollar_kur_aksam;
		pound_kur_sabah = pound_kur_aksam;
		
		tl_kur_sabah = 1.00;
		karsilastirma = paraTipi;
    }
	   
  	
	fprintf(outputFile,"Genel Kar Raporu\n");
	fprintf(outputFile,"Toplam Kar: %dTL\n", ( tlKarsiligi - ILK_PARA ) );
  	
	fclose(inputFile);
	fclose(outputFile);


   return 0;
}

/*--------------------------------------------------------------- */
/*------------------- Function Implementations ------------------ */
/*--------------------------------------------------------------- */

/* Fonksiyon Buyuk */
/*-------------------                                             */
/* 	Verilen 3 sayi arasindan en buyugunu bulup geri dondurur.     */
/* Danismanlarin en yuksek kazancli tahminde bulunmasi icin       */
/* kullanilmistir.                                                */
/* ------------------                                             */

double Buyuk (double a ,double b ,double c)
{
	double max;

	if(a >= b )
	{
		max = a;
		if(a >= c)
		max = a;
		else
		max = c;
	}
	if( b >= c )
		max = b;	
	else
		max = c;


	return max;
}
/* Fonksiyon Danisman                                             */
/*-------------------                                             */
/* Gerekli inputlari aldiktan sonra, danisman ucretini            */
/* dusup toplamPara yi geri dondurmektedir. 3 Danismanda          */
/* bu fonksiyonda tanimlanmistir.                                 */
/* ------------------                                             */


int Danisman(int toplamPara, int danismanParasiA, int danismanParasiB,
			int danismanParasiC, char paraTipi, double euro_kur_sabah,double
dollar_kur_sabah,double pound_kur_sabah,double euro_kur_aksam,double
dollar_kur_aksam,double pound_kur_aksam,double tl_kur_sabah)

{/* Ana parantez! */

		int rastgele, /* 0-3 e kadar rastgele sayi. */
			x,
			danismanParasi = 0;
		double enBuyuk=0,
		   	oran_euro=0,
		   	oran_dollar=0,
		   	oran_pound=0;
		int userChoose=0;


	srand(time(NULL));
	x = rand() % 100; /* 0-100 arasi rastgele sayi uretmek. */


	while( !( userChoose == 1 || userChoose == 2 || userChoose == 3 ) )
	{
		printf("Bir danisman girin\n");
		printf("A danismani icin 1'e,B danismani icin 2'e,C danismaniicin3'e:");
		scanf("%d",&userChoose);
	}
	
	
	if( userChoose == 1 )
	{
		if( x >=75 ) /* Yanlisi tutturma olasiligi. */
		{
			rastgele = (rand() % 3) + 1;
			if((euro_kur_aksam / euro_kur_sabah) < 1 )
			{	
				printf("Euro yukselicek yatirim yapin!\n");
			}	
			else if((dollar_kur_aksam / dollar_kur_sabah) < 1)
			{	
				printf("Dollar yukselicek yatirim yapin!\n");
			}	
			else if((pound_kur_aksam / pound_kur_sabah) < 1)
			{	
				printf("Pound yukselicek yatirim yapin!\n");
			}
					/* 3ude yanlis */
			else if( oran_euro == 0 && oran_dollar == 0 && oran_pound == 0) 
			{
				switch(rastgele)
				{
					case 1:
					printf("Dollar yukselicek yatirim yapin!\n");
					break;
					case 2:
					printf("Euro yukselicek yatirim yapin!\n");
					break;
					case 3:
					printf("Pound yukselicek yatirim yapin!\n");
					break;
				}
			}
		}

		else
		{
			if((euro_kur_aksam / euro_kur_sabah) > 1 )
			{	
				oran_euro = (euro_kur_aksam / euro_kur_sabah); 
			}
			if((dollar_kur_aksam / dollar_kur_sabah) > 1)
			{
				oran_dollar = (dollar_kur_aksam / dollar_kur_sabah);
			}
			if((pound_kur_aksam / pound_kur_sabah) > 1)
			{
				oran_pound = (pound_kur_aksam / pound_kur_sabah);
			}
			if(oran_euro == 0 && oran_dollar == 0 && oran_pound == 0)
			{
				printf("Paranizda kalin!\n");
				return(toplamPara - danismanParasiA);
			}
		
			enBuyuk = Buyuk(oran_euro,oran_dollar,oran_pound); /* En karli
													yatirimi bulmak icin. */

			if(enBuyuk == oran_euro)
			printf("Euro ya yatirim yapin!\n");

			else if(enBuyuk == oran_dollar)
			printf("Dollar a yatirim yapin!\n");

			else if(enBuyuk == oran_pound)
			printf("Pound a yatirim yapin!\n");
		}
		switch(paraTipi)
		{
			case 'e':
				toplamPara = toplamPara - (danismanParasiA/euro_kur_sabah);
			break;	
			case 'd':
				toplamPara = toplamPara - (danismanParasiA/dollar_kur_sabah);
			break;	
			case 'p':
				toplamPara = toplamPara - (danismanParasiA/pound_kur_sabah);
			break;	
			case 't':
			toplamPara -= danismanParasiA; 
			break;	
		}
		
		return(toplamPara);
	}
	
	/*B danismani*/
	
	else if( userChoose == 2 )
	{
		if( x >=50 ) /* Yanlisi tutturma olasiligi. */
		{
			rastgele = (rand() % 3) + 1;
			if((euro_kur_aksam / euro_kur_sabah) < 1 )
			{	
				printf("Euro yukselicek yatirim yapin!\n");
			}	
			else if((dollar_kur_aksam / dollar_kur_sabah) < 1)
			{	
				printf("Dollar yukselicek yatirim yapin!\n");
			}	
			else if((pound_kur_aksam / pound_kur_sabah) < 1)
			{	
				printf("Pound yukselicek yatirim yapin!\n");
			}
					/* 3ude yanlis */
			else if( oran_euro == 0 && oran_dollar == 0 && oran_pound == 0) 
			{
				switch(rastgele)
				{
					case 1:
					printf("Dollar yukselicek yatirim yapin!\n");
					break;
					case 2:
					printf("Euro yukselicek yatirim yapin!\n");
					break;
					case 3:
					printf("Pound yukselicek yatirim yapin!\n");
					break;
				}
			}
		}

		else
		{
			if((euro_kur_aksam / euro_kur_sabah) > 1 )
			{	
				oran_euro = (euro_kur_aksam / euro_kur_sabah); 
			}
			if((dollar_kur_aksam / dollar_kur_sabah) > 1)
			{
				oran_dollar = (dollar_kur_aksam / dollar_kur_sabah);
			}
			if((pound_kur_aksam / pound_kur_sabah) > 1)
			{
				oran_pound = (pound_kur_aksam / pound_kur_sabah);
			}
			if(oran_euro == 0 && oran_dollar == 0 && oran_pound == 0)
			{
				printf("Paranizda kalin!\n");
				return(toplamPara - danismanParasiB);
			}
		
			enBuyuk = Buyuk(oran_euro,oran_dollar,oran_pound); /* En karli
													yatirimi bulmak icin. */

			if(enBuyuk == oran_euro)
			printf("Euro ya yatirim yapin!\n");

			else if(enBuyuk == oran_dollar)
			printf("Dollar a yatirim yapin!\n");

			else if(enBuyuk == oran_pound)
			printf("Pound a yatirim yapin!\n");
		}
		switch(paraTipi)
		{
			case 'e':
				toplamPara = toplamPara - (danismanParasiB/euro_kur_sabah);
			break;	
			case 'd':
				toplamPara = toplamPara - (danismanParasiB/dollar_kur_sabah);
			break;	
			case 'p':
				toplamPara = toplamPara - (danismanParasiB/pound_kur_sabah);
			break;	
			case 't':
			toplamPara -= danismanParasiB; 
			break;	
		}
		
		return(toplamPara);
	}
	
		/*C danismani*/	
	
	else if( userChoose == 3 )
	{
		if( x >=40 ) /* Yanlisi tutturma olasiligi. */
		{
			rastgele = (rand() % 3) + 1;
			if((euro_kur_aksam / euro_kur_sabah) < 1 )
			{	
				printf("Euro yukselicek yatirim yapin!\n");
			}	
			else if((dollar_kur_aksam / dollar_kur_sabah) < 1)
			{	
				printf("Dollar yukselicek yatirim yapin!\n");
			}	
			else if((pound_kur_aksam / pound_kur_sabah) < 1)
			{	
				printf("Pound yukselicek yatirim yapin!\n");
			}
					/* 3ude yanlis */
			else if( oran_euro == 0 && oran_dollar == 0 && oran_pound == 0) 
			{
				switch(rastgele)
				{
					case 1:
					printf("Dollar yukselicek yatirim yapin!\n");
					break;
					case 2:
					printf("Euro yukselicek yatirim yapin!\n");
					break;
					case 3:
					printf("Pound yukselicek yatirim yapin!\n");
					break;
				}
			}
		}

		else
		{
			if((euro_kur_aksam / euro_kur_sabah) > 1 )
			{	
				oran_euro = (euro_kur_aksam / euro_kur_sabah); 
			}
			if((dollar_kur_aksam / dollar_kur_sabah) > 1)
			{
				oran_dollar = (dollar_kur_aksam / dollar_kur_sabah);
			}
			if((pound_kur_aksam / pound_kur_sabah) > 1)
			{
				oran_pound = (pound_kur_aksam / pound_kur_sabah);
			}
			if(oran_euro == 0 && oran_dollar == 0 && oran_pound == 0)
			{
				printf("Paranizda kalin!\n");
				return(toplamPara - danismanParasiB);
			}
		
			enBuyuk = Buyuk(oran_euro,oran_dollar,oran_pound); /* En karli
													yatirimi bulmak icin. */

			if(enBuyuk == oran_euro)
			printf("Euro ya yatirim yapin!\n");

			else if(enBuyuk == oran_dollar)
			printf("Dollar a yatirim yapin!\n");

			else if(enBuyuk == oran_pound)
			printf("Pound a yatirim yapin!\n");
		}
		
		switch(paraTipi)
		{
			case 'e':
				toplamPara = toplamPara - (danismanParasiC/euro_kur_sabah);
			break;	
			case 'd':
				toplamPara = toplamPara - (danismanParasiC/dollar_kur_sabah);
			break;	
			case 'p':
				toplamPara = toplamPara - (danismanParasiC/pound_kur_sabah);
			break;	
			case 't':
			toplamPara -= danismanParasiC; 
			break;	
		}
		return(toplamPara);
	}
}/* Ana parantez! */

/*################################################################*/
/*                  End of HW01_101044044_part2.c                 */
/*################################################################*/


