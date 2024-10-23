#include <iostream>
using namespace std;

struct Thongke {
    int Nam;
    int SoNguoiSinh;
};

int main() {
    const int nam_dau = 1920;
    const int nam_cuoi = 1970;
    const int n = nam_cuoi - nam_dau + 1;

    Thongke Thongke[n];

    for (int i = 0; i < n; ++i) {
        Thongke[i].Nam = nam_dau + i;
        cout <<  Thongke[i].Nam << "  ";
        cin >> Thongke[i].SoNguoiSinh;
    }

    // In ra những năm không có người nào được sinh ra
    int khongsinh=0;
    for (int i = 0; i < n; ++i) {
        if (Thongke[i].SoNguoiSinh == 0) {
            khongsinh++;
        }
    }
    cout<<"So nam khong co nguoi sinh ra: "<<khongsinh<<endl;

    // Tính số lượng những năm mà số người sinh ra không quá 10
    int Sinhit = 0;
    for (int i = 0; i < n; ++i) {
        if (Thongke[i].SoNguoiSinh <= 10) {
            Sinhit++;
        }
    }
    cout << "So luong nam co so nguoi sinh ra khong qua 10: " << Sinhit << endl;

    // Tính số người đã trên 50 tuổi tính đến năm 1985
    int a = 1985;
    int hon50 = 0;
    for (int i = 0; i < n; ++i) {
        if (a - Thongke[i].Nam > 50) {
            hon50 += Thongke[i].SoNguoiSinh;
        }
    }
    cout << "So nguoi da tren 50 tuoi den nam 1985: " << hon50 << endl;

    return 0;
}
