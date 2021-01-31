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
	std::string wifiname;
	std::cin >> wifiname; //Problems with space between words ->  std::getline(std::cin, wifiname);
	std::cout << "\n";
	std::string command = (std::string("netsh wlan show profile ").c_str());
	command.append(wifiname);
	command.append(" key=clear");
	system((std::string(command).c_str()));
	printf("\n\n");
	system("Pause");
};

void choose_programm_mode() {
	std::cout << "Which kind of scan do you want to perform? \n";
	std::cout << "[1] System Informations\n";
	std::cout << "[2] WiFi Profiles and Passwords\n";
	int chooseamode;
	std::cin >> chooseamode;
	switch (chooseamode) {
	case 1:
		std::cout << "Mode: System Informations\n";
		device_scan();
		break;
	case 2:
		std::cout << "Mode: WiFi Profiles and Passwords\n";
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