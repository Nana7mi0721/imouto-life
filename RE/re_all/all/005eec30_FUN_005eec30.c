
undefined4 FUN_005eec30(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_1[1];
  param_1[0x12] = -1;
  if (*param_1 == 0) {
    if (iVar1 == 5) {
      if (*(int *)(param_2 + 0x2c) == 1) {
        param_1[0x12] = 1;
      }
    }
    else if (((iVar1 == 9) && (param_1[0x349] != 0)) && (*(int *)(param_2 + 0x7c) == DAT_00a38120))
    {
      FUN_0059d460();
      FUN_00598650(*(int *)(param_1[0x349] + 0x4c) + 0x3c,DAT_00a38140);
    }
    if (param_1[0x12] == -1) {
      param_1[0x12] = *(int *)(&DAT_00a05510 + param_1[1] * 4);
    }
    param_1[0x13] = *(int *)(&DAT_00a05578 + param_1[1] * 4);
  }
  else {
    param_1[0x12] = *(int *)(&DAT_00a055e0 + iVar1 * 4);
    param_1[0x13] = *(int *)(&DAT_00f3ca90 + iVar1 * 4);
  }
  if (((param_1[8] != param_1[0x10]) || (param_1[9] != param_1[0x11])) || (DAT_00ddb4cc == 0)) {
    param_1[0x13] = 1;
  }
  if (DAT_00a37dc8 == 0) {
    param_1[0x12] = 1;
  }
  if (DAT_00e79688 == 0) {
    FUN_0059d430();
  }
  FUN_005ee360(&DAT_00f3ca48);
  return 0;
}

