from selenium import webdriver
import time
from bs4 import BeautifulSoup

url = 'https://www.binance.com/en/trade/BTC_BUSD?_from=markets&theme=dark&type=spot'
browser = webdriver.Chrome()
browser.get(url)
time.sleep(3)
browser.find_element("xpath",'//*[@id="onetrust-reject-all-handler"]').click()
browser.find_element("xpath",'//*[@id="1s"]').click()

while(True):
    soup = BeautifulSoup(browser.page_source, "html.parser")
    result = soup.find_all("div", {"class": "price left"})

    for item in result:
        time.sleep(1)
        print(item.text)
        



