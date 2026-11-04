
int FUN_007a01c0(uint param_1)

{
  int iVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  
  if ((int)param_1 < 0) {
    return 0;
  }
  if (0xf7e < (int)param_1) {
    return 0x7fffffff;
  }
  iVar1 = 1 << ((byte)((int)param_1 >> 7) & 0x1f);
  uVar3 = param_1 & 0x7f;
  sVar2 = (short)uVar3;
  if ((int)param_1 < 0x800) {
    uVar4 = (int)(short)(0x80 - sVar2) * (int)sVar2;
    return iVar1 + ((int)((((int)((uVar4 & 0xffff) * -0xae) >> 0x10) + ((int)uVar4 >> 0x10) * -0xae
                          + uVar3) * iVar1) >> 7);
  }
  uVar4 = (int)(short)(0x80 - sVar2) * (int)sVar2;
  return iVar1 + (((int)((uVar4 & 0xffff) * -0xae) >> 0x10) + ((int)uVar4 >> 0x10) * -0xae + uVar3)
                 * (iVar1 >> 7);
}

