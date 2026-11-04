
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall FUN_004daed0(void *param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_e2 [6];
  uint local_dc;
  uint local_c8;
  undefined1 local_c4 [172];
  undefined4 local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b143b;
  pvStack_10 = ExceptionList;
  local_18 = DAT_0084b484;
  local_14 = auStack_e2 + -0xe;
  ExceptionList = &pvStack_10;
  FUN_004df3f0(param_4);
  local_8 = 0;
  local_dc = FUN_004dac90();
  if (param_3 != 0) {
    iVar1 = FUN_004d0530();
    iVar2 = FUN_004e4af0();
    if ((uint)(iVar2 - iVar1) < param_3) {
      FID_conflict__Xran(param_1);
    }
    else {
      iVar1 = FUN_004d0530();
      if (local_dc < iVar1 + param_3) {
        iVar1 = FUN_004e4af0();
        if (iVar1 - (local_dc >> 1) < local_dc) {
          local_dc = 0;
        }
        else {
          local_dc = (local_dc >> 1) + local_dc;
        }
        local_c8 = local_dc;
        iVar1 = FUN_004d0530();
        if (local_dc < iVar1 + param_3) {
          iVar1 = FUN_004d0530();
          local_c8 = iVar1 + param_3;
        }
        iVar1 = FUN_004e4b80(local_c8);
        local_8 = CONCAT31(local_8._1_3_,1);
        uVar3 = DoMessageBox(*(undefined4 *)((int)param_1 + 4),param_2,iVar1);
        uVar3 = FUN_004db350(uVar3,param_3,local_c4);
        DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),uVar3);
        local_8 = 0;
        iVar2 = FUN_004d0530();
        if (*(int *)((int)param_1 + 4) != 0) {
          FUN_004dae30(*(undefined4 *)((int)param_1 + 4),*(undefined4 *)((int)param_1 + 8));
          deallocate(*(undefined4 *)((int)param_1 + 4),
                     (*(int *)((int)param_1 + 0xc) - *(int *)((int)param_1 + 4)) / 0xa8);
        }
        *(uint *)((int)param_1 + 0xc) = local_c8 * 0xa8 + iVar1;
        *(uint *)((int)param_1 + 8) = (iVar2 + param_3) * 0xa8 + iVar1;
        *(int *)((int)param_1 + 4) = iVar1;
      }
      else if ((uint)((*(int *)((int)param_1 + 8) - param_2) / 0xa8) < param_3) {
        DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),param_3 * 0xa8 + param_2);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_004db350(*(undefined4 *)((int)param_1 + 8),
                     param_3 - (*(int *)((int)param_1 + 8) - param_2) / 0xa8,local_c4);
        local_8 = 0;
        *(uint *)((int)param_1 + 8) = param_3 * 0xa8 + *(int *)((int)param_1 + 8);
        FUN_004ee2e0(param_2,*(int *)((int)param_1 + 8) + param_3 * -0xa8,local_c4);
      }
      else {
        iVar1 = *(int *)((int)param_1 + 8);
        uVar3 = DoMessageBox(iVar1 + param_3 * -0xa8,iVar1,*(undefined4 *)((int)param_1 + 8));
        *(undefined4 *)((int)param_1 + 8) = uVar3;
        FUN_004ee310(param_2,iVar1 + param_3 * -0xa8,iVar1);
        FUN_004ee2e0(param_2,param_3 * 0xa8 + param_2,local_c4);
      }
    }
  }
  local_8 = 0xffffffff;
  FUN_004ada90();
  ExceptionList = pvStack_10;
  return;
}

