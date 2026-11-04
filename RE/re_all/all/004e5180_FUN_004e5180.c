
void __thiscall FUN_004e5180(void *param_1,int param_2,uint param_3,undefined2 *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_36 [6];
  uint local_30;
  uint local_1c;
  undefined2 local_18 [2];
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b1820;
  pvStack_10 = ExceptionList;
  local_14 = auStack_36 + -0xe;
  local_18[0] = *param_4;
  ExceptionList = &pvStack_10;
  local_30 = FUN_004eabf0();
  if (param_3 != 0) {
    iVar1 = FUN_004d0c60();
    iVar2 = FUN_004e54a0();
    if ((uint)(iVar2 - iVar1) < param_3) {
      FID_conflict__Xran(param_1);
    }
    else {
      iVar1 = FUN_004d0c60();
      if (local_30 < iVar1 + param_3) {
        iVar1 = FUN_004e54a0();
        if (iVar1 - (local_30 >> 1) < local_30) {
          local_30 = 0;
        }
        else {
          local_30 = (local_30 >> 1) + local_30;
        }
        local_1c = local_30;
        iVar1 = FUN_004d0c60();
        if (local_30 < iVar1 + param_3) {
          iVar1 = FUN_004d0c60();
          local_1c = iVar1 + param_3;
        }
        iVar1 = allocate(local_1c);
        local_8 = 0;
        uVar3 = DoMessageBox(*(undefined4 *)((int)param_1 + 4),param_2,iVar1);
        uVar3 = FUN_004eac30(uVar3,param_3,local_18);
        DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),uVar3);
        local_8 = 0xffffffff;
        iVar2 = FUN_004d0c60();
        if (*(int *)((int)param_1 + 4) != 0) {
          FUN_004e4160(*(undefined4 *)((int)param_1 + 4),*(undefined4 *)((int)param_1 + 8));
          deallocate(*(undefined4 *)((int)param_1 + 4),
                     *(int *)((int)param_1 + 0xc) - *(int *)((int)param_1 + 4) >> 1);
        }
        *(uint *)((int)param_1 + 0xc) = iVar1 + local_1c * 2;
        *(uint *)((int)param_1 + 8) = iVar1 + (iVar2 + param_3) * 2;
        *(int *)((int)param_1 + 4) = iVar1;
      }
      else if ((uint)(*(int *)((int)param_1 + 8) - param_2 >> 1) < param_3) {
        DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),param_2 + param_3 * 2);
        local_8 = 2;
        FUN_004eac30(*(undefined4 *)((int)param_1 + 8),
                     param_3 - (*(int *)((int)param_1 + 8) - param_2 >> 1),local_18);
        local_8 = 0xffffffff;
        *(uint *)((int)param_1 + 8) = *(int *)((int)param_1 + 8) + param_3 * 2;
        FUN_004eee30(param_2,*(int *)((int)param_1 + 8) + param_3 * -2,local_18);
      }
      else {
        iVar1 = *(int *)((int)param_1 + 8);
        uVar3 = DoMessageBox(iVar1 + param_3 * -2,iVar1,*(undefined4 *)((int)param_1 + 8));
        *(undefined4 *)((int)param_1 + 8) = uVar3;
        FUN_004eee60(param_2,iVar1 + param_3 * -2,iVar1);
        FUN_004eee30(param_2,param_2 + param_3 * 2,local_18);
      }
    }
  }
  ExceptionList = pvStack_10;
  return;
}

