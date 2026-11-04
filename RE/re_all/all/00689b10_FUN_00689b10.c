
uint FUN_00689b10(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  
  if (param_3 < param_5) {
    cVar1 = FUN_006899f0(param_1,param_2,param_3,param_5);
    if (cVar1 == '\0') {
      return 0xffffffff;
    }
    param_2 = *(int *)(param_1 + 8);
    param_3 = *(int *)(param_1 + 0xc);
  }
  param_3 = param_3 - param_5;
  uVar3 = *(uint *)(&DAT_00823428 + param_5 * 4) & param_2 >> ((byte)param_3 & 0x1f);
  piVar2 = (int *)(param_4 + param_5 * 4);
  if (*(int *)(param_4 + param_5 * 4) < (int)uVar3) {
    do {
      if (param_3 < 1) {
        cVar1 = FUN_006899f0(param_1,param_2,param_3,1);
        if (cVar1 == '\0') {
          return 0xffffffff;
        }
        param_2 = *(int *)(param_1 + 8);
        param_3 = *(int *)(param_1 + 0xc);
      }
      param_3 = param_3 + -1;
      piVar2 = piVar2 + 1;
      uVar3 = uVar3 << 1 | param_2 >> ((byte)param_3 & 0x1f) & DAT_0082342c;
      param_5 = param_5 + 1;
    } while (*piVar2 < (int)uVar3);
  }
  *(int *)(param_1 + 8) = param_2;
  *(int *)(param_1 + 0xc) = param_3;
  if (param_5 < 0x11) {
    return (uint)*(byte *)(*(int *)(param_4 + 0x48 + param_5 * 4) + *(int *)(param_4 + 0x8c) + 0x11
                          + uVar3);
  }
  *(undefined4 *)(**(int **)(param_1 + 0x10) + 0x14) = 0x79;
  (**(code **)(**(int **)(param_1 + 0x10) + 4))(*(int **)(param_1 + 0x10),0xffffffff);
  return 0;
}

