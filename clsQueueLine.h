//
// Created by Ayman yassien on 17/02/2024.
//
#include "iostream"
#include "queue"
#include "clsDate.h"

using namespace std;

class clsQueueLine
{
    string _prefex;
    short _timeToServeOneInMinute = 0;
    int _totalTickets = 0;
    int _serveClients = 0;
//    int _waitingClients = _totalTickets - _serveClients;

    class clsTicket
    {
        string _prefex;
        string _date;
        int _waitingClients;
        int _waitingTime;
    public:
        clsTicket(string prefex, int waitingClients, int waitingTime)
        {
            clsDate date1;
            _prefex = prefex;
            _date   = date1.getSystemDateAndTimeString();
            _waitingTime = waitingTime;
            _waitingClients = waitingClients;
        }

        void updateWaitingClientesAndTime()
        {

            _waitingTime -= _waitingTime / _waitingClients;
            --_waitingClients ;
        }

        void printTicket()
        {
            cout << "\n\t\t\t\t\t\t\t\t\t____________________________________\n";
            cout << "\t\t\t\t\t\t\t\t\t" << "               " << _prefex << "\n";
            cout << "\t\t\t\t\t\t\t\t\t" << "     " << _date  << "\n";
            cout << "\t\t\t\t\t\t\t\t\t" << "      Waiting Clients: " << _waitingClients << "\n";
            cout << "\t\t\t\t\t\t\t\t\t" << "      Serve Time in " << "\n";
            cout << "\t\t\t\t\t\t\t\t\t" << "       " << _waitingTime << " Minute(s) " << "\n";
            cout << "\t\t\t\t\t\t\t\t\t____________________________________\n";
        }
    };

    queue<clsTicket> queueLine;

    string createTicketPrefex()
    {
        return _prefex + to_string(queueLine.size() + 1);
    }

public:
    clsQueueLine(string prefex, int time)
    {
        _prefex = prefex;
        _timeToServeOneInMinute = time;
    }

    void serveNextClient()
    {
        queueLine.pop();
        ++_serveClients;

        int size = queueLine.size();

        queue<clsTicket> temp;
        for (int i = 0; i < size; ++i) {
            queueLine.front().updateWaitingClientesAndTime();
            temp.push(queueLine.front());
            queueLine.pop();
        }
        queueLine = temp;
    }

    void printTicketsLineRTL()
    {
        int size = queueLine.size();
        for (int i = 1; i <= size; ++i)
            cout << _prefex << i << " <-- ";
        cout << '\n';
    }

    void printTicketsLineLTR()
    {
        int size = queueLine.size();
        for (int i = size; i > 0; --i)
            cout << _prefex << i << " --> ";
        cout << '\n';
    }

    void issueTicket()
    {
        clsTicket ticket(createTicketPrefex(),
                         _totalTickets - _serveClients,
                         _timeToServeOneInMinute * queueLine.size());

        queueLine.push(ticket);
        ++_totalTickets;
    }

    void printInfo()
    {
        cout << "\n\t\t\t\t\t\t\t\t\t____________________________________\n";
        cout << "\t\t\t\t\t\t\t\t\t" << "            Queue Info" << "\n\n";
        cout << "\t\t\t\t\t\t\t\t\t" << "   Prefex         : " << _prefex << "\n";
        cout << "\t\t\t\t\t\t\t\t\t" << "   Total Tickets  : " << _totalTickets << "\n";
        cout << "\t\t\t\t\t\t\t\t\t" << "   Served Clients : " << _serveClients << "\n";
        cout << "\t\t\t\t\t\t\t\t\t" << "   Waiting Clients: " << _totalTickets - _serveClients << "\n";
        cout << "\t\t\t\t\t\t\t\t\t____________________________________\n\n";
    }

    void printAllTickets()
    {
        queue<clsTicket> temp = queueLine;
        int size = queueLine.size();
        for (int i = 0; i < size; ++i) {
            temp.front().printTicket();
            temp.pop();
        }
    }



};