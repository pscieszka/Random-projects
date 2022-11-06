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

       playsound('buy.wav')

    elif x < y:

        print("es")
        
    else:
        print("same")
    del x,y
    del a,s
    

    
    
    