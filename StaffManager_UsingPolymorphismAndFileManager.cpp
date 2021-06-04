// StaffManager_UsingPolymorphismAndFileManager.cpp 

#include<iostream>
using namespace std;
#include<string>
#include<fstream>

// khai báo cấu trúc lớp ngày tháng năm sinh
class NamSinh
{
private:
    int ngay;
    int thang;
    int nam;
public:
    // Phương thức getter
    int Getter_Ngay()
    {
        return ngay;
    }
    // Phương thức setter
    void Setter_Ngay(int NGAY)
    {
        ngay = NGAY;
    }

    // Phương thức getter
    int Getter_Thang()
    {
        return thang;
    }
    // Phương thức setter
	void Setter_Thang(int THANG)
    {
        thang = THANG;
    }

    // Phương thức getter
    int Getter_Nam()
    {
        return nam;
    }
    // Phương thức setter
	void Setter_Nam(int NAM)
    {
        nam = NAM;
    }
};

// khai báo lớp cha : NhanVien
class NhanVien
{
protected:
    string MaNhanVien;
    string TenNhanVien;
    NamSinh namsinh;
    string DiaChi;
    float HeSoLuong;
    float LuongCoBan;

public:
    virtual void Doc_File(ifstream&);
	virtual void XuatThongTin();
};

// cài đăt phương thức đọc file của lớp cha
void NhanVien::Doc_File(ifstream& filein)
{
    getline(filein, MaNhanVien, ',');
    filein.seekg(1, 1); // dịch con trỏ chỉ vị của file tại vị trí hiện tại sang 1 byte
    getline(filein, TenNhanVien, ',');
    int ngay;
    filein >> ngay;
    namsinh.Setter_Ngay(ngay);
    filein.seekg(1, 1); // dịch con trỏ chỉ vị của file tại vị trí hiện tại sang 1 byte

    int thang;
    filein >> thang;
    namsinh.Setter_Ngay(thang);
    filein.seekg(1, 1); // dịch con trỏ chỉ vị của file tại vị trí hiện tại sang 1 byte

    int nam;
    filein >> nam;
    namsinh.Setter_Ngay(nam);

    filein.seekg(2, 1); // dịch con trỏ chỉ vị của file tại vị trí hiện tại sang 2 byte
    getline(filein, DiaChi, ',');

    filein >> HeSoLuong;
    filein.seekg(1, 1);

    filein >> LuongCoBan;
    filein.seekg(1, 1);

}

// xuất thông tin NhanVien
void NhanVien::XuatThongTin()
{
	cout << endl << "Ma Nhan Vien: " << MaNhanVien;
	cout << endl << "Ho ten Nhan Vien: " << TenNhanVien;
	cout << endl << "Ngay thang nam sinh" << namsinh.Getter_Ngay() << "/" << namsinh.Getter_Thang() << "/" << namsinh.Getter_Nam();
	cout << endl << "Dia chi nhan vien: " << DiaChi;
	cout << endl << "He so  luong: " << HeSoLuong;
}

// khai báo lớp con NhanVienLapTrinh kế thừa lại lớp cha : NhanVien
class NhanVienLapTrinh : public NhanVien
{
private:
    float TienLamNgoaiGio;
public:
    void Doc_File(ifstream&);
	void XuatThongTin();
};

// cài đăt phương thức đọc file của lớp con NhanVienLapTrinh
void NhanVienLapTrinh::Doc_File(ifstream& filein)
{
    NhanVien::Doc_File(filein);
    filein >> TienLamNgoaiGio;
}

// xuất thông tin nhân viên lập trình
void NhanVienLapTrinh::XuatThongTin()
{
	NhanVien::XuatThongTin();
	cout << endl << "Tien lam ngoai gio: " << TienLamNgoaiGio;
}

// khai báo lớp con NhanVienThietKe kế thừa lại lớp cha : NhanVien
class NhanVienThietKe : public NhanVien
{
private:
    float TienThuong;
public:
    void Doc_File(ifstream&);
	void XuatThongTin();
};


