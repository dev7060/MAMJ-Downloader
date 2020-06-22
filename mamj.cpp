//coded by github.com/dev7060
//MAMJ Downloader
#include <iostream>
#include <urlmon.h>
#include <string>
#include <fstream>
using namespace std;
void downloadURL(string URL);
void fileURL(string FILENAME);
string msg;
class DownloadIndicator : public IBindStatusCallback {
	double expression;
	string filename;
	public:
		/*
		DownloadIndicator(string filename) {
			this->filename = filename;
		}
		*/
	virtual HRESULT __stdcall OnProgress(ULONG ulProgress, ULONG ulProgressMax, ULONG ulStatusCode, LPCWSTR szStatusText)
	{
		//perentage = 
		if (ulProgressMax != 0) {
			//	if ((percentage == (temp + 10))||temp==0) {
					//cout.precision(2);
					//cout << double((double)ulProgress/(double)ulProgressMax)*100 << "\n";
			//	}
			int flag[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
			expression = double((double)ulProgress/(double)ulProgressMax)*100;
			//cout.precision();
			cout <<msg <<" "<< expression<<"%"<<"\n";
			/*
			if (int(expression) == 10 && flag[0]) {
				cout << "|";
				flag[0] = 0;
			}
			else if (int(expression) == 20 && flag[1]) {
				cout << "|";
				flag[1] = 0;
			}
			else if (int(expression) == 30 && flag[2]) {
				cout << "|";
				flag[2] = 0;
			}
			else if (int(expression) == 40 && flag[3]) {
				cout << "|";
				flag[3] = 0;
			}
			else if (int(expression) == 50 && flag[4]) {
				cout << "|";
				flag[4] = 0;
			}
			else if (int(expression) == 60 && flag[5]) {
				cout << "|";
				flag[5] = 0;
			}
			else if (int(expression) == 70 && flag[6]) {
				cout << "|";
				flag[6] = 0;
			}
			else if (int(expression) == 80 && flag[7]) {
				cout << "|";
				flag[7] = 0;
			}
			else if (int(expression) == 90 && flag[8]) {
				cout << "|";
				flag[8] = 0;
			}
			else if (int(expression) == 100 && flag[9]) {
				cout << "|";
				flag[9] = 0;
			}
			*/
			//cout << double((double)ulProgress / (double)ulProgressMax) * 100<<" ";
		}
		//temp = ulProgress;
		return S_OK;
	}
	HRESULT __stdcall QueryInterface(const IID &, void **) {
		return E_NOINTERFACE;
	}
	ULONG STDMETHODCALLTYPE AddRef(void) {
		return 1;
	}
	ULONG STDMETHODCALLTYPE Release(void) {
		return 1;
	}
	HRESULT STDMETHODCALLTYPE OnStartBinding(DWORD dwReserved, IBinding *pib) {
		return E_NOTIMPL;
	}
	virtual HRESULT STDMETHODCALLTYPE GetPriority(LONG *pnPriority) {
		return E_NOTIMPL;
	}
	virtual HRESULT STDMETHODCALLTYPE OnLowResource(DWORD reserved) {
		return S_OK;
	}
	virtual HRESULT STDMETHODCALLTYPE OnStopBinding(HRESULT hresult, LPCWSTR szError) {
		return E_NOTIMPL;
	}
	virtual HRESULT STDMETHODCALLTYPE GetBindInfo(DWORD *grfBINDF, BINDINFO *pbindinfo) {
		return E_NOTIMPL;
	}
	virtual HRESULT STDMETHODCALLTYPE OnDataAvailable(DWORD grfBSCF, DWORD dwSize, FORMATETC *pformatetc, STGMEDIUM *pstgmed) {
		return E_NOTIMPL;
	}
	virtual HRESULT STDMETHODCALLTYPE OnObjectAvailable(REFIID riid, IUnknown *punk) {
		return E_NOTIMPL;
	}
};
int main(int argc, char *argv[]) {
	system("title MAMJ Downloader by github.com/dev7060");
	system("color 0a");
	system("cls");
	//using loop: download done 1 ok.
	//argc = 2;
	int flag = 0;
	for (int j = 1; j <= (argc - 1);) {
		//cout << "enter here\n";
		string temp(argv[j]); //for - args
		//cout << temp;
		if (flag == 0) {
			j++;
		}
		if (temp == "-u") {
			if (flag == 1) {
				j++;
			}
			string temp2(argv[j]);
			//cout << temp2 << " "<<argv[j] << "\n"<<j <<" "<<argc;
			while (temp2 != "-f" && j <= (argc - 1)){
				//cout << "\nenter while";
				//cout << "url " << temp2 << "\n";
				downloadURL(temp2);
				j++;
				if (!(j > (argc - 1))) {
					string temp3(argv[j]);
					temp2 = temp3;
				}

			}
			flag = 1;
		}
		if (temp =="-f"){
			if (flag == 1) {
				j++;
			}
			string temp2(argv[j]);
			//cout << temp2 << " "<<argv[j] << "\n"<<j <<" "<<argc;
			while (temp2 != "-u" && j <= (argc - 1)) {
				fileURL(temp2);
				//cout << "file " << temp2 << "\n";
				j++;
				if (!(j > (argc - 1))) {
					string temp3(argv[j]);
					temp2 = temp3;
				}
			}
			flag = 1;
		}
	}
	cout << "_________________________________________________";
	cout << "\n";
	system("pause");
	return 0;
}
void downloadURL(string URL) {
	cout << "\n_________________________________________________\n";
	//argv[1] = "http://212.183.159.230/100MB.zip";
	cout << "\nURL: " << URL << "\n";
	string fileName = URL;
	int loc = fileName.find_last_of('/');
	fileName = fileName.substr(loc + 1, (fileName.length() - loc));
	//cout << fileName;
	//int flag = true;
	int i = 0;
	string fileNameBackup = fileName;
	while (true) {
		ifstream fileCheck(fileName);
		if (fileCheck.good() == true) {
			cout << "File: " << fileName << " already exists.";
			cout << "\nRenaming ...\n";
			int temp_loc = fileNameBackup.find_last_of('.');
			string temp = fileNameBackup.substr(0, (fileName.length() - (fileName.length() - temp_loc)));
			fileName = temp + "[" + to_string(i) + "]";
			fileName = fileName + fileNameBackup.substr(temp_loc, fileNameBackup.length() - temp_loc);
			i++;
			fileCheck.close();
		}
		else {
			//cout << "File" << fileName << "doesn't exist. continue...\n";
			fileCheck.close();
			break;
		}
		cout << "\n";
	}
	//cout << "\n";
	cout << "File: " << fileName << endl;
	msg = fileName;
	cout << "\nDownloading ...\n\n";
	HRESULT status = URLDownloadToFile(NULL, URL.c_str(), fileName.c_str(), 0, new DownloadIndicator);
	if (status == S_OK) {
		cout << "Download OK" << "\n";
	}else if (status == E_OUTOFMEMORY) {
		cout << "The buffer length is invalid, or there is insufficient memory to complete the operation" << "\n";
	}else if (status == INET_E_DOWNLOAD_FAILURE) {
		cout << "The specified resource or callback interface was invalid." << "\n";
	}else {
		cout << "Other error: " << status;
	}
}
void fileURL(string FILENAME) {
	ifstream ifile(FILENAME);
	char URL[500];
	#define SIZE 500
	while (ifile.eof() == 0) {
		ifile.getline(URL, SIZE);
		//cout << "url from file " << URL;
		downloadURL(URL);
	}
}
