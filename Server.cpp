#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    int serv,conf;


    char n;
    cout<<"\n\n\tQuieres actualizar el sistema? s/n ";
    cin >> n;
    if(n == 's' ||n == 'S'){
    system("apt-get update && apt-get upgrade");
    }else{
    cout <<"\n\tSi se produce algun error es recomendable actualizar";
    }

    cout << "\n\t Que desea instalar?"<<endl;
    cout << "\n 1- Server-DHCP.";
    cout << "\n 2- FTP.";
    cout << "\n 3- SSH.";
    cout << "\n\n Deseo instalar: ";cin>>serv;

    switch(serv){

        //DHCP
        case 1:
        system("apt install isc-dhcp-server");
        break;

        //FTP
        case 2:
        system("apt -y install vsftpd");
        break;

        //SSH
        case 3:
        system("apt install openssh-server openssh-client openssh");
        break;
    }

    char s;
    cout<<"\n\n\tQuieres configurar alguna de las opciones anteriores? s/n ";
    cin >> s;
    if(s == 'n' || s == 'N'){
        return 0;
    }

    cout <<"\n\n1-Configurar DHCP";
    cout <<"\n2-Configurar FTP";
    cout <<"\n3-Configurar SSH";
    cout <<"\n\nQue desea configurar: ";cin>>conf;

    switch (conf){

        //CONFIGURACION DHCP
        case 1:
        system("nano /etc/default/isc-dhcp-server");
        break;
        //CONFIGURACION FTP
        case 2:
        /*Backup*/ system("cp /etc/vsftpd.conf /etc/vsftpd.conf.bak");
        system("ystemctl restart vsftpd");
        system("ystemctl status vsftpd");
        break;

        //CONFIGURACION SSH
        case 3:
        system("systemctl status ssh");
        cout<<"\n\nComo conectarse: \nEjemplo: El usuario debianpolskai ip 10.0.2.15 (ssh debianpolska@10.0.2.15)";
    }

    return 0;
}