import json
import random
import time
import os
import shutil
import requests

import pyautogui
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.common.exceptions import TimeoutException, NoSuchElementException


import os
import requests
import shutil


def download_and_move_file(url, destination_dir):
    # Определение имени файла на основе URL
    filename = url.split('/')[-1]
    # Получение содержимого файла по URL
    response = requests.get(url, stream=True)
    # Проверка успешности загрузки файла
    if response.status_code == 200:
        # Путь к файлу для сохранения
        file_path = os.path.join(destination_dir, filename)
        # Запись содержимого файла
        with open(file_path, 'wb') as f:
            response.raw.decode_content = True
            shutil.copyfileobj(response.raw, f)
        print(f"Файл успешно загружен и перемещен в {file_path}")
    else:
        print("Ошибка при загрузке файла")



def get_selectors(driver, selectors):
    results = []
    wait = WebDriverWait(driver, 10)
    wait.until(EC.presence_of_element_located((By.CSS_SELECTOR, 'body')))
    for selector in selectors:
        try:
            print(f"Selector: {selector}")
            DOM_selector = wait.until(
                EC.visibility_of_element_located((By.CSS_SELECTOR, selector)))
            print(DOM_selector)
            results.append(DOM_selector)
        except TimeoutException:
            raise TimeoutException(
                f"Timeout occurred while waiting for {selector}")
        except NoSuchElementException:
            raise NoSuchElementException(f"Element {selector} was not found.")
    return results


def get_credentials(path='credentials.json'):
    try:
        with open(path, 'r') as file:
            data = json.load(file)
        return (data['login'], data['password'])
    except FileNotFoundError:
        print("Credentials file not found, login unsuccess.")
        return None


def enter_into_element(input_field, text, min_delay=0.0, max_delay=0.1):
    input_field.click()
    for char in text:
        pyautogui.typewrite(char)
        sleep_time = random.gauss(
            (min_delay + max_delay) / 2, (min_delay + max_delay) / 2)
        print(f"Sleeptime: {sleep_time}")
        time.sleep(abs(sleep_time))


def get_driver():
    options = webdriver.ChromeOptions()
    options.add_argument(
        "user-agent=Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.102 Safari/537.36")
    return webdriver.Chrome(options=options)


def login(driver):
    driver.get('https://fresh.nsuts.ru/nsuts-new/login')
    email_field, password_field, submit_button = get_selectors(
        driver, ['input[name="email"]',  'input[name="password"]', 'input[type="submit"]'])

    credentials = get_credentials()
    if credentials:
        enter_into_element(email_field, credentials[0])
        enter_into_element(password_field, credentials[1])

        submit_button.click()


def iterate_and_click_links(driver, filter, handler):
    body = get_selectors(driver, ['body'])[0]
    print(f"iterate_pack body {body}")
    links = body.find_elements(By.TAG_NAME, 'a')
    print(f"iterate_pack links {links}")
    for link in links:
        if not link:
            print(f"Empty link {link}")
            continue
        if not link.get_attribute('href'):
            print(f"No href {link.get_attribute('href')}")
            continue
        if filter in link.get_attribute('href'):
            link.click()
            handler(driver)


def get_task_pdf():
    url = 
    destination_dir = os.path.dirname(os.path.abspath(__file__))
    download_and_move_file(url, destination_dir)


def iterate_packs(driver):
    iterate_and_click_links(driver, 'tour_to_select', iterate_packs)


def select_olympiad(driver):
    iterate_and_click_links(driver, '194', iterate_packs)




def download_file(href):
    pass

driver = get_driver()
login(driver)
time.sleep(1)
select_olympiad(driver)
time.sleep(3)
iterate_packs(driver)
time.sleep(1000)
