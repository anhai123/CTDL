#include <iostream>
#include <iomanip>

using namespace std;

struct SoHuuTy
{
    int tuSo;
    int mauSo; // thiet ke cac truong o day
};
typedef struct SoHuuTy SHT;

int main();

void nhapSHT(SHT *);
void inSHT(const SHT *);
void toiGianSHT(SHT *);
SHT *congSHT(const SHT *, const SHT *);
int soSanhSHT(const SHT *, const SHT *);
void sapXepLuaChonMangSHT(SHT *, int);
void HoanVi(SHT *ps1, SHT *ps2);
void SapXep(SHT *arr, int n);
double TBC(SHT *mangSHT, int soPhanTu);
int main()
{
    // cap phat bo nho dong cho con tro toi mot so huu ti
    SHT *sht1 = new SHT;
    SHT *sht2 = new SHT;
    SHT *tongSHT = new SHT;

    // cap phat bo nho dong cho mang cac so huu ti
    SHT *mangSHT = new SHT[100];

    nhapSHT(sht1);
    inSHT(sht1);

    nhapSHT(sht2);
    inSHT(sht2);

    tongSHT = congSHT(sht1, sht2);
    inSHT(tongSHT);

    return 0;
}
int UCLN(int tuso, int mauso)
{
    if (mauso == 0)
        return tuso;
    return UCLN(mauso, tuso % mauso);
}
void HoanVi(SHT *ps1, SHT *ps2)
{
    SHT *temp = ps1;
    *ps1 = *ps2;
    *ps2 = *temp;
}

void SapXep(SHT *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].tuSo * arr[j + 1].mauSo > arr[j + 1].tuSo * arr[j].mauSo)
            {
                // SHT *temp1 = arr[j];
                HoanVi(&arr[j], &arr[j + 1]);
            }
        }
    }
}
void nhapSHT(SHT *sht)
{
    if (sht->mauSo == 0)
    {
        cout << "mau so phai khac 0 nhe";
        nhapSHT(sht);
    }
    else
    {
        toiGianSHT(sht);
    }
}

// in duoi dang phan so a/b
void inSHT(const SHT *sht)
{
    cout << sht->tuSo << ' / ' << sht->mauSo;
}

// tu so va mau so cua 1 so huu ti nguyen to cung nhau
// luu y: so huu ti luon luon phai luu duoi dang nay
void toiGianSHT(SHT *sht)
{
    int uc = UCLN(sht->tuSo, sht->mauSo);
    sht->tuSo /= uc;
    sht->mauSo /= uc;
}

SHT *congSHT(const SHT *sht1, const SHT *sht2)
{
    // gia tri tra ve la tong 2 so huu ti sht1 va sht2
    // can cap phat bo nho dong cho bien tong cua 2 so huu ti
    // sau do tra con tro nay ve
    SHT *tongSHT = new SHT;
    tongSHT->tuSo = sht1->tuSo * sht2->mauSo + sht2->tuSo * sht1->mauSo;
    tongSHT->mauSo = sht1->mauSo * sht2->mauSo;
    // tongSHT = sht1 + sht2;
    toiGianSHT(tongSHT);
    return tongSHT;
}

// tra ve 1 neu sht1 > sht2
// tra ve 0 neu sht1 = sht2
// tra ve -1 neu sht1 < sht2
int soSanhSHT(const SHT *sht1, const SHT *sht2)
{
    int ts1 = sht1->tuSo * sht2->mauSo;
    int ts2 = sht2->tuSo * sht1->mauSo;

    if (ts1 > ts2)
    {
        return 1; // ps1 > ps2
    }
    else if (ts1 < ts2)
    {
        return -1; // ps1 < ps2
    }
    else
    {
        return 0; // ps1 = ps2
    }
}

// sap xep su dung thuat toan lua chon
void sapXepLuaChonMangSHT(SHT *mangSHT, int soPhanTu)
{
    int i, j;
    int viTriMin;
    for (i = 0; i < soPhanTu - 1; i++)
    {
        viTriMin = i;
        for (j = i + 1; j < soPhanTu; j++)
        {
            // thay doi vi tri cua min moi
            if (soSanhSHT(&mangSHT[viTriMin], &mangSHT[j]) == 1)
            {
                viTriMin = j;
            }
        }
        // doi cho phan tu nho nhat voi phan tu dau tien trong day chua sap xep (vi tri i)
        SHT temp = mangSHT[i];
        mangSHT[i] = mangSHT[viTriMin];
        mangSHT[viTriMin] = temp;
    }
}
double TBC(SHT *mangSHT, int soPhanTu)
{
    double tong = 0;
    for (int i = 0; i < soPhanTu; i++)
    {
        // Chuyển phân số thành số thập phân
        tong += (double)mangSHT[i].tuSo / mangSHT[i].mauSo;
    }

    // Tính trung bình cộng
    double tb = tong / soPhanTu;

    // In kết quả ra màn hình
    cout << setprecision(2) << fixed;
    cout << "Trung binh cong: " << tb;
}
