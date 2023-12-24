#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hwa_project.h"
#define YEOL 100
#define BUNHO 30
#define MAX 10000

char save[BUNHO][YEOL] = {""};
int type[5];
int count = 0;
char line[MAX];          // 일기용
char content[MAX] = "";  // 일기용
int check = 1;
int med_check = 0;
int month, day;
int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char skin_type[10];
char temp[MAX];

struct HwaInfo hwa_save[BUNHO];

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
  MedCalculator(&med_check, &month, &day);

  while (1) {
    int choice = 0;

    printf("--------------------------\n");
    printf("번호를 선택해주세요!\n");
    printf(
        "1. 피부타입 진단하기\n2. 나의 화장품 서랍\n3. 오늘의 피부 일기\n4. "
        "올리브영 바로가기\n5. 여드름 관련 정보 모음zip\n");
    printf("6. 약 설정\n");
    if (med_check == 2) {
      printf("7. eat & splash\n8. 프로그램 종료\n");
    } else {
      printf("7. 프로그램 종료\n");
    }
    if (med_check == 1) {
      printf("*오늘은 약 먹는(바르는) 날이 맞습니다*\n");
    } else if (med_check == 2) {
      printf("*약을 먹어야(발라야) 하는 다음 날짜는 %d월 %d일입니다.*\n", month,
             day);
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
        strcpy_s(skin_type, (int)sizeof(skin_type), "지성");
      } else if (sum <= 8) {
        printf("피부 타입 진단 결과는 중성(복합성)입니다!\n");
        printf(
            "중성은 기름이 너무 많이 나오지도, 너무 적지도 않은 피부입니다. "
            "따라서 지금 상태를 유지하는 것이 좋습니다. 시중의 화장품 대부분이 "
            "잘 맞을 것으로 보입니다.\n");
        strcpy_s(skin_type, (int)sizeof(skin_type), "복합성");
      } else {
        printf("피부 타입 진단 결과는 건성입니다!\n");
        printf(
            "건성은 얼굴에 기름이 별로 나오지 않는 피부입니다. 그렇기에 보습을 "
            "잘 해주는 것이 중요합니다. 피부가 건조해지지 않도록 꼭 "
            "기초화장품을 발라주세요.\n");
        strcpy_s(skin_type, (int)sizeof(skin_type), "건성");
      }

    } else if (choice == 2) {
      int num = 0;

      DisplayHwaInfo(hwa_save, count);
      printf("-------------------\n");

      printf(
          "1. 화장품 추가\n2. 화장품 수정\n3. 화장품 삭제\n4. 화장품 "
          "추천(BETA)\n5. 나가기\n");
      check = 1;
      while (check) {
        scanf_s("%d", &num);
        check = errordetect(num, 5);
      }

      if (num == 1) {
        if (count < BUNHO) {
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
            check = errordetect(sujeong, count);
          }
          int num = 0;

          check = 1;
          while (check) {
            printf("수정할 항목을 선택하세요.\n");
            printf("1. 화장품 브랜드 2.화장품 이름 3.별점 4. 메모\n");
            scanf_s("%d", &num);
            check = errordetect(num, 4);
          }

          ChangeHwaInfo(&hwa_save[sujeong - 1], num);
        }

      } else if (num == 3) {
        int delete = 0;
        printf("삭제할 화장품 번호: ");
        check = 1;
        while (check) {
          scanf_s("%d", &delete);
          check = errordetect(delete, count);
        }
        SubHwaInfo(hwa_save, count, delete -1);
        count = count - 1;
      } else if (num == 4) {
        char one;
        char component[15];
        printf("기초 화장품 추천 탭입니다!\n");
        printf(
            "화장품 저장소에서 맞지 않았던 화장품 성분이 있다면 y를 없으면 n를 "
            "입력해주세요.\n");
        scanf_s(" %c", &one, 1);
        getchar();
        if (one == 'y' || one == 'Y') {
          printf("맞지 않았던 성분 한가지를 입력해주세요: ");
          scanf_s("%s", component, (int)sizeof(component));

          if (strcmp(component, "티트리") == 0) {
            char* fileName2 = "./best_hwa_byeongful.txt";
            FILE* file3;

            printf("%s 성분 대신 [병풀] 성분의 화장품을 추천드립니다\n",
                   component);
            fopen_s(&file3, fileName2, "w");
            fputs(
                "1. 라운드랩 소나무 진정 앰플\n2. 토리든 밸런스풀 병풀 진정 "
                "크림\n",
                file3);
            fclose(file3);
            fopen_s(&file3, fileName2, "r");

            while (1) {
              char* result = fgets(temp, MAX, file3);
              if (result == NULL) {
                break;
              }
              printf("%s", temp);
            }
            fclose(file3);
          } else if (strcmp(component, "병풀") == 0) {
            FILE* file2;
            fopen_s(&file2, "./best_hwa_teetree.txt", "w");
            if (file2 != NULL) {
              printf("%s 성분 대신 [티트리] 성분의 화장품을 추천드립니다\n",
                     component);
              fputs(
                  "1. 메디힐 티트리 진정 수분 앰플\n2. 린제이 모델링마스크 "
                  "쿨티트리\n3. 브링그린 티트리수딩토너\n4. 파파레서피 "
                  "티트리 "
                  "수딩 크림\n",
                  file2);
              fclose(file2);
              fopen_s(&file2, "./best_hwa_teetree.txt", "r");

              while (1) {
                char* result = fgets(temp, MAX, file2);
                if (result == NULL) {
                  break;
                }
                printf("%s", temp);
              }
              fclose(file2);
            }
          } else {
            printf(
                "성분이 추천 데이터베이스에 존재하지 않습니다. 그 대신 "
                "피부타입에 따른 화장품을 추천해드릴게요!\n");
            SkinTypeHwa(skin_type);
          }

        } else {
          printf("그렇다면 피부타입에 따른 화장품을 추천해드릴게요!\n");
          SkinTypeHwa(skin_type);
        }
      }

    } else if (choice == 3) {
      int num = 0;

      fopen_s(&file, fileName, "a+");
      if (file == NULL) {
        printf("실패\n");
        return 1;
      }
      printf("1. 피부 일기 쓰기\n2. 피부 일기 보기\n");
      check = 1;
      while (check) {
        scanf_s("%d", &num);
        check = errordetect(num, 2);
      }
      
      if (num == 1) {
        int month = 0;
        int day = 0;
        printf("월을 입력하세요.(1~12)\n");
        scanf_s("%d", &month);
        printf("일을 입력하세요.(1~31)\n");
        scanf_s("%d", &day);
        printf("%d월 %d일", month, day);
        fprintf(file, "%d월 %d일 ", month, day);
        printf("일기 입력(작성이 완료되면 나가기를 입력하세요): ");
        while (1) {
          scanf_s("%[^\n]", content, (int)sizeof(content));
          getchar();

          if (strcmp(content, "나가기") == 0) {
            printf("일기가 저장되었습니다.\n");
            break;
          }
          fputs(content, file);
          fputs("\n", file);
        }
        fclose(file);

      } else if (num == 2) {
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
          "올리브영 링크입니다! (링크 바로가기는 추후 업데이트 예정입니다)\n");
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
        printf("잘못된 입력입니다. 목록에 있는 번호를 입력해주세요.\n");
      }
    } else if (choice == 6) {
      MedCalculator(&med_check, &month, &day);
    }
    if (med_check == 2) {
      if (choice == 7) {
        day += 2;

        int EndDay = month_day[month - 1];
        if (day > EndDay) {
          day -= EndDay;  // 1일로 만들기
          month++;
          if (month > 12) {
            month = 1;
          }
        }
      } else if (choice == 8) {
        printf("프로그램을 종료합니다.\n");
        Freemalloc(hwa_save, count);
        return 0;
      } else {
        errordetect(choice, 8);
      }
    } else {
      if (choice == 7) {
        printf("프로그램을 종료합니다.\n");
        Freemalloc(hwa_save, count);
        return 0;

      } else {
        errordetect(choice, 7);
      }
    }
  }
}
