#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>

int bigO[20];
int icicebigO[5];
int recursivebigO[5];
int say=0,recursivesayisi=0,kacrecursive=0,aynisatir=0,enbuyukrecursive=0;
char *intvarmi="int ",*voidvarmi="void ", *floatvarmi = "float ", *ifbul="if", *matriskontrol = "][";
int say2=0, ilineer=0, ilogaritmik=0, lin=0, log=0,fonksiyon=0,tekbolu=0;
int ilineer2=0, ilogaritmik2=0, lin2=0, log2=0, bolusayisi=0, ificinderecursive=0;
char *nvarmi="n", *Nvarmi="N", *bosluk=" ", *acikparantez="(", *koseliparantez = "[", *doublevarmi = "double ";
char *susluparantez="{", *susluparantez2="}", *noktalivirgul=";", *virgul = ",", *longvarmi = "long ";//longdan sonra bosluk ekledimm
int forparantez=0, wparantez=0, doparantez=0, parantez=0;
char *forvarmi="for", *wvarmi="while", *dovarmi="do", *iartiarti="i++;", *ieksieksi= "i--;", *charvarmi = "char ";
char *arti="++", *eksi="--", *carpi="*", *bolu="/", *tekeksi="-", *tekarti="+", *mainvarmi = "main";
char *ibolu="i/", *icarpi="i*", *eksi2="-2", *eksi_2="- 2", *eksi1="-1", *eksi_1="- 1";
char dizi3[6][20];
int sayac=0,sayac2=0,sayac3=0,sayac4=0,sayac5=0,sayac6=0,sayac7=0,sayac8=0,sayac9=0;
int adetbul(char dizi[], char *aranan){

  int uzunluk1=strlen(dizi);
  int uzunluk2=strlen(aranan);
  int i,j,temp=0,kacdefa=0;
  for(i=0;i<uzunluk1;i++){
    for(j=0;j<uzunluk2;j++){
        if(dizi[i+j]==aranan[j]){
            temp++;
        }
    }

   if(uzunluk2==temp){
    kacdefa++;
   }
   temp=0;
  }
  return kacdefa;
}
int recursive(char dizi[]){
    kacrecursive++;
    if(recursivesayisi==0){
    recursivesayisi++;
    }
     if(ificinderecursive==0){
            printf("recursive fonksiyon var.\n");

     }else{
     ificinderecursive--;
     }


    if(adetbul(dizi, dizi3[fonksiyon -1])>1){
            aynisatir++;
       printf("ayni satirda iki kez cagiriliyor.\n");
       if(strstr(dizi, eksi2) || strstr(dizi, eksi_2)){
        printf("big o O(2^n)'dir.\n");
        bigO[say2]=10;
        say2++;
        recursivebigO[recursivesayisi-1]=10;
       }else{
        printf("big o O(2^n)'dir.\n");
        bigO[say2]=10;
        say2++;
        recursivebigO[recursivesayisi-1]=10;
       }
    }else{
     if(strstr(dizi, bolu)){
        tekbolu++;
     }
    }
    return 0;
 }
void recursivekontrol(char dizi[]){

      if(aynisatir==0 && kacrecursive==1){
      if(tekbolu>0){
        printf("logaritmik. big o O(logn)'dir\n");
        bigO[say2]=3;
        say2++;
        recursivebigO[recursivesayisi-1]=3;
      }else{
      printf("lineer. big o O(n)'dir.\n");
        bigO[say2]=5;
        say2++;
        recursivebigO[recursivesayisi-1]=5;
      }
    }else if(aynisatir==0 && kacrecursive==2){
       if(bolusayisi==0){
         printf("big o O(2^n)'dir.\n");
        bigO[say2]=10;
        say2++;
        recursivebigO[recursivesayisi-1]=10;
       }else if(ificinderecursive>0){
        printf("logaritmik. big o O(logn)'dir\n");
        bigO[say2]=6;
        say2++;
        recursivebigO[recursivesayisi-1]=6;
       }else{
        printf("logaritmik. big o O(nlogn)'dir\n");
        bigO[say2]=3;
        say2++;
        recursivebigO[recursivesayisi-1]=3;
       }
    }
}
void oku(char dizi[],FILE *fp2){

  fgets(dizi,150,fp2);
        if(strstr(dizi, susluparantez)){
                parantez++;
            }else if(strstr(dizi, susluparantez2)){

              parantez--;
            }
        if(strstr(dizi, dizi3[fonksiyon-1])){
            recursive(dizi);

            }
        if(strstr(dizi, bolu)){
            bolusayisi++;
        }

        printf("%s",dizi);

}
 void ifcheck(char dizi[],FILE *fp2){
     if(strstr(dizi, ifbul)){

        fgets(dizi,150,fp2);
        if(strstr(dizi, susluparantez)){
                parantez++;
        }else if(strstr(dizi, susluparantez2)){
              parantez--;
        }
        if(strstr(dizi, dizi3[fonksiyon-1])){
            ificinderecursive++;
            recursive(dizi);
            }
        if(strstr(dizi, bolu)){
            bolusayisi++;
        }
        printf("%s",dizi);

     }
 }
