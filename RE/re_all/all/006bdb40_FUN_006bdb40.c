
void FUN_006bdb40(int param_1,int param_2,byte *param_3,int param_4,int param_5,byte *param_6)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  byte *pbVar10;
  int iVar11;
  int iVar12;
  byte *local_28;
  int local_24;
  
  param_2 = param_2 + 0x7f;
  iVar2 = *(int *)(param_1 + 0x240 + param_4 * 4);
  iVar3 = *(int *)(param_4 * 0x20 + 0x50 + param_1);
  piVar1 = (int *)(param_4 * 0x20 + 0x48 + param_1);
  iVar4 = *piVar1;
  iVar5 = piVar1[3];
  iVar6 = *(int *)(param_1 + 0xac);
  iVar12 = iVar4 * param_5 + iVar3;
  iVar9 = iVar4 * (int)param_6 + iVar3;
  iVar7 = *(int *)(param_1 + 0xa8);
  iVar8 = *(int *)(param_1 + 0x224 + (int)param_3 * 4);
  if (iVar12 < iVar9) {
    local_24 = iVar12 + iVar4;
    param_3 = (byte *)(iVar7 + iVar12 * 4);
    local_28 = (byte *)(iVar7 + local_24 * 4);
    do {
      if (iVar12 < local_24) {
        param_6 = local_28;
        pbVar10 = param_3;
        param_1 = iVar12;
        do {
          if ((*pbVar10 & 1) != 0) {
            iVar11 = *(int *)(pbVar10 + (iVar6 - iVar7)) + iVar8;
            if (iVar12 < param_1) {
              FUN_006bdd10(iVar11,iVar2,param_2);
            }
            if (iVar3 < iVar12) {
              FUN_006bddb0(iVar11,iVar2,param_2);
            }
            if (((1 - iVar4) + param_1 + iVar4 < local_24) && ((pbVar10[4] & 1) == 0)) {
              FUN_006bdd10(iVar11 + 8,iVar2,param_2);
            }
            if ((param_1 + iVar4 < iVar5 + iVar3) && ((*param_6 & 1) == 0)) {
              FUN_006bddb0(iVar11 + iVar2 * 8,iVar2,param_2);
            }
          }
          param_6 = param_6 + 4;
          param_1 = param_1 + 1;
          pbVar10 = pbVar10 + 4;
        } while (param_1 < local_24);
      }
      param_3 = param_3 + iVar4 * 4;
      iVar12 = iVar12 + iVar4;
      local_28 = local_28 + iVar4 * 4;
      local_24 = local_24 + iVar4;
    } while (iVar12 < iVar9);
  }
  return;
}

