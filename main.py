import inputs
import serial
import time


arduino = serial.Serial('/dev/ttyACM0', 9600, timeout=1)


def send_command_to_arduino(command):
    # Send the command string to the Arduino
    arduino.write(command)


def check_buttons():
    # Get the events from the gamepad (PS4 controller)
    events = inputs.get_gamepad()

    for event in events:
        if event.ev_type == 'Key':

            if event.ev_code == 'BTN_SOUTH' and event.ev_value == 1:  # 'X' button pressed
                print("X Button Pressed! Sending command to Arduino...")
                send_command_to_arduino("ARMRotateUp();")
            
            if event.ev_code == 'BTN_EAST' and event.ev_value == 1: 
                print("Z Button Pressed! Sending command to Arduino...")
                send_command_to_arduino("ARMRotateDown();")

            if event.ev_code == 'ABS_Y' and event.ev_value > 0:
                 print("Movement Data gathering")
                 send_command_to_arduino("MoveForward();")
                 

def main():
    while True:
        check_buttons()

        time.sleep(0.1) 

if __name__ == "__main__":
    main()
