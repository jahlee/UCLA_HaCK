import tkinter as tk
#import matplotlib.pyplot as plt

xarr = []
yarr = []

class Car:
    def __init__(self,canvas):
        self.x = 100  #Sets the car near the origin
        self.y = 900
        self.draw(canvas)
    def draw(self,canvas):
        size = 25
        pos = canvas.create_oval(self.x-size, self.y-size, self.x+size, self.y+size, fill='yellow')
        xarr.append(pos)

def updatePos(car, canvas, window):
    while car.x < 1000:
        car.x = car.x + 20
        car.draw(canvas)
    if car.x == 1000:
        #Reaches right wall
        car.y = car.y - 20
        car.draw(canvas)
        car.x = car.x - 20
        while car.x > 100:
            car.x = car.x - 20
            car.draw(canvas)
        car.y = car.y - 20    
        car.draw(canvas)
    elif car.x == 0:
        #Reaches left wall
        car.y = car.y - 20
        car.draw(canvas)
        car.x = car.x + 20
        while car.x < 1000:
            car.x = car.x + 20
            car.draw(canvas)
        car.y = car.y - 20    
        car.draw(canvas)    
    elif car.y == 0:
        #Reaches top wall
        pass
    window.after(100,car)

def main():
    window = tk.Tk()
    window.title('Real-Time Graph')
    canvas = tk.Canvas(window, height=1000, width=1000, bg='black')
    canvas.pack()

    car = Car(canvas)
    
    window.after(100,updatePos,car,canvas,window) #to update the graph every 100 ms

    window.mainloop()

main()    
