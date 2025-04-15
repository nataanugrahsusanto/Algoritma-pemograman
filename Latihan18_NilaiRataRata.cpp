#include<iostream>
#include<iomanip>

using namespace std;

int main () 
{
	int nilai[10], total=0;
	float ratarata;
	
	//input nilai
	for (int i = 0; i <10; i++) {
		cout<<"masukan nilai ke-"<< i + 1 << ": ";
		cin>>nilai[i];
		total+= nilai[i]; //menghitung total
	}
	
	//menghitung rata-rata
	ratarata= total / 10,0;
	
	//menampilkan hasil
	cout << "total nilai: " << total << endl;
	cout << "rata-rata nilai: " << ratarata << endl;
	
	return 0;
}
