#include "..\..\modules\admin_commands\alogin.inc"

//первый уровень
#include "..\..\modules\admin_commands\LVL1\a.inc"
#include "..\..\modules\admin_commands\LVL1\ans.inc"
#include "..\..\modules\admin_commands\LVL1\check.inc"
#include "..\..\modules\admin_commands\LVL1\delveh.inc"
#include "..\..\modules\admin_commands\LVL1\explode.inc"
#include "..\..\modules\admin_commands\LVL1\goto.inc"
#include "..\..\modules\admin_commands\LVL1\ip.inc"
#include "..\..\modules\admin_commands\LVL1\jail.inc"
#include "..\..\modules\admin_commands\LVL1\kick.inc"
#include "..\..\modules\admin_commands\LVL1\mute.inc"
#include "..\..\modules\admin_commands\LVL1\o.inc"
#include "..\..\modules\admin_commands\LVL1\offspec.inc"
#include "..\..\modules\admin_commands\LVL1\setarmor.inc"
#include "..\..\modules\admin_commands\LVL1\sethp.inc"
#include "..\..\modules\admin_commands\LVL1\slap.inc"
#include "..\..\modules\admin_commands\LVL1\spec.inc"
#include "..\..\modules\admin_commands\LVL1\unjail.inc"
#include "..\..\modules\admin_commands\LVL1\unmute.inc"
#include "..\..\modules\admin_commands\LVL1\veh.inc"

//второй уровень
#include "..\..\modules\admin_commands\LVL2\ban.inc"
#include "..\..\modules\admin_commands\LVL2\banip.inc"
#include "..\..\modules\admin_commands\LVL2\freeze.inc"
#include "..\..\modules\admin_commands\LVL2\gethere.inc"
#include "..\..\modules\admin_commands\LVL2\givegun.inc"
#include "..\..\modules\admin_commands\LVL2\live.inc"
#include "..\..\modules\admin_commands\LVL2\respcars.inc"
#include "..\..\modules\admin_commands\LVL2\setskin.inc"
#include "..\..\modules\admin_commands\LVL2\takegun.inc"
#include "..\..\modules\admin_commands\LVL2\unfreeze.inc"
#include "..\..\modules\admin_commands\LVL2\cc.inc"

//третий уровень
#include "..\..\modules\admin_commands\LVL3\fo.inc"
#include "..\..\modules\admin_commands\LVL3\tpto.inc"
#include "..\..\modules\admin_commands\LVL3\unban.inc"
#include "..\..\modules\admin_commands\LVL3\unbanip.inc"
#include "..\..\modules\admin_commands\LVL3\offban.inc"

//четвертый уровень
#include "..\..\modules\admin_commands\LVL4\makeadmin.inc"
#include "..\..\modules\admin_commands\LVL4\blockadmin.inc"
#include "..\..\modules\admin_commands\LVL4\makevip.inc"
#include "..\..\modules\admin_commands\LVL4\pmread.inc"
#include "..\..\modules\admin_commands\LVL4\cmdscan.inc"
#include "..\..\modules\admin_commands\LVL4\acread.inc"

