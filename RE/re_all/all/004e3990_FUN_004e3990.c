
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall FUN_004e3990(void *param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_66 [6];
  uint local_60;
  uint local_4c;
  undefined1 local_48 [48];
  undefined4 local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b1778;
  pvStack_10 = ExceptionList;
  local_18 = DAT_0084b484;
  local_14 = auStack_66 + -0xe;
  ExceptionList = &pvStack_10;
  FUN_004e9620(param_4);
  local_8 = 0;
  local_60 = FUN_004d8410();
  if (param_3 != 0) {
    iVar1 = FUN_004ce5c0();
    iVar2 = FUN_004e3900();
    if ((uint)(iVar2 - iVar1) < param_3) {
      FID_conflict__Xran(param_1);
    }
    else {
      iVar1 = FUN_004ce5c0();
      if (local_60 < iVar1 + param_3) {
        iVar1 = FUN_004e3900();
        if (iVar1 - (local_60 >> 1) < local_60) {
          local_60 = 0;
        }
        else {
          local_60 = (local_60 >> 1) + local_60;
        }
        local_4c = local_60;
        iVar1 = FUN_004ce5c0();
        if (local_60 < iVar1 + param_3) {
          iVar1 = FUN_004ce5c0();
          local_4c = iVar1 + param_3;
        }
        iVar1 = FUN_004ea6c0(local_4c);
        local_8 = CONCAT31(local_8._1_3_,1);
        uVar3 = DoMessageBox(*(undefined4 *)((int)param_1 + 4),param_2,iVar1);
        uVar3 = FUN_004ea7d0(uVar3,param_3,local_48);
        DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),uVar3);
        local_8 = 0;
        iVar2 = FUN_004ce5c0();
        if (*(int *)((int)param_1 + 4) != 0) {
          FUN_004d85a0(*(undefined4 *)((int)param_1 + 4),*(undefined4 *)((int)param_1 + 8));
          deallocate(*(undefined4 *)((int)param_1 + 4),
                     (*(int *)((int)param_1 + 0xc) - *(int *)((int)param_1 + 4)) / 0x30);
        }
        *(uint *)((int)param_1 + 0xc) = local_4c * 0x30 + iVar1;
        *(uint *)((int)param_1 + 8) = (iVar2 + param_3) * 0x30 + iVar1;
        *(int *)((int)param_1 + 4) = iVar1;
      }
      else if ((uint)((*(int *)((int)param_1 + 8) - param_2) / 0x30) < param_3) {
        DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),param_3 * 0x30 + param_2);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_004ea7d0(*(undefined4 *)((int)param_1 + 8),
                     param_3 - (*(int *)((int)param_1 + 8) - param_2) / 0x30,local_48);
        local_8 = 0;
        *(uint *)((int)param_1 + 8) = param_3 * 0x30 + *(int *)((int)param_1 + 8);
        _Destroy_range<>(param_2,*(int *)((int)param_1 + 8) + param_3 * -0x30,local_48);
      }
      else {
        iVar1 = *(int *)((int)param_1 + 8);
        uVar3 = DoMessageBox(iVar1 + param_3 * -0x30,iVar1,*(undefined4 *)((int)param_1 + 8));
        *(undefined4 *)((int)param_1 + 8) = uVar3;
        FUN_004ee9f0(param_2,iVar1 + param_3 * -0x30,iVar1);
        _Destroy_range<>(param_2,param_3 * 0x30 + param_2,local_48);
      }
    }
  }
  local_8 = 0xffffffff;
  FUN_004864a0();
  ExceptionList = pvStack_10;
  return;
}

