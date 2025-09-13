#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// fungsi rata-rata
double rataRata(const vector<int>& arrData) {
    int total = 0;
    
    for (int i = 0; i < arrData.size(); i++)
    {
        total += arrData[i];
    }
    
    return (double) total / arrData.size();
}

// fungsi median
double median(vector<int>& arrData) {
    sort(arrData.begin(), arrData.end()); // sorting

    int n = arrData.size();
    if (n % 2 == 1)
    {
        /* jika ganjil, ambil elemen tengah */
        return arrData[n/2];
    }
    else
    {
        /* jika genap, jumlahkan 2 elemen tengah dan bagi 2*/
        return (arrData[n/2 - 1] + arrData[n/2]) / 2.0;
    }
    
}

// fungsi modus
vector<int> modus(vector<int>& arrData) {
    unordered_map<int, int> frequencyMap; // deklarasi unordered_map untuk menghitung frekuensi

    for(int val : arrData) {
        frequencyMap[val]++; // key = nilai, value = frekuensi
    }

    int maxFreq = 0;
    for(auto& p : frequencyMap) {
        if (p.second > maxFreq)
        {
            maxFreq = p.second;
        }
        
    }

    vector<int> hasil;
    if (maxFreq == 1)
    {
        return {};
    }

    for(auto& p : frequencyMap) {
        if (p.second == maxFreq)
        {
            hasil.push_back(p.first);
        }
    }

    return hasil;
}

// fungsi kuartil
// fungsi untuk menghitung median
double calculateMedian(const std::vector<int>& arr) {
    size_t size = arr.size();
    if (size == 0) {
        return 0.0; // Mengembalikan 0 untuk array kosong
    }
    if (size % 2 == 1) {
        return static_cast<double>(arr[size / 2]);
    } else {
        return static_cast<double>(arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    }
}

// fungsi kuartil
std::vector<double> kuartil(std::vector<int> arrData) {
    std::sort(arrData.begin(), arrData.end());
    size_t n = arrData.size();

    if (n == 0) {
        return {0.0, 0.0, 0.0};
    }

    double Q2 = calculateMedian(arrData);

    std::vector<int> lowerHalf;
    std::vector<int> upperHalf;

    if (n % 2 == 0) {
        lowerHalf.assign(arrData.begin(), arrData.begin() + n / 2);
        upperHalf.assign(arrData.begin() + n / 2, arrData.end());
    } else {
        lowerHalf.assign(arrData.begin(), arrData.begin() + n / 2);
        upperHalf.assign(arrData.begin() + n / 2 + 1, arrData.end());
    }

    double Q1 = calculateMedian(lowerHalf);
    double Q3 = calculateMedian(upperHalf);

    return {Q1, Q2, Q3};
}

// fungsi utama
int main() {
    int jumlahData;
    cout << "masukkan berapa banyak data yang ingin anda masukkan : " << endl;
    cin >> jumlahData;

    vector<int> arrData(jumlahData);
    
    for (int i = 0; i < jumlahData; i++)
    {
        cout << "masukkan data ke-" << (i+1) << " : ";
        cin >> arrData[i];
    }

    cout << "\nData yang anda masukkan : ";
    for (int i = 0; i < jumlahData; i++)
    {
        cout << arrData[i] << " ";
    }
    
    // opsi
    int opsi;

    cout << "\nmau diapakan data-data tersebut?" << endl;
    cout << "1. cari rata-rata" << endl;
    cout << "2. cari median" << endl;
    cout << "3. cari modus" << endl;
    cout << "4. cari kuartil" << endl;
    cin >> opsi;


    // case sesuai fungsi
    if (opsi == 1)
    {
        cout << "ayo cari nilai 'rata-rata'nya" << endl;
        cout << "Rata-rata = " << rataRata(arrData);
    }
    else if (opsi == 2)
    {
        cout << "ayo cari nilai 'median'nya" << endl;
        cout << "Median = " << median(arrData);
    }
    else if (opsi == 3)
    {
        cout << "ayo cari nilai 'modus'nya" << endl;
        vector<int> hasil = modus(arrData);

        if (hasil.empty())
        {
            cout << "Semua data unik!" << endl;
        }
        else
        {
            cout << "Modus = ";
            for(int m : hasil) {
                cout << m << " ";
            }
            cout << endl;
        }
    }
    else if (opsi == 4)
    {
        cout << "ayo cari nilai 'kuartil'nya" << endl;
        vector<double> k = kuartil(arrData);
        cout << "Q1 = " << k[0] << endl;
        cout << "Q2 = " << k[1] << endl;
        cout << "Q3 = " << k[2] << endl;
    }
    else
    {
        cout << "yahh, pilihan kamu tidak ada di opsi kami :(" << endl;
    }
    
}