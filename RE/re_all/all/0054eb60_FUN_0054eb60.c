
undefined4
FUN_0054eb60(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,char *param_7,
            char *param_8)

{
  int iVar1;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  if (*param_7 != '\0') {
    iVar1 = FUN_00546d90(param_7,1);
    if (iVar1 < 0) {
      return 0xffffffff;
    }
  }
  if (*param_8 != '\0') {
    iVar1 = FUN_00546d90(param_8,1);
    if (iVar1 < 0) {
      return 0xffffffff;
    }
  }
  if (param_1 < 0) {
    param_5 = param_5 - param_1;
    param_3 = param_3 + param_1;
    param_1 = 0;
  }
  if (param_2 < 0) {
    param_4 = param_4 + param_2;
    param_6 = param_6 - param_2;
    param_2 = 0;
  }
  if (param_5 < 0) {
    param_3 = param_3 + param_5;
    param_1 = param_1 - param_5;
    param_5 = 0;
  }
  if (param_6 < 0) {
    param_4 = param_4 + param_6;
    param_2 = param_2 - param_6;
    param_6 = 0;
  }
  if (*(int *)(param_8 + 0x428) < param_5 + param_3) {
    param_3 = *(int *)(param_8 + 0x428) - param_5;
  }
  if (*(int *)(param_8 + 0x42c) < param_4 + param_6) {
    param_4 = *(int *)(param_8 + 0x42c) - param_6;
  }
  if (*(int *)(param_7 + 0x428) < param_1 + param_3) {
    param_3 = *(int *)(param_7 + 0x428) - param_1;
  }
  if (*(int *)(param_7 + 0x42c) < param_2 + param_4) {
    param_4 = *(int *)(param_7 + 0x42c) - param_2;
  }
  if ((0 < param_3) && (0 < param_4)) {
    local_4 = param_2 + param_4;
    local_8 = param_1 + param_3;
    local_10 = param_1;
    local_c = param_2;
    FUN_00549b20(*(undefined4 *)(param_8 + 0x434),*(undefined4 *)(param_8 + 0x430),param_8,
                 *(undefined4 *)(param_7 + 0x434),*(undefined4 *)(param_7 + 0x430),param_7,0,0,0,
                 param_5,param_6,&local_10,0,0,0,0,0,0,0,1);
  }
  return 0;
}

