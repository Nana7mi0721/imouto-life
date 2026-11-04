
void FUN_00687040(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  FUN_00686af0(param_1,param_2);
  FUN_00686b50(param_1,param_1[0x13] * 3 + 8);
  if ((0xffff < param_1[0x11]) || (0xffff < param_1[0x10])) {
    *(undefined4 *)(*param_1 + 0x14) = 0x2a;
    *(undefined4 *)(*param_1 + 0x18) = 0xffff;
    (**(code **)*param_1)(param_1);
  }
  FUN_00686b10(param_1,param_1[0x12]);
  FUN_00686b50(param_1,param_1[0x11]);
  FUN_00686b50(param_1,param_1[0x10]);
  FUN_00686b10(param_1,param_1[0x13]);
  puVar2 = (undefined4 *)param_1[0x15];
  iVar1 = 0;
  if (0 < param_1[0x13]) {
    do {
      FUN_00686b10(param_1,*puVar2);
      FUN_00686b10(param_1,puVar2[2] * 0x10 + puVar2[3]);
      FUN_00686b10(param_1,puVar2[4]);
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 0x16;
    } while (iVar1 < param_1[0x13]);
  }
  return;
}

