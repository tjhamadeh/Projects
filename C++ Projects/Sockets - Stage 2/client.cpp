/*****************************************
* Toufic Hamadeh
* Programming Assignment (Client) - Part 2
* Due: April 9, 2014
******************************************/
#pragma once 
#pragma comment(lib,"Ws2_32.lib") 
#include <sdkddkver.h> 
#include <WinSock2.h> 
#include <Windows.h> 
#include <iostream> 
#include <string> 
#define SCK_VERSION2 0x0202
using namespace std; 

struct node {
unsigned dist[20];
unsigned from[20];
}rt[10];

int main() {
	int nodes = 4;
	int count = 0;
	int num[20];
	int poz;
	int costmat[2][4]={0, 1, 3, 7,
                       0, 0, 0, 0};
	long SUCCESSFUL;
	WSAData WinSockData; 
    WORD DLLVersion; 
    DLLVersion = MAKEWORD(2,1);
    SUCCESSFUL = WSAStartup(DLLVersion, &WinSockData); 

    string RESPONSE;
	string IP = "192.168.1.30";
	string PORT = "8765";    
	char MESSAGE[300]; 

    SOCKADDR_IN ADDRESS; 

    SOCKET sock; 
    sock = socket(AF_INET,SOCK_STREAM,NULL); 
    ADDRESS.sin_addr.s_addr = inet_addr("192.168.1.30");
    ADDRESS.sin_family = AF_INET; 
    ADDRESS.sin_port = htons(8765);

    cout << "CLIENT: Connect to server? (Y/N)"; 
    cin >> RESPONSE; 

    RESPONSE[0] = tolower(RESPONSE[0]); 

    if(RESPONSE == "n")  {
        cout << "Exiting program..." << endl; 
    }
    else if (RESPONSE == "y") {
        connect(sock, (SOCKADDR*)&ADDRESS, sizeof(ADDRESS)); 
        SUCCESSFUL = recv(sock,MESSAGE,sizeof(MESSAGE),NULL); 
        SUCCESSFUL = send(sock,"0 1 3 7", 199, NULL);

        cout << "Message from server..." << endl;

        const char* str = MESSAGE;
        while (sscanf_s(str,"%d%n",&num[count], &poz) == 1) {
			count++;
			str += poz;
			if (count == 20) {
				break;
			}
        }

        for (int i = 0; i < 4; i++) {
			costmat[1][i]=num[i];
			cout << costmat[1][i]<<endl;
        }
    }
    else {
        cout << "Invalid input..." << endl; 
    }

    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            costmat[i][i]=0;
            rt[i].dist[j]=costmat[i][j];
            rt[i].from[j]=j;
        }
    }

    for (int i = 0; i < 1; i++) {
        cout << endl << "Table BEFORE update..." << endl;
		cout << "Client: ROUTER " << i << "." << endl;
		for (int j = 0; j < nodes; j++) {
			cout << "TO ROUTER " << j+1 << " FROM ROUTER " << rt[i].from[j]+1 << ": \tDISTANCE: " << rt[i].dist[j] << endl;
		}
	}
    do {
		count = 0;
		for (int i = 0; i < nodes; i++) {
			for (int j = 0; j < nodes; j++) {
				for (int k = 0; k < nodes; k++) {
					if (rt[i].dist[j]>costmat[i][k] + rt[k].dist[j]) {
						rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
						rt[i].from[j] = k;
						count++;
					}
				}
			}
		}
	} while (count != 0);

	for (int i = 0; i < 1; i++) {    
		cout << endl << "Table AFTER update..." << endl;
		cout << "Client: ROUTER " << i << "." << endl;
		for (int j = 0; j < nodes; j++) {
			cout << "TO ROUTER " << j+1 << " FROM ROUTER " << rt[i].from[j]+1 << ": \tDISTANCE: " << rt[i].dist[j] << endl;
		}
	}
	cin.get();

    system ("PAUSE");
    exit(1);
}