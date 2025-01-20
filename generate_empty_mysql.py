"""
Скрипт генерирует для локалки файл mysql.ini, который можно открыть и прописать свои данные от БД.
"""

import os

file_path = './mysql.ini'

config_content = f"""
hostname = localhost
username = root
password = password
database = database
server_port = 3306
"""

with open(file_path, 'w') as config_file:
    config_file.write(config_content)

print("The MySQL configuration file has been created successfully.")
