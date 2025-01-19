"""
Скрипт выполняет заполнение файла конфигурации подключения к mysql,
 беря значения из переменного окружения.

Сделано для облегчения деплоя с публичного репозитория, где нелья хранить
 приватные данные на виду =)
"""

import os

file_path = './scriptfiles/mysql.ini'

mysql_host = os.getenv('DDP_MYSQL_HOST')
mysql_user = os.getenv('DDP_MYSQL_USER')
mysql_pass = os.getenv('DDP_MYSQL_PASS')
mysql_dtbs = os.getenv('DDP_MYSQL_DTBS')

if not mysql_host or not mysql_user or not mysql_pass or not mysql_dtbs:
    raise ValueError("One of the required environment variable values ​​is not set!")

config_content = f"""
hostname = {mysql_host}
username = {mysql_user}
password = {mysql_pass}
database = {mysql_dtbs}
"""

with open(file_path, 'w') as config_file:
    config_file.write(config_content)

print("The MySQL configuration file has been created successfully.")
