import serial
import time

# Replace 'COMx' with your actual serial port, e.g., '/dev/ttyUSB0' on Linux or 'COM3' on Windows
arduino_port = 'COM8'

arduino = serial.Serial(arduino_port, 9600, timeout=2)


def send_command(command):
    print(f"Sending command: {command}")
    arduino.write(command.encode('utf-8'))
    time.sleep(1)  # Allow some time for the Arduino to process the command


def receive_response():
    while True:
        data = arduino.readline().decode('utf-8').strip()
        if data:
            if "0.5mm" in data:
                with open('C:\\Users\\msaad\\Documents\\Saad\\Research Projects\\Dr. Umer\'s Project\\Reverse-Engineered-Actuator\\DataExtraction\\Experiment 2\\Sample 4\\0.5mm.txt','w') as f0_5:
                    while True:
                        data = arduino.readline().decode('utf-8').strip()
                        print(data)
                        if "end" in data:
                            f0_5.close()
                            break
                        else:
                            f0_5.write(data)
                            f0_5.write("\n")

            if "1mm" in data:
                with open('C:\\Users\\msaad\\Documents\\Saad\\Research Projects\\Dr. Umer\'s Project\\Reverse-Engineered-Actuator\\DataExtraction\\Experiment 2\\Sample 4\\1mm.txt','w') as f1:
                    while True:
                        data = arduino.readline().decode('utf-8').strip()
                        print(data)
                        if "end" in data:
                            f1.close()
                            break
                        else:
                            f1.write(data)
                            f1.write("\n")

            if "1.5mm" in data:
                with open('C:\\Users\\msaad\\Documents\\Saad\\Research Projects\\Dr. Umer\'s Project\\Reverse-Engineered-Actuator\\DataExtraction\\Experiment 2\\Sample 4\\1.5mm.txt','w') as f1_5:
                    while True:
                        data = arduino.readline().decode('utf-8').strip()
                        print(data)
                        if "end" in data:
                            f1_5.close()
                            break
                        else:
                            f1_5.write(data)
                            f1_5.write("\n")

            if "2mm" in data:
                with open('C:\\Users\\msaad\\Documents\\Saad\\Research Projects\\Dr. Umer\'s Project\\Reverse-Engineered-Actuator\\DataExtraction\\Experiment 2\\Sample 4\\2mm.txt','w') as f2:
                    while True:
                        data = arduino.readline().decode('utf-8').strip()
                        print(data)
                        if "end" in data:
                            f2.close()
                            break
                        else:
                            f2.write(data)
                            f2.write("\n")

            if "2.5mm" in data:
                with open('C:\\Users\\msaad\\Documents\\Saad\\Research Projects\\Dr. Umer\'s Project\\Reverse-Engineered-Actuator\\DataExtraction\\Experiment 2\\Sample 4\\2.5mm.txt','w') as f2_5:
                    while True:
                        data = arduino.readline().decode('utf-8').strip()
                        print(data)
                        if "end" in data:
                            f2_5.close()
                            break
                        else:
                            f2_5.write(data)
                            f2_5.write("\n")

            if "3mm" in data:
                with open('C:\\Users\\msaad\\Documents\\Saad\\Research Projects\\Dr. Umer\'s Project\\Reverse-Engineered-Actuator\\DataExtraction\\Experiment 2\\Sample 4\\3mm.txt','w') as f3:
                    while True:
                        data = arduino.readline().decode('utf-8').strip()
                        print(data)
                        if "end" in data:
                            f3.close()
                            break
                        else:
                            f3.write(data)
                            f3.write("\n")

            if "3.5mm" in data:
                with open('C:\\Users\\msaad\\Documents\\Saad\\Research Projects\\Dr. Umer\'s Project\\Reverse-Engineered-Actuator\\DataExtraction\\Experiment 2\\Sample 4\\3.5mm.txt','w') as f3_5:
                    while True:
                        data = arduino.readline().decode('utf-8').strip()
                        print(data)
                        if "end" in data:
                            f3_5.close()
                            break
                        else:
                            f3_5.write(data)
                            f3_5.write("\n")

            if "4mm" in data:
                with open('C:\\Users\\msaad\\Documents\\Saad\\Research Projects\\Dr. Umer\'s Project\\Reverse-Engineered-Actuator\\DataExtraction\\Experiment 2\\Sample 4\\4mm.txt','w') as f4:
                    while True:
                        data = arduino.readline().decode('utf-8').strip()
                        print(data)
                        if "end" in data:
                            f4.close()
                            break
                        else:
                            f4.write(data)
                            f4.write("\n")

            if "4.5mm" in data:
                with open('C:\\Users\\msaad\\Documents\\Saad\\Research Projects\\Dr. Umer\'s Project\\Reverse-Engineered-Actuator\\DataExtraction\\Experiment 2\\Sample 4\\4.5mm.txt','w') as f4_5:
                    while True:
                        data = arduino.readline().decode('utf-8').strip()
                        print(data)
                        if "end" in data:
                            f4_5.close()
                            break
                        else:
                            f4_5.write(data)
                            f4_5.write("\n")

            if "5.5mm" in data:
                with open('C:\\Users\\msaad\\Documents\\Saad\\Research Projects\\Dr. Umer\'s Project\\Reverse-Engineered-Actuator\\DataExtraction\\Experiment 2\\Sample 4\\5.5mm.txt','w') as f5_5:
                    while True:
                        data = arduino.readline().decode('utf-8').strip()
                        print(data)
                        if "end" in data:
                            f5_5.close()
                            break
                        else:
                            f5_5.write(data)
                            f5_5.write("\n")

            if "6mm" in data:
                with open('C:\\Users\\msaad\\Documents\\Saad\\Research Projects\\Dr. Umer\'s Project\\Reverse-Engineered-Actuator\\DataExtraction\\Experiment 2\\Sample 4\\6mm.txt','w') as f6:
                    while True:
                        data = arduino.readline().decode('utf-8').strip()
                        print(data)
                        if "end" in data:
                            f6.close()
                            break
                        else:
                            f6.write(data)
                            f6.write("\n")

            if "6.5mm" in data:
                with open('C:\\Users\\msaad\\Documents\\Saad\\Research Projects\\Dr. Umer\'s Project\\Reverse-Engineered-Actuator\\DataExtraction\\Experiment 2\\Sample 4\\6.5mm.txt','w') as f6_5:
                    while True:
                        data = arduino.readline().decode('utf-8').strip()
                        print(data)
                        if "end" in data:
                            f6_5.close()
                            break
                        else:
                            f6_5.write(data)
                            f6_5.write("\n")

            if "7mm" in data:
                with open('C:\\Users\\msaad\\Documents\\Saad\\Research Projects\\Dr. Umer\'s Project\\Reverse-Engineered-Actuator\\DataExtraction\\Experiment 2\\Sample 4\\7mm.txt','w') as f7:
                    while True:
                        data = arduino.readline().decode('utf-8').strip()
                        print(data)
                        if "end" in data:
                            f7.close()
                            break
                        else:
                            f7.write(data)
                            f7.write("\n")

            if "7.5mm" in data:
                with open('C:\\Users\\msaad\\Documents\\Saad\\Research Projects\\Dr. Umer\'s Project\\Reverse-Engineered-Actuator\\DataExtraction\\Experiment 2\\Sample 4\\7.5mm.txt','w') as f7_5:
                    while True:
                        data = arduino.readline().decode('utf-8').strip()
                        print(data)
                        if "end" in data:
                            f7_5.close()
                            break
                        else:
                            f7_5.write(data)
                            f7_5.write("\n")

            if "8mm" in data:
                with open('C:\\Users\\msaad\\Documents\\Saad\\Research Projects\\Dr. Umer\'s Project\\Reverse-Engineered-Actuator\\DataExtraction\\Experiment 2\\Sample 4\\8mm.txt','w') as f8:
                    while True:
                        data = arduino.readline().decode('utf-8').strip()
                        print(data)
                        if "end" in data:
                            f8.close()
                            break
                        else:
                            f8.write(data)
                            f8.write("\n")

            if "8.5mm" in data:
                with open('C:\\Users\\msaad\\Documents\\Saad\\Research Projects\\Dr. Umer\'s Project\\Reverse-Engineered-Actuator\\DataExtraction\\Experiment 2\\Sample 4\\8.5mm.txt','w') as f8_5:
                    while True:
                        data = arduino.readline().decode('utf-8').strip()
                        print(data)
                        if "end" in data:
                            f8_5.close()
                            break
                        else:
                            f8_5.write(data)
                            f8_5.write("\n")

            if "9mm" in data:
                with open('C:\\Users\\msaad\\Documents\\Saad\\Research Projects\\Dr. Umer\'s Project\\Reverse-Engineered-Actuator\\DataExtraction\\Experiment 2\\Sample 4\\9mm.txt','w') as f9:
                    while True:
                        data = arduino.readline().decode('utf-8').strip()
                        print(data)
                        if "end" in data:
                            f9.close()
                            break
                        else:
                            f9.write(data)
                            f9.write("\n")

            if "9.5mm" in data:
                with open('C:\\Users\\msaad\\Documents\\Saad\\Research Projects\\Dr. Umer\'s Project\\Reverse-Engineered-Actuator\\DataExtraction\\Experiment 2\\Sample 4\\9.5mm.txt','w') as f9_5:
                    while True:
                        data = arduino.readline().decode('utf-8').strip()
                        print(data)
                        if "end" in data:
                            f9_5.close()
                            break
                        else:
                            f9_5.write(data)
                            f9_5.write("\n")

            if "10mm" in data:
                with open('C:\\Users\\msaad\\Documents\\Saad\\Research Projects\\Dr. Umer\'s Project\\Reverse-Engineered-Actuator\\DataExtraction\\Experiment 2\\Sample 4\\10mm.txt','w') as f10:
                    while True:
                        data = arduino.readline().decode('utf-8').strip()
                        print(data)
                        if "end" in data:
                            f10.close()
                            break
                        else:
                            f10.write(data)
                            f10.write("\n")

            if "5mm" in data:
                with open('C:\\Users\\msaad\\Documents\\Saad\\Research Projects\\Dr. Umer\'s Project\\Reverse-Engineered-Actuator\\DataExtraction\\Experiment 2\\Sample 4\\5mm.txt','w') as f5:
                    while True:
                        data = arduino.readline().decode('utf-8').strip()
                        print(data)
                        if "end" in data:
                            f5.close()
                            break
                        else:
                            f5.write(data)
                            f5.write("\n")

            if "finish" in data:
                break

            # else:
            #     print("End of data")
            #     break


try:
    send_command("start\n")
    send_command("start\n")
    while True:
        receive_response()
        break

except Exception as e:
    print(f"Error: {str(e)}")

finally:
    arduino.close()
