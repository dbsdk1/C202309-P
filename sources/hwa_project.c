#include "hwa_project.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ErrorDetect(int user_num, int limit_num) {
  int check=1;
  if (user_num > limit_num || user_num <= 0) {
    check = 1;
    printf("잘못된 입력입니다. 1~%d 사이의 숫자를 입력해주세요!\n", limit_num);
    // 조건파악
  } else {
    check = 0;
  }
  return check;
}

void AddHwaInfo(struct HwaInfo* hwa) {
  printf("화장품 브랜드를 입력하세요.(띄어쓰기 없이 입력): ");
  char temp[300];
  scanf_s("%s", temp, (int)sizeof(temp));
  hwa->brandname = (char*)malloc((strlen(temp) + 1) * sizeof(char));
  strcpy_s(hwa->brandname, strlen(temp) + 1, temp);

  printf("화장품 이름을 입력하세요.(띄어쓰기 없이 입력): ");
  scanf_s("%s", temp, (int)sizeof(temp));
  hwa->name = (char*)malloc((strlen(temp) + 1) * sizeof(char));
  strcpy_s(hwa->name, strlen(temp) + 1, temp);

  printf("별점을 입력하세요(5점 만점): ");
  scanf_s("%f", &hwa->star);

  printf("메모를 입력하세요(띄어쓰기 없이 입력): ");
  scanf_s("%s", temp, (int)sizeof(temp));
  hwa->write = (char*)malloc((strlen(temp) + 1) * sizeof(char));
  strcpy_s(hwa->write, strlen(temp) + 1, temp);
}

void DisplayHwaInfo(const struct HwaInfo* hwa, int count) {
  printf("[화장품 목록]\n");
  for (int i = 0; i < count; i++) {
    printf("%d. %s | %s (%.1f/5)\n", i + 1, hwa[i].brandname, hwa[i].name,
           hwa[i].star);
    printf("%s\n", hwa[i].write);  // 한줄평 출력
  }
}
void ChangeHwaInfo(struct HwaInfo* hwa, int num) {
  char temp[300];
  if (num == 1) {
    printf("화장품 브랜드를 입력하세요.(띄어쓰기 없이 입력): ");
    scanf_s("%s", temp, (int)sizeof(temp));
    hwa->brandname = (char*)malloc((strlen(temp) + 1) * sizeof(char));
    strcpy_s(hwa->brandname, strlen(temp) + 1, temp);
  }
  if (num == 2) {
    printf("화장품 이름을 입력하세요.(띄어쓰기 없이 입력): ");
    scanf_s("%s", temp, (int)sizeof(temp));
    hwa->name = (char*)malloc((strlen(temp) + 1) * sizeof(char));
    strcpy_s(hwa->name, strlen(temp) + 1, temp);
  }
  if (num == 3) {
    printf("별점을 입력하세요(5점 만점): ");
    scanf_s("%f", &hwa->star);
  }
  if (num == 4) {
    printf("메모를 입력하세요(띄어쓰기 없이 입력): ");
    scanf_s("%s", temp, (int)sizeof(temp));
    hwa->write = (char*)malloc((strlen(temp) + 1) * sizeof(char));
    strcpy_s(hwa->write, strlen(temp) + 1, temp);
  }
}

void SubHwaInfo(struct HwaInfo* hwa, int count, int delete) {
  printf("%s | %s 화장품을 삭제할게요.\n", hwa[delete].brandname,
         hwa[delete].name);

  free(hwa[delete].brandname);
  free(hwa[delete].name);
  free(hwa[delete].write);

  for (int i = delete; i < count; i++) {
    hwa[i] = hwa[i + 1];
  }
  hwa[count - 1].brandname = NULL;
  hwa[count - 1].name = NULL;
  hwa[count - 1].write = NULL;
}

void Freemalloc(struct HwaInfo* hwa, int count) {
  for (int i = 0; i < count; i++) {
    free(hwa[i].brandname);
    free(hwa[i].name);
    free(hwa[i].write);
  }
}

void MedCalculator(int* med_check, int* Month, int* Day) {
  char one = ' ';

  printf(
      "여드름약을 먹거나 바르고 계신가요? 맞다면 y를, 틀리면 n을 입력해주세요. "
      "이 정보는 약 알리미 기능에 사용됩니다!\n");
  scanf_s(" %c", &one, 1);
  getchar();
  if (one == 'y' || one == 'Y') {
    int med;
    printf("약 먹는(바르는) 주기가 어떻게 되나요?\n1. 매일 2. 이틀 3. 기타\n");
    scanf_s("%d", &med);

    if (med == 1) {
      printf("답변 감사합니다 :)\n");
      *med_check = 1;
    } else if (med == 2) {
      printf("답변 감사합니다 :)\n");
      printf("날짜 정보를 수집할게요!\n");
      printf("오늘 월을 입력하세요: ");
      scanf_s("%d", Month);
      printf("일을 입력하세요: ");
      scanf_s("%d", Day);
      *med_check = 2;
      printf(
          "앞으로 약을 먹거나 발랐다면 메뉴 번호인 7번을 입력해주세요! 약 "
          "알리미에 날짜 계산이 실시간 "
          "반영되게 됩니다.\n");
    } else if (med == 3) {
      printf(
          "매일, 이틀 외는 알림기능을 지원하고 "
          "있지 않습니다.\n");
      *med_check = 0;
    } else {
      printf("잘못된 입력입니다. 약 설정 메뉴에서 다시 설정해주세요.\n");
    }
  } else {
    *med_check = 0;
  }
}
void SkinTypeHwa(char* skin_type) {
  if (strcmp(skin_type, "지성") == 0) {
    printf("[지성 피부]\n");
    printf("1. 독도토너\n2. 에스네이처 아쿠아 오아시스 수분크림\n");
  } else if (strcmp(skin_type, "복합성") == 0) {
    printf("[중성(복합성) 피부]\n");
    printf(
        "1. 이즈앤트리 초저분자 히알루론산 토너\n2. 메이크프렘 인테카 "
        "수분크림\n");
  } else if (strcmp(skin_type, "건성") == 0) {
    printf("[건성 피부]\n");
    printf("1. 일리윤 더마 스킨\n2. 토리든 솔리드인 세라마이드 크림\n");
  } else {
    printf("먼저 피부타입 진단을 하시면 그에 맞는 화장품을 추천드려요.\n");
  }
}