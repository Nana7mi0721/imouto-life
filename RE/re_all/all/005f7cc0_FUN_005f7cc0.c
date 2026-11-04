
int FUN_005f7cc0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                undefined1 *param_5)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int extraout_EDX;
  int iVar5;
  longlong lVar6;
  undefined1 local_30 [16];
  undefined1 local_20 [32];
  
  iVar5 = 0;
  bVar1 = false;
  if (param_5 == (undefined1 *)0x0) {
    lVar6 = FUN_005f7ef0(param_1,local_30,0x10000,0);
    if (lVar6 == -0x80) {
      return -0x80;
    }
    if (((int)((ulonglong)lVar6 >> 0x20) < 1) && (lVar6 < 0)) {
      return -0x84;
    }
    param_5 = local_30;
  }
  FUN_006aba80(param_2);
  FUN_006ab9d0(param_3);
  iVar2 = FUN_006a8260(param_5);
  if (iVar2 != 0) {
    iVar2 = param_1 + 0x78;
    do {
      uVar3 = FUN_006a8360(param_5);
      FUN_006a8d60(iVar2,uVar3);
      FUN_006a89a0(iVar2,param_5);
      iVar4 = FUN_006a8d90(iVar2,local_20);
      if ((0 < iVar4) && (iVar4 = FUN_006abc20(local_20), iVar4 != 0)) {
        if (param_4 != (undefined4 *)0x0) {
          *param_4 = *(undefined4 *)(param_1 + 0x1c8);
        }
        *(undefined4 *)(param_1 + 0x58) = 3;
        iVar2 = FUN_006abcd0(param_2,param_3,local_20);
        if (iVar2 == 0) goto joined_r0x005f7df7;
        goto LAB_005f7eb0;
      }
      lVar6 = FUN_005f7ef0(param_1,param_5,0x10000,0);
      if (lVar6 == -0x80) {
        return -0x80;
      }
      if (lVar6 < 0) {
        return -0x84;
      }
      iVar4 = FUN_006a8260(param_5);
    } while (iVar4 != 0);
  }
  iVar2 = -0x84;
LAB_005f7eb0:
  FUN_006abab0(param_2);
  FUN_006ab9f0(param_3);
  *(undefined4 *)(param_1 + 0x58) = 2;
  return iVar2;
joined_r0x005f7df7:
  while( true ) {
    if (1 < iVar5) {
      return 0;
    }
    iVar2 = FUN_006a8d90(param_1 + 0x78,local_20);
    if (iVar2 != 0) break;
    if (1 < iVar5) {
      return 0;
    }
    while( true ) {
      FUN_005f7ef0(param_1,param_5,0x10000,0);
      if (extraout_EDX < 0) goto LAB_005f7eab;
      iVar2 = FUN_006a8360(param_5);
      if (*(int *)(param_1 + 0x1c8) == iVar2) break;
      iVar2 = FUN_006a8260();
      if (iVar2 != 0) {
        if (bVar1) goto LAB_005f7eab;
        bVar1 = true;
      }
    }
    FUN_006a89a0(param_1 + 0x78,param_5);
  }
  if (iVar2 == -1) {
LAB_005f7eab:
    iVar2 = -0x85;
    goto LAB_005f7eb0;
  }
  iVar2 = FUN_006abcd0(param_2,param_3,local_20);
  if (iVar2 != 0) goto LAB_005f7eb0;
  iVar5 = iVar5 + 1;
  goto joined_r0x005f7df7;
}

