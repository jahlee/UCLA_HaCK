# https://maker.pro/arduino/tutorial/how-to-create-simple-serial-communications-between-an-arduino-and-the-python-ide
# on mac, use ls /dev/tty.* to find something like /dev/tty.usbmodem141101 (for COM port)
import serial
import time
import sys
import signal
import tkinter as tk
from time import sleep


# GUI to turn on/off/exit the project
class Switch:
    def __init__(self):
        self.window = tk.Tk()
        self.message = tk.Label(
            self.window, text="Ready whenever you are!", fg="blue")
        self.onButton = tk.Button(self.window, text="ON", command=self.TurnOn)
        self.offButton = tk.Button(
            self.window, text="OFF", command=self.TurnOff)
        self.exitButton = tk.Button(
            self.window, text="EXIT", command=self.Exit)
        self.run()
        self.running = 'w'  # waiting

    def TurnOn(self):
        self.message.config(text='VROOM! The car is running!', fg="green")
        self.running = ''  # running, no Serial.available

    def TurnOff(self):
        self.message.config(text='HOLUP! The car has stopped!', fg="red")
        self.running = 's'  # stopped

    def run(self):
        self.message.pack()
        self.onButton.pack()
        self.offButton.pack()
        self.exitButton.pack()
        self.window.mainloop()

    def Exit(self):
        self.running = 'e'  # exited
        exit(0)


# not sure if we need this lol
def signal_handler(signal, frame):
    print("closing program")
    SerialPort.close()
    sys.exit(0)


def start():
    COM = input("Enter the COM Port\n")
    BAUD = input("Enter the Baudrate\n")
    switch = Switch()

    SerialPort = serial.Serial(COM, BAUD, timeout=1)
    values = {}
    while len(values) < 3:
        try:
            OutgoingData = switch.running
            SerialPort.write(bytes(OutgoingData, 'utf-8'))
        except KeyboardInterrupt:
            print("Closing and exiting the program")
            SerialPort.close()
            sys.exit(0)

        # gets the incoming data from serial
        IncomingData = SerialPort.readline()
        if (IncomingData):
            # print((IncomingData).decode('utf-8'))   # print data
            # gets value without extra whitespace
            value = IncomingData.decode('utf-8').rstrip().split(": ")
            if (value[0] == "EXIT"):
                return None
            elif (value[0] == "WAIT"):
                return {"WAIT": 0}
            elif (value[0] == "STOP"):
                return {"STOP": 0}
            values[value[0]] = value[1]
        time.sleep(0.01)
    return values


def main():
    start()


if __name__ == "__main__":
    main()
