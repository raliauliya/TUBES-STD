#include "AntrianKoraKora.h"

int main()
{
    KoraKora data;
    queue Q;
    createQueue(Q);
    int x;
    int i = 1;
    adrQueue P;
    int ID = 1302210000 ;

    cout << "Selamat Datang di Wahana Kora Kora! Tiket Untuk Berapa Orang ? ";
    cin >> x;
    cout << endl;
    cout << "Silahkan Mengantri :)" << endl;
    cout << endl;
    while (i <= x)
    {
        cout << "Nama : ";
        cin >> data.nama;
        cout << "ID Tiket : ";
        ID = ID + i ;
        data.ticketID = ID ;
        cout << ID << endl ;
        cout << endl;
        createElementQ(data, P);
        enqueue(Q, P);
        i++;
        ID = 1302210000 ;
    }

    cout << " DATA ANTRIAN SEMENTARA " << endl; // tabel
    printInfoQ(Q);
    cout << endl;

    cout << "Silahkan 5 orang masuk ke dalam Kora Kora" << endl;

    stack S;
    createStack(S);

    for (i = 0; i < 5; i++)
    {
        data = dequeue(Q, P);
        push(S, data.nama, data.ticketID);
    }

    cout << endl;

    cout << " DATA ANTRIAN TERBARU " << endl; // tabel
    printInfoQ(Q);
    cout << endl;

    cout << " MENGISI KURSI KORA KORA " << endl; // tabel
    printInfoS(S);
    cout << endl;

    for (i = 0; i < 5; i++)
    {
        data = dequeue(Q, P);
        pop(S);
    }

    cout << " ========== MENGOSONGKAN KURSI KORA KORA ==========" << endl;
    printInfoS(S);
    cout << endl;
}
