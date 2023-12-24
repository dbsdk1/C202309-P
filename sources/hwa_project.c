#include "hwa_project.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ErrorDetect(int user_num, int limit_num) {
  int check=1;
  if (user_num > limit_num || user_num <= 0) {
    check = 1;
    printf("�߸��� �Է��Դϴ�. 1~%d ������ ���ڸ� �Է����ּ���!\n", limit_num);
    // �����ľ�
  } else {
    check = 0;
  }
  return check;
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
void ChangeHwaInfo(struct HwaInfo* hwa, int num) {
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
      "���帧���� �԰ų� �ٸ��� ��Ű���? �´ٸ� y��, Ʋ���� n�� �Է����ּ���. "
      "�� ������ �� �˸��� ��ɿ� ���˴ϴ�!\n");
  scanf_s(" %c", &one, 1);
  getchar();
  if (one == 'y' || one == 'Y') {
    int med;
    printf("�� �Դ�(�ٸ���) �ֱⰡ ��� �ǳ���?\n1. ���� 2. ��Ʋ 3. ��Ÿ\n");
    scanf_s("%d", &med);

    if (med == 1) {
      printf("�亯 �����մϴ� :)\n");
      *med_check = 1;
    } else if (med == 2) {
      printf("�亯 �����մϴ� :)\n");
      printf("��¥ ������ �����ҰԿ�!\n");
      printf("���� ���� �Է��ϼ���: ");
      scanf_s("%d", Month);
      printf("���� �Է��ϼ���: ");
      scanf_s("%d", Day);
      *med_check = 2;
      printf(
          "������ ���� �԰ų� �߶��ٸ� �޴� ��ȣ�� 7���� �Է����ּ���! �� "
          "�˸��̿� ��¥ ����� �ǽð� "
          "�ݿ��ǰ� �˴ϴ�.\n");
    } else if (med == 3) {
      printf(
          "����, ��Ʋ �ܴ� �˸������ �����ϰ� "
          "���� �ʽ��ϴ�.\n");
      *med_check = 0;
    } else {
      printf("�߸��� �Է��Դϴ�. �� ���� �޴����� �ٽ� �������ּ���.\n");
    }
  } else {
    *med_check = 0;
  }
}
void SkinTypeHwa(char* skin_type) {
  if (strcmp(skin_type, "����") == 0) {
    printf("[���� �Ǻ�]\n");
    printf("1. �������\n2. ��������ó ����� ���ƽý� ����ũ��\n");
  } else if (strcmp(skin_type, "���ռ�") == 0) {
    printf("[�߼�(���ռ�) �Ǻ�]\n");
    printf(
        "1. �����Ʈ�� �������� ���˷�л� ���\n2. ����ũ���� ����ī "
        "����ũ��\n");
  } else if (strcmp(skin_type, "�Ǽ�") == 0) {
    printf("[�Ǽ� �Ǻ�]\n");
    printf("1. �ϸ��� ���� ��Ų\n2. �丮�� �ָ����� �����̵� ũ��\n");
  } else {
    printf("���� �Ǻ�Ÿ�� ������ �Ͻø� �׿� �´� ȭ��ǰ�� ��õ�����.\n");
  }
}