
int FUN_00655060(int param_1,int param_2,int *param_3,uint param_4,int *param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar5 = param_2;
  iVar3 = FUN_00653680(*(undefined2 *)(param_2 + 2));
  uVar7 = *(uint *)(iVar5 + 8);
  uVar1 = *(uint *)(iVar5 + 0xc);
  if ((uVar7 == 0 && uVar1 == 0) || (iVar3 == 0)) {
    *param_5 = 0;
    return 0;
  }
  uVar4 = (uint)(0x7fffffff / (longlong)iVar3);
  uVar6 = (int)uVar4 >> 0x1f;
  if ((uVar6 <= uVar1) && ((uVar6 < uVar1 || (uVar4 < uVar7)))) {
    return 6;
  }
  if ((uVar1 != 0) || ((uint)(0x7fffffff / (ulonglong)param_4) < uVar7)) {
    return 6;
  }
  iVar2 = *(int *)(iVar5 + 8);
  *param_3 = iVar2;
  uVar7 = iVar2 * iVar3;
  iVar3 = FUN_00650c00(param_1,iVar2,iVar3,s_ReadDirEntryArray_00a09ff8);
  if (iVar3 == 0) {
    return 7;
  }
  uVar1 = *(uint *)(param_1 + 0xc);
  if ((uVar1 & 0x80000) == 0) {
    if (4 < uVar7) {
      param_2 = *(undefined4 *)(iVar5 + 0x10);
      if ((uVar1 & 0x80) != 0) {
        FUN_0065a600(&param_2);
      }
      iVar5 = FUN_006558d0(param_1,param_2,0,uVar7,iVar3);
      if (iVar5 != 0) {
        FUN_006507e0(iVar3);
        return iVar5;
      }
      goto LAB_006551c3;
    }
  }
  else if (8 < uVar7) {
    local_8 = *(undefined4 *)(iVar5 + 0x10);
    local_4 = *(undefined4 *)(iVar5 + 0x14);
    if ((uVar1 & 0x80) != 0) {
      FUN_0065a620(&local_8);
    }
    iVar5 = FUN_006558d0(param_1,local_8,local_4,uVar7,iVar3);
    if (iVar5 != 0) {
      FUN_006507e0(iVar3);
      return iVar5;
    }
    goto LAB_006551c3;
  }
  FUN_00650840(iVar3,iVar5 + 0x10,uVar7);
LAB_006551c3:
  *param_5 = iVar3;
  return 0;
}