// cài đăt phương thức đọc file của lớp con NhanVienThietKe
void NhanVienThietKe::Doc_File(ifstream& filein)
{
    NhanVien::Doc_File(filein);
    filein >> TienThuong;
}

// xuất thông tin nhân viên thiết kế
void NhanVienThietKe::XuatThongTin()
{
	NhanVien::XuatThongTin();
	cout << endl << "Tien thuong: " << TienThuong;
}

// thiết kế menu xử lý
void Menu(NhanVien *ds[], int n)
{
	int luachon;
	while (true)
	{
		ifstream filein;
		filein.open("Staff.txt", ios_base::in);
		system("cls");
		cout << endl << "=============CHUONG TRINH QUAN LY=============";
		cout << endl << "1. Doc thong tin nhan vien";
		cout << endl << "2. Xuat danh sach Nhan Vien";
		/*cout << endl << "3. NHAP THONG TIN NHAN VIEN XE OM CONG NGHE";
		cout << endl << "4. XUAT DANH SACH THONG TIN NHAN VIEN SUA ONG NUOC";
		cout << endl << "5. XUAT DANH SACH THONG TIN NHAN VIEN GIAO HANG";
		cout << endl << "6. XUAT DANH SACH THONG TIN NHAN VIEN XE OM CONG NGHE";
		cout << endl << "7. TONG TIEN LUONG CUA 3 LOAI NHAN VIEN";
		cout << endl << "8. SAP XEP DANH SACH NHAN VIEN CAC LOAI GIAM DAN THEO LUONG";*/
		cout << endl << "0. KET THUC";
		cout << endl << "=====================ENDL=====================";
		cout << endl << "NHAP LUA CHON: ";
		cin >> luachon;
		if (luachon < 0 || luachon>8)
		{
			cout << "LUA CHON KHONG TON TAI, NHAP LAI: ";
		}
		else if (luachon == 1)
		{
			filein >> n;
			NhanVien* x;
			for (int i = 0; i < n; i++)
			{
				char c;
				filein >> c;
				filein.seekg(-1, 1);
				if (c=='P')
				{
					x = new NhanVienLapTrinh();
					x->Doc_File(filein);
				}
				else if (c=='D')
				{
					x = new NhanVienThietKe();
					x->Doc_File(filein);
				}
			}
		}
		else if (luachon == 2)
		{
			for (int i = 0; i < n; i++)
			{
				cout << endl << "Thong tin nhan vien thu " << i + 1 << endl;
				ds[i]->XuatThongTin();
				system("pause");
			}
		}
		//else if (luachon == 3)
		//{
		//	NhanVienXeOmCongNghe nv_xeomcn;
		//	cout << endl << "NHAP THONG TIN NHAN VIEN XE OM CONG NGHE";
		//	nv_xeomcn.Nhap();
		//	// thêm đối tượng giá trị vào danh sách
		//	ds_nv_xeomcn[l] = nv_xeomcn;
		//	l++;
		//}
		//else if (luachon == 4)
		//{
		//	cout << endl << "DANH SACH THONG TIN NHAN VIEN SUA ONG NUOC";
		//	for (int i = 0; i < n; i++)
		//	{
		//		cout << endl << "THONG TIN NHAN VIEN SUA ONG NUOC THU " << i + 1 << ": " << endl;
		//		ds_nv_suaongnuoc[i].Xuat();
		//	}
		//	cout << endl << "TONG TIEN LUONG: " << (size_t)TongTienLuongNVSON(ds_nv_suaongnuoc, n) << endl;
		//	system("pause");
		//}
		//else if (luachon == 5)
		//{
		//	cout << endl << "DANH SACH THONG TIN NHAN VIEN GIAO HANG";
		//	for (int i = 0; i < m; i++)
		//	{
		//		cout << endl << "THONG TIN NHAN VIEN GIAO HANG THU " << i + 1 << ": " << endl;
		//		ds_nv_giaohang[i].Xuat();
		//	}
		//	cout << endl << "TONG TIEN LUONG: " << (size_t)TongTienLuongNVGH(ds_nv_giaohang, m) << endl;
		//	system("pause");
		//}
		//else if (luachon == 6)
		//{
		//	cout << endl << "DANH SACH THONG TIN NHAN VIEN XE OM CONG NGHE";
		//	for (int i = 0; i < l; i++)
		//	{
		//		cout << endl << "THONG TIN NHAN VIEN XE OM CONG NGHE THU " << i + 1 << ": " << endl;
		//		ds_nv_xeomcn[i].Xuat();
		//	}
		//	cout << endl << "TONG TIEN LUONG: " << (size_t)TongTienLuongNVXOCN(ds_nv_xeomcn, l) << endl;
		//	system("pause");
		//}
		//else if (luachon == 7)
		//{
		//	double a = (size_t)(TongTienLuongNVGH(ds_nv_giaohang, m) + TongTienLuongNVSON(ds_nv_suaongnuoc, n) + TongTienLuongNVXOCN(ds_nv_xeomcn, l));
		//	cout << endl << "Tong tien cong ty can tra hang thang: " << (size_t)a;
		//	cout << endl;
		//	system("pause");
		//}
		//else if (luachon == 8)
		//{
		//	// Sủa ống nước
		//	cout << endl << "I.	DANH SACH THONG TIN NHAN VIEN SUA ONG NUOC GIAM DAN THEO LUONG" << endl;
		//	SAP_XEP_DANH_SACH_NV_SuaOngNuoc_GIAM_DAN_THEO_LUONG(ds_nv_suaongnuoc, n);
		//	for (int i = 0; i < n; i++)
		//	{
		//		cout << endl << "THONG TIN NHAN VIEN SUA ONG NUOC THU " << i + 1 << ": " << endl;
		//		ds_nv_suaongnuoc[i].Xuat();
		//	}
		//	cout << endl << "TONG TIEN LUONG: " << (size_t)TongTienLuongNVSON(ds_nv_suaongnuoc, n) << endl;
		//	// Giao Hàng
		//	cout << endl << "II.	DANH SACH THONG TIN NHAN VIEN GIAO HANG GIAM DAN THEO LUONG" << endl;
		//	SAP_XEP_DANH_SACH_NV_GiaoHang_GIAM_DAN_THEO_LUONG(ds_nv_giaohang, m);
		//	for (int i = 0; i < m; i++)
		//	{
		//		cout << endl << "THONG TIN NHAN VIEN GIAO HANG THU " << i + 1 << ": " << endl;
		//		ds_nv_giaohang[i].Xuat();
		//	}
		//	cout << endl << "TONG TIEN LUONG: " << (size_t)TongTienLuongNVGH(ds_nv_giaohang, m) << endl;
		//	// Xe ôm công nghệ
		//	cout << endl << "III.	DANH SACH THONG TIN NHAN VIEN XE OM CONG NGHE GIAM DAN THEO LUONG" << endl;
		//	SAP_XEP_DANH_SACH_NV_XeOmCN_GIAM_DAN_THEO_LUONG(ds_nv_xeomcn, l);
		//	for (int i = 0; i < l; i++)
		//	{
		//		cout << endl << "THONG TIN NHAN VIEN XE OM CONG NGHE THU " << i + 1 << ": " << endl;
		//		ds_nv_xeomcn[i].Xuat();
		//	}
		//	cout << endl << "TONG TIEN LUONG: " << (size_t)TongTienLuongNVXOCN(ds_nv_xeomcn, l) << endl;

		//	system("pause");

		//}
		else if (luachon == 0)
		{
			break;
		}
		filein.close();

	}
}


int main()
{
	NhanVien* ds[100]; //khai báo mảng 1 chiều lưu trữ 2 loại NV
	int n; //số nhân viên hiện có

	Menu(ds, n);

	system("pause");
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

