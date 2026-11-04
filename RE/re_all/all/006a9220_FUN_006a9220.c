
int FUN_006a9220(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                undefined4 *param_5,undefined1 *param_6)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_EDX;
  int iVar4;
  longlong lVar5;
  undefined1 local_30 [16];
  undefined1 local_20 [32];
  
  bVar1 = false;
  if (param_6 == (undefined1 *)0x0) {
    lVar5 = FUN_006a94d0(param_1,local_30,0x10000,0);
    if (lVar5 == -0x80) {
      return -0x80;
    }
    if (((int)((ulonglong)lVar5 >> 0x20) < 1) && (lVar5 < 0)) {
      return -0x84;
    }
    param_6 = local_30;
  }
  FUN_006aba80(param_2);
  FUN_006ab9d0(param_3);
  *(undefined4 *)(param_1 + 0x58) = 2;
  iVar2 = FUN_006a8260(param_6);
joined_r0x006a92a3:
  if (iVar2 == 0) goto LAB_006a93f5;
  if (param_4 != (undefined4 *)0x0) {
    iVar2 = FUN_006a9670(param_6,*param_4,*param_5);
    if (iVar2 != 0) {
      if ((void *)*param_4 != (void *)0x0) {
        _free((void *)*param_4);
      }
      *param_4 = 0;
      *param_5 = 0;
LAB_006a93b4:
      iVar2 = -0x85;
      goto LAB_006a93b9;
    }
    FUN_006a9610(param_6,param_4,param_5);
  }
  if (*(int *)(param_1 + 0x58) < 3) {
    iVar2 = param_1 + 0x78;
    uVar3 = FUN_006a8360(param_6);
    FUN_006a8d60(iVar2,uVar3);
    FUN_006a89a0(iVar2,param_6);
    iVar2 = FUN_006a8d90(iVar2,local_20);
    if ((0 < iVar2) && (iVar2 = FUN_006abc20(local_20), iVar2 != 0)) {
      *(undefined4 *)(param_1 + 0x58) = 3;
      iVar2 = FUN_006abcd0(param_2,param_3,local_20);
      if (iVar2 != 0) goto LAB_006a93b4;
    }
  }
  lVar5 = FUN_006a94d0(param_1,param_6,0x10000,0);
  if (lVar5 == -0x80) {
    iVar2 = -0x80;
    goto LAB_006a93b9;
  }
  if (lVar5 < 0) goto LAB_006a93fb;
  if ((*(int *)(param_1 + 0x58) == 3) &&
     (iVar2 = FUN_006a8360(param_6), *(int *)(param_1 + 0x1c8) == iVar2)) {
    FUN_006a89a0(param_1 + 0x78,param_6);
    goto LAB_006a93f5;
  }
  iVar2 = FUN_006a8260(param_6);
  goto joined_r0x006a92a3;
LAB_006a93f5:
  if (*(int *)(param_1 + 0x58) == 3) {
    iVar4 = 0;
    do {
      if (1 < iVar4) {
        return 0;
      }
      while (iVar2 = FUN_006a8d90(param_1 + 0x78,local_20), iVar2 != 0) {
        if (iVar2 == -1) goto LAB_006a93b4;
        iVar2 = FUN_006abcd0(param_2,param_3,local_20);
        if (iVar2 != 0) goto LAB_006a93b9;
        iVar4 = iVar4 + 1;
        if (1 < iVar4) {
          return 0;
        }
      }
      if (1 < iVar4) {
        return 0;
      }
      while( true ) {
        FUN_006a94d0(param_1,param_6,0x10000,0);
        if (extraout_EDX < 0) goto LAB_006a93b4;
        iVar2 = FUN_006a8360(param_6);
        if (*(int *)(param_1 + 0x1c8) == iVar2) break;
        iVar2 = FUN_006a8260();
        if (iVar2 != 0) {
          if (bVar1) goto LAB_006a93b4;
          bVar1 = true;
        }
      }
      FUN_006a89a0(param_1 + 0x78,param_6);
    } while( true );
  }
LAB_006a93fb:
  iVar2 = -0x84;
LAB_006a93b9:
  FUN_006abab0(param_2);
  FUN_006ab9f0(param_3);
  *(undefined4 *)(param_1 + 0x58) = 2;
  return iVar2;
}

