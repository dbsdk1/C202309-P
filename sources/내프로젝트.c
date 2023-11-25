#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define yeol 50
#define bunho 20

int main() {
  printf("피부관리 프로그램 ver1.0 \n");

  while (1) {
    int choice = 0;
    // char med[20] = "맞습니다";
    printf("--------------------------\n");
    printf("번호를 선택해주세요!\n");
    printf(
        "1. 피부타입 진단하기\n2. 나의 화장품 서랍\n3. 오늘의 피부 일기\n4. "
        "올리브영 바로가기\n5. 여드름 관련 정보 모음zip\n");
    printf("6. 프로그램 종료\n");
    /*printf("오늘(날짜~)은 약 먹는 날이 %s\n", med;*/
    printf("--------------------------\n");
    scanf_s("%d", &choice);

    if (choice == 1) {
      int type1 = 0, type2 = 0, type3 = 0;
      printf("피부타입 진단을 시작할게요 :)\n");
      printf("피부타입은 크게 지성, 복합성(중성), 건성으로 나누어져요!\n");
      printf("다음 보기들을 보고 자신의 피부에 맞는 것을 고르면 됩니다.\n");
      printf("세수하고 나오면 얼굴이 건조하고 ");
      scanf_s("%d", &type1);  // 이걸 뭐로구현해야지..? 동적메모리? 한 5개 정도 질문지 만들고 1번이..? sum으로 해야하나 아하 그래야할듯;.? 함수만들어버리기?
      //배열 칸에 1, 2 각각 저장 후 for문으로 
    } else if (choice == 2) {
      int num = 0;
     
      char save[bunho][yeol] = {""};  // 동적할당 ㄱㄱㄱㄱ
      // 화장품 저장소 2차원배열 만들어서 그 안에 화장품 이름 저장하기, 목록은
      // 바로 출력하기
      for (int i = 0; i < bunho; i++) {
        if (strlen(save[i]) >= 1) {
          printf("%d. %s\n", i + 1, save[i]);
        }
        
      //그리고 저장안되면(배열 빈칸이면) 출력안되게 해야한다. -> 문자열길이함수사용!
      } 

      printf("1. 화장품 추가\n2. 나가기\n");
      scanf_s("%d", &num);
      if (num == 1) {
        printf("");
      }
    } else if (choice == 3) {
      int num = 0;
      printf(
          "1. 피부 일기 쓰기\n2. 피부 일기 수정\n3. 피부 일기 삭제\n4. 피부 "
          "일기 보기\n");
      scanf_s("%d", &num);
      if (num == 1) {
        int month = 0;
        int day = 0;
        printf("월을 입력하세요.(1~12)\n");
        scanf_s("%d", &month);
        printf("일을 입력하세요.(1~31)\n");
        scanf_s("%d", &day);  // 사용자가 1월1일 이렇게 바로 입력할 순
                              // 없을까,,,,, 안되면 이런형식으로 하자
        // 할 일: 배열에 글 저장
      } else if (num == 2) {
        // printf("날짜수정할건지 일기내용을수정할건지 고르라고 하기");
      } else if (num == 3) {
        printf("삭제할 일기의 번호를 입력하세요.");
      } else if(num==4) {
          // 배열 for문으로 불러오기
      }
    } else if (choice == 4) {
      printf(
          "올리브영 링크입니다! (링크 바로가기는 추후 업데이트 예정입니다) "
          "복사(ctrl+c) 후 주소 창에 붙여넣기(ctrl+v) 하세요\n");
      printf("www.oliveyoung.co.kr\n");
    } else if (choice == 5) {
      int num = 0;
      printf("1) 여드름에 좋은 화장품 성분들\n");
      printf("2) 기초화장품 바르는 순서?\n");
      printf("3) 좁쌀여드름과 화농성 여드름의 차이\n");
      scanf_s("%d", &num);
      if (num == 1) {
        printf(
            "'티트리' - 티트리는 진정에 매우 탁월하여 예민해진 피부에 도움을 "
            "줄 수 있습니다.\n");
        printf(
            "'병풀' - 병풀은 상처입은 호랑이가 병풀이 있는 곳에서 뒹굴어 "
            "호랑이 풀이라고도 불리며 마데카식애씨드 등의 성분이 피부 진정과 "
            "수분관리에 도움을 줍니다.\n");
      } else if (num == 2) {
        printf(
            "기초화장품은 가벼운 것부터 점차 무겁고 꾸덕한 순서로 바르면 "
            "됩니다! 간단하게 설명하면 [스킨(토너) - 앰플 - 로션 or 수분크림 - "
            "스팟연고] 순서로 바르면 됩니다. ");
        printf(
            "바를 때는 빡빡 힘줘서 바르면 안되고 살살 발라야 자극이 덜해서 "
            "트러블을 막을 수 있습니다.\n");
      } else if (num == 3) {
        printf(
            "좁쌀 여드름은 하얗고 안에 쌀알같은 것이 차있는 것이고 화농성 "
            "여드름은 염증이 생겨서 빨갛고 만지면 아프고 부어올라있는 "
            "여드름입니다.\n");
      } else {
        printf(
            "잘못된 입력입니다. 목록에 있는 번호를 입력해주세요.\n");  // +
                                                                       // while문
                                                                       // 추가해서
                                                                       // 맨처음으로안돌아가게
                                                                       // ㄱ
      }
    } else if (choice == 6) {
      printf("프로그램을 종료합니다.\n");
      return;
    } else {
      printf("잘못된 입력입니다. 1~6번 사이의 번호를 입력해주세요\n");
    }
  }
}