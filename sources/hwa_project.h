struct HwaInfo {
  char* brandname;
  char* name;
  float star;
  char* write;
};

struct HwaInfo hwa_save[];

void AddHwaInfo(struct HwaInfo* hwa);
void DisplayHwaInfo(const struct HwaInfo* hwa, int count);
void ChangeHwaInfo(struct HwaInfo* hwa, int num);
void SubHwaInfo(struct HwaInfo* hwa, int count, int delete);
void Freemalloc(struct HwaInfo* hwa, int count);
void MedCalculator(int* MedCheck, int* month, int* day);
void SkinTypeHwa(char* SkinType);

