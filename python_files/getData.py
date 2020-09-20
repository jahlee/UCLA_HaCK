# https://maker.pro/arduino/tutorial/how-to-create-simple-serial-communications-between-an-arduino-and-the-python-ide
# on mac, use ls /dev/tty.* to find something like /dev/tty.usbmodem141101 (for COM port)
import serial
# import time
import sys
import signal
import tkinter as tk
from time import sleep


# GUI to turn on/off/exit the project
class Switch:
    def __init__(self, window):
        self.COM = input("Enter the COM Port\n")
        self.BAUD = input("Enter the Baudrate\n")
        self.SerialPort = serial.Serial(self.COM, self.BAUD, timeout=1)
        self.window = window
        self.message = tk.Label(
            self.window, text="Ready whenever you are!", fg="blue")
        self.onButton = tk.Button(self.window, text="ON", command=self.TurnOn)
        self.offButton = tk.Button(
            self.window, text="OFF", command=self.TurnOff)
        self.exitButton = tk.Button(
            self.window, text="EXIT", command=self.Exit)
        self.pack()
        # self.run()
        self.running = ''  # waiting

    def TurnOn(self):
        self.message.config(text='VROOM! The car is running!', fg="green")
        self.running = ''  # running, no Serial.available

    def TurnOff(self):
        self.message.config(text='HOLUP! The car has stopped!', fg="red")
        self.running = 'w'  # stopped (waiting)

    def pack(self):
        self.message.pack()
        self.onButton.pack()
        self.offButton.pack()
        self.exitButton.pack()

    def run(self):
        self.window.after(1000, self.pack)
        # return
        # self.window.mainloop()

    def Exit(self):
        self.running = 'e'  # exited
        exit(0)

    def loop(self):
        self.window.mainloop()

    def signal_handler(self, signal, frame):
        print("closing program")
        SerialPort.close()
        sys.exit(0)


# not sure if we need this lol


def start(switch):
    # COM = input("Enter the COM Port\n")
    # BAUD = input("Enter the Baudrate\n")
    # SerialPort = serial.Serial(switch.COM, switch.BAUD, timeout=1)
    values = {}
    while len(values) < 3:
        try:
            OutgoingData = switch.running
            switch.SerialPort.write(bytes(OutgoingData, 'utf-8'))
        except KeyboardInterrupt:
            print("Closing and exiting the program")
            switch.SerialPort.close()
            sys.exit(0)

        IncomingData = switch.SerialPort.readline()
        if (IncomingData):
            # print((IncomingData).decode('utf-8'))   # print data
            # gets value without extra whitespace
            value = IncomingData.decode('utf-8').strip().split(":")

            if (value[0] == "EXIT"):
                return None
            elif (value[0] == "WAIT"):  # wait 2 seconds and try again
                sleep(2)
                continue
            elif value[0] == 'front' or value[0] == 'inner' or value[0] == 'outer':
                values[value[0]] = float(value[1])
        sleep(0.01)
    return values


def main():
    window = tk.Tk()
    switch = Switch(window)
    print("hello")
    window.mainloop()
    for i in range(200):
        print(i)
        # if (i % 20 == 0):
        #     switch.running = 'w'
        # if i % 45 == 0:
        #     switch.running = 'e'
        print(start(switch))


if __name__ == "__main__":
    main()
