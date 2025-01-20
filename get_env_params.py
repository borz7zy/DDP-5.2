"""
Скрипт написан больше для деплоя на разные сервисы, чтобы докер запускал этот скрипт,
 а он редачил конфигурационный файл через переменные окружения.

Я на своем впс использую coolify который автоматически может качать мод с гитхаба и деплоит в докер контейнер
"""

import json
import os

file_path = 'config.json'

with open(file_path, 'r') as file:
    data = json.load(file)

rcon_password = os.getenv('DDP_RCON_PASSWORD')
network_port = os.getenv('DDP_NETWORK_PORT')
url_link = os.getenv('DDP_WEBSITE_LINK')
server_pwd = os.getenv('DDP_SERVER_PASSWORD')

if rcon_password:
    data['rcon']['password'] = rcon_password

if network_port:
    data['network']['port'] = int(network_port)

if url_link:
    data['website'] = url_link

if server_pwd:
    data['password'] = server_pwd
    if server_pwd == "none":
        data['password'] = ""

with open(file_path, 'w') as file:
    json.dump(data, file, indent=4)

print("JSON updated!!!")
