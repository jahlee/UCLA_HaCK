'''
# https://maker.pro/arduino/tutorial/how-to-create-simple-serial-communications-between-an-arduino-and-the-python-ide
import tkinter as tk
# import Tkinter
# from Tkinter import *
import serial
from time import sleep

# Enter your COM port in the below line

# ard = serial.Serial(‘/dev/tty.usbmodem14201’, 9600)
ard = serial.Serial('com8', 9600)
sleep(2)
print(ard.readline(ard.inWaiting()))

top = tk.Tk()


def TrunOn():
    ard.write('1')
    sleep(0.1)
    data = ard.readline(ard.inWaiting())
    label1.config(text=str(data))


def Turnoff():
    ard.write('0')
    sleep(0.1)
    data = ard.readline(ard.inWaiting())
    label1.config(text=str(data))


OnButton = tk.Button(top, text="LED ON", command=TrunOn)
OffButton = tk.Button(top, text="LED OFF", command=Turnoff)
label1 = Label(top, fg="green")

label1.pack()
OnButton.pack()
OffButton.pack()
top.mainloop()
'''
# on mac, use ls /dev/tty.* to find something like /dev/tty.usbmodem141101 (for COM port)
import serial
import time
import sys
import signal


def signal_handler(signal, frame):
    print("closing program")
    SerialPort.close()
    sys.exit(0)


COM = input("Enter the COM Port\n")
BAUD = input("Enter the Baudrate\n")
SerialPort = serial.Serial(COM, BAUD, timeout=1)

while (1):
    try:
        OutgoingData = input('> ')
        SerialPort.write(bytes(OutgoingData, 'utf-8'))
    except KeyboardInterrupt:
        print("Closing and exiting the program")
        SerialPort.close()
        sys.exit(0)
    IncomingData = SerialPort.readline()
    if(IncomingData):
        print((IncomingData).decode('utf-8'))
    time.sleep(0.01)
