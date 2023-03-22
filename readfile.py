import sys
import re

from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from bs4 import BeautifulSoup

filename = sys.argv[1]

class Course:
    def __init__(self, dept, num, grade):
        self.department = dept
        self.number = num
        self.grade = grade
        self.credit = ""
        self.title = ""
        self.description = ""


course_objects = []

with open(filename, 'r') as f:
    for line in f:
        dept, num, grade = line.split()
        course_obj = Course(dept, num, grade)
        course_objects.append(course_obj)


##############################################################################################
url = 'https://calendar.carleton.ca/undergrad/courses/'
chrome_options = Options()
chrome_options.add_argument('--headless')
driver = webdriver.Chrome(options=chrome_options)
driver.get(url)



for course in course_objects:

    # Find the hyperlink containing "dept" and click it
    driver.find_element(By.LINK_TEXT, course.department).click()

    # Find all div elements with class="courseblock"
    course_blocks = driver.find_elements(By.CLASS_NAME, 'courseblock')


    # Loop through each div to find and extract the desired information
    for block in course_blocks:
        if course.number in block.find_element(By.CLASS_NAME, 'courseblockcode').text:

            soup = BeautifulSoup(block.get_attribute('innerHTML'), 'html.parser')
            title_span = soup.find('span', class_='courseblocktitle')
            credit_match = re.search(r'\[(\d+(?:\.\d+)?) credit\]', title_span.text)

            # extract data
            course_code = title_span.find('span', class_="courseblockcode").text
            course_credit = credit_match.group(1)
            course_title = title_span.text.replace(course_code, '').replace(credit_match.group(0), '').strip()


            #append to course object
            course.credit = course_credit
            course.title = course_title
            

for course in course_objects:
    print(f"{course.department} {course.number} {course.credit} {course.grade}")