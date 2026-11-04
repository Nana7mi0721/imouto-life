
void FUN_0067fe80(undefined2 *param_1,int param_2,int param_3)

{
  short sVar1;
  undefined2 uVar2;
  short *psVar3;
  uint uVar4;
  int iVar5;
  short asStack_20 [16];
  
  sVar1 = 0;
  psVar3 = asStack_20;
  iVar5 = 0xf;
  do {
    psVar3 = psVar3 + 1;
    sVar1 = (*(short *)((param_3 - (int)(asStack_20 + 1)) + (int)psVar3) + sVar1) * 2;
    iVar5 = iVar5 + -1;
    *psVar3 = sVar1;
  } while (iVar5 != 0);
  if (-1 < param_2) {
    param_2 = param_2 + 1;
    do {
      uVar4 = (uint)(ushort)param_1[1];
      if (uVar4 != 0) {
        sVar1 = asStack_20[uVar4];
        asStack_20[uVar4] = sVar1 + 1;
        uVar2 = FUN_00680d00(sVar1,uVar4);
        *param_1 = uVar2;
      }
      param_1 = param_1 + 2;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}

