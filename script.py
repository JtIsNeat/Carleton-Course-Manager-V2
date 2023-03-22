import sys
import re

from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from bs4 import BeautifulSoup

url = 'https://calendar.carleton.ca/undergrad/courses/'

chrome_options = Options()
chrome_options.add_argument('--headless')
driver = webdriver.Chrome(options=chrome_options)
driver.get(url)

if(len(sys.argv) < 3):
    exit()

dept = sys.argv[1]
num = sys.argv[2]

# Find the hyperlink containing "dept" and click it
driver.find_element(By.LINK_TEXT, dept).click()

# Find all div elements with class="courseblock"
course_blocks = driver.find_elements(By.CLASS_NAME, 'courseblock')

if(len(sys.argv) > 2):

    # Loop through each div to find and extract the desired information
    for block in course_blocks:
        if num in block.find_element(By.CLASS_NAME, 'courseblockcode').text:

            soup = BeautifulSoup(block.get_attribute('innerHTML'), 'html.parser')
            title_span = soup.find('span', class_='courseblocktitle')
            credit_match = re.search(r'\[(\d+(?:\.\d+)?) credit\]', title_span.text)

            # extract data
            course_code = title_span.find('span', class_="courseblockcode").text
            course_title = title_span.text.replace(course_code, '').replace(credit_match.group(0), '').strip()


            print(f"{course_title}")

else:

    # Loop through each div to find and extract the desired information
    for block in course_blocks:
        if num in block.find_element(By.CLASS_NAME, 'courseblockcode').text:

            soup = BeautifulSoup(block.get_attribute('innerHTML'), 'html.parser')
            title_span = soup.find('span', class_='courseblocktitle')
            credit_match = re.search(r'\[(\d+(?:\.\d+)?) credit\]', title_span.text)

            # extract data
            course_code = title_span.find('span', class_="courseblockcode").text
            course_dept, course_num = re.match(r'([A-Z]+)\s*(\d+)', course_code).groups()
            course_credit = credit_match.group(1)
            course_title = title_span.text.replace(course_code, '').replace(credit_match.group(0), '').strip()

            # get course description
            #course_description = title_span.find_next('br').next_sibling.strip()
            #course_description_additional = title_span.find_next('div', class_='coursedescadditional').text.strip()

            print(f"{course_dept}")
            print(f"{course_num}")
            print(f"{course_credit}")
            print(f"{course_title}")