int dokontrol(char dizi[],FILE *fp2){
    if(strstr(dizi, susluparantez))
    {
        doparantez++;
        if(whilearama(dizi, iartiarti) || whilearama(dizi, ieksieksi)){
                        ilineer++;
        }else if(whilearama(dizi, ibolu) || whilearama(dizi, icarpi)){
                        ilogaritmik++;
        }else if(whilearama(dizi, arti) || whilearama(dizi, eksi) || whilearama(dizi, tekarti) || whilearama(dizi, tekeksi)){
                        lin++;
        }else if(whilearama(dizi, bolu) || whilearama(dizi, carpi)){
                        log++;
        }
       oku(dizi,fp2);
       ifcheck(dizi, fp2);
        dokontrol(dizi,fp2);

    }
    else if(strstr(dizi, susluparantez2))
    {
        if(doparantez==1)
        {
            doparantez--;
            printf("donguden cikildi.\n");
            if(ilineer>0){
                bigO[say2]=5;
                printf("dongunun bigosu O(n)\n");
                say2++;
            }else if(ilogaritmik>0){
                bigO[say2]=3;
                printf("dongunun bigosu O(logn)\n");
                say2++;
            }else if(lin>0){
                bigO[say2]=5;
                printf("dongunun bigosu O(n)\n");
                say2++;
            }else if(log>0){
                bigO[say2]=3;
                printf("dongunun bigosu O(logn)\n");
                say2++;
            }
        }
    }
    else
    {
        if(whilearama(dizi, iartiarti) || whilearama(dizi, ieksieksi)){
                        ilineer++;
        }else if(whilearama(dizi, ibolu) || whilearama(dizi, icarpi)){
                        ilogaritmik++;
        }else if(whilearama(dizi, arti) || whilearama(dizi, eksi) || whilearama(dizi, tekarti) || whilearama(dizi, tekeksi)){
                        lin++;
        }else if(whilearama(dizi, bolu) || whilearama(dizi, carpi)){
                        log++;
        }
       oku(dizi,fp2);
       ifcheck(dizi, fp2);
        dokontrol(dizi,fp2);
    }
  return 0;
}
int enbuyukObul(int bul[]){
         int enbuyuk=bul[0];
         for(int a=1;a<say2;a++){
            if(bul[a]>enbuyuk){
                enbuyuk=bul[a];
            }
         }
   return enbuyuk;
}
int whilearama(char dizi[],char *aranan){

            if(strstr(dizi, aranan)){
                return 1;
            }
return 0;
}
int artiskontrolw(char dizi[]){
    if(!(strstr(dizi, nvarmi) || strstr(dizi, Nvarmi))){
            printf("donus sayisi belli O(1).\n");
    }
 return 0;
}
int whilekontrol(char dizi[],FILE *fp2){
    int toplam=0;
    if(strstr(dizi, susluparantez))
    {
        if(wparantez>=1)
        {
            printf("icice dongu var %d. dongu.\n",wparantez+1);

        }
        wparantez++;
        if(whilearama(dizi, iartiarti) || whilearama(dizi, ieksieksi)){
                if(wparantez==2){
                        ilineer2++;
                }else{
                        ilineer++;
                }


        }else if(whilearama(dizi, ibolu) || whilearama(dizi, icarpi)){
           if(wparantez==2){
                        ilogaritmik2++;
                }else{
                        ilogaritmik++;
                }
        }else if(whilearama(dizi, arti) || whilearama(dizi, eksi) || whilearama(dizi, tekarti) || whilearama(dizi, tekeksi)){
           if(wparantez==2){
                        lin2++;
                }else{
                        lin++;
                }

        }else if(whilearama(dizi, bolu) || whilearama(dizi, carpi)){
           if(wparantez==2){
                        log2++;
                }else{
                        log++;
                }
        }
        oku(dizi,fp2);
        ifcheck(dizi, fp2);
         if(strstr(dizi, wvarmi) && !(strstr(dizi, noktalivirgul)))
        {
            artiskontrolw(dizi);
        }
        whilekontrol(dizi,fp2);

    }
    else if(strstr(dizi, susluparantez2))
    {
        if(wparantez==1)
        {
            if(ilineer>0){
                icicebigO[say]=5;
                say++;
            }else if(ilogaritmik>0){
                icicebigO[say]=3;
                say++;
            }else if(lin>0){
                icicebigO[say]=5;
                say++;
            }else if(log>0){
                icicebigO[say]=3;
                say++;
            }
            wparantez--;
            printf("dongulerden cikildi.\n");
            ilineer=0;
            ilogaritmik=0;
            lin=0;
            log=0;
                if(say==2){
                        for(int a=0; a<say; a++)
                              {
                                    toplam=toplam+icicebigO[a];
                              }

                    switch(toplam)
                    {
                    case 6:
                        printf("dongulerin bigOsu (logn)^2'dir.\n");
                        bigO[say2]=4;
                        say2++;
                        break;
                    case 8:
                        printf("dongulerin bigOsu nlogn'dir.\n");
                        bigO[say2]=6;
                        say2++;
                        break;
                    case 10:
                        printf("dongulerin bigOsu n^2'dir.\n");
                        bigO[say2]=7;
                        say2++;
                        break;
                    default:
                        printf("bitti\n");


                    }

                }else if(say==1){
                    if(icicebigO[say-1]==3){
                           printf("1. dongu logaritmik buyuyor O(logn).\n");
                        }else if(icicebigO[say-1]==5){
                           printf("1. dongu lineer buyuyor O(n).\n");
                        }
                        icicebigO[say]=bigO[say2];
                        say2++;
                }
                for(int b=0;b<say;b++){
                        icicebigO[b]=0;
                    }
                    say=0;
        }
        else
        {


            printf("%d. donguden cikildi\n",wparantez);
            wparantez--;

            if(ilineer2>0){
                icicebigO[say]=5;
                say++;
            }else if(ilogaritmik2>0){
                icicebigO[say]=3;
                say++;
            }else if(lin2>0){
                icicebigO[say]=5;
                say++;
            }else if(log2>0){
                icicebigO[say]=3;
                say++;
            }
            ilineer2=0;
            ilogaritmik2=0;
            lin2=0;
            log2=0;
            if(whilearama(dizi, iartiarti) || whilearama(dizi, ieksieksi)){
                if(wparantez==2){

                        ilineer2++;
                }else{
                        ilineer++;
                }


            }else if(whilearama(dizi, ibolu) || whilearama(dizi, icarpi)){
                 if(wparantez==2){

                        ilogaritmik2++;
                }else{
                        ilogaritmik++;
                }
        }else if(whilearama(dizi, arti) || whilearama(dizi, eksi) || whilearama(dizi, tekarti) || whilearama(dizi, tekeksi)){
           if(wparantez==2){

                        lin2++;
                }else{
                        lin++;
                }

        }else if(whilearama(dizi, bolu) || whilearama(dizi, carpi)){
           if(wparantez==2){

                        log2++;
                }else{
                        log++;
                }
        }


            oku(dizi,fp2);
            ifcheck(dizi, fp2);
             if(strstr(dizi, wvarmi) && !(strstr(dizi, noktalivirgul)))
            {
                artiskontrolw(dizi);
            }
             whilekontrol(dizi,fp2);

        }
    }else{

        if(whilearama(dizi, iartiarti) || whilearama(dizi, ieksieksi)){//////
                if(wparantez==2){

                        ilineer2++;
                }else{
                        ilineer++;
                }


        }else if(whilearama(dizi, ibolu) || whilearama(dizi, icarpi)){
           if(wparantez==2){

                        ilogaritmik2++;
                }else{
                        ilogaritmik++;
                }
        }else if(whilearama(dizi, arti) || whilearama(dizi, eksi) || whilearama(dizi, tekarti) || whilearama(dizi, tekeksi)){
           if(wparantez==2){

                        lin2++;
                }else{
                        lin++;
                }

        }else if(whilearama(dizi, bolu) || whilearama(dizi, carpi)){
           if(wparantez==2){

                        log2++;
                }else{
                        log++;
                }
        }
        oku(dizi,fp2);
        ifcheck(dizi, fp2);
         if(strstr(dizi, wvarmi) && !(strstr(dizi, noktalivirgul)))
        {
            artiskontrolw(dizi);
        }
        whilekontrol(dizi,fp2);
         }

 return 0;
}
int artiskontrol(char dizi[]){
    if(forparantez>1){
    if(strstr(dizi, nvarmi) || strstr(dizi, Nvarmi)){
    if(strstr(dizi, arti) || strstr(dizi, eksi) || strstr(dizi, tekeksi) || strstr(dizi, tekarti)){
        icicebigO[say]=5;
        say++;
        printf("lineer buyuyor o(n)\n");
    }else if(strstr(dizi, bolu) || strstr(dizi, carpi)){
        icicebigO[say]=3;
        say++;
        printf("logaritmik buyuyor o(logn).\n");
    }
    }else{
        printf("donus sayisi belli O(1)\n");
    }
    }else{
     if(strstr(dizi, arti) || strstr(dizi, eksi) || strstr(dizi, tekeksi) || strstr(dizi, tekarti)){
        icicebigO[say]=5;
        say++;
        printf("lineer buyuyor o(n)\n");
    }else if(strstr(dizi, bolu) || strstr(dizi, carpi)){
        icicebigO[say]=3;
        say++;
        printf("logaritmik buyuyor o(logn).\n");
    }
    }
    return 0;
}
int forkontrol(char dizi[],FILE *fp2)
{
    int toplam=0;
    if(strstr(dizi, susluparantez))
    {
        if(forparantez>=1)
        {
            printf("icice dongu var %d. dongu.\n",forparantez+1);

        }
        forparantez++;
        oku(dizi,fp2);
        ifcheck(dizi, fp2);
        if(strstr(dizi, forvarmi))
        {
            artiskontrol(dizi);
        }
        forkontrol(dizi,fp2);

    }
    else if(strstr(dizi, susluparantez2))
    {
        if(forparantez==1)
        {
            forparantez--;
            printf("dongulerden cikildi.\n");
            if(say!=0)
            {
                for(int a=0; a<say; a++)
                {
                    toplam=toplam+icicebigO[a];
                }
                if(say==2)
                {
                    switch(toplam) {
                    case 6:
                        printf("dongulerin bigOsu (logn)^2'dir.\n");
                        bigO[say2]=4;
                        say2++;
                        break;
                    case 8:
                        printf("dongulerin bigOsu nlogn'dir.\n");
                        bigO[say2]=6;
                        say2++;
                        break;
                    case 10:
                        printf("dongulerin bigOsu n^2'dir.\n");
                        bigO[say2]=7;
                        say2++;
                        break;
                    default:
                        printf("bitti\n");


                    }
                }else if(say==3){

                    switch(toplam) {
                    case 9:
                        printf("dongulerin bigOsu (logn)^3'dur.\n");
                        bigO[say2]=4;
                        say2++;
                        break;
                    case 11:
                        printf("dongulerin bigOsu n(logn)^2'dir.\n");
                        bigO[say2]=6;
                        say2++;
                        break;
                    case 13:
                        printf("dongulerin bigOsu n^2logn'dir.\n");
                        bigO[say2]=8;
                        say2++;
                        break;
                    case 15:
                        printf("dongulerin bigOsu n^3'dur.\n");
                        bigO[say2]=9;
                        say2++;
                        break;
                    default:
                        printf("bitti\n");


                    }
                }
                 for(int b=0;b<say;b++){
                        icicebigO[b]=0;
                    }
                    say=0;
            }
        }
        else
        {
            printf("%d. donguden cikildi\n",forparantez);
            forparantez--;
            oku(dizi,fp2);
            ifcheck(dizi,fp2);
            if(strstr(dizi, forvarmi))
            {
                artiskontrol(dizi);
            }
            forkontrol(dizi,fp2);
        }

    }
    else
    {

        oku(dizi,fp2);
        ifcheck(dizi,fp2);
        forkontrol(dizi,fp2);
    }



    return 0;
}
int dosyakontrol(FILE *yp,int dizi2[])
{
    char ch;
    int satir=0;
    yp=fopen("ornekkod4.txt","r");
    if((fgets(dizi2,150,yp))==NULL){
        fclose(yp);
        return 1;
    }else{
        while(!feof(yp)){
            ch=getc(yp);
            if(ch=='\n'){
                satir++;
            }
        }if(satir<=5){
            printf("Bu dosyadaki verinin BIG O hesaplamasi yapilamiyor.Satir sayisi 5 den azdir.");
            fclose(yp);
            return 1;
        }
    }
    return 0;
}
void intkontrol(char array[])
{
    if (strstr(array, intvarmi)){
        if (!(strstr(array, mainvarmi))){
            if (strstr(array, intvarmi)){
                sayac++;
                if (!(strstr(array, noktalivirgul)) && strstr(array, intvarmi)){
                    sayac++;
                }
            }
            if (strstr(array, virgul) && !(strstr(array, koseliparantez))){
                sayac++;
            }
            if ((strstr(array, matriskontrol)) && strstr(array, intvarmi)){
                sayac--;
            }
            if (strstr(array, intvarmi) && strstr(array, koseliparantez) && strstr(array, noktalivirgul) && !(strstr(array, matriskontrol))){
                sayac--;
            }
            if(strstr(array,voidvarmi)){
                sayac--;
            }
        }
    }
    intarraykontrol(array);
}
void intarraykontrol(char array[])
{
    if (strstr(array, matriskontrol) && strstr(array, intvarmi)){
        sayac3++;
    }
    if (strstr(array, koseliparantez) && strstr(array, intvarmi) && !(strstr(array, matriskontrol))){
        sayac2++;
    }
}
void doublekontrol(char array[])
{
    if (strstr(array, doublevarmi)){
        sayac7++;
        if (!(strstr(array, noktalivirgul)) && strstr(array, doublevarmi)){
            sayac7++;
        }
        if (strstr(array, virgul) && !(strstr(array, koseliparantez))){
            sayac7++;
        }
        if ((strstr(array, matriskontrol)) && strstr(array, doublevarmi)){
            sayac7--;
        }
        if (strstr(array, doublevarmi) && strstr(array, koseliparantez) && strstr(array, noktalivirgul) && !(strstr(array, matriskontrol))){
            sayac7--;
        }
    }
    doublearraykontrol(array);
}
void doublearraykontrol(char array[])
{
    if (strstr(array, matriskontrol) && strstr(array, doublevarmi)){
        sayac9++;
    }
    if (strstr(array, koseliparantez) && strstr(array, doublevarmi) && !(strstr(array, matriskontrol))){
        sayac8++;
    }
}
void floatkontrol(char array[])
{
    if (strstr(array, floatvarmi)){
        sayac++;
        if (!(strstr(array, noktalivirgul)) && strstr(array, floatvarmi)){
            sayac++;
        }
        if (strstr(array, virgul) && !(strstr(array, koseliparantez))){
            sayac++;
        }
        if ((strstr(array, matriskontrol)) && strstr(array, floatvarmi)){
            sayac--;
        }
        if (strstr(array, floatvarmi) && strstr(array, koseliparantez) && strstr(array, noktalivirgul) && !(strstr(array, matriskontrol))){
            sayac--;
        }
    }
    floatarraykontrol(array);
}
void floatarraykontrol(char array[])
{
    if (strstr(array, matriskontrol) && strstr(array, floatvarmi)){

        sayac3++;
    }
    if (strstr(array, koseliparantez) && strstr(array, floatvarmi) && !(strstr(array, matriskontrol))){

        sayac2++;
    }
}
void charkontrol(char array[])
{
    if (strstr(array, charvarmi)){
        sayac4++;
        if (!(strstr(array, noktalivirgul)) && strstr(array, charvarmi)){
            sayac4++;
        }
        if (strstr(array, virgul) && !(strstr(array, koseliparantez))){
            sayac4++;
        }
        if ((strstr(array, matriskontrol)) && strstr(array, charvarmi)){
            sayac4--;
        }
        if (strstr(array, charvarmi) && strstr(array, koseliparantez) && strstr(array, noktalivirgul) && !(strstr(array, matriskontrol))){
            sayac4--;
        }
         if (strstr(array, charvarmi) && strstr(array, koseliparantez) && !(strstr(array, noktalivirgul)) && !(strstr(array, matriskontrol))){
            sayac4--;
        }

          if(strstr(array,voidvarmi)){
                sayac4--;
            }
    }
    chararraykontrol(array);
}
void chararraykontrol(char array[])
{
    if (strstr(array, matriskontrol) && strstr(array, charvarmi)){
        sayac6++;
    }
    if (strstr(array, koseliparantez) && strstr(array, charvarmi) && !(strstr(array, matriskontrol))){
        sayac5++;
    }
}
void longkontrol(char array[])
{
    if (strstr(array, longvarmi)){
        sayac++;
        if (!(strstr(array, noktalivirgul)) && strstr(array, longvarmi)){
            sayac++;
        }
        if (strstr(array, virgul) && !(strstr(array, koseliparantez))){
            sayac++;
        }
        if ((strstr(array, matriskontrol)) && strstr(array, longvarmi)){
            sayac--;
        }
        if (strstr(array, longvarmi) && strstr(array, koseliparantez) && strstr(array, noktalivirgul) && !(strstr(array, matriskontrol))){
            sayac--;
        }
    }
    longarraykontrol(array);
}
void longarraykontrol(char array[])
{
   if (strstr(array, matriskontrol) && strstr(array, longvarmi)){

        sayac3++;
    }if (strstr(array, koseliparantez) && strstr(array, longvarmi) && !(strstr(array, matriskontrol))){

        sayac2++;
    }
}
void yerkarmasikligi(int counter, int counter2, int counter3, int counter4, int counter5, int counter6, int counter7, int counter8, int counter9)
{
    if ((counter || counter4 || counter7) != 0 && (counter2 || counter5 || counter8) != 0 && (counter3 || counter6 || counter9) != 0){
            if(enbuyukrecursive>7){
               printf("yer karmasikligi 2^n+%dn^2+%dn+%d ve O(2^n)'dir\n",(counter3*4 + counter6 + counter9*8),(counter2 * 4 + counter5 + counter8 * 8), (counter * 4 + counter4 + counter7 * 8));
            }else if(enbuyukrecursive==7){
            printf("yer karmasikligi %dn^2+%dn+%d ve O(n^2)\n", (counter3 * 4 + counter6 + counter9 * 8 +1), (counter2 * 4 + counter5 + counter8 * 8), (counter * 4 + counter4 + counter7 * 8));
            }else if(enbuyukrecursive==6){
            printf("yer karmasikligi %dn^2+%dn+nlogn+%d ve O(n^2)\n", (counter3 * 4 + counter6 + counter9 * 8 +1), ( counter2 * 4 + counter5 + counter8 * 8), (counter * 4 + counter4 + counter7 * 8));
            }else if(enbuyukrecursive==5){
            printf("yer karmasikligi %dn^2+%dn+%d ve O(n^2)\n", (counter3 * 4 + counter6 + counter9 * 8 +1), (1+counter2 * 4 + counter5 + counter8 * 8), (counter * 4 + counter4 + counter7 * 8));
            }else if(enbuyukrecursive==3){
            printf("yer karmasikligi %dn^2+%dn+logn+%d ve O(n^2)\n", (counter3 * 4 + counter6 + counter9 * 8 +1), (counter2 * 4 + counter5 + counter8 * 8), (counter * 4 + counter4 + counter7 * 8));
            }else{
            printf("yer karmasikligi %dn^2+%dn+%d ve O(n^2)\n", (counter3 * 4 + counter6 + counter9 * 8 +1), (counter2 * 4 + counter5 + counter8 * 8), (counter * 4 + counter4 + counter7 * 8));
            }
    }
    if ((counter || counter4 || counter7) != 0 && (counter2 || counter5 || counter8) != 0 && (counter3 || counter6 || counter9) == 0){
        if(enbuyukrecursive>7){
            printf("yer karmasikligi 2^n+%dn+%d ve O(2^n)\n", (counter2 * 4 + counter5 + counter8 * 8), (counter * 4 + counter4 + counter7 * 8));
        }else if(enbuyukrecursive==7){
         printf("yer karmasikligi n^2+%dn+%d ve O(n^2)\n", (counter2 * 4 + counter5 + counter8 * 8), (counter * 4 + counter4 + counter7 * 8));
        }else if(enbuyukrecursive==6){
         printf("yer karmasikligi nlogn+%dn+%d ve O(nlogn)\n", (counter2 * 4 + counter5 + counter8 * 8), (counter * 4 + counter4 + counter7 * 8));
        }else if(enbuyukrecursive==5){
         printf("yer karmasikligi %dn+%d ve O(n)\n", (1+counter2 * 4 + counter5 + counter8 * 8), (counter * 4 + counter4 + counter7 * 8));
        }else if(enbuyukrecursive==3){
         printf("yer karmasikligi %dn+logn+%d ve O(n)\n", (counter2 * 4 + counter5 + counter8 * 8), (counter * 4 + counter4 + counter7 * 8));
        }else{
         printf("yer karmasikligi %dn+%d ve O(n)\n", (counter2 * 4 + counter5 + counter8 * 8), (counter * 4 + counter4 + counter7 * 8));
        }
    }
    if ((counter || counter4 || counter7) != 0 && (counter2 || counter5 || counter8) == 0 && (counter3 || counter6 || counter9) == 0){
        if(enbuyukrecursive>7){
            printf("yer karmasikligi 2^n+%d ve O(2^n)\n", (counter * 4 + counter4 + counter7 * 8));
        }else if(enbuyukrecursive==7){
         printf("yer karmasikligi n^2+%d ve O(n^2)\n", (counter * 4 + counter4 + counter7 * 8));
        }else if(enbuyukrecursive==6){
           printf("yer karmasikligi nlogn+%d ve O(nlogn)\n", (counter * 4 + counter4 + counter7 * 8));
        }else if(enbuyukrecursive==5){
           printf("yer karmasikligi n+%d ve O(n)\n", (counter * 4 + counter4 + counter7 * 8));
        }else if(enbuyukrecursive==3){
           printf("yer karmasikligi logn+%d ve O(logn)\n", (counter * 4 + counter4 + counter7 * 8));
        }else{
          printf("yer karmasikligi %d ve O(1)\n", (counter * 4 + counter4 + counter7 * 8));
        }
    }
    if ((counter || counter4 || counter7) != 0 && (counter2 || counter5 || counter8) == 0 && (counter3 || counter6 || counter9) != 0){
       if(enbuyukrecursive>7){
           printf("yer karmasikligi 2^n+%dn2+%d ve O(2^n)\n", (counter3 * 4 + counter6 + counter9 * 8), (counter * 4 + counter4 + counter7 * 8));
        }else if(enbuyukrecursive==7){
        printf("yer karmasikligi %dn2+%d ve O(n^2)\n", (1+counter3 * 4 + counter6 + counter9 * 8), (counter * 4 + counter4 + counter7 * 8));
        }else if(enbuyukrecursive==6){
        printf("yer karmasikligi %dn2+nlogn+%d ve O(n^2)\n", (counter3 * 4 + counter6 + counter9 * 8), (counter * 4 + counter4 + counter7 * 8));
        }else if(enbuyukrecursive==5){
         printf("yer karmasikligi %dn2+n+%d ve O(n^2)\n", (counter3 * 4 + counter6 + counter9 * 8), (counter * 4 + counter4 + counter7 * 8));
        }else if(enbuyukrecursive==3){
        printf("yer karmasikligi %dn2+logn+%d ve O(n^2)\n", (counter3 * 4 + counter6 + counter9 * 8), (counter * 4 + counter4 + counter7 * 8));
        }else{
         printf("yer karmasikligi %dn2+%d ve O(n^2)\n", (counter3 * 4 + counter6 + counter9 * 8), (counter * 4 + counter4 + counter7 * 8));
        }
    }
}
int main()
{
    int enbuyuk,a,tmp;
    FILE *fp2;
    char dizi[150];
    char arr[2000];
    fp2=fopen("ornekkod4.txt","r");
    if(dosyakontrol(fp2,dizi))
    {
        printf("dosya bostur!!\n");
    }
    else
    {
        printf("dosya dolu\n");
        printf("BIG O hesaplamasi yapiliyor...\n");

        while(!feof(fp2))
        {
            fgets(dizi,150,fp2);

            if(parantez==0 && strstr(dizi, voidvarmi) ){
                if(fonksiyon>0){
                recursivekontrol(dizi);
                }
                bolusayisi=0,ificinderecursive=0,recursivesayisi=0,kacrecursive=0,aynisatir=0;
                a=5,tmp=0,tekbolu=0;
                while(1){
                        if(dizi[a]== *bosluk){
                           break;
                        }else if(dizi[a]== *acikparantez){
                           break;
                        }else{
                          dizi3[fonksiyon][tmp]=dizi[a];
                          tmp++;
                          a++;
                        }
                }
                 printf(" fonksiyonun ismi: %s\n",dizi3[fonksiyon]);

                    fonksiyon++;

            }else if(parantez==0 && strstr(dizi, intvarmi)){
                if(fonksiyon>0){
                recursivekontrol(dizi);
                }
                bolusayisi=0, ificinderecursive=0,recursivesayisi=0,aynisatir=0,kacrecursive=0;
                a=4,tmp=0,tekbolu=0;
                while(1){
                        if(dizi[a]== *bosluk){
                           break;
                        }else if(dizi[a]== *acikparantez){
                           break;
                        }else{
                          dizi3[fonksiyon][tmp]=dizi[a];
                          tmp++;
                          a++;
                        }
                }

                 printf(" fonksiyonun ismi: %s\n",dizi3[fonksiyon]);
                    fonksiyon++;

            }
             printf("%s",dizi);
             if(parantez>0 &&  strstr(dizi, dizi3[fonksiyon-1])){
            recursive(dizi);
            }

            if(strstr(dizi, susluparantez)){
                parantez++;
            }else if(strstr(dizi, susluparantez2)){
                parantez--;
            }
            if(strstr(dizi, bolu)){
            bolusayisi++;
        }
           ifcheck(dizi, fp2);

            if(strstr(dizi,forvarmi))
            {   artiskontrol(dizi);
                forkontrol(dizi,fp2);
            }
            if(strstr(dizi, wvarmi) && !(strstr(dizi, noktalivirgul))){
                artiskontrolw(dizi);
                whilekontrol(dizi,fp2);
            }
            if(strstr(dizi, dovarmi) && strstr(dizi, susluparantez)){
               dokontrol(dizi,fp2);
            }
        }
    }
    enbuyuk=enbuyukObul(bigO);
    enbuyukrecursive=enbuyukObul(recursivebigO);
    switch(enbuyuk){
    case 1:
        printf("\nkodun big o degeri O(1)dir.\n");
        break;
    case 2:
        printf("\nkodun big o degeri O(loglogn)dir.\n");
        break;
     case 3:
        printf("\nkodun big o degeri O(logn)dir.\n");
        break;
     case 4:
        printf("\nkodun big o degeri O((logn)^2)dir.\n");
        break;
     case 5:
        printf("\nkodun big o degeri O(n)dir.\n");
        break;
     case 6:
        printf("\nkodun big o degeri O(nlogn)dir.\n");
        break;
     case 7:
        printf("\nkodun big o degeri O(n^2)dir.\n");
        break;
      case 8:
        printf("\nkodun big o degeri O(n^2logn)dir.\n");
        break;
      case 9:
        printf("\nkodun big o degeri O(n^3)dur.\n");
        break;
      case 10:
        printf("\nkodun big o degeri O(2^n)dir.\n");
        break;
      default:
          printf("\nbigO hesaplamasi yapilamadi veya O(1)\n");

    }
    fseek(fp2, 0, SEEK_SET);
    if(dosyakontrol(fp2,dizi))
    {
        printf("dosya bostur!!\n");
    }
    else
    {
    char array[100];

    while (!feof(fp2))
    {
        fgets(array, 100, fp2);
        intkontrol(array);
        floatkontrol(array);
        charkontrol(array);
        longkontrol(array);
        doublekontrol(array);
    }
    yerkarmasikligi(sayac, sayac2, sayac3, sayac4, sayac5, sayac6, sayac7, sayac8, sayac9);

    fseek(fp2, 0, SEEK_SET);
    int b=0;
    char dizi3[100];
    int satiruzunlugu;
    while(!feof(fp2)){

        fgets(dizi3,100, fp2);
        satiruzunlugu=strlen(dizi3);
        for(int i=0;i<satiruzunlugu;i++){
            arr[b]=dizi3[i];
            b++;
        }
    }
    double time_spent = 0.0;

    clock_t begin = clock();

   FILE *proc = popen("gcc -x c -", "w");
    fwrite(arr, sizeof(char), strlen(arr), proc);
    clock_t end = clock();

    pclose(proc);
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("gecen zaman %f saniye\n", time_spent);

    fclose(fp2);
    }
    return 0;
 }
