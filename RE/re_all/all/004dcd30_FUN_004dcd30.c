
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall FUN_004dcd30(void *param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_3c2 [6];
  uint local_3bc;
  uint local_3a8;
  undefined1 local_3a4 [908];
  undefined4 local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b153b;
  pvStack_10 = ExceptionList;
  local_18 = DAT_0084b484;
  local_14 = auStack_3c2 + -0xe;
  ExceptionList = &pvStack_10;
  FUN_004df500(param_4);
  local_8 = 0;
  local_3bc = FUN_004dcad0();
  if (param_3 == 0) {
    FUN_004dd17e();
    return;
  }
  iVar1 = FUN_004d3180();
  iVar2 = FUN_004e6bc0();
  if ((uint)(iVar2 - iVar1) < param_3) {
    FID_conflict__Xran(param_1);
    FUN_004dd17e();
    return;
  }
  iVar1 = FUN_004d3180();
  if (local_3bc < iVar1 + param_3) {
    iVar1 = FUN_004e6bc0();
    if (iVar1 - (local_3bc >> 1) < local_3bc) {
      local_3bc = 0;
    }
    else {
      local_3bc = (local_3bc >> 1) + local_3bc;
    }
    local_3a8 = local_3bc;
    iVar1 = FUN_004d3180();
    if (local_3bc < iVar1 + param_3) {
      iVar1 = FUN_004d3180();
      local_3a8 = iVar1 + param_3;
    }
    iVar1 = FUN_004e6c90(local_3a8);
    local_8 = CONCAT31(local_8._1_3_,1);
    uVar3 = DoMessageBox(*(undefined4 *)((int)param_1 + 4),param_2,iVar1);
    uVar3 = FUN_004e6c50(uVar3,param_3,local_3a4);
    DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),uVar3);
    local_8 = 0;
    iVar2 = FUN_004d3180();
    if (*(int *)((int)param_1 + 4) != 0) {
      FUN_004dcc90(*(undefined4 *)((int)param_1 + 4),*(undefined4 *)((int)param_1 + 8));
      deallocate(*(undefined4 *)((int)param_1 + 4),
                 (*(int *)((int)param_1 + 0xc) - *(int *)((int)param_1 + 4)) / 0x388);
    }
    *(uint *)((int)param_1 + 0xc) = local_3a8 * 0x388 + iVar1;
    *(uint *)((int)param_1 + 8) = (iVar2 + param_3) * 0x388 + iVar1;
    *(int *)((int)param_1 + 4) = iVar1;
    FUN_004dd17e();
    return;
  }
  if ((uint)((*(int *)((int)param_1 + 8) - param_2) / 0x388) < param_3) {
    DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),param_3 * 0x388 + param_2);
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_004e6c50(*(undefined4 *)((int)param_1 + 8),
                 param_3 - (*(int *)((int)param_1 + 8) - param_2) / 0x388,local_3a4);
    local_8 = 0;
    *(uint *)((int)param_1 + 8) = param_3 * 0x388 + *(int *)((int)param_1 + 8);
    FUN_004ee5d0(param_2,*(int *)((int)param_1 + 8) + param_3 * -0x388,local_3a4);
    FUN_004dd17e();
    return;
  }
  iVar1 = *(int *)((int)param_1 + 8);
  uVar3 = DoMessageBox(iVar1 + param_3 * -0x388,iVar1,*(undefined4 *)((int)param_1 + 8));
  *(undefined4 *)((int)param_1 + 8) = uVar3;
  FUN_004ee600(param_2,iVar1 + param_3 * -0x388,iVar1);
  FUN_004ee5d0(param_2,param_3 * 0x388 + param_2,local_3a4);
  local_8 = 0xffffffff;
  FUN_0049eca0();
  ExceptionList = pvStack_10;
  return;
}

