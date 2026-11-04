
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall FUN_004e5e50(void *param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_182 [6];
  uint local_17c;
  uint local_168;
  undefined1 local_164 [332];
  undefined4 local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b185b;
  pvStack_10 = ExceptionList;
  local_18 = DAT_0084b484;
  local_14 = auStack_182 + -0xe;
  ExceptionList = &pvStack_10;
  FUN_004b4bb0(param_4);
  local_8 = 0;
  local_17c = FUN_004dc2e0();
  if (param_3 != 0) {
    iVar1 = FUN_004d25e0();
    iVar2 = FUN_004e5dc0();
    if ((uint)(iVar2 - iVar1) < param_3) {
      FID_conflict__Xran(param_1);
    }
    else {
      iVar1 = FUN_004d25e0();
      if (local_17c < iVar1 + param_3) {
        iVar1 = FUN_004e5dc0();
        if (iVar1 - (local_17c >> 1) < local_17c) {
          local_17c = 0;
        }
        else {
          local_17c = (local_17c >> 1) + local_17c;
        }
        local_168 = local_17c;
        iVar1 = FUN_004d25e0();
        if (local_17c < iVar1 + param_3) {
          iVar1 = FUN_004d25e0();
          local_168 = iVar1 + param_3;
        }
        iVar1 = FUN_004e62d0(local_168);
        local_8 = CONCAT31(local_8._1_3_,1);
        uVar3 = DoMessageBox(*(undefined4 *)((int)param_1 + 4),param_2,iVar1);
        uVar3 = FUN_004eae90(uVar3,param_3,local_164);
        DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),uVar3);
        local_8 = 0;
        iVar2 = FUN_004d25e0();
        if (*(int *)((int)param_1 + 4) != 0) {
          FUN_004dc4a0(*(undefined4 *)((int)param_1 + 4),*(undefined4 *)((int)param_1 + 8));
          deallocate(*(undefined4 *)((int)param_1 + 4),
                     (*(int *)((int)param_1 + 0xc) - *(int *)((int)param_1 + 4)) / 0x148);
        }
        *(uint *)((int)param_1 + 0xc) = local_168 * 0x148 + iVar1;
        *(uint *)((int)param_1 + 8) = (iVar2 + param_3) * 0x148 + iVar1;
        *(int *)((int)param_1 + 4) = iVar1;
      }
      else if ((uint)((*(int *)((int)param_1 + 8) - param_2) / 0x148) < param_3) {
        DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),param_3 * 0x148 + param_2);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_004eae90(*(undefined4 *)((int)param_1 + 8),
                     param_3 - (*(int *)((int)param_1 + 8) - param_2) / 0x148,local_164);
        local_8 = 0;
        *(uint *)((int)param_1 + 8) = param_3 * 0x148 + *(int *)((int)param_1 + 8);
        FUN_004eef30(param_2,*(int *)((int)param_1 + 8) + param_3 * -0x148,local_164);
      }
      else {
        iVar1 = *(int *)((int)param_1 + 8);
        uVar3 = DoMessageBox(iVar1 + param_3 * -0x148,iVar1,*(undefined4 *)((int)param_1 + 8));
        *(undefined4 *)((int)param_1 + 8) = uVar3;
        FUN_004eef60(param_2,iVar1 + param_3 * -0x148,iVar1);
        FUN_004eef30(param_2,param_3 * 0x148 + param_2,local_164);
      }
    }
  }
  local_8 = 0xffffffff;
  FUN_004788e0();
  ExceptionList = pvStack_10;
  return;
}

