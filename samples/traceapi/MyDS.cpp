////////////////////////////////////////////////////////////////// API Rank struct , NOTE: 186 is the number of monitored APIs, it needs adjustment if this number changes

// For capturing the PID
// #include <iostream>
#include <winsock2.h>

#pragma comment(lib, "Ws2_32.lib")
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <signal.h>
#include <comdef.h>

#include <errno.h>

const int APIS_Number = 203;
const int Regs_Number = 105;
const int monitored_name_max_langth = 100;

struct ApiRank {
    char name[monitored_name_max_langth];
    float rank;
    int called;
};

ApiRank ApisRankArr[APIS_Number];

ApiRank RegsRankArr [Regs_Number];

////////////////////////////////////////////////////////////// Global Variable Threshold

float gThreshold = 0;

unsigned long pid = 0;

bool fill_Arr(char *apiFile, char *rankFile ,ApiRank arr[]){
    FILE * fp = fopen(apiFile, "r");
    if (fp == NULL)
        return false;

    int i = 0;
    while(fgets(arr[i].name, monitored_name_max_langth, fp) != NULL) {
        arr[i].name[strlen(arr[i].name) -1] = '\0';
        arr[i].called = 0;
        i++;
    }
    fclose(fp);

    fp = fopen(rankFile, "r");
    
    if (fp == NULL)
        return false;
    
    i = 0;
    while(fscanf(fp, "%f\n", &arr[i].rank) == 1) {
        i++;
    }
    fclose(fp);
    
    return true;
}


void LoadedApi(char *ApiName){
    // Search if this function is inside the ApisRankArr array
   _PrintEnter("I'm Here\n");
   _PrintExit("Bye\n");
    for (int i=0; i < APIS_Number; i ++){
        if( strcmp(ApisRankArr[i].name, ApiName) == 0)
            {
                if (ApisRankArr[i].called == 0){
                    gThreshold += ApisRankArr[i].rank;
                     _PrintEnter("First: Threshold is %d, after %s\n", gThreshold, ApiName);
                    //  _PrintEnter("~~%c%c%c%c\n",ApiName[0],ApiName[1],ApiName[2],ApiName[3]);
                }
                
                _PrintEnter("Threshold is %d, after %s\n", gThreshold, ApiName);

                // _PrintEnter("~~%c%c%c%c\n",ApiName[0],ApiName[1],ApiName[2],ApiName[3]);

                ApisRankArr[i].called += 1;
                
                // /*
                if (gThreshold > 21){
                    //MessageBox(NULL, "EVASIVEEEE RUNN", "HI", MB_OKCANCEL);
                    
                    _PrintEnter("Evasive File trying to finger print the environment\nTerminating the Process Now\n");

                    // Reading Pid From File
                    if (pid == 0){
                        _PrintEnter("trying to open the file\n");
                        FILE *fptr = fopen("C:\\Users\\ali\\Desktop\\Detours5\\samples\\traceapi\\pid.txt","r");
                        if (fptr){
                            fscanf(fptr,"%lu", &pid);
                            _PrintEnter("PID FROM FILE IS %lu", pid);
                            fclose(fptr);
                        }else{
                            _PrintEnter("Couldnt open file due to %d\n", errno);
                        }
                    }
                    
                    _PrintEnter("PID IS not 0, it's %d\n",pid);
                    

                    // Kill the process
                   	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid & INT_MAX);
                        if (hProcess){
                            if (TerminateProcess(hProcess, 1))
                                _PrintEnter("Successfully killed the process !\n");
                            else
                                _PrintEnter("Couldnt kill the process\n");

                        }else{
                            _PrintEnter("The ID retrieved is %d, Falied to retrieve the handle\n", pid);
                        }
                }
                
                // */

                // printf("Hallo The pid is %lu\n", pid);
                // printf("------------The Threshold is %f\n", gThreshold);
                break;
            }
    }

}

void LoadedRegs(LPCSTR lpSubKey, LPCWSTR lpSubKeyW){
    // Check if this is an array of wide character (LPCWSTR) or just an array of char (LPCSTR)
    bool wide = lpSubKey==NULL?true:false;

    // this subKey will be used when comparing with the Monitored registry
    const char *subKey;

    if (!wide)
        subKey = lpSubKey;
    else{
        _bstr_t b(lpSubKeyW);
        subKey = b;
    }
    // _PrintEnter("The sub key is %s\n", subKey);

    // Search if this function is inside the RegsRankArr array
    for (int i=0; i < Regs_Number; i ++){
        if(strstr(subKey, RegsRankArr[i].name) == 0)
            {
                if (RegsRankArr[i].called == 0){
                    gThreshold += RegsRankArr[i].rank;
                   
                }
                _PrintEnter("Registry: Threshold is %f, after %s\n", gThreshold, subKey);
                
                RegsRankArr[i].called += 1;
            //    /*
                if (gThreshold > 21){
                    _PrintEnter("Registry: Evasive File trying to finger print the environment\nTerminating the Process Now\n");

                    // Reading Pid From File
                    if (pid == 0){
                        FILE *fptr = fopen("pid.txt","r");
                        if (fptr){
                            fscanf(fptr,"%lu", &pid);
                            // printf("%lu", pid);
                            fclose(fptr);
                        }
                    }

                    // Kill the process
                    	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid & INT_MAX);
                        if (hProcess){
                            if (TerminateProcess(hProcess, 1))
                                _PrintEnter("Successfully killed the process !\n");
                            else
                                _PrintEnter("Couldnt kill the process\n");

                        }else{
                            _PrintEnter("Falied to retrieve the handle\n");
                        }
                }
                // */

                break;
            }
    }

}