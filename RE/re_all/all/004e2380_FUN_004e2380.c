
void __thiscall FUN_004e2380(void *param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_3e [6];
  uint local_38;
  uint local_24;
  undefined1 local_20 [12];
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b16f8;
  pvStack_10 = ExceptionList;
  local_14 = auStack_3e + -0xe;
  ExceptionList = &pvStack_10;
  FUN_004b50e0(param_4);
  local_8 = 0;
  local_38 = FUN_004d7840();
  if (param_3 != 0) {
    iVar1 = FUN_004ccff0();
    iVar2 = FUN_004e22f0();
    if ((uint)(iVar2 - iVar1) < param_3) {
      FID_conflict__Xran(param_1);
    }
    else {
      iVar1 = FUN_004ccff0();
      if (local_38 < iVar1 + param_3) {
        iVar1 = FUN_004e22f0();
        if (iVar1 - (local_38 >> 1) < local_38) {
          local_38 = 0;
        }
        else {
          local_38 = (local_38 >> 1) + local_38;
        }
        local_24 = local_38;
        iVar1 = FUN_004ccff0();
        if (local_38 < iVar1 + param_3) {
          iVar1 = FUN_004ccff0();
          local_24 = iVar1 + param_3;
        }
        iVar1 = FUN_004e26c0(local_24);
        local_8 = CONCAT31(local_8._1_3_,1);
        uVar3 = DoMessageBox(*(undefined4 *)((int)param_1 + 4),param_2,iVar1);
        uVar3 = FUN_004ea6e0(uVar3,param_3,local_20);
        DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),uVar3);
        local_8 = 0;
        iVar2 = FUN_004ccff0();
        if (*(int *)((int)param_1 + 4) != 0) {
          FUN_004d79d0(*(undefined4 *)((int)param_1 + 4),*(undefined4 *)((int)param_1 + 8));
          deallocate(*(undefined4 *)((int)param_1 + 4),
                     (*(int *)((int)param_1 + 0xc) - *(int *)((int)param_1 + 4)) / 0xc);
        }
        *(uint *)((int)param_1 + 0xc) = local_24 * 0xc + iVar1;
        *(uint *)((int)param_1 + 8) = (iVar2 + param_3) * 0xc + iVar1;
        *(int *)((int)param_1 + 4) = iVar1;
      }
      else if ((uint)((*(int *)((int)param_1 + 8) - param_2) / 0xc) < param_3) {
        DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),param_3 * 0xc + param_2);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_004ea6e0(*(undefined4 *)((int)param_1 + 8),
                     param_3 - (*(int *)((int)param_1 + 8) - param_2) / 0xc,local_20);
        local_8 = 0;
        *(uint *)((int)param_1 + 8) = param_3 * 0xc + *(int *)((int)param_1 + 8);
        _Destroy_range<>(param_2,*(int *)((int)param_1 + 8) + param_3 * -0xc,local_20);
      }
      else {
        iVar1 = *(int *)((int)param_1 + 8);
        uVar3 = DoMessageBox(iVar1 + param_3 * -0xc,iVar1,*(undefined4 *)((int)param_1 + 8));
        *(undefined4 *)((int)param_1 + 8) = uVar3;
        FUN_004ee750(param_2,iVar1 + param_3 * -0xc,iVar1);
        _Destroy_range<>(param_2,param_3 * 0xc + param_2,local_20);
      }
    }
  }
  local_8 = 0xffffffff;
  FUN_00471980();
  ExceptionList = pvStack_10;
  return;
}

