import serial 
import time 
import pyautogui

ArduinoSerial = serial.Serial('COM3',9600) 
time.sleep(2)
while 1:
    incoming = str (ArduinoSerial.readline()) 
    print(incoming)
    
    if 'gesture 1' in incoming:
        pyautogui.hotkey('up')  

    if 'gesture 3' in incoming:
        pyautogui.hotkey('right')
        
    if 'gesture 5' in incoming:
        pyautogui.hotkey('down')  

    if 'gesture 4' in incoming:
        pyautogui.hotkey('left') 

    incoming = "";
    
