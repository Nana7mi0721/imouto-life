
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall FUN_004e8c40(void *param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_b2 [6];
  uint local_ac;
  uint local_98;
  undefined1 local_94 [124];
  undefined4 local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b18fb;
  pvStack_10 = ExceptionList;
  local_18 = DAT_0084b484;
  local_14 = auStack_b2 + -0xe;
  ExceptionList = &pvStack_10;
  FUN_004e98a0(param_4);
  local_8 = 0;
  local_ac = FUN_004deaf0();
  if (param_3 != 0) {
    iVar1 = FUN_004dec00();
    iVar2 = FUN_004e8b80();
    if ((uint)(iVar2 - iVar1) < param_3) {
      FID_conflict__Xran(param_1);
    }
    else {
      iVar1 = FUN_004dec00();
      if (local_ac < iVar1 + param_3) {
        iVar1 = FUN_004e8b80();
        if (iVar1 - (local_ac >> 1) < local_ac) {
          local_ac = 0;
        }
        else {
          local_ac = (local_ac >> 1) + local_ac;
        }
        local_98 = local_ac;
        iVar1 = FUN_004dec00();
        if (local_ac < iVar1 + param_3) {
          iVar1 = FUN_004dec00();
          local_98 = iVar1 + param_3;
        }
        iVar1 = FUN_004e90a0(local_98);
        local_8 = CONCAT31(local_8._1_3_,1);
        uVar3 = DoMessageBox(*(undefined4 *)((int)param_1 + 4),param_2,iVar1);
        uVar3 = FUN_004dedb0(uVar3,param_3,local_94);
        DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),uVar3);
        local_8 = 0;
        iVar2 = FUN_004dec00();
        if (*(int *)((int)param_1 + 4) != 0) {
          FUN_004e8c10(*(undefined4 *)((int)param_1 + 4),*(undefined4 *)((int)param_1 + 8));
          deallocate(*(undefined4 *)((int)param_1 + 4),
                     (*(int *)((int)param_1 + 0xc) - *(int *)((int)param_1 + 4)) / 0x74);
        }
        *(uint *)((int)param_1 + 0xc) = local_98 * 0x74 + iVar1;
        *(uint *)((int)param_1 + 8) = (iVar2 + param_3) * 0x74 + iVar1;
        *(int *)((int)param_1 + 4) = iVar1;
      }
      else if ((uint)((*(int *)((int)param_1 + 8) - param_2) / 0x74) < param_3) {
        DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),param_3 * 0x74 + param_2);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_004dedb0(*(undefined4 *)((int)param_1 + 8),
                     param_3 - (*(int *)((int)param_1 + 8) - param_2) / 0x74,local_94);
        local_8 = 0;
        *(uint *)((int)param_1 + 8) = param_3 * 0x74 + *(int *)((int)param_1 + 8);
        _Destroy_range<>(param_2,*(int *)((int)param_1 + 8) + param_3 * -0x74,local_94);
      }
      else {
        iVar1 = *(int *)((int)param_1 + 8);
        uVar3 = DoMessageBox(iVar1 + param_3 * -0x74,iVar1,*(undefined4 *)((int)param_1 + 8));
        *(undefined4 *)((int)param_1 + 8) = uVar3;
        FUN_004ef260(param_2,iVar1 + param_3 * -0x74,iVar1);
        _Destroy_range<>(param_2,param_3 * 0x74 + param_2,local_94);
      }
    }
  }
  local_8 = 0xffffffff;
  FUN_004c0f80();
  ExceptionList = pvStack_10;
  return;
}

