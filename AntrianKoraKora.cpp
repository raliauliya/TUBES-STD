#include "AntrianKoraKora.h"

void createStack(stack &S)
{
    Top(S) = 0;
}

bool isEmptyS(stack S)
{
    if (Top(S) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull(stack S)
{
    if (Top(S) == 15)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push(stack &S, string nama, int ticketID)
{
    if (isFull(S) == false)
    {
        Top(S)++;
        infoS(S)[Top(S)].nama = nama;
        infoS(S)[Top(S)].ticketID = ticketID;
    }
}

void pop(stack &S)
{
    if (isEmptyS(S))
    {
        cout << "Tidak Ada Orang dalam Wahana Kora-Kora" << endl;
    }
    else
    {
        // nama = infoS(S)[Top(S)].nama;
        // ticketID = infoS(S)[Top(S)].ticketID;
        Top(S)--;
    }
}

void printInfoS(stack S)
{
    if (Top(S) != 0)
    {
        int j = Top(S);
        int maxID = 8;
        int maxName = 4;
        int lenID = 0;
        int lenName = 0;
        while (j > 0)
        {
            lenName = (infoS(S)[j].nama).length();
            if (maxName < lenName)
            {
                maxName = lenName;
            }

            lenID = (to_string(infoS(S)[j].ticketID)).length();
            if (maxID < lenID)
            {
                maxID = lenID;
            }

            j--;
        }

        for (int i = 0; i < maxName + maxID + 7; i++)
        {
            cout << "=";
        }

        cout << endl;

        j = Top(S);

        cout << "| ID Tiket ";

        for (int i = 0; i < maxID - 8; i++)
        {
            cout << " ";
        }

        cout << "| Nama ";

        for (int i = 0; i < maxName - 4; i++)
        {
            cout << " ";
        }

        cout << "|" << endl;

        for (int i = 0; i < maxName + maxID + 7; i++)
        {
            cout << "=";
        }

        cout << endl;

        while (j > 0)
        {
            cout << "| ";
            cout << infoS(S)[j].ticketID;

            for (int i = 0; i < maxID - (to_string(infoS(S)[j].ticketID)).length(); i++)
            {
                cout << " ";
            }
            cout << " | ";
            cout << infoS(S)[j].nama;

            for (int i = 0; i < maxName - (infoS(S)[j].nama).length(); i++)
            {
                cout << " ";
            }

            cout << " |" << endl;
            j--;
        }

        for (int i = 0; i < maxName + maxID + 7; i++)
        {
            cout << "=";
        }

        cout << endl;
    }
    else
    {
        cout << "========== TIDAK ADA ORANG DALAM WAHANA KORA-KORA ==========" << endl;
    }
}

// queue

void createQueue(queue &Q)
{
    head(Q) = NULL;
    tail(Q) = NULL;
}

bool isEmptyQ(queue &Q)
{
    if (head(Q) == NULL && tail(Q) == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createElementQ(KoraKora antrianBaru, adrQueue &P)
{
    P = new elmtQueue;
    infoQ(P) = antrianBaru;
    next(P) = NULL;
}

void enqueue(queue &Q, adrQueue P)
{
    if (isEmptyQ(Q))
    {
        head(Q) = P;
        tail(Q) = P;
    }
    else
    {
        next(tail(Q)) = P;
        tail(Q) = P;
    }
}

KoraKora dequeue(queue &Q, adrQueue P)
{
    KoraKora keluar;
    P = head(Q);

    keluar.nama = head(Q)->infoQ.nama;
    keluar.ticketID = head(Q)->infoQ.ticketID;

    if (isEmptyQ(Q))
    {
        cout << "========== TIDAK ADA ANTRIAN ==========";
    }
    else if (tail(Q) == head(Q))
    {
        tail(Q) == NULL;
        head(Q) == NULL;
    }
    else
    {
        head(Q) = next(head(Q));
        head(Q) = next(P);
        next(P) = NULL;
    }

    return keluar;
}

void printInfoQ(queue Q)
{
    adrQueue P;
    if (head(Q) != NULL)
    {
        P = head(Q);
        int maxID = 8;
        int maxName = 4;
        int lenID = 0;
        int lenName = 0;
        while (P != NULL)
        {
            lenName = (infoQ(P).nama).length();
            if (maxName < lenName)
            {
                maxName = lenName;
            }

            lenID = (to_string(infoQ(P).ticketID)).length();
            if (maxID < lenID)
            {
                maxID = lenID;
            }

            P = next(P);
        }

        for (int i = 0; i < maxName + maxID + 7; i++)
        {
            cout << "=";
        }

        cout << endl;

        P = head(Q);

        cout << "| ID Tiket ";
        for (int i = 0; i < maxID - 8; i++)
        {
            cout << " ";
        }

        cout << "| Nama ";

        for (int i = 0; i < maxName - 4; i++)
        {
            cout << " ";
        }

        cout << "|" << endl;

        for (int i = 0; i < maxName + maxID + 7; i++)
        {
            cout << "=";
        }

        cout << endl;

        while (P != NULL)
        {
            cout << "| ";
            cout << infoQ(P).ticketID;

            for (int i = 0; i < maxID - (to_string(infoQ(P).ticketID)).length(); i++)
            {
                cout << " ";
            }
            cout << " | ";
            cout << infoQ(P).nama;

            for (int i = 0; i < maxName - (infoQ(P).nama).length(); i++)
            {
                cout << " ";
            }

            cout << " |" << endl;
            P = next(P);
        }

        for (int i = 0; i < maxName + maxID + 7; i++)
        {
            cout << "=";
        }

        cout << endl;
    }
    else
    {
        cout << "========== TIDAK ADA ANTRIAN ==========" << endl;
    }
}
