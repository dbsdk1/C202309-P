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
  printf("�Ǻΰ��� ���α׷� ver1.0 \n");
  printf("�ʱ� ���� �ܰ��Դϴ�!\n");
  printf(
      "���帧���� �԰ų� �ٸ��� ��Ű���? �´ٸ� y��, Ʋ���� n�� �Է����ּ���. "
      "�� ������ �� �˸��� ��ɿ� ���˴ϴ�!\n");  // �Լ�ȭ ��Ű�� ����6������
                                                    // �߰����Ѽ� �Լ���
                                                    // ���� �ҷ����� ��
  scanf_s("%c", &one, 1);

  while (1) {
    int choice = 0;
    // char med[20] = "�½��ϴ�";  //���� ���
    printf("--------------------------\n");
    printf("��ȣ�� �������ּ���!\n");
    printf(
        "1. �Ǻ�Ÿ�� �����ϱ�\n2. ���� ȭ��ǰ ����\n3. ������ �Ǻ� �ϱ�\n4. "
        "�ø��꿵 �ٷΰ���\n5. ���帧 ���� ���� ����zip\n");
    printf("6. ���α׷� ����\n");
    /*printf("����(��¥~)�� �� �Դ� ���� %s\n", med;*/
    printf("--------------------------\n");
    scanf_s("%d", &choice);

    if (choice == 1) {
      int sum = 0;
      printf("�Ǻ�Ÿ�� ������ �����ҰԿ� :)\n");
      printf("�Ǻ�Ÿ���� ũ�� ����, ���ռ�(�߼�), �Ǽ����� ����������!\n");
      printf("���� ������� ���� �ڽ��� �Ǻο� ����� ���� ���� �˴ϴ�.\n");
      printf(
          "1. �����ϰ� ���ͼ� �ƹ��͵� �ȹٸ� ���·� �ð��� ������ ���������� "
          "�ʴ�. 2. �����ϰ� �ƹ��͵� �ȹٸ��ٸ� ���� �����ϰ� ���� "
          "���̴�.\n");
      scanf_s("%d", &type[0]);
      printf(
          "1. ���İ� �Ǹ� �󱼿� �⸧�� �߰� ��¦�Ÿ���. 2. ���İ� �Ǿ "
          "��ħ�� �Ǻλ��°� �Ȱų� �⸧�� ���� ����.\n");
      scanf_s("%d", &type[1]);
      printf(
          "1. �����ܿ￡�� �Ǻ��� �������� ������ ���Ѵ�. 2. �����ܿ��� �Ǻΰ� "
          "�ٸ� �������� ����������.\n");
      scanf_s("%d", &type[2]);
      printf(
          "1. �⸧���̸� ������� �� �⸧�� �ܶ� ����ȴ�. 2. �⸧���̸� "
          "��µ� "
          "�⸧���̰� �Ǽ��ϴ�. (�⸧���̰� ���ٸ� ������ ������ ���� "
          "�������� ���� ���� Ȯ���غ�����)\n");
      scanf_s("%d", &type[3]);
      printf("1. ���帧�� ���� ���ִ�. 2. ���帧�� ���� ���̴�.\n");
      scanf_s("%d", &type[4]);

      for (int i = 0; i < 5; i++) {
        sum += *(type + i);
      }
      if (sum <= 6) {
        printf("�Ǻ� Ÿ�� ���� ����� �����Դϴ�!\n");
        printf(
            "������ �Ϲ������� ����(�⸧)�� ���� �Ǻ��Դϴ�. �ٴ��ϰų� �� "
            "������� �ʴ� ���ſ� ����ȭ��ǰ�� ����ϸ� ���帧�� �� �������� "
            "�����ϼ���!\n");
      } else if (sum <= 8) {
        printf("�Ǻ� Ÿ�� ���� ����� �߼�(���ռ�)�Դϴ�!\n");
        printf("~~\n");
      } else {
        printf("�Ǻ� Ÿ�� ���� ����� �Ǽ��Դϴ�!\n");
        printf("�Ǽ��� ~\n");
      }  // �Լ��� �����

    } else if (choice == 2) {
      int num = 0;
      struct HwaInfo
          hwa_save[bunho];  // ����ü�� ���� �����ϱ� (�귣��� �̸� ����)

      displayHwaInfo(hwa_save, count);
      printf("-------------------\n");

      printf("1. ȭ��ǰ �߰�\n2. ȭ��ǰ ����\n3. ������\n");
      scanf_s("%d", &num);
      if (num == 1) {
        if (count < bunho) {
          addHwaInfo(&hwa_save[count]);  // ������
          count++;
        } else {
          printf("ȭ��ǰ ����Ұ� �� á���. (�ִ� 20������ ���� ����)\n");
        }

      } else if (num == 2) {
      } else if (num == 3) {
      }
    } else if (choice == 3) {
      int num = 0;
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
        scanf_s("%d", &day);
        // ��������� ~
      } else if (num == 2) {
        int num = 0;
        printf("1. ��¥����\n2. �ϱ⳻�����\n");
        scanf_s("%d", &num);

      } else if (num == 3) {
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
      printf("���α׷��� �����մϴ�.\n");
      return;
    } else {
      printf("�߸��� �Է��Դϴ�. 1~6�� ������ ��ȣ�� �Է����ּ���\n");
    }
  }
}

void addHwaInfo(struct HwaInfo* hwa) {
  printf("ȭ��ǰ �귣�带 �Է��ϼ���.(���� ���� �Է�): ");
  char temp[100];
  scanf_s("%s", temp, (int)sizeof(temp));
  hwa->brandname = (char*)malloc((strlen(temp) + 1) * sizeof(char));
  strcpy_s(hwa->brandname, strlen(temp) + 1, temp);

  printf("ȭ��ǰ �̸��� �Է��ϼ���.(���� ���� �Է�): ");
  scanf_s("%s", temp, (int)sizeof(temp));
  hwa->name = (char*)malloc((strlen(temp) + 1) * sizeof(char));
  strcpy_s(hwa->name, strlen(temp) + 1, temp);

  printf("������ �Է��ϼ���(5�� ����): ");
  scanf_s("%f", &hwa->star);

  printf("�������� �Է��ϼ���: ");
}

void displayHwaInfo(const struct HwaInfo* hwa, int count) {
  printf("[ȭ��ǰ ���]\n");
  for (int i = 0; i < count; i++) {
    printf("%d. %s | %s (%.1f/5)\n", i + 1, hwa[i].brandname, hwa[i].name,
           hwa[i].star);
    // printf("%s"); ������ ���
  }
}
// ���� �����޸� free