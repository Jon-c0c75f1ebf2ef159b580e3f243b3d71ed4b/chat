#pragma once
#include <iostream>

#if defined(__linux__)
#include <sys/utsname.h> // Linux Для uname()
#elif defined(_WIN32) || defined(_WIN64)
#include //системная библиотека Windows
#endif

#define cout std::cout
#define endl std::endl

void info_system() {
    
    #if defined(__linux__)
        //для линукса
        //system("uname -a");
        struct utsname uts_name;
        // uname() - утилита выдает название ядра и информацию о нем
        uname(&uts_name);
        
        // распечатаем на экране информацию об операционной системе
        cout << "OS name: "         << uts_name.sysname << endl;
        cout << "Host name: "       << uts_name.nodename << endl;
        cout << "OS release: "      << uts_name.release << endl;
        cout << "OS version: "      << uts_name.version << endl;
        cout << "Machine name: "    << uts_name.machine << endl;
        
    #elif defined(_WIN32) || defined(_WIN64)
        //для Windows
        cout << "OS Windows" << endl;
    #else
        cout << "System information is not available\n" << endl;
    #endif
}
