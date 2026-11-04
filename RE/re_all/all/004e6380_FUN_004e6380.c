
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall FUN_004e6380(void *param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_2a2 [6];
  uint local_29c;
  uint local_288;
  undefined1 local_284 [620];
  undefined4 local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b187b;
  pvStack_10 = ExceptionList;
  local_18 = DAT_0084b484;
  local_14 = auStack_2a2 + -0xe;
  ExceptionList = &pvStack_10;
  FUN_004d3fe0(param_4);
  local_8 = 0;
  local_29c = FUN_004dc540();
  if (param_3 == 0) {
    FUN_004e67ce();
    return;
  }
  iVar1 = FUN_004d29a0();
  iVar2 = FUN_004e62f0();
  if ((uint)(iVar2 - iVar1) < param_3) {
    FID_conflict__Xran(param_1);
    FUN_004e67ce();
    return;
  }
  iVar1 = FUN_004d29a0();
  if (local_29c < iVar1 + param_3) {
    iVar1 = FUN_004e62f0();
    if (iVar1 - (local_29c >> 1) < local_29c) {
      local_29c = 0;
    }
    else {
      local_29c = (local_29c >> 1) + local_29c;
    }
    local_288 = local_29c;
    iVar1 = FUN_004d29a0();
    if (local_29c < iVar1 + param_3) {
      iVar1 = FUN_004d29a0();
      local_288 = iVar1 + param_3;
    }
    iVar1 = FUN_004e6800(local_288);
    local_8 = CONCAT31(local_8._1_3_,1);
    uVar3 = DoMessageBox(*(undefined4 *)((int)param_1 + 4),param_2,iVar1);
    uVar3 = FUN_004dc800(uVar3,param_3,local_284);
    DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),uVar3);
    local_8 = 0;
    iVar2 = FUN_004d29a0();
    if (*(int *)((int)param_1 + 4) != 0) {
      FUN_004dc760(*(undefined4 *)((int)param_1 + 4),*(undefined4 *)((int)param_1 + 8));
      deallocate(*(undefined4 *)((int)param_1 + 4),
                 (*(int *)((int)param_1 + 0xc) - *(int *)((int)param_1 + 4)) / 0x268);
    }
    *(uint *)((int)param_1 + 0xc) = local_288 * 0x268 + iVar1;
    *(uint *)((int)param_1 + 8) = (iVar2 + param_3) * 0x268 + iVar1;
    *(int *)((int)param_1 + 4) = iVar1;
    FUN_004e67ce();
    return;
  }
  if ((uint)((*(int *)((int)param_1 + 8) - param_2) / 0x268) < param_3) {
    DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),param_3 * 0x268 + param_2);
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_004dc800(*(undefined4 *)((int)param_1 + 8),
                 param_3 - (*(int *)((int)param_1 + 8) - param_2) / 0x268,local_284);
    local_8 = 0;
    *(uint *)((int)param_1 + 8) = param_3 * 0x268 + *(int *)((int)param_1 + 8);
    FUN_004eefc0(param_2,*(int *)((int)param_1 + 8) + param_3 * -0x268,local_284);
    FUN_004e67ce();
    return;
  }
  iVar1 = *(int *)((int)param_1 + 8);
  uVar3 = DoMessageBox(iVar1 + param_3 * -0x268,iVar1,*(undefined4 *)((int)param_1 + 8));
  *(undefined4 *)((int)param_1 + 8) = uVar3;
  FUN_004eeff0(param_2,iVar1 + param_3 * -0x268,iVar1);
  FUN_004eefc0(param_2,param_3 * 0x268 + param_2,local_284);
  local_8 = 0xffffffff;
  FUN_0047a350();
  ExceptionList = pvStack_10;
  return;
}

