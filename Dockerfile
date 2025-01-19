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
RUN ./samp/compiler/linux/pawncc '/samp/gamemodes/DDP.pwn' '-D/samp/gamemodes' '-;+' '-(+' '-d3' '-i/samp/compiler/include'
RUN ./samp/compiler/linux/pawncc '/samp/filterscripts/mapping.pwn' '-D/samp/filterscripts' '-;+' '-(+' '-d3' '-i/samp/compiler/include'

#идем назад в директорию samp
WORKDIR /samp

#передаем хостовые переменные окружения
#generate_mysql.py
ENV DDP_MYSQL_HOST=$DDP_MYSQL_HOST
ENV DDP_MYSQL_USER=$DDP_MYSQL_USER
ENV DDP_MYSQL_PASS=$DDP_MYSQL_PASS
ENV DDP_MYSQL_DTBS=$DDP_MYSQL_DTBS
#get_env_params.py
ENV DDP_RCON_PASSWORD=$DDP_RCON_PASSWORD
ENV DDP_NETWORK_PORT=$DDP_NETWORK_PORT
ENV DDP_WEBSITE_LINK=$DDP_WEBSITE_LINK
ENV DDP_SERVER_PASSWORD=$DDP_SERVER_PASSWORD

RUN echo $DDP_MYSQL_HOST

#запускаем питоновские скрипты генерации
RUN python3 generate_mysql.py
RUN python3 get_env_params.py

#даем права на запуск и запускаем
RUN chmod +x omp-server
CMD ["./omp-server"]