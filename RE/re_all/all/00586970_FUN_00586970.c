
undefined4 __fastcall FUN_00586970(int param_1,int param_2,int *param_3,int param_4)

{
  int *in_EAX;
  int iVar1;
  int iVar2;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  if (in_EAX == (int *)0x0) {
    iVar1 = param_3[10] - param_3[8];
    iVar2 = param_3[0xb] - param_3[9];
  }
  else {
    iVar1 = in_EAX[2] - *in_EAX;
    iVar2 = in_EAX[3] - in_EAX[1];
  }
  if ((param_2 < 0) || (param_1 < 0)) {
    param_1 = iVar2;
    param_2 = iVar1;
  }
  param_3[0x14] = param_2;
  param_3[0x15] = param_1;
  param_3[0x123] = 0;
  param_3[0x233] = 0;
  param_3[0x343] = 0;
  if (in_EAX == (int *)0x0) {
    local_10 = param_3[8];
    local_c = param_3[9];
    local_8 = param_3[10];
    local_4 = param_3[0xb];
  }
  else {
    local_c = in_EAX[1];
    local_10 = *in_EAX;
    local_4 = in_EAX[3];
    local_8 = in_EAX[2];
  }
  iVar1 = FUN_005866a0(param_3[2],param_3 + 0x16,&local_10);
  if ((-1 < iVar1) &&
     ((*param_3 == 0 || (iVar1 = FUN_005866a0(param_3[3],param_3 + 0x126,&local_10), -1 < iVar1))))
  {
    if (param_4 == 0) {
      local_10 = param_3[0x10];
      local_8 = param_3[0x14] + local_10;
      local_c = param_3[0x11];
      local_4 = param_3[0x15] + local_c;
      iVar1 = FUN_005866a0(param_3[4],param_3 + 0x236,&local_10);
    }
    else {
      iVar1 = FUN_00546c90(param_3[0x14],param_3[0x15],param_3 + 0x236);
    }
    if (-1 < iVar1) {
      return 0;
    }
  }
  if (param_3[0x123] != 0) {
    FUN_005421c0(param_3 + 0x16);
  }
  if (param_3[0x233] != 0) {
    FUN_005421c0(param_3 + 0x126);
  }
  if (param_3[0x343] != 0) {
    FUN_005421c0(param_3 + 0x236);
  }
  return 0xffffffff;
}

