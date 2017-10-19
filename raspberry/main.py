import xbox
import serial

arduino =  serial.Serial('/dev/ttyACM0', 9600)

def send_forward():
    arduino.write('w') 

def send_turn_right():
    arduino.write('e') 

def send_turn_left():
    arduino.write('q') 

def send_spin_right():
    arduino.write('d') 

def send_spin_left():
    arduino.write('a') 

def send_backwards():
    arduino.write('s') 

def send_halt():
    arduino.write('h')

def parse_joy(joy):
    # Dpad U/D/L/R
    if joy.dpadUp() and joy.dpadRight():
        send_turn_right()
    elif joy.dpadUp() and joy.dpadLeft():
        send_turn_left()
    elif joy.dpadUp():
        send_forward()
    elif joy.dpadDown():
        send_backwards()
    elif joy.dpadLeft():
        send_spin_left() 
    elif joy.dpadRight():
        send_spin_right() 
    else:
        send_halt()
        
def main():
    joy = xbox.Joystick()
    while not joy.Back():
        parse_joy(joy)
    joy.close()

if __name__ == '__main__':
    main()
