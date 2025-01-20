fpub:dialog_login(pid, dialogid, response, listitem, string:inputtext[]){
    if (!response)
    {
        Kick(pid);
        return 1;
    }
    if (PassControl(inputtext) == 0)
    {
        SendClientMessage(pid, COLOR_VIOLET, ""NS" {FFFFFF}В пароле можно использовать ТОЛЬКО латинские");
        SendClientMessage(pid, COLOR_VIOLET, ""NS" {FFFFFF}символы: от a до z , от A до Z , и цифры от 0 до 9 !");
        DialogLoginShow(pid);
        return 1;
    }
    if (strlen(inputtext) < 6) return DialogLoginShow(pid);
    new hashed_pass[65];
    SHA256_Hash(inputtext, PlayerInfo[pid][pHASH], hashed_pass, 65);
    if (strcmp(PlayerInfo[pid][pKey], hashed_pass) == 0)
    {
        SendClientMessage(pid, COLOR_VIOLET, ""NS"{FFFFFF} Вы успешно авторизировались!");
        new query[256];
        mysql_format(ServerDB, query, sizeof(query), "SELECT * FROM `players` WHERE `PlayerName`='%s' LIMIT 1", PlayerInfo[pid][pName]);
        mysql_tquery(ServerDB, query, "OnPlayerLogin", "i", pid);
    }
    else
    {
        PlayerInfo[pid][pPodbor]++;
        if (5 - PlayerInfo[pid][pPodbor] == 0)
        {
            SendClientMessage(pid, COLOR_VIOLET, ""NS"{FFFFFF} Вы были кикнуты за подбор пароля!");
            Kick(pid);
            return 1;
        }
        DialogLoginShow(pid);
        SendClientMessage(pid, COLOR_VIOLET, ""NS"{FFFFFF}Вы ввели неверный пароль!");
        new string[144];
        format(string, 64, "%s{FFFFFF} У Вас осталось %d попытки!", NS, 5 - PlayerInfo[pid][pPodbor]);
        SendClientMessage(pid, COLOR_VIOLET, string);
    }
    return 1;
}

stock DialogLoginShow(playerid)
{
    new string[1024];
    format(string, sizeof(string), "{FFFFFF}Участились взломы игровых аккаунтов игроков!\
	\n{FFFFFF}Не станьте жертвой мошенников, не вводите свой пароль на других проектах!\
	\n{FFFFFF}Администрация {8F30E4}DDP сервера {FFFFFF}- не несёт ответственности за потеряные аккаунты.\
	\n\n{FFFFFF}Ваш ник: {8F30E4}%s.\
	\n{FFFFFF}Введите свой пароль в поле ниже:", PlayerInfo[playerid][pName]);
    
    Dialog_ShowCallback(playerid, using public dialog_login<iiiis>, DIALOG_STYLE_INPUT, "{8F30E4}>>[АВТОРИЗАЦИЯ НА DREAMS]<<", string, "Войти", "Отмена");

    // ShowPlayerDialog(playerid, 1, DIALOG_STYLE_INPUT, "{8F30E4}>>[АВТОРИЗАЦИЯ НА DREAMS]<<", string, "Войти", "Отмена");
    return 1;
}