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
        self.COM = input("Enter the COM Port\n")
        self.BAUD = input("Enter the Baudrate\n")
        # self.COM = "/dev/tty.usbmodem141101"
        # self.BAUD = "9600"
        self.SerialPort = serial.Serial(self.COM, self.BAUD, timeout=1)

        self.new_window = tk.Toplevel(window)
        self.message = tk.Label(
            self.new_window, text="Ready whenever you are!", fg="blue")
        self.onButton = tk.Button(
            self.new_window, text="ON", command=self.TurnOn)
        self.offButton = tk.Button(
            self.new_window, text="OFF", command=self.TurnOff)
        self.exitButton = tk.Button(
            self.new_window, text="EXIT", command=self.Exit)
        self.packComponents()
        # self.run()
        self.command = ''  # waiting

    def TurnOn(self):
        self.message.config(text='VROOM! The car is command!', fg="green")
        self.command = ''  # running, no Serial.available

    def TurnOff(self):
        self.message.config(text='HOLUP! The car has stopped!', fg="red")
        self.command = 'w'  # stopped (waiting)

    def packComponents(self):
        self.message.pack()
        self.onButton.pack()
        self.offButton.pack()
        self.exitButton.pack()

    def Exit(self):
        self.command = 'e'  # exited
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
            #switch.command = choices[random.randrange(3)]
            OutgoingData = switch.command
            switch.SerialPort.write(bytes(OutgoingData, 'utf-8'))
        except KeyboardInterrupt:
            print("Closing and exiting the program")
            switch.SerialPort.close()
            sys.exit(0)

        IncomingData = switch.SerialPort.readline()
        if (IncomingData):
            # print((IncomingData).decode('utf-8'))   # print data
            # gets value without extra whitespace
            try:
                value = IncomingData.decode('utf-8').strip().split(":")
                if (value[0] == "EXIT" or value[0] == "-1"):
                    print("EXIT")
                    return None
                elif (value[0] == "WAIT" or value[0] == "-2"):  # wait 2 seconds and try again
                    print("WAIT")
                    sleep(0.3)
                    continue
                elif value[0] == 'front' or value[0] == 'inner' or value[0] == 'outer':
                    try:
                        num = float(value[1])
                        values[value[0]] = num
                    except ValueError:
                        print("Bad input... retrying")
                else:
                    print(value)
            except UnicodeDecodeError:
                print("Bad unicode")
        sleep(0.01)
    return values


# def main():
    # window = tk.Tk()
    # switch = Switch(window)
    # print("hello")
    # window.after
    # window.mainloop()
    # for i in range(200):
    #     print(i)
    # if (i % 20 == 0):
    #     switch.command = 'w'
    # if i % 45 == 0:
    #     switch.command = 'e'
    # print(start(switch))

    # if __name__ == "__main__":
    #     main()
