
import pyautogui,time 

time.sleep(10)
word = "I luvv you soo much xoxo"
for i in range(100):
    
        pyautogui.typewrite(word)
        pyautogui.press("enter")
        print(i+1)