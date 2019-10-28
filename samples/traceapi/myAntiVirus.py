import platform
import subprocess
from subprocess import DEVNULL, STDOUT, check_call
import os
import threading
import PySimpleGUI as sg
import hashlib


def hash256(abs_path):
    filename = abs_path
    with open(filename,"rb") as f:
        bytes = f.read() # read entire file as bytes
        readable_hash = hashlib.sha256(bytes).hexdigest();
        return readable_hash
    return -1

def check_among_benign(abs_path):
    #calculate hash
    hash = hash256(abs_path)
    if hash == -1:
        print("Error calculating the file's hash\n")
        return -1
    else:
        # check if it's in benign applications
        with open("signatures/bengin_apps_sigs.txt", "r") as f:
            for l in f:
                l = l.strip()
                if l == hash:
                    return 1
            return 0
        print("Failed to open signatures file")
        return -1 # failed to open


def check_among_evasive(abs_path):
    #calculate hash
    hash = hash256(abs_path)
    if hash == -1:
        print("Error calculating the file's hash\n")
        return -1
    else:
        # check if it's in benign applications
        with open("signatures/evasive_apps_sigs.txt", "r") as f:
            for l in f:
                l = l.strip()
                if l == hash:
                    return 1
            return 0
        print("Failed to open signatures file")
        return -1 # failed to open
    #check if hash 


def launch_detour(abs_path):
    DETOURS_BITS = ""
    BIND         = ""
    if platform.architecture()[0] == "64bit":
        DETOURS_BITS = "64"
        BIND         = "C:\\Users\\ali\\Desktop\\Detours5\\bin.X64"
    else:
        DETOURS_BITS = "32"
        BIND         = "C:\\Users\\ali\\Desktop\\Detours5\\bin.X86"

    # launch syelogd
    index = abs_path.rfind('/')
    filename = abs_path [index + 1:]

    os.system("@echo -------- Logging output to " + filename + ".txt")
    os.system("start " + BIND + "\\syelogd.exe /q /o " + filename + ".txt")
    os.system(BIND + "\\sleep5.exe")
    os.system(BIND + "\\withdll -d:" + BIND + "\\trcapi" + DETOURS_BITS + ".dll " + abs_path)

    # os.system("@echo -------- Logging output to " + filename + ".txt")
    # os.system("start ..\\..\\bin.X64\\syelogd.exe /q /o " + filename + ".txt")
    # os.system("..\\..\\bin.X64\\sleep5.exe 1")
    # os.system("..\\..\\bin.X64\\withdll -d:..\\..\\bin.X64\\trcapi64.dll " + abs_path)



def check_file(filename):
    try:
        f = open(filename + ".txt")
        t = open("temp.txt","w+")
        for l in f:
            t.write(l)
            if "Evasive" in l:
                f.close()
                t.close()
                return 1
        f.close()
        t.close()
        return 0
    except Exception as e:
        print(e)
        return -1


def launch_window():
    layout = [[sg.Text('Select a File to Scan')],
                [sg.Text('Source for File ', size=(15, 1)), sg.InputText(), sg.FileBrowse()],
                [sg.Submit(), sg.Cancel()]]

    window = sg.Window('Ransomware Scanner', layout)

    event, values = window.Read()

    abs_path = values[0] 
    window.Close()     # get the data from the values dictionary

    
    if abs_path:

        if check_among_benign(abs_path) == 1:
            sg.Popup('Safe Application', 'This application is safe and saved among the whitelisted applications')
            return
        elif check_among_evasive == 1:
            sg.Popup('WARNING', 'This program is EVASIVE and saved among the list of evasive programs')
            return
        else:
            threading.Thread(target=launch_detour(abs_path)).start()

            # layout the window
            layout = [[sg.Text('Please wait while we scan your file')],
                [sg.ProgressBar(10000, orientation='h', size=(20, 20), key='progressbar')],
                [sg.Cancel()]]

            # create the window
            window = sg.Window('Scanning the File', layout)
            progress_bar = window.FindElement('progressbar')

            # loop that would normally do something useful
            for i in range(100000):
                # check to see if the cancel button was clicked and exit loop if clicked
                event, values = window.Read(timeout=0)
                if event == 'Cancel'  or event is None:
                    break
                
                check = check_file(abs_path[abs_path.rfind('/') + 1:])
                if check == 1:
                    print("Evasive")
                    break
                elif check == 0:
                    print("Benign")
                    break
                else:
                    print("Pending")
                    
                # update bar with loop value +1 so that bar eventually reaches the maximum
                progress_bar.UpdateBar(i + 1)
            # done with loop... need to destroy the window as it's still open
            window.Close()
    else:
        pass



launch_window()