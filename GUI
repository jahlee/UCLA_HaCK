import tkinter as tk
#import matplotlib.pyplot as plt

xarr = []
yarr = []

class Car:
    def __init__(self,canvas):
        self.x = 100  #Sets the car at the origin
        self.y = 900
        self.draw(canvas)
    def draw(self,canvas):
        size = 25
        pos = canvas.create_oval(self.x-size, self.y-size, self.x+size, self.y+size, fill='yellow')
        xarr.append(pos)

def main():
    window = tk.Tk()
    window.title('Real-Time Graph')
    canvas = tk.Canvas(window, height=1000, width=1000, bg='black')
    canvas.pack()

    car = Car(canvas)
    
    #window.after(100,stuff) to update the graph every 100 ms

    window.mainloop()

main()    
