import re
import requests
import pandas as pd
from bs4 import BeautifulSoup

data = requests.get('https://en.wikipedia.org/wiki/List_of_counties_in_California').text
soup = BeautifulSoup(data, 'html.parser')

for table in soup.find_all('span', {"data-sort-value" : "\d+"}):
    for i in table:
        print(i)