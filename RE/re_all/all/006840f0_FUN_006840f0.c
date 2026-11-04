
void FUN_006840f0(int *param_1,int param_2,int *param_3,int param_4,char param_5)

{
  int iVar1;
  int iVar2;
  
  if (param_1[5] != 100) {
    *(undefined4 *)(*param_1 + 0x14) = 0x15;
    *(int *)(*param_1 + 0x18) = param_1[5];
    (**(code **)*param_1)(param_1);
  }
  if ((param_2 < 0) || (3 < param_2)) {
    *(undefined4 *)(*param_1 + 0x14) = 0x20;
    *(int *)(*param_1 + 0x18) = param_2;
    (**(code **)*param_1)(param_1);
  }
  if (param_1[param_2 + 0x16] == 0) {
    iVar1 = FUN_00684870(param_1);
    param_1[param_2 + 0x16] = iVar1;
  }
  iVar1 = 0;
  do {
    iVar2 = (param_4 * *param_3 + 0x32) / 100;
    if (iVar2 < 1) {
      iVar2 = 1;
    }
    else if (0x7fff < iVar2) {
      iVar2 = 0x7fff;
    }
    if ((param_5 != '\0') && (0xff < iVar2)) {
      iVar2 = 0xff;
    }
    iVar1 = iVar1 + 2;
    param_3 = param_3 + 1;
    *(short *)(param_1[param_2 + 0x16] + -2 + iVar1) = (short)iVar2;
  } while (iVar1 < 0x80);
  *(undefined1 *)(param_1[param_2 + 0x16] + 0x80) = 0;
  return;
}

