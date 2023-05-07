#include "Defs.h"
#include "Jerry.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

char* wordUpper(char* a){
    for (int i = 0; a[i]!='\0'; i++) {
        if(a[i] >= 'a' && a[i] <= 'z') {
            a[i] = a[i] - 32;
        }
    }
    return a;


}

int main(int argc, char* argv[]) {
    int numberOfPlanets=atoi(argv[1]);
    int numberOfJerries=atoi(argv[2]);
    int i;
    FILE *pFile;
    pFile= fopen(argv[3],"r");
    char line[300];
    char s[3] = ",";
    char *token;
    int p;
    char *jer[4];
    char *pl[4];
    char* att[2];
    planets *newplanets[numberOfPlanets];
    jerry *newJerreis[numberOfJerries];
    if (pFile == NULL)
        return 0;
    // planet word
    fgets(line, 300, pFile);
    //ALL PLANETS
    fgets(line, 300, pFile);

    for (i = 0; i < numberOfPlanets; i++) {
        p = 0;
        token = strtok(line, s);
        while (token != NULL) {
            pl[p] = token;
            token = strtok(NULL, s);
            p++;
        }
        newplanets[i] = initPlanet(pl[0], atof(pl[1]), atof(pl[2]), atof(pl[3]));
        if(newplanets[i]== NULL){
            printf("Memory Problem");
        }
        fgets(line, 300, pFile);
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    //ALL JERREIS
    fgets(line, 300, pFile);
    int j;
    char attn[300] ;
    double value;
    //ALL JERREIS
    for (j = 0; j < numberOfJerries; j++) {
        i=0;
        token = strtok(line, s);
        jer[i] = token;
        while (token != NULL) {
            jer[i] = token;
            token = strtok(NULL, ",\n");
            i++;
        }
        for (i = 0; i < numberOfPlanets; i++) {
            if (strcmp(newplanets[i]->name, jer[2]) == 0) {
                newJerreis[j] = initJerry(jer[0], atoi(jer[3]), jer[1], newplanets[i]);
                if(newJerreis[j]==NULL){
                    printf("Memory Problem");
                }
                break;
            }
        }



        fgets(line, 300, pFile);
        //    //JERRY'S Attribute
        while(line[0] == '\t') {
            token = strtok(line, "\t:\r");
            strcpy(attn,token);
            token = strtok(NULL, ":\n\r");
            if(token==NULL){break;}
            value = atof(token);
            addAttribute(newJerreis[j],attn,value );
            /*printf("att:%s\nvalue:%.2f\n",attn,value);*/
            fgets(line, 300, pFile);
        }

    }
    fclose(pFile);
    bool done=true;
    char number=-1;
    while(done) {
        number=-1;
        printf("AW JEEZ RICK, what do you want to do now ? \n");
        printf("1 : Print all Jerries \n");
        printf("2 : Print all Planets \n");
        printf("3 : Add physical characteristic to Jerry \n");
        printf("4 : Remove physical characteristic from Jerry \n");
        printf("5 : Print Jerries by a planet \n");
        printf("6 : Print Jerries by a physical characteristic \n");
        printf("7 : Go home \n");
        scanf("%s", &number);
        char jerryName[30];
        char physicalAtt[30] ;
        double attValue;
        char id[30];
        int c;
        int f;
        int flag;
        char planetsName[30];
        jerry * jerry1;
        switch (number) {
            case '1':
                for (i = 0; i < numberOfJerries; i++) {
                    printJerry(newJerreis[i]);
                }
                break;

            case '2':
                for (int i = 0; i < numberOfPlanets; i++) {
                    printPlanet(newplanets[i]);
                }
                break;

            case '3':
                c=0;
                flag=0;
                printf("What is your Jerry's ID ? \n");
                scanf("%s", jerryName);
                for (i = 0; i < numberOfJerries; i++) {
                    if (strcmp(jerryName, newJerreis[i]->id) == 0) {
                        c++;
                        jerry1=newJerreis[i];
                    }
                }
                if(c==0){
                    printf("OH NO! I CAN'T FIND HIM RICK ! \n");
                    break;
                }
                printf("What physical characteristic can you add to Jerry - %s ? \n", jerry1->id);
                scanf("%s", physicalAtt);
                flag=0;
                if(jerry1->attributeNum>0) {
                    for (f = 0; f < jerry1->attributeNum; f++) {
                        if (strcmp(physicalAtt, jerry1->p[f]->name) == 0) {
                            printf("RICK I ALREADY KNOW HIS %s ! \n", wordUpper(physicalAtt));
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0){
                    printf("What is the value of his %s ? \n", physicalAtt);
                    scanf("%lf", &attValue);
                    addAttribute(jerry1, physicalAtt, attValue);
                    printJerry(jerry1);
                    break;}
                }
                else{
                    printf("What is the value of his %s ? \n", physicalAtt);
                    scanf("%lf", &attValue);
                    addAttribute(jerry1, physicalAtt, attValue);
                    printJerry(jerry1);
                }

                break;

            case '4':
                flag=0;
                jerry1=NULL;
                printf("What is your Jerry's ID ? \n");
                scanf("%s", id);
                for (j = 0; j < numberOfJerries; j++) {
                    if (strcmp(id, newJerreis[j]->id) == 0) {
                        jerry1=newJerreis[j];

                    } else { flag++; }
//
                }
                if(jerry1==NULL){
                    printf("OH NO! I CAN'T FIND HIM RICK ! \n");
                    break;
                }

                printf("What physical characteristic do you want to remove from Jerry - %s ? \n", id);
                scanf("%s", physicalAtt);
                c=jerry1->attributeNum;
                if(jerry1->attributeNum>0){
                    for (i = 0; i < jerry1->attributeNum; i++) {
                            if (strcmp(physicalAtt,jerry1->p[i]->name) == 0) {
                                removeAttribute(jerry1, physicalAtt);
                                printJerry(jerry1);
                                break;
                            }
//
                    }
                    if(c==jerry1->attributeNum){
                        printf("RICK I DON'T KNOW HIS %s ! \n", wordUpper(physicalAtt));
                        break;
                    }
                }
                else{
                    printf("RICK I DON'T KNOW HIS %s ! \n", wordUpper(physicalAtt));
                    break;
                }

                break;
            case '5':
                printf("What planet is your Jerry from ? \n");
                scanf("%s", planetsName);
                planets * p=NULL;
                bool f =false;
                for (i = 0; i < numberOfPlanets; i++) {
                    if (strcmp(planetsName, newplanets[i]->name) == 0) {
                        p=newplanets[i];
                        break;
                    }
                }
                if(p==NULL){printf("RICK I NEVER HEARD ABOUT %s ! \n", wordUpper(planetsName));
                    break;}
                for (j = 0; j < numberOfJerries; j++) {
                    if (strcmp(planetsName, newJerreis[j]->planet[i].name) == 0) {
                        printJerry(newJerreis[j]);
                        f=true;
                    }
                }
                if(f==false){
                printf("OH NO! I DON'T KNOW ANY JERRIES FROM %s ! \n", wordUpper(planetsName));
                }
                break;

            case '6': {
                bool f =true;
                memset(physicalAtt,0,30);
                printf("What do you know about your Jerry ? \n");
                scanf("%s", physicalAtt);
                for (j = 0; j < numberOfJerries; j++) {
                    for (i = 0; i < newJerreis[j]->attributeNum; i++) {
                        if (strcmp(physicalAtt, newJerreis[j]->p[i]->name) == 0) {
                            printJerry(newJerreis[j]);
                            f=false;
                        }

                    }
                }
                if(f){
                    printf("OH NO! I DON'T KNOW ANY JERRY'S %s ! \n", wordUpper(physicalAtt));
                }
                break;
            }
            case '7': {
                for (j = 0; j < numberOfPlanets; j++) {
                    deletePlanet(newplanets[j]);
                }
                for (i = 0; i < numberOfJerries; i++) {
                    deletejerry(newJerreis[i]);
                }
                printf("AW JEEZ RICK, ALL THE JERRIES GOT FREE ! \n");
                done=false;
                break;
            }
            default:{
                printf("RICK WE DON'T HAVE TIME FOR YOUR GAMES ! \n");
                break;

            }

        }
    }

    return 0;
}