CMD:ahelp(playerid){
	if(AI[playerid][aLevel] < 1) return 1;
	new str[4096];
	format(str, sizeof(str), "{CCFF00}1LVL\
	\n\n{FF0000}/a - {FFFFFF}Админ чат");
	format(str, sizeof(str), "%s\n{FF0000}/ans - {FFFFFF}дать ответ игроку от имени админа", str);
	//format(str, sizeof(str), "%s\n{FF0000}/check.inc"
	format(str, sizeof(str), "%s\n{FF0000}/acread - {FFFFFF}вкл/откл уведомления о читах", str);
	format(str, sizeof(str), "%s\n{FF0000}/delveh - {FFFFFF}удалить админ транспорт", str);
	format(str, sizeof(str), "%s\n{FF0000}/explode - {FFFFFF}взорвать игрока", str);
	format(str, sizeof(str), "%s\n{FF0000}/goto - {FFFFFF}телепортироваться к игроку", str);
	format(str, sizeof(str), "%s\n{FF0000}/ip - {FFFFFF}узнать IP игрока", str);
	format(str, sizeof(str), "%s\n{FF0000}/jail - {FFFFFF}посадить игрока в тюрьму", str);
	format(str, sizeof(str), "%s\n{FF0000}/kick - {FFFFFF}кикнуть игрока", str);
	format(str, sizeof(str), "%s\n{FF0000}/mute - {FFFFFF}заткнуть игрока", str);
	format(str, sizeof(str), "%s\n{FF0000}/o - {FFFFFF}написать в чат с выделением", str);
	format(str, sizeof(str), "%s\n{FF0000}/specoff - {FFFFFF}отключить слежку", str);
	format(str, sizeof(str), "%s\n{FF0000}/setarmor - {FFFFFF}установить броню", str);
	format(str, sizeof(str), "%s\n{FF0000}/sethp - {FFFFFF}установить здоровье", str);
	format(str, sizeof(str), "%s\n{FF0000}/slap - {FFFFFF}пнуть игрока", str);
	format(str, sizeof(str), "%s\n{FF0000}/spec - {FFFFFF}следить за игроком", str);
	format(str, sizeof(str), "%s\n{FF0000}/unjail - {FFFFFF}освободить игрока", str);
	format(str, sizeof(str), "%s\n{FF0000}/unmute - {FFFFFF}разоткнуть игрока", str);
	format(str, sizeof(str), "%s\n{FF0000}/veh - {FFFFFF}заспавнить транспорт", str);
	format(str, sizeof(str), "%s\n\n{CCFF00}2LVL\n", str);
	format(str, sizeof(str), "%s\n{FF0000}/ban - {FFFFFF}забанить игрока", str);
	//format(str, sizeof(str), "%s\n{FF0000}/banip - {FFFFFF}забанить IP", str);
	format(str, sizeof(str), "%s\n{FF0000}/freeze - {FFFFFF}заморозить игрока", str);
	format(str, sizeof(str), "%s\n{FF0000}/gethere - {FFFFFF}тп к себе игрока", str);
	format(str, sizeof(str), "%s\n{FF0000}/givegun - {FFFFFF}выдать оружие", str);
	format(str, sizeof(str), "%s\n{FF0000}/live - {FFFFFF}админ бессмертие", str);
	format(str, sizeof(str), "%s\n{FF0000}/respcars - {FFFFFF}зареспавнить транспорт", str);
	format(str, sizeof(str), "%s\n{FF0000}/setskin - {FFFFFF}установить скин", str);
	format(str, sizeof(str), "%s\n{FF0000}/takegun - {FFFFFF}отобрать оружие", str);
	format(str, sizeof(str), "%s\n{FF0000}/unfreeze - {FFFFFF}разморозить игрока", str);
	format(str, sizeof(str), "%s\n{FF0000}/cc - {FFFFFF}очистить чат", str);
	format(str, sizeof(str), "%s\n\n{CCFF00}3LVL\n", str);
	format(str, sizeof(str), "%s\n{FF0000}/fo - {FFFFFF}написать от имени сервера", str);
	format(str, sizeof(str), "%s\n{FF0000}/tpto - {FFFFFF}телепортироваться по координатам", str);
	format(str, sizeof(str), "%s\n{FF0000}/unban - {FFFFFF}разбанить игрока", str);
	format(str, sizeof(str), "%s\n{FF0000}/verifyclan - {FFFFFF}верифицировать клан", str);
	//format(str, sizeof(str), "%s\n{FF0000}/unbanip - {FFFFFF}разбанить IP", str);
	format(str, sizeof(str), "%s\n{FF0000}/offban - {FFFFFF}забанить аккаунт игрока", str);
	format(str, sizeof(str), "%s\n\n{CCFF00}4LVL\n", str);
	format(str, sizeof(str), "%s\n{FF0000}/makeadmin - {FFFFFF}выдать админку", str);
	format(str, sizeof(str), "%s\n{FF0000}/blockadmin - {FFFFFF}отжать админку", str);
	format(str, sizeof(str), "%s\n{FF0000}/makevip - {FFFFFF}выдать/забрать VIP", str);
	format(str, sizeof(str), "%s\n{FF0000}/pmread - {FFFFFF}читать PM игроков", str);
	format(str, sizeof(str), "%s\n{FF0000}/cmdscan - {FFFFFF}читать вводимые команды игроками", str);
	ShowPlayerDialog(playerid, DIALOG_ZERO, DIALOG_STYLE_MSGBOX, ">>[Помощь по админке]<<", str, "OK", "");
	return 1;
}