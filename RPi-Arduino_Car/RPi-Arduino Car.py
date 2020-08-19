import serial
import pygame
import time





ser = serial.Serial('/dev/ttyACM0', 9600)
print("Serial Begin")
time.sleep(2)
pygame.init()
screen = pygame.display.set_mode((200, 200))

Start ='W'
Left= 'A'
Right='D'
Backwards='S'
Stop = 'Q'

Start= Start.encode()
Left = Left.encode()
Right= Right.encode()
Backwards = Backwards.encode()
Stop = Stop.encode()

Car_Running = True
while Car_Running:

    if(ser.in_waiting > 0):

        #print("Serial Communication Begin")

        for event in pygame.event.get():

            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_UP:
                    ser.write(Start)
                    print("Moving Forward!")
                
            
                if event.key == pygame.K_DOWN:
                    ser.write(Backwards)
                    print("Moving Backwards!")
 
            
                if event.key == pygame.K_LEFT:
                    ser.write(Left)
                    print("Turn Left!")

           
                if event.key == pygame.K_RIGHT:
                    ser.write(Right)
                    print("Turn Right!")
            
            
                if event.key == pygame.K_SPACE:
                    ser.write(Stop)
                    print("Stop the car!")
        if event.type == pygame.KEYUP:
            if event.key == pygame.K_LEFT or event.key == pygame.K_RIGHT or pygame.K_DOWN or pygame.K_UP: 
                ser.write(Stop)
