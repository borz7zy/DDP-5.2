"""
Генерирует пустой файл для локалки на Redis коннект.
"""

import os

file_path = './scriptfiles/redis_connect.ini'

config_content = f"""
host = localhost
port = 3839
auth = auth_pass
"""

with open(file_path, 'w') as config_file:
    config_file.write(config_content)

print("The Redis configuration file has been created successfully.")
