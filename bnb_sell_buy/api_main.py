import json
import requests
from io import StringIO
from playsound import playsound

  
key = "https://api.binance.com/api/v3/ticker/price?symbol=BTCUSDT"




while(True):

    data = requests.get(key)  
    data = data.json()
    s = StringIO()
    print(f"{data['price']}",file=s)
    x = float(s.getvalue())
    print(x)
    


    data = requests.get(key)  
    data = data.json()
    a = StringIO()
    print(f"{data['price']}",file=a)
    y = float(a.getvalue())
    print(y)
    
    
    if x > y:

        playsound(r'C:\Users\Piotr\Desktop\Random-projects\bnb_sell_buy\sell.wav')

    elif x < y:

        playsound(r'C:\Users\Piotr\Desktop\Random-projects\bnb_sell_buy\buy.wav')

    else:
        print("same")
    del x,y
    del a,s
    

    
    
    