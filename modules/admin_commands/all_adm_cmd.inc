#include "..\..\modules\admin_commands\alogin.inc"

//������ �������
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

//������ �������
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

//������ �������
#include "..\..\modules\admin_commands\LVL3\fo.inc"
#include "..\..\modules\admin_commands\LVL3\tpto.inc"
#include "..\..\modules\admin_commands\LVL3\unban.inc"
#include "..\..\modules\admin_commands\LVL3\unbanip.inc"
#include "..\..\modules\admin_commands\LVL3\offban.inc"

//��������� �������
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
	\n\n{FF0000}/a - {FFFFFF}����� ���");
	format(str, sizeof(str), "%s\n{FF0000}/ans - {FFFFFF}���� ����� ������ �� ����� ������", str);
	//format(str, sizeof(str), "%s\n{FF0000}/check.inc"
	format(str, sizeof(str), "%s\n{FF0000}/acread - {FFFFFF}���/���� ����������� � �����", str);
	format(str, sizeof(str), "%s\n{FF0000}/delveh - {FFFFFF}������� ����� ���������", str);
	format(str, sizeof(str), "%s\n{FF0000}/explode - {FFFFFF}�������� ������", str);
	format(str, sizeof(str), "%s\n{FF0000}/goto - {FFFFFF}����������������� � ������", str);
	format(str, sizeof(str), "%s\n{FF0000}/ip - {FFFFFF}������ IP ������", str);
	format(str, sizeof(str), "%s\n{FF0000}/jail - {FFFFFF}�������� ������ � ������", str);
	format(str, sizeof(str), "%s\n{FF0000}/kick - {FFFFFF}������� ������", str);
	format(str, sizeof(str), "%s\n{FF0000}/mute - {FFFFFF}�������� ������", str);
	format(str, sizeof(str), "%s\n{FF0000}/o - {FFFFFF}�������� � ��� � ����������", str);
	format(str, sizeof(str), "%s\n{FF0000}/specoff - {FFFFFF}��������� ������", str);
	format(str, sizeof(str), "%s\n{FF0000}/setarmor - {FFFFFF}���������� �����", str);
	format(str, sizeof(str), "%s\n{FF0000}/sethp - {FFFFFF}���������� ��������", str);
	format(str, sizeof(str), "%s\n{FF0000}/slap - {FFFFFF}����� ������", str);
	format(str, sizeof(str), "%s\n{FF0000}/spec - {FFFFFF}������� �� �������", str);
	format(str, sizeof(str), "%s\n{FF0000}/unjail - {FFFFFF}���������� ������", str);
	format(str, sizeof(str), "%s\n{FF0000}/unmute - {FFFFFF}���������� ������", str);
	format(str, sizeof(str), "%s\n{FF0000}/veh - {FFFFFF}���������� ���������", str);
	format(str, sizeof(str), "%s\n\n{CCFF00}2LVL\n", str);
	format(str, sizeof(str), "%s\n{FF0000}/ban - {FFFFFF}�������� ������", str);
	//format(str, sizeof(str), "%s\n{FF0000}/banip - {FFFFFF}�������� IP", str);
	format(str, sizeof(str), "%s\n{FF0000}/freeze - {FFFFFF}���������� ������", str);
	format(str, sizeof(str), "%s\n{FF0000}/gethere - {FFFFFF}�� � ���� ������", str);
	format(str, sizeof(str), "%s\n{FF0000}/givegun - {FFFFFF}������ ������", str);
	format(str, sizeof(str), "%s\n{FF0000}/live - {FFFFFF}����� ����������", str);
	format(str, sizeof(str), "%s\n{FF0000}/respcars - {FFFFFF}������������ ���������", str);
	format(str, sizeof(str), "%s\n{FF0000}/setskin - {FFFFFF}���������� ����", str);
	format(str, sizeof(str), "%s\n{FF0000}/takegun - {FFFFFF}�������� ������", str);
	format(str, sizeof(str), "%s\n{FF0000}/unfreeze - {FFFFFF}����������� ������", str);
	format(str, sizeof(str), "%s\n{FF0000}/cc - {FFFFFF}�������� ���", str);
	format(str, sizeof(str), "%s\n\n{CCFF00}3LVL\n", str);
	format(str, sizeof(str), "%s\n{FF0000}/fo - {FFFFFF}�������� �� ����� �������", str);
	format(str, sizeof(str), "%s\n{FF0000}/tpto - {FFFFFF}����������������� �� �����������", str);
	format(str, sizeof(str), "%s\n{FF0000}/unban - {FFFFFF}��������� ������", str);
	format(str, sizeof(str), "%s\n{FF0000}/verifyclan - {FFFFFF}�������������� ����", str);
	//format(str, sizeof(str), "%s\n{FF0000}/unbanip - {FFFFFF}��������� IP", str);
	format(str, sizeof(str), "%s\n{FF0000}/offban - {FFFFFF}�������� ������� ������", str);
	format(str, sizeof(str), "%s\n\n{CCFF00}4LVL\n", str);
	format(str, sizeof(str), "%s\n{FF0000}/makeadmin - {FFFFFF}������ �������", str);
	format(str, sizeof(str), "%s\n{FF0000}/blockadmin - {FFFFFF}������ �������", str);
	format(str, sizeof(str), "%s\n{FF0000}/makevip - {FFFFFF}������/������� VIP", str);
	format(str, sizeof(str), "%s\n{FF0000}/pmread - {FFFFFF}������ PM �������", str);
	format(str, sizeof(str), "%s\n{FF0000}/cmdscan - {FFFFFF}������ �������� ������� ��������", str);
	ShowPlayerDialog(playerid, DIALOG_ZERO, DIALOG_STYLE_MSGBOX, ">>[������ �� �������]<<", str, "OK", "");
	return 1;
}