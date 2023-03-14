#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>


typedef enum{
    MAY_BAY_THUONG_MAI,
    MAY_BAY_TRUC_THANG,
    XE_KHACH,
    XE_DAP,
    XE_MAY,
    TAU_THUY,
    CANO
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

void duong_hang_khong(phuong_tien_giao_thong *phuong_tien){
    printf("######################\n");
    printf("Ban da chon duong hang khong!!!!");
    printf("Vui long chon loai phuong tien\n");
    printf("Nhan 1: May bay thuong mai\n");
    printf("Nhan 2: May bay truc thang\n");
    printf("Nhan 0: Quay lai\n");
    int phim = 0;
    scanf("%d", &phim);
    switch (phim)
    {
    case 1:
        printf("Ban chon: May bay thuong mai\n");
        phuong_tien->duong_hang_khong.may_bay_thuong_mai = MAY_BAY_THUONG_MAI;
        break;
    case 2:
        printf("Ban chon: May bay truc thang\n");
        phuong_tien->duong_hang_khong.may_bay_truc_thang = MAY_BAY_TRUC_THANG;
        break;
    default:
        break;
    }
}
void duong_bo(phuong_tien_giao_thong *phuong_tien){
	
    printf("######################\n");
    printf("Ban da chon duong bo!!!!");
    printf("Vui long chon loai phuong tien\n");
    printf("Nhan 1: Xe khach\n");
    printf("Nhan 2: Xe Dap\n");
    printf("Nhan 3: Xe May\n");
    printf("Nhan 0: Quay lai\n");
    int phim = 0;
    scanf("%d", &phim);
    switch (phim)
    {
    case 1:
        printf("Ban chon: Xe khach\n");
        phuong_tien->duong_bo.xe_khach =XE_KHACH ;
        break;
    case 2:
        printf("Ban chon: Xe Dap\n");
        phuong_tien->duong_bo.xe_dap = XE_DAP;
        break;
    case 3:
        printf("Ban chon: Xe May\n");
        phuong_tien->duong_bo.xe_may = XE_MAY;
        break;
    default:
        break;
    }
}
void duong_thuy(phuong_tien_giao_thong *phuong_tien){
    printf("######################\n");
    printf("Ban da chon duong thuy!!!!");
    printf("Vui long chon loai phuong tien\n");
    printf("Nhan 1: Tau Thuy\n");
    printf("Nhan 2: Cano\n");
    printf("Nhan 0: Quay lai\n");
    int phim = 0;
    scanf("%d", &phim);
    switch (phim)
    {
    case 1:
        printf("Ban chon: Tau Thuy\n");
        phuong_tien->duong_thuy.tau_thuy =TAU_THUY;
        break;
    case 2:
        printf("Ban chon: Cano\n");
        phuong_tien->duong_thuy.ca_no = CANO;
        break;
    default:
        break;
    }
}
void Chuong_Trinh_Chon_Duong(phuong_tien_giao_thong *phuong_tien){
	back:
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
        duong_hang_khong(phuong_tien);
        break;
    case 2:
        duong_bo(phuong_tien);
        break;
    case 3:
        duong_thuy(phuong_tien);
        break;
    case 0:
        exit(0);
    default:
        break;
    }
}
void Hien_Thi_Gia(phuong_tien_giao_thong phuong_tien){
    
   switch (phuong_tien.loai_phuong_tien)
   {
   case MAY_BAY_THUONG_MAI:
        printf("Loai phuong tien: May bay thuong mai\n");
        printf("Gia ve: 1.000.000 vnd\n");
    break;
   case MAY_BAY_TRUC_THANG:
        printf("Loai phuong tien: May bay truc thang\n");
        printf("Gia ve: 1.200.000 vnd\n");
    break;
    case XE_KHACH:
        printf("Loai phuong tien: Xe Khach\n");
        printf("Gia ve: 120.000 vnd\n");
    break;
    case XE_MAY:
        printf("Loai phuong tien: Xe May\n");
        printf("Gia ve: 80.000 vnd\n");
    break;
    case XE_DAP:
        printf("Loai phuong tien: Xe Dap\n");
        printf("Gia ve: 20.000 vnd\n");
    break;
    case TAU_THUY:
        printf("Loai phuong tien: Tau Thuy\n");
        printf("Gia ve: 200.000 vnd\n");
    break;
    case CANO:
        printf("Loai phuong tien: Cano\n");
        printf("Gia ve: 300.000 vnd\n");
    break;
   default:
    break;
   }
}


int main(int argc, char const *argv[])
{

    phuong_tien_giao_thong phuong_tien;
    
    Chuong_Trinh_Chon_Duong(&phuong_tien);

    
    Hien_Thi_Gia(phuong_tien);

    
  
    return 0;
}
