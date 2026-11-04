
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall FUN_004e4ce0(void *param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_23a [6];
  uint local_234;
  uint local_220;
  undefined1 local_21c [516];
  undefined4 local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b180b;
  pvStack_10 = ExceptionList;
  local_18 = DAT_0084b484;
  local_14 = auStack_23a + -0xe;
  ExceptionList = &pvStack_10;
  FUN_004b4780(param_4);
  local_8 = 0;
  local_234 = FUN_004db510();
  if (param_3 != 0) {
    iVar1 = FUN_004d0b50();
    iVar2 = FUN_004e4c50();
    if ((uint)(iVar2 - iVar1) < param_3) {
      FID_conflict__Xran(param_1);
    }
    else {
      iVar1 = FUN_004d0b50();
      if (local_234 < iVar1 + param_3) {
        iVar1 = FUN_004e4c50();
        if (iVar1 - (local_234 >> 1) < local_234) {
          local_234 = 0;
        }
        else {
          local_234 = (local_234 >> 1) + local_234;
        }
        local_220 = local_234;
        iVar1 = FUN_004d0b50();
        if (local_234 < iVar1 + param_3) {
          iVar1 = FUN_004d0b50();
          local_220 = iVar1 + param_3;
        }
        iVar1 = FUN_004e5160(local_220);
        local_8 = CONCAT31(local_8._1_3_,1);
        uVar3 = DoMessageBox(*(undefined4 *)((int)param_1 + 4),param_2,iVar1);
        uVar3 = FUN_004db7f0(uVar3,param_3,local_21c);
        DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),uVar3);
        local_8 = 0;
        iVar2 = FUN_004d0b50();
        if (*(int *)((int)param_1 + 4) != 0) {
          FUN_004db750(*(undefined4 *)((int)param_1 + 4),*(undefined4 *)((int)param_1 + 8));
          deallocate(*(undefined4 *)((int)param_1 + 4),
                     (*(int *)((int)param_1 + 0xc) - *(int *)((int)param_1 + 4)) / 0x1fc);
        }
        *(uint *)((int)param_1 + 0xc) = local_220 * 0x1fc + iVar1;
        *(uint *)((int)param_1 + 8) = (iVar2 + param_3) * 0x1fc + iVar1;
        *(int *)((int)param_1 + 4) = iVar1;
      }
      else if ((uint)((*(int *)((int)param_1 + 8) - param_2) / 0x1fc) < param_3) {
        DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),param_3 * 0x1fc + param_2);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_004db7f0(*(undefined4 *)((int)param_1 + 8),
                     param_3 - (*(int *)((int)param_1 + 8) - param_2) / 0x1fc,local_21c);
        local_8 = 0;
        *(uint *)((int)param_1 + 8) = param_3 * 0x1fc + *(int *)((int)param_1 + 8);
        FUN_004eed10(param_2,*(int *)((int)param_1 + 8) + param_3 * -0x1fc,local_21c);
      }
      else {
        iVar1 = *(int *)((int)param_1 + 8);
        uVar3 = DoMessageBox(iVar1 + param_3 * -0x1fc,iVar1,*(undefined4 *)((int)param_1 + 8));
        *(undefined4 *)((int)param_1 + 8) = uVar3;
        FUN_004eed40(param_2,iVar1 + param_3 * -0x1fc,iVar1);
        FUN_004eed10(param_2,param_3 * 0x1fc + param_2,local_21c);
      }
    }
  }
  local_8 = 0xffffffff;
  FUN_00471b50();
  ExceptionList = pvStack_10;
  return;
}

