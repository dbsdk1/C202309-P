#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define yeol 100
#define bunho 30
#define MAX 10000

char save[bunho][yeol] = {""};
int type[5];
int count = 0;
char line[MAX];          // �ϱ��
char content[MAX] = "";  // �ϱ��
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
    hwa_save[bunho];  // ����ü�� ���� �����ϱ� (�귣��� �̸� ����) ����ü ����
void AddHwaInfo(struct HwaInfo* hwa);
void DisplayHwaInfo(const struct HwaInfo* hwa, int count);
void ChangeHwaInfo(struct HwaInfo* hwa);
void Freemalloc(struct HwaInfo* hwa, int count);
void SubHwaInfo(struct HwaInfo* hwa, int count, int delete);
int MedCalculator();


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
  int MedCheck = MedCalculator();
  
  while (1) {
    int choice = 0;

    printf("--------------------------\n");
    printf("��ȣ�� �������ּ���!\n");
    printf(
        "1. �Ǻ�Ÿ�� �����ϱ�\n2. ���� ȭ��ǰ ����\n3. ������ �Ǻ� �ϱ�\n4. "
        "�ø��꿵 �ٷΰ���\n5. ���帧 ���� ���� ����zip\n");
    printf("6. �� ����\n");
    if (MedCheck == 2) {
      printf("7. eat\n8. ���α׷� ����\n");
    } else {
      printf("7. ���α׷� ����\n");
    }
    if (MedCheck == 1) {
      printf("*������ �� �Դ� ���� �½��ϴ�*\n");
    } else if (MedCheck == 2) {
      
        

      printf("*���� �Ծ�� �ϴ� ���� ��¥�� %d�� %d���Դϴ�.*\n", month, day);
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
      } else if (sum <= 8) {
        printf("�Ǻ� Ÿ�� ���� ����� �߼�(���ռ�)�Դϴ�!\n");
        printf(
            "�߼��� �⸧�� �ʹ� ���� ��������, �ʹ� ������ ���� �Ǻ��Դϴ�. "
            "���� ���� ���¸� �����ϴ� ���� �����ϴ�. ������ ȭ��ǰ ��κ��� "
            "�� ���� ������ ���Դϴ�.\n");
      } else {
        printf("�Ǻ� Ÿ�� ���� ����� �Ǽ��Դϴ�!\n");
        printf(
            "�Ǽ��� �󱼿� �⸧�� ���� ������ �ʴ� �Ǻ��Դϴ�. �׷��⿡ ������ "
            "�� ���ִ� ���� �߿��մϴ�. �Ǻΰ� ���������� �ʵ��� �� "
            "����ȭ��ǰ�� �߶��ּ���.\n");
      }

    } else if (choice == 2) {
      int num = 0;

      DisplayHwaInfo(hwa_save, count);
      printf("-------------------\n");

      printf("1. ȭ��ǰ �߰�\n2. ȭ��ǰ ����\n3. ȭ��ǰ ����\n4. ������\n");
      check = 1;
      while (check) {
        scanf_s("%d", &num);
        check = errordetect(num, 3);
      }

      if (num == 1) {
        if (count < bunho) {
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
            errordetect(sujeong, count);
          }

          ChangeHwaInfo(&hwa_save[sujeong - 1]);
        }

      } else if (num == 3) {
        int delete = 0;
        printf("������ ȭ��ǰ ��ȣ: ");
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
        printf("����\n");
        return 1;
      }
      printf(
          "1. �Ǻ� �ϱ� ����\n2. �Ǻ� �ϱ� ����\n3. �Ǻ� "
          "�ϱ� ����\n");
      scanf_s("%d", &num);
      if (num == 1) {
        int month = 0;
        int day = 0;
        printf("���� �Է��ϼ���.(1~12)\n");
        scanf_s("%d", &month);
        printf("���� �Է��ϼ���.(1~31)\n");
        scanf_s("%d",
                &day);  // �׳� printf("���� ��¥�� �Է��ϼ���:") �� ����ϱ�
        printf("%d�� %d��", month, day);
        fprintf(file, "%d�� %d�� ", month, day);
        printf("�ϱ� �Է�(�ۼ��� �Ϸ�Ǹ� �����⸦ �Է��ϼ���): ");
        while (1) {
          scanf_s("%[^\n]", content, (int)sizeof(content));
          getchar();

          if (strcmp(content, "������") ==
              0) {  // ���ڿ� �� ������ 0��ȯ�ϴ°���
            printf("�ϱⰡ ����Ǿ����ϴ�.\n");
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
          "�ø��꿵 ��ũ�Դϴ�! (��ũ �ٷΰ���� ���� ������Ʈ �����Դϴ�) "
          "����(ctrl+c) �� �ּ� â�� �ٿ��ֱ�(ctrl+v) �ϼ���\n");
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
        printf(
            "�߸��� �Է��Դϴ�. ��Ͽ� �ִ� ��ȣ�� �Է����ּ���.\n");  // +
                                                                       // while��
                                                                       // �߰��ؼ�
                                                                       // ��ó�����ξȵ��ư���
                                                                       // ��
      }
    } else if (choice == 6) {
      MedCheck = MedCalculator();
    }

    else if (MedCheck != 2) {
      if (choice == 7) {
        printf("���α׷��� �����մϴ�.\n");
        Freemalloc(hwa_save, count);
        return 0;
      } else {
        errordetect(choice, 7);
      }

    } else if (MedCheck == 2) {
      if (choice = 7) {
        day += 2;  // ���� ��Ʋ�� (����� ��: 31 30 ó�� ��¥ �ݺ�.. �迭�� ������ �Ƿ���..?)

        if (day > 31) {
          day -= 31;  // 1�Ϸ� �����
          month++;
          if (month > 12) {
            month = 1;
          }
        }
      
      }
      if (choice == 8) {
        printf("���α׷��� �����մϴ�.\n");
        Freemalloc(hwa_save, count);
        return 0;
      } else {
        errordetect(choice, 8);
      }
    }
  }
}

