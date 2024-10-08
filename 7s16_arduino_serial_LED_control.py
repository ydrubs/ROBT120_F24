import serial
import time

# Replace 'COM3' with the appropriate port for your system
# On Linux or Mac, it might be something like '/dev/ttyUSB0'
arduino = serial.Serial('COM4', 9600, timeout=1)
time.sleep(2)  # Give the connection a second to settle

while True:
    command = input("Enter '0' to turn the LED off, '1' to turn it on, or 'quit' to exit: ").strip()

    if command == '0' or command == '1':
        arduino.write(command.encode())  # Send the command to Arduino
    elif command.lower() == 'quit':
        break
    else:
        print("Invalid command. Please enter '0', '1', or 'quit'.")

arduino.close()
