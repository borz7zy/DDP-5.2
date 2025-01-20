//4884

fpub:dialog_register(pid, dialogid, response, listitem, string:inputtext[]){
    if (!response)
    {
        Kick(pid);
        return 1;
    }
    if (PassControl(inputtext) == 0)
    {
        SendClientMessage(pid, COLOR_VIOLET, ""NS" {FFFFFF}В пароле можно использовать ТОЛЬКО латинские");
        dialog_register_show(pid);
        return 1;
    }
    if (strlen(inputtext) < 6)
    {
        SendClientMessage(pid, COLOR_VIOLET, ""NS" {FFFFFF}Символов в пароле должно быть не меньше 6!");
        SendClientMessage(pid, COLOR_VIOLET, ""NS" {FFFFFF}символы: от a до z , от A до Z , и цифры от 0 до 9 !");
        dialog_register_show(pid);
        return 1;
    }
    new hashed_pass[65];
    new salt[17];
    for (new i; i < 16; i++)
    {
        switch(random(3)){
            case 0: salt[i] = random_range_int(48, 57);
            case 1: salt[i] = random_range_int(65, 90);
            case 2: salt[i] = random_range_int(97, 122);
        }
    }
    SHA256_Hash(inputtext, salt, hashed_pass, 65);
    new query[512];
    mysql_format(ServerDB, query, sizeof(query), "INSERT INTO `players` (`PlayerName`, `Pass`, `HASH`, `Money`, `Kills`, `Deaths`, `TDReg`, `Combo`, `IPAdr`, `Skin`) VALUES ('%e','%s','%e','50000','0','0','%d','1','%e','-1')", PlayerInfo[pid][pName], hashed_pass, salt, gettime(), PlayerInfo[pid][pIPAdr]);
    mysql_tquery(ServerDB, query, "OnPlayerRegistered", "is", pid, inputtext);
    PlayerInfo[pid][pTDReg] = gettime();
    return 1;
}

stock dialog_register_show(playerid)
{
    new strr[2048];
    format(strr, sizeof(strr), "{FF0000}КРАТКИЕ ПРАВИЛА СЕРВЕРА:\
    \n- {8F30E4}Запрещено использовать ники других игроков или администрации.\
    \n- {8F30E4}Запрещено оскорблять других игроков и мешать им играть.\
    \n- {8F30E4}Запрещено просить админку.\
    \n- {8F30E4}Запрещено рекламировать посторонние сайты/сервера.");
    format(strr, sizeof(strr), "%s\
    \n- {8F30E4}Запрещено убивать игроков транспортным средством (ДБ).\
    \n- {8F30E4}Запрещено матерится и флудить в чат.\
    \n- {8F30E4}Запрещено использовать любые читы, в особенности вредоносные!\
    \n- {8F30E4}Запрещена продажа чего либо, за реальные деньги.\
    \n\n{FF0000}НЕБОЛЬШОЙ FAQ ПО СЕРВЕРУ:", strr);
    format(strr, sizeof(strr), "%s\
    \n- {8F30E4}Для вызова команд сервера используйте /cmd.\
    \n- {8F30E4}На сервере присутствует удобное меню (ALT - пешком, кнопка 2 - в машине)\
    \n\n{FF0000}Придумайте сложный пароль, чтобы избежать взлома вашего аккаунта.\
    \n{FF0000}Администрация {00FFAA}DDP сервера {FF0000}- не несёт ответственности за потеряные аккаунты.\
    \n\n{FF0000}Ваш ник: {8F30E4}%s", strr, PlayerInfo[playerid][pName]);
    // ShowPlayerDialog(playerid, 0, DIALOG_STYLE_INPUT, ">>[РЕГИСТРАЦИЯ НА DREAMS]<<", strr, "Войти", "Отмена");
    Dialog_ShowCallback(playerid, using public dialog_register<iiiis>, DIALOG_STYLE_INPUT, "{8F30E4}>>[РЕГИСТРАЦИЯ НА DREAMS]<<", strr, "Войти", "Отмена");
}