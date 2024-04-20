import json
import random
import time
import pyautogui
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC


def get_credentials(path='credentials.json'):
    with open(path, 'r') as file:
        data = json.load(file)
    return (data['login'], data['password'])


def enter_into_element(input_field, text, min_delay=0.05, max_delay=0.5):
    input_field.click()
    for char in text:
        pyautogui.typewrite(char, interval=random.uniform(
            (min_delay, max_delay), 1.0))
        time.sleep(random.gauss((min_delay + max_delay) / 2, 1.0))


def get_driver():
    options = webdriver.ChromeOptions()
    options.add_argument(
        "user-agent=Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.102 Safari/537.36")
    return webdriver.Chrome(options=options)


def login(driver):
    driver.get('https://fresh.nsuts.ru/nsuts-new/login')

    wait = WebDriverWait(driver, 10)
    wait.until(EC.presence_of_element_located((By.CSS_SELECTOR, 'body')))
    email_field = wait.until(EC.visibility_of_element_located(
        (By.NAME, 'input[type="email"]')))
    password_field = wait.until(EC.visibility_of_element_located(
        (By.NAME, 'input[type="password"]')))

    credentials = get_credentials()
    enter_into_element(email_field, credentials[0])
    enter_into_element(password_field, credentials[1])

    driver.find_element(By.CSS_SELECTOR, 'input[type="submit"]').click()


driver = get_driver()
login(driver)
