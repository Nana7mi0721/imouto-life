
void FUN_0065a700(undefined1 *param_1,int param_2)

{
  undefined1 uVar1;
  
  if (0 < param_2) {
    do {
      uVar1 = param_1[7];
      param_1[7] = *param_1;
      *param_1 = uVar1;
      uVar1 = param_1[6];
      param_1[6] = param_1[1];
      param_1[1] = uVar1;
      uVar1 = param_1[5];
      param_1[5] = param_1[2];
      param_1[2] = uVar1;
      uVar1 = param_1[4];
      param_1[4] = param_1[3];
      param_1[3] = uVar1;
      param_1 = param_1 + 8;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}

