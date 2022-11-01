#include <stdio.h>
#include <stdlib.h>

 struct Land {

    char co[4]; // code
    char na[50]; // name
    char ct[50]; // contient
    long po; // population
    long su; // surface area

};


# define TOTAL_PAYS 10


int main()
{
    struct Land l[TOTAL_PAYS];

    FILE *r = fopen("country.csv","r");

    FILE *w = fopen("pays.txt","w");

    if(r==NULL && w == NULL) {

         printf(" Can't open files ");
         return 1;
    }


    int re = 0;

    int cor = 0;



    do {


         // Code,Name,Continent,SurfaceArea,Population,
          re = fscanf(r,"%4[^,],%50[^,],%50[^,],%lu,%lu \n",&l[cor].co,l[cor].na,l[cor].ct,&l[cor].su,&l[cor].po);

//          printf(" re = %d ",re);

          if( re!=5 && !feof(r) ){

             printf("File format incorrect.\n");
             return 1;

          }

          if (ferror(r))
            {
                  printf("Error reading file.\n");
                  return 1;
            }



       cor++;


    } while(!feof(r) && cor<TOTAL_PAYS);

    fclose(r);

  for (int i = 0; i < TOTAL_PAYS; i++)
  {
//    printf("i %d - code = %s name = %s contient = %s surface = %lu population =  %lu  \n ",i,l[i].co,l[i].na,l[i].ct,l[i].su,l[i].po);

    fprintf(w,"%s,%s,%s,%lu,%lu \n",l[i].co,l[i].na,l[i].ct,l[i].su,l[i].po);


    if (ferror(w))
    {
      printf("Error writing to file.\n");
      return 1;
    }

  }

   fclose(w);

                    /*
                                      =========================

                                             LES REQUETES

                                      =========================
                                                                           */

                                  /*
                                          les noms du pays ayant une surface > 1 000 000

                                                                                           */



     w = fopen("pays.txt","r");

     cor = 0;


    printf("\t \t  Les noms du pays ayant une surface > 1 000 000 : \n \n ");

    struct Land l2[50];
     int i = 0;
    do {


         // Code,Name,Continent,SurfaceArea,Population,
          re = fscanf(w,"%4[^,],%50[^,],%50[^,],%lu,%lu \n",&l[cor].co,l[cor].na,l[cor].ct,&l[cor].su,&l[cor].po);

          if(l[cor].su > 1000000)
             printf("- nom : %s \n",l[cor].na);
           // printf("l2 -> %s \n ",l[cor].ct);

//           printf("strcmp(str1, str2) = %d\n", strcmp(l[cor].ct,"Africa"));

           if(strcmp(l[cor].ct,"Africa")==0){

//               printf("l2 -> %s \n ",l[cor].ct);
               strcpy(l2[i].co ,l[cor].co);
               i++;
           }




          if (ferror(w))
            {
                  printf("Error reading file.\n");
                  return 1;
            }



       cor++;


    } while(!feof(w));

    fclose(w);
                         /*

                                    Les codes du pays appatinent au continent africain


                                                                                            */

               printf("\n \n \t \t Les codes du pays appatinent au continent africain : \n \n ");


       for(int j=0;j<i;j++){

         printf("- code : %s \n ",l2[j].co);


       }


                                /*

                                                   Toutes les pays


                                                                                            */
                    printf("\n \n \t \t Toutes les données  des pays : \n \n ");

      for(i= 0 ;i<cor;i++)
          printf(" code = %s name = %s contient = %s surface = %lu population =  %lu  \n ",l[i].co,l[i].na,l[i].ct,l[i].su,l[i].po);



    return 0;
}
