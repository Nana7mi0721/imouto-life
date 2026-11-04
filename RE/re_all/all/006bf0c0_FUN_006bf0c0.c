
uint FUN_006bf0c0(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(param_1 + 8);
  iVar2 = *(int *)(param_1 + 0xc);
  if (param_2 == 0) {
    return 0;
  }
  if (iVar2 < param_2) {
    uVar1 = FUN_006bf040(param_1,param_2);
    iVar2 = *(int *)(param_1 + 0xc);
  }
  *(int *)(param_1 + 0xc) = iVar2 - param_2;
  *(uint *)(param_1 + 8) = uVar1 * 2 << ((char)param_2 - 1U & 0x1f);
  return uVar1 >> (0x20U - (char)param_2 & 0x1f);
}

