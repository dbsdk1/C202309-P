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
char line[MAX];          // �ϱ��
char content[MAX] = "";  // �ϱ��
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
    printf("�߸��� �Է��Դϴ�. 1~%d ������ ���ڸ� �Է����ּ���!\n", limit_num);
    // �����ľ�
  } else {
    check = 0;
  }
  return check;
}

int main() {
  char* fileName = "./hwa_diary.txt";  // �ϱ� ���� txt
  FILE* file;
  printf("�Ǻΰ��� ���α׷� ver1.0 \n");
  printf("�ʱ� ���� �ܰ��Դϴ�!\n");
  MedCalculator(&med_check, &month, &day);

  while (1) {
    int choice = 0;

    printf("--------------------------\n");
    printf("��ȣ�� �������ּ���!\n");
    printf(
        "1. �Ǻ�Ÿ�� �����ϱ�\n2. ���� ȭ��ǰ ����\n3. ������ �Ǻ� �ϱ�\n4. "
        "�ø��꿵 �ٷΰ���\n5. ���帧 ���� ���� ����zip\n");
    printf("6. �� ����\n");
    if (med_check == 2) {
      printf("7. eat & splash\n8. ���α׷� ����\n");
    } else {
      printf("7. ���α׷� ����\n");
    }
    if (med_check == 1) {
      printf("*������ �� �Դ�(�ٸ���) ���� �½��ϴ�*\n");
    } else if (med_check == 2) {
      printf("*���� �Ծ��(�߶��) �ϴ� ���� ��¥�� %d�� %d���Դϴ�.*\n", month,
             day);
    }
    printf("--------------------------\n");
    scanf_s("%d", &choice);

    if (choice == 1) {
      int sum = 0;

      printf("�Ǻ�Ÿ�� ������ �����ҰԿ� :)\n");
      printf("�Ǻ�Ÿ���� ũ�� ����, ���ռ�(�߼�), �Ǽ����� ����������!\n");
      printf("���� ������� ���� �ڽ��� �Ǻο� ����� ���� ���� �˴ϴ�.\n");
      do {
        printf(
            "1. �����ϰ� ���ͼ� �ƹ��͵� �ȹٸ� ���·� �ð��� ������ "
            "���������� "
            "�ʴ�. 2. �����ϰ� �ƹ��͵� �ȹٸ��ٸ� ���� �����ϰ� ���� "
            "���̴�.\n");
        scanf_s("%d", &type[0]);
        check = errordetect(*(type + 0), 2);
      } while (check);
      do {
        printf(
            "1. ���İ� �Ǹ� �󱼿� �⸧�� �߰� ��¦�Ÿ���. 2. ���İ� �Ǿ "
            "��ħ�� �Ǻλ��°� �Ȱ��ų� �⸧�� ���� ����.\n");
        scanf_s("%d", &type[1]);
        check = errordetect(*(type + 1), 2);
      } while (check);
      do {
        printf(
            "1. �����ܿ￡�� �Ǻ��� �������� ������ ���Ѵ�. 2. �����ܿ��� "
            "�Ǻΰ� "
            "�ٸ� �������� ����������.\n");
        scanf_s("%d", &type[2]);
        check = errordetect(*(type + 2), 2);
      } while (check);
      do {
        printf(
            "1. �⸧���̸� ������� �� �⸧�� �ܶ� ����ȴ�. 2. �⸧���̸� "
            "��µ� �⸧���̰� �Ǽ��ϴ�. (�⸧���̰� ���ٸ� ������ ������ "
            "���� �������� ���� ���� Ȯ���غ�����)\n");
        scanf_s("%d", &type[3]);
        check = errordetect(*(type + 3), 2);
      } while (check);
      do {
        printf("1. ���帧�� ���� ���ִ�. 2. ���帧�� ���� ���̴�.\n");
        scanf_s("%d", &type[4]);
        check = errordetect(*(type + 4), 2);
      } while (check);

      for (int i = 0; i < 5; i++) {
        sum += *(type + i);
      }
      if (sum <= 6) {
        printf("�Ǻ� Ÿ�� ���� ����� �����Դϴ�!\n");
        printf(
            "������ �Ϲ������� ����(�⸧)�� ���� �Ǻ��Դϴ�. �ٴ��ϰų� �� "
            "������� �ʴ� ���ſ� ����ȭ��ǰ�� ����ϸ� ���帧�� �� �������� "
            "�����ϼ���! ���� �⸧���� ����� ��õ�մϴ�.\n");
        strcpy_s(skin_type, (int)sizeof(skin_type), "����");
      } else if (sum <= 8) {
        printf("�Ǻ� Ÿ�� ���� ����� �߼�(���ռ�)�Դϴ�!\n");
        printf(
            "�߼��� �⸧�� �ʹ� ���� ��������, �ʹ� ������ ���� �Ǻ��Դϴ�. "
            "���� ���� ���¸� �����ϴ� ���� �����ϴ�. ������ ȭ��ǰ ��κ��� "
            "�� ���� ������ ���Դϴ�.\n");
        strcpy_s(skin_type, (int)sizeof(skin_type), "���ռ�");
      } else {
        printf("�Ǻ� Ÿ�� ���� ����� �Ǽ��Դϴ�!\n");
        printf(
            "�Ǽ��� �󱼿� �⸧�� ���� ������ �ʴ� �Ǻ��Դϴ�. �׷��⿡ ������ "
            "�� ���ִ� ���� �߿��մϴ�. �Ǻΰ� ���������� �ʵ��� �� "
            "����ȭ��ǰ�� �߶��ּ���.\n");
        strcpy_s(skin_type, (int)sizeof(skin_type), "�Ǽ�");
      }

    } else if (choice == 2) {
      int num = 0;

      DisplayHwaInfo(hwa_save, count);
      printf("-------------------\n");

      printf(
          "1. ȭ��ǰ �߰�\n2. ȭ��ǰ ����\n3. ȭ��ǰ ����\n4. ȭ��ǰ "
          "��õ(BETA)\n5. ������\n");
      check = 1;
      while (check) {
        scanf_s("%d", &num);
        check = errordetect(num, 5);
      }

      if (num == 1) {
        if (count < BUNHO) {
          AddHwaInfo(&hwa_save[count]);  // ������
          count++;
        } else {
          printf("ȭ��ǰ ����Ұ� �� á���. (�ִ� 30������ ���� ����)\n");
        }

      } else if (num == 2) {
        int sujeong = 0;
        if (count == 0) {
          printf("ȭ��ǰ ����ҿ� ȭ��ǰ�� �����. \n");
        } else {
          printf("������ ȭ��ǰ ��ȣ: ");
          check = 1;
          while (check) {
            scanf_s("%d", &sujeong);
            check = errordetect(sujeong, count);
          }
          int num = 0;

          check = 1;
          while (check) {
            printf("������ �׸��� �����ϼ���.\n");
            printf("1. ȭ��ǰ �귣�� 2.ȭ��ǰ �̸� 3.���� 4. �޸�\n");
            scanf_s("%d", &num);
            check = errordetect(num, 4);
          }

          ChangeHwaInfo(&hwa_save[sujeong - 1], num);
        }

      } else if (num == 3) {
        int delete = 0;
        printf("������ ȭ��ǰ ��ȣ: ");
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
        printf("���� ȭ��ǰ ��õ ���Դϴ�!\n");
        printf(
            "ȭ��ǰ ����ҿ��� ���� �ʾҴ� ȭ��ǰ ������ �ִٸ� y�� ������ n�� "
            "�Է����ּ���.\n");
        scanf_s(" %c", &one, 1);
        getchar();
        if (one == 'y' || one == 'Y') {
          printf("���� �ʾҴ� ���� �Ѱ����� �Է����ּ���: ");
          scanf_s("%s", component, (int)sizeof(component));

          if (strcmp(component, "ƼƮ��") == 0) {
            char* fileName2 = "./best_hwa_byeongful.txt";
            FILE* file3;

            printf("%s ���� ��� [��Ǯ] ������ ȭ��ǰ�� ��õ�帳�ϴ�\n",
                   component);
            fopen_s(&file3, fileName2, "w");
            fputs(
                "1. ���左 �ҳ��� ���� ����\n2. �丮�� �뷱��Ǯ ��Ǯ ���� "
                "ũ��\n",
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
          } else if (strcmp(component, "��Ǯ") == 0) {
            FILE* file2;
            fopen_s(&file2, "./best_hwa_teetree.txt", "w");
            if (file2 != NULL) {
              printf("%s ���� ��� [ƼƮ��] ������ ȭ��ǰ�� ��õ�帳�ϴ�\n",
                     component);
              fputs(
                  "1. �޵��� ƼƮ�� ���� ���� ����\n2. ������ �𵨸�����ũ "
                  "��ƼƮ��\n3. �긵�׸� ƼƮ���������\n4. ���ķ����� "
                  "ƼƮ�� "
                  "���� ũ��\n",
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
                "������ ��õ �����ͺ��̽��� �������� �ʽ��ϴ�. �� ��� "
                "�Ǻ�Ÿ�Կ� ���� ȭ��ǰ�� ��õ�ص帱�Կ�!\n");
            SkinTypeHwa(skin_type);
          }

        } else {
          printf("�׷��ٸ� �Ǻ�Ÿ�Կ� ���� ȭ��ǰ�� ��õ�ص帱�Կ�!\n");
          SkinTypeHwa(skin_type);
        }
      }

    } else if (choice == 3) {
      int num = 0;

      fopen_s(&file, fileName, "a+");
      if (file == NULL) {
        printf("����\n");
        return 1;
      }
      printf("1. �Ǻ� �ϱ� ����\n2. �Ǻ� �ϱ� ����\n");
      check = 1;
      while (check) {
        scanf_s("%d", &num);
        check = errordetect(num, 2);
      }
      
      if (num == 1) {
        int month = 0;
        int day = 0;
        printf("���� �Է��ϼ���.(1~12)\n");
        scanf_s("%d", &month);
        printf("���� �Է��ϼ���.(1~31)\n");
        scanf_s("%d", &day);
        printf("%d�� %d��", month, day);
        fprintf(file, "%d�� %d�� ", month, day);
        printf("�ϱ� �Է�(�ۼ��� �Ϸ�Ǹ� �����⸦ �Է��ϼ���): ");
        while (1) {
          scanf_s("%[^\n]", content, (int)sizeof(content));
          getchar();

          if (strcmp(content, "������") == 0) {
            printf("�ϱⰡ ����Ǿ����ϴ�.\n");
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
          "�ø��꿵 ��ũ�Դϴ�! (��ũ �ٷΰ���� ���� ������Ʈ �����Դϴ�)\n");
      printf("www.oliveyoung.co.kr\n");
    } else if (choice == 5) {
      int num = 0;
      printf("1) ���帧�� ���� ȭ��ǰ ���е�\n");
      printf("2) ����ȭ��ǰ �ٸ��� ����?\n");
      printf("3) ���ҿ��帧�� ȭ�� ���帧�� ����\n");
      scanf_s("%d", &num);
      if (num == 1) {
        printf(
            "'ƼƮ��' - ƼƮ���� ������ �ſ� Ź���Ͽ� �������� �Ǻο� ������ "
            "�� �� �ֽ��ϴ�.\n");
        printf(
            "'��Ǯ' - ��Ǯ�� ��ó���� ȣ���̰� ��Ǯ�� �ִ� ������ �߱��� "
            "ȣ���� Ǯ�̶�� �Ҹ��� ����ī�ľ־��� ���� ������ �Ǻ� ������ "
            "���а����� ������ �ݴϴ�.\n");
      } else if (num == 2) {
        printf(
            "����ȭ��ǰ�� ������ �ͺ��� ���� ���̰� �ٴ��� ������ �ٸ��� "
            "�˴ϴ�! �����ϰ� �����ϸ� [��Ų(���) - ���� - �μ� or ����ũ�� - "
            "���̿���] ������ �ٸ��� �˴ϴ�. ");
        printf(
            "�ٸ� ���� ���� ���༭ �ٸ��� �ȵǰ� ��� �߶�� �ڱ��� ���ؼ� "
            "Ʈ������ ���� �� �ֽ��ϴ�.\n");
      } else if (num == 3) {
        printf(
            "���� ���帧�� �Ͼ�� �ȿ� �Ҿ˰��� ���� ���ִ� ���̰� ȭ�� "
            "���帧�� ������ ���ܼ� ������ ������ ������ �ξ�ö��ִ� "
            "���帧�Դϴ�.\n");
      } else {
        printf("�߸��� �Է��Դϴ�. ��Ͽ� �ִ� ��ȣ�� �Է����ּ���.\n");
      }
    } else if (choice == 6) {
      MedCalculator(&med_check, &month, &day);
    }
    if (med_check == 2) {
      if (choice == 7) {
        day += 2;

        int EndDay = month_day[month - 1];
        if (day > EndDay) {
          day -= EndDay;  // 1�Ϸ� �����
          month++;
          if (month > 12) {
            month = 1;
          }
        }
      } else if (choice == 8) {
        printf("���α׷��� �����մϴ�.\n");
        Freemalloc(hwa_save, count);
        return 0;
      } else {
        errordetect(choice, 8);
      }
    } else {
      if (choice == 7) {
        printf("���α׷��� �����մϴ�.\n");
        Freemalloc(hwa_save, count);
        return 0;

      } else {
        errordetect(choice, 7);
      }
    }
  }
}
