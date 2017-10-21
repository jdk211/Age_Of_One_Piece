#include "stdafx.h"
#include "gameStudy.h"

void gameStudy::addImage()
{
	//유닛 이미지
	//player unit
	//루피
	IMAGEMANAGER->addFrameImage("luffy_stand", "image/unit/playerUnit/luffy/luffy_stand.bmp", 132, 65, 3, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("luffy_move", "image/unit/playerUnit/luffy/luffy_move.bmp", 472, 61, 8, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("luffy_attack1", "image/unit/playerUnit/luffy/luffy_attack1.bmp", 345, 60, 5, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("luffy_attack2", "image/unit/playerUnit/luffy/luffy_attack2.bmp", 1950, 85, 13, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("luffy_attack3", "image/unit/playerUnit/luffy/luffy_attack3.bmp", 880, 70, 11, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("luffy_attack4", "image/unit/playerUnit/luffy/luffy_attack4.bmp", 2720, 110, 17, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("luffy_attack5", "image/unit/playerUnit/luffy/luffy_attack5.bmp", 11000, 150, 22, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("luffy_die", "image/unit/playerUnit/luffy/luffy_die.bmp", 350, 54, 5, 1, true, TRANSCOLOR);
	//조로
	IMAGEMANAGER->addFrameImage("zoro_stand", "image/unit/playerUnit/zoro/zoro_stand.bmp", 200, 100, 4, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("zoro_move", "image/unit/playerUnit/zoro/zoro_move.bmp", 480, 100, 8, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("zoro_attack", "image/unit/playerUnit/zoro/zoro_attack.bmp", 900, 100, 5, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("zoro_die", "image/unit/playerUnit/zoro/zoro_die.bmp", 240, 100, 4, 1, true, TRANSCOLOR);
	//나미
	IMAGEMANAGER->addFrameImage("nami_stand", "image/unit/playerUnit/nami/nami_stand.bmp", 150, 100, 3, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("nami_move", "image/unit/playerUnit/nami/nami_move.bmp", 700, 100, 7, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("nami_attack", "image/unit/playerUnit/nami/nami_attack.bmp", 1800, 100, 12, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("nami_die", "image/unit/playerUnit/nami/nami_die.bmp", 400, 100, 4, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("nami_bullet", "image/unit/playerUnit/nami/nami_bullet.bmp", 200, 100, 4, 1, true, TRANSCOLOR);
	//쵸파
	IMAGEMANAGER->addFrameImage("chopper_stand", "image/unit/playerUnit/chopper/chopper_stand.bmp", 108, 39, 4, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("chopper_move", "image/unit/playerUnit/chopper/chopper_move.bmp", 208, 40, 8, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("chopper_attack", "image/unit/playerUnit/chopper/chopper_attack.bmp", 360, 40, 6, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("chopper_die", "image/unit/playerUnit/chopper/chopper_die.bmp", 320, 35, 4, 1, true, TRANSCOLOR);
	//로빈
	IMAGEMANAGER->addFrameImage("robin_stand", "image/unit/playerUnit/robin/robin_stand.bmp", 124, 70, 4, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("robin_move", "image/unit/playerUnit/robin/robin_move.bmp", 640, 70, 8, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("robin_attack", "image/unit/playerUnit/robin/robin_attack.bmp", 450, 75, 9, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("robin_die", "image/unit/playerUnit/robin/robin_die.bmp", 500, 70, 5, 1, true, TRANSCOLOR);
	EFFECTMANAGER->addEffect("robin_effect", "image/unit/playerUnit/robin/robin_effect.bmp", 1200, 80, 150, 80, 1, 0.2, 300);
	//브룩
	IMAGEMANAGER->addFrameImage("brook_stand", "image/unit/playerUnit/brook/brook_stand.bmp", 252, 91, 4, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("brook_move", "image/unit/playerUnit/brook/brook_move.bmp", 800, 91, 8, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("brook_attack", "image/unit/playerUnit/brook/brook_attack.bmp", 1800, 91, 10, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("brook_die", "image/unit/playerUnit/brook/brook_die.bmp", 500, 91, 5, 1, true, TRANSCOLOR);
	//쿠마
	IMAGEMANAGER->addFrameImage("kuma_stand", "image/unit/playerUnit/kuma/kuma_stand.bmp", 427, 97, 7, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("kuma_move", "image/unit/playerUnit/kuma/kuma_move.bmp", 488, 97, 8, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("kuma_attack", "image/unit/playerUnit/kuma/kuma_attack.bmp", 1690, 230, 13, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("kuma_die", "image/unit/playerUnit/kuma/kuma_die.bmp", 700, 97, 7, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("kuma_bullet", "image/unit/playerUnit/kuma/kuma_bullet.bmp", 36, 29, 1, 1, true, TRANSCOLOR);
	//상디
	IMAGEMANAGER->addFrameImage("sanji_stand", "image/unit/playerUnit/sanji/sanji_stand.bmp", 100, 67, 4, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("sanji_move", "image/unit/playerUnit/sanji/sanji_move.bmp", 608, 68, 8, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("sanji_attack", "image/unit/playerUnit/sanji/sanji_attack.bmp", 756, 66, 7, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("sanji_die", "image/unit/playerUnit/sanji/sanji_die.bmp", 304, 68, 4, 1, true, TRANSCOLOR);
	//우솝
	IMAGEMANAGER->addFrameImage("usopp_stand", "image/unit/playerUnit/usopp/usopp_stand.bmp", 304, 68, 4, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("usopp_move", "image/unit/playerUnit/usopp/usopp_move.bmp", 532, 68, 7, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("usopp_attack", "image/unit/playerUnit/usopp/usopp_attack.bmp", 1416, 68, 12, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("usopp_die", "image/unit/playerUnit/usopp/usopp_die.bmp", 1062, 68, 9, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addImage("usopp_bullet", "image/unit/playerUnit/usopp/usopp_bullet.bmp", 20, 20, true, TRANSCOLOR);
	//프랑키
	IMAGEMANAGER->addFrameImage("franky_stand", "image/unit/playerUnit/franky/franky_stand.bmp", 320, 90, 4, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("franky_move", "image/unit/playerUnit/franky/franky_move.bmp", 800, 100, 8, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("franky_attack", "image/unit/playerUnit/franky/franky_attack.bmp", 1368, 80, 9, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("franky_die", "image/unit/playerUnit/franky/franky_die.bmp", 600, 85, 5, 1, true, TRANSCOLOR);
	//핸콕
	IMAGEMANAGER->addFrameImage("hancock_stand", "image/unit/playerUnit/hancock/hancock_stand.bmp", 210, 75, 6, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("hancock_move", "image/unit/playerUnit/hancock/hancock_move.bmp", 400, 80, 8, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("hancock_attack", "image/unit/playerUnit/hancock/hancock_attack.bmp", 540, 90, 6, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("hancock_die", "image/unit/playerUnit/hancock/hancock_die.bmp", 810, 80, 9, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("hancock_bullet", "image/unit/playerUnit/hancock/hancock_bullet.bmp", 180, 20, 9, 1, true, TRANSCOLOR);

	//enemy unit
	//로브 루치
	IMAGEMANAGER->addFrameImage("lucci_stand", "image/unit/enemyUnit/lucci/lucci_stand.bmp", 66, 73, 3, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("lucci_move", "image/unit/enemyUnit/lucci/lucci_move.bmp", 400, 78, 8, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("lucci_attack", "image/unit/enemyUnit/lucci/lucci_attack.bmp", 1000, 75, 10, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("lucci_die", "image/unit/enemyUnit/lucci/lucci_die.bmp", 500, 78, 5, 1, true, TRANSCOLOR);
	//도플라밍고
	IMAGEMANAGER->addFrameImage("doflamingo_stand", "image/unit/enemyUnit/doflamingo/doflamingo_stand.bmp", 560, 80, 8, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("doflamingo_move", "image/unit/enemyUnit/doflamingo/doflamingo_move.bmp", 560, 80, 8, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("doflamingo_attack", "image/unit/enemyUnit/doflamingo/doflamingo_attack.bmp", 480, 100, 6, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("doflamingo_die", "image/unit/enemyUnit/doflamingo/doflamingo_die.bmp", 500, 80, 5, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("doflamingo_effect", "image/unit/enemyUnit/doflamingo/doflamingo_effect.bmp", 1100, 120, 11, 1, true, TRANSCOLOR);
	EFFECTMANAGER->addEffect("doflamingo_effect", "image/unit/enemyUnit/doflamingo/doflamingo_effect.bmp", 1100, 120, 100, 120, 1, 0.2, 300);
	//아카이누
	IMAGEMANAGER->addFrameImage("akainu_stand", "image/unit/enemyUnit/akainu/akainu_stand.bmp", 132, 78, 3, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("akainu_move", "image/unit/enemyUnit/akainu/akainu_move.bmp", 488, 79, 8, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("akainu_attack", "image/unit/enemyUnit/akainu/akainu_attack.bmp", 4830, 125, 23, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("akainu_die", "image/unit/enemyUnit/akainu/akainu_die.bmp", 385, 71, 5, 1, true, TRANSCOLOR);
	//키자루
	IMAGEMANAGER->addFrameImage("kizaru_stand", "image/unit/enemyUnit/kizaru/kizaru_stand.bmp", 160, 80, 4, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("kizaru_move", "image/unit/enemyUnit/kizaru/kizaru_move.bmp", 480, 80, 8, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("kizaru_attack", "image/unit/enemyUnit/kizaru/kizaru_attack.bmp", 725, 80, 5, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("kizaru_die", "image/unit/enemyUnit/kizaru/kizaru_die.bmp", 800, 80, 8, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addImage("kizaru_bullet", "image/unit/enemyUnit/kizaru/kizaru_bullet.bmp", 78, 20, true, TRANSCOLOR);
	//코비
	IMAGEMANAGER->addFrameImage("coby_stand", "image/unit/enemyUnit/coby/coby_stand.bmp", 250, 100, 5, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("coby_move", "image/unit/enemyUnit/coby/coby_move.bmp", 640, 100, 8, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("coby_attack", "image/unit/enemyUnit/coby/coby_attack.bmp", 480, 100, 6, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("coby_die", "image/unit/enemyUnit/coby/coby_die.bmp", 400, 100, 4, 1, true, TRANSCOLOR);
	//호디
	IMAGEMANAGER->addFrameImage("hody_stand", "image/unit/enemyUnit/hody/hody_stand.bmp", 472, 90, 5, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("hody_move", "image/unit/enemyUnit/hody/hody_move.bmp", 1072, 90, 8, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("hody_attack", "image/unit/enemyUnit/hody/hody_attack.bmp", 1120, 90, 7, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("hody_die", "image/unit/enemyUnit/hody/hody_die.bmp", 800, 90, 5, 1, true, TRANSCOLOR);
	//와폴
	IMAGEMANAGER->addFrameImage("wapol_stand", "image/unit/enemyUnit/wapol/wapol_stand.bmp", 472, 68, 4, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("wapol_move", "image/unit/enemyUnit/wapol/wapol_move.bmp", 944, 68, 8, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("wapol_attack", "image/unit/enemyUnit/wapol/wapol_attack.bmp", 944, 68, 8, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("wapol_die", "image/unit/enemyUnit/wapol/wapol_die.bmp", 590, 68, 5, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addImage("wapol_bullet", "image/unit/enemyUnit/wapol/wapol_bullet.bmp", 20, 20, true, TRANSCOLOR);
	EFFECTMANAGER->addEffect("wapol_effect", "image/unit/enemyUnit/wapol/wapol_effect.bmp", 320, 80, 80, 80, 1, 0.2, 300);
	EFFECTMANAGER->addEffect("wapol_effect2", "image/unit/enemyUnit/wapol/wapol_effect_2.bmp", 400, 80, 80, 80, 1, 0.2, 300);
	//스모커
	IMAGEMANAGER->addFrameImage("smoker_stand", "image/unit/enemyUnit/smoker/smoker_stand.bmp", 240, 100, 3, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("smoker_move", "image/unit/enemyUnit/smoker/smoker_move.bmp", 640, 100, 8, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("smoker_attack", "image/unit/enemyUnit/smoker/smoker_attack.bmp", 600, 100, 6, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("smoker_die", "image/unit/enemyUnit/smoker/smoker_die.bmp", 750, 100, 5, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("smoker_bullet", "image/unit/enemyUnit/smoker/smoker_bullet.bmp", 1500, 100, 10, 1, true, TRANSCOLOR);
	//시키
	IMAGEMANAGER->addFrameImage("shiki_stand", "image/unit/enemyUnit/shiki/shiki_stand.bmp", 420, 90, 6, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("shiki_move", "image/unit/enemyUnit/shiki/shiki_move.bmp", 560, 90, 8, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("shiki_attack", "image/unit/enemyUnit/shiki/shiki_attack.bmp", 640, 100, 8, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("shiki_die", "image/unit/enemyUnit/shiki/shiki_die.bmp", 1000, 100, 10, 1, true, TRANSCOLOR);
	//에넬
	IMAGEMANAGER->addFrameImage("enel_stand", "image/unit/enemyUnit/enel/enel_stand.bmp", 840, 100, 7, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("enel_move", "image/unit/enemyUnit/enel/enel_move.bmp", 840, 100, 7, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("enel_attack", "image/unit/enemyUnit/enel/enel_attack.bmp", 480, 100, 6, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("enel_die", "image/unit/enemyUnit/enel/enel_die.bmp", 500, 90, 5, 1, true, TRANSCOLOR);
	EFFECTMANAGER->addEffect("enel_effect", "image/unit/enemyUnit/enel/enel_effect.bmp", 420, 110, 70, 110, 1, 0.2, 300);
	//검은수염
	IMAGEMANAGER->addFrameImage("blackbeard_stand", "image/unit/enemyUnit/blackbeard/blackbeard_stand.bmp", 320, 80, 4, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("blackbeard_move", "image/unit/enemyUnit/blackbeard/blackbeard_move.bmp", 640, 80, 8, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("blackbeard_attack1", "image/unit/enemyUnit/blackbeard/blackbeard_attack1.bmp", 840, 80, 7, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("blackbeard_attack2", "image/unit/enemyUnit/blackbeard/blackbeard_attack2.bmp", 700, 100, 7, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("blackbeard_attack3", "image/unit/enemyUnit/blackbeard/blackbeard_attack3.bmp", 900, 100, 9, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("blackbeard_attack4", "image/unit/enemyUnit/blackbeard/blackbeard_attack4.bmp", 980, 80, 7, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("blackbeard_attack5", "image/unit/enemyUnit/blackbeard/blackbeard_attack5.bmp", 1080, 100, 12, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("blackbeard_die", "image/unit/enemyUnit/blackbeard/blackbeard_die2.bmp", 450, 75, 5, 1, true, TRANSCOLOR);
	EFFECTMANAGER->addEffect("blackbeard_effect4", "image/unit/enemyUnit/blackbeard/blackbeard_attack4_effect1.bmp", 450, 110, 90, 110, 1, 0.1, 300);
	EFFECTMANAGER->addEffect("blackbeard_effect5_1", "image/unit/enemyUnit/blackbeard/blackbeard_attack5_effect1.bmp", 2280, 40, 190, 40, 1, 0.5, 300);
	EFFECTMANAGER->addEffect("blackbeard_effect5_2", "image/unit/enemyUnit/blackbeard/blackbeard_attack5_effect2.bmp", 2112, 192, 192, 192, 1, 0.09, 300);



	//타이틀 이미지
	IMAGEMANAGER->addImage("title", "image/title_scene/title.bmp", WINSIZEX, WINSIZEY, false, false);
	IMAGEMANAGER->addFrameImage("start", "image/title_scene/button_start_frame.bmp", 320, 225, 1, 3, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("exit", "image/title_scene/button_exit_frame.bmp", 320, 225, 1, 3, true, TRANSCOLOR);

	//본진 이미지
	IMAGEMANAGER->addFrameImage("castle", "image/mainSceneBg/castle.bmp", 730, 405, 4, 3, true, TRANSCOLOR);

	//맵 배경
	IMAGEMANAGER->addImage("map", "image/mainSceneBg/map.bmp", 1600, 768, false, false);
	IMAGEMANAGER->addFrameImage("seaFrame", "image/mainSceneBg/sea_frame.bmp", 6400, 768, 4, 1, true, TRANSCOLOR);

	//HUD menu 이미지
	//돈, 경험치
	IMAGEMANAGER->addImage("coin_board", "image/hud/coin_board.bmp", 186, 129, true, TRANSCOLOR);
	IMAGEMANAGER->addImage("beri", "image/hud/beri_coin.bmp", 25, 25, true, TRANSCOLOR);
	//라인 선택 이미지
	IMAGEMANAGER->addFrameImage("selectObject", "image/hud/line_select.bmp", 200, 80, 4, 1, true, TRANSCOLOR);
	IMAGEMANAGER->addImage("lineSelect", "image/hud/selectLine.bmp", 1165, 82, false, false);
	//유닛 생성 버튼 이미지
	IMAGEMANAGER->addImage("board", "image/hud/board.bmp", 337, 129, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("luffy", "image/unit/playerUnit/luffy/luffy_wanted.bmp", 79, 348, 1, 3, true, TRANSCOLOR);
	IMAGEMANAGER->addImage("luffy_wait", "image/unit/playerUnit/luffy/luffy_wait.bmp", 32, 24, true, TRANSCOLOR);
	//1
	IMAGEMANAGER->addFrameImage("zoro", "image/unit/playerUnit/zoro/zoro_wanted.bmp", 79, 348, 1, 3, true, TRANSCOLOR);
	IMAGEMANAGER->addImage("zoro_wait", "image/unit/playerUnit/zoro/zoro_wait.bmp", 32, 24, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("nami", "image/unit/playerUnit/nami/nami_wanted.bmp", 79, 348, 1, 3, true, TRANSCOLOR);
	IMAGEMANAGER->addImage("nami_wait", "image/unit/playerUnit/nami/nami_wait.bmp", 32, 24, true, TRANSCOLOR);
	//2
	IMAGEMANAGER->addFrameImage("usopp", "image/unit/playerUnit/usopp/usopp_wanted.bmp", 79, 348, 1, 3, true, TRANSCOLOR);
	IMAGEMANAGER->addImage("usopp_wait", "image/unit/playerUnit/usopp/usopp_wait.bmp", 32, 24, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("sanji", "image/unit/playerUnit/sanji/sanji_wanted.bmp", 79, 348, 1, 3, true, TRANSCOLOR);
	IMAGEMANAGER->addImage("sanji_wait", "image/unit/playerUnit/sanji/sanji_wait.bmp", 32, 24, true, TRANSCOLOR);
	//3
	IMAGEMANAGER->addFrameImage("robin", "image/unit/playerUnit/robin/robin_wanted.bmp", 79, 348, 1, 3, true, TRANSCOLOR);
	IMAGEMANAGER->addImage("robin_wait", "image/unit/playerUnit/robin/robin_wait.bmp", 32, 24, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("chopper", "image/unit/playerUnit/chopper/chopper_wanted.bmp", 79, 348, 1, 3, true, TRANSCOLOR);
	IMAGEMANAGER->addImage("chopper_wait", "image/unit/playerUnit/chopper/chopper_wait.bmp", 32, 24, true, TRANSCOLOR);
	//4
	IMAGEMANAGER->addFrameImage("franky", "image/unit/playerUnit/franky/franky_wanted.bmp", 79, 348, 1, 3, true, TRANSCOLOR);
	IMAGEMANAGER->addImage("franky_wait", "image/unit/playerUnit/franky/franky_wait.bmp", 32, 24, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("hancock", "image/unit/playerUnit/hancock/hancock_wanted.bmp", 79, 348, 1, 3, true, TRANSCOLOR);
	IMAGEMANAGER->addImage("hancock_wait", "image/unit/playerUnit/hancock/hancock_wait.bmp", 32, 24, true, TRANSCOLOR);
	//5
	IMAGEMANAGER->addFrameImage("brook", "image/unit/playerUnit/brook/brook_wanted.bmp", 79, 348, 1, 3, true, TRANSCOLOR);
	IMAGEMANAGER->addImage("brook_wait", "image/unit/playerUnit/brook/brook_wait.bmp", 32, 24, true, TRANSCOLOR);
	IMAGEMANAGER->addFrameImage("kuma", "image/unit/playerUnit/kuma/kuma_wanted.bmp", 79, 348, 1, 3, true, TRANSCOLOR);
	IMAGEMANAGER->addImage("kuma_wait", "image/unit/playerUnit/kuma/kuma_wait.bmp", 32, 24, true, TRANSCOLOR);
}