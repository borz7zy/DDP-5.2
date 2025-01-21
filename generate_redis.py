"""
Скрипт выполняет заполнение файла конфигурации подключения к Redis и его форкам,
 беря значения из переменного окружения.
"""

import os

file_path = './scriptfiles/redis_connect.ini'

redis_host = os.getenv('DDP_REDIS_HOST')
redis_port = os.getenv('DDP_REDIS_PORT')
redis_auth = os.getenv('DDP_REDIS_AUTH')

if not redis_host or not redis_port or not redis_auth:
    raise ValueError("[REDIS]: One of the required environment variable values is not set!")

config_content = f"""
host = {redis_host}
port = {int(redis_port)}
auth = {redis_auth}
"""

with open(file_path, 'w') as config_file:
    config_file.write(config_content)

print("The Redis configuration file has been created successfully.")
