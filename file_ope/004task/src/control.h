#ifndef __control_H__
#define __control_H__
void conmain(Fruit p[],int *pidx);
int file_load(Fruit*p,int *pidx);
int file_save(Fruit*p,int indx);

int condele_fruit(Fruit*p,int *pidx);
int conupdate_fruit(Fruit*p,int *pidex);

#endif
