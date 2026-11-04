
longlong FUN_006a9b00(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int extraout_EDX;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  longlong lVar10;
  undefined1 local_30 [16];
  undefined1 local_20 [32];
  
  uVar5 = 0;
  iVar6 = 0;
  iVar7 = -1;
  iVar1 = *(int *)(param_1 + 0x1c8);
  do {
    do {
      FUN_006a94d0(param_1,local_30,0xffffffff,0xffffffff);
      lVar10 = CONCAT44(iVar6,uVar5);
      if (extraout_EDX < 0) goto LAB_006a9bf7;
      iVar2 = FUN_006a8260(local_30);
      lVar10 = CONCAT44(iVar6,uVar5);
      if (iVar2 != 0) goto LAB_006a9bf7;
      iVar2 = FUN_006a8360(local_30);
    } while (iVar2 != iVar1);
    iVar8 = param_1 + 0x78;
    FUN_006a89a0(iVar8,local_30);
    iVar2 = FUN_006a8d90(iVar8,local_20);
    while (iVar2 != 0) {
      iVar3 = iVar7;
      if ((0 < iVar2) && (iVar3 = FUN_006ac510(param_2,local_20), iVar7 != -1)) {
        uVar4 = iVar3 + iVar7 >> 2;
        bVar9 = CARRY4(uVar5,uVar4);
        uVar5 = uVar5 + uVar4;
        iVar6 = iVar6 + (iVar3 + iVar7 >> 0x1f) + (uint)bVar9;
      }
      iVar2 = FUN_006a8d90(iVar8,local_20);
      iVar7 = iVar3;
    }
    lVar10 = FUN_006a8280(local_30);
  } while (lVar10 == -1);
  lVar10 = FUN_006a8280(local_30);
  lVar10 = lVar10 - CONCAT44(iVar6,uVar5);
LAB_006a9bf7:
  if ((lVar10 < 0x100000000) && (lVar10 < 0)) {
    return 0;
  }
  return lVar10;
}

