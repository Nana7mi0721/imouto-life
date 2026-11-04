
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall FUN_004d90f0(void *param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_c2 [6];
  uint local_bc;
  uint local_a8;
  undefined1 local_a4 [140];
  undefined4 local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b132b;
  pvStack_10 = ExceptionList;
  local_18 = DAT_0084b484;
  local_14 = auStack_c2 + -0xe;
  ExceptionList = &pvStack_10;
  FUN_004d41b0(param_4);
  local_8 = 0;
  local_bc = FUN_004d8f60();
  if (param_3 == 0) {
    FUN_004d953e();
    return;
  }
  iVar1 = FUN_004cf130();
  iVar2 = FUN_004e42a0();
  if ((uint)(iVar2 - iVar1) < param_3) {
    FID_conflict__Xran(param_1);
    FUN_004d953e();
    return;
  }
  iVar1 = FUN_004cf130();
  if (local_bc < iVar1 + param_3) {
    iVar1 = FUN_004e42a0();
    if (iVar1 - (local_bc >> 1) < local_bc) {
      local_bc = 0;
    }
    else {
      local_bc = (local_bc >> 1) + local_bc;
    }
    local_a8 = local_bc;
    iVar1 = FUN_004cf130();
    if (local_bc < iVar1 + param_3) {
      iVar1 = FUN_004cf130();
      local_a8 = iVar1 + param_3;
    }
    iVar1 = FUN_004e42c0(local_a8);
    local_8 = CONCAT31(local_8._1_3_,1);
    uVar3 = DoMessageBox(*(undefined4 *)((int)param_1 + 4),param_2,iVar1);
    uVar3 = FUN_004d9570(uVar3,param_3,local_a4);
    DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),uVar3);
    local_8 = 0;
    iVar2 = FUN_004cf130();
    if (*(int *)((int)param_1 + 4) != 0) {
      FUN_004d9050(*(undefined4 *)((int)param_1 + 4),*(undefined4 *)((int)param_1 + 8));
      deallocate(*(undefined4 *)((int)param_1 + 4),
                 (*(int *)((int)param_1 + 0xc) - *(int *)((int)param_1 + 4)) / 0x88);
    }
    *(uint *)((int)param_1 + 0xc) = local_a8 * 0x88 + iVar1;
    *(uint *)((int)param_1 + 8) = (iVar2 + param_3) * 0x88 + iVar1;
    *(int *)((int)param_1 + 4) = iVar1;
    FUN_004d953e();
    return;
  }
  if ((uint)((*(int *)((int)param_1 + 8) - param_2) / 0x88) < param_3) {
    DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),param_3 * 0x88 + param_2);
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_004d9570(*(undefined4 *)((int)param_1 + 8),
                 param_3 - (*(int *)((int)param_1 + 8) - param_2) / 0x88,local_a4);
    local_8 = 0;
    *(uint *)((int)param_1 + 8) = param_3 * 0x88 + *(int *)((int)param_1 + 8);
    FUN_004ede30(param_2,*(int *)((int)param_1 + 8) + param_3 * -0x88,local_a4);
    FUN_004d953e();
    return;
  }
  iVar1 = *(int *)((int)param_1 + 8);
  uVar3 = DoMessageBox(iVar1 + param_3 * -0x88,iVar1,*(undefined4 *)((int)param_1 + 8));
  *(undefined4 *)((int)param_1 + 8) = uVar3;
  FUN_004ede60(param_2,iVar1 + param_3 * -0x88,iVar1);
  FUN_004ede30(param_2,param_3 * 0x88 + param_2,local_a4);
  local_8 = 0xffffffff;
  FUN_0046f320();
  ExceptionList = pvStack_10;
  return;
}

