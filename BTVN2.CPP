
// So nua nguyen to la so co tich la 2 so nguyen to khong nhat thiet phai khac nhau
// So Blum thoa man la tich la 2 so nguyen to va 2 so co dang 4k+3 phan biet

// Giai thuat
// Bai toan 1 : tao ra mot mang so blum < N
// B1 : Tao mot mang so nguyen to nho hon N ( dung sang so nguyen to Eratosthenes)
// B2 : Loc nhung so co dang 4k+3
// B3 : Tinh n = tich tung cap so da loc ( loai nhung so giong)
// B4 : Sap xep lai mang
// Bai toan 2 : Tim cac cap trong mang so blum co tong cung la mot blum < N
// B1 : Duyet tung cap mot so voi N
// Bai toan 3 : Kiem tra mot so blum M co trong mang khong thi duyet .

#include<iostream>
#include<math.h>
using namespace std;
int N;
bool *nt;
int *a;

void SangSoNT(){
	nt = new bool[N+1];
	for(int i = 0 ; i <= N ; i++){
	        nt[i] = true;
        }
    nt[0] = nt[1] = false;
    for(int i = 2; i<= sqrt(N);i++){
    	if(nt[i] == true){
    		for(int j = i*i ; j <= N ; j+=i){ // Vi moi so nguyen to < i^2 da duoc sang boi so nho hon truoc do
    			nt[j] = false;
			}
		}
	}
}
void soBlum(){
	SangSoNT();
	a = new int[N];
	int k = 0;
	for(int i = 0;i < N;i++){
		if(nt[i] && (i-3)%4 == 0){
		   for(int j = i+1 ; j <= N ; j++ ){
		   	if(nt[j] && (j%4 == 3)){
		   		int blumNumber = i*j;
		   		if(blumNumber < N){
		   			a[k++] = blumNumber;
				   }
			   }

		   }
		}
	}
}
void Check(int M){
	bool check1 = false;
	for(int i = 0; i<N;i++){
		if(a[i] = M && a[i]!=0) {
			check1 = true;
			break;
		}

	}
	if(check1 = true ){
		cout<<M<<" thuoc";
	}
	else cout<<M<<" Khong thuoc";
}


int main(){
	cout<<"Nhap so N: ";
	cin >> N;
	int M;
	cout<<"Nhap so can check: ";
	cin>>M;
	soBlum();

	// Tim cac cap co tong la so blum va nho hon N
	for(int i = 0; i < N && a[i] != 0 ; i++ ){
for(int j = i+1; j<N && a[j] != 0;j++){
			if(a[i+j]!=0 && a[i+j] < N) cout<<"("<<a[i]<<","<<a[j]<<")"<<" ";
}
}
    cout<<"\n";
   // Kiem tra mot so blum M co nam trong M mang blum khong
    Check(M);
	delete[] nt;
	delete[] a;
	return 0;
}





