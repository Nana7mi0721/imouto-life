
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall FUN_004e4560(void *param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_c2a [6];
  uint local_c24;
  uint local_c10;
  undefined1 local_c0c [3060];
  undefined4 local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b17eb;
  pvStack_10 = ExceptionList;
  local_18 = DAT_0084b484;
  local_14 = auStack_c2a + -0xe;
  ExceptionList = &pvStack_10;
  FUN_004e9690(param_4);
  local_8 = 0;
  local_c24 = FUN_004d9c20();
  if (param_3 != 0) {
    iVar1 = FUN_004cfab0();
    iVar2 = FUN_004e44d0();
    if ((uint)(iVar2 - iVar1) < param_3) {
      FID_conflict__Xran(param_1);
    }
    else {
      iVar1 = FUN_004cfab0();
      if (local_c24 < iVar1 + param_3) {
        iVar1 = FUN_004e44d0();
        if (iVar1 - (local_c24 >> 1) < local_c24) {
          local_c24 = 0;
        }
        else {
          local_c24 = (local_c24 >> 1) + local_c24;
        }
        local_c10 = local_c24;
        iVar1 = FUN_004cfab0();
        if (local_c24 < iVar1 + param_3) {
          iVar1 = FUN_004cfab0();
          local_c10 = iVar1 + param_3;
        }
        iVar1 = FUN_004e49e0(local_c10);
        local_8 = CONCAT31(local_8._1_3_,1);
        uVar3 = DoMessageBox(*(undefined4 *)((int)param_1 + 4),param_2,iVar1);
        uVar3 = FUN_004d9ee0(uVar3,param_3,local_c0c);
        DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),uVar3);
        local_8 = 0;
        iVar2 = FUN_004cfab0();
        if (*(int *)((int)param_1 + 4) != 0) {
          FUN_004d9e40(*(undefined4 *)((int)param_1 + 4),*(undefined4 *)((int)param_1 + 8));
          deallocate(*(undefined4 *)((int)param_1 + 4),
                     (*(int *)((int)param_1 + 0xc) - *(int *)((int)param_1 + 4)) / 0xbec);
        }
        *(uint *)((int)param_1 + 0xc) = local_c10 * 0xbec + iVar1;
        *(uint *)((int)param_1 + 8) = (iVar2 + param_3) * 0xbec + iVar1;
        *(int *)((int)param_1 + 4) = iVar1;
      }
      else if ((uint)((*(int *)((int)param_1 + 8) - param_2) / 0xbec) < param_3) {
        DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),param_3 * 0xbec + param_2);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_004d9ee0(*(undefined4 *)((int)param_1 + 8),
                     param_3 - (*(int *)((int)param_1 + 8) - param_2) / 0xbec,local_c0c);
        local_8 = 0;
        *(uint *)((int)param_1 + 8) = param_3 * 0xbec + *(int *)((int)param_1 + 8);
        FUN_004eec20(param_2,*(int *)((int)param_1 + 8) + param_3 * -0xbec,local_c0c);
      }
      else {
        iVar1 = *(int *)((int)param_1 + 8);
        uVar3 = DoMessageBox(iVar1 + param_3 * -0xbec,iVar1,*(undefined4 *)((int)param_1 + 8));
        *(undefined4 *)((int)param_1 + 8) = uVar3;
        FUN_004eec50(param_2,iVar1 + param_3 * -0xbec,iVar1);
        FUN_004eec20(param_2,param_3 * 0xbec + param_2,local_c0c);
      }
    }
  }
  local_8 = 0xffffffff;
  FUN_00481330();
  ExceptionList = pvStack_10;
  return;
}

