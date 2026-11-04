
void FUN_00653130(int param_1,uint param_2,int param_3,int param_4,int *param_5,int *param_6,
                 int *param_7)

{
  int iVar1;
  
  if (0xff < param_2) {
    param_2 = 0xff;
  }
  if (param_3 < 0) {
    param_3 = 0;
  }
  else if (0xff < param_3) {
    param_3 = 0xff;
  }
  if (param_4 < 0) {
    param_4 = 0;
  }
  else if (0xff < param_4) {
    param_4 = 0xff;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 4) + param_4 * 4) +
          *(int *)(*(int *)(param_1 + 0x14) + param_2 * 4);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  else if (0xff < iVar1) {
    iVar1 = 0xff;
  }
  *param_5 = iVar1;
  iVar1 = (*(int *)(*(int *)(param_1 + 0x10) + param_3 * 4) +
           *(int *)(*(int *)(param_1 + 0xc) + param_4 * 4) >> 0x10) +
          *(int *)(*(int *)(param_1 + 0x14) + param_2 * 4);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  else if (0xff < iVar1) {
    iVar1 = 0xff;
  }
  *param_6 = iVar1;
  iVar1 = *(int *)(*(int *)(param_1 + 8) + param_3 * 4) +
          *(int *)(*(int *)(param_1 + 0x14) + param_2 * 4);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  else if (0xff < iVar1) {
    *param_7 = 0xff;
    return;
  }
  *param_7 = iVar1;
  return;
}

