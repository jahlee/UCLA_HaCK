import tkinter as tk
import getData
from time import sleep
# import matplotlib.pyplot as plt
# car ~ 25 x 24cm, arena ~ 150 x 150cm
# --> 100 x 100px car, 600 x 600px arena
# 4 px = 1cm
# given a distance X in cm, --> 4 * X = num of pixels
# optimally ~25cm away = ~100px away from walls

car_arr = []
wall_arr = []


class Walls:
    def __init__(self, canvas):
        self.draw(canvas)

    def draw(self, canvas):
        canvas.create_rectangle(50, 50, 650, 650, outline='white')


class Car:
    def __init__(self, canvas):
        self.x = 150
        self.y = 550
        self.endX = 650
        self.endY = 550
        self.width = 40  # 40 pixels is how far from center they are, make it a little smaller
        self.draw(canvas)
        self.direction = 0  # self.direction % 4 = current direction of car
        # 0 = right, 1 = up, 2 = left, 3 = down

    def draw(self, canvas):
        # show moving car
        if len(car_arr) != 0:
            canvas.delete(car_arr[0])
            car_arr.pop()
        pos = canvas.create_rectangle(
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
        # recorded a distance greater than the arena length or faulty distance
        if distance > 150 or distance < 0:
            return

        # tot_dist = poisition of sensors + distance away from object
        tot_dist = self.width + (int)(4 * distance)

        # above
        if self.direction % 4 == 0:
            canvas.create_oval(self.x - 3, self.y - tot_dist - 3,
                               self.x + 3, self.y - tot_dist + 3, fill="white")
        # to left
        elif self.direction % 4 == 1:
            canvas.create_oval(self.x - tot_dist - 3, self.y - 3,
                               self.x - tot_dist + 3, self.y + 3, fill="white")
        # below
        elif self.direction % 4 == 2:
            canvas.create_oval(self.x - 3, self.y + tot_dist - 3,
                               self.x + 3, self.y + tot_dist + 3, fill="white")
        # to right
        else:
            canvas.create_oval(self.x + tot_dist - 3, self.y - 3,
                               self.x + tot_dist + 3, self.y + 3, fill="white")

    # Adjust self.x and self.y according to car's distance from the wall
    def updatePos(self, distance):
        if (distance < 0):
            pass
        tot_distance = self.width + (int)(distance*4)
        if self.direction % 4 == 0:
            self.y = 650 - tot_distance
            self.endY = self.y
        elif self.direction % 4 == 1:
            self.x = 650 - tot_distance
            self.endX = self.x
        elif self.direction % 4 == 2:
            self.y = 50 + tot_distance
            self.endY = self.y
        else:
            self.x = 50 + tot_distance
            self.endX = self.x

    # turn the car
    def turn(self):
        self.direction += 1
        if self.direction % 4 == 0:
            self.endX = 650
            # self.endX = self.x
        elif self.direction % 4 == 1:
            self.endY = 50
            # self.endX = self.x
        elif self.direction % 4 == 2:
            self.endX = 50
            # self.endY = self.y
        else:
            self.endY = 650
            # self.endX = self.x


def moveCar(car, canvas, window, num_turns, innerDist, outerDist, frontDist, switch):
    # MAX: stop finishing 2 rotations
    if num_turns >= 8:
        switch.command = 'e'
        tempVals = getData.start(switch)
        if tempVals == None:
            sleep(3)    # look at map for 3 seconds
            exit(0)
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
            window.after(2500, moveCar, car, canvas, window,
                         num_turns + 1, innerDist, outerDist, frontDist, switch)
            return
        # if distance in front is readable and the change in position is not larger than 100 pixels
        if frontDist > 0 and abs(650 - (frontDist * 4) - car.x) < 100:
            car.x = 950 - (int)(frontDist * 4)
        else:
            car.x += 5

    # going up
    elif num_turns % 4 == 1:
        # switch.command = 'w'
        if car.y <= 100:
            car.turn()
            window.after(2500, moveCar, car, canvas, window,
                         num_turns + 1, innerDist, outerDist, frontDist, switch)
            return
        # if distance in front is readable and the change in position is not larger than 100 pixels
        if frontDist > 0 and abs((frontDist * 4) - 50 - car.y) < 100:
            car.y = (int)(frontDist * 4) - 50
        else:
            car.y -= 5

    # going left
    elif num_turns % 4 == 2:
        # switch.command = 'e'
        if car.x <= 100:
            car.turn()
            window.after(2500, moveCar, car, canvas, window,
                         num_turns + 1, innerDist, outerDist, frontDist, switch)
            return
        # if distance in front is readable and the change in position is not larger than 100 pixels
        if frontDist > 0 and abs((frontDist * 6) - 50 - car.x) < 100:
            car.x = (int)(frontDist * 6) - 50
        else:
            car.x -= 5

    # going down
    else:
        if car.y >= 900:
            car.turn()
            window.after(2500, moveCar, car, canvas, window,
                         num_turns + 1, innerDist, outerDist, frontDist, switch)
            return
        # if distance in front is readable and the change in position is not larger than 100 pixels
        if frontDist > 0 and abs(650 - (frontDist * 4) - car.y) < 100:
            car.y = 650 - (int)(frontDist * 4)
        else:
            car.y += 5

    car.draw(canvas)

    # re-align if necessary
    if outerDist*4 > 140:
        switch.command = 'f'    # too far
    elif outerDist*4 < 60:
        switch.command = 'c'    # too close

    # get the data points again
    dictVals = getData.start(switch)
    if dictVals == None:
        sleep(3)
        exit(0)

    # changed it to every 10 ms to make it faster
    window.after(10, moveCar, car, canvas, window,
                 num_turns, dictVals.get('inner', -1), dictVals.get('outer', -1), dictVals.get('front', -1), switch)


def main():
    window = tk.Tk()
    window.title('Real-Time Graph')
    canvas = tk.Canvas(window, height=700, width=700, bg='black')
    canvas.pack()

    setup = Walls(canvas)
    car = Car(canvas)
    switch = getData.Switch(window)

    # to update the graph every 100 ms
    dictVals = getData.start(switch)
    if dictVals == None:
        sleep(3)
        exit(0)

    window.after(100, moveCar, car, canvas, window, 0,
                 dictVals.get('inner', -1), dictVals.get('outer', -1), dictVals.get('front', -1), switch)

    window.mainloop()


if __name__ == "__main__":
    main()
