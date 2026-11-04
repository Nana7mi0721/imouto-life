
void __thiscall FUN_004da7d0(void *param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_5a [6];
  uint local_54;
  uint local_40;
  undefined1 local_3c [40];
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b13e8;
  pvStack_10 = ExceptionList;
  local_14 = auStack_5a + -0xe;
  ExceptionList = &pvStack_10;
  FUN_004dab10(param_4);
  local_8 = 0;
  local_54 = FUN_004da5a0();
  if (param_3 != 0) {
    iVar1 = FUN_004d00e0();
    iVar2 = FUN_004e4a40();
    if ((uint)(iVar2 - iVar1) < param_3) {
      FID_conflict__Xran(param_1);
    }
    else {
      iVar1 = FUN_004d00e0();
      if (local_54 < iVar1 + param_3) {
        iVar1 = FUN_004e4a40();
        if (iVar1 - (local_54 >> 1) < local_54) {
          local_54 = 0;
        }
        else {
          local_54 = (local_54 >> 1) + local_54;
        }
        local_40 = local_54;
        iVar1 = FUN_004d00e0();
        if (local_54 < iVar1 + param_3) {
          iVar1 = FUN_004d00e0();
          local_40 = iVar1 + param_3;
        }
        iVar1 = FUN_004e4ad0(local_40);
        local_8 = CONCAT31(local_8._1_3_,1);
        uVar3 = DoMessageBox(*(undefined4 *)((int)param_1 + 4),param_2,iVar1);
        uVar3 = FUN_004dac60(uVar3,param_3,local_3c);
        DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),uVar3);
        local_8 = 0;
        iVar2 = FUN_004d00e0();
        if (*(int *)((int)param_1 + 4) != 0) {
          FUN_004da730(*(undefined4 *)((int)param_1 + 4),*(undefined4 *)((int)param_1 + 8));
          deallocate(*(undefined4 *)((int)param_1 + 4),
                     (*(int *)((int)param_1 + 0xc) - *(int *)((int)param_1 + 4)) / 0x28);
        }
        *(uint *)((int)param_1 + 0xc) = local_40 * 0x28 + iVar1;
        *(uint *)((int)param_1 + 8) = (iVar2 + param_3) * 0x28 + iVar1;
        *(int *)((int)param_1 + 4) = iVar1;
      }
      else if ((uint)((*(int *)((int)param_1 + 8) - param_2) / 0x28) < param_3) {
        DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),param_3 * 0x28 + param_2);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_004dac60(*(undefined4 *)((int)param_1 + 8),
                     param_3 - (*(int *)((int)param_1 + 8) - param_2) / 0x28,local_3c);
        local_8 = 0;
        *(uint *)((int)param_1 + 8) = param_3 * 0x28 + *(int *)((int)param_1 + 8);
        _Destroy_range<>(param_2,*(int *)((int)param_1 + 8) + param_3 * -0x28,local_3c);
      }
      else {
        iVar1 = *(int *)((int)param_1 + 8);
        uVar3 = DoMessageBox(iVar1 + param_3 * -0x28,iVar1,*(undefined4 *)((int)param_1 + 8));
        *(undefined4 *)((int)param_1 + 8) = uVar3;
        FUN_004ee220(param_2,iVar1 + param_3 * -0x28,iVar1);
        _Destroy_range<>(param_2,param_3 * 0x28 + param_2,local_3c);
      }
    }
  }
  local_8 = 0xffffffff;
  FUN_004ada40();
  ExceptionList = pvStack_10;
  return;
}

