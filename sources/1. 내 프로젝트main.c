#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define yeol 100
#define bunho 20

char save[bunho][yeol] = {""};
int type[bunho];
int count = 0;

struct HwaInfo {
  char* brandname;
  char* name;
};

void ScanfHwaInfo(struct HwaInfo* hwa);
void displayHwaInfo(const struct HwaInfo* hwa, int count);

int main() {
  printf("�Ǻΰ��� ���α׷� ver1.0 \n");

  while (1) {
    int choice = 0;
    // char med[20] = "�½��ϴ�";
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
      printf("���� ������� ���� �ڽ��� �Ǻο� �´� ���� ���� �˴ϴ�.\n");
      printf("�����ϰ� ������ ���� �����ϰ� \n");
      scanf_s("%d", &type[0]);
      printf("1.~ 2.~\n");
      scanf_s("%d", &type[1]);
      for (int i = 0; i < 5; i++) {
        sum += *(type + i);
      }

      printf("%d\n", sum);
      printf("�Ǻ� Ÿ�� ����� ~�Դϴ�!\n");  // �׽�Ʈ�� if�� �߰��ϱ�

      // �����޸�? �� 5�� ����
      // ������ ����� 1����..? sum���� �ؾ��ϳ� ����
      // �Լ�����������?
      // �� ��: �迭 ĭ�� 1, 2 ���� ���� �� for������ �ϰ� ���ϴ� �� ������
      // �Լ��� �����
    } else if (choice == 2) {
      int num = 0;
      struct HwaInfo hwa_save[bunho];  // ����ü�� ���� �����ϱ�
     
      displayHwaInfo(hwa_save, count);
      printf("-------------------\n");

      printf("1. ȭ��ǰ �߰�\n2. ������\n");
      scanf_s("%d", &num);
      if (num == 1) {
        if (count < bunho) {
          ScanfHwaInfo(&hwa_save[count]);
          count++;
        } else {
          printf("ȭ��ǰ ����Ұ� �� á���.\n");
        }

      } else if (num == 2) {
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

void ScanfHwaInfo(struct HwaInfo* hwa) {
  printf("ȭ��ǰ �귣�带 �Է��ϼ���.(���� ���� �Է�): \n");
  char temp[100];
  scanf_s("%s", temp, (int)sizeof(temp));
  hwa->brandname = (char*)malloc((strlen(temp) + 1) * sizeof(char));
  strcpy_s(hwa->brandname, strlen(temp) + 1, temp);

  printf("ȭ��ǰ �̸��� �Է��ϼ���.(���� ���� �Է�): \n");
  scanf_s("%s", temp, (int)sizeof(temp));
  hwa->name = (char*)malloc((strlen(temp) + 1) * sizeof(char));
  strcpy_s(hwa->name, strlen(temp) + 1, temp);
}

void displayHwaInfo(const struct HwaInfo* hwa, int count) {
  printf("[ȭ��ǰ ���]\n");
  for (int i = 0; i < count; i++) {
    printf("%d. %s | %s\n", i + 1, hwa[i].brandname, hwa[i].name);
    // printf("%s"); ������ ���
  }
}
