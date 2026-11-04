
undefined4 FUN_0079f0f0(short *param_1,uint param_2)

{
  short sVar1;
  undefined4 uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int local_80 [32];
  
  iVar5 = 0;
  piVar3 = local_80 + (param_2 & 1) * 0x10;
  if (0 < (int)param_2) {
    uVar4 = param_2;
    do {
      sVar1 = *param_1;
      iVar5 = iVar5 + sVar1;
      param_1 = param_1 + 1;
      *piVar3 = (int)sVar1 << 0xc;
      piVar3 = piVar3 + 1;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
    if (0xfff < iVar5) {
      return 0;
    }
  }
  uVar2 = FUN_0079f160(local_80,param_2);
  return uVar2;
}

