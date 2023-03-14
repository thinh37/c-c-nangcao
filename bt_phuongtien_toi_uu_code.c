#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
int leght(char a[100]){
    int i=0;
    int tong=0;
    while (a[i]!='\0')
    {
        tong=tong+a[i];
        i++;
    }
    return tong;
}

typedef enum{
    MAY_BAY_THUONG_MAI=1711,
    MAY_BAY_TRUC_THANG=1715,
    XE_KHACH=764,
    XE_DAP=562,
    XE_MAY=580,
    TAU_THUY=820,
    CANO=449
}phuong_tien;


typedef union{
    phuong_tien may_bay_thuong_mai;
    phuong_tien may_bay_truc_thang;
}hang_khong;

typedef union{
    phuong_tien xe_khach;
    phuong_tien xe_may;
    phuong_tien xe_dap;
}bo;

typedef union{
    phuong_tien tau_thuy;
    phuong_tien ca_no;
}thuy;

typedef union{
    hang_khong duong_hang_khong;
    bo duong_bo;
    thuy duong_thuy;
    phuong_tien loai_phuong_tien;
}phuong_tien_giao_thong;

#define PHUONG_TIEN_GIAO_THONG(loai_hinh, num, ...)                                 \
    loai_hinh                                                                       \
    char key_value[num][20];                                                        \
    static int index = 0;                                                           \
    int phim = 0;                                                                   \
    __VA_ARGS__                                                                     \
    printf("Vui long chon loai phuong tien\n");                                     \
    for (int i = 0; i < index; i++)                                                 \
    {                                                                               \
        printf("Nhan %d: %s\n",i+1, key_value[i]);                                  \
    }                                                                               \
    printf("Nhan 0: Thoat\n");                                                      \
    printf("Vui long nhan phim: ...");                                              \
    scanf("%d", &phim);                                                             \
    for (int i = 0; i < index; i++)                                                 \
    {                                                                               \
        if((phim-1) == i){                                                          \
            printf("Ban chon: %s\n", key_value[i]);                                 \
            printf("Loai phuong tien: %s\n",key_value[i]);                          \
            phuong_tien->loai_phuong_tien=leght(key_value[i]);                      \
        }                                                                           \
    }                                                                               \
    }
    
#define LOAI_HINH(name)                                                      \
void name(phuong_tien_giao_thong *phuong_tien){


#define PHUONG_TIEN(value)                                                          \
    strcpy(key_value[index], (char*)value);                                         \
    index++;                    

#define SO_LUONG_PHUONG_TIEN(num) num


PHUONG_TIEN_GIAO_THONG(
        LOAI_HINH(Duong_Hang_Khong),
        SO_LUONG_PHUONG_TIEN(2),
            PHUONG_TIEN("may bay thuong mai")
            PHUONG_TIEN("may bay truc thang")
        );
PHUONG_TIEN_GIAO_THONG(
        LOAI_HINH(Duong_Bo),
        SO_LUONG_PHUONG_TIEN(3),
            PHUONG_TIEN("xe may")
            PHUONG_TIEN("xe khach")
            PHUONG_TIEN("xe dap")
        );
PHUONG_TIEN_GIAO_THONG(
        LOAI_HINH(Duong_Thuy),
        SO_LUONG_PHUONG_TIEN(2),
            PHUONG_TIEN("tau thuy")
            PHUONG_TIEN("ca no")
        );


void Chuong_Trinh_Chon_Duong(phuong_tien_giao_thong *phuong_tien){
	
    printf("Ban muon di chuyen bang duong nao?\n");
    printf("Nhan 1: Duong Hang Khong\n");
    printf("Nhan 2: Duong Bo\n");
    printf("Nhan 3: Duong Thuy\n");
    printf("Nhan 0: Thoat chuong trinh\n");
    int phim = 0;
    scanf("%d", &phim);

    switch (phim)
    {
    case 1:
        Duong_Hang_Khong(phuong_tien);
        break;
    case 2:
        Duong_Bo(phuong_tien);
        break;
    case 3:
        Duong_Thuy(phuong_tien);
        break;
    case 0:
        exit(0);
    default:
        break;
    }
}
#define GIA_VE(money) \
printf("Gia ve:"); \
printf(#money);
void Hien_Thi_Gia(phuong_tien_giao_thong phuong_tien){
    
   switch (phuong_tien.loai_phuong_tien)
   {
   case MAY_BAY_THUONG_MAI:
        GIA_VE(1.000.000 VND);
    break;
   case MAY_BAY_TRUC_THANG:
        GIA_VE(1.200.000 VND);
    break;
    case XE_KHACH:
        GIA_VE(120.000 VND);
    break;
    case XE_MAY:
        GIA_VE(80.000 VND);
    break;
    case XE_DAP:
        GIA_VE(20.000 VND);
    break;
    case TAU_THUY:
        GIA_VE(200.000 VND);
    break;
    case CANO:
        GIA_VE(300.000 VND);
    break;
   default:
    break;
}
}
int main(int argc, char const *argv[]){
    phuong_tien_giao_thong phuong_tien;

    
    Chuong_Trinh_Chon_Duong(&phuong_tien);
    
    Hien_Thi_Gia(phuong_tien);
    return 0;
}
