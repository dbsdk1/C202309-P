#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define yeol 100
#define bunho 20

char save[bunho][yeol] = {""};
int type[5];
int count = 0;

struct HwaInfo {
  char* brandname;
  char* name;
  float star;
  char* write;
};

void addHwaInfo(struct HwaInfo* hwa);
void displayHwaInfo(const struct HwaInfo* hwa, int count);

int main() {
  char one;
  printf("피부관리 프로그램 ver1.0 \n");
  printf("초기 설정 단계입니다!\n");
  printf(
      "여드름약을 먹거나 바르고 계신가요? 맞다면 y를, 틀리면 n을 입력해주세요. "
      "이 정보는 약 알리미 기능에 사용됩니다!\n");  // 함수화 시키고 설정6번으로
                                                    // 추가시켜서 함수로
                                                    // 만들어서 불러오기 ㄱ
  scanf_s("%c", &one, 1);

  while (1) {
    int choice = 0;
    // char med[20] = "맞습니다";  //동적 고려
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
      int sum = 0;
      printf("피부타입 진단을 시작할게요 :)\n");
      printf("피부타입은 크게 지성, 복합성(중성), 건성으로 나누어져요!\n");
      printf("다음 보기들을 보고 자신의 피부와 가까운 것을 고르면 됩니다.\n");
      printf(
          "1. 세수하고 나와서 아무것도 안바른 상태로 시간이 지나도 건조하지가 "
          "않다. 2. 세수하고 아무것도 안바른다면 얼굴이 건조하고 당기는 "
          "편이다.\n");
      scanf_s("%d", &type[0]);
      printf(
          "1. 오후가 되면 얼굴에 기름이 뜨고 반짝거린다. 2. 오후가 되어도 "
          "아침과 피부상태가 똑거나 기름이 거의 없다.\n");
      scanf_s("%d", &type[1]);
      printf(
          "1. 가을겨울에도 피부의 건조함을 느끼지 못한다. 2. 가을겨울은 피부가 "
          "다른 계절보다 건조해진다.\n");
      scanf_s("%d", &type[2]);
      printf(
          "1. 기름종이를 사용했을 때 기름이 잔뜩 흡수된다. 2. 기름종이를 "
          "썼는데 "
          "기름종이가 뽀송하다. (기름종이가 없다면 깨끗한 손으로 얼굴을 "
          "만져보고 묻은 양을 확인해보세요)\n");
      scanf_s("%d", &type[3]);
      printf("1. 여드름이 많이 나있다. 2. 여드름이 없는 편이다.\n");
      scanf_s("%d", &type[4]);

      for (int i = 0; i < 5; i++) {
        sum += *(type + i);
      }
      if (sum <= 6) {
        printf("피부 타입 진단 결과는 지성입니다!\n");
        printf(
            "지성은 일반적으로 유분(기름)이 많은 피부입니다. 꾸덕하거나 잘 "
            "흡수되지 않는 무거운 기초화장품을 사용하면 여드름이 더 심해지니 "
            "주의하세요!\n");
      } else if (sum <= 8) {
        printf("피부 타입 진단 결과는 중성(복합성)입니다!\n");
        printf("~~\n");
      } else {
        printf("피부 타입 진단 결과는 건성입니다!\n");
        printf("건성은 ~\n");
      }  // 함수로 만들기

    } else if (choice == 2) {
      int num = 0;
      struct HwaInfo
          hwa_save[bunho];  // 구조체에 대한 정의하기 (브랜드랑 이름 저장)

      displayHwaInfo(hwa_save, count);
      printf("-------------------\n");

      printf("1. 화장품 추가\n2. 화장품 수정\n3. 나가기\n");
      scanf_s("%d", &num);
      if (num == 1) {
        if (count < bunho) {
          addHwaInfo(&hwa_save[count]);  // 포인터
          count++;
        } else {
          printf("화장품 저장소가 꽉 찼어요. (최대 20개까지 저장 가능)\n");
        }

      } else if (num == 2) {
      } else if (num == 3) {
      }
    } else if (choice == 3) {
      int num = 0;
      printf(
          "1. 피부 일기 쓰기\n2. 피부 일기 수정\n3. 피부 "
          "일기 보기\n");
      scanf_s("%d", &num);
      if (num == 1) {
        int month = 0;
        int day = 0;
        printf("월을 입력하세요.(1~12)\n");
        scanf_s("%d", &month);
        printf("일을 입력하세요.(1~31)\n");
        scanf_s("%d", &day);
        // 파일입출력 ~
      } else if (num == 2) {
        int num = 0;
        printf("1. 날짜수정\n2. 일기내용수정\n");
        scanf_s("%d", &num);

      } else if (num == 3) {
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

void addHwaInfo(struct HwaInfo* hwa) {
  printf("화장품 브랜드를 입력하세요.(띄어쓰기 없이 입력): ");
  char temp[100];
  scanf_s("%s", temp, (int)sizeof(temp));
  hwa->brandname = (char*)malloc((strlen(temp) + 1) * sizeof(char));
  strcpy_s(hwa->brandname, strlen(temp) + 1, temp);

  printf("화장품 이름을 입력하세요.(띄어쓰기 없이 입력): ");
  scanf_s("%s", temp, (int)sizeof(temp));
  hwa->name = (char*)malloc((strlen(temp) + 1) * sizeof(char));
  strcpy_s(hwa->name, strlen(temp) + 1, temp);

  printf("별점을 입력하세요(5점 만점): ");
  scanf_s("%f", &hwa->star);

  printf("한줄평을 입력하세요: ");
}

void displayHwaInfo(const struct HwaInfo* hwa, int count) {
  printf("[화장품 목록]\n");
  for (int i = 0; i < count; i++) {
    printf("%d. %s | %s (%.1f/5)\n", i + 1, hwa[i].brandname, hwa[i].name,
           hwa[i].star);
    // printf("%s"); 한줄평 출력
  }
}
// 할일 동적메모리 free