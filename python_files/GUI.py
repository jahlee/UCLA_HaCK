import tkinter as tk
import getData
# import matplotlib.pyplot as plt
# car ~ 25 x 20cm, arena ~ 1500 x 1500cm
# --> 16 x 13px car, 1000 x 1000px arena


car_arr = []
wall_arr = []


class Walls:
    def __init__(self, canvas):
        self.draw(canvas)

    def draw(self, canvas):
        canvas.create_rectangle(50, 50, 950, 950, outline='white')


class Car:
    def __init__(self, canvas):
        self.x = 100
        self.y = 900
        self.endX = 950
        self.endY = 900
        self.width = 8  # 8 pixels is how far from center they are
        self.draw(canvas)
        self.direction = 0  # self.direction % 4 = current direction of car
        # 0 = right, 1 = up, 2 = left, 3 = down

    def draw(self, canvas):
        # show moving car
        if len(car_arr) != 0:
            canvas.delete(car_arr[0])
            car_arr.pop()
        pos = canvas.create_oval(
            self.x-self.width, self.y-self.width, self.x+self.width, self.y+self.width, fill='red')
        car_arr.append(pos)

        # show line from current position to end of facing wall
        if len(wall_arr) != 0:
            canvas.delete(wall_arr[0])
            wall_arr.pop()
        pos = canvas.create_line(
            self.x, self.y, self.endX, self.endY, dash=(6, 5), fill="yellow")
        wall_arr.append(pos)

    def drawInside(self, canvas, distance):
        # tot_dist = poisition of sensors + distance away from object
        tot_dist = self.width + distance

        if self.direction % 4 == 0:
            canvas.create_oval(self.x - 1, self.y - tot_dist - 1,
                               self.x + 1, self.y - tot_dist + 1, fill="white")
        elif self.direction % 4 == 1:
            canvas.create_oval(self.x - tot_dist - 1, self.y - 1,
                               self.x - tot_dist + 1, self.y + 1, fill="white")
        elif self.direction % 4 == 2:
            canvas.create_oval(self.x - 1, self.y + tot_dist - 1,
                               self.x + 1, self.y + tot_dist + 1, fill="white")
        else:
            canvas.create_oval(self.x + tot_dist - 1, self.y - 1,
                               self.x + tot_dist + 1, self.y + 1, fill="white")

    # Adjust self.x and self.y according to car's distance from the wall
    def updatePos(self, distance):
        if (distance == 0):
            pass
        distance += self.width
        if self.direction % 4 == 0:
            self.y = 950 - distance
            self.endY = self.y
        elif self.direction % 4 == 1:
            self.x = 950 - distance
            self.endX = self.x
        elif self.direction % 4 == 2:
            self.y = 50 + distance
            self.endY = self.y
        else:
            self.x = 50 + distance
            self.endX = self.x

    # turn the car
    def turn(self):
        self.direction += 1
        if self.direction % 4 == 0:
            self.endX = 950
            # self.endX = self.x
        elif self.direction % 4 == 1:
            self.endY = 50
            # self.endX = self.x
        elif self.direction % 4 == 2:
            self.endX = 50
            # self.endY = self.y
        else:
            self.endY = 950
            # self.endX = self.x


def moveCar(car, canvas, window, num_turns, innerDist, outerDist):
    # stop finishing 2 rotations
    if num_turns >= 8:
        exit(0)
        return

    # update position of car
    car.updatePos(outerDist)

    # draw inner line
    car.drawInside(canvas, innerDist)

    # going right
    if num_turns % 4 == 0:
        if car.x >= 900:
            car.turn()
            window.after(100, moveCar, car, canvas, window,
                         num_turns + 1, innerDist, outerDist)
            return
        car.x += 10

    # going up
    elif num_turns % 4 == 1:
        if car.y <= 100:
            car.turn()
            window.after(100, moveCar, car, canvas, window,
                         num_turns + 1, innerDist, outerDist)
            return
        car.y -= 10

    # going left
    elif num_turns % 4 == 2:
        if car.x <= 100:
            car.turn()
            window.after(100, moveCar, car, canvas, window,
                         num_turns + 1, innerDist, outerDist)
            return
        car.x -= 10

    # going down
    else:
        if car.y >= 900:
            car.turn()
            window.after(100, moveCar, car, canvas, window,
                         num_turns + 1, innerDist, outerDist)
            return
        car.y += 10

    car.draw(canvas)

    # get the data points again
    dictVals = getData.start()

    # changed it to every 10 ms to make it faster
    window.after(10, moveCar, car, canvas, window,
                 num_turns, dictVals.get('inner', 0), dictVals.get('outer', 0))


def main():
    window = tk.Tk()
    window.title('Real-Time Graph')
    canvas = tk.Canvas(window, height=1000, width=1000, bg='black')
    canvas.pack()

    setup = Walls(canvas)
    car = Car(canvas)

    # to update the graph every 100 ms
    dictVals = getData.start()
    window.after(100, moveCar, car, canvas, window, 0,
                 dictVals.get('inner', 0), dictVals.get('outer', 0))

    window.mainloop()


if __name__ == "__main__":
    main()
