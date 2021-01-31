// Libraries 
#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <stdio.h>

void device_scan() {
	std::cout << "Searching for general Device informations \n";
	system("ipconfig/all");
	printf("\n\n");
	system("Pause");
};

void wifi_scan() {
	std::cout << "Searching for WiFi Profiles and Passwords\n";
	std::cout << "\n";
	system("netsh wlan show profile");
	std::cout << "Which WiFi-Profile do you want to observe? \n";
	cin.ignore();
	std::string wifiname;
	std::getline(std::cin, wifiname);
	std::cout << wifiname;
	std::cout << "\n";
	std::string wificredentials = "\"";
	wificredentials.append(wifiname);
	wificredentials.append("\"");
	std::string command = (std::string("netsh wlan show profile name=").c_str());
	command.append(wificredentials);
	command.append(" key=clear");
	system((std::string(command).c_str()));
	printf("\n\n");
	system("Pause");
};

void choose_programm_mode() {
	std::cout << "What type of scan do you want to perform? \n";
	std::cout << "[1] System Information Scan\n";
	std::cout << "[2] WiFi Profile and Password Scan\n";
	int chooseamode;
	std::cin >> chooseamode;
	switch (chooseamode) {
	case 1:
		std::cout << "Mode: System Information Scan\n";
		device_scan();
		break;
	case 2:
		std::cout << "Mode: WiFi Profile and Password Scan\n";
		wifi_scan();
		break;
	default:
		std::cout << "Invalid input.\n";
		choose_programm_mode();
		break;
	}
};

// Main-Function
int main()
{
	std::string startascan;
	std::cout << "System-Identify\n";
	std::cout << "Press 'Y' to start a system scan. \n";
	std::cin >> startascan;
	if (startascan == "Y" || startascan == "y") {
		choose_programm_mode();
	}
	else {
		std::cout << "Bye. \n";
	}
}