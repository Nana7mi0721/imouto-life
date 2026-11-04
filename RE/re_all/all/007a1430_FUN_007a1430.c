
void FUN_007a1430(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  uint local_10;
  uint *local_c;
  int local_8;
  
  iVar1 = param_6;
  uVar6 = *(int *)(param_6 + 4) * 8;
  iVar2 = FUN_007a22e0(*(undefined4 *)(param_6 + 0x1c));
  iVar2 = *(int *)(param_6 + 0x14) - iVar2;
  uVar4 = -(uint)(param_3 != 0) & 0xfffffffe;
  if ((param_5 < 1) || (param_6 = 1, uVar6 < uVar4 + 5 + iVar2)) {
    param_6 = 0;
  }
  local_10 = 0;
  uVar7 = 0;
  if (param_1 < param_2) {
    local_c = (uint *)(param_4 + param_1 * 4);
    local_8 = param_2 - param_1;
    iVar3 = uVar4 + 4;
    do {
      if ((uint)(iVar3 + iVar2) <= uVar6 - param_6) {
        uVar4 = FUN_007a2130(iVar1,iVar3);
        uVar7 = uVar7 ^ uVar4;
        iVar2 = FUN_007a22e0(*(undefined4 *)(iVar1 + 0x1c));
        iVar2 = *(int *)(iVar1 + 0x14) - iVar2;
        local_10 = local_10 | uVar7;
      }
      *local_c = uVar7;
      local_c = local_c + 1;
      local_8 = local_8 + -1;
      iVar3 = 5 - (uint)(param_3 != 0);
    } while (local_8 != 0);
  }
  iVar2 = 0;
  if ((param_6 != 0) &&
     (iVar3 = local_10 + (param_3 + param_5 * 2) * 4,
     (&DAT_0083c4b0)[iVar3] != (&DAT_0083c4b2)[iVar3])) {
    iVar2 = FUN_007a2130(iVar1,1);
  }
  if (param_1 < param_2) {
    param_2 = param_2 - param_1;
    piVar5 = (int *)(param_4 + param_1 * 4);
    do {
      param_2 = param_2 + -1;
      *piVar5 = (int)(char)(&DAT_0083c4b0)[*piVar5 + (iVar2 + (param_3 + param_5 * 2) * 2) * 2];
      piVar5 = piVar5 + 1;
    } while (param_2 != 0);
  }
  return;
}

