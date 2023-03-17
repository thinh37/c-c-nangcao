#include<stdio.h>
#include<stdint.h>
uint8_t  GIO_HANG; 
typedef enum{
    AO=1<<0,
    QUAN=1<<1,
    VAY=1<<2,
    BAN_CHAI=1<<3,
    NHAN=1<<4,
    TUI=1<<5,
    GIAY=1<<6,
    BALO=1<<7
}DO_DUNG_CA_NHAN;
void THEM_VAO_GIO_HANG(uint8_t *gio_hang,DO_DUNG_CA_NHAN them){
    *gio_hang|=them;
}
void XOA_KHOI_GIO_HANG(uint8_t *gio_hang,DO_DUNG_CA_NHAN xoa){
    *gio_hang&=~xoa;
}

#define kiem_tra(DO_DUNG) \
if(((*gio_hang&DO_DUNG)==DO_DUNG)&((temp&DO_DUNG)==DO_DUNG)) {\
    printf("%s da ton tai trong gio hang \n",#DO_DUNG);}\
else if((temp&DO_DUNG)==DO_DUNG) printf("%s khong ton tai trong gio hang\n",#DO_DUNG);

void KIEM_TRA_SAN_PHAM(uint8_t *gio_hang,DO_DUNG_CA_NHAN do_dung){
    
    DO_DUNG_CA_NHAN temp=do_dung;
    kiem_tra(AO);
    kiem_tra(QUAN);
    kiem_tra(VAY);
    kiem_tra(BAN_CHAI);
    kiem_tra(NHAN);
    kiem_tra(TUI);
    kiem_tra(GIAY);
    kiem_tra(BALO);
}
#define KIEM_TRA(DO_DUNG) if((*gio_hang&DO_DUNG)==DO_DUNG) {i++; printf("%d   %s \n",i,#DO_DUNG);}
void KIEM_TRA_GIO_HANG(uint8_t *gio_hang){
    int i=0;
    printf("STT TEN\n");
    KIEM_TRA(AO);
    KIEM_TRA(QUAN);
    KIEM_TRA(VAY);
    KIEM_TRA(BAN_CHAI);
    KIEM_TRA(NHAN);
    KIEM_TRA(TUI);
    KIEM_TRA(GIAY);
    KIEM_TRA(BALO);
}

 
int main(int argc, char const *argv[])
{   //uint8_t  GIO_HANG;                         
    
    THEM_VAO_GIO_HANG(&GIO_HANG,AO|QUAN|NHAN|BAN_CHAI);
    KIEM_TRA_SAN_PHAM(&GIO_HANG,QUAN|BALO|BAN_CHAI|TUI);
    KIEM_TRA_GIO_HANG(&GIO_HANG);
    return 0;
}
