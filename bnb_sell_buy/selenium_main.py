from selenium import webdriver
import time
from bs4 import BeautifulSoup
from io import StringIO


url = 'https://www.binance.com/en/trade/BTC_BUSD?_from=markets&theme=dark&type=spot'
browser = webdriver.Chrome()
browser.minimize_window()
browser.get(url)
time.sleep(1)
browser.find_element("xpath",'//*[@id="onetrust-reject-all-handler"]').click()
browser.find_element("xpath",'//*[@id="1s"]').click()

while(True):
    soup = BeautifulSoup(browser.page_source, "html.parser")
    result = soup.find_all("div", {"class": "showPrice"})
    for item in result:
        print(item.text)
        




        
    

          
        
        
        



