
void __thiscall FUN_004e6840(void *param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_46 [6];
  uint local_40;
  uint local_2c;
  CDHtmlElementEventSink local_28 [20];
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b1898;
  pvStack_10 = ExceptionList;
  local_14 = auStack_46 + -0xe;
  ExceptionList = &pvStack_10;
  <>(param_4);
  local_8 = 0;
  local_40 = FUN_004dc840();
  if (param_3 == 0) {
    FUN_004e6b5d();
    return;
  }
  iVar1 = FUN_004d2d60();
  iVar2 = FUN_004e6820();
  if ((uint)(iVar2 - iVar1) < param_3) {
    FID_conflict__Xran(param_1);
    FUN_004e6b5d();
    return;
  }
  iVar1 = FUN_004d2d60();
  if (local_40 < iVar1 + param_3) {
    iVar1 = FUN_004e6820();
    if (iVar1 - (local_40 >> 1) < local_40) {
      local_40 = 0;
    }
    else {
      local_40 = (local_40 >> 1) + local_40;
    }
    local_2c = local_40;
    iVar1 = FUN_004d2d60();
    if (local_40 < iVar1 + param_3) {
      iVar1 = FUN_004d2d60();
      local_2c = iVar1 + param_3;
    }
    iVar1 = FUN_004e6b80(local_2c);
    local_8 = CONCAT31(local_8._1_3_,1);
    uVar3 = DoMessageBox(*(undefined4 *)((int)param_1 + 4),param_2,iVar1);
    uVar3 = FUN_004dca20(uVar3,param_3,local_28);
    DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),uVar3);
    local_8 = 0;
    iVar2 = FUN_004d2d60();
    if (*(int *)((int)param_1 + 4) != 0) {
      FUN_004dc980(*(undefined4 *)((int)param_1 + 4),*(undefined4 *)((int)param_1 + 8));
      deallocate(*(undefined4 *)((int)param_1 + 4),
                 (*(int *)((int)param_1 + 0xc) - *(int *)((int)param_1 + 4)) / 0x14);
    }
    *(uint *)((int)param_1 + 0xc) = local_2c * 0x14 + iVar1;
    *(uint *)((int)param_1 + 8) = (iVar2 + param_3) * 0x14 + iVar1;
    *(int *)((int)param_1 + 4) = iVar1;
    FUN_004e6b5d();
    return;
  }
  if ((uint)((*(int *)((int)param_1 + 8) - param_2) / 0x14) < param_3) {
    DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),param_3 * 0x14 + param_2);
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_004dca20(*(undefined4 *)((int)param_1 + 8),
                 param_3 - (*(int *)((int)param_1 + 8) - param_2) / 0x14,local_28);
    local_8 = 0;
    *(uint *)((int)param_1 + 8) = param_3 * 0x14 + *(int *)((int)param_1 + 8);
    _Destroy_range<>(param_2,*(int *)((int)param_1 + 8) + param_3 * -0x14,local_28);
    FUN_004e6b5d();
    return;
  }
  iVar1 = *(int *)((int)param_1 + 8);
  uVar3 = DoMessageBox(iVar1 + param_3 * -0x14,iVar1,*(undefined4 *)((int)param_1 + 8));
  *(undefined4 *)((int)param_1 + 8) = uVar3;
  FUN_004ef080(param_2,iVar1 + param_3 * -0x14,iVar1);
  _Destroy_range<>(param_2,param_3 * 0x14 + param_2,local_28);
  local_8 = 0xffffffff;
  CDHtmlElementEventSink::~CDHtmlElementEventSink(local_28);
  ExceptionList = pvStack_10;
  return;
}

