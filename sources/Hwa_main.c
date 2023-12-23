#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define yeol 100
#define bunho 30
#define MAX 10000

char save[bunho][yeol] = {""};
int type[5];
int count = 0;
char line[MAX];          // 일기용
char content[MAX] = "";  // 일기용
int check = 1;
int MedCheck=0;
int month, day;


struct HwaInfo {
  char* brandname;
  char* name;
  float star;
  char* write;
};

struct HwaInfo
    hwa_save[bunho];  // 구조체에 대한 정의하기 (브랜드랑 이름 저장) 구조체 변수
void AddHwaInfo(struct HwaInfo* hwa);
void DisplayHwaInfo(const struct HwaInfo* hwa, int count);
void ChangeHwaInfo(struct HwaInfo* hwa);
void Freemalloc(struct HwaInfo* hwa, int count);
void SubHwaInfo(struct HwaInfo* hwa, int count, int delete);
int MedCalculator();


int errordetect(int user_num, int limit_num) {
  if (user_num > limit_num || user_num <= 0) {
    check = 1;
    printf("잘못된 입력입니다. 1~%d 사이의 숫자를 입력해주세요!\n", limit_num);
    // 조건파악
  } else {
    check = 0;
  }
  return check;
}

int main() {
 
  char* fileName = "./hwa_diary.txt";  // 일기 저장 txt
  FILE* file;
  printf("피부관리 프로그램 ver1.0 \n");
  printf("초기 설정 단계입니다!\n");
  int MedCheck = MedCalculator();
  
  while (1) {
    int choice = 0;

    printf("--------------------------\n");
    printf("번호를 선택해주세요!\n");
    printf(
        "1. 피부타입 진단하기\n2. 나의 화장품 서랍\n3. 오늘의 피부 일기\n4. "
        "올리브영 바로가기\n5. 여드름 관련 정보 모음zip\n");
    printf("6. 약 설정\n");
    if (MedCheck == 2) {
      printf("7. eat\n8. 프로그램 종료\n");
    } else {
      printf("7. 프로그램 종료\n");
    }
    if (MedCheck == 1) {
      printf("*오늘은 약 먹는 날이 맞습니다*\n");
    } else if (MedCheck == 2) {
      
        

      printf("*약을 먹어야 하는 다음 날짜는 %d월 %d일입니다.*\n", month, day);
    }

    printf("--------------------------\n");
    scanf_s("%d", &choice);

    if (choice == 1) {
      int sum = 0;
      printf("피부타입 진단을 시작할게요 :)\n");
      printf("피부타입은 크게 지성, 복합성(중성), 건성으로 나누어져요!\n");
      printf("다음 보기들을 보고 자신의 피부와 가까운 것을 고르면 됩니다.\n");
      do {
        printf(
            "1. 세수하고 나와서 아무것도 안바른 상태로 시간이 지나도 "
            "건조하지가 "
            "않다. 2. 세수하고 아무것도 안바른다면 얼굴이 건조하고 당기는 "
            "편이다.\n");
        scanf_s("%d", &type[0]);
        check = errordetect(*(type + 0), 2);
      } while (check);
      do {
        printf(
            "1. 오후가 되면 얼굴에 기름이 뜨고 반짝거린다. 2. 오후가 되어도 "
            "아침과 피부상태가 똑같거나 기름이 거의 없다.\n");
        scanf_s("%d", &type[1]);
        check = errordetect(*(type + 1), 2);
      } while (check);
      do {
        printf(
            "1. 가을겨울에도 피부의 건조함을 느끼지 못한다. 2. 가을겨울은 "
            "피부가 "
            "다른 계절보다 건조해진다.\n");
        scanf_s("%d", &type[2]);
        check = errordetect(*(type + 2), 2);
      } while (check);
      do {
        printf(
            "1. 기름종이를 사용했을 때 기름이 잔뜩 흡수된다. 2. 기름종이를 "
            "썼는데 기름종이가 뽀송하다. (기름종이가 없다면 깨끗한 손으로 "
            "얼굴을 만져보고 묻은 양을 확인해보세요)\n");
        scanf_s("%d", &type[3]);
        check = errordetect(*(type + 3), 2);
      } while (check);
      do {
        printf("1. 여드름이 많이 나있다. 2. 여드름이 없는 편이다.\n");
        scanf_s("%d", &type[4]);
        check = errordetect(*(type + 4), 2);
      } while (check);

      for (int i = 0; i < 5; i++) {
        sum += *(type + i);
      }
      if (sum <= 6) {
        printf("피부 타입 진단 결과는 지성입니다!\n");
        printf(
            "지성은 일반적으로 유분(기름)이 많은 피부입니다. 꾸덕하거나 잘 "
            "흡수되지 않는 무거운 기초화장품을 사용하면 여드름이 더 심해지니 "
            "주의하세요! 또한 기름종이 사용을 추천합니다.\n");
      } else if (sum <= 8) {
        printf("피부 타입 진단 결과는 중성(복합성)입니다!\n");
        printf(
            "중성은 기름이 너무 많이 나오지도, 너무 적지도 않은 피부입니다. "
            "따라서 지금 상태를 유지하는 것이 좋습니다. 시중의 화장품 대부분이 "
            "잘 맞을 것으로 보입니다.\n");
      } else {
        printf("피부 타입 진단 결과는 건성입니다!\n");
        printf(
            "건성은 얼굴에 기름이 별로 나오지 않는 피부입니다. 그렇기에 보습을 "
            "잘 해주는 것이 중요합니다. 피부가 건조해지지 않도록 꼭 "
            "기초화장품을 발라주세요.\n");
      }

    } else if (choice == 2) {
      int num = 0;

      DisplayHwaInfo(hwa_save, count);
      printf("-------------------\n");

      printf("1. 화장품 추가\n2. 화장품 수정\n3. 화장품 삭제\n4. 나가기\n");
      check = 1;
      while (check) {
        scanf_s("%d", &num);
        check = errordetect(num, 3);
      }

      if (num == 1) {
        if (count < bunho) {
          AddHwaInfo(&hwa_save[count]);  // 포인터
          count++;
        } else {
          printf("화장품 저장소가 꽉 찼어요. (최대 30개까지 저장 가능)\n");
        }

      } else if (num == 2) {
        int sujeong = 0;
        if (count == 0) {
          printf("화장품 저장소에 화장품이 없어요. \n");
        } else {
          printf("수정할 화장품 번호: ");
          check = 1;
          while (check) {
            scanf_s("%d", &sujeong);
            errordetect(sujeong, count);
          }

          ChangeHwaInfo(&hwa_save[sujeong - 1]);
        }

      } else if (num == 3) {
        int delete = 0;
        printf("삭제할 화장품 번호: ");
        check = 1;
        while (check) {
          scanf_s("%d", &delete);
          errordetect(delete, count);
        }
        SubHwaInfo(hwa_save, count, delete -1);
        count = count - 1;
      } else {
      }
    } else if (choice == 3) {
      int num = 0;
      char temp[MAX];
      fopen_s(&file, fileName, "a+");
      if (file == NULL) {
        printf("실패\n");
        return 1;
      }
      printf(
          "1. 피부 일기 쓰기\n2. 피부 일기 삭제\n3. 피부 "
          "일기 보기\n");
      scanf_s("%d", &num);
      if (num == 1) {
        int month = 0;
        int day = 0;
        printf("월을 입력하세요.(1~12)\n");
        scanf_s("%d", &month);
        printf("일을 입력하세요.(1~31)\n");
        scanf_s("%d",
                &day);  // 그냥 printf("오늘 날짜를 입력하세요:") 도 고려하기
        printf("%d월 %d일", month, day);
        fprintf(file, "%d월 %d일 ", month, day);
        printf("일기 입력(작성이 완료되면 나가기를 입력하세요): ");
        while (1) {
          scanf_s("%[^\n]", content, (int)sizeof(content));
          getchar();

          if (strcmp(content, "나가기") ==
              0) {  // 문자열 비교 같으면 0반환하는거임
            printf("일기가 저장되었습니다.\n");
            break;
          }
          fputs(content, file);
          fputs("\n", file);
        }
        fclose(file);

      } else if (num == 2) {
      } else if (num == 3) {
        while (1) {
          char* result = fgets(temp, MAX, file);
          if (result == NULL) {
            break;
          }
          printf("%s", temp);
        }
        fclose(file);
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
      MedCheck = MedCalculator();
    }

    else if (MedCheck != 2) {
      if (choice == 7) {
        printf("프로그램을 종료합니다.\n");
        Freemalloc(hwa_save, count);
        return 0;
      } else {
        errordetect(choice, 7);
      }

    } else if (MedCheck == 2) {
      if (choice = 7) {
        day += 2;  // 간격 이틀로 (고려할 거: 31 30 처럼 날짜 반복.. 배열에 담으면 되려나..?)

        if (day > 31) {
          day -= 31;  // 1일로 만들기
          month++;
          if (month > 12) {
            month = 1;
          }
        }
      
      }
      if (choice == 8) {
        printf("프로그램을 종료합니다.\n");
        Freemalloc(hwa_save, count);
        return 0;
      } else {
        errordetect(choice, 8);
      }
    }
  }
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
void ChangeHwaInfo(struct HwaInfo* hwa) {
  int num = 0;
  printf("수정할 항목을 선택하세요.\n");
  printf("1. 화장품 브랜드 2.화장품 이름 3.별점 4. 메모\n");
  scanf_s("%d", &num);
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
  hwa[count - 1].write = NULL;  // 맨 마지막 칸 없애기
}

void Freemalloc(struct HwaInfo* hwa, int count) {
  for (int i = 0; i < count; i++) {
    free(hwa[i].brandname);
    free(hwa[i].name);
    free(hwa[i].write);
  }
}



int MedCalculator() {
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
    printf("답변 감사합니다 :)\n");
    if (med == 1) {
      MedCheck = 1;
    } else if (med == 2) {
      printf("날짜 정보를 수집할게요!\n");
      printf("오늘 월을 입력하세요: ");
      scanf_s("%d", &month);
      printf("일을 입력하세요: ");
      scanf_s("%d", &day);
      MedCheck = 2;
      printf(
          "앞으로 약을 먹었다면 eat 메뉴 번호인 7번을 입력해주세요! 약 알리미에 날짜 계산이 실시간 "
          "반영되게 됩니다.\n");
    } else if (med == 3) {
      printf(
          "매일, 이틀 외는 알림기능을 지원하고 "
          "있지 않습니다.\n");
      MedCheck = 0;
    } else {
      printf("잘못된 입력입니다.");
    }
  }
  else {
      MedCheck = 0;
    }
  
  return MedCheck;

}
    // 할 일: 파일 3개 이상 만들기!!!!!!!! 함수화 시키기