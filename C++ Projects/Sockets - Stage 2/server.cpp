/*****************************************
* Toufic Hamadeh
* Programming Assignment (Server) - Part 2
* Due: April 9, 2014
******************************************/
#pragma once
#pragma comment(lib, "Ws2_32.lib")
#include <sdkddkver.h>
#include <conio.h>
#include <stdio.h>
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
    int costmat[2][4] =	{0, 0, 0, 0,
						 1, 0, 1, 9999};
    long SUCCESSFUL;
    WSAData WinSockData; 
    WORD DLLVersion;
    DLLVersion = MAKEWORD(2,1);
    SUCCESSFUL = WSAStartup(DLLVersion, &WinSockData); 

	string RESPONSE;
    char MESSAGE[300];

    SOCKADDR_IN ADDRESS; 
    int AddressSize = sizeof(ADDRESS);

    SOCKET sock_LISTEN;
    SOCKET sock_CONNECTION;

    sock_CONNECTION = socket(AF_INET, SOCK_STREAM, NULL); 
    ADDRESS.sin_addr.s_addr = inet_addr("192.168.1.30");
    ADDRESS.sin_family = AF_INET; 
    ADDRESS.sin_port = htons(8765);
 
    sock_LISTEN = socket(AF_INET, SOCK_STREAM, NULL);
    bind(sock_LISTEN, (SOCKADDR*)&ADDRESS, sizeof(ADDRESS)); 
    listen(sock_LISTEN, SOMAXCONN);

    while(true) {
        cout << "SERVER: Waiting for connection..." << endl;

        if (sock_CONNECTION = accept(sock_LISTEN, (SOCKADDR*)&ADDRESS, &AddressSize)) {
            cout << "Connection found..." << endl;
            SUCCESSFUL = send(sock_CONNECTION, "1 0 1 9999", 199, NULL);
            SUCCESSFUL = recv(sock_CONNECTION,MESSAGE,sizeof(MESSAGE),NULL);

            cout << "Message from client..." << endl;

            const char* str = MESSAGE;
            while(sscanf_s(str,"%d%n",&num[count], &poz) == 1) {
				count++;
				str += poz;
				if(count == 20) {
					break;
				}
			}

            for (int i = 0; i < 4; i++) {
                costmat[0][i]=num[i];
                cout << costmat[0][i]<<endl;
            }

			for(int i = 0; i < nodes; i++) {
				for(int j = 0; j < nodes; j++) {
					costmat[i][i]=0;
					rt[i].dist[j]=costmat[i][j];
					rt[i].from[j]=j;
				}
			}

		for(int i = 1; i < 2; i++) {
			cout << endl << "Table BEFORE update..." << endl;
			cout << "Server: ROUTER " << i << "." << endl;
			for(int j = 0; j < nodes; j++) {
				cout << "TO ROUTER " << j+1 << " FROM ROUTER " << rt[i].from[j]+1 << ": \tDISTANCE: " << rt[i].dist[j] << endl;
            }
		}
        
		do {
			count=0;
			for(int i = 0; i < nodes; i++) {
				for(int j = 0; j < nodes; j++) {
					for(int k = 0; k < nodes; k++) {
						if(rt[i].dist[j]>costmat[i][k]+rt[k].dist[j]) {
							rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
							rt[i].from[j]=k;
							count++;
						}
					}
				}
			}
		} while(count != 0);

		for(int i = 1; i < 2; i++) {    
            cout << endl << "Table AFTER update..." << endl;
			cout << "Server: ROUTER " << i << "." << endl;
            for(int j = 0; j < nodes; j++) {
				cout << "TO ROUTER " << j+1 << " FROM ROUTER " << rt[i].from[j]+1 << ": \tDISTANCE: " << rt[i].dist[j] << endl;
            }
        }
        std::cin.get();
        }
    }
}