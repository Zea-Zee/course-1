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


def download_and_move_file(url, destination_dir):
    print(f"Load url: {url}")
    response = requests.get(url, stream=True)
    if response.status_code == 200:
        file_path = os.path.join(destination_dir, 'Task.pdf')
        with open(file_path, 'wb') as f:
            response.raw.decode_content = True
            shutil.copyfileobj(response.raw, f)
        print(f"File successfuly loaded into {file_path}")
    else:
        print("Loading error")


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


def iterate_and_click_links(driver, filter, handler, click=False, attribute='href'):
    index = 0
    body = get_selectors(driver, ['body'])[0]
    print(f"iterate_pack body {body}")
    links = body.find_elements(By.TAG_NAME, 'a')
    print(f"iterate_pack links {links}")
    for link in links:
        if not link:
            print(f"Empty link {link}")
            continue
        if not link.get_attribute(attribute):
            print(f"No href {link.get_attribute('href')}")
            continue
        print(f"Link href is {link}")
        if filter in link.get_attribute(attribute):
            print(f"Found link: {link}")
            if click:
                link.click()
                print(f"Clicked on link: {link}")
            handler(driver)
            return 


# def get_task_pdf():
#     url =
#     destination_dir = os.path.dirname(os.path.abspath(__file__))
#     download_and_move_file(url, destination_dir)


def get_pack_data(driver):
    time.sleep(5)
    executable_path = os.path.abspath(__file__)
    executable_directory = os.path.dirname(executable_path)

    body = get_selectors(driver, ['body'])[0]
    print(f"iterate_pack body {body}")
    links = body.find_elements(By.TAG_NAME, 'a')
    print(f"iterate_pack links {links}")

    url = ''
    name = ''

    for link in links:
        if link and link.get_attribute('href'):
            print(f"HREF: {link.get_attribute('href')}")
            if 'tour_statement' in link.get_attribute('href'):
                url = link.get_attribute('href')
            elif 'nsuts-new/tours' in link.get_attribute('href'):
                name = link.text
                return_elem = link
        else:
            print(f"Link {link} is fake")

    if 'Туры > ' in name:
        name = name.replace('Туры > ', '')
    pack_dir = os.path.join(executable_directory, name)
    print(f"URL: {url}")
    print(f"Dir: {pack_dir}")
    if not os.path.exists(pack_dir):
        os.makedirs(pack_dir)

    download_and_move_file(url, pack_dir)
    return_elem.click()
    time.sleep(1)



def iterate_packs(driver):
    iterate_and_click_links(driver, 'tour_to_select', get_pack_data, click=True)


def select_olympiad(driver):
    iterate_and_click_links(driver, '194', iterate_packs, click=True, attribute='id')


def download_file(href):
    pass


driver = get_driver()
login(driver)
time.sleep(1)
select_olympiad(driver)
time.sleep(3)
iterate_packs(driver)
time.sleep(1000)
