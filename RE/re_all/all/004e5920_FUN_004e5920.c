
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall FUN_004e5920(void *param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_8e2 [6];
  uint local_8dc;
  uint local_8c8;
  undefined1 local_8c4 [2220];
  undefined4 local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b183b;
  pvStack_10 = ExceptionList;
  local_18 = DAT_0084b484;
  local_14 = auStack_8e2 + -0xe;
  ExceptionList = &pvStack_10;
  FUN_004b4900(param_4);
  local_8 = 0;
  local_8dc = FUN_004dc0a0();
  if (param_3 == 0) {
    FUN_004e5d6e();
    return;
  }
  iVar1 = FUN_004d21f0();
  iVar2 = FUN_004e5890();
  if ((uint)(iVar2 - iVar1) < param_3) {
    FID_conflict__Xran(param_1);
    FUN_004e5d6e();
    return;
  }
  iVar1 = FUN_004d21f0();
  if (local_8dc < iVar1 + param_3) {
    iVar1 = FUN_004e5890();
    if (iVar1 - (local_8dc >> 1) < local_8dc) {
      local_8dc = 0;
    }
    else {
      local_8dc = (local_8dc >> 1) + local_8dc;
    }
    local_8c8 = local_8dc;
    iVar1 = FUN_004d21f0();
    if (local_8dc < iVar1 + param_3) {
      iVar1 = FUN_004d21f0();
      local_8c8 = iVar1 + param_3;
    }
    iVar1 = FUN_004e5da0(local_8c8);
    local_8 = CONCAT31(local_8._1_3_,1);
    uVar3 = DoMessageBox(*(undefined4 *)((int)param_1 + 4),param_2,iVar1);
    uVar3 = FUN_004eae20(uVar3,param_3,local_8c4);
    DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),uVar3);
    local_8 = 0;
    iVar2 = FUN_004d21f0();
    if (*(int *)((int)param_1 + 4) != 0) {
      FUN_004dc240(*(undefined4 *)((int)param_1 + 4),*(undefined4 *)((int)param_1 + 8));
      deallocate(*(undefined4 *)((int)param_1 + 4),
                 (*(int *)((int)param_1 + 0xc) - *(int *)((int)param_1 + 4)) / 0x8a8);
    }
    *(uint *)((int)param_1 + 0xc) = local_8c8 * 0x8a8 + iVar1;
    *(uint *)((int)param_1 + 8) = (iVar2 + param_3) * 0x8a8 + iVar1;
    *(int *)((int)param_1 + 4) = iVar1;
    FUN_004e5d6e();
    return;
  }
  if ((uint)((*(int *)((int)param_1 + 8) - param_2) / 0x8a8) < param_3) {
    DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),param_3 * 0x8a8 + param_2);
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_004eae20(*(undefined4 *)((int)param_1 + 8),
                 param_3 - (*(int *)((int)param_1 + 8) - param_2) / 0x8a8,local_8c4);
    local_8 = 0;
    *(uint *)((int)param_1 + 8) = param_3 * 0x8a8 + *(int *)((int)param_1 + 8);
    FUN_004eeea0(param_2,*(int *)((int)param_1 + 8) + param_3 * -0x8a8,local_8c4);
    FUN_004e5d6e();
    return;
  }
  iVar1 = *(int *)((int)param_1 + 8);
  uVar3 = DoMessageBox(iVar1 + param_3 * -0x8a8,iVar1,*(undefined4 *)((int)param_1 + 8));
  *(undefined4 *)((int)param_1 + 8) = uVar3;
  FUN_004eeed0(param_2,iVar1 + param_3 * -0x8a8,iVar1);
  FUN_004eeea0(param_2,param_3 * 0x8a8 + param_2,local_8c4);
  local_8 = 0xffffffff;
  FUN_0044e960();
  ExceptionList = pvStack_10;
  return;
}

