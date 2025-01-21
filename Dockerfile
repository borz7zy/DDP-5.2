#Докерфайл сам компилирует мод и сайдскрипты.
#Если меняете название мода или сайдскрипты, или добавляете новые,
# то добавляйте изменения и сюда!!!

FROM ubuntu:24.04
#ставим зависимости
RUN dpkg --add-architecture i386 && \
    apt-get update && apt-get install -y lib32gcc-s1 libstdc++6:i386 libc6:i386 python3 && \
    apt-get clean && rm -rf /var/lib/apt/lists/*

#копируем в директорию samp
WORKDIR /samp
COPY . .

#выходим в корень и билдим павн исходники 
# (увы компиль поддерживает только полный путь, относительный не сработал)
WORKDIR /
RUN ./samp/compiler/linux/pawncc '/samp/gamemodes/DDP.pwn' '-D/samp/gamemodes' '-;+' '-(+' '-d3' '-\\' '-O2' '-C+' '-Z+' '-i/samp/compiler/include'
RUN ./samp/compiler/linux/pawncc '/samp/filterscripts/mapping.pwn' '-D/samp/filterscripts' '-;+' '-(+' '-d3' '-\\' '-O2' '-C+' '-Z+' '-i/samp/compiler/include'

#идем назад в директорию samp
WORKDIR /samp

#передаем хостовые переменные окружения
#generate_mysql.py
ARG DDP_MYSQL_HOST
ENV DDP_MYSQL_HOST=${DDP_MYSQL_HOST:-localhost}
ARG DDP_MYSQL_USER
ENV DDP_MYSQL_USER=${DDP_MYSQL_USER:-root}
ARG DDP_MYSQL_PASS
ENV DDP_MYSQL_PASS=${DDP_MYSQL_PASS:-123456}
ARG DDP_MYSQL_DTBS
ENV DDP_MYSQL_DTBS=${DDP_MYSQL_DTBS:-database}
ARG DDP_MYSQL_PORT
ENV DDP_MYSQL_PORT=${DDP_MYSQL_PORT:-3306}
#get_env_params.py
ARG DDP_RCON_PASSWORD
ENV DDP_RCON_PASSWORD=${DDP_RCON_PASSWORD:-jnjnjkoasdkjNDUSHYASD9n2}
ARG DDP_NETWORK_PORT
ENV DDP_NETWORK_PORT=${DDP_NETWORK_PORT:-7777}
ARG DDP_WEBSITE_LINK
ENV DDP_WEBSITE_LINK=${DDP_WEBSITE_LINK:-https://vk.com/rds.energy}
ARG DDP_SERVER_PASSWORD
ENV DDP_SERVER_PASSWORD=${DDP_SERVER_PASSWORD:-none}
#generate_redis.py
ARG DDP_REDIS_HOST
ENV DDP_REDIS_HOST=${DDP_REDIS_HOST:-localhost}
ARG DDP_REDIS_PORT
ENV DDP_REDIS_PORT=${DDP_REDIS_PORT:-3839}
ARG DDP_REDIS_AUTH
ENV DDP_REDIS_AUTH=${DDP_REDIS_AUTH:-auth_pass}

#запускаем питоновские скрипты генерации
RUN python3 generate_mysql.py
RUN python3 get_env_params.py

#даем права на запуск и запускаем
RUN chmod +x omp-server
CMD ["./omp-server"]