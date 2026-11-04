
uint FUN_006bf040(undefined4 *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  
  uVar4 = param_1[2];
  uVar2 = 0x20 - param_1[3];
  for (pbVar3 = (byte *)param_1[1]; (7 < uVar2 && (pbVar3 < (byte *)*param_1)); pbVar3 = pbVar3 + 1)
  {
    uVar2 = uVar2 - 8;
    uVar4 = uVar4 | (uint)*pbVar3 << ((byte)uVar2 & 0x1f);
  }
  param_1[1] = pbVar3;
  iVar1 = 0x20 - uVar2;
  if (iVar1 < param_2) {
    if ((byte *)*param_1 <= pbVar3) {
      param_1[4] = 1;
      param_1[3] = 0x40000000;
      return uVar4;
    }
    uVar4 = uVar4 | *pbVar3 >> ((byte)iVar1 & 7);
  }
  param_1[3] = iVar1;
  return uVar4;
}

