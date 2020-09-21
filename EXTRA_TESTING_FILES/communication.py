# https://maker.pro/arduino/tutorial/how-to-create-simple-serial-communications-between-an-arduino-and-the-python-ide
# on mac, use ls /dev/tty.* to find something like /dev/tty.usbmodem141101 (for COM port)
import serial
import random
import sys
import signal
import tkinter as tk
from time import sleep


# GUI to turn on/off/exit the project


class Switch:
    def __init__(self, window):
        # self.COM = input("Enter the COM Port\n")
        # self.BAUD = input("Enter the Baudrate\n")
        # self.COM = "/dev/tty.usbmodem141101"
        # self.BAUD = "9600"
        # self.SerialPort = serial.Serial(self.COM, self.BAUD, timeout=1)

        # self.new_window = tk.Toplevel(window)
        self.new_window = window
        self.message = tk.Label(
            self.new_window, text="Ready whenever you are!", fg="blue")
        self.onButton = tk.Button(
            self.new_window, text="ON", command=self.TurnOn)
        self.offButton = tk.Button(
            self.new_window, text="OFF", command=self.TurnOff)
        self.exitButton = tk.Button(
            self.new_window, text="EXIT", command=self.Exit)
        self.closeButton = tk.Button(
            self.new_window, text="close", command=self.Close)
        self.farButton = tk.Button(
            self.new_window, text="far", command=self.Far)
        self.packComponents()
        # self.run()
        self.command = 'w'  # waiting

    def TurnOn(self):
        self.message.config(text='VROOM! The car is running!', fg="green")
        self.command = 'r'  # running, no Serial.available

    def TurnOff(self):
        self.message.config(text='HOLUP! The car has stopped!', fg="red")
        self.command = 'w'  # stopped (waiting)

    def Close(self):
        self.message.config(text='too close!', fg="purple")
        self.command = 'c'

    def Far(self):
        self.message.config(text='too far!!', fg="orange")
        self.command = 'f'

    def packComponents(self):
        self.message.pack()
        self.onButton.pack()
        self.offButton.pack()
        self.exitButton.pack()
        self.closeButton.pack()
        self.farButton.pack()

    def Exit(self):
        self.command = 'e'  # exited

    def loop(self):
        self.window.mainloop()


def signal_handler(self, signal, frame):
    print("closing program")
    SerialPort.close()
    sys.exit(0)


def loop():
    try:
        #OutgoingData = switch.command
        OutgoingData = 'e'
        print(OutgoingData)
        SerialPort.write(bytes(OutgoingData, 'utf-8'))
    except KeyboardInterrupt:
        print("Closing and exiting the program")
        SerialPort.close()
        sys.exit(0)
    IncomingData = SerialPort.readline()
    print(IncomingData.decode('utf-8').strip())
    if IncomingData:
        print((IncomingData).decode('utf-8'))
    sleep(1)
    window.after(100, loop)


'''
COM = "/dev/tty.usbmodem141101"
BAUD = 9600
SerialPort = serial.Serial(COM, BAUD, timeout=1)
window = tk.Tk()
window.geometry("200x150")
switch = Switch(window)
window.after(100, loop)
window.mainloop()
'''
COM = "/dev/tty.usbmodem141101"
BAUD = 9600
SerialPort = serial.Serial(COM, BAUD, timeout=1)
try:
    #OutgoingData = switch.command
    OutgoingData = 'e'
    print(OutgoingData)
    SerialPort.write(bytes(OutgoingData, 'utf-8'))
except KeyboardInterrupt:
    print("Closing and exiting the program")
    SerialPort.close()
    sys.exit(0)
IncomingData = SerialPort.readline()
print(IncomingData.decode('utf-8').strip())
if IncomingData:
    print((IncomingData).decode('utf-8'))
sleep(1)

'''
import serial
import time
import sys
import signal


def signal_handler(signal, frame):
    print("closing program")
    SerialPort.close()
    sys.exit(0)


COM = "/dev/tty.usbmodem141101"
BAUD = "9600"
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
'''