void AddHwaInfo(struct HwaInfo* hwa) {
  printf("ȭ��ǰ �귣�带 �Է��ϼ���.(���� ���� �Է�): ");
  char temp[300];
  scanf_s("%s", temp, (int)sizeof(temp));
  hwa->brandname = (char*)malloc((strlen(temp) + 1) * sizeof(char));
  strcpy_s(hwa->brandname, strlen(temp) + 1, temp);

  printf("ȭ��ǰ �̸��� �Է��ϼ���.(���� ���� �Է�): ");
  scanf_s("%s", temp, (int)sizeof(temp));
  hwa->name = (char*)malloc((strlen(temp) + 1) * sizeof(char));
  strcpy_s(hwa->name, strlen(temp) + 1, temp);

  printf("������ �Է��ϼ���(5�� ����): ");
  scanf_s("%f", &hwa->star);

  printf("�޸� �Է��ϼ���(���� ���� �Է�): ");
  scanf_s("%s", temp, (int)sizeof(temp));
  hwa->write = (char*)malloc((strlen(temp) + 1) * sizeof(char));
  strcpy_s(hwa->write, strlen(temp) + 1, temp);
}

void DisplayHwaInfo(const struct HwaInfo* hwa, int count) {
  printf("[ȭ��ǰ ���]\n");
  for (int i = 0; i < count; i++) {
    printf("%d. %s | %s (%.1f/5)\n", i + 1, hwa[i].brandname, hwa[i].name,
           hwa[i].star);
    printf("%s\n", hwa[i].write);  // ������ ���
  }
}
void ChangeHwaInfo(struct HwaInfo* hwa) {
  int num = 0;
  printf("������ �׸��� �����ϼ���.\n");
  printf("1. ȭ��ǰ �귣�� 2.ȭ��ǰ �̸� 3.���� 4. �޸�\n");
  scanf_s("%d", &num);
  char temp[300];
  if (num == 1) {
    printf("ȭ��ǰ �귣�带 �Է��ϼ���.(���� ���� �Է�): ");
    scanf_s("%s", temp, (int)sizeof(temp));
    hwa->brandname = (char*)malloc((strlen(temp) + 1) * sizeof(char));
    strcpy_s(hwa->brandname, strlen(temp) + 1, temp);
  }
  if (num == 2) {
    printf("ȭ��ǰ �̸��� �Է��ϼ���.(���� ���� �Է�): ");
    scanf_s("%s", temp, (int)sizeof(temp));
    hwa->name = (char*)malloc((strlen(temp) + 1) * sizeof(char));
    strcpy_s(hwa->name, strlen(temp) + 1, temp);
  }
  if (num == 3) {
    printf("������ �Է��ϼ���(5�� ����): ");
    scanf_s("%f", &hwa->star);
  }
  if (num == 4) {
    printf("�޸� �Է��ϼ���(���� ���� �Է�): ");
    scanf_s("%s", temp, (int)sizeof(temp));
    hwa->write = (char*)malloc((strlen(temp) + 1) * sizeof(char));
    strcpy_s(hwa->write, strlen(temp) + 1, temp);
  }
}

void SubHwaInfo(struct HwaInfo* hwa, int count, int delete) {
  printf("%s | %s ȭ��ǰ�� �����ҰԿ�.\n", hwa[delete].brandname,
         hwa[delete].name);

  free(hwa[delete].brandname);
  free(hwa[delete].name);
  free(hwa[delete].write);

  for (int i = delete; i < count; i++) {
    hwa[i] = hwa[i + 1];
  }
  hwa[count - 1].brandname = NULL;
  hwa[count - 1].name = NULL;
  hwa[count - 1].write = NULL;  // �� ������ ĭ ���ֱ�
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
      "���帧���� �԰ų� �ٸ��� ��Ű���? �´ٸ� y��, Ʋ���� n�� �Է����ּ���. "
      "�� ������ �� �˸��� ��ɿ� ���˴ϴ�!\n"); 
  scanf_s(" %c", &one, 1);
  getchar();
  if (one == 'y' || one == 'Y') {
    int med;
    printf("�� �Դ�(�ٸ���) �ֱⰡ ��� �ǳ���?\n1. ���� 2. ��Ʋ 3. ��Ÿ\n");
    scanf_s("%d", &med);
    printf("�亯 �����մϴ� :)\n");
    if (med == 1) {
      MedCheck = 1;
    } else if (med == 2) {
      printf("��¥ ������ �����ҰԿ�!\n");
      printf("���� ���� �Է��ϼ���: ");
      scanf_s("%d", &month);
      printf("���� �Է��ϼ���: ");
      scanf_s("%d", &day);
      MedCheck = 2;
      printf(
          "������ ���� �Ծ��ٸ� eat �޴� ��ȣ�� 7���� �Է����ּ���! �� �˸��̿� ��¥ ����� �ǽð� "
          "�ݿ��ǰ� �˴ϴ�.\n");
    } else if (med == 3) {
      printf(
          "����, ��Ʋ �ܴ� �˸������ �����ϰ� "
          "���� �ʽ��ϴ�.\n");
      MedCheck = 0;
    } else {
      printf("�߸��� �Է��Դϴ�.");
    }
  }
  else {
      MedCheck = 0;
    }
  
  return MedCheck;

}
    // �� ��: ���� 3�� �̻� �����!!!!!!!! �Լ�ȭ ��Ű��