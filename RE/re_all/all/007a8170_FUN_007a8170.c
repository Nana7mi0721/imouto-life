
uint FUN_007a8170(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  
  iVar3 = param_1 + -1;
  puVar5 = (uint *)(param_2 + iVar3 * 4);
  uVar1 = *(uint *)(param_2 + iVar3 * 4);
  uVar6 = (uint)((int)uVar1 < 0);
  iVar4 = (uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f);
  iVar7 = param_1 - iVar3;
  param_1 = iVar3;
  do {
    puVar5 = puVar5 + -1;
    param_1 = param_1 + -1;
    iVar7 = iVar7 + 1;
    iVar3 = iVar7;
    if (iVar4 <= iVar7) {
      iVar3 = iVar4;
    }
    iVar2 = iVar7;
    if (iVar7 <= iVar4) {
      iVar2 = iVar4;
    }
    uVar6 = uVar6 + *(int *)((&PTR_DAT_0083dc68)[iVar3] + iVar2 * 4);
    uVar1 = *puVar5;
    iVar4 = iVar4 + ((uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f));
    if ((int)uVar1 < 0) {
      iVar3 = iVar4 + 1;
      iVar2 = iVar7;
      if (iVar3 <= iVar7) {
        iVar2 = iVar3;
      }
      if (iVar3 < iVar7) {
        iVar3 = iVar7;
      }
      uVar6 = uVar6 + *(int *)((&PTR_DAT_0083dc68)[iVar2] + iVar3 * 4);
    }
  } while (0 < param_1);
  return uVar6;
}

