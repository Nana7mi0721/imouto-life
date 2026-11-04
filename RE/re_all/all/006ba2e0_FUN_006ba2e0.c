
void FUN_006ba2e0(undefined *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 *local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar6 = (int)param_1;
  iVar1 = (int)param_1 + 0xc9b4;
  iVar4 = FUN_006bf0c0(iVar1,3);
  if (iVar4 == 0) {
    iVar4 = 0;
    local_8 = 0;
    local_4 = 0;
    do {
      iVar5 = FUN_006bf0c0(iVar1,3);
      puVar2 = &DAT_00831eb8 + iVar4;
      iVar4 = iVar4 + 1;
      *(undefined1 *)((int)&local_8 + iVar5) = *puVar2;
    } while (iVar4 < 8);
    local_c = &local_8;
  }
  else {
    local_c = (undefined4 *)(&DAT_00831e80 + iVar4 * 8);
    param_1 = &DAT_0083211c;
    if (iVar4 == 7) goto LAB_006ba34f;
  }
  param_1 = &DAT_008320e8;
LAB_006ba34f:
  iVar4 = *(int *)(iVar6 + 200);
  uVar3 = *(uint *)(iVar6 + 0xd4);
  uVar7 = 0;
  if (uVar3 != 0) {
    do {
      if ('\0' < *(char *)(uVar7 + iVar4)) {
        iVar6 = FUN_006bef60(iVar1,param_1);
        *(undefined *)(uVar7 + iVar4) = *(undefined *)(iVar6 + (int)local_c);
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < uVar3);
  }
  return;
}

