import pandas as pd
import time
import requests
from playsound import playsound
from datetime import datetime
import calendar 


while True:
    symbol='BTCUSDT'
    timeinterval = 15
    
    now = datetime.utcnow()
    unixtime = calendar.timegm(now.utctimetuple())
    since = unixtime
    start=str(since-60*60*10)    
    
    url = 'https://fapi.binance.com/fapi/v1/klines?symbol='+symbol+'&interval='+str(timeinterval)+'m'+'&limit=100'
    data = requests.get(url).json()        
    
    D = pd.DataFrame(data)
    D.columns = ['open_time', 'open', 'high', 'low', 'close', 'volume', 'close_time', 'qav', 'num_trades',
                 'taker_base_vol', 'taker_quote_vol', 'is_best_match']
    
    period=14
    df=D
    df['close'] = df['close'].astype(float)
    df2=df['close'].to_numpy()
    
    df2 = pd.DataFrame(df2, columns = ['close'])
    delta = df2.diff()
    
    up, down = delta.copy(), delta.copy()
    up[up < 0] = 0
    down[down > 0] = 0
    
    _gain = up.ewm(com=(period - 1), min_periods=period).mean()
    _loss = down.abs().ewm(com=(period - 1), min_periods=period).mean()
    
    RS = _gain / _loss
    
    
    rsi=100 - (100 / (1 + RS))  
    rsi=rsi['close'].iloc[-1]
    rsi=round(rsi,1)
    now = datetime.now()

    current_time = now.strftime("%H:%M:%S")
    
    text='Time: '+ current_time + ' Binance Futures '+symbol+' RSI: '+str(rsi)

    print(text)

    if rsi>67:

        playsound(r'C:\Users\Piotr\Desktop\Random-projects\bnb_sell_buy\high.mp3')

    elif rsi < 30:

        playsound(r'C:\Users\Piotr\Desktop\Random-projects\bnb_sell_buy\low.mp3')
  
    time.sleep(3)
