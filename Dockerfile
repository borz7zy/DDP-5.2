#Докерфайл сам компилирует мод и сайдскрипты.
#Если меняете название мода или сайдскрипты, или добавляете новые,
# то добавляйте изменения и сюда!!!

FROM ubuntu:24.04

RUN dpkg --add-architecture i386 && apt-get update && apt-get install -y lib32gcc-s1 libstdc++6:i386 libc6:i386 && apt-get clean && rm -rf /var/lib/apt/lists/*

WORKDIR /samp

COPY . .

WORKDIR /

RUN ./samp/compiler/linux/pawncc /samp/gamemodes/DDP.pwn -D/samp/gamemodes '-;+' '-(+' '-d3' '-i/samp/compiler/include'
RUN ./samp/compiler/linux/pawncc /samp/filterscripts/mapping.pwn -D/samp/filterscripts '-;+' '-(+' '-d3' '-i/samp/compiler/include'

WORKDIR /samp

RUN chmod +x omp-server

CMD ["./omp-server"]